/*题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

方法一：使用map保存每个数字出现对次数
然后对map进行排序

方法二：
使用两个变量 a,b 分别保存 当然数字，当前数字出现的次数。
利用 出现的次数超过数组一半这个特点
for(遍历) {
    if(b == 0) {
        a = num[i];
        b = 1;
    }
    if(num[i] == a) {
        b++
    } else {
        b--;
    }
}
*/
#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:

    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    }

    int MoreThanHalfNum_Solution(vector<int> numbers) {

        map<int, int> mp;
        for(int i = 0; i < numbers.size(); i++) {
            mp[numbers[i]] ++;
        }

        // sort
        vector<pair<int, int> > vi(mp.begin(), mp.end());
        sort(vi.begin(), vi.end(), cmp);

        if(vi[0].second > numbers.size() / 2) {
            return vi[0].first;
        } else {
            return 0;
        } 
    }

    // 方法二：
    int MoreThanHalfNum_Solution1(vector<int> numbers) {

        if(numbers.empty()) {
            return 0;
        }
        stack<int> s;
        for(int i = 0; i < numbers.size(); i++) {
            if(s.empty()) {
                s.push(numbers[i]);
            } else if(numbers[i] == s.top()){
                s.push(numbers[i]);
            } else {
                s.pop();
            }
        }

        int n = s.top();
        int times = 0;

        // 统计top数出现的次数，
        for(int i = 0; i < numbers.size(); i++) {
            if(n == numbers[i]) {
                times++;
            }
        }
        if(times * 2 <= numbers.size()) {
            return 0;
        } else {
            return n;
        }
    }
    
};



int main() {
    int a[9] = {1,2,3,2,2,2,5,4,2};
    
    class Solution solu;
    vector<int> v(9);
    for(int i = 0; i < v.size(); i++) {
        v[i] = a[i];
    }
    
    printf("%d\n", solu.MoreThanHalfNum_Solution1(v));
    
    return 0;
}