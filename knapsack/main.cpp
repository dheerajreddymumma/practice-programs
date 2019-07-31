//
//  main.cpp
//  knapsack
//
//  Created by Dheeraj Reddy on 05/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <algorithm>
//#include <pair>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int N, num1, num2, total_weight = 0;
    cin >> N;
    vector<pair<int,int>> items(N+1);
    items[0] = make_pair(0,0);
    for(int i=0;i<N;i++) {
        cin>>num1>>num2;
        total_weight += num1;
        items[i+1] = make_pair(num1, num2);
    }
    
    vector<vector<int>> dp(total_weight + 1, vector<int>(N+1,0));
    
    for(int i=1;i<total_weight+1;i++) {
        for(int j = 1; j< N+1;j++) {
            if(items[j].first > i)
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = max(items[j].second + dp[i-items[j].first][j-1], dp[i][j-1]);
        }
        if(i == total_weight)
            cout<<dp[i][N] <<endl;
        else
            cout << dp[i][N] << " ";
    }
    
    return 0;
}
