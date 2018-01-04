#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    int lastAnswer = 0;
    cin >> n >> q;
    vector<vector<int>> seqList(n, vector<int>());
    int array[q][3];
    int x = 0;
    int y = 0;
    for(int m = 0; m < q; ++m) {
        for(int p = 0; p < 3; ++p) {
            cin >> array[m][p];
        }
    }
    for(int m = 0; m < q; ++m) {
        x = array[m][1];
        y = array[m][2];
        if(array[m][0] == 1) {
            seqList[(x^lastAnswer) % n].push_back(y);
        }
        else {
            lastAnswer = seqList[(x^lastAnswer) % n][y % n];
            cout << lastAnswer << endl;
        }
    }
    
    return 0;
}
