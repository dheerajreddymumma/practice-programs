//
//  main.cpp
//  FROGV
//
//  Created by Dheeraj Reddy on 11/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int comp(pair<ll,ll> int1, pair<ll,ll> int2) {
    if(int1.first < int2.first)
        return 1;
    return 0;
}

int main(int argc, const char * argv[]) {
    int P,N,K;
    cin >> N >> K >> P;
    vector<pair<ll, ll>> vec, vec1;
    ll num;
    for(int i=0;i<N;i++) {
        cin >> num;
        //vec.push_back(make_pair(num, i));
        vec1.push_back(make_pair(num, i));
    }
    
    sort(vec1.begin(), vec1.end(), comp);
    
    //for(int i=0;i<N;i++)
    //    vec[vec1[i].second].second = i;
    
    vector<ll> uf(N);
//
    uf[0] = 0;
//    for(int i=1;i<N;i++)
//        uf[i] = vec1[i].first - vec1[i-1].first <= K ? uf[i-1] : i;
//
    for(int i=1;i<N;i++) {
        uf[vec1[i].second] = vec1[i].first - vec1[i-1].first <= K ? uf[vec1[i-1].second] : i;
    }
    
    while(P--) {
        ll i,j;
        cin >> i >> j;
        if(uf[i-1] == uf[j-1])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
