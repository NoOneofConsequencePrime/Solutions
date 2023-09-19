#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        if (citations.size()-i <= citations[i]) return citations.size()-i;
    }

    return 0;
}

int main() {
    vector<int> v = {3,0,6,1,5};
    cout << hIndex(v);

    return 0;
}