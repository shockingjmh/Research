#include <stdio.h>
#include <string.h>

int main(void) {

	char lastName[20];
	char firstName[50];
	int lastNameLen;
	int firstNameLen;

	printf("# 성을 입력하시오 : ");
	scanf("%s", lastName);
	printf("# 이름을 입력하시오 : ");
	scanf("%s", firstName);

	lastNameLen = strlen(lastName);
	firstNameLen = strlen(firstName);

	printf("%s %s\n", lastName, firstName);
	printf("%*d %*d\n", lastNameLen, lastNameLen, firstNameLen, firstNameLen);

	return 0;
}