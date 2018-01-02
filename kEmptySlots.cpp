class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> blooming;
        int l = flowers.size();
        for(int i = 0; i < l; ++i) {
            set<int>::iterator itr = blooming.insert(flowers[i]).first;
            if(itr != blooming.begin()) {
                if(flowers[i] - *(--itr) == k + 1) {
                    return i + 1;
                }
                ++itr; // because we subtract 1 from itr
            }
            if(++itr != blooming.end()) {
                // set<int>::iterator itrr = ++itr;
                if(*itr - flowers[i] == k + 1) return i + 1;
            }
        }
        return -1;
    }
};
