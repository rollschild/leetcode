class Solution {
public:
    vector<int> countBits(int num) {
       vector<int> result(num + 1);
        for(int i = 1; i <= num; ++i) {
            result[i] = result[i >> 1] + i%2; // or i&1 
        }
        return result;
    }
};
