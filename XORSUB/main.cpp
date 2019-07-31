//
//  main.cpp
//  XORSUB
//
//  Created by Dheeraj Reddy on 10/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--) {
        int N = 0, K;
        cin >> N >> K;
        vector<int> A(N+1);
        for(int i = 0;i<N;i++){
            cin >> A[i+1];
        }
        vector<vector<int>> dp(N+1,vector<int>(1024,0));
        dp[0][0] = 1;
        
        for(int i=1;i<N+1;i++){
            for(int j=0;j<1024;j++){
                dp[i][j] = dp[i-1][j] | dp[i-1][j^A[i]];
            }
        }
        int ans = 0;
        for(int i=0;i<1024;i++)
            ans = max(ans, dp[N][i] * (i^K));
        cout << ans << endl;
    }
    return 0;
}
