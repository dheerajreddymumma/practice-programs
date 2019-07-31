//
//  main.cpp
//  logs
//
//  Created by Dheeraj Reddy on 27/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//vector<int> dailyTemperatures(vector<int>& T) {
//    vector<int> temperatures(T.size(), 0);
//    int size = T.size();
//    for(int i= size-2;i>=0;i--) {
//        if(T[i] < T[i+1])
//            temperatures[i] = 1;
//        else {
//            int nextIndex = i+1 + temperatures[i+1];
//            while(temperatures[nextIndex] != 0) {
//                if(T[i] < T[nextIndex]) {
//                    temperatures[i] = nextIndex - i;
//                    break;
//                }
//                else
//                    nextIndex += temperatures[nextIndex];
//            }
//            if(temperatures[nextIndex] == 0 && T[i] < T[nextIndex])
//                temperatures[i] = nextIndex - i;
//        }
//    }
//    return temperatures;
//}

bool sortFunction(vector<int> v1, vector<int> v2) {
    if(v1[1] < v2[1])
        return true;
    if(v1[1] > v2[1])
        return false;
    if(v1[0] <= v2[0])
        return true;
    return false;
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), sortFunction);
    int index = 0, size = people.size();
    vector<vector<int>> vec;
    
    for(int i=0;i<size;i++) {
        
        int count = people[i][1], foundSoFar = 0, flag = 0;
        vector<vector<int>>::iterator it = vec.begin();
        for(int j=0;j<vec.size();j++) {
            if(vec[j][0] >= people[i][0])
                foundSoFar++;
            if(foundSoFar == count+1) {
                it = vec.begin() + j;
                vec.insert(it, {people[i][0], people[i][1]});
                flag = 1;
                break;
            }
            it++;
        }
        if(it == vec.end() && flag == 0) {
            vec.insert(it, {people[i][0], people[i][1]});
        }
    }
    return vec;
}

int main(int argc, const char * argv[]) {
    //vector<int> vec= {73,74,75,71,69,72,76,73};
    //dailyTemperatures(vec);
    vector<vector<int>> vec = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    sort(vec.begin(), vec.end(), sortFunction);
//    vector<vector<int>>::iterator it1 = vec.end();
//    vec.insert(it1, {1,2});
    for(int i=0;i<vec.size();i++) {
        cout << vec[i][0] << " " << vec[i][1] << endl;
    }
    
    reconstructQueue(vec);
    return 0;
}
