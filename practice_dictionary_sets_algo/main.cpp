//
//  main.cpp
//  practice_dictionary_sets_algo
//
//  Created by Dheeraj Reddy on 15/02/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    map<int,int> dict;
    dict.insert(make_pair(10,20));
    dict.insert(make_pair(4,23));
    dict.insert(make_pair(5,15));
    dict.insert(make_pair(6,29));
    for(auto x:dict) {
        cout << x.first << " " <<x.second<<endl;
    }
    map<int,int>::iterator it = dict.find(6);
    if(it != dict.end())
        cout << it->first << " " << it->second<<endl;
    else
        cout<<"Whoo hoo"<<endl;
    //dict.clear();
    map<int,int>::iterator it1;
    for(it1 = dict.begin(); it1 != dict.end();it1++) {
        it1->second = 1;
    }
    
    for(auto x:dict) {
        cout << x.first << " " << x.second <<endl;
    }
    
    vector<int> vec = {1,2,3,4,5,6,6,6};
    set<int> s(vec.begin(), vec.end());
    multiset<int> s1(vec.begin(), vec.end());
    for(auto x:s)
        cout << x << endl;
    s.insert(20);
    s.insert(10);
//    for(auto x:s)
//        cout << x << endl;
    set<int>::iterator ite = s.find(6);
    if(ite != s.end())
        s.erase(ite);
    for(auto x:s)
        cout << x << endl;
    
    set<int>::iterator ite1 = s.lower_bound(8);
    if(ite != s.end())
        cout << *ite1;
    
    return 0;
}
