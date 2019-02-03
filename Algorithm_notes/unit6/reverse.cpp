#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() 
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    reverse(a, a+10);
    for(int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    string str = "hello world!";
    reverse(str.begin(), str.end());
    printf("%s", str.c_str());
    return 0;
}

// string 类型下定义的变量,变量的首字母不再是指针。若想取指针，使用str.begin + n