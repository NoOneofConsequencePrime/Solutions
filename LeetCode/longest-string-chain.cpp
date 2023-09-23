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

int chkStr(string a, string b) {
    int cnt = 0;
    for (int i = 0, j = 0; i < a.length() && j < b.length(); i++, j++) {
        while (j < b.length() && a[i] != b[j]) {
            cnt++;
            j++;
        }
    }
    cnt += (b.length()-1 == a.length() && cnt == 0);
    
    return b.length()-1 == a.length() && cnt == 1;
}

bool cmp(string& a, string& b) {return a.length() < b.length();}

int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), cmp);
    int dist[words.size()]; memset(dist, 0, sizeof(dist));
    queue<int> q;
    for (int i = 0; i < words.size(); i++) {
        dist[i] = 1; q.push(i);
    }

    int ret = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = u+1; i < words.size(); i++) {
            if (chkStr(words[u], words[i]) && dist[i] < dist[u]+1) {
                dist[i] = dist[u]+1;
                q.push(i);
                ret = max(ret, dist[i]);
            }
        }
    }

    return ret;
}

int main() {
    vector<string> v = {"a","b","ba","bca","bda","bdca"};
    cout << longestStrChain(v);

    return 0;
}