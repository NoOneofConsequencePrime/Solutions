class Solution {
    public:
        bool canMakeArithmeticProgression(vector<int>& arr) {
            sort(arr.begin(), arr.end());
            for (int i = 2; i < arr.size(); i++) {
                if (arr[i]-arr[i-1] != arr[i-1]-arr[i-2]) {return false;}
            }
    
            return true;
        }
    };aclass Solution {
        public:
            bool canMakeArithmeticProgression(vector<int>& arr) {
                unordered_map<int, int> st;
                int mi = INT_MAX, ma = INT_MIN;
                for (int x : arr) {
                    mi = min(mi, x);
                    ma = max(ma, x);
                    st[x]++;
                }
        
                if (st.size() == 1) {return true;}
        
                int chg = (ma-mi)/(arr.size()-1);
                for (int i = mi; i <= ma; i += chg) {
                    if (st.count(i) == 0) {return false;}
                    st[i]--;
                    if (st[i] == 0) {st.erase(i);}
                }
        
                return st.empty();
            }
        };