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

string findDifferentBinaryString(vector<string>& nums) {
    string ret(nums[0].length(), '0');
    for (int i = 0; i < ret.length(); i++) {
        int a, b; a = b = 0;
        for (string& str : nums) {
            (str[i] == '0')? a++ : b++;
        }
        if (b < a) {
            ret[i] = '1';
            for (string& str : nums) {
                if (str[i] == '0') str.clear();
            }
        } else {
            ret[i] = '0';
            for (string& str : nums) {
                if (str[i] == '1') str.clear();
            }
        }
    }

    return ret;
}

int main() {
    vector<string> v = {"111","011","001"};
    cout << findDifferentBinaryString(v);
    cout << v[0];

    return 0;
}