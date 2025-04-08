class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            string ret = word1+word2;
            for (int i = 0; i < min(word1.length(), word2.length()); i++) {
                ret[i*2] = word1[i];
                ret[i*2+1] = word2[i];
            }
    
            if (word1.length() < word2.length()) {swap(word1, word2);}
            for (int i = word2.length(); i < word1.length(); i++) {
                ret[word2.length()*2 + (i-word2.length())] = word1[i];
            }
    
            return ret;
        }
    };