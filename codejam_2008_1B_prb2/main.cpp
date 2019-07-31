//
//  main.cpp
//  codejam_2008_1B_prb2
//
//  Created by Dheeraj Reddy on 21/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<ll> findPrimeFactors(ll A, ll B, ll P) {
    ll llerval = B - A + 1;
    vector<ll> primeFactors;
    for(ll i = P; i <= llerval && i <= (ll)B/2; i++) {
        bool is_prime = true;
        for(ll j=2; j<=(ll)sqrt(i); j++)
            if(i%j == 0) {
                is_prime = false;
                break;
            }
        if(is_prime)
            primeFactors.push_back(i);
    }
    return primeFactors;
}

ll findParent(vector<pair<ll,ll> > &positions, ll index) {
    ll index1 = index;
    while(positions[index1].first != -1)
        index1 = positions[index1].first;
    return index1;
}

void findParentAndMerge(vector<pair<ll,ll> > &positions, ll index1, ll index2) {
    ll parent1, parent2;
    parent1 = findParent(positions, index1);
    parent2 = findParent(positions, index2);
    if(parent1 == parent2)
        return;
    
    if(positions[parent1].second >= positions[parent2].second) {
        positions[parent1].second += positions[parent2].second;
        positions[parent2].first = parent1;
    }
    else {
        positions[parent2].second += positions[parent1].second;
        positions[parent1].first = parent2;
    }
}

int main(int argc, const char * argv[]) {
    int C;
    cin >> C;
    for (int c = 1; c <= C; c++) {
        ll A,B,P;
        cin >> A >> B >> P;
        vector<ll> primeFactors = findPrimeFactors(A, B, P);
        
        vector<pair<ll,ll> > positions(B - A + 1, make_pair(-1, 1));
        for(ll i=0;i<primeFactors.size();i++) {
            ll num = A;
            ll remainder = A % primeFactors[i];
            if(remainder != 0)
                num = A + (primeFactors[i] - remainder);
            ll quotient = num / primeFactors[i];
            while(((quotient + 1) * primeFactors[i]) <= B) {
                findParentAndMerge(positions, (quotient * primeFactors[i]) - A, ((quotient + 1) * primeFactors[i]) - A);
                quotient++;
            }
        }
        ll count = 0;
        for(auto x: positions)
            if(x.first == -1)
                count++;
        cout << "Case #" << c << ": " << count << endl;
    }
    return 0;
}
