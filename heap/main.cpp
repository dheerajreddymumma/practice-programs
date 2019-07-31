//
//  main.cpp
//  heap
//
//  Created by Dheeraj Reddy on 08/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

int findTargetSumWays(vector<int>& nums, int S) {
    int maximum = 0;
    for(int i=0; i<nums.size(); i++)
        maximum += nums[i] >= 0 ? nums[i] : -nums[i];
    S = S < 0 ? -S : S;
    
    if(S > maximum || nums.empty())
        return 0;
    
    vector<int> vec(maximum+1, 0);
    vec[nums[0]] = 1;
    for(int i=1;i<nums.size();i++) {
        vector<int> temp(maximum+1, 0);
        for(int j=0;j<maximum+1;j++) {
            int negativeIndex, positiveIndex, negativeValue = 0, positiveValue = 0;
            negativeIndex = j - nums[i];
            negativeIndex = negativeIndex >= 0 ? negativeIndex : -negativeIndex;
            
            if(negativeIndex <= maximum)
                negativeValue = vec[negativeIndex];
            
            positiveIndex = j + nums[i];
            positiveIndex = positiveIndex >= 0 ? positiveIndex : -positiveIndex;
            
            if(positiveIndex <= maximum)
                positiveValue = vec[positiveIndex];
            
            temp[j] = negativeValue + positiveValue;
        }
        vec = temp;
    }
    return vec[S];
}

string decodeString(string s) {
    vector<pair<int,int>> positions;
    vector<char> stackString;
    string ans;
    for(int chr = 0;chr < s.size();chr++) {
        if(s[chr] >= '0' && s[chr] <= '9') {
            string number = "";
            while(s[chr] != '[') {
                number += s[chr];
                chr++;
            }
            positions.push_back(make_pair(stackString.size(),stoi(number)));
        }
        else if(s[chr] == ']') {
            if(positions.size() == 1) {
                for(int j=0;j<positions[0].second;j++)
                    for(int i=positions[0].first; i<stackString.size();i++)
                        ans += stackString[i];
                int strsize = (int)stackString.size();
                for(int i=positions[0].first; i<strsize; i++)
                    stackString.pop_back();
                positions.pop_back();
            }
            else {
                int index = (int)positions.size()-1, size = (int)stackString.size();
                for(int j=1;j<positions[index].second;j++)
                    for(int i=positions[index].first; i<size;i++)
                        stackString.push_back(stackString[i]);
                
                positions.pop_back();
                
            }
        }
        else
            if(positions.empty())
                ans+=s[chr];
            else
                stackString.push_back(s[chr]);
    }
    return ans;
}

int maxArea(vector<int>& height) {
    vector<pair<int,int>> leftArray;
    int currentHeight, maxValueFound = 0;
    leftArray.push_back(make_pair(height[0], 0));
    for(int i=1;i<height.size()-1;i++)
        if(height[i] > leftArray[leftArray.size() - 1].first)
            leftArray.push_back(make_pair(height[i],i));
    
    currentHeight = -1;
    for(int i=height.size()-1; i>0; i--) {
        if(height[i] > currentHeight) {
            currentHeight = height[i];
            for(auto x: leftArray) {
                int width = i - x.second;
                if(width <= 0)
                    break;
                
                int minHeight = min(x.first, height[i]);
                maxValueFound = minHeight * width > maxValueFound ? minHeight * width : maxValueFound;
            }
        }
    }
    return maxValueFound;
}

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

pair<TreeNode*, TreeNode*> flattenTree(TreeNode *node) {
    if(node != NULL) {
        pair<TreeNode*, TreeNode*> left, right;
        if(node->left != NULL)
            left = flattenTree(node->left);
        else
            left.first = NULL;
        
        if(node->right != NULL)
            right = flattenTree(node->right);
        else
            right.first = NULL;
        
        if(left.first == NULL && right.first == NULL)
            return make_pair(node,node);
        if(left.first == NULL)
            return make_pair(node, right.second);
        if(right.first == NULL){
            node->right = left.first;
            node->left = NULL;
            return make_pair(node, left.second);
        }
        
        left.second->right = right.first;
        node->right = node->left;
        node->left = NULL;
        return make_pair(node, right.second);
    }
    else {
        pair<TreeNode*, TreeNode*> temp1;
        temp1.first = NULL;
        temp1.second = NULL;
        return temp1;
    }
}

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void sortColors(vector<int>& nums) {
    int index0 = 0, index2 = (int)nums.size()-1;
    for(int i=0;i<=index2;i++) {
        if(nums[i] == 1)
            continue;
        while(i >= index0 && i <= index2 && (nums[i] == 0 || nums[i] == 2)) {
            if(nums[i] == 0) {
                swap(nums[i], nums[index0]);
                index0++;
            }
            else {
                swap(nums[i], nums[index2]);
                index2--;
            }
        }
    }
}

