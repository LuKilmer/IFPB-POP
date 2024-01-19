#include <iostream>
#include <queue>
#include <bits/stdc++.h> 


using namespace std;

#define ROW 5
#define COL 5

ofstream outputFile("output.txt");
ostream& out = outputFile;

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool isSafe(int mat[ROW][COL], int visited[ROW][COL], int row, int col) {
    return (mat[row][col] == 0) && !visited[row][col];
}

bool BFS(int mat[ROW][COL]) {
    int visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int startRow = 0, startCol = 0;
    int endRow = 4, endCol = 4;

    queue<pair<int, int>> q;

    visited[startRow][startCol] = 1;
    q.push({startRow, startCol});

    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();

        int currentRow = front.first;
        int currentCol = front.second;

        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + row[i];
            int newCol = currentCol + col[i];

            if (isValid(newRow, newCol) && isSafe(mat, visited, newRow, newCol)) {
                if (newRow == endRow && newCol == endCol)
                    return true;

                visited[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }

    return false;
}
int main() {
    int test_case;
    cin >> test_case;

    while (test_case-- != 0) {
        int mat[ROW][COL];

        // Input for the current matrix
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cin >> mat[i][j];
            }
        }
        if(mat[0][0]==0 && mat[4][4]==0){
            // Check if there is a valid path in the current matrix
            if (BFS(mat)) {
                out << "COPS" << endl;
            } else {
                out << "ROBBERS" << endl;
            }
        }else {
            out << "ROBBERS" << endl;
        }

        
    }

    return 0;
}