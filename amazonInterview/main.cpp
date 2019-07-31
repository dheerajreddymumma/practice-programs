//
//  main.cpp
//  amazonInterview
//
//  Created by Dheeraj Reddy on 28/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int minimumTime(int numOfParts, int *parts) {
    if(numOfParts == 0)
        return 0;
    if(numOfParts == 1)
        return parts[0];
    
    vector<int> vec(parts, parts + numOfParts);
    make_heap(vec.begin(), vec.end(), greater<int>());
    int ans = 0;
    while(vec.size() != 1) {
        int first = vec[0];
        pop_heap(vec.begin(), vec.end(), greater<int>());
        vec.pop_back();
        int second = vec[0];
        pop_heap(vec.begin(), vec.end(), greater<int>());
        vec.pop_back();
        ans += first + second;
        vec.push_back(first+second);
        make_heap(vec.begin(), vec.end(), greater<int>());
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int *p = new int[4];
    p[0] = 8;
    p[1] = 4;
    p[2] = 6;
    p[3] = 12;
    minimumTime(4, p);
    return 0;
}
