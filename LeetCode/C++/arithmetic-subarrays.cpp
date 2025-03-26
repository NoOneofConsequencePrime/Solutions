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

const int MM = 502;

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ret(l.size());
    bool chk[MM] = {0};
    for (int idx = 0; idx < l.size(); idx++) {
        int li = l[idx], ri = r[idx], n = ri-li+1;

        if (n <= 2) ret[idx] = 1;
        else {
            memset(chk, 0, sizeof(chk));
            int miA = INT_MAX, miB = INT_MAX;
            for (int i = li; i <= ri; i++) {
                if (nums[i] < miA) {
                    miB = miA; miA = nums[i];
                } else if (nums[i] < miB) miB = nums[i];
            }

            int chg = miB-miA;
            bool flag = true;
            for (int i = li; i <= ri; i++) {
                if ((nums[i]-miA)%chg != 0) {
                    flag = false; break;
                }
                int tmp = (nums[i]-miA)/chg;
                if (tmp < 0 || tmp >= n || chk[tmp]) {
                    flag = false; break;
                } else chk[tmp] = true;
            }
            
            ret[idx] = flag;
        }
    }

    return ret;
}

int main() {
    vector<int> v = {4,6,5,9,3,7}, l = {0}, r = {3};//l = {0,0,2}, r = {2,3,5};
    vector<bool> ret = checkArithmeticSubarrays(v, l, r);
    for (bool x : ret) cout << x << " ";

    return 0;
}