//
//  main.cpp
//  using_map
//
//  Created by Dheeraj Reddy on 23/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    map<int, int> s;
    s.insert({3,4});
    s.insert({5,1});
    s.insert({6,6});
    s.insert({7,9});
    /*for (auto x: s)
    {
        cout <<x.first<< "  "<<x.second<<endl;
        x.
    }*/
    s.erase(s.find(8));
    
    for( auto x: s)
        cout << x.first << x.second <<endl;
    
    map<int, int>::iterator it;
    
    return 0;
}
