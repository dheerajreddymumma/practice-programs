//
//  main.cpp
//  codejam_2008_prb2
//
//  Created by Dheeraj Reddy on 13/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
//using namespace std;

std::pair<std::string, std::string> split(std::string str, char delimiter) {
    std::stringstream ss(str);
    std::string s1, s2, temp;
    int i = 0;
    while(getline(ss,temp, delimiter)) {
        if(i==0) {
            i++;
            s1 = temp;
        }
        else
            s2 = temp;
    }
    return make_pair(s1,s2);
}

std::pair<int,int> add_some_time(std::string hours, std::string minutes, int turn_around_time) {
    int hour = stoi(hours), minute = stoi(minutes);
    if(minute + turn_around_time < 60)
        minute = minute + turn_around_time;
    else {
        hour += ((minute + turn_around_time)/60);
        minute = ( minute + turn_around_time ) % 60;
    }
    return std::make_pair(hour,minute);
}

void get_train_schedule(int num_trains, std::vector<std::pair<int,int> > &DT, std::vector<std::pair<int,int> > &ST, int T) {
    std::pair<std::string,std::string> p1,p2;
    char schedule[100];
    for(int i=0;i<num_trains;i++) {
        
        std::cin.getline(schedule, 100);
        p1= split(schedule, ' ');
        
        p2 = split(p1.first, ':');
        DT.push_back(std::make_pair(stoi(p2.first), stoi(p2.second)));
        
        p2 = split(p1.second, ':');
        ST.push_back(add_some_time(p2.first, p2.second, T));
    }
}

bool comp(std::pair<int,int> p1, std::pair<int,int> p2) {
    if(p1.first < p2.first)
        return true;
    if(p1.first > p2.first)
        return false;
    if(p1.second < p2.second)
        return true;
    if(p1.second > p2.second)
        return false;
    return true;
}

int get_count(std::vector<std::pair<int,int> > DT, std::vector<std::pair<int,int> > ST) {
    int st_count = 0, answer = 0;
    for(int i=0;i<DT.size();i++){
        if(st_count == ST.size()) {
            answer++;
            continue;
        }
        if(comp(ST[st_count],DT[i]))
            st_count++;
        else
            answer++;
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    int N;
    std::cin >> N;
    //cin >> ws;
 //   cin.ignore(256, '\n');
    for(int t=1;t<=N;t++) {
        int T, NA, NB;
        std::cin >> T;
        std::cin.ignore(256, '\n');
        //cin >> ws;
        std::string temp;
        getline(std::cin, temp);
        std::pair<std::string, std::string> p1 = split(temp,' ');
        NA = stoi(p1.first);
        NB = stoi(p1.second);

        std::vector<std::pair<int,int> > DT1, ST1, DT2, ST2;
        
        get_train_schedule(NA, DT1, ST2, T);
        
        get_train_schedule(NB, DT2, ST1, T);
        
        sort(DT1.begin(), DT1.end(), comp);
        sort(ST1.begin(), ST1.end(), comp);
        sort(DT2.begin(), DT2.end(), comp);
        sort(ST2.begin(), ST2.end(), comp);
        
        int answer, answer2;
        
        answer = get_count(DT1, ST1);
        answer2 = get_count(DT2, ST2);
        //if(t==9) {
        std::cout << "Case #" << t << ": " << answer << " " << answer2 << std::endl;
        //}
    }
    return 0;
}
