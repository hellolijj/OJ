/*题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

思路，使用二分法完成。
如果有多组树，输出乘积最小的。也就是首次遇到的那组数据。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int length = array.size();
        int low = 0;
        int hign = length-1;
        vector<int> res;
        int min_mutil = 0;
        while(low < hign) {
            if(array[low] + array[hign] == sum) {
                if(min_mutil > array[low] * array[hign]) {
                    res.clear();
                    res.push_back(array[low]);
                    res.push_back(array[hign]);
                }
                // return res; // 首次出现的就是乘ji最小的
            } else if(array[low] + array[hign] < sum) {
                low ++;
            } else {
                hign--;
            }
        }
        return res;
    }
};

/*
扩展如果是乘积最大的呢？
就需要使用一个变量记录成绩。类似与找最小的数字。
*/