//
//  main.cpp
//  kickstart_practiceround_1
//
//  Created by Dheeraj Reddy on 23/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool binary_search_num(int lower, int higher) {
    
    int search = lower + (higher - lower)/2;
    string str;
    cout << search<<endl;
    getline(cin, str);
    if( str == "TOO_BIG")
        return binary_search_num(lower, search-1);
    else if (str == "TOO_SMALL")
        return binary_search_num(search+1, higher);
    else if(str == "CORRECT")
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    string str_T;
    getline(cin, str_T);
    //cin >> str_T;
    int T;
    T = stoi(str_T);
    while(T--) {
        //cin.ignore();
        string str_a_b, str_N;
        int a,b,n,temp;
        getline(cin, str_a_b);
        istringstream iss(str_a_b,istringstream::in);
        vector<int> temp_vector;
        while(iss >> temp)
            temp_vector.push_back(temp);
        a = temp_vector[0];
        b = temp_vector[1];
        getline(cin, str_N);
        n = stoi(str_N);
        binary_search_num(a+1, b);
    }
    return 0;
}
