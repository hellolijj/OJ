#include <cstdio>
#include <cmath>

const double eps = 1e-8;
#define Equ(a,b) ((fabs((a) - (b))) < (eps))
#define More(a,b) ((fabs((a) - (b))) > (eps))
#define Less(a,b) ((fabs((a) - (b))) < (-eps))
#define MoreEqu(a,b) ((fabs((a) - (b))) > (-eps))
#define LessEqu(a,b) ((fabs((a) - (b))) < (eps))
const double Pi = acos(-1.0)

void compare_flout_with_eps() {
    double n = 3.14;
	if (Equ(n, 3.14)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	
}

void compare_flout() {

    float n = 3.14;
	if (n == 3.14) {
		printf("true\n");
	} else {
		printf("false\n");
	}

}

int main(int argc, char const *argv[])
{
	compare_flout();
	compare_flout_with_eps();
}