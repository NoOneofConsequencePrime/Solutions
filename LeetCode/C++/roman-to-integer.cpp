public class Solution {
    Dictionary<char, int> conv = new Dictionary<char, int>(){
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    public int RomanToInt(string s) {
        int ret = conv[s[s.Length-1]];
        for (int i = s.Length-2; i >= 0; i--) {
            if (conv[s[i]] < conv[s[i+1]]) {ret -= conv[s[i]];}
            else {ret += conv[s[i]];}
        }

        return ret;
    }
}