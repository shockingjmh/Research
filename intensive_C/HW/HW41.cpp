#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

unsigned int ustrlen(char*);
void ustrcpy(char*, char*);
int ustrcmp(char*, char*);

int main()
{
	char str[10];
	char chr[20] = "Dream";
	unsigned int len;
	int res;

	len = ustrlen(chr);
	printf("%s 의 길이 : %u\n\n", chr, len);

	ustrcpy(str, chr);
	printf("str의 내용 : %s\n\n", str);
	
	res = ustrcmp(str, "Drama");
	
	if (res > 0)
	{
		printf("%s가 %s보다 큰값을 가진다.\n\n", str, "Drama");
	}
	else if (res == 0)
	{
		printf("%s는 %s과 같은 값을 가진다\n\n", str, "Drama");
	}
	else
	{
		printf("%s가 %s보다 더 작은 값을 가진다.\n\n", str, "Drama");
	}
	
	return 0;
}

unsigned int ustrlen(char *p)
{
	unsigned int len;
	int i = 0;

	while (1)
	{
		if (p[i] == '\0') //널문자 전에 까지의 길이를 구해야 하므로 널문자를 만나면 0부터 시작했으므로 인덱스로 봤을때는 그 길이가 문자열의 길이
		{
			len = (unsigned)i;
			break;
		}
		i++;
	}

	return len;
}

void ustrcpy(char *s1, char *s2)
{
	int i = 0;

	while (1)
	{
		if (*(s2+i) == '\0')//s2의 널문자가 나올 때까지 진행
		{
			*(s1 + i) = '\0';//s2에서 널문자가 나온 자리와 똑같은 s1의 자리에 널문자 삽입하고 종료
			break;
		}
		*(s1 + i) = *(s2 + i);

		i++;
	}

	return;
}

int ustrcmp(char *s1, char *s2)
{
	int res;
	int i = 0;

	while (1)
	{
		if (*(s1 + i) != *(s2 + i) || (*(s1 + i) == 0  && *(s2 + i) == 0))// s1과 s2의 값이 다르거나 아니면 s1과 s2가 모두 널문자를 만나면 값들의 차를 리턴
		{
			res = *(s1 + i) - *(s2 + i);
			break;
		}
		i++;
	}

	return res;
}