//
//  main.cpp
//  codejam_2019_1B_prb1
//
//  Created by Dheeraj Reddy on 28/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int P,Q;
        cin >> P >> Q;
        vector<vector<int> > grid(Q+1, vector<int>(Q+1));
        for(int i=0;i<P;i++) {
            int X, Y;
            char D;
            cin >> X >> Y >> D;
            if(D == 'N') {
                for(int j = 0; j <= Q; j++) {
                    for(int k = Y+1; k <= Q; k++) {
                        grid[j][k] += 1;
                    }
                }
            }
            if(D == 'S') {
                for(int j = 0; j <=Q; j++) {
                    for(int k = Y-1; k >=0; k--) {
                        grid[j][k] += 1;
                    }
                }
            }
            if(D == 'E') {
                for(int j = X+1; j <= Q; j++) {
                    for(int k = 0; k <= Q; k++) {
                        grid[j][k] += 1;
                    }
                }
            }
            if(D == 'W') {
                for(int j = X-1; j >= 0; j--) {
                    for(int k = 0; k <=Q; k++) {
                        grid[j][k] += 1;
                    }
                }
            }
        }
        int maxFound = 0, X_cord = 0, Y_cord = 0;
        for(int i=0;i<=Q;i++) {
            for(int j=0;j<=Q;j++) {
                if(grid[i][j] > maxFound) {
                    maxFound = grid[i][j];
                    X_cord = i;
                    Y_cord = j;
                }
            }
        }
        
        cout << "Case #" << t << ": " << X_cord << " " << Y_cord <<endl;
        
    }
    return 0;
}
