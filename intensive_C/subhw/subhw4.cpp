#include <stdio.h>

int main(void) {

	double fahrenheit;
	double celcius;

	printf("ȭ�� �µ��� �Է��ϼ��� : ");
	scanf("%lf", &fahrenheit);

	celcius = 5.0 / 9.0 * (fahrenheit - 32.0);

	printf("���� �µ��� %.1lf���Դϴ�.\n", celcius);

	return 0;
}