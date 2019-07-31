//
//  main.cpp
//  DELISH
//
//  Created by Dheeraj Reddy on 07/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

typedef long long  ll;

using namespace std;

ll find_max(ll int1, ll int2) {
    return int1 > int2 ? int1 : int2;
}

ll find_min(ll int1, ll int2) {
    return int1 < int2 ? int1 : int2;
}

ll find_abs(ll int1) {
    return int1 < 0 ? -int1 : int1;
}


int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<ll> D(N), maxLeft(N), maxRight(N), minLeft(N), minRight(N);
        for(int i=0;i<N;i++)
            cin >> D[i];
        
        maxLeft[0] = D[0];
        minLeft[0] = D[0];
        ll leftValue = find_max(0,D[0]);
        ll leftMinValue = find_min(0,D[0]);
        for(int i=1;i<N;i++) {
            ll temp = max(maxLeft[i-1], D[i]);
            maxLeft[i] = find_max(D[i] + leftValue, temp);
            leftValue = find_max(0, leftValue + D[i]);
            
            temp = min(minLeft[i-1], D[i]);
            minLeft[i] = find_min(D[i] + leftMinValue, temp);
            leftMinValue = find_min(0, leftMinValue + D[i]);
        }
        
        maxRight[N-1] = D[N-1];
        minRight[N-1] = D[N-1];
        ll rightValue = find_max(0,D[N-1]);
        ll rightMinValue = find_min(0,D[N-1]);
        for(int i=N-2;i>=0;i--) {
            ll temp = find_max(D[i], maxRight[i+1]);
            maxRight[i] = find_max(D[i] + rightValue, temp);
            rightValue = find_max(0,rightValue + D[i]);
            
            temp = find_min(minRight[i+1], D[i]);
            minRight[i] = find_min(D[i] + rightMinValue, temp);
            rightMinValue = find_min(0, rightMinValue + D[i]);
        }
        
        ll ans = LLONG_MIN;
        
        for(int i=0;i<N-1;i++) {
            ans = find_max(ans, find_abs(maxLeft[i] - minRight[i+1]));
            ans = find_max(ans, find_abs(minLeft[i] - maxRight[i+1]));
        }
        cout << ans <<endl;
    }
    return 0;
}
