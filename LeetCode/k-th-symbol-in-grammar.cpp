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

int kthGrammar(int n, int k) {
    if (n == 1) return !(k%2);
    return k%2? kthGrammar(n-1, (k+1)/2) : !kthGrammar(n-1, (k+1)/2);
}

int main() {
    cout << kthGrammar(2, 2);

    return 0;
}