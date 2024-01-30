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
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    for (auto &str : tokens) {
        if (isdigit(str[str.length()-1])) {
            stk.push(stoi(str));
        } else {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            switch (str[0]) {
                case '+':
                    stk.push(a+b);
                    break;
                case '-':
                    stk.push(a-b);
                    break;
                case '*':
                    stk.push(a*b);
                    break;
                case '/':
                    stk.push(a/b);
            }
        }
    }

    return stk.top();
}

int main() {
    vector<string> v = {"10","6","9","3","+","-11","*","/","*"};
    cout << evalRPN(v);

    return 0;
}