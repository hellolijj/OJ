/*顺时针打印矩阵.cpp

题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.


思路一：遍历
获取行数、列树、圈数、按照规则遍历。
注意点1: 如何判断不重复打印（下面的行数  > 左边的行数 左边的列数 < 右边的列数）
错误的地方： 圈数求错了。要多试几个边界值

方法二：旋转？

*/

#include<cstdio>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        res.clear();
        int raw = matrix.size();     // 行数
        int low = matrix[0].size();  // 列数
        int cicle = ((raw < low ? raw : low)+1)/2;   // 圈数
        for (int i = 0; i < cicle; ++i)
        {
            // left -> right
            for (int left = i; left <  low -i; ++left)
            {   
                res.push_back(matrix[i][left]);   
            }
            // top -> botton
            for (int top = i+1; top < raw-i; ++top)
            {   
                res.push_back(matrix[top][low-i-1]);   
            }
            // right -> left  rwa-i-1 != i 是为了不重复
            for (int right = low-i-2; right >= i&&raw-i-1!=i; right--)
            {
                res.push_back(matrix[raw-i-1][right]);       
            }
            // botton -> top
            for (int botton = raw-2-i; botton > i && low-i-1!=i  ; botton--)
            {
                res.push_back(matrix[botton][i]);
            }
        }

        return res;
    }
};

int main() {
    // vector<vector<int> >vi(6, vector<int>(4));
    // int a[6][4] = {{1,2, 3, 4}, {5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20},{21,22,23,24}};
    // vector<vector<int> >vi(1, vector<int>(1));
    // int a[6][4] = {{1}};

    vector<vector<int> >vi(5, vector<int>(2));
    int a[5][2] = {{1,2},{3,4},{5,6},{7,8},{9,10}};

    

    for(int i = 0; i < vi.size(); i++) {
        for(int j = 0; j < vi[i].size(); j++) {
            vi[i][j] = a[i][j];
        }
    }
    class Solution solu;
    vector<int> res = solu.printMatrix(vi);
    for(int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    
    return 0;
}