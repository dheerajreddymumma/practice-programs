//
//  main.cpp
//  testingdatastructures
//
//  Created by Dheeraj Reddy on 22/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int singleNumber(vector<int> nums) {
    unordered_set<int> numSet;
    for(int i = 0; i < nums.size(); i++) {
        unordered_set<int>::iterator it1 =  numSet.find(nums[i]);
        if(it1 != numSet.end())
            numSet.erase(it1);
        else
            numSet.insert(nums[i]);
    }
    unordered_set<int>::iterator it2 = numSet.begin();
    return *it2;
}

int main(int argc, const char * argv[]) {
    
    vector<int> nums = [0];
    vector<int>::iterator it1 = nums.begin();
    long initialSize = nums.size(), i=1, negateCount = 0;
    
    while(nums.size() - i >= 0 && nums[nums.size() - i] == 0) {
        negateCount++;
        i++;
    }
    
    i = 0;
    while(i < (initialSize - negateCount)) {
        if(*it1 == 0) {
            vector<int>::iterator it2 = it1;
            nums.erase(it2);
            nums.push_back(0);
        }
        else
            it1++;
        i++;
    }
    for(auto x: nums) {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}
