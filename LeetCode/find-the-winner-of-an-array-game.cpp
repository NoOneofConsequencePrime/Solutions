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

int getWinner(vector<int>& arr, int k) {
    int len = arr.size();
    for (int i = 0; i < len; i++) arr.push_back(arr[i]);

    int ret = arr[0], cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (ret > arr[i]) cnt++;
        else {
            ret = arr[i];
            cnt = 1;
        }
        if (cnt == k) return ret;
    }

    return ret;
}

int main() {
    vector<int> v = {2,1,3,5,4,6,7};
    cout << getWinner(v, 2);

    return 0;
}