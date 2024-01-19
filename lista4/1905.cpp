#include <bits/stdc++.h>



using namespace std;

#define ROW 5
#define COL 5

//ofstream outputFile("output.txt");
//ostream& out = outputFile;

bool validation(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool safecheck(int mattriz[ROW][COL], int visited[ROW][COL], int row, int col) {
    return (mattriz[row][col] == 0) && !visited[row][col];
}

string menor_caminho(int mattriz[ROW][COL]) {
    int visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    int start_row = 0, start_col = 0;
    int final_row = 4, final_col = 4;

    queue<pair<int, int>> aux;

    visited[start_row][start_col] = 1;
    aux.push({start_row, start_col});

    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    while (!aux.empty()) {
        pair<int, int> front = aux.front();
        aux.pop();

        int currentRow = front.first;
        int currentCol = front.second;

        for (int i = 0; i < 4; i++) {
            int new_row = currentRow + row[i];
            int new_col = currentCol + col[i];

            if (validation(new_row, new_col) && safecheck(mattriz, visited, new_row, new_col)) {
                if (new_row == final_row && new_col == final_col)return "COPS";

                visited[new_row][new_col] = 1;
                aux.push({new_row, new_col});
            }
        }
    }

    return "ROBBERS";
}
int main() {
    int test_case;
    cin >> test_case;

    while (test_case-- != 0) {
        int mattriz[ROW][COL];

       
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cin >> mattriz[i][j];
            }
        }
        if(mattriz[0][0]==0 && mattriz[4][4]==0){
            cout << menor_caminho(mattriz) << endl;
           
        }else {
            cout << "ROBBERS" << endl;
        }

        
    }

    return 0;
}