#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
	int i = 0; int N = 1000;
	float uc1, uc2 = 0;
	float un1, un2;
	while (i < N) {
		un1 = uc1 + 0.02 *(uc2 - uc1) - 0.05 * uc1;
		un2 = uc2 + 0.01 *(1 - uc2) - 0.002 * (uc2 - uc1);
		i++;
		uc1 = un1;
		uc2 = un2;
		printf("%f, %f\n", uc1, uc2);
	}
	return 0;
}