void findMinimum(vector<int> nums, int index, int valueRemain, int currentValue, int &minValue, bool &flag) {
    if(nums[index] > valueRemain) {
        findMinimum(nums, index-1, valueRemain, currentValue, minValue, flag);
        if(flag == true)
            flag = false;
        return;
    }
    int div = (int) valueRemain / nums[index], rem = valueRemain % nums[index];
    if(div + currentValue > minValue) {
        flag = true;
        return;
    }
    if(rem == 0)
        minValue = currentValue + div;
    else
        for(int i=div;i>=0;i--) {
            findMinimum(nums, index-1, valueRemain - (i*nums[index]), currentValue + i, minValue, flag);
            if(flag == true){
                flag = false;
                return;
            }
        }
    return;
}

int numSquares(int n) {
    int minValue = INT_MAX;
    vector<int> nums;
    bool flag = false;
    for(int i=1;i<=(int)sqrt(n);i++)
        nums.push_back(i*i);
    findMinimum(nums, (int)nums.size()-1, n, 0, minValue, flag);
    return minValue;
}

vector<string> letterCombinations(string digits) {
    map<int, string> mp;
    mp[0] = ""; mp[1] =  ""; mp[2] = "abc"; mp[3] = "def"; mp[4] = "ghi"; mp[5] = "jkl"; mp[6] = "mno"; mp[7] = "pqrs"; mp[8] = "tuv"; mp[9] = "xyz";
    list<string> str;
    str.push_back("");
    while(str.front().length() != digits.length()) {
        string temp = str.front();
        temp.empty();
        str.pop_front();
        string newString = mp[(int)digits[temp.length()] - 48];
        for(auto x: newString)
            str.push_back(temp + x);
    }
    vector<string> nums(str.begin(), str.end());
    return nums;
}

int main(int argc, const char * argv[]) {
//    string a = "2[1[]abc]3[cd]ef";
//    decodeString(a);
//    vector<int> vec = {1,8,6,2,5,4,8,3,7};
//    maxArea(vec);
//    TreeNode *root = NULL;
//    //root = new TreeNode(5);
//
//
//    root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->left->left = new TreeNode(3);
//    root->left->left->left = new TreeNode(4);
//    root->left->left->right = new TreeNode(5);
//    root->left->left->right->left = new TreeNode(6);
//    root->left->left->right->right = new TreeNode(7);
//    root->left->right = new TreeNode(8);
//    root->left->right->left = new TreeNode(9);
//    root->left->right->right = new TreeNode(10);
//    root->right = new TreeNode(11);
//    root->right->left = new TreeNode(12);
//    root->right->right = new TreeNode(13);
//    root->right->right->left = new TreeNode(14);
//    root->right->right->right = new TreeNode(15);
//    flattenTree(root);
//    cout << root->val;
    
//    map<int,int> mp;
//    mp[2] = 4;
//    mp[4] =5;
//    cout << mp[1] << " " << mp[4] <<endl;
//    vector<int> nums = {0,1,2,2,1,1,1,0,0,2,2};
//    sortColors(nums);
    //cout << (int)sqrt(35) <<endl;
   // cout << numSquares(133) << endl;
    //char begin = '0', end = '9';
    //cout << (int)begin << (int)end <<endl;
//    letterCombinations("22");
//
//    vector<int> vec;
//    vec.push_back(20);
//    vec.push_back(30);
//    vec.push_back(40);
//    vec.push_back(50);
//
    
    
    map<int,string> mp;
    mp[0] = "Zero";
    mp[1] = "One"; mp[2] = "Two"; mp[3] = "Three"; mp[4] = "Four";

    string s;
    cin >> s;
    for(auto x: s) {
        cout << mp[(int)x - 48] << " ";
    }
    cout<<endl;
    
    return 0;
}
