//
//  main.cpp
//  stringPermutations
//
//  Created by Dheeraj Reddy on 25/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int find_next_permutation(string &s) {
    int i = s.size() - 1;
    while(i-1 >= 0 && s[i] < s[i-1])
        i--;
    if(i == 0)
        return 0;
    
    int smallestOneLarger = INT_MAX, smallestIndex=0;
    for(int j= i; j < s.size(); j++)
        if(s[j] > s[i-1] && s[j] < smallestOneLarger)
            smallestIndex = j;
    
    char c = s[i-1];
    s[i-1] = s[smallestIndex];
    s[smallestIndex] = c;
    
    sort(s.begin()+i,s.end());
    cout << s <<endl;
    return 1;
}

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << s <<endl;
    int flag = 1, count = 0;
    while( flag == 1) {
        flag = find_next_permutation(s);
        count++;
    }
    cout <<count <<endl;
    return 0;
}
