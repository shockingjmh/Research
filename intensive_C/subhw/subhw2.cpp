#include <stdio.h>

int main(void) {

	double minimumCharge = 660;
	double chargePerKw = 88.5;
	double tax;
	double wholeCharge;
	double finalCharge;
	double usingRate;

	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%lf", &usingRate);

	wholeCharge = minimumCharge + (usingRate * chargePerKw);
	tax = wholeCharge * 0.09;
	finalCharge = wholeCharge + tax;

	printf("전기 사용요금은 %.6lf 원 입니다.\n", finalCharge);

	return 0;
}