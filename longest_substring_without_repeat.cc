#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    string sub = "";
    vector<string> res;
    size_t l = 0;
    if (s.length() == 0)
      return 0;
    if (s.length() == 1)
      return 1;
    for (int i = 0; i < s.length() - 1; ++i) {
      sub = "";
      sub += s[i];
      for (int j = i + 1; j < s.length(); ++j) {
        if (sub.find(s[j]) != string::npos) {
          l = max(l, sub.length());
          break;
        }
        sub += s[j];
      }
      l = max(l, sub.length());
    }
    return l;
    }
};

int main() {
  Solution solution;
  cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
  return 0;
}
