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
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret = {{1}};
    for (int i = 1; i < numRows; i++) {
        vector<int> tmp = {1};
        for (int j = 0; j < ret[i-1].size()-1; j++) {
            tmp.push_back(ret[i-1][j]+ret[i-1][j+1]);
        }
        tmp.push_back(1);
        ret.push_back(tmp);
    }

    return ret;
}

int main() {
    vector<vector<int>> v = generate(5);
    for (auto& vec : v) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}