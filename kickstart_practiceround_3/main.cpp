//
//  main.cpp
//  kickstart_practiceround_3
//
//  Created by Dheeraj Reddy on 24/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <sstream>
typedef long long ll;
using namespace std;

map<ll,ll> calculate_dict(ll N, ll K) {
    map<ll,ll> dict;
    
    for(ll i=1;i<=N;i++) {
        if(i==1) {
            dict.insert(make_pair(1,K));
            continue;
        }
        ll sum = 0;
        sum = i * ((1 - pow(i,K))/(1-i));
        dict.insert(make_pair(i, sum));
    }
    return dict;
}


ll calculate_sum(vector<ll> vec, ll N, ll K) {
    map<ll, ll> dict;
    dict = calculate_dict(N, K);
    ll ans = 0;
    ll n_value = N, K_value = 1;
    for(ll i=0;i<N;i++) {
        ll temp = 0;
        for(ll j=1; j<=K_value;j++)
            temp += dict[j];
        ans += (vec[i] * n_value * temp);
        n_value--;
        K_value++;
    }
    return ans % 1000000007;
}

int main(int argc, const char * argv[]) {
    string str_T;
    getline(cin,str_T);
    int T;
    T = stoi(str_T);
    for(int itr = 1;itr<=T;itr++) {
        string str_N;
        getline(cin, str_N);
        istringstream iss(str_N,istringstream::in);
        vector<ll> temp_vector;
        vector<ll> vec;
        ll temp;
        while(iss >> temp)
            temp_vector.push_back(temp);
        ll N = temp_vector[0], K = temp_vector[1], x1 = temp_vector[2], y1 = temp_vector[3], C = temp_vector[4], D = temp_vector[5],
        E1 = temp_vector[6], E2 = temp_vector[7], F = temp_vector[8], previous_x,previous_y;
        vec.push_back((x1 + y1)%F);
        previous_x = x1;
        previous_y = y1;
        for(ll i=2;i<=N;i++) {
            x1 = (C * previous_x + D * previous_y + E1) % F;
            y1 = (D * previous_x + C * previous_y + E2) % F;
            vec.push_back((x1 + y1)%F);
            previous_x = x1;
            previous_y = y1;
        }
        cout << "Case #" << itr << ": " << calculate_sum(vec, N, K) <<endl;
    }
//    vector<ll> vec = {6,1};
//    cout << calculate_sum(vec, 2, 8) <<endl;
    return 0;
}
