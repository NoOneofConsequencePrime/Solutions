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

const int M = 1e9+7;

int countVowelPermutation(int n) {
    int a, e, i, o, u; a = e = i = o = u = 1;
    for (int j = 2; j <= n; j++) {
        int A = e;
        int E = (a+i)%M;
        int I = ((a+e)%M+(o+u)%M)%M;
        int O = (i+u)%M;
        int U = a;

        a = A; e = E; i = I; o = O; u = U;
    }

    return (((a+e)%M+(i+o)%M)%M+u)%M;
}

int main() {
    cout << countVowelPermutation(2);

    return 0;
}