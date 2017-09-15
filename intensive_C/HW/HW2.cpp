#include <stdio.h>
#include <stdlib.h>

int main(void){

	int money = 278970;
	int m10000, m5000, m1000, m500, m100, m50, m10;

	m10000 = money/10000;
	money = money - (m10000 * 10000);

	m5000 = money/5000;
	money = money - (m5000 * 5000);

	m1000 = money/1000;
	money = money - (m1000 * 1000);

	m500 = money/500;
	money = money - (m500 * 500);

	m100 = money/100;
	money = money - (m100 * 100);

	m50 = money/50;
	money = money - (m50 * 50);

	m10 = money / 10;
	money = money - (m10 * 10);

	printf("10000원권 => %d\n", m10000);
	printf("5000원권 => %d\n", m5000);
	printf("1000원권 => %d\n", m1000);
	printf("500원권 => %d\n", m500);
	printf("100원권 => %d\n", m100);
	printf("50원권 => %d\n", m50);
	printf("10원권 => %d\n", m10);

	system("pause");

	return 0;
}