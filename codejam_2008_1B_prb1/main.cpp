//
//  main.cpp
//  codejam_2008_1B_prb1
//
//  Created by Dheeraj Reddy on 20/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    for(int t=0;t<N;t++) {
        int n, A, B, C, D, x0, y0, M;
        cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
        vector<pair<int,int>> vertex;
        int X = x0,Y = y0;
        vertex.push_back(make_pair(X, Y));
        cout << X << " " << Y << endl;
        for(int i=1;i<n;i++) {
            X = (A * X + B) % M;
            Y = (C * Y + D) % M;
            vertex.push_back(make_pair(X,Y));
            cout << X << " " << Y << endl;
        }
        
    }
    return 0;
}
