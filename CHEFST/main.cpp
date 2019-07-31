//
//  main.cpp
//  CHEFST
//
//  Created by Dheeraj Reddy on 23/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    long long N;
    cin >> N;
    while(N--){
        long long n1, n2, m, range_num, total;
        cin >> n1 >> n2 >> m;
        range_num = ( m * (m + 1) ) / 2;
        long long min_num = min(n1, n2);
        long long max_num = max(n1, n2);
        if(range_num <= min_num)
            total = n1 + n2 - (2 * range_num);
        else
            total = max_num - min_num;
        cout << total << "\n";
    }
    return 0;
}
