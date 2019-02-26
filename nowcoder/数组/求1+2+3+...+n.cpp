#include <cstdio>

int Sum_Solution(int n) {
    int sum = n;
    bool ans = (n>0)&&((sum+=Sum_Solution(n-1))>0);
    return sum;
}

int main() {
    printf("%d\n", Sum_Solution(10));
}