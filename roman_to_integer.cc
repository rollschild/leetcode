class Solution {
public:
  int romanToInt(string s) {
    map<char, int> dict{
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };
    int pos = 0;
    int value = 0;
    while (pos < s.length()) {
      if (pos == s.length() - 1)
        return value += dict[s[pos]];
      if (s[pos] == 'I') {
        if (s[pos + 1] == 'V' || s[pos + 1] == 'X') {
          value += dict[s[pos + 1]] - dict[s[pos]];
          pos += 2;
        } else {
          value += dict[s[pos]];
          ++pos;
        }
      } else if (s[pos] == 'X') {
        if (s[pos + 1] == 'L' || s[pos + 1] == 'C') {
          value += dict[s[pos + 1]] - dict[s[pos]];
          pos += 2;
        } else {
          value += dict[s[pos]];
          ++pos;
        }
      } else if (s[pos] == 'C') {
        if (s[pos + 1] == 'D' || s[pos + 1] == 'M') {
          value += dict[s[pos + 1]] - dict[s[pos]];
          pos += 2;
        } else {
          value += dict[s[pos]];
          ++pos;
        }
      } else {
        value += dict[s[pos]];
        ++pos;
      }
    }
    return value;
  }
};
