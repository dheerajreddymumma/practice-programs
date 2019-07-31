//
//  main.cpp
//  STICKS
//
//  Created by Dheeraj Reddy on 29/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    int T = 0;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)
            cin >> arr[i];
        vector<int> v1(arr,arr+N);
        sort(v1.begin(), v1.end(), greater<int>());
        int found = 0, val_1[2];
        for(int i=0; i<N-1;i++) {
            if(v1[i] == v1[i+1]){
                val_1[found] = v1[i];
                i+=1;
                found +=1;
            }
            if(found >= 2)
                break;
        }
        if(found == 2)
            cout << val_1[0] * val_1[1] <<endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
