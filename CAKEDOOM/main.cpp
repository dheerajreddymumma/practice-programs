//
//  main.cpp
//  CAKEDOOM
//
//  Created by Dheeraj Reddy on 25/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool flag = false;
bool findMinCombination(string &s, int length, int index, int K) {
    if (index == length)
        return true;
    
    int leftValue, rightValue;
    if (index == 0) {
        if (s[length - 1] != '?')
            leftValue = (int)s[length - 1] - 48;
        else
            leftValue = -1;
        
        if (s[index + 1] != '?')
            rightValue = (int)s[index + 1] - 48;
        else
            rightValue = -1;
    }
    else if (index == (length - 1)) {
        if (s[index - 1] != '?')
            leftValue = (int)s[index - 1] -48;
        else
            leftValue = -1;
        
        if (s[0] != '?')
            rightValue = (int)s[0] - 48;
        else
            rightValue = -1;
    }
    else {
        if (s[index - 1] != '?')
            leftValue = (int)s[index - 1] - 48;
        else
            leftValue = -1;
        
        if (s[index + 1] != '?')
            rightValue = (int)s[index + 1] - 48;
        else
            rightValue = -1;
    }
    bool result;
    if (s[index] == '?') {
        for (int i = 0; i < K; i++) {
            if (i != leftValue && i != rightValue) {
                s[index] = i + '0';
                result = findMinCombination(s, length, index + 1, K);
                if (result == true)
                    return true;
                if (flag == true)
                    return false;
            }
        }
        s[index] = '?';
    }
    else {
        int currentValue = (int)s[index] - 48;
        if (currentValue == leftValue)
        {
            flag = true;
            return false;
        }
        result = findMinCombination(s, length, index + 1, K);
        if (result == true)
            return true;
        flag = true;
        return false;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    while(n--) {
        int k = 0, length = 0;
        cin >> k;
        k = min(3,k);
        string s;
        cin >> s;
        length = s.size();
        flag = false;
        bool result = findMinCombination(s, length, 0, k);
        if (result == true)
            cout<<s<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
