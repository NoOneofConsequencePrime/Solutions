#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<pii> pos[30];
bool vst[15][15];
int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};

bool dfs(vector<vector<char>>& board, ppi u, string& word) {
    if (u.f >= word.length()-1) {return true;}

    for (int i = 0; i < 4; i++) {
        pii v = {u.s.f+mx[i], u.s.s+my[i]};
        if (v.f>=0 && v.f<board.size() && v.s>=0 && v.s<board[0].size() && !vst[v.f][v.s] && board[v.f][v.s]==word[u.f+1]) {
            vst[v.f][v.s] = true;
            bool state = dfs(board, {u.f+1, v}, word);
            vst[v.f][v.s] = false;
            if (state) {return true;}
        }
    }

    return false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ret;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            pos[board[i][j]-'a'].push_back({i, j});
        }
    }

    for (auto& word : words) {
        bool chk = false;
        for (pii x : pos[word[0]-'a']) {
            vst[x.f][x.s] = true;
            if (dfs(board, {0, x}, word)) {chk = true;}
            vst[x.f][x.s] = false;
        }

        if (chk) {ret.push_back(word);}
    }

    return ret;
}

int main() {
    vector<vector<char>> mat = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"eat", "oath", "pea", "rain"};
    vector<string> ret = findWords(mat, words);
    for (auto& str : ret) {cout << str << endl;}

    return 0;
}