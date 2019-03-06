/*
平安果 
 
简要描述： 
给定一个M行N列的矩阵（M*N个格子），每个格子中放着一定数量的平安果。 
你从左上角的各自开始，只能向下或者向右走，目的地是右下角的格子。 
每走过一个格子，就把格子上的平安果都收集起来。求你最多能收集到多少平安果。 
注意：当经过一个格子时，需要一次性把格子里的平安果都拿走。 
限制条件：1<N,M<=50；每个格子里的平安果数量是0到1000（包含0和1000）. 
 
输入描述： 
输入包含两部分： 
第一行M, N 
接下来M行，包含N个平安果数量 
 
输出描述： 
一个整数 
最多拿走的平安果的数量 

示例： 
 
输入 
2 4 
1 2 3 40 
6 7 8 90 
 
输出 
136
*/

#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

// m行 n 列

int apple[51][51];

int dp(int m, int n) {
	if (m == 0 && n == 0) {
		return apple[0][0];
	}
	else if (m == 0) {
		return apple[m][n] + dp(m, n - 1);
	}
	else if (n == 0) {
		return apple[m][n] + dp(m-1, n);
	}
	else {
		return max(apple[m][n] + dp(m, n - 1), apple[m][n] + dp(m - 1, n));
	}
}


int main() {
	
    int m, n; 
    cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
            cin >> tmp;
			apple[i][j] = tmp;
		}
	}

	cout << dp(1, 3);
}

// 思路：使用动态规划，找到动态规划的出口和状态方程