#include <bits/stdc++.h>
using namespace std;

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

bool canMakeSubsequence(string str1, string str2) {
    int j = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (j >= str2.length()) {break;}
        if (isChk(str1[i], str2[j])) {
            j++;
        }
    }

    return j == str2.length();
}

bool isChk(char a, char b) {
    return a==b || (b-a == 1) || (a-b == 25);
}

int main() {

    return 0;
}