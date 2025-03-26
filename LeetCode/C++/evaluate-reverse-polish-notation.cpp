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
    for (int i = 0, prev = -1; i < tokens.size(); i++) {
        string str = tokens[i];
        if (isdigit(str[str.length()-1])) {
            prev++;
            if (prev < i) {tokens[prev] = str;}
        } else {
            int a = stoi(tokens[prev-1]), b = stoi(tokens[prev]);
            switch (str[0]) {
                case '+':
                    tokens[prev-1] = to_string(a+b);
                    break;
                case '-':
                    tokens[prev-1] = to_string(a-b);
                    break;
                case '*':
                    tokens[prev-1] = to_string(a*b);
                    break;
                case '/':
                    tokens[prev-1] = to_string(a/b);
            }
            prev--;
        }
    }

    return stoi(tokens[0]);
}

int main() {
    vector<string> v = {"10","6","9","3","+","-11","*","/","*"};
    cout << evalRPN(v);

    return 0;
}