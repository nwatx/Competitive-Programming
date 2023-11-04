#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMinOperations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */
 
// int f(long long n) {
//     int best = __builtin_popcountll(n);
    
//     for(int i = 0; i < 60; i++) {
//         long long convert_to = (1 << i);
//         long long diff = abs(n - convert_to);
        
//         // find bit difference
//         int bit_diff = __builtin_popcountll(diff) + 1;
//         cout << convert_to << " " << bit_diff << endl;
        
//         best = min(best, bit_diff);
//     }
    
//     return best;
// }

int getMinOperations(long long n) {
    if(n == 0) return 0;
    string s = bitset<64>(n).to_string();
    // cout << s << endl;
    int first = 0;
    for(int i = 0; i < 64; i++) {
        if(s[i] == '1') {
            first = i;
            break;
        }
    }
    
    int cnt = 0;
    int low = 0;
    bool run = false;
    for (int i = 63; i >= 0; i--) {
        if (!run && s[i] == '0') continue;
        if (!run && s[i] == '1') {
            run = true;
            low = i;
            continue;
        }
        if (run && s[i] == '1') continue;
        if (run && s[i] == '0') {
            if (low - i == 1) {
                run = false;
                cnt++;
            } else {
                cnt++;
                s[i] = '1';
                low = i;
            }
        }
    }
    
    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long long n = stoll(ltrim(rtrim(n_temp)));

    int result = getMinOperations(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
