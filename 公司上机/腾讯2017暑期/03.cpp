#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            v.push_back(t);
        }
        // 作差
        vector<int> res;
        for(int i = 1; i < n; i++) {
            res.push_back(abs(v[i] - v[i-1]));
        }
        sort(res.begin(), res.end());

        int min_count = 1, max_count = 1;
        for(int i = 1; i < n; i++) {
            if(res[i] != res[0]) break;
            min_count++;
        }
        for(int i = res.size()-2; i >= 0; i--) {
            if(res[i] != res[res.size()-1]) break;
            max_count++;
        }
        cout << min_count << " " << max_count << endl;
    }
    return 0;
}

