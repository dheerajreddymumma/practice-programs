//
//  main.cpp
//  graphs
//
//  Created by Dheeraj Reddy on 08/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

double implementDFS(map<string,vector<pair<string,double>>> graph, int N, string node1, string node2) {
    stack<pair<string, double>> nodeStack;
    unordered_set<string> s;
    s.insert(node1);
    for(auto x: graph[node1]) {
        s.insert(x.first);
        if(x.first == node2)
            return x.second;
        nodeStack.push(make_pair(x.first, x.second));
    }
    while(nodeStack.size() != 0) {
        pair<string,double> p1 = nodeStack.top();
        nodeStack.pop();
        //cout << "Node: " << get<0>(p1) << " To Node " << get<1>(p1) << " Distance: " <<get<2>(p1) <<endl;
        for(auto x: graph[p1.first])
            if(s.find(x.first) == s.end()) {
                if(x.first == node2)
                    return x.second * p1.second;
                nodeStack.push(make_pair(x.first, x.second * p1.second));
                s.insert(x.first);
            }
    }
    return -1;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<map<char,int>, vector<string>> dict;
    
    for(auto str: strs) {
        map<char,int> mp;
        for(auto chr: str)
            mp[chr]++;
        dict[mp].push_back(str);
    }
    vector<vector<string>> ans;
    for(auto x: dict)
        ans.push_back(x.second);
    return ans;
}

int main(int argc, const char * argv[]) {
//    int N, M;
//    cin >> N >> M;
//    vector<vector<pair<int,double>>> graph(N);
//    for(int i=0;i<M;i++) {
//        int v1, v2, weight;
//        cin >> v1 >> v2 >> weight;
//
//        graph[v1].push_back(make_pair(v2, (double)weight));
//        graph[v2].push_back(make_pair(v1, 1/(double)weight));
//    }
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
    return 0;
}
