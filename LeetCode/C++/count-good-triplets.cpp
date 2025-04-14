class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n = arr.size();
            int ret = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    for (int k = j+1; k < n; k++) {
                        int na = arr[i], nb = arr[j], nc = arr[k];
                        if (abs(na-nb) <= a && abs(nb-nc) <= b && abs(na-nc) <= c) {
                            ret++;
                        }
                    }
                }
            }
    
            return ret;
        }
    };