//
//  main.cpp
//  nodelist
//
//  Created by Dheeraj Reddy on 25/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode ListNode;
ListNode* merge(ListNode *l1, ListNode *l2) {
    ListNode*p = new ListNode(0), *temp;
    temp = p;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    ListNode *l3 = l1 == NULL ? l2 : l1;
    while(l3!= NULL) {
        p->next = l3;
        p = p->next;
        l3 = l3->next;
    }
    return temp->next;
}

ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *prev = head, *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    return merge(l1,l2);
}

string longestPalindrome(string s) {
    string finalString;
    if(s.empty())
        return finalString;
    vector<int> vec(s.length(), 0);
    int ans = 1;
    finalString = s[0];
    for(int j=0;j<s.length();j++) {
        for(int i=0;i<=j;i++) {
            if(i == j) {
                vec[i] = 1;
                break;
            }
            if(s[i] == s[j]) {
                vec[i] = vec[i+1] + 2;
                if(vec[i] > ans) {
                    ans = vec[i];
                    finalString = s.substr(j-ans+1, ans);
                }
            }
            else
                vec[i] = 0;
        }
    }
    return finalString;
}

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty())
        return 0;
    vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
    int ans = 0;
    for(int i=1;i<matrix.size();i++)
        for(int j=1;j<matrix[0].size();j++) {
            dp[i][j] = matrix[i-1][j-1] == '0' ? 0 : min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            ans = max(dp[i][j],ans);
        }
    return ans;
}

int main(int argc, const char * argv[]) {
//    ListNode *root= NULL;
//    root = new ListNode(4);
//    root->next = new ListNode(2);
//    root->next->next = new ListNode(1);
//    root->next->next->next = new ListNode(3);
//
//    sortList(root);
   
//    vector<int> vec = {5,7,7,8,8,10};
//    int target = 9;
//    auto it = lower_bound(vec.begin(), vec.end(), target);
//    cout <<  it - vec.begin() << endl;
//    auto it2 = upper_bound(it, vec.end(), target);
//    cout << it2 - vec.begin();
    
    vector<vector<char>> vec = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    
    maximalSquare(vec);
    return 0;
}
