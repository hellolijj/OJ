#include <cstdio>

using namespace std;

bool isji(int n) {
    if(n % 2 == 0) {
        return false;
    } else {
        return true;
    }
}

int main() {
	int N;
    scanf("%d", &N);
    while(N--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int res = 0;
        
        // 第一个数
        if(b == a) {
            if (a % 2 == 0) {
                res = a;
            } else {
                res = 0 - a;
            }
        } else {
            // 多个数字
            int cnt = b - a + 1;
            if(cnt % 2 == 0) {
                if(isji(a)) {
                    res = cnt / 2;
                } else {
                    res = 0 - (cnt / 2);
                }
            } else {
                if(isji(a)) {
                    res = (cnt-1)/2 - b;
                } else {
                    res = (cnt-1)/2 + a;
                }
            }
        }
        printf("%d\n", res);
    }
}