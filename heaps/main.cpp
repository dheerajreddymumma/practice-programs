//
//  main.cpp
//  heaps
//
//  Created by Dheeraj Reddy on 04/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <unordered_set>
#include <queue>
using namespace std;

struct greater1{
    bool operator()(int a,int b) {
        return a>b;
    }
};
struct lesser1{
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second <= b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> mp;
    map<int,int>::iterator it1;
    for(int i=0;i<nums.size();i++) {
        it1 = mp.find(nums[i]);
        if(it1 == mp.end())
            mp.insert(make_pair(nums[i],1));
        else
            it1->second += 1;
    }
    
    vector<pair<int,int>> maps;
    for(it1 = mp.begin(); it1 != mp.end(); it1++)
        maps.push_back(make_pair(it1->first, it1->second));
    
    make_heap(maps.begin(), maps.end(), lesser1());
    vector<int> ans;
    for(int i=0;i<k;i++) {
        ans.push_back(maps[0].first);
        pop_heap(maps.begin(), maps.end(), lesser1());
        maps.pop_back();
    }
    return ans;
}
void findingAllCombinations(vector<vector<int>> &ans, vector<int> nums) {
    int total = pow(2,nums.size()), places = nums.size();
    for(int i=0;i<total;i++) {
        vector<int> temp;
        for(int j=0;j<places;j++)
            if(1 >> j & i)
                temp.push_back(nums[j]);
        ans.push_back(temp);
    }
}
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;
    queue<pair<TreeNode *, int>> que;
    que.push(make_pair(root, 0));
    while(!que.empty()) {
        pair<TreeNode *, int> p1 = que.front();
        if(ans.size() > p1.second) {
            ans[p1.second].push_back(p1.first->val);
        }
        else {
            vector<int> temp = {p1.first->val};
            ans.push_back(temp);
        }
        que.pop();
        if(p1.first->left != NULL)
            que.push(make_pair(p1.first->left, p1.second + 1));
        if(p1.first->right != NULL)
            que.push(make_pair(p1.first->right, p1.second + 1));
    }
    return ans;
}


void rotate(vector<vector<int>>& matrix) {
    int matrixSize = matrix.size(), leftIndex = 1;
    for(int i=0;i<matrixSize/2;i++) {
        for(int j=i;j<matrixSize-leftIndex;j++) {
            int oldI = i, oldJ = j, oldValue = matrix[i][j];
            for(int k=0;k<4;k++) {
                int newI = oldJ, newJ = matrixSize - oldI - 1;
                int temp = matrix[newI][newJ];
                
                matrix[newI][newJ] = oldValue;
                oldValue = temp;
                oldI = newI;
                oldJ = newJ;
            }
        }
        leftIndex++;
    }
    
}


int main(int argc, const char * argv[]) {
    
//    vector<int> v1 = {2,1,4,5,8};
//    make_heap(v1.begin(), v1.end(), greater1());
//    for(int i=0;i<v1.size();i++) {
//        cout  << v1[i] << " ";
//    }
//    v1.push_back(6);
//    v1.push_back(3);
//    push_heap(v1.begin(), v1.end(), greater1());
//    cout<<endl;
//    for(int i=0;i<v1.size();i++) {
//        cout  << v1[i] << " ";
//    }
//    cout<<endl;
//    cout << v1.front() << endl;
//    vector<int> nums = {1,2,3};
//    vector<vector<int>> ans;
//    int val = 1 << 2;
//    cout << val <<endl;
    
    
    
//    TreeNode *root = NULL;
//    root = new TreeNode(3);
//    root->left = new TreeNode(9);
//    root->right = new TreeNode(20);
//    root->right->left = new TreeNode(15);
//    root->right->right  = new TreeNode(7);
//    levelOrder(root);

    vector<vector<int>> vec = {
        { 5, 1, 9,11},
        { 2, 4, 8,10},
        {13, 3, 6, 7},
        {15,14,12,16}
    };
    rotate(vec);
    return 0;
}
