/*题目描述
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,
嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,
决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 
如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

*/
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() != 5) {
            return false;
        }
        int min = 14, max = -1;
        int d[15] = {0};
        d[0] = -5;    // 0可以重复
        for(int i = 0; i < numbers.size(); i++) {
            d[numbers[i]]++;
            if(numbers[i] == 0) {
                continue;
            }
            if(d[numbers[i]] > 1) {
                return false;
            }
            if(numbers[i] < min) {
                min = numbers[i];
            }
            if(numbers[i] > max) {
                max = numbers[i];
            }
        }
        if(max - min < 5) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    // test case {1,2,3,4,5} {0,1,2,4,5},{5,2,1,0,2}
    // int a[5] = {1,2,3,4,5};
    // int a[5] = {0,1,2,3,5};
    // int a[5] = {0,1,2,4,5};
    // int a[5] = {0,1,0,1,0};     // 相同的元素
    int a[5] = {1,3,0,7,0};  // 测试不通过
    vector<int> res;
    for(int i = 0; i < 5; i++){
        res.push_back(a[i]);
    }
    class Solution solu;
    if(solu.IsContinuous(res)){
        printf("true");
    }else{
        printf("false");
    }
    return 0;
}

// 总结这一类题目很多边界条件没有考虑全，这类题目应该先把所有的边界条件写好，再写程序