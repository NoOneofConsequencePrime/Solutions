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

unordered_map<string, int> mp;
int cnt[26];

void addEdge(string &text1, string &text2, vector<int> *edge) {
    if (text1.length() < text2.length()) {swap(text1, text2);}
    int n1 = text1.length(), n2 = text2.length();
    if (n1-n2 > 1) {return;}
    memset(cnt, 0, sizeof(cnt));
    int flag = 0;
    for (int i = 0; i < n2; i++) {
        int tmp1 = cnt[text1[i]-'a'], tmp2 = cnt[text2[i]-'a'];
        cnt[text1[i]-'a']++;
        cnt[text2[i]-'a']--;
        if (cnt[text1[i]-'a'] != tmp1) {flag++;}
        if (cnt[text2[i]-'a'] != tmp2) {flag++;}
        if (cnt[text1[i]-'a'] != tmp1 && cnt[text2[i]-'a'] != tmp2) {flag--;}
        if (abs(cnt[text1[i]-'a'])>1 || abs(cnt[text2[i]-'a'])>1) {return;}
    }

    if (n1-n2+flag != 1) {return;}

    edge[mp[text1]].push_back(mp[text2]);
    edge[mp[text2]].push_back(mp[text1]);

    return;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    for (auto &str : wordList) {
        mp[str] = mp.size();
    }
    if (mp.count(beginWord) != 1) {
        mp[beginWord] = mp.size();
    }
    if (mp.count(endWord) != 1) {return 0;}

    int n = wordList.size();
    vector<int> edge[mp.size()];
    for (int i = 0; i < n; i++) {
        addEdge(beginWord, wordList[i], edge);
        for (int j = i+1; j < n; j++) {
            addEdge(wordList[i], wordList[j], edge);
        }
    }

    vector<int> vst(mp.size(), 0);
    queue<int> q; q.push(mp[beginWord]); vst[mp[beginWord]] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == mp[endWord]) {return vst[u];}
        for (int v : edge[u]) {
            if (vst[v] == 0) {
                q.push(v);
                vst[v] = vst[u]+1;
            }
        }
    }

    return 0;
}

int main() {
    vector<string> v = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit", "cog", v);

    return 0;
}