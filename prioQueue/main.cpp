//
//  main.cpp
//  prioQueue
//
//  Created by Dheeraj Reddy on 26/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    // insert code here...
    int t;
    cin >> t;
    while(t--) {
        int N,M = 0;
        cin >> N >> M;
        int arr[M];
        vector<queue<int>> vec(401);
        for (int i = 0; i < M; i++) {
            cin >> arr[i];
            if(i != 0)
                vec[arr[i]].push(i);
        }
        int ans = 1;
        set<int> s;
        s.insert(arr[0]);
        for(int i = 1; i < M; i++) {
            vec[arr[i]].pop();
            if (s.find(arr[i]) != s.end())
                continue;
            
            if (s.size() < N) {
                s.insert(arr[i]);
                ans++;
            }
            
            else {
                set<int>::iterator it, itr;
                int find_max = -1, flag = 0;
                for (it = s.begin(); it != s.end(); it++) {
                    if (vec[*it].size() == 0) {
                        s.erase(it);
                        s.insert(arr[i]);
                        flag = 0;
                        break;
                    }
                    else {
                        if (vec[*it].front() > find_max) {
                            find_max = vec[*it].front();
                            itr = it;
                            flag = 1;
                        }
                    }
                }
                if (flag == 1) {
                    s.erase(itr);
                    s.insert(arr[i]);
                }
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

