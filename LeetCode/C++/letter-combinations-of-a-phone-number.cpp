class Solution {
    private:
        string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;
        void fun(string& digits, int idx, string tmp) {
            if (idx >= digits.length()) {
                ret.push_back(tmp);
                return;
            }
            
            int dig = digits[idx]-'0';
            for (char c : arr[dig]) {
                fun(digits, idx+1, tmp+c);
            }
        }
    public:
        vector<string> letterCombinations(string digits) {
            if (!digits.empty()) {fun(digits, 0, "");}
    
            return ret;
        }
    };