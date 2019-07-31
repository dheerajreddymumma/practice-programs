//
//  main.cpp
//  CLETAB
//
//  Created by Dheeraj Reddy on 26/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin >> t;
    while(t--) {
        int N,M = 0;
        cin >> N >> M;
        int arr[M];
        for (int i = 0; i < M; i++)
            cin >> arr[i];
        
        int ans = 1;
        set<int> s;
        s.insert(arr[0]);
        for(int i = 1; i < M; i++) {
            if (s.find(arr[i]) != s.end())
                continue;
            
            if (s.size() < N) {
                s.insert(arr[i]);
                ans++;
            }
            
            else {
                set<int>::iterator it = s.begin(), itr;
                int ind[401];
                memset(ind, -1, sizeof(ind));
                for(int j = i+1; j < M; j++)
                    if (ind[arr[j]] == -1)
                        ind[arr[j]] = j;
                
                int max_index_found = -1, flag = 0;
                
                for (; it != s.end(); it++)
                    if(ind[*it] == -1) {
                        s.erase(it);
                        s.insert(arr[i]);
                        flag = 1;
                        ans++;
                        break;
                    }
                    else
                        if(ind[*it] > max_index_found) {
                            max_index_found = ind[*it];
                            itr = it;
                        }
                if(flag == 0) {
                    s.erase(itr);
                    s.insert(arr[i]);
                    flag = 0;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
