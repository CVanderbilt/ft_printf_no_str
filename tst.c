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
/*
	kk = ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12,&a13,&a14,&a15);
	printf("%d\n", kk);
	kk = printf("%p%p%p%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12,&a13,&a14,&a15);
	printf("%d\n", kk)*/;

	char c;
	
	printf("%%.10c: >%c<\n", 'f');
	printf("%%.10d(p>s): >%.10d<\n", 2367);
	printf("%%.3d(p<s): >%.3d<\n", 2367);


/*	c = 0;
	kk = printf("sys>%c<\n", c);
	printf("%d\n", kk);
	kk = ft_printf("mio>%c<\n", c);
	printf("%d\n", kk);
	//ft_printnchr_fd("test de prueba", 10, 1);*/
}
