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

string addBinary(string a, string b) {
    vector<int> v;
    int cry = 0;
    if (a.length() > b.length()) a.swap(b);
    int A = a.length()-1, B = b.length()-1;

    for (int i = 0; i <= A; i++) {
        int tmp = cry+a[A-i]+b[B-i]-'0'*2;
        v.push_back(tmp%2);
        cry = tmp > 1;
    }
    for (int i = A+1; i <= B; i++) {
        int tmp = cry+b[B-i]-'0';
        v.push_back(tmp%2);
        cry = tmp > 1;
    }
    if (cry != 0) v.push_back(1);

    int n = v.size()-1;
    string ret(n+1, '0');
    for (int i = 0; i <= n; i++) ret[n-i] = v[i]+'0';

    return ret;
}

int main() {
    cout << addBinary("0", "0");

    return 0;
}