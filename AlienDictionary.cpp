class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map< char, unordered_set<char> > smaller;
        unordered_map< char, unordered_set<char> > greater;
        unordered_set<char> chars;
        string s;
        for(auto word : words) {
            chars.insert(word.begin(), word.end()); // this line of code is to set up a complete dictionary
            for(int i = 0; i < min(s.size(), word.size()); ++i) {
                if(s[i] != word[i]) {
                    greater[s[i]].insert(word[i]);
                    smaller[word[i]].insert(s[i]);
                    break;
                }
            }
            s = word;
        }
        string res;
        unordered_set<char> dup(chars);
        for(auto largenum : smaller) dup.erase(largenum.first); // this will leave the first element only
        while(!dup.empty()) {
            char initial = *(dup.begin());
            dup.erase(initial);
            res += initial;
            for(auto a : greater[initial]) {
                smaller[a].erase(initial);
                if(smaller[a].empty()) dup.insert(a);
            }
        }
        return (res.size() == chars.size()) ? res : "";
    }
};
