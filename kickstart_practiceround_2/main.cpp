//
//  main.cpp
//  kickstart_practiceround_2
//
//  Created by Dheeraj Reddy on 24/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string str_T;
    int T;
    getline(cin,str_T);
    T = stoi(str_T);
    for(int j=1;j<=T;j++) {
        string str_numbers, str_N;
        int N;
        getline(cin, str_N);
        N = stoi(str_N);
        getline(cin,str_numbers);
        vector<int> numbers;
        
        for(auto x: str_numbers)
            numbers.push_back(int(x) - 48);
        
        int window_size = (N + 2 -1)/2, value = 0, best_ans = 0;
        for(int i=0;i<window_size;i++) {
            value += numbers[i];
        }
        best_ans = value;
        
        for(int i = window_size; i<N;i++) {
            value -= numbers[i-window_size];
            value += numbers[i];
            if(value > best_ans)
                best_ans = value;
        }
        cout << "Case #" << j << ": " << best_ans <<endl;
    }
    return 0;
}
