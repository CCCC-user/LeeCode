/*
	2020 8 27
	输入实型数据 a、b，然后输出 a、b 的值。 
*/
#include<stdio.h>
int main()
{
	double a,b;

	printf("Please input two numbers:");
	scanf("%lf,%lf",&a,&b);
	printf("a=%.6f,b=%.6f\n",a,b);

	return 0;
}
/*
输出结果:
	Please input two numbers:6.79,5.823
	a=6.790000,b=5.823000
	Press any key to continue

*/