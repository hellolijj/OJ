/*http://codeup.cn/problem.php?cid=100000574&pid=3
题目描述
你的任务是计算若干整数的和。

输入
每行的第一个数N，表示本行后面有N个数。

如果N=0时，表示输入结束，且这一行不要计算。

输出
对于每一行数据需要在相应的行输出和。

样例输入
4 1 2 3 4
5 1 2 3 4 5
0 
样例输出
10
15
*/
#include <cstdio>

int main(int argc, char const *argv[])
{
	int N;
	while(true) {
		scanf("%d", &N);
		if (N == 0) break;
		int sum = 0, num;
		while(N--) {
			scanf("%d", &num);
			sum += num;
		}
		printf("%d\n", sum);
	}
	return 0;
}

// 网上参考答案，感觉还不如我的代码简介
/*
#include<stdio.h>
int main()
{
 int N,i,j;
 scanf("%d",&N);
 while(N!=0){
  int sum=0;
   
  for(i=0;i<N;i++){
   scanf("%d",&j);
   sum=sum+j;
  }
  printf("%d\n",sum);
  scanf("%d",&N);
 }
 return 0;
}
*/