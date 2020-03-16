#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

int main(void)
{
	int result_f;
	int result_r;
	char *str = "123";

	ft_printf("f = [%20p]\n", str);
	   printf("r = [%20p]\n", str);
	ft_printf("f = [%-20p]\n", str);
	   printf("r = [%-20p]\n", str);

	result_f = ft_printf("f = [%-20s]\n", (void *)0);
	result_r =    printf("r = [%-20s]\n", (void *)0);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%c]\n", '\0');
	result_r =    printf("r = [%c]\n", '\0');
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%.3s]\n", "hello");
	result_r =    printf("r = [%.3s]\n", "hello");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%7.5s]\n", "bombastic");
	result_r =    printf("r = [%7.5s]\n", "bombastic");
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);
	result_f = ft_printf("f = [%7.5u]\n", 123);
	result_r =    printf("r = [%7.5u]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);


	result_f = ft_printf("f = [%#10.5x]\n", 123);
	result_r =    printf("r = [%#10.5x]\n", 123);
	printf("result_f = %d\nresult_r = %d\n\n", result_f, result_r);




	ft_printf("f = [%-20p]\n", (void *)0);
	   printf("r = [%-20p]\n", (void *)0);






	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");
	return 0;
}
