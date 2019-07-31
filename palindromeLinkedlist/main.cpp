//
//  main.cpp
//  palindromeLinkedlist
//
//  Created by Dheeraj Reddy on 02/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

int findUnsortedSubarray(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int startIndex = INT_MAX, endIndex = -1, maximumValueFound = nums[0];
    for(int i=1;i<nums.size(); i++) {
        if(nums[i] < maximumValueFound) {
            
            int j = i-1;
            while(j >= 0 && nums[j] > nums[i])
                j--;
            startIndex = min(j+1, startIndex);
            
            endIndex = i;
        }
        else {
            maximumValueFound = nums[i];
        }
    }
    if(endIndex == -1)
        return 0;
    else
        return endIndex - startIndex + 1;
}

vector<int> productExceptSelf(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1)
        return nums;
    vector<int> output(nums.size());
    output[0] = nums[0];
    for(int i=1;i<nums.size()-1;i++)
        output[i] = nums[i] * output[i-1];
    output[nums.size()-1] = output[nums.size()-2];
    int accumulatedValue = 1;
    for(int i = nums.size()-2;i>=0;i--) {
        int product = i == 0 ? 1 : output[i-1];
        accumulatedValue *= nums[i+1];
        output[i] = product * accumulatedValue;
    }
    return output;
}

bool isPalindrome(ListNode* head) {
    if(head->next == NULL || head == NULL) {
        return true;
    }
    ListNode *p1 = new ListNode;
    p1->next = head;
    ListNode *starter = p1, *end = p1;
    stack<int> stk;
    int count = 0;
    while(end != NULL && end->next != NULL) {
        starter = starter->next;
        end = end->next->next;
        stk.push(starter->val);
        count++;
    }
    if(end == NULL) {
        stk.pop();
    }
    while(starter->next != NULL) {
        if(stk.top() != starter->next->val)
            return false;
        starter = starter->next;
        stk.pop();
    }
    return true;
    
}
int main(int argc, const char * argv[]) {
//    ListNode *head;
//    head = new ListNode;
//    head->val = 1;
//    ListNode *tail;
//    tail = new ListNode;
//    tail->val = 2;
//    tail->next = NULL;
//    head->next = tail;
//    isPalindrome(head);
    
    //set<int> s;
    vector<int> num = {1,2,3,4};
    productExceptSelf(num);
    
    return 0;
}
