//
//  main.cpp
//  MATRIX2
//
//  Created by Dheeraj Reddy on 13/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(N+1, vector<ll>(M+1,0));
    vector<string> str(N);
    for(int i=0;i<N;i++)
        cin >> str[i];
    ll ans = 0;
    for(int i=1;i<N+1;i++) {
        for(int j=1;j<M+1;j++) {
            if(str[i-1][j-1] == '0')
                continue;
            dp[i][j] = 1+ min(dp[i-1][j],dp[i-1][j-1]);
            ans += dp[i][j];
        }
    }
    cout << ans <<endl;
    return 0;
}
