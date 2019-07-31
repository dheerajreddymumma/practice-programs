//
//  main.cpp
//  deque
//
//  Created by Dheeraj Reddy on 25/06/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> window;
    
    for(int i=0;i<nums.size();i++) {
        if(!window.empty() && i-k+1 > window.front())
            window.pop_front();
        
        while(!window.empty() && nums[window.back()] <= nums[i])
            window.pop_back();
        window.push_back(i);
        if(i >= k-1)
            ans.push_back(nums[window.front()]);
    }
    return ans;
}

int minDistance(string word1, string word2) {
    int ans = 0;
    vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1));
    
    for(int i=1;i<word1.length()+1;i++) {
        for(int j=1; j<word2.length()+1;j++) {
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    pair<int,int> lastFound;
    lastFound.first = (int)word1.length() + 1;
    lastFound.second = (int)word2.length() + 1;
    int i = (int)word1.length(), j = (int)word2.length();
    while( i >= 1 && j >= 1) {
        if(dp[i][j] == 0)
            break;
        while(j >= 1 && dp[i][j] == dp[i][j-1]){
            j--;
        }
        if(j == 0)
            continue;
        
        if(dp[i][j] > dp[i-1][j]) {
            ans+= max(lastFound.first-i-1, lastFound.second-j-1);
            lastFound.first = i;
            lastFound.second = j;
            cout << word1[i-1] << endl;
            i--;
            j--;
        }
        else
            i--;
    }
    ans+= max(lastFound.first-1, j-lastFound.second-1);
    return ans;
}

int main(int argc, const char * argv[]) {
    vector<int> vec = {1,3,-1,-3,5,3,6,7};
//    vector<int> ans = maxSlidingWindow(vec, 3);
//    for(auto x: ans)
//        cout << x <<"  ";
//    cout<<"\n";
    cout << minDistance("intention", "execution");
    return 0;
}
