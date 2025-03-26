class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum = skill[0] + skill[skill.size()-1];
        long long ret = 0;
        for (int i = 0; i < skill.size()/2; i++) {
            if (skill[i]+skill[skill.size()-1-i] == sum) {
                ret += (long long)skill[i]*skill[skill.size()-1-i];
            } else {
                return -1;
            }
        }

        return ret;
    }
};