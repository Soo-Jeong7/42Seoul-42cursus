#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int test_memmove(void)
{
	char *src = "abcd1234!";
	char *result = (char *)malloc(sizeof(char) * 10);
	char *result2 = (char *)malloc(sizeof(char) * 10);
	result[3] = 'A';
	result2[3] = 'A';
	char *addr = ft_memmove(result, src, sizeof(char) * 10);
	char *addr2 = memmove(result2, src, sizeof(char) * 10);
	for (int i = 0; i < 10; i++) {
		//printf("%c, %c\n", result[i], result2[i]);
		if (result[i] != result2[i])
			return (0);
	}
	for (int i = 0; i < 10; i++) {
		result[i] = src[i];
		result2[i] = src[i];
	}
	ft_memmove(result, result + 1, 9);
	memmove(result2, result2 + 1, 9);
	for (int i = 0; i < 10; i++) {
		//printf("%c, %c\n", result[i], result2[i]);
		if (result[i] != result2[i])
			return (0);
	}
	ft_memmove(result + 1, result, 9);
	memmove(result2 + 1, result2, 9);
	for (int i = 0; i < 10; i++) {
		//printf("%c, %c\n", result[i], result2[i]);
		if (result[i] != result2[i])
			return (0);
	}
	return (1);
}


int test_memccpy(void)
{
	char *src = "abcd1234!";
	char *result = (char *)malloc(sizeof(char) * 10);
	char *result2 = (char *)malloc(sizeof(char) * 10);
	result[3] = 'A';
	result2[3] = 'A';
	char *addr = ft_memccpy(result, src, '!', sizeof(char) * 10);
	char *addr2 = memccpy(result2, src, '!', sizeof(char) * 10);
	for (int i = 0; i < 10; i++) {
		//printf("%c, %c\n", result[i], result2[i]);
		if (result[i] != result2[i])
			return (0);
	}
	return (1);
}

int test_memcpy(void)
{
	char *src = "abcd1234!";
	char *result = (char *)malloc(sizeof(char) * 10);
	char *result2 = (char *)malloc(sizeof(char) * 10);
	ft_memcpy(result, src, sizeof(char) * 10);
	memcpy(result2, src, sizeof(char) * 10);
	for (int i = 0; i < 10; i++) {
		//printf("%c, %c\n", result[i], result2[i]);
		if (result[i] != result2[i])
			return (0);
	}
	return (1);
}

int test_bzero(void)
{
	char *result = (char *)malloc(sizeof(char) * 10);
	char *result2 = (char *)malloc(sizeof(char) * 10);
	ft_bzero(result, sizeof(char) * 10);
	bzero(result2, sizeof(char) * 10);
	for (int i = 0; i < 10; i++) {
		//printf("%x, %x\n", result[i], result2[i]);
		if (result[i] != result2[i])
			return (0);
	}
	return (1);
}

int test_memset(void)
{
	unsigned char *result = (unsigned char *)malloc(sizeof(unsigned char) * 10);
	unsigned char *result2 = (unsigned char *)malloc(sizeof(unsigned char) * 10);
	int c = 999999999;
	ft_memset(result, c, sizeof(unsigned char) * 10);
	memset(result2, c, sizeof(unsigned char) * 10);
	for (int i = 0; i < 10; i++)
	{
		//printf("%x %x\n", result[i], result2[i]);
		if (result[i] != result2[i])
			return (0);
	}
	return (1);
}

int main(void)
{
	if (!test_memset())
		printf("%s\n", "memset error");
	if (!test_bzero())
		printf("%s\n", "bzero error");
	if (!test_memcpy())
		printf("%s\n", "memcpy error");
	if (!test_memccpy())
		printf("%s\n", "memccpy error");
	if (!test_memmove())
		printf("%s\n", "memmove error");

}

