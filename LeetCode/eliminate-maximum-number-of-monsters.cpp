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
    vector<int> time;
    for (int i = 0; i < dist.size(); i++) time.push_back((dist[i]+speed[i]-1)/speed[i]);
    sort(time.begin(),time.end());
    for (int i = 0; i < time.size(); i++) {
        if (time[i] <= i) return i;
    }

    return time.size();
}

int main() {
    vector<int> a = {1,3,4}, b = {1,1,1};
    cout << eliminateMaximum(a, b);

    return 0;
}