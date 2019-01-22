#include <cstdio>

void change(int &n) {
    n = 3;
}
int main() {
    int a = 10;
    change(a);
    printf("%d\n", a);
}