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

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    for (int a = 0, b = 0, sum = 0; b < 2*n; b++) {
        sum += gas[b%n]-cost[b%n];
        if (sum < 0) {
            a = b+1; sum = 0;
        } else if (b-a+1 == n) return a;
    }

    return -1;
}

int main() {
    vector<int> g = {1,2,3,4,5}, c = {3,4,5,1,2};
    cout << canCompleteCircuit(g, c);

    return 0;
}