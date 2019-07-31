//
//  main.cpp
//  vishvaas_balls
//
//  Created by Dheeraj Reddy on 19/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int calculateDistance(vector<int> arr, int num) {
    vector<int> minLeft(num), maxRight(num);
    
    minLeft[0] = arr[0];
    for(int i=1;i<num;i++)
        minLeft[i] = min(minLeft[i-1], arr[i]);
    
    maxRight[num-1] = arr[num-1];
    for(int i=num-2;i>=0;i--)
        maxRight[i] = max(maxRight[i+1], arr[i]);
    
    int maxDiff = -1;
    int i = 0, j = 0;
    
    while( i < num && j < num ) {
        if (maxRight[i] <= minLeft[j])
            j += 1;
        else if (maxRight[i] > minLeft[j]) {
            maxDiff = max((i-j), maxDiff);
            i += 1;
        }
    }
    return maxDiff;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num, temp;
    cin >> num;
    vector<int> arr;
    for(int i=0; i<num; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    cout << calculateDistance(arr, num);
    
    return 0;
}
