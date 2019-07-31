//
//  main.cpp
//  numberPermuatation
//
//  Created by Dheeraj Reddy on 26/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int climbStairs(int n) {
    if(n == 0)
    return 0;
    int previous = 1, twoPrevious = 0, temp;
    for(int i=1;i<=n;i++){
        temp = twoPrevious + previous;
        twoPrevious = previous;
        previous = temp;
    }
    return previous;
}

int findAllPermutations(int sum, int finalSum, vector<int> &dp, vector<int> elements) {
    if(sum > finalSum)
        return 0;
    if(sum == finalSum) {
        for(int i=0;i<elements.size();i++)
            cout << elements[i] << " ";
        cout <<endl;
        return 1;
    }
//    if(dp[sum] != -1)
//        return dp[sum];
    
    vector<int> temp1(elements.begin(), elements.end()), temp2(elements.begin(), elements.end());
    temp1.push_back(1);
    temp2.push_back(2);
    int total = findAllPermutations(sum + 1, finalSum, dp, temp1) + findAllPermutations(sum + 2, finalSum, dp, temp2);
//    dp[sum] = total;
    return total;
}

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    vector<int> dp(num, -1), temp;
    cout << findAllPermutations(0,num, dp, temp) << endl;
    cout << climbStairs(num) << endl;
    return 0;
}
