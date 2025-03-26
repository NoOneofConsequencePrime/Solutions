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

string largestOddNumber(string num) {
    for (int i = num.length()-1; i >= 0 && !((num[i]-'0')%2); i--) num.pop_back();

    return num;
}

int main() {
    cout << largestOddNumber("52");

    return 0;
}