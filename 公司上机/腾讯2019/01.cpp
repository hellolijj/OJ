#include <cstdio>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if(n >= m) {
        printf("%d\n", 1);
    } else {
        printf("%d\n",  (m / n) + 1);
    }
}