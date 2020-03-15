#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

int main(void)
{
	int result = ft_printf("[%-5s]\n", "ab");
	printf("result = %d\n", result);
	
	result = ft_printf("[%5s][%-5s]\n", "ab", "123");
	printf("result = %d\n", result);
	
	char *str = "123";
	ft_printf("f = [%20p]\n", str);
	   printf("r = [%20p]\n", str);
	ft_printf("f = [%-20p]\n", str);
	   printf("r = [%-20p]\n", str);
	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return 0;
}
