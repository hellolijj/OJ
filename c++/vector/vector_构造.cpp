#include <cstdio>
#include <vector>

using namespace std;

int main() {

    // vector<int> vi(5);
    vector<int> vi(5, 1939);
    
    // vector<int> obj(vi)
    // vector<int> obj(vi.begin()+2, vi.end());
    vector<int> obj(vi.begin(), vi.end());  // [） begin相当于0 end() 相当于5

    for(int i = 0; i < vi.size(); i++) {
        printf("%d ", vi[i]);
    }

    printf("\n");

    for(vector<int>::iterator i = obj.begin(); i != obj.end(); i++) {
        printf("%d ", *i);
    }
}