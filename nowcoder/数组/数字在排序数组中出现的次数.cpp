/*题目描述
统计一个数字在排序数组中出现的次数。

测试用例
{}
{1,2,3}, k=1
{1,2,3, 5,6,7} k=4
{1,2,3, 4,4,4,6,7} k=5
{1,2,3, 4,4,4,6,7} k=-1

注意：特殊情况是返回0 而不是返回-1
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) {
            return 0;
        }
        int left = 0, right = data.size()-1;
        if(data[left] > data[right]) {
            sort(data.begin(), data.end());
        }
        if(k < data[left] || k > data[right]) {
            return 0;
        }
        while(k < data[right]) {
            right--;
        }
        while(k > data[left]) {
            left++;
        }
        return right - left + 1;
    }
};