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

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        sort(meetings.begin(), meetings.end());
        int roomCnt[n] = {};
        bool room[n] = {};
        priority_queue<pii> pq;
        for (auto &v : meetings) {
            while (pq.size() >= n) {
                pii cur = pq.top(); pq.pop();
                room[cur.s] = false;
            }
            int fr = -1;
            for (int i = 0; i < n; i++) {
                if (!room[i]) {
                    fr = i;
                    break;
                }
            }

            room[fr] = true;
            roomCnt[fr]++;
            pq.push({v[1], fr});
        }

        int ret = -1, mx = INT_MIN;
        for (int i = 0; i < n; i++) [
            if (roomCnt[i] > mx) {
                mx = roomCnt;
                ret = i;
            }
        ]

        return ret;
    }
};

int main() {

    return 0;
}