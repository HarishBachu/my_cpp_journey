//Count number of ways to reach destination in a Maze

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

int nPaths(vector<vector<int>> grid){
    int rows = grid.size();
    int cols = grid[0].size();
    if(grid[0][0] == -1)
        return 0;

    for(int i = 0; i < rows; i++){
        if(grid[i][0] == 0)
            grid[i][0] = 1;
        else
            break;
    }
    for(int i = 0; i < cols; i++){
        if(grid[0][i] == 0)
            grid[0][i] = 1;
        else
            break;
    }

    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(grid[i][j]!=-1){
                if(grid[i-1][j] > 0)
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                if(grid[i][j-1] > 0)
                    grid[i][j] = grid[i][j] + grid[i][j-1];
            }
        }
    }
    return (grid[rows-1][cols-1] > 0) ? grid[rows-1][cols-1] : 0;
}

int main(){

    vector<vector<int>> grid = {{0,  0, 0, 0},
                                {0, -1, 0, 0},
                                {-1, 0, 0, 0},
                                {0,  0, 0, 0}};
    cout << nPaths(grid);
    return 0;
}