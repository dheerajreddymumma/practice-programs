//
//  main.cpp
//  BIASED
//
//  Created by Dheeraj Reddy on 29/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(int argc, const char * argv[]) {
    ll T;
    cin >> T;
    while(T--) {
        ll num, index, ans = 0;
        cin >> num;
        vector<int> v1(num);
        string s1;
        for(int i=0;i<num;i++) {
            cin >>s1;
            cin >> v1[i];
        }
        sort(v1.begin(), v1.end());
        
        for(ll i=0;i<num;i++) {
            index = i + 1;
            ans += abs(v1[i] - index);
        }
        cout<<ans<<endl;
    }
    return 0;
}
