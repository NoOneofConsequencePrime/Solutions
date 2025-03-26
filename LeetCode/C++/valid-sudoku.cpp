#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    short chk = 0;
    for (int i = 0; i < 9; i++) {
        chk = 0;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            if ((chk >> board[i][j]-'1')&1) return false;
            chk |= 1 << board[i][j]-'1';
        }
    }
    for (int j = 0; j < 9; j++) {
        chk = 0;
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.') continue;
            if ((chk >> board[i][j]-'1')&1) return false;
            chk |= 1 << board[i][j]-'1';
        }
    }
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            chk = 0;
            for (int i = a*3; i < a*3+3; i++) {
                for (int j = b*3; j < b*3+3; j++) {
                    if (board[i][j] == '.') continue;
                    if ((chk >> board[i][j]-'1')&1) return false;
                    chk |= 1 << board[i][j]-'1';
                }
            }
        }
    }

    return true;
}

int main() {

    return 0;
}