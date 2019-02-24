/*
找出数字中首次只出现一次的元素

思路一：
暴力破解 时间复杂度o(n^2)

思路二：
建立一个map，记录出现的值、位置、次数
空间复杂度o(n),时间复杂度o(n)

*/

#include <cstdio>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() == 0) {
            return -1;
        }

        map<char, int> mp;
        for(int i = 0; i < str.length(); i++) {
            mp[str[i]] ++;
        }

        for(int i = 0; i < str.length(); i++) {
            if(mp[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    class Solution solu;
    printf("%d\n", solu.FirstNotRepeatingChar("abcac"));
    return 0;
}