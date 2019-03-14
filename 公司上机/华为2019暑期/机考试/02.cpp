#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


int max_sq(vector<vector<int> > &matrix) {
    int row = matrix.size();  //行大小
    int line = matrix[0].size();  //列大小

    //一个与matrix相同大小的辅助数组
    vector<vector<int> > tmp(row, vector<int>(line));

    //将matrix的第一行和第一列元素直接存放到
    for(int i=0;i<row;i++){
        tmp[i][0] = matrix[i][0];
    }
    for(int i=0;i<line;i++){
        tmp[0][i] = matrix[0][i];
    }

    for(int i=1;i<row;i++){
        for(int j=1;j<line;j++){
            if(matrix[i][j] == 1){
                tmp[i][j] = 
                min(min(tmp[i-1][j],tmp[i][j-1]),tmp[i-1][j-1]) + 1;
            }
            if(matrix[i][j] == 0){
                tmp[i][j] = 0;
            }

        }
    }

    int max=0;  //记录tmp中最大元素的值（tmp中元素值表示正方形的边长)
    for(int i=0;i<row;i++){
        for(int j=0;j<line;j++){
            if(tmp[i][j] > max){
                max = tmp[i][j];
            }
        }
    }

    return max*max;

}
    



long long get_max_quare(vector<vector<long long> > &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    long long M = matrix.size(), N = matrix[0].size(), res = 0;
    vector<vector<long long> > dp(M, vector<long long>(N));
    for (int i = 0; i < M; i++) {
        if (matrix[i][0] == 1) {
            dp[i][0] = 1;
            res = 1;
        }
    }
    for (int j = 0; j < N; j++) {
        if (matrix[0][j] == 1) {
            dp[0][j] = 1;
            res = 1;
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return (long long) res * res;
}

int main() {
    long long n;
    cin >> n;
    vector<vector<long long> > metux;
    vector<vector<long long> > metux_back;  // 0换1 1换0
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        vector<long long> temp;
        vector<long long> temp_back;
        for(int j = 0; j < t.length(); j++) {
            if(t[j] - '0' == 0) {
                temp.push_back(0);
                temp_back.push_back(1);
            } else {
                temp.push_back(1);
                temp_back.push_back(0);
            }
        }
        metux.push_back(temp);
        metux_back.push_back(temp_back);
    }

    cout << max(get_max_quare(metux), get_max_quare(metux_back)) << endl;
    return 0;
}

/*
3
110
111
110 

8
1010111111
0000000111
1010110111
0000111111
1010111111
0000001111
1010111111
0000110001
*/