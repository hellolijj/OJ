#include <cstdio>
#include <vector>


using namespace std;


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for(int i = array.size() - 1, j = 0; i >= 0 &&j < array[0].size(); ) {
            if(target == array[i][j]) {
                return true;
            }
            if(array[i][j] < target) {
                j++;
                continue;
            }
            if(array[i][j] > target) {
                i--;
                continue;
            } 
        }
        return false;
    }
};

int main() {
    
    vector<vector<int> >vi(2, vector<int>(3));

    int a[2][3] = {{2, 3, 4}, {6, 9, 10}};

    for(int i = 0; i < vi.size(); i++) {
        for(int j = 0; j < vi[i].size(); j++) {
            vi[i][j] = a[i][j];
        }
    }
    
    class Solution Solu;
    
	if(Solu.Find(10, vi)) {
        printf("查到了\n");
    } else {
        printf("没有查到\n");
    }
    return 0;
}

/*
注意点：
1、vector的基本使用，一维数组、二维数组
2、这个题目中有序二维数组的查找，时间复杂度点优化
*/

/* 思路

1、因为是有序二维数组，从左下角往右上方找过去

2、先比行，比每一行的第一个元素，找到对应的行。然后再去比这一行的元素。

*/
