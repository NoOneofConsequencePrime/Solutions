#define f first
#define s second
typedef long long ll;
typedef pair<ll, ll> pll;

class Solution {
private:
    struct Node {
        ll val;
        Node *next;
        Node *prev;
        bool isValid;

        Node(): val(0), next(nullptr), prev(nullptr), isValid(true) {}
        Node(ll x) : val(x), next(nullptr), prev(nullptr), isValid(true) {}
        Node(ll x, Node *next, Node* prev) : val(x), next(next), prev(prev), isValid(true) {}
    };
    typedef pair<pll, pair<Node*, Node*>> pr;
public:
    int minimumPairRemoval(vector<int>& nums) {
        Node* head = new Node(nums[0]);
        Node* tmp = head;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        int cntOff = 0;
        for (int i = 1; i < nums.size(); i++) {
            tmp->next = new Node(nums[i]);
            tmp->next->prev = tmp;
            pq.push({{tmp->val+nums[i], i-1}, {tmp, tmp->next}});
            if (tmp->val > nums[i]) {cntOff++;}
            tmp = tmp->next;
        }
        
        int ret = 0;
        while (!pq.empty()) {
            pr curr = pq.top(); pq.pop();
            if (cntOff <= 0) {break;}
            if (!curr.s.f->isValid || !curr.s.s->isValid) {continue;}
            if (curr.f.f != curr.s.f->val + curr.s.s->val) {continue;}
            
            Node* a = curr.s.f->prev;
            Node* b = curr.s.s->next;
            if (curr.s.f->val > curr.s.s->val) {cntOff--;}
            if (a && a->val > curr.s.f->val) {cntOff--;}
            if (b && curr.s.s->val > b->val) {cntOff--;}
            curr.s.f->val += curr.s.s->val;
            curr.s.f->next = b;
            if (b) {b->prev = curr.s.f;}
            curr.s.s->isValid = false;
            
            if (a) {
                pq.push({{a->val+curr.s.f->val, curr.f.s}, {a, curr.s.f}});
                if (a->val > curr.s.f->val) {cntOff++;}
            }
            if (b) {
                pq.push({{b->val+curr.s.f->val, curr.f.s}, {curr.s.f, b}});
                if (curr.s.f->val > b->val) {cntOff++;}
            }
            
            ret++;
        }
        
        return ret;
    }
};