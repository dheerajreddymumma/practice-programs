//
//  main.cpp
//  amazon3
//
//  Created by Dheeraj Reddy on 28/05/19.
//  Copyright © 2019 Dheeraj Reddy. All rights reserved.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
struct QItem {
    int row, col, dist;
    QItem(int x, int y, int z) : row(x), col(y), dist(z){}
};

int removeObstacle(int numRows, int numColumns, int **lot) {
    QItem source(0, 0, 0);
    
    if(numRows == 0 || numColumns == 0 || lot[0][0] == 0)
        return -1;
    // To keep track of visited QItems. Marking
    // blocked cells as visited.
    bool visited[numRows][numColumns];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++)
        {
            if (lot[i][j] == 0)
                visited[i][j] = true;
            else
                visited[i][j] = false;
        }
    }
    
    queue<QItem> q;
    q.push(source);
    visited[source.row][source.col] = true;
    while (!q.empty()) {
        QItem p = q.front();
        q.pop();
        
        // Destination found;
        if (lot[p.row][p.col] == 9)
            return p.dist;
        
        // moving up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false) {
            q.push(QItem(p.row - 1, p.col, p.dist + 1));
            visited[p.row - 1][p.col] = true;
        }
        
        // moving down
        if (p.row + 1 < numRows && visited[p.row + 1][p.col] == false) {
            q.push(QItem(p.row + 1, p.col, p.dist + 1));
            visited[p.row + 1][p.col] = true;
        }
        
        // moving left
        if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false) {
            q.push(QItem(p.row, p.col - 1, p.dist + 1));
            visited[p.row][p.col - 1] = true;
        }
        
        // moving right
        if (p.col + 1 < numColumns && visited[p.row][p.col + 1] == false) {
            q.push(QItem(p.row, p.col + 1, p.dist + 1));
            visited[p.row][p.col + 1] = true;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int **lot = NULL;
    int numRows = 4, numColumns = 1;
    lot = new int*[numRows];
    for(int i=0;i<numRows;i++)
        lot[i] = new int[numColumns];
    lot[0][0] = 9;
    //    for(int i=0;i<numRows;i++) {
    //        for(int j=0;j<numColumns;j++) {
    //            cin >> lot[i][j];
    //        }
    //    }
    cout << removeObstacle(numRows, numColumns, lot);
    return 0;
}
