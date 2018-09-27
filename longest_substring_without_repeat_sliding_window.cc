class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int size = s.length();
    set<char> dict{};
    int left = 0;
    int right = 0;
    int res = 0;
    while (left < size && right < size) {
      if (dict.find(s[right]) != dict.end()) {
        dict.erase(s[left++]);
      } else {
        dict.insert(s[right++]);
        res = max(res, right - left);
      }
    }
    return res;
  }
};
