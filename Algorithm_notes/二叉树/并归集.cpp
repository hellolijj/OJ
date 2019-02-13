// 并归集 是一种集合的操作

#include <cstdio>

const int N = 101;

int a[N];     // 存储元素集合关系

bool is_root[N] = {false};

int get_father(int x) {
    if(x == a[x]) {
        return x;
    }
    return get_father(a[x]);
}

void union_set(int x, int y) {
    int x_father = get_father(x);
    int y_father = get_father(y);
    if(x_father != y_father) {
        a[x_father] = y_father;
    }
}

int main() {
    int n, m;   // n个元素， m种关系
    scanf("%d%d", &n, &m);
    
    // init 
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    // 输入
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        union_set(x, y);
    }

    // 统计树的颗树
    for(int i = 1; i <= n; i++) {
        is_root[get_father(i)] = true;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(is_root[i] == true) {
            ans++;
        }
    }

    //输出
    printf("%d\n", ans);
    return 0;
}

/*
输入
4 2
1 4
2 3
输出
2

输入
7 5
1 2
2 3
3 1
1 4
5 6
输出
3
*/