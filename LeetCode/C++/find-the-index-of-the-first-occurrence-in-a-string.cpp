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

int strStr(string haystack, string needle) {
    return haystack.find(needle);
}

int main() {
    cout << strStr("sadbutsad", "sad");

    return 0;
}