#include <bits/stdc++.h>

using namespace std;

struct Fact {
    string from;
    string to;
    double rate;
};

/*
Let's notice that any path that goes from and to will be "correct";
Assume no arbitrage opportunities
*/

struct FactEdge {
    string to;
    double rate;
};

map<string, vector<FactEdge>> fact_graph;

inline void generate_facts_graph() {
    // generate the reverse edge
    vector<Fact> input{{"m", "ft", 3.28}, {"ft", "in", 12}, {"hr", "min", 60}, {"min", "sec", 60}};

    for(Fact &f : input) {
        fact_graph[f.from].push_back({f.to, f.rate});
        fact_graph[f.to].push_back({f.from, 1.0 / f.rate});
    }
}

string answer_query(string from, string to, double initial) {
    // we want to find any path from and to, and calculate the product of the values on that path
    set<string> visited;

    queue<pair<string, double>> bfs; // contains {fact, conversion rate}
    bfs.push({from, 1.0});
    while(bfs.size()) {
        auto top = bfs.front(); bfs.pop();
        string top_unit = top.first;
        double top_conversion = top.second;

        visited.insert(top_unit);

        if(top_unit == to) {
            return to_string(initial * top_conversion);
        }

        // go through our adjacency list
        for(FactEdge &fact : fact_graph[top_unit]) {
            if(!visited.count(fact.to)) {
                double new_rate = top_conversion * fact.rate;
                bfs.push({fact.to, new_rate});
            }
        }
    }

    return "not convertible!";
}

int main() {
    generate_facts_graph();
    cout << answer_query("m", "in", 2.0) << endl;
    cout << answer_query("in", "hr", 1.0) << endl;
    cout << answer_query("in", "m", 13.0) << endl;
}