class Solution {
public:
    bool isWithinLimit(int count[], int num) {
        int val = 0;
        for(int i = 0; i < 128; ++i) {
            if(count[i] > 0) {
                ++val;
            }
        }
        return (val <= num);
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = s.length();
        if(l == 0) return 0;
        if(k == 0) return 0;
        int begin = 0;
        int max_begin = begin;
        int end;
        int window = 1;
        int count[128];
        int num = 0;
        memset(count, 0, sizeof(count));
        for(char c : s) {
            if(count[c - 0] == 0) {
                ++num;
            }
            ++count[c - 0];
        }
        /*
        if(num < k) {
            cout << "Not enough unique characters. Exiting... " << endl;
            return;
        }
        */
        // use substr(), you stupid fuck!
        memset(count, 0, sizeof(count));
        ++count[s[begin]-0];
        for(end = begin + 1; end < l; ++end) {
            ++count[s[end] - 0];
            while(!isWithinLimit(count, k)) {
                --count[s[begin] - 0];
                ++begin;
            }
            if((end - begin + 1) > window) {
                window = end - begin + 1;
                max_begin = begin;
            }
        }
        return window;
    }
};
