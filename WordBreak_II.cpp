class Solution {
public:
    unordered_map< string, vector<string> > dict;
    vector<string> append(string word, vector<string> book) {
        for(int j = 0; j < book.size(); ++j) {
            book[j] += " ";
            book[j] += word;
        }
        return book;
    }
        
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dict.count(s)) return dict[s];
        vector<string> result;
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) {
            result.push_back(s);
        }
        for(int i = 1; i < s.length(); ++i) {
            string sub = s.substr(i);
            if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                string rem = s.substr(0, i);
                vector<string> prev = append(sub, wordBreak(rem, wordDict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        dict[s] = result;
        return result;
    }
};
