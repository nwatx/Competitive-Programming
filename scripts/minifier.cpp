#include <bits/stdc++.h>
using namespace std;

/*
How the preprocessor works:
Step 1: Find all macros, typedefs, etc.
a) Macro scan regex: \s*#define.*
*/

string removeComments(fstream &readFile) {
    string source;
    getline(readFile, source, '\0');
    while(source.find("/*") != string::npos) {
        size_t Beg = source.find("/*");
        source.erase(Beg, (source.find("*/", Beg) - Beg)+2);
    }
    while(source.find("//") != string::npos) {
        size_t Beg = source.find("//");
        source.erase(Beg, source.find("\n", Beg) - Beg);
    }
    
    return source;
}

namespace stringProcessing {
    // trim from start
    static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }

    // trim from end
    static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(),
                std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }

    // trim from both ends
    static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
    }

    std::vector<std::string> splitString(const std::string& stringToSplit, const std::string& regexPattern)
    {
        std::vector<std::string> result;

        const std::regex rgx(regexPattern);
        std::sregex_token_iterator iter(stringToSplit.begin(), stringToSplit.end(), rgx, -1);

        for (std::sregex_token_iterator end; iter != end; ++iter)
        {
            result.push_back(iter->str());
        }

        return result;
    }
}

using namespace stringProcessing;

namespace Regex {
    const regex regex_macro("\\s*#define.*");
    const regex regex_function(".*\\(.*\\).*");
    const regex regex_trim_blank_lines("\\\\n\\s*\\\\n");
    const string regex_firstSpace = "/^(\\S+)\\s(.*)/";
    const string regex_macro_separator("\\(|\\)|\\.|\\s");
};

using namespace Regex;

namespace Macros {
    struct MacroInfo {
        string content;
        string name;
        int params;
        int line;

        MacroInfo() {
            content = "";
            params = 0;
            name = "";
            line = -1;
        }

        bool operator==(MacroInfo b) {
            return (content == b.content && name == b.name && params == b.params);
        }
    };

    MacroInfo getMacroInfo(string &line) {
        // cout << line << "\n";
        MacroInfo info;
        string trimmedLine = trim(line);
        string macroContent = trimmedLine.substr(trimmedLine.find(' '));
        macroContent = trim(macroContent);
        string macroName = macroContent.substr(0, macroContent.find_first_of(" ()"));
        // cout << macroContent << " | " << macroName << '\n';
        macroContent = macroContent.substr(trimmedLine.find(' '));
        if(regex_match(macroContent, regex_function)) {
            int params = 0;
            int leftIt = macroContent.find('(');
            int rightIt = macroContent.find(')');
            if(rightIt - leftIt > 1) params++;

            for(int i = leftIt; i < rightIt; i++) if(macroContent[i] == ',') params++;
            info.params = params;      
        }

        info.name = macroName;

        // if(info.params) cout << info.params << "\n";
        return info;
    }

    inline bool operator<(const MacroInfo &a, const MacroInfo &b) {
        if(a.content != b.content) return a.content < b.content;
        if(a.name != b.name) return a.name < b.name;
        if(a.params != b.params) return a.params < b.params;
        return a.line < b.line;
    }
}

set<Macros::MacroInfo> macros;
unordered_set<string> macrosNames;
map<string, int> macroFrequency;

// TODO: next we make a directed dependency graph...

string line;

#define loopLines for(string line; getline(sourceStream, line);)
#define clearLines sourceStream.clear(), sourceStream.str(source);

string removeBlankLines(const string &file) {
    string res = "";
    istringstream ss(file);
    for(string temp; getline(ss, temp);) {
        string copy = temp;
        if(trim(copy).size() > 0) 
            res += temp + "\n";
    }
    return res;
}

int main() {
	clock_t start = clock();
    fstream file; file.open("../testscript.cpp");
    string source = removeComments(file);
    source = removeBlankLines(source);
    istringstream sourceStream(source);

    loopLines {
        // if()
        // cout << line << "\n";
        if(regex_match(line, regex_macro)) {
            Macros::MacroInfo info = Macros::getMacroInfo(line);
            macros.insert(info);
            if(info.name.size()) macrosNames.insert(info.name);
            // cerr << macroName << " | " << macroContent << "\n";
        }
    }

    for(const string &a : macrosNames) {
        cout << "macroName: " << a << "\n";
    }

    // if(file.is_open()) { // process: find used macros
        // file.clear();
        // file.seekg(0);

    cout << "HERE===2";

    clearLines;

    set<Macros::MacroInfo> detectedMacros;
    loopLines {
        cout << line << "\n";
        if(line == "#pragma endregion") break;
    }

    loopLines {
        cout << line << "\n";
        for(const string &token : splitString(line, regex_macro_separator))
        for(const string &a : macrosNames) {
            if(token == a) {
                cout << "detected: " << line << " || " << a << "\n";
            }
        }
    }
    // }

    // if(file.is_open()) {
    //     file.clear();
    //     file.seekg(0);
    //     int lineNumber = 0;
    //     while(getline(file, line)) {
    //         // cout << line << "\n";
    //         if(line == "#pragma endregion") break;
    //         lineNumber++;
    //     }

    //     cerr << lineNumber;

    //     while(getline(file, line)) {

    //     }
    // }
	cerr << "Total Time: " << (double)(clock() - start)/ CLOCKS_PER_SEC;
}