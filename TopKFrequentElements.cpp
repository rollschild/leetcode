class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        vector<int> result;
        for(auto i : nums) {
            if(frequency.count(i)) ++frequency[i];
            else frequency[i] = 1;
        }
        map< int, vector<int> > dict;
        unordered_map<int, int>::iterator itr;
        map< int, vector<int> >::reverse_iterator dict_itr;
        for(itr = frequency.begin(); itr != frequency.end(); ++itr) {
            dict[itr->second].push_back(itr->first);
        }
        
        for(dict_itr = dict.rbegin(); dict_itr != dict.rend(); ++dict_itr) {
            for(auto j : dict_itr->second) {
                result.push_back(j);
                // --k;
                if(result.size() == k) return result;
            }
        }
        // return result;
    }
};
