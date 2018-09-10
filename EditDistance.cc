class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> paths(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      paths[i][0] = i;
    }
    for (int j = 1; j <= n; ++j) {
      paths[0][j] = j;
    }
    for (int p = 1; p <= m; ++p) {
      for (int q = 1; q <= n; ++q) {
        if (word1[p - 1] == word2[q - 1])
          paths[p][q] = paths[p - 1][q - 1];
        else {
          paths[p][q] = min(paths[p - 1][q] + 1,
                            min(paths[p - 1][q - 1] + 1, paths[p][q - 1] + 1));
        }
      }
    }
    return paths[m][n];
  }
};
