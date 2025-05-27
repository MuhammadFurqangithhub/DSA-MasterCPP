#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> q;
    int freshCount = 0;

    // Directions for adjacent cells (up, down, left, right)
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    // Initialize queue with all rotten oranges and count fresh oranges
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2) {
                q.push({r,c});
            } else if (grid[r][c] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) return 0;

    int minutes = 0;

    while (!q.empty()) {
        int size = q.size();
        bool rottenThisRound = false;

        for (int i = 0; i < size; ++i) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    freshCount--;
                    rottenThisRound = true;
                }
            }
        }

        if (rottenThisRound) {
            minutes++;
        }
    }

    return freshCount == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = orangesRotting(grid);
    if (result == -1) {
        cout << "Not all oranges can rot." << endl;
    } else {
        cout << "Minimum time to rot all oranges: " << result << " minutes." << endl;
    }
    return 0;
}
