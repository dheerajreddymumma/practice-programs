//
//  main.cpp
//  GRID
//
//  Created by Dheeraj Reddy on 10/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        
        vector<vector<char>> str(N, vector<char>(N));
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin >> str[i][j];
        
        vector<vector<int>> dp(N, vector<int>(N));
        int isAvailable = 1;
        for(int j=0; j<N;j++) {
            isAvailable = 1;
            for(int i = N-1; i>= 0; i--) {
                if(str[i][j] == '#') {
                    isAvailable = 0;
                    dp[i][j] = 0;
                    continue;
                }
                if(j == 0)
                    dp[i][j] = isAvailable;
                else
                    dp[i][j] = dp[i][j-1] + isAvailable;
            }
        }
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cout << dp[i][j] << " ";
            }
            cout<<endl;
        }
        int ans = 0;
        for(int i=0;i<N;i++)
            ans += dp[i][N-1];

        cout<<ans<<endl;
    }
    return 0;
}
