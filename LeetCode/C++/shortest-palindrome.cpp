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
    ll *powB;

    string shortestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {return s;}
        powB = new ll[n]; powB[0] = 1;
        for (int i = 1; i < n; i++) {powB[i] = (powB[i-1]*B)%M;}

        vector<ll> hashL(n, 0), hashR(n, 0);
        string rev = s; reverse(rev.begin(), rev.end());
        hashL[0] = s[0]-'a'+1; hashR[0] = rev[0]-'a'+1;
        for (int i = 1; i < n; i++) {
            hashL[i] = (hashL[i-1]*B + s[i]-'a'+1)%M;
            hashR[i] = (hashR[i-1]*B + rev[i]-'a'+1)%M;
        }

        string ret = "";
        for (int i = n/2; i >= 1; i--) {
            ll lh = getH(hashL, 0, i);
            int r = n-1-i, l = r-i;
            ll rha = getH(hashR, l, r), rhb = getH(hashR, l+1, r+1);
            
            if (lh == rha) {
                for (int j = 0; j < l; j++) {
                    ret += rev[j];
                }
                ret += s;
                break;
            }
            if (lh == rhb) {
                for (int j = 0; j < l+1; j++) {
                    ret += rev[j];
                }
                ret += s;
                break;
            }
        }
        if (ret == "") {
            ret = rev+s.substr(1, s.length()-1);
        }

        return ret;
    }

    ll getH(vector<ll> &hsh, int l, int r) {
        if (l <= 0) return hsh[r];
        return (hsh[r]-(hsh[l-1]*powB[r-l+1])%M + M)%M;
    }
};