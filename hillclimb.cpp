#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_board(const vector<vector<int>>& board) {
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isGoal(const vector<vector<int>>& puzzle, const vector<vector<int>>& goal) {
    return puzzle == goal;
}

pair<int,int> findEmptyBox(const vector<vector<int>>& puzzle) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[i][j] == 0)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int misplaced_tiles(const vector<vector<int>>& puzzle, const vector<vector<int>>& goal) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[i][j] != 0 && puzzle[i][j] != goal[i][j])
                count++;
        }
    }
    return count;
}

vector<vector<vector<int>>> get_neighbors(const vector<vector<int>>& board) {
    vector<vector<vector<int>>> neighbors;
    pair<int,int> pos = findEmptyBox(board);
    int x = pos.first, y = pos.second;

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
            vector<vector<int>> new_board = board;
            swap(new_board[x][y], new_board[nx][ny]);
            neighbors.push_back(new_board);
        }
    }
    return neighbors;
}

bool hillClimbing(vector<vector<int>> start, vector<vector<int>> goal) {
    vector<vector<int>> current = start;
    int current_h = misplaced_tiles(current, goal);

    cout << "Starting hill climbing...\n";
    print_board(current);
    cout << "Heuristic: " << current_h << "\n\n";

    while (true) {
        if (isGoal(current, goal)) {
            cout << "Goal reached!\n";
            return true;
        }

        vector<vector<vector<int>>> neighbors = get_neighbors(current);
        vector<vector<int>> best_neighbor = current;
        int best_h = current_h;

        for (size_t i = 0; i < neighbors.size(); i++) {
            int h = misplaced_tiles(neighbors[i], goal);
            if (h < best_h) {
                best_h = h;
                best_neighbor = neighbors[i];
            }
        }

        if (best_h >= current_h) {
            cout << "No better neighbor found. Stopping.\n";
            return false;
        }

        current = best_neighbor;
        current_h = best_h;

        print_board(current);
        cout << "Heuristic: " << current_h << "\n\n";
    }
}

int main() {
    vector<vector<int>> puzzle = {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};
    vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    hillClimbing(puzzle, goal);
    return 0;
}
