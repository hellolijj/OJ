#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
    	int v[42];
		v[0] = 0;
		v[1] = 1;
    	for (int i = 2; i <= n; ++i)
    	{
    		v[i] = v[i-1] + v[i-2];
    	}
    	return v[n];
    }
};

int main() {
	class Solution solu;
	for(int i = 0; i <= 39; i++) {
		printf("%d\n", solu.Fibonacci(i));
	}
	
}