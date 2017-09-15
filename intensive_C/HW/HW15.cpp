#pragma warning(disable:4996)
#include <stdio.h>

int input(char*);
double totalIncome(int);
double calcTax(double);
void output(int, double, double);
void myfflush();

int main()
{
	int workingHour;
	double grossIncome, tax;

	workingHour = input("1주일간의 근무시간을 입력하시오 : ");
	grossIncome = totalIncome(workingHour);
	tax = calcTax(grossIncome);
	output(workingHour, grossIncome, tax);
	
	return 0;
}

int input(char *str)
{
	int workingHour;
	while (1)
	{
		printf(str);
		if (scanf("%d", &workingHour) == 1 && getchar() == '\n')
		{
				break;
		}
		else
		{
			printf("정수만 입력해주세요!\n");
			myfflush();
		}
	}

	return workingHour;
}

double totalIncome(int workingHour)
{
	double fixedIncome, overIncome, result;

	if (workingHour > 40)
	{
		fixedIncome = 40 * 3000;
		overIncome = (workingHour - 40) * 3000 * 1.5;
	}
	else
	{
		fixedIncome = workingHour * 3000;
		overIncome = 0;
	}

	result = fixedIncome + overIncome;

	return result;
}

double calcTax(double grossIncome)
{
	double fixedTax, overTax, result;

	if (grossIncome > 100000)
	{
		fixedTax = 100000 * 0.15;
		overTax = (grossIncome - 100000)*0.25;
		
	}
	else
	{
		fixedTax = 100000 * 0.15;
		overTax = 0;
	}

	result = fixedTax + overTax;

	return result;
}

void output(int workingHour, double grossIncome, double tax)
{
	if (workingHour < 0){
		return;
	}
	else
	{
		printf("근무시간 %d 시간 : 총수입 %d, 세금 %d, 실수입 %d\n", workingHour, (int)grossIncome, (int)tax, (int)(grossIncome - tax));
	}

	return;
}

void myfflush() 
{

	while (getchar() != '\n')
	{
		;
	}

	return;
}