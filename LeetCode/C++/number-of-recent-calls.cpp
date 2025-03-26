class RecentCounter {
private:
    queue<int> pings;
public:
    RecentCounter() {}
    
    int ping(int t) {
        pings.push(t);
        while (!pings.empty() && t-pings.front() > 3000) pings.pop();
        
        return pings.size();
    }
};