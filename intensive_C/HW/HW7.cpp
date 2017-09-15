#include <stdio.h>

int main(void) {

	int inputNumber;

	printf("한 개의 정수를 입력하시오 : ");
	scanf("%d", &inputNumber);

	printf("%d의 2배수 => %d\n", inputNumber, inputNumber * 2);
	printf("%d의 제곱 => %d\n", inputNumber, inputNumber * inputNumber);

	return 0;
}