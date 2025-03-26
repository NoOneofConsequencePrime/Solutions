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
    int ret = arr[0], cnt = 0;
    for (int j = 1; j < arr.size()*2; j++) {
        int i = j%arr.size();
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