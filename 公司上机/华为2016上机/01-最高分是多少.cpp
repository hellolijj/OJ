/*老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩.

输入描述:
输入包括多组测试数据。
每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
学生ID编号从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。

输出描述:
对于每一次询问操作，在一行里面输出最高成绩.

输入例子1:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

输出例子1:
5
6
5
9

*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 30010;
const int M = 5010;

int student[N];

int get_max_core(int a, int b) {
    int max_core = 0;
    int hign = max(a, b);
    int low = min(a, b);
    for(int i = low; i <= hign; i++) {
        if(student[i] > max_core) {
            max_core = student[i];
        }
    }
    return max_core;
}

int main() {
    int m, n;   // n表示人数 m表示要操作记录
    while(scanf("%d%d", &n, &m) != EOF) {
        vector<int> res;

        fill(student, student+N, -1);
    
        for(int i = 1; i <= n; i++) {
            scanf("%d", &student[i]);
        }

        for(int i = 0; i < m; i++) {
            int a, b;
            char c;
            getchar(); // 读入换行
            scanf("%c%d%d", &c, &a, &b);
            if(a < 1 || a > n) {
                return -1;
            }
            if(!(c == 'Q' || c == 'U')) {
                return -1;
            }
            if(c == 'U') {
                student[a] = b;
            } else {
                res.push_back(get_max_core(a, b));
            }
        }

        for(int i = 0; i < res.size(); i++) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}


// 问题在字符如何输入
// scanf("%c")
// getchar()
// 是可以读入换行的

/*
错误地方：
int get_max(int a, int b){
    int a = min(a, b);
    int b = max(a, b);
    
    // 其实此时 a, b并不是我们想要的 最大值 最小值
}
*/