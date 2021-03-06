/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/

/*

暴力破解：
判断一个树有多少个1
然后遍历
时间复杂度o(nlgn)
*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i <= n; i++) {
        string s = to_string(i);
        for(int j = 0; j < s.length(); j++) {
            if(s[j] == '1') {
                cnt ++;
            }
        }
    }
    cout  << cnt << endl;
}