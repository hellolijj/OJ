#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    vector<int> vi;

    for(int i = 1; i <= 5; i++) {
        vi.push_back(i);
    }
    
    // 遍历方法1
    for(int i = 0; i < 5; i++) {
        printf("%d ", vi[i]);
    }

    // 遍历方法2
    vector<int>::iterator it = vi.begin();
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(it+i));
    }

    

    vi.pop_back();
    // 遍历方法4    
    // it 不支持 it < vi.end的写法 只支持 it < vi.end
    for(; it != vi.end(); it++) {
        printf("%d ", *(it));
    }

    



    // 在  vi.begin() + 2 处 添加 元素
    vi.insert(vi.begin() + 2, -1);
    // 遍历方法3
    for(int i = 0; i < vi.size(); i++) {
        printf("%d ", *(vi.begin() +i));
    }

    // 删除某个元素
    vi.erase(vi.begin());
    // 删除某个区间的元素
    vi.erase(vi.begin(), vi.end());

    vi.clear();
    return 0;
}

// gcc 编译默认编译 c程序，不加载 c++的库，因此使用如下命令加载c++库
// gcc vector.cpp -o test -lstdc++