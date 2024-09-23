class Solution {
public:
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef pair<int, pii> ppi;
    typedef pair<ll, ll> pll;
    #define f first
    #define s second

    const ll M = 1e9+7;
    const ll B = 31;
    vector<ll> hshS, hshB;
    vector<int> dp;
    unordered_set<ll> ust;

    int minExtraChar(string s, vector<string>& dictionary) {
        hshS = vector<ll>(s.length(), 0); hshB = vector<ll>(s.length(), 0);
        dp = vector<int>(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {dp[i] = i+1;}
        hshS[0] = s[0]-'a'+1; hshB[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            hshS[i] = (hshS[i-1]*B + s[i]-'a'+1)%M;
            hshB[i] = (hshB[i-1]*B)%M;
        }

        for (string &str : dictionary) {
            if (str.length() > s.length()) {continue;}
            ll tmp = str[0]-'a'+1;
            for (int i = 1; i < str.length(); i++) {
                tmp = (tmp*B + str[i]-'a'+1)%M;
            }
            ust.insert(tmp);
        }

        for (int r = 0; r < s.length(); r++) {
            for (int l = r; l >= 0; l--) {
                if (ust.count(getHsh(l, r)) != 0) {
                    dp[r] = min(dp[r], (l-1>=0)?dp[l-1]:0);
                }
                if (r >= 1) {dp[r] = min(dp[r], dp[r-1]+1);}
            }
        }

        return dp[s.length()-1];
    }

    ll getHsh(int l, int r) {
        if (l <= 0) {return hshS[r];}
        return (hshS[r] - hshS[l-1]*hshB[r-l+1]%M + M)%M;
    }
};