//
//  main.cpp
//  STRSUB
//
//  Created by Dheeraj Reddy on 21/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    while(T--) {
        int N,K,Q;
        cin >> N >> K >> Q;
        string s;
        cin >> s;
        vector<int> count_1(N+1), count_0(N+1);
        count_1[0] = 0;
        count_0[0] = 0;
        for(int i=1;i<N+1;i++) {
            if(s[i-1] == '0')
                count_0[i] = count_0[i-1] + 1;
            else
                count_1[i] = count_1[i-1] + 1;
        }
        
        for(int i=0;i<Q;i++) {
            
        }
    }
    
    return 0;
}
