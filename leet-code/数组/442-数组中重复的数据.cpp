/*给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

示例：

输入:
[4,3,2,7,8,2,3,1]

输出:
[2,3]

*/

/*
testcase
[4,3,2,7,8,2,3,1]
[1]
[1,2]

*/

#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != i+1) {
                if(nums[i] == nums[nums[i]-1]) {
                    res.push_back(nums[i]);
                    break;
                } 
                
                // swap(nums[i], nums[nums[i]-1]);
                int temp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[nums[i]-1] = temp;
            }
        }
        return res;
    }
};

int main() {
    class Solution solu;
    int a[8] = {4,3,2,7,8,2,3,1};
    vector<int> p;
    for(int i = 0; i < 8; i++) {
        p.push_back(a[i]);
    }
    vector<int> res = solu.findDuplicates(p);
    for(int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }

    return 0;
}