#include <stdio.h>

int main(void) {

	double minimumCharge = 660;
	double chargePerKw = 88.5;
	double tax;
	double wholeCharge;
	double finalCharge;
	double usingRate;

	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf("%lf", &usingRate);

	wholeCharge = minimumCharge + (usingRate * chargePerKw);
	tax = wholeCharge * 0.09;
	finalCharge = wholeCharge + tax;

	printf("���� ������� %.6lf �� �Դϴ�.\n", finalCharge);

	return 0;
}