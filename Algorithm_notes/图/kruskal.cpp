// 克鲁斯卡而算法，以边为贪心策略

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 101;

struct Eduge{
    int u, v;
    int cost;
}E[N];

int a[N]; // 存储并归集

// 按照 cost 从小到大排序
bool cmp(Eduge a, Eduge b) {
    return a.cost < b.cost;
}

int get_father(int x) {

    if(x == a[x]) {
        return x;
    }

    return get_father(a[x]);
}

int kruskal(int n, int m) {
    
    // init 并归集
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }

    // 对边的大小进行排序
    sort(E, E+m, cmp);

    // 初始化 已排边树为0
    int eduge_cnt = 0;
    int ans = 0;

    for(int i = 0; i < m; i++) {

        int u_father = get_father(E[i].u);
        int v_father = get_father(E[i].v);
        if(u_father != v_father) {
            a[u_father] = v_father;
            ans += E[i].cost;
            eduge_cnt ++;
            if(eduge_cnt == n - 1) {
                break;
            }
        }

    }

    // 非连通图情况
    if(eduge_cnt != n-1) return -1;   
    
    return ans;
}

int main() {
    int n, m;   // n个点 m条边
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
    }
    printf("%d\n", kruskal(n, m));
    return 0;
}

/*
输入
6 10
0 1 4
0 4 1
0 5 2
1 2 1
1 5 3
2 3 6
2 5 5
3 4 5
3 5 4
4 5 3
输出
11
*/