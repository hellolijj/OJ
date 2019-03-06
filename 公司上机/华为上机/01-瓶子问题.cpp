#include <cstdio>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    int n;
    while(cin >> n) {
        queue<char> q;
        for(int i = 0; i < n; i++) {
            q.push('*');
        }

        int count = 0;
        while(q.size() > 1) {
            q.pop();
            q.pop();
            q.pop();
            q.push('*');
            count++;
        }
        cout << count << endl;
    }
    return 0;
}