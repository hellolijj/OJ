#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
求n个数字的组合为m输入两个整数n和m，从数列1,2,3...n中随意取几个数，使其和等于m，要求列出所有的组合。
思路：
针对第一个字符，我们有两种选择：
第一是把这个数字放到组合中去，接下来我们需要在剩下的n-1个数字中选取和为m-n[n]
第二是不把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选择m个字符。
*/



class Solution {

public:
    vector<string> res;
    void find_factor(int sum,int n)
    {
        //递归出口
        if(n<=0||sum<=0)
            return;
        //输出找到的数
        // sum == 要求的值
        if(sum == n)
        {
            list1.reverse();
            for(list<int>::iterator iter=list1.begin();iter!=list1.end();iter++)
                cout<<*iter<<"+";
            cout<<n<<endl;
            list1.reverse();
        }
        list1.push_front(n);
        find_factor(sum-n,n-1);//n放在里面
        list1.pop_front();
        find_factor(sum,n-1);//n不放在里面
    }
};

int main() {
    nt sum,n;
    cin>>sum>>n;
    cout<<"所有可能的序列，如下："<<endl;
    class Solution solu;
    solu.find_factor(sum,n);
    return 0;
}