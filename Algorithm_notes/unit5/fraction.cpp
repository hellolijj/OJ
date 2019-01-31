#include <cstdio>
#include <cmath>
#include <cstdlib>


// 分数的结构体
struct Fraction
{
	int up;     // 分子
	int down;     // 分母
}; 


int gcd(int m, int n) {
	if (m < n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}
	if (n == 0) 
		return m;
	else 
		return gcd(m, m - n);
}
// 分数的化简
Fraction reduction(Fraction f) {

	if(f.down < 0) {
		f.down = 0 - f.down;
		f.up = 0 - f.up;
	}

	if (f.up == 0) {
		f.down = 1;
	} else {
		int d = gcd(abs(f.up), abs(f.down));
		f.down /= d;
		f.up /= d;
	}
	return f;
}

// 分数的加法
Fraction reduction(Fraction f1, Fraction f2) {
	Fraction res;
	res.up = f1.up * f2.down + f1.down * f2.up;        // 求分子
	res.down = f1.down * f2.down;						// 求分母
	return reduction(res);
}

// 分数的减法   f1 - f2
Fraction minu(Fraction f1, Fraction f2) {
	Fraction res;
	res.up = f1.up * f2.down - f1.down * f2.up;        // 求分子
	res.down = f1.down * f2.down;						// 求分母
	return reduction(res);
}

// 分数的乘法
Fraction multi(Fraction f1, Fraction f2) {
	Fraction res;
	res.up = f1.up * f2.up;        // 求分子
	res.down = f1.down * f2.down;						// 求分母
	return reduction(res);
}

// 分数的加法
Fraction divide(Fraction f1, Fraction f2) {
	Fraction res;
	res.up = f1.up * f2.down;        // 求分子
	res.down = f1.down * f2.up;						// 求分母
	return reduction(res);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}