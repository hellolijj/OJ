/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

思路：此题的本质就是比较n1 n2两个数字哪个排在前面，哪个排在后面
无非就两种情况 n1n2 或者 n2n1 比较 这两个值的大小就可以了。
由于拼接起来的数值可能很大，因此用字符串排序即可

字符串拼函数

s = s1 + s2;

int => stirng
s1 = to_string(n1)

*/

#include <cstdio>
#include <queue>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    static bool cmp(int n1, int n2) {
        string s1 = to_string(n1) + to_string(n2);
        string s2 = to_string(n2) + to_string(n1);
        return s1 < s2;
    }

    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty()) {
            return res;
        }
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i = 0; i < numbers.size(); i++) {
            res += to_string(numbers[i]);
        }
        return  res;
    }
};

int main() {
    int a[6] = {3, 32, 321};
    vector<int> v(3);
    for(int i = 0; i < v.size(); i++) {
        v[i] = a[i];
    }
    class Solution solu;
    printf("%s\n", solu.PrintMinNumber(v).c_str());
    return 0;
}