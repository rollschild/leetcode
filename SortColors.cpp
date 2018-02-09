class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        for(auto i : nums) {
            ++freq[i];
        }
        int count = 0;
        for(int j = 0; j < 3; ++j) {
            for(int k = count; k < count + freq[j]; ++k) {
                nums[k] = j;
            }
            count += freq[j];
        }
    }
};
