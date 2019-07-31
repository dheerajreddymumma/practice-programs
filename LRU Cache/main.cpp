//
//  main.cpp
//  LRU Cache
//
//  Created by Dheeraj Reddy on 05/06/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int,int>> mlist;
    map<int, list<pair<int,int>>::iterator> mp;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto itr = mp.find(key);
        int value = -1;
        if(itr != mp.end()) {
            mlist.splice(mlist.begin(), mlist, itr->second);
            return itr->second->second;
        }
        return value;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            mlist.splice(mlist.begin(), mlist, it->second);
            auto itr = mlist.begin();
            itr->second = value;
            return;
        }
        if(mp.size() >= capacity) {
            auto pr = mlist.back();
            mlist.pop_back();
            auto itp = mp.find(pr.first);
            mp.erase(itp);
        }
        mlist.push_front({key,value});
        mp[key] = mlist.begin();
    }
};

int main(int argc, const char * argv[]) {
//    LRUCache cache( 2 );
//
//    cache.put(1, 1);
//    cache.put(2, 2);
//    cout << cache.get(1) << endl;       // returns 1
//    cache.put(3, 3);    // evicts key 2
//    cout << cache.get(2) << endl;       // returns -1 (not found)
//    cache.put(4, 4);    // evicts key 1
//    cout << cache.get(1) << endl;       // returns -1 (not found)
//    cout << cache.get(3) << endl;       // returns 3
//    cout << cache.get(4) << endl;       // returns 4
    
    unordered_set<vector<int>> vec;
    vector<int> v1 = {1,2,3}, v2 = {2,3,4},v3 = {1,2,3};
    vec.insert(v1);
    vec.insert(v2);
    vec.insert(v3);
    for(auto x: vec) {
        
        for(auto y: x) {
            cout << y << " ";
        }
            
        cout << endl;
    }
    return 0;
}
