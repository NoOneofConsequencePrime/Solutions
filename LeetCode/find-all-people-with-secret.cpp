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
private:
    int fd(int u) {
        if (p[u] == u) {return u;}
        else {return fd(p[u]);}
    }
public:
    vector<int> p;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        p = vector<int>(n, 0);
        sort(meetings.begin(), meetings.end(), [this](vector<int> &a, vector<int> &b) -> bool {
            if (a[2] != b[2]) {return a[2] < b[2];}
            return fd(a[0])==fd(0) || fd(a[1])==fd(0);
        });
        for (int i = 0; i < n; i++) {p[i] = i;}
        p[firstPerson] = p[0];
        for (auto &v : meetings) {
            int a = v[0], b = v[1];
            if (fd(a) != fd(0) && fd(b) != fd(0)) {continue;}
            if (fd(a) != fd(b)) {
                p[fd(a)] = fd(b);
            }
        }

        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (fd(i) == fd(0)) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};