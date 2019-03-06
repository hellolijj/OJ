/*开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325

输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符

输入例子1:
E:\V1R2\product\fpgadrive.c 1325

输出例子1:
fpgadrive.c 1325 1
*/

#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 这个题目最好要需要了解 pair结构

struct File{
    string filename;
    int low;
}file[10];


// 根据最后一个"\" 寻找
string get_filename(const string &path) {
    if(path.length() == 0) {
        return "";
    }
    // 剔除 ：E:\V1R2\product\fpgadrive.c 1325
    int start;
    string res;
    if((start = path.find(":")) != -1) {
        res = path.substr(start+1);
    }
    int ops1 = 0, ops2 = res.find("\\");
    while(ops2 != -1) {
        ops1 = ops2+1;
        ops2 = res.find("\\", ops1);
    }
    return res.substr(ops1);
}

bool cmp(pair<map<string , int>, int> p1, pair<map<string , int>, int> p2) {
    return p1.second < p2.second;
}

int main() {
    string path;
    int low;
    int n;
    

    map<string, int> tmp;
    map<map<string, int> ,int> mp;     // mp[文件名, 行号] 出现的个数
    
    pair<map<string , int>, int> ppair;
    vector<pair<map<string, int>, int> > v;

    
    while(cin >> path >> low) {

        string filename = get_filename(path);
        tmp[filename] = low;
        mp[tmp]++;
        
        // sort map
        v.assign(mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);

        for(vector<pair<map<string, int>, int> >::iterator it = v.begin(); it!=v.end(); it++) {
            map<string, int> a = it->first;
            map<string, int>::iterator i = a.begin();
            cout << i->first << " " << i->second  << endl;
        }

    } 
    return 0;
}
