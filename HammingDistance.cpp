class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int count = 0;
        string result = bitset<32>(z).to_string();
        for(int i = 0; i < result.length(); ++i) {
            if(result[i] == '1') ++count;
        }
        return count;
    }
};
