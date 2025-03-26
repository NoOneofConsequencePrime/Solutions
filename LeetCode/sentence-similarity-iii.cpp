class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() == sentence2.length()) {
            if (sentence1 == sentence2) {return true;}
            else {return false;}
        } else if (sentence1.length() > sentence2.length()) {
            swap(sentence1, sentence2);
        }

        vector<string> v1 = tokenize(sentence1), v2 = tokenize(sentence2);
        if (v1.size() >= v2.size()) {return false;}
        size_t found = sentence2.find(sentence1);
        if (found != string::npos) {
            if (found == 0 && sentence2[found+sentence1.length()] == ' ') {
                return true;
            } else if (found == sentence1.length()-sentence2.length() && sentence2[found-1] == ' ') {
                return true;
            }
        }
        int i;
        for (i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                cout << i << endl;
                break;
            }
        }
        for (int j = 0; j < v1.size()-i; j++) {
            if (v1[v1.size()-j-1] != v2[v2.size()-j-1]) {
                printf("%s, %s\n", v1[v1.size()-j-1].c_str(), v2[v2.size()-j-1].c_str());
                return false;
            }
        }

        return true;
    }

    vector<string> tokenize(string &str) {
        vector<string> ret;
        for (int i = 0, s = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                ret.push_back(str.substr(s, i-s));
                s = i+1;
            } else if (i == str.length()-1) {
                ret.push_back(str.substr(s, i-s+1));
            }
        }

        return ret;
    }
};