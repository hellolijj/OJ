/*
http://codeup.cn/problem.php?cid=100000566&pid=4
题目描述
求一元二次方程ax2+bx+c=0的根，三个系数a, b, c由键盘输入，且a不能为0，且保证b2-4ac>0。
程序中所涉及的变量均为double类型。
*/

#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a == 0) {
        printf("error: a 不能为0");
        return 0;
    }

    double delta = pow(b, 2) - 4 * a * c;
    if (delta <= 0) {
        printf("error: b ^ 2 - 4 * a * c 只能大于0");
        return 0;
    }

    printf("r1= %7.2f\n", (0 - b + sqrt(delta)) / (2 * a));
    printf("r2= %7.2f\n", (0 - b - sqrt(delta)) / (2 * a));
    
    return 0;
}

/**
 * 
 * ⚠️： 求跟公式 x = [-b±√(b2-4ac)]/(2a)
 * 输出的格式：%mf %0mf %.mf
 * 
 * 
 **/