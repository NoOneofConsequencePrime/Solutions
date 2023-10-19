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
    bool cnt[9];
    for (int i = 0; i < 9; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            if (cnt[board[i][j]-'1']) return false;
            cnt[board[i][j]-'1'] = 1;
        }
    }
    for (int j = 0; j < 9; j++) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.') continue;
            if (cnt[board[i][j]-'1']) return false;
            cnt[board[i][j]-'1'] = 1;
        }
    }
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = a*3; i < a*3+3; i++) {
                for (int j = b*3; j < b*3+3; j++) {
                    if (board[i][j] == '.') continue;
                    if (cnt[board[i][j]-'1']) return false;
                    cnt[board[i][j]-'1'] = 1;
                }
            }
        }
    }

    return true;
}

int main() {

    return 0;
}