#include <cstdio>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(5);

    while(!s.empty()){
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}