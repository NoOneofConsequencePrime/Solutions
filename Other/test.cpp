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

vector<int> fun(vector<int> hand) {
    if (hand.size() == 0) return {};
    else {
        hand.pop_front();
        vector<int> a = fun(hand);
        for (auto& x : a) printf("%d ", x);
        printf("\n");
        a.push_front(hand[0]);
        for (auto& x : a) printf("%d ", x);
    }
}

int main(void) {
    vector<int> v = {1,2,3};
    cout << v.end()-v.begin();
}