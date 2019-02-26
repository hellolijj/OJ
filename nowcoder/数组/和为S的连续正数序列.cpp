/*题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

*/

#include <cstdio>
#include <vector>
// #include <>

using namespace std;

class Solution {
public:
    vector<vector<int> > res;       // 所有符合的情况
    vector<vector<int> > FindContinuousSequence(int sum) {
        if (sum < 3) {
            return res;
        }

        vector<int> temp_vector;
        int left = 1, right = 2;
        temp_vector.push_back(left);
        temp_vector.push_back(right);

        while(true) {
            if(temp_vector.size() < 2) {
                break;
            }

            // todo: 可用求和公式做
            int temp_sum = 0;
            for(int i = 0; i < temp_vector.size(); i++) {
                temp_sum += temp_vector[i];
            }
            
            if(temp_sum == sum) {
                res.push_back(temp_vector);
                temp_vector.erase(temp_vector.begin());
            } else if (temp_sum < sum) {
                temp_vector.push_back(++right);
            } else {
                temp_vector.erase(temp_vector.begin());
            }
        }
        return res;
    }
};

int main() {
    class Solution solu;
    vector<vector<int> > result = solu.FindContinuousSequence(100);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}