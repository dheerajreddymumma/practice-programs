//
//  main.cpp
//  quicksort
//
//  Created by Dheeraj Reddy on 05/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int findPivotIndex(vector<int> &vec, int low, int high) {
    int index = low+1, temp;
    for(int i=low+1; i<=high;i++) {
        if(vec[low] <= vec[i]) {
            temp = vec[index];
            vec[index++] = vec[i];
            vec[i] = temp;
        }
    }
    
    if(index != low+1) {
        temp = vec[index-1];
        vec[index-1] = vec[low];
        vec[low] = temp;
    }
    return index-1;
}

int findRandomPivotIndex(vector<int> &vec, int low, int high) {
    int pivotElement = low + ((high - low)/2),index = low, temp, i;
    for(i=low; i<=high;i++) {
        if(pivotElement == i)
            continue;
        if(vec[pivotElement] <= vec[i]) {
            temp = vec[index];
            vec[index++] = vec[i];
            vec[i] = temp;
            if(index == pivotElement)
                index++;
        }
    }
    
    if(index <= pivotElement) {
        temp = vec[index];
        vec[index] = vec[pivotElement];
        vec[pivotElement] = temp;
        return index;
    }
    
    temp = vec[index-1];
    vec[index-1] = vec[pivotElement];
    vec[pivotElement] = temp;
    return index-1;
}

void quicksort(vector<int> &vec, int first, int last) {
    if(first < last) {
        int pivot = findRandomPivotIndex(vec, first, last);
        quicksort(vec, first, pivot-1);
        quicksort(vec, pivot+1, last);
    }
}

bool map_compare (map<char,int> lhs, map<char,int> rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
    && equal(lhs.begin(), lhs.end(),
                  rhs.begin());
}

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if(s.size() < p.size())
        return ans;
    
    map<char,int> mapP, mapS;
    for(auto x: p)
        mapP[x]++;
    
    for(int i=0;i<p.size();i++)
        mapS[s[i]]++;
    
    if(map_compare(mapP, mapS))
        ans.push_back(0);
    
    for(int i=1;i<=s.size()-p.size();i++) {
        mapS[s[i-1]]--;
        if(mapS[s[i-1]] == 0) {
            map<char,int>::iterator it1 = mapS.find(s[i-1]);
            mapS.erase(it1);
        }
        mapS[s[i+p.size()-1]]++;
        if(map_compare(mapP, mapS))
            ans.push_back(i);
    }
    return ans;
}

int minPathSum(vector<vector<int>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0)
        return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    dp[0][0] = grid[0][0];
    for(int i=1;i<n;i++)
        dp[0][i] = dp[0][i-1] + grid[0][i];
    for(int i=1;i<m;i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    
    for(int i=1;i<m;i++)
        for(int j=1;i<n;j++)
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
    return dp[m-1][n-1];
}

int numTrees(int n) {
    int ans = 0;
    vector<int> dp(n+1);
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++) {
        int firstValue = i-1, lastValue = 0, ans = 0;
        for(int j = 0; j < i/2; j++)
            ans += (dp[firstValue--] * dp[lastValue++]);
        dp[i] = 2 * ans;
        if(i%2 == 1)
            dp[i] += (dp[firstValue] * dp[lastValue]);
    }
    return dp[n];
}

int main(int argc, const char * argv[]) {
    
//    vector<vector<int>> vec = {
//                               {1,3,1},
//                               {1,5,1},
//                               {4,2,1}
//                               };
//    minPathSum(vec);
    numTrees(5);
    return 0;
}
