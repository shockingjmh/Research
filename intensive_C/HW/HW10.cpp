#include <stdio.h>
#include <string.h>

int main(void) {

	char name[100] = " ";
	int fieldWidth = 0;

	printf("�̸��� �Է��Ͻÿ� : ");
	scanf("%s", name);

	fieldWidth = (1.5)*strlen(name);

	printf("\"%s\"\n", name);
	printf("\"%*s\"\n", fieldWidth,name);
	printf("\"%-*s\"\n", fieldWidth,name);
	
	return 0;
}