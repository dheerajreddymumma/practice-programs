//
//  main.cpp
//  TADELIVE
//
//  Created by Dheeraj Reddy on 26/01/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> pr;
/*class Compare {
public:
    bool operator() (pair<int,int> a, pair<int,int> b) {
        if (a.second > b.second)
            return true;
        return false;
    }
};*/

/*priority_queue<pr, vector<pr>, greater<pr>> pq;
 pq.push(make_pair(3, 6));
 pq.push(make_pair(1, 2));
 pq.push(make_pair(5, 5));
 pq.push(make_pair(8, 9));
 pq.push(make_pair(7, 1));
 pq.push(make_pair(4, 4));
 pr p;
 while(!pq.empty()) {
 p = pq.top();
 cout << p.first << " " << p.second <<endl;
 pq.pop();
 }*/

int main(int argc, const char * argv[]) {
    
    int N = 0, X, Y, value = 0;
    priority_queue<pr, vector<pr>, greater<pr>> negative_queue;
    priority_queue<pr> positive_queue;
    
    cin >> N >> X >> Y;
    
    int arr1[N], arr2[N];
    
    for (int i = 0; i < N; i++)
        cin >> arr1[i];
    
    for (int i = 0; i < N; i++) {
        cin >> arr2[i];
        value = arr1[i] - arr2[i];
        if (value < 0)
            negative_queue.push(make_pair(value, i));
        else
            positive_queue.push(make_pair(value, i));
    }
    
    int ans = 0;
    while( X > 0 && positive_queue.size() > 0) {
        ans += arr1[positive_queue.top().second];
        positive_queue.pop();
        X--;
    }
    
    while( Y > 0 && negative_queue.size() > 0) {
        ans += arr2[negative_queue.top().second];
        negative_queue.pop();
        Y--;
    }
    
    while (positive_queue.size() > 0) {
        ans += arr2[positive_queue.top().second];
        positive_queue.pop();
    }
    
    while (negative_queue.size() > 0) {
        ans += arr1[negative_queue.top().second];
        negative_queue.pop();
    }
    
    cout<<ans<<endl;
    
    return 0;
}
