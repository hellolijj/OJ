#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    
    vector<int> vi;
    vi.push_back(2);
    vi.push_back(100);
    vi.push_back(0);
    vi.push_back(6);

    

    for(int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }

    printf("\n");
    sort(vi.begin(), vi.end(), cmp);
    for(vector<int>::iterator it = vi.begin();it!=vi.end();it++)
    {
        printf("%d ", *it);
    }
}