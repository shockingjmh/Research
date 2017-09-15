#include <stdio.h>

int main(void) {

	int inputNumber;

	printf("정수값을 입력하세요 : ");
	scanf("%d", &inputNumber);

	printf("입력된 값은 8진수로 %#o 입니다.\n", inputNumber);
	printf("입력된 값은 16진수로 %#x 입니다.\n", inputNumber);

	return 0;
}