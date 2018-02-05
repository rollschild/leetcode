class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<bool> used(wordDict.size(), true);
        string temp = "";
        int leftpos = 0;
        bool initial = true;
        int initial_length = 1;
        int rightpos = leftpos + initial_length - 1;
        while(rightpos < s.length()) {
            string sub = s.substr(leftpos, rightpos-leftpos+1);
            auto itr = find(wordDict.begin(), wordDict.end(), sub);
            int distance = itr - wordDict.begin();
            vector<bool>::iterator itr_used = used.begin() + distance;
            if(itr != wordDict.end() && *itr_used) {
                *itr_used = false;
                if(initial) {
                    // the first match
                    initial_length = rightpos - leftpos + 1;
                    initial = false;
                }
                // string occurs in the vector/dictionary
                if(rightpos == (s.length() - 1)) {
                    // end of string
                    // need to restart
                    temp += sub;
                    result.push_back(temp);
                    if(rightpos-leftpos+1 >= s.length()) break;
                    leftpos = 0;
                    ++initial_length;
                    rightpos = leftpos + initial_length - 1;
                    temp = "";
                    used.assign(used.size(), true);
                }
                else {
                    temp += sub;
                    temp += " ";
                    leftpos = rightpos + 1;
                    rightpos = leftpos;
                }
            }
            // now if rightpos not reaching end of string
            else if(rightpos < (s.length()-1)) {
                ++rightpos;
            }
            // if rightpos is already end of string
            else {
                temp = "";
                if(rightpos-leftpos+1 >= s.length()) break;
                leftpos = 0;
                ++initial_length;
                rightpos = leftpos + initial_length - 1;
                used.assign(used.size(), true);
            }
        }
        return result;
    }
};
