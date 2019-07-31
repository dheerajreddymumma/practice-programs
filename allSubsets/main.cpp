//
//  main.cpp
//  allSubsets
//
//  Created by Dheeraj Reddy on 27/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printSubsets(vector<int> subset, vector<int> vec) {
    if(subset.size() == vec.size()) {
        for(int i=0;i<subset.size();i++)
            if(subset[i] == 1)
                cout << vec[i] << " ";
        cout << endl;
        return;
    }
    subset.push_back(0);
    printSubsets(subset, vec);
    subset.pop_back();
    subset.push_back(1);
    printSubsets(subset, vec);
    subset.pop_back();
}

int main(int argc, const char * argv[]) {
//    vector<int> vec = {1,2,4,8,16};
//    int total = pow(2,5);
//    for(int i=1;i<total;i++) {
//        vector<int> temp;
//        for(int j=0;j<5;j++)
//            if(i & 1 << j)
//                temp.push_back(vec[j]);
//        for(int j =0; j< temp.size(); j++)
//            cout << temp[j] << " ";
//        cout << endl;
//    }
    vector<int> vec = {1,2,4,8,16}, temp;
    printSubsets(temp, vec);
    return 0;
}
