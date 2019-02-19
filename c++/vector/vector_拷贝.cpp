#include<cstdio>
#include<vector>

using namespace std;

int main() {
    vector<int> a(5, 99);
    vector<int> b;
    // b.swap(a);
    b.assign(a.begin(), a.end());

    b[2] = 0;
    for(vector<int>::iterator i = b.begin(); i != b.end(); i++) {
        printf("%d ", *i);
    }

    for(vector<int>::iterator i = a.begin(); i != a.end(); i++) {
        printf("%d ", *i);
    }

    printf("\nhello world\n");
    return 0;
}

// 结论：
// 说明 swap是浅拷贝。b.swap(a); b生效了，确失效了
// b.assign是深拷贝，重新分配了新的内存空间