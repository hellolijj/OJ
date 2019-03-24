/*给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 重复(某字符串出现在之前的字符串中)就切割，并重新计数字
        if(s.length() <= 1) {
            return s.length();
        }

        map<char, int> mp;

        int l = 1;
        int max_length = 1;
        mp[s[0]] = 1;
        for(int i = 1; i < s.length(); i++) {
            mp[s[i]]++;
            if(mp[s[i]] == 1) {
                l ++;
            } else {
                max_length = max(max_length, l);
                l = 1;
                mp.clear();
                mp[s[i]] = 1;
            }
        }
        max_length = max(max_length, l);
        return max_length;
    }
};

int main() {
    class Solution solu;
    printf("%d\n", solu.lengthOfLongestSubstring("dvdf"));
    return 0;
}