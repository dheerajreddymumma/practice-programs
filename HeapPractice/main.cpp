//
//  main.cpp
//  HeapPractice
//
//  Created by Dheeraj Reddy on 05/07/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode ListNode;

struct sortList {
    bool operator()(ListNode *node1, ListNode *node2){
        
        if(node1->val > node2->val)
            return true;
        return false;
    }
};

//ListNode* mergeKLists(vector<ListNode*>& lists) {
//    vector<ListNode*> vec;
//    ListNode* ans = new ListNode(-1), *temp;
//    temp = ans;
//    for(auto x: lists) {
//        while(x != NULL) {
//            vec.push_back(x);
//            x = x->next;
//        }
//    }
//
//    make_heap(vec.begin(), vec.end(), sortList());
//    while(!vec.empty()) {
//        ans->next = new ListNode(vec[0]->val);
//        pop_heap(vec.begin(), vec.end(), sortList());
//        vec.pop_back();
//        ans = ans->next;
//    }
//    return temp->next;
//}

ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
    ListNode *ans = new ListNode(-1), *temp;
    temp = ans;
    while(l1 || l2) {
        if(l1 == NULL) {
            ans->next = l2;
            break;
        }
        if(l2 == NULL) {
            ans->next = l1;
            break;
        }
        if(l1->val <= l2->val) {
            ans->next = l1;
            l1 = l1->next;
        }
        else {
            ans->next = l2;
            l2 = l2->next;
        }
        ans = ans->next;
    }
    return temp->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int interval = 1, length = (int)lists.size();
    
    while(interval < length) {
        for(int i=0;i<(length - interval); i += 2 * interval) {
            lists[i] = merge2Lists(lists[i], lists[i+interval]);
        }
        interval *= 2;
    }
    return lists[0];
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty())
        return 0;
    int rowSize = (int)matrix.size(), colSize = (int)matrix[0].size();
    vector<int> left(colSize, 0), right(colSize, colSize), height(colSize, 0);
    int maxA = 0;
    for(int i=0;i<rowSize;i++) {
        int currLeft = 0, currRight = colSize;
        
        for(int j=0;j<colSize;j++) {
            if(matrix[i][j] == '1') {
                height[j]++;
                left[j] = max(left[j], currLeft);
            }
            else {
                height[j] = 0;
                left[j] = 0;
                currLeft = j+1;
            }
        }
        
        for(int j=colSize-1;j>=0;j--) {
            if(matrix[i][j] == '1')
                right[j] = min(right[j], currRight);
            else {
                right[j] = colSize;
                currRight = j;
            }
        }
        
        for(int j=0;j<colSize;j++)
            maxA = max(maxA, (right[j] - left[j]) * height[j]);
    }
    return maxA;
}

string minWindow(string s, string t) {
    map<char, int> mapT;
    for(auto x: t)
        mapT[x] += 1;
    
    int formed = 0, required = (int)mapT.size(), left = 0, right = 0;
    int windowSize = INT_MAX, leftIndex = 0, rightIndex = 0;
    while(formed < required && right < s.length()) {
        char rightValue = s[right];
        
        if(mapT.find(rightValue) != mapT.end()) {
            
            mapT[rightValue]--;
            
            if(mapT[rightValue] == 0)
                formed++;
            
            while(formed == required) {
                char leftValue = s[left];
                if(windowSize > (right - left + 1)) {
                    windowSize = right - left + 1;
                    rightIndex = right;
                    leftIndex = left;
                }
                
                if(mapT.find(leftValue) != mapT.end()) {
                    mapT[leftValue]++;
                    if(mapT[leftValue] > 0)
                        formed++;
                }
                left++;
            }
        }
        right++;
    }
    return windowSize == INT_MAX ? "" : s.substr(leftIndex, windowSize);
}

int main(int argc, const char * argv[]) {
//    vector<vector<char>> vec = {{'0','1','0','1','0'},{'0','1','0','1','0'},{'1','1','1','1','1'},{'1','1','1','1','1'}};
//    cout << maximalRectangle(vec);
    string s = "ADOBECODEBANC",t = "ABC";
    minWindow(s, t);
    return 0;
}
