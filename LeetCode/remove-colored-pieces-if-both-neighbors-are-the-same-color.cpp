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

bool winnerOfGame(string colors) {
    int A = 0, B = 0;
    for (int i = 2; i < colors.size(); i++) {
        if (colors[i] == colors[i-1] && colors[i-1] == colors[i-2]) {
            if (colors[i] == 'A') A++;
            else B++;
        }
    }
    
    return A>B;
}

int main() {
    cout << winnerOfGame("ABBBBBBBAAA");

    return 0;
}