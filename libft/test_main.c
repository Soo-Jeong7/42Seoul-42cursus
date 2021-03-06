#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int test_strlcat(void)
{
	size_t size = 15;
	char *src = "abcd1234";
	char *dst = (char*)malloc(sizeof(char) * size * 10);
	char *dst2 = (char*)malloc(sizeof(char) * size * 10);
	for (int i = 0; i <= size; ++i) {
		ft_bzero(dst, size);
		ft_bzero(dst2, size);
		int result = ft_strlcat(dst, src, i);
		int result2 = strlcat(dst2, src, i);
		//printf("%d, %d\n", result, result2);
		//printf("%s, %s\n", dst, dst2);
		if (result != result2)
			return (0);
		if (ft_memcmp(dst, dst2, size) != 0)
			return (0);
	}
	for (int i = 0; i <= size; ++i) {
		int result = ft_strlcat(dst, src, i);
		int result2 = strlcat(dst2, src, i);
		//printf("%d, %d\n", result, result2);
		//printf("%s, %s\n", dst, dst2);
		if (result != result2)
			return (0);
		if (ft_memcmp(dst, dst2, size * 10) != 0)
			return (0);
	}
	return (1);
}

int test_strlcpy(void)
{
	size_t size = 15;
	char *src = "abcd1234!";
	char *dst = (char*)malloc(sizeof(char) * size);
	char *dst2 = (char*)malloc(sizeof(char) * size);
	for (int i = 0; i <= size; ++i) {
		ft_bzero(dst, size);
		ft_bzero(dst2, size);
		int result = ft_strlcpy(dst, src, i);
		int result2 = strlcpy(dst2, src, i);
		//printf("%d, %d\n", result, result2);
		//printf("%s, %s\n", dst, dst2);
		if (result != result2)
			return (0);
		if (ft_memcmp(dst, dst2, size) != 0)
			return (0);
	}
	return (1);
}

int test_strlen(void)
{
	char *src = "abcd1234!";
	int result = ft_strlen(src);
	int result2 = strlen(src);
	//printf("%d, %d\n", result, result2);
	if (result != result2)
		return (0);
	src = "abc21212fewafcce34!";
	result = ft_strlen(src);
	result2 = strlen(src);
	//printf("%d, %d\n", result, result2);
	if (result != result2)
		return (0);
	src = "";
	result = ft_strlen(src);
	result2 = strlen(src);
	//printf("%d, %d\n", result, result2);
	if (result != result2)
		return (0);
	return (1);
}

int test_memcmp(void)
{
	char *src1 = "abcd1234!";
	char *src2 = "abcd1234!";
	int result = ft_memcmp(src1, src2, 10);
	int result2 = memcmp(src1, src2, 10);
	//printf("%d, %d\n", result, result2);
	if (result != result2)
		return (0);
	src1 = "abc21234!";
	src2 = "abcd1234!";
	result = ft_memcmp(src1, src2, 10);
	result2 = memcmp(src1, src2, 10);
	//printf("%d, %d\n", result, result2);
	if (result != result2)
		return (0);
	return (1);
}

