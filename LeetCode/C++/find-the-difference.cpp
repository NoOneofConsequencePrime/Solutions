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

char findTheDifference(string s, string t) {
    int sum = 0;
    for (char& c : s) sum -= c;
    for (char& c : t) sum += c;

    return sum;
}

int main() {
    cout << findTheDifference("", "y");

    return 0;
}