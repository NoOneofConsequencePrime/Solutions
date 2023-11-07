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

int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    for (int i = 0; i < dist.size(); i++) dist[i] = (dist[i]+speed[i]-1)/speed[i];
    sort(dist.begin(), dist.end());
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] <= i) return i;
    }

    return dist.size();
}

int main() {
    vector<int> a = {1,3,4}, b = {1,1,1};
    cout << eliminateMaximum(a, b);

    return 0;
}