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

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size(); i++) {
        if (flowerbed[i]) continue;
        bool chk = true;
        if (i > 0 && flowerbed[i-1]) chk = false;
        if (i < flowerbed.size()-1 && flowerbed[i+1]) chk = false;

        n -= chk;
        if (chk) flowerbed[i] = 1;
    }

    return n <= 0;
}

int main() {
    vector<int> v = {1, 0, 0, 0, 1};
    cout << canPlaceFlowers(v, 1);

    return 0;
}