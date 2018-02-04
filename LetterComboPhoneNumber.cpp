class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        map< char, vector<char> > dict;
        string full_num = "23456789";
        string full_alphabet = "abcdefghijklmnopqrstuvwxyz";
        for(int i = 0; i < 8 ; ++i) {
            if(full_num[i] <= '6') {
                dict[full_num[i]].push_back(full_alphabet[i*3]);
                dict[full_num[i]].push_back(full_alphabet[i*3+1]);
                dict[full_num[i]].push_back(full_alphabet[i*3+2]);
                
            }
            else if(full_num[i] == '7') {
                for(int j = 15; j <= 18; ++j) {
                    dict[full_num[i]].push_back(full_alphabet[j]);
                }
            }
            else if(full_num[i] == '8') {
                for(int j = 19; j <= 21; ++j) {
                    dict[full_num[i]].push_back(full_alphabet[j]);
                }
            }
            else {
                for(int j = 22; j <= 25; ++j) {
                    dict[full_num[i]].push_back(full_alphabet[j]);
                }
            }
        }
        
        for(int i = 0; i < digits.length(); ++i) {
            auto s = digits[i];
            if(s == '1' || s == '0') continue;
            if(result.empty()) {
                result.push_back("");
            }
            int original_size = result.size();
            for(int k = 0; k < original_size; ++k) {
                string o = result[k];
                for(auto p : dict[s]) {
                    result.push_back(o+p);
                }
            }
            result.erase(result.begin(), result.begin()+original_size);
        }
        return result;
    }
};
