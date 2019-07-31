//
//  main.cpp
//  codejam_2008_1A_prb1
//
//  Created by Dheeraj Reddy on 14/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n;
        cin >> n;
        vector<long long> v1(n),v2(n);
        for(int i=0;i<n;i++)
            cin >> v1[i];
        sort(v1.begin(), v1.end());
        for(int i=0;i<n;i++)
            cin>>v2[i];
        sort(v2.begin(), v2.end(), greater<long long>());
        long long answer = 0;
        for(int i=0;i<n;i++)
            answer += (v1[i] * v2[i]);
        cout << "Case #" << t << ": " << answer << "\n";
    }
    return 0;
}
