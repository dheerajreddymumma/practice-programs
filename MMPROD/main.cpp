//
//  main.cpp
//  MMPROD
//
//  Created by Dheeraj Reddy on 27/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    
//    short int t;
//    cin >> t;
//    while(t--) {
//        int N, K, M, total = 0;
//        cin >> N >> K >> M;
//        total = K + M;
//        int arr1[N], temp;
//
//        for(int i=0;i<N;i++)
//            cin >> arr1[i];
//
//        for(int i = 0; i<N; i++) {
//            cin >> temp;
//            arr1[i] -= temp;
//        }
//
//        int ans = 0;
//        multiset<int> v1;
//
//        for(int i =0;i<total;i++) {
//            cin >> temp;
//            v1.insert(temp);
//        }
//
//        for(int i=0;i<N;i++) {
//            if(v1.size() == 0) {
//                ans += arr1[i];
//                continue;
//            }
//            multiset<int>::iterator it = lower_bound(v1.begin(), v1.end(), arr1[i]);
//            if (it != v1.end() && *it == arr1[i]) {
//                v1.erase(it);
//            }
//            else{
//                if(it == v1.begin()) {
//                    ans += arr1[i];
//                }
//                else {
//                    it = it - 1;
//                    ans = ans + arr1[i] - *it;
//                    v1.erase(it);
//                }
//            }
//        }
//        cout << ans <<endl;
//    }
    multiset<int> v1;
    v1.insert(30);
    v1.insert(40);
    v1.insert(20);
    v1.insert(20);
    v1.insert(10);
    multiset<int>::iterator it = lower_bound(v1.begin(), v1.end(), 15);
    cout << it - v1.begin() <<endl;
    return 0;
}
