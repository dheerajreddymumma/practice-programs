//
//  main.cpp
//  FGFS
//
//  Created by Dheeraj Reddy on 31/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <limits>
#include <numeric>
#include <regex>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <chrono>
using namespace std;

bool sort_deadline(vector<int> t1, vector<int> t2) {
    if(t1[2] == t2[2])
        return t1[1] <= t2[1];
    return t1[2] <= t2[2];
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        int N, K, s,f,p;
        cin >> N >> K;
        vector<vector<int>> vec;
        for(int i =0;i<N;i++) {
            cin >> s >> f >> p;
            vec.push_back({s,f,p});
        }
        sort(vec.begin(), vec.end(), sort_deadline);
        
        int cust_satisfied = 0, previous_compartment = -1, check_time = 0;
        for(int i = 0; i<N; i++) {
            
            int arrival_time = vec[i][0], deadline = vec[i][1], comp_num = vec[i][2];
            
            if(previous_compartment != comp_num) {
                previous_compartment = comp_num;
                check_time = 0;
            }
            
            if(arrival_time >= check_time) {
                check_time = deadline;
                cust_satisfied += 1;
            }
        }
        cout << cust_satisfied << endl;
    }
    
    return 0;
}
