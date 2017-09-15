#include <stdio.h>
#include <string.h>

int main(void) {

	char name[100] = " ";
	int fieldWidth = 0;

	printf("이름을 입력하시오 : ");
	scanf("%s", name);

	fieldWidth = (1.5)*strlen(name);

	printf("\"%s\"\n", name);
	printf("\"%*s\"\n", fieldWidth,name);
	printf("\"%-*s\"\n", fieldWidth,name);
	
	return 0;
}