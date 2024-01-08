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

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

unordered_map<long long, int> mp;
unordered_map<int, int> cnt;

long long hsh(long long a, long long b, int c) {// val, chg
    return (long long)a*1e10+b+c*1e5;
}

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size(), ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j--) {
            long long chg = nums[i]-nums[j];
            if (chg == 0) continue;
            // printf("%lld, %d\n", hsh(nums[j], chg, j), mp[hsh(nums[j], chg, j)]);
            if (mp.count(hsh(nums[j], chg, j)) != 0) {
                mp[hsh(nums[i], chg, i)] = mp[hsh(nums[j], chg, j)]+1;
                ret += max(0, mp[hsh(nums[i], chg, i)]-2);
                printf("%d %d %d\n", i, j, mp[hsh(nums[i], chg, i)]-2);
            }
            if (mp.count(hsh(nums[i], chg, i)) == 0) mp[hsh(nums[i], chg, i)] = 2;
        }
        cnt[nums[i]]++;
    }

    for (auto& [key, val] : cnt) {
        if (val < 3) continue;
        int sum = 1, prev = 1; val -= 2;
        for (int i = 2; i <= val; i++) {
            prev = sum+1+prev+1;
            sum += prev;
        }
        ret += sum;
    }

    return ret;
}

int main() {
    vector<int> v(1000, 1000);
    //  234
    // 1234
    // 1 34

    // 1+2+2+6+5
    // +(sum+1)+(prev+1) = prev

    //   345
    //  2 45
    //  2345
    // 1  45
    // 1 345
    // 12 45
    // 12345
    cout << numberOfArithmeticSlices(v);

    return 0;
}