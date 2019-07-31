//
//  main.cpp
//  MAXDIFF
//
//  Created by Dheeraj Reddy on 23/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    while(T--) {
        int N, K, total=0, ind;
        cin >> N >> K;
        vector<int> arr(N);
        for(int i = 0;i<N;i++) {
            cin >> arr[i];
            total += arr[i];
        }
        sort(arr.begin(),arr.end(),[] (int a, int b){return a > b;});
        ind = max(K, N-K);
        int max_total = 0;
        for(int i = 0; i<ind; i++)
            max_total += arr[i];
        cout << (max_total - (total - max_total)) << endl;
    }
    
    return 0;
}
