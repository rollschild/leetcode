class Solution {
public:
    string findContestMatch(int n) {
        vector<string> strV(n);
        for(int i = 0; i < n; ++i) {
            strV[i] = to_string(i + 1);
        }
        while(n > 1) {
            for(int r = 0; r < n/2; ++r) {
                strV[r] = "(" + strV[r] + "," + strV[n - 1 - r] + ")";
            }
            n /= 2;
        }
        return strV[0];
    }
};
