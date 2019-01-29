#include <cstdio>

// 计算 a^b
long long binary_pow(int a, int b) {

	if(b % 2 == 0) {
		return binary_pow(a, b/2) * binary_pow(a, b/2);
	} else {
		return binary_pow(a, b-1) * a;
	}

}

int main(int argc, char const *argv[])
{
	
	return 0;
}


// if(b%2==1) 也可以用 if(b&1) 来替代，为了提高计算速度也可以这样写