int test_memchr(void)
{
	char *src = "abcd1234!";
	char *result;
	char *result2;
	for (int i = 0; i < 10; i++) {
		result = ft_memchr(src, src[i], 10);
		result2 = memchr(src, src[i], 10);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

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

int test_strchr(void)
{
	char *src = "abcd1234!";
	char *result;
	char *result2;
	for (int i = 0; i < 10; i++) {
		result = ft_strchr(src, src[i]);
		result2 = strchr(src, src[i]);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	char *charset = "A0B12";
	for (int i = 0; i < 6; i++) {
		result = ft_strchr(src, charset[i]);
		result2 = strchr(src, charset[i]);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_strrchr(void)
{
	char *src = "abcd1234!";
	char *result;
	char *result2;
	for (int i = 0; i < 10; i++) {
		result = ft_strrchr(src, src[i]);
		result2 = strrchr(src, src[i]);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	char *charset = "A0B12";
	for (int i = 0; i < 6; i++) {
		result = ft_strrchr(src, charset[i]);
		result2 = strrchr(src, charset[i]);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_strncmp(void)
{
	int result;
	int result2;
	char *src1 = "abcd1234!";
	char *src2 = "abcd1234!";
	for (int i = 0; i < 20; i++) {
		result = ft_strncmp(src1, src2, i);
		result2 = strncmp(src1, src2, i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	src1 = "abcd1234!";
	src2 = "abcd1";
	for (int i = 0; i < 20; i++) {
		result = ft_strncmp(src1, src2, i);
		result2 = strncmp(src1, src2, i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	src1 = "abcd1234!";
	src2 = "abcd1nfeowinaawe";
	for (int i = 0; i < 20; i++) {
		result = ft_strncmp(src1, src2, i);
		result2 = strncmp(src1, src2, i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	src1 = "abcd1234!";
	src2 = "abcd1234!winaawe";
	for (int i = 0; i < 20; i++) {
		result = ft_strncmp(src1, src2, i);
		result2 = strncmp(src1, src2, i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_strnstr(void)
{
	char *result;
	char *result2;
	char *src1 = "abcd1234!";
	char *src2 = "abcd1234!";
	for (int i = 0; i < 20; i++) {
		result = ft_strnstr(src1, src2, i);
		result2 = strnstr(src1, src2, i);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	src1 = "abcd1234!131";
	src2 = "abcd1";
	for (int i = 0; i < 20; i++) {
		result = ft_strnstr(src1, src2, i);
		result2 = strnstr(src1, src2, i);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	src1 = "abcd1234!";
	src2 = "abcd1nfeowinaawe";
	for (int i = 0; i < 20; i++) {
		result = ft_strnstr(src1, src2, i);
		result2 = strnstr(src1, src2, i);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	src1 = "abcd1234!";
	src2 = "abcd1234!winaawe";
	for (int i = 0; i < 20; i++) {
		result = ft_strnstr(src1, src2, i);
		result2 = strnstr(src1, src2, i);
		//printf("%p, %p\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_atoi(void)
{
	int result;
	int result2;
	char str[100];
	for (int i = -15; i < 15; ++i) {
		sprintf(str, "%d", i);
		result = ft_atoi(str);
		result2 = atoi(str);
		//printf("%s, %d, %d\n", str, result, result2);
		if (result != result2)
			return (0);
	}
	int temp = -2147483645;
	for (int i = 0; i < 10; ++i) {
		sprintf(str, "%d", temp - i);
		result = ft_atoi(str);
		result2 = atoi(str);
		//printf("%s, %d, %d\n", str, result, result2);
		if (result != result2)
			return (0);
	}
	sprintf(str, " 	137-41hf");
	result = ft_atoi(str);
	result2 = atoi(str);
	//printf("%s, %d, %d\n", str, result, result2);
	if (result != result2)
		return (0);
	sprintf(str, "+ef13");
	result = ft_atoi(str);
	result2 = atoi(str);
	//printf("%s, %d, %d\n", str, result, result2);
	if (result != result2)
		return (0);
	sprintf(str, "+31 13");
	result = ft_atoi(str);
	result2 = atoi(str);
	//printf("%s, %d, %d\n", str, result, result2);
	if (result != result2)
		return (0);
	sprintf(str, "++31 13");
	result = ft_atoi(str);
	result2 = atoi(str);
	//printf("%s, %d, %d\n", str, result, result2);
	if (result != result2)
		return (0);
	sprintf(str, "+-31 13");
	result = ft_atoi(str);
	result2 = atoi(str);
	//printf("%s, %d, %d\n", str, result, result2);
	if (result != result2)
		return (0);
	sprintf(str, "--31 13");
	result = ft_atoi(str);
	result2 = atoi(str);
	//printf("%s, %d, %d\n", str, result, result2);
	if (result != result2)
		return (0);
	sprintf(str, "-31 13");
	result = ft_atoi(str);
	result2 = atoi(str);
	//printf("%s, %d, %d\n", str, result, result2);
	if (result != result2)
		return (0);
	return (1);
}

int test_isalpha(void)
{
	int result;
	int result2;
	for (int i = -3; i < 260; i++) {
		result = ft_isalpha(i);
		result2 = isalpha(i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_isdigit(void)
{
	int result;
	int result2;
	for (int i = -3; i < 260; i++) {
		result = ft_isdigit(i);
		result2 = isdigit(i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_isalnum(void)
{
	int result;
	int result2;
	for (int i = -3; i < 260; i++) {
		result = ft_isalnum(i);
		result2 = isalnum(i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_isascii(void)
{
	int result;
	int result2;
	for (int i = -3; i < 260; i++) {
		result = ft_isascii(i);
		result2 = isascii(i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_isprint(void)
{
	int result;
	int result2;
	for (int i = -3; i < 260; i++) {
		result = ft_isprint(i);
		result2 = isprint(i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_toupper(void)
{
	int result;
	int result2;
	for (int i = -3; i < 260; i++) {
		result = ft_toupper(i);
		result2 = toupper(i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_tolower(void)
{
	int result;
	int result2;
	for (int i = -3; i < 260; i++) {
		result = ft_tolower(i);
		result2 = tolower(i);
		//printf("%d, %d\n", result, result2);
		if (result != result2)
			return (0);
	}
	return (1);
}

int test_calloc(void)
{
	size_t size = 10;
	char *result = ft_calloc(size, sizeof(char));
	char *result2 = calloc(size, sizeof(char));
	if (memcmp(result, result2, sizeof(char) * size) != 0)
		return (0);
	return (1);
}

int test_strdup(void)
{
	char *str = "";
	char *result = ft_strdup(str);
	char *result2 = strdup(str);
	//printf("%s, %s, %s\n", str, result, result2);
	if (strcmp(result, result2) != 0)
		return (0);
	str = "ewae fealknewn231uh";
	result = ft_strdup(str);
	result2 = strdup(str);
	//printf("%s, %s, %s\n", str, result, result2);
	if (strcmp(result, result2) != 0)
		return (0);
// strdup는 null pointer에 대한 에러처리가 없음
//	str = 0;
//	result = ft_strdup(str);
//	result2 = strdup(str);
//	if ((result == 0 && result2 == 0) ||strcmp(result, result2) != 0)
//		return (0);
	return (1);
}

int test_substr(void)
{
	char *str = "abcdef123456!@#$%";
	unsigned int start;
	size_t len;
	for (start = 0; start < 20; ++start) {
		for (len = 0; len < 20; ++len) {
			char *result = ft_substr(str, start, len);
			printf("%s\n", result);
			free(result);
		}
	}
	return (1);
}

int test_strjoin(void)
{
	char *s1 = "abcdef";
	char *s2 = "123456";
	char *result = ft_strjoin(s1, s2);
	printf("%s + %s = %s\n", s1, s2, result);
	free(result);

	s1 = "";
	s2 = "123456";
	result = ft_strjoin(s1, s2);
	printf("%s + %s = %s\n", s1, s2, result);
	free(result);

	s1 = "abcdef";
	s2 = "";
	result = ft_strjoin(s1, s2);
	printf("%s + %s = %s\n", s1, s2, result);
	free(result);

	s1 = 0;
	s2 = "123456";
	result = ft_strjoin(s1, s2);
	printf("%s + %s = %s\n", s1, s2, result);
	free(result);

	s1 = "abcdef";
	s2 = 0;
	result = ft_strjoin(s1, s2);
	printf("%s + %s = %s\n", s1, s2, result);
	free(result);

	s1 = 0;
	s2 = 0;
	result = ft_strjoin(s1, s2);
	printf("%s + %s = %s\n", s1, s2, result);
	free(result);

	return (1);
}

int test_strtrim(void)
{
	char *s1 = "abcdef";
	char *s2 = "123456";
	char *answer = "abcdef";
	char *result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	int check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);

	s1 = "";
	s2 = "123456";
	answer = "";
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);

	s1 = "abcdef";
	s2 = "";
	answer = "abcdef";
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);

	s1 = 0;
	s2 = "123456";
	answer = 0;
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = result == answer ? 0 : 1;
	free(result);
	if (check != 0)
		return (0);

	s1 = "abcdef";
	s2 = 0;
	answer = "abcdef";
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);

	s1 = 0;
	s2 = 0;
	answer = 0;
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = result == answer ? 0 : 1;
	free(result);
	if (check != 0)
		return (0);

	s1 = "16abc";
	s2 = "123456";
	answer = "abc";
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);

	s1 = "abc42";
	s2 = "123456";
	answer = "abc";
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);

	s1 = "abc42a";
	s2 = "123456";
	answer = "abc42a";
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);

	s1 = "a22abc42";
	s2 = "123456";
	answer = "a22abc";
	result = ft_strtrim(s1, s2);
	//printf("%s, %s -> %s\n", s1, s2, result);
	check = strcmp(result, answer);
	free(result);
	if (check != 0)
		return (0);
	return (1);
}

int test_split(void)
{
	char *s1 = "abcdef";
	char c = 'c';
	char **result = ft_split(s1, c);
	printf("split result = %p\n", result);
	for (int i = 0; result[i]; ++i) {
		printf("%d -> %s\n", i, result[i]);
	}
	return (1);
}

int test_itoa(void)
{
	int s = 0;
	char *answer = "0";
	char *result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (strcmp(result, answer) != 0)
		return (0);
	s = 1;
	answer = "1";
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (strcmp(result, answer) != 0)
		return (0);
	s = -1;
	answer = "-1";
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (strcmp(result, answer) != 0)
		return (0);
	s = 10;
	answer = "10";
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (strcmp(result, answer) != 0)
		return (0);
	s = -10;
	answer = "-10";
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (strcmp(result, answer) != 0)
		return (0);
	s = 100;
	answer = "100";
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (strcmp(result, answer) != 0)
		return (0);
	s = -100;
	answer = "-100";
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (strcmp(result, answer) != 0)
		return (0);
	s = INT_MAX;
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (atoi(result) != INT_MAX)
		return (0);
	s = INT_MIN;
	result = ft_itoa(s);
	printf("%d, %s\n", s, result);
	if (atoi(result) != INT_MIN)
		return (0);
	return (1);
}

char strmapi_func(unsigned int i, char c)
{
	i++;
	return (c);
}

int test_strmapi(void)
{
	char *s = "";
	char *answer = "";
	char *result = ft_strmapi(s, &strmapi_func);
	if (strcmp(result, answer) != 0)
		return (0);
	s = "abc";
	answer = "abc";
	result = ft_strmapi(s, &strmapi_func);
	if (strcmp(result, answer) != 0)
		return (0);
	s = "123";
	answer = "123";
	result = ft_strmapi(s, &strmapi_func);
	if (strcmp(result, answer) != 0)
		return (0);
	return (1);
}




char	**ft_split2(char const *s, char c);

int main(void)
{
	if (!test_substr())
		printf("%s\n", "substr error");
	if (!test_strjoin())
		printf("%s\n", "strjoin error");


//	if (!test_())
//		printf("%s\n", " error");


	if (!test_strmapi())
		printf("%s\n", "strmapi error");
	if (!test_itoa())
		printf("%s\n", "itoa error");
	if (!test_split())
		printf("%s\n", "split error");
	if (!test_strtrim())
		printf("%s\n", "strtrim error");
	if (!test_strdup())
		printf("%s\n", "strdup error");
	if (!test_calloc())
		printf("%s\n", "calloc error");
	if (!test_tolower())
		printf("%s\n", "tolower error");
	if (!test_toupper())
		printf("%s\n", "toupper error");
	if (!test_isprint())
		printf("%s\n", "isprint error");
	if (!test_isascii())
		printf("%s\n", "isascii error");
	if (!test_isalnum())
		printf("%s\n", "isalnum error");
	if (!test_isdigit())
		printf("%s\n", "isdigit error");
	if (!test_isalpha())
		printf("%s\n", "isalpha error");
	if (!test_atoi())
		printf("%s\n", "atoi error");
	if (!test_strnstr())
		printf("%s\n", "strnstr error");
	if (!test_strncmp())
		printf("%s\n", "strncmp error");
	if (!test_strrchr())
		printf("%s\n", "strrchr error");
	if (!test_strchr())
		printf("%s\n", "strchr error");
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
	if (!test_memchr())
		printf("%s\n", "memchr error");
	if (!test_memcmp())
		printf("%s\n", "memcmp error");
	if (!test_strlen())
		printf("%s\n", "strlen error");
	if (!test_strlcpy())
		printf("%s\n", "strlcpy error");
	if (!test_strlcat())
		printf("%s\n", "strlcat error");


	printf("\n");
	char **sp = ft_split("", 'z');
	char **sp2 = ft_split2("", 'z');
	printf("%p\n", sp);
	printf("%p\n", sp2);
	for (int i = 0; sp[i]; ++i) {
		printf("1 %d = [%s]\n", i, sp[i]);
		free(sp[i]);
	}
	free(sp);
	for (int i = 0; sp2[i]; ++i) {
		printf("2 %d = [%s]\n", i, sp2[i]);
		free(sp2[i]);
	}
	free(sp2);
	sp = 0;
	sp2 = 0;

	printf("\n");
	sp = ft_split("cccc", 'c');
	sp2 = ft_split2("cccc", 'c');
	printf("%p\n", sp);
	printf("%p\n", sp2);
	for (int i = 0; sp[i]; ++i) {
		printf("1 %d = [%s]\n", i, sp[i]);
		free(sp[i]);
	}
	free(sp);
	for (int i = 0; sp2[i]; ++i) {
		printf("2 %d = [%s]\n", i, sp2[i]);
		free(sp2[i]);
	}
	free(sp2);
	sp = 0;
	sp2 = 0;

	printf("\n");
	sp = ft_split(0, 'c');
	sp2 = ft_split2(0, 'c');
	printf("%p\n", sp);
	printf("%p\n", sp2);
	for (int i = 0; sp && sp[i]; ++i) {
		printf("1 %d = [%s]\n", i, sp[i]);
		free(sp[i]);
	}
	free(sp);
	for (int i = 0; sp2 && sp2[i]; ++i) {
		printf("2 %d = [%s]\n", i, sp2[i]);
		free(sp2[i]);
	}
	free(sp2);
	sp = 0;
	sp2 = 0;


	return (0);
}


#include "libft.h"
size_t	ft_strnum(char *s, char c)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			num++;
		}
		else
			i++;
	}
	return (num);
}

void	str_malloc_copy(char *s, char c, size_t num, char **res)
{
	size_t	x;
	size_t	i;
	size_t	len;

	i = 0;
	x = 0;
	while (s[i] && x < num)
	{
		len = 0;
		if (s[i] != c)
		{
			while (s[i + len] != c && s[i + len])
				len++;
			res[x] = ft_calloc(sizeof(char), len + 1);
			if (res[x] == 0)
				return ;
			ft_strlcpy(res[x], s + i, len + 1);
			x++;
		}
		i += 1 + len;
	}
}

char	**ft_split2(char const *s, char c)
{
	size_t	num;
	char	**res;

	if (s == 0)
		return (0);
	num = ft_strnum((char *)s, c);
	res = ft_calloc(sizeof(char *), num + 1);
	if (res == 0)
		return (0);
	res[num] = 0;
	str_malloc_copy((char *)s, c, num, res);
	return (res);
}
