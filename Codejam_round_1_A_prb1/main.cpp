//
//  main.cpp
//  Codejam_round_1_A_prb1
//
//  Created by Dheeraj Reddy on 13/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int t = 1; t<= T; t++) {
        int N;
        cin >> N;
        vector<string> W(N);
        for(int i =0;i<N;i++)
            cin >> W[i];
        
        map<string,vector<string>> mp;
        
        for(int i=0;i<N;i++) {
            char temp = W[i][W[i].size()-1];
            string s1(1,temp);
            map<string,vector<string>>::iterator it = mp.find(s1);
            if(it == mp.end()) {
                vector<string> v1;
                v1.push_back(W[i]);
                mp.insert(make_pair(s1,v1));
            }
            else
                it->second.push_back(W[i]);
        }
        
        
        int answer = 0;
        map<string, vector<string>>::iterator it1 = mp.begin();
        while(it1 != mp.end()) {
            map<string, vector<string>>::iterator tempIT;
            if(it1->second.size() == 1) {
                tempIT = it1;
                it1++;
                mp.erase(tempIT);
            }
            else if (it1->second.size() == 2 || it1->second.size() == 3) {
                tempIT = it1;
                it1++;
                mp.erase(tempIT);
                answer += 2;
            }
            else {
                answer += 2;
                it1++;
            }
        }
        int count = 2;
        while(!mp.empty()) {
            map<string,vector<string>>::iterator it3 = mp.begin();
            map<string, vector<string>> mp2;
            while(it3 != mp.end()) {
                string s3 = it3->first;
                
                for(auto str: it3->second) {
                    //cout << "Size: "<<str.size()<<" count: "<<count<<endl;
                    if(((int)str.size() - count) >= 0) {
                        char ch2 = str[str.size() - count];
                        string s_2;
                        s_2 = ch2+s3;
                        map<string,vector<string>>::iterator it4 = mp2.find(s_2);
                        if(it4 == mp2.end()) {
                            vector<string> v8;
                            v8.push_back(str);
                            mp2.insert(make_pair(s_2,v8));
                        }
                        else {
                            it4->second.push_back(str);
                        }
                    }
                }
                
                map<string, vector<string>>::iterator it5 = mp2.begin();
                while(it5 != mp2.end()) {
                    map<string, vector<string>>::iterator tempIT2;
                    if(it5->second.size() == 1) {
                        tempIT2 = it5;
                        it5++;
                        mp2.erase(tempIT2);
                    }
                    else if (it5->second.size() == 2 || it5->second.size() == 3) {
                        tempIT2 = it5;
                        it5++;
                        mp2.erase(tempIT2);
                        answer += 2;
                    }
                    else {
                        answer += 2;
                        it5++;
                    }
                }
                count++;
                it3++;
            }
            mp = mp2;
        }
        cout << "Case #" <<t<<": "<<min(answer, N) <<endl;
    }

    return 0;
}
