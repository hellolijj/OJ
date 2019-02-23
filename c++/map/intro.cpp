#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    map<int, int> mp;
    int a[15] = {1,2,3,4,5,0,9,6,4,2,4,1,6,9,1};
    for(int i = 0; i < 15; i++) {
        mp[a[i]] ++;
    }

    // map 的遍历
    for(map<int, int>::iterator i = mp.begin(); i != mp.end(); i++) {
        printf("%d:%d\n", i->first, i->second);
    }
    return 0;
}