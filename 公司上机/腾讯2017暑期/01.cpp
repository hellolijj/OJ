#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_length(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    vector<vector<int> > v(len1+1, vector<int>(len2+1));
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0 || j == 0) {
                v[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                v[i][j] = v[i-1][j-1] + 1;  
            } else {
                v[i][j] = max(v[i][j-1], v[i-1][j]);
            }
        }
    }
    return v[len1][len2];
}

int main() {
    string s;
    while(cin >> s) {
        string r(s.rbegin(), s.rend());
        cout << s.length() - max_length(s, r) << endl;
    }
    return 0;
}