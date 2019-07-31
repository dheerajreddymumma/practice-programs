//
//  main.cpp
//  binarysearch
//
//  Created by Dheeraj Reddy on 20/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_set>
using namespace std;

typedef vector<pair<int,int>> pt;
//
//bool searchMatrix(vector<vector<int>>& matrix, int target) {
//    if(matrix.empty())
//        return false;
//    auto it1 = lower_bound(matrix[0].begin(), matrix[0].end(), target);
//    int index = it1 - matrix[0].begin();
//    if(it1 != matrix[0].end() && *it1 == target)
//        return true;
//    if(index == 0)
//        return false;
//
//    int j=index-1, i=1;
//    while(i < matrix.size() && j >= 0) {
//        if(matrix[i][j] == target)
//            return true;
//        if(matrix[i][j] > target)
//            j--;
//        i++;
//    }
//    return false;
//}
//
//int lengthOfLIS(vector<int>& nums) {
//    if(nums.empty())
//        return 0;
//    vector<int> dp(nums.size());
//    dp[0] = 1;
//    int ans = 1;
//    for(int i=1;i<nums.size();i++) {
//        int maxValue = 0;
//        for(int j=0;j<i;j++) {
//            if(nums[j] < nums[i])
//                maxValue = max(maxValue, dp[j]);
//        }
//        dp[i] = maxValue + 1;
//        ans = max(ans, maxValue + 1);
//    }
//    return ans;
//}
//
int findPivot(vector<int> &vec, int low, int high) {
    int mid = low + (int)((high - low) /2), pivotIndex = low;

    for(int i=low;i<=high;i++) {
        if(i == mid)
            continue;
        if(vec[i] <= vec[mid]) {
            int temp = vec[i];
            vec[i] = vec[pivotIndex];
            vec[pivotIndex++] = temp;
            if(pivotIndex == mid)
                pivotIndex++;
        }
    }
    if(pivotIndex > mid)
        pivotIndex--;
    int temp = vec[mid];
    vec[mid] = vec[pivotIndex];
    vec[pivotIndex] = temp;
    return pivotIndex;
}

void quickSort(vector<int> &vec, int low, int high) {
    if(low < high) {
        int pivot = findPivot(vec, low, high);
        quickSort(vec, low, pivot-1);
        quickSort(vec, pivot+1, high);
    }
}

void addEdge(vector<vector<int>> &grph, int node1, int node2) {
    grph[node1].push_back(node2);
}

void printGraph(vector<vector<int>> &grph)
{
    auto it1 = find(grph[2].begin(), grph[2].end(), 10);
//    if(it1 != grph[2].end())
//        grph[2].erase(it1);
    for(int i=0;i<grph.size();i++) {
        for(auto it = grph[i].begin(); it != grph[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

void visitNodes(vector<vector<int>> graph, vector<bool> &visited, int node) {
    visited[node] = true;
    cout << "Node Visited is " << node << endl;
    for(auto it = graph[node].begin(); it < graph[node].end(); it++)
        if(visited[*it] == false)
            visitNodes(graph, visited, *it);
}

void implementDFS(vector<vector<int>> graph) {
    vector<bool> visited(graph.size(), false);
    for(int i=1;i<graph.size();i++) {
        if(visited[i] == false)
            visitNodes(graph, visited, i);
    }
}

//void addEdge(pt graph[], int v1, int v2, int cost) {
//    graph[v1].push_back(make_pair(v2,cost));
//}
//
//void printGraph(pt graph[]) {
//    for(int i=1;i<6;i++)
//        for(auto it=graph[i].begin(); it < graph[i].end(); it++)
//            cout << "Node " << i << " to " << it->first << " cost: " << it->second << endl;
//}

bool DFS(vector<vector<int>> graph, unordered_set<int> &grey,unordered_set<int> &completelyVisited, int value) {
    grey.insert(value);
    for(auto x: graph[value]) {
        if(grey.find(x) != grey.end())
            return false;
        if(completelyVisited.find(x) != completelyVisited.end())
            continue;
        if(!DFS(graph, grey, completelyVisited, x))
            return false;
        completelyVisited.insert(x);
        auto it1 = grey.find(x);
        if(it1 != grey.end())
            grey.erase(it1);
    }
    completelyVisited.insert(value);
    auto it = grey.find(value);
    grey.erase(it);
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_set<int> grey, completelyVisited;
    vector<vector<int>> graph(numCourses);
    for(auto x: prerequisites)
        graph[x[0]].push_back(x[1]);
    for(int i=0;i<numCourses;i++) {
        if(grey.find(i) == grey.end() && completelyVisited.find(i) == completelyVisited.end())
            if(!DFS(graph, grey, completelyVisited, i))
                return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
//    int V = 8;
//    vector<vector<int>> graph(V);
//    addEdge(graph, 1, 4);
//    addEdge(graph, 1, 2);
//    addEdge(graph, 1, 3);
//    addEdge(graph, 2, 5);
//    addEdge(graph, 2, 6);
//    addEdge(graph, 5, 6);
//    printGraph(graph);
//    implementDFS(graph);
    
    
//    int V = 6;
//    pt graph[V];
//    addEdge(graph, 1, 2, 2);
//    addEdge(graph, 1, 2, 4);
//    addEdge(graph, 2, 4, 6);
//    addEdge(graph, 2, 3, 13);
//    addEdge(graph, 3, 5, 7);
//    addEdge(graph, 4, 1, 8);
//    addEdge(graph, 5, 3, 5);
//    addEdge(graph, 5, 4, 89);
//    printGraph(graph);
    int numCourses = 6;
    vector<vector<int>> graph(numCourses);
    vector<vector<int>> prereq = {{0,3}, {1,0}, {1,3}, {3,5}, {4,5}, {3,4}, {2,4}, {1,2}};
    //canFinish(numCourses, prereq);
    for(auto p: prereq) {
        cout << p[0] << "  " << p[1] <<endl;
    }
    return 0;
}
