//
//  main.cpp
//  hackerrank
//
//  Created by Dheeraj Reddy on 29/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
bool compa(string s1, string s2) {
    return s1.length() < s2.length();
}

string arrange(string sentence) {
    if(sentence.length() == 0)
        return sentence;
    vector<string> s1;
    string temp = "";
    for(auto i : sentence) {
        if(i == ' ') {
            s1.push_back(temp);
            temp = "";
        }
        else if(i == '.') {
            s1.push_back(temp);
            temp = "";
        }
        else if(i >= 'A' && i <= 'Z')
            temp += (char)((int)i + 32);
        else
            temp += i;
    }
    stable_sort(s1.begin(), s1.end(), compa);
    s1[0][0] = (char)((int)s1[0][0] - 32);
    
    string ans = "";
    for(int i=0;i<s1.size()-1;i++)
        ans += s1[i] + " ";
    ans += s1[s1.size()-1] + ".";
    return ans;
}

bool checkForChar(vector<vector<char>>& board, string word, int index, int row, int col, vector<vector<bool>>& visited) {
    visited[row][col] = true;
    if(index == word.size())
        return true;
    if(row - 1 >= 0 && !visited[row-1][col] && board[row-1][col] == word[index])
        if(checkForChar(board, word, index+1, row-1, col, visited))
            return true;
    if(row + 1 < board.size() && !visited[row+1][col] && board[row+1][col] == word[index])
        if(checkForChar(board, word, index+1, row+1, col, visited))
            return true;
    if(col - 1 >= 0 && !visited[row][col-1] && board[row][col-1] == word[index])
        if(checkForChar(board, word, index+1, row, col-1, visited))
            return true;
    if(col + 1 < board[0].size() && !visited[row][col+1] && board[row][col+1] == word[index])
        if(checkForChar(board, word, index+1, row, col+1, visited))
            return true;
    visited[row][col] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
            if(board[i][j] == word[0]) {
                if(checkForChar(board, word, 1, i, j, visited))
                    return true;
            }
        }
    }
    return false;
}

int maxProduct(vector<int>& nums) {
    if(nums.size() == 1)
        return nums[0];
    vector<int> maxProduct(nums.size()), absMaxProduct(nums.size());
    int ans;
    maxProduct[0] = absMaxProduct[0] = ans = nums[0];
    for(int i=1;i<nums.size();i++) {
        maxProduct[i] = max(nums[i], maxProduct[i-1] * nums[i]);
        
        absMaxProduct[i] = absMaxProduct[i-1] * nums[i];
        
        ans = max(ans, maxProduct[i]);
        ans = max(ans, absMaxProduct[i]);
        
        if(absMaxProduct[i] == 0)
            absMaxProduct[i] = 1;
    }
    return ans;
}

int maxCoins(vector<int>& nums) {
    vector<pair<int,int>> vec;
    vector<int> left, right;
    for(int i=0;i<nums.size();i++) {
        vec.push_back({nums[i], i});
        left.push_back(i-1);
        right.push_back(i+1);
    }
    int ans = 0;
    
    if(nums.empty())
        return ans;
    
    make_heap(vec.begin(), vec.end(), greater<pair<int,int>>());
    while(!vec.empty()) {
        auto p1 = vec.front();
        pop_heap(vec.begin(), vec.end(), greater<pair<int,int>>());
        vec.pop_back();
        int index = p1.second, leftIndex = left[p1.second], rightIndex = right[p1.second];
        
        ans += (nums[index] * (leftIndex == -1 ? 1 : nums[leftIndex]) * (rightIndex == nums.size() ? 1 : nums[rightIndex]));
        if(rightIndex < nums.size())
            left[rightIndex] = leftIndex;
        if(leftIndex > -1)
            right[leftIndex] = rightIndex;
    }
    return ans;
}

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int ans=1;
    for(auto i: s)
        if(s.find(i-1) == s.end()) {
            int longestStreak = 1, value = i+1;
            while(s.find(value++) != s.end())
                ans = max(ans, ++longestStreak);
        }
    return ans;
}

int main(int argc, const char * argv[]) {
//    string s= "C.";
//    cout << arrange(s);
//    istringstream ss(s);
//    vector<string> s1;
//    do {
//        string word;
//        ss >> word;
//        if(word == "")
//            continue;
//        if(word[0] >= 'A' && word[0] <= 'Z')
//            word[0] = (char)((int)word[0] + 32);
//        if(word[word.length()-1] == '.')
//            word.pop_back();
//        s1.push_back(word);
//    } while (ss);
//    stable_sort(s1.begin(), s1.end(), compa);
//    s1[0][0] = (char)((int)s1[0][0] - 32);
//    for(int i=0;i<s1.size()-1;i++)
//        cout << s1[i] << " ";
//    cout << s1[s1.size()-1] << "." <<endl;
    
//    string s2 = "1234";
//    cout << s2.find('9');
//    map<int,int> mp1;
    
//    if(it != s2.end())
//        s2.erase(it);
    //cout << s2;
    
//    vector<vector<char>> vec = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
//    string word = "ABCESEEEFS";
//    cout << exist(vec, word) <<endl;
//    unordered_map<int, int> un_mp;
//    map<int,int> mp;
//
//    un_mp.insert(make_pair(10,2));
//    un_mp.insert(make_pair(5,2));
//    un_mp.insert(make_pair(3,2));
//    un_mp.insert(make_pair(7,2));
//    un_mp.insert(make_pair(9,2));
//
//    cout << un_mp[8] << "\n\n";
//
//    mp.insert({10,2});
//    mp.insert(make_pair(5,2));
//    mp.insert(make_pair(3,2));
//    mp.insert(make_pair(7,2));
//    mp.insert(make_pair(9,2));
//    un_mp.erase(un_mp.find(7));
//    for(auto it: un_mp) {
//        cout << it.first << " " << it.second <<endl;
//    }
//
//
//    for(auto it: mp) {
//        cout << it.first << " " << it.second <<endl;
//    }
    
    //vector<int> v1 = {1,9,2, 4,10,2,2,3}, v2 = {2,3,4},v3 = {1,2,3};
//    vec.insert(v1);
//    vec.insert(v2);
//    vec.insert(v3);
//    for(auto x: vec) {
//
//        for(auto y: x) {
//            cout << y << " ";
//        }
//
//        cout << endl;
//    }
//    vector<int> vect1 = {1,2,3,4}, vect2 = {1};
//    copy(vect1.begin(), vect1.end(), back_inserter(vect2));
//    for(auto x: vect2) {
//        cout << x << " ";
//    }
//    cout <<endl;
    
    vector<int> vec = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(vec) <<endl;
    
    return 0;
}
