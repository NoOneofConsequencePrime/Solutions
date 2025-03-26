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

stack<int> stk1, stk2;
void reOrder() {
    while (!stk2.empty()) {
        stk1.push(stk2.top());
        stk2.pop();
    }
}

MyQueue() {
}

void push(int x) {
    stk2.push(x);
}

int pop() {
    if (stk1.empty()) {reOrder();}
    
    int ret = stk1.top();
    stk1.pop();
    return ret;
}

int peek() {
    if (stk1.empty()) {reOrder();}
    
    return stk1.top();
}

bool empty() {
    return stk1.empty() && stk2.empty();
}

int main() {

    return 0;
}