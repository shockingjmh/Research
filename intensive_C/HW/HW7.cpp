#include <stdio.h>

int main(void) {

	int inputNumber;

	printf("�� ���� ������ �Է��Ͻÿ� : ");
	scanf("%d", &inputNumber);

	printf("%d�� 2��� => %d\n", inputNumber, inputNumber * 2);
	printf("%d�� ���� => %d\n", inputNumber, inputNumber * inputNumber);

	return 0;
}