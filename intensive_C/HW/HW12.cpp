#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void) {

	char str[100];
	int strLen, outLen;

	printf("���ڸ� �Է��Ͻÿ� : ");
	scanf("%s", str);

	strLen = strlen(str);
	outLen = strLen / 2;

	printf("[%*.*s...]", strLen, outLen, str);

	return 0;
}