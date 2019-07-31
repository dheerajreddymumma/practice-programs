//
//  main.cpp
//  codejam_2008_1C_prb1
//
//  Created by Dheeraj Reddy on 23/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int P, K, L;
        cin >> P >> K >> L;
        vector<ll> num(L);
        for(int i=0;i<L; i++)
            cin >> num[i];
        sort(num.begin(), num.end(), greater<ll>());
        ll product = 0, count = 0;
        for(int i=0;i<num.size();i++) {
            if(i%K == 0)
                product += 1;
            count = count + (product * num[i]);
        }
        cout << "Case #" << t << ": " << count << endl;
    }
    set<char> s1;
    
    return 0;
}
