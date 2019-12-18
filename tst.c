#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int kk;
	int a01;
	int a02;
	int a03;
	int a04;
	int a05;
	int a06;
	int a07;
	int a08;
	int a09;
	int a10;
	int a11;
	int a12;
	int a13;
	int a14;
	int a15;
	
	//printf("%lu\n", &kk);
	printf("sys:\n");
	kk = printf("solo %-10.5d texto", -216);
	printf("\n%d\n", kk);
	printf("mio:\n");
	kk = ft_printf("solo %-10.5d texto", -216);
	printf("\n%d\n", kk);
}
