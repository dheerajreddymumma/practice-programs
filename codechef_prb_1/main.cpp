//
//  main.cpp
//  codechef_prb_1
//
//  Created by Dheeraj Reddy on 06/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
int main(int argc, const char * argv[]) {
    int T,iter_count = 1;
    cin >> T;
    while(T--) {
        ll N, temp_N, N2=0, count = 0, remainder, digit;
        cin >> N;
        temp_N = N;
        while(temp_N) {
            remainder = temp_N % 10;
            if(remainder == 4) {
                digit = pow(10,count);
                N -= digit;
                N2 += digit;
            }
            temp_N /= 10;
            count++;
        }
        cout << "Case #" << iter_count++ << ": "<<N<<" "<<N2 <<endl;
    }
    return 0;
}
