#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        vector<int> vi;
        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            vi.push_back(t);
        }
        sort(vi.begin(), vi.end());
        map<int, int> mp;
        for(int i = 0; i < vi.size(); i++) {
            mp[vi[i]] ++;
            if(mp[vi[i]] == 1) {
                cout << vi[i] << endl;
            }
        }
    }
    return 0;
}