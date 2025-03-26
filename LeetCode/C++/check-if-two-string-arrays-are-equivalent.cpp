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

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string tmp1, tmp2;
    for (string str : word1) tmp1+=str;
    for (string str : word2) tmp2+=str;

    return !tmp1.compare(tmp2);
}

int main() {

    return 0;
}