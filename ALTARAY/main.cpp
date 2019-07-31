//
//  main.cpp
//  ALTARAY
//
//  Created by Dheeraj Reddy on 06/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int get_sign(int num) {
    if(num >= 0)
        return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<int> ans(N);
        for(int i=0;i<N;i++) {
            cin >> A[i];
        }
        ans[N-1] = 1;
        for(int i = N-2;i >= 0; i--) {
            if(get_sign(A[i]) == get_sign(A[i+1]))
                ans[i] = 1;
            else
                ans[i] = ans[i+1] + 1;
        }
        for(int i=0;i<N;i++)
            cout << ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
