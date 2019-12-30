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
	
	int *p;
	p = 0;
	//printf("%lu\n", &kk);
	kk = 99;
	printf("sys:\n");
	char str[] = "hola";
	//printf(0, &kk);
	//kk = printf("solo %hhd texto", 22337203685477);
	//kk = printf("%hhd", -45);
	printf("\n%d\n", kk);
	printf("mio:\n");
	//kk = ft_printf("%hhd", -45);
	//ft_printf(">%p<", &kk);
	//printf(0, &kk);
	//kk = ft_printf("solo %hhd texto", 22337203685477);
	printf("\n%d\n", kk);

	double var, var2;
	var = 16;
	var2 = 1223456;
	/*
	printf("pruebas %%f flag\n");
	printf("     %f\n", var);
	printf("%f\n", var2);
	printf("%.5f\n", var);
	printf("%20.5f\n", var);
	printf("%020f\n", var);
	printf("%.f\n", var);
	printf("%-020f\n", var);
	*/	
}