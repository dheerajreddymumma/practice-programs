//
//  main.cpp
//  MSTICK
//
//  Created by Dheeraj Reddy on 15/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pr;
bool sortPairs(pr p1, pr p2) {
    if(p1.first > p2.first)
        return true;
    else if (p1.first < p2.first)
        return false;
    else {
        if(p1.second > p2.second)
            return true;
        return false;
    }
}
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--) {
        int numPairs;
        cin >> numPairs;
        vector<pair<int,int>> pairs;
        for(int i=0;i<numPairs;i++) {
            int height, width;
            cin >> height >> width;
            pairs.push_back(make_pair(height, width));
        }
        sort(pairs.begin(), pairs.end(), sortPairs);
        
        vector<int> ans;
        ans.push_back(pairs[0].second);
        for(int i=1;i<numPairs;i++){
            vector<int>::iterator it1 = lower_bound(ans.begin(), ans.end(), pairs[i].second);
            if(it1 == ans.end())
                ans.push_back(pairs[i].second);
            else
                *it1 = pairs[i].second;
        }
        cout << ans.size() <<endl;
    }
    return 0;
}
