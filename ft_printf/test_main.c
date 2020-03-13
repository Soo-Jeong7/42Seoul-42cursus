#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

int main(void)
{
	int result = ft_printf("ab = %s\n[123]\n", "ab");
	printf("result = %d\n", result);
	
	result = ft_printf("[%s][%s]", "ab", "123");
	printf("result = %d\n", result);
	

	system("leaks a.out > leaks_result && cat leaks_result | grep leaked");

	return 0;
}
