typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

class MyCalendar {
private:
    vector<pii> v;

    bool isContained(int a, int b) {
        b--;
        for (pii p : v) {
            if (p.f <= a && a <= p.s) {
                return true;
            } else if (p.f <= b && b <= p.s) {
                return true;
            } else if (a <= p.f && p.f <= b) {
                return true;
            } else if (a <= p.s && p.s <= b) {
                return true;
            }
        }
        return false;
    }
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (!isContained(start, end)) {
            v.push_back({start, end-1});
            return true;
        }

        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */