//
//  main.cpp
//  codejam_2008_prb1
//
//  Created by Dheeraj Reddy on 13/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int N;
    std::cin >> N;
    cin.ignore(256, '\n');
    for(int t=1;t<=N;t++) {
        int S;
        std::cin >> S;
        cin.ignore(256, '\n');
        string s2;
        for(int i=0;i<S;i++)
            getline(cin,s2);
        
        int Q;
        std::cin >> Q;
        cin.ignore(256, '\n');
        set<string> queries;
        int ans = 0;
        string query;
        for(int i=0;i<Q;i++){
            getline(cin,query);
            queries.insert(query);
            if((int)queries.size() == S) {
                queries.clear();
                queries.insert(query);
                ans++;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
