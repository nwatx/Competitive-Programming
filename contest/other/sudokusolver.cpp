#include <bits/stdc++.h>

using namespace std;

const int dim = 9;
const int seed = 7;
const int rand_inv_freq = 2;

vector<vector<int>> gen_board() {
    // shuffle each of the 9 tiles
    vector<vector<int>> board(dim);
    for(int i = 0; i < dim; i++) {
        for(int j = 1; j <= 9; j++) {
            board[i].push_back(j);
        }

        shuffle(board[i].begin(), board[i].end(), std::default_random_engine(seed));
    }

    return board;
}

void mask_board(vector<vector<int>> &board) {
    vector<vector<bool>> mask(dim);
    for(int i = 0; i < dim; i++) {
        for(int j = 1; j <= 9; j++) {
            mask[i].push_back(rand() % rand_inv_freq == 0);
        }
    }

    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            if(mask[i][j]) board[i][j] = 0;
        }
    }
}

void display_board() {
    for(int i = 0; i < 9; i++) {
        
    }
}

int main() {
    auto board = gen_board();


    mask_board(board);
}