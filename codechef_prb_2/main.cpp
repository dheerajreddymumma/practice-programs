//
//  main.cpp
//  codechef_prb_2
//
//  Created by Dheeraj Reddy on 06/04/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

bool find_path(vector<vector<int>> &grid, int row_index, int col_index, int size, string &path, int num_steps) {
    if(row_index == size-1 && col_index == size-1)
        return true;
    
    if(row_index < size - 1 && grid[row_index + 1][col_index] != 2)
        if(grid[row_index][col_index] == 0 || (grid[row_index][col_index] == 1 && grid[row_index + 1][col_index] != 1) ) {
            path[num_steps] = 'S';
            bool res = find_path(grid, row_index + 1, col_index, size, path, num_steps + 1);
            if(res == true)
                return true;
        }
    
    if(col_index < size - 1 && grid[row_index][col_index + 1] != 2)
        if(grid[row_index][col_index] == 0 || (grid[row_index][col_index] == 1 && grid[row_index][col_index + 1] != 1) ) {
            path[num_steps] = 'E';
            bool res4 = find_path(grid, row_index, col_index + 1, size, path, num_steps + 1);
            if(res4 == true)
                return true;
        }
    
    grid[row_index][col_index] = 2;
    return false;
}

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    for(int itr=1;itr<=T;itr++) {
        int N=0, col=0, row=0;
        string P;
        cin >> N;
        vector<vector<int>> grid(N, vector<int>(N, 0));
        cin >> P;
        grid[0][0] = 1;
        for(char c: P)
            if(c == 'E')
                grid[row][++col] = 1;
            else
                grid[++row][col] = 1;
        string path((2*N)-2, ' ');
        find_path(grid, 0, 0, N, path, 0);
        cout << "Case #" << itr << ": " << path << endl;
    }
    return 0;
}
