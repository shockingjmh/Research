#pragma warning(disable:4996)
#include <stdio.h>

void inputCoefficient(double*, double*, double*);
void output(double, double, double);
double inputCoefficientNum(char* str);
void myfflush();


int main()
{
	double a = 0;
	double b = 0;
	double c = 0;

	inputCoefficient(&a, &b, &c);
	output(a, b, c);

	return 0;
}

void inputCoefficient(double* a, double* b, double* c)
{

	*a = inputCoefficientNum("a : ");
	*b = inputCoefficientNum("b : ");
	*c = inputCoefficientNum("c : ");

	return;
}

void output(double a, double b, double c)
{
	double y = 0;
	int i;
	
	printf("\n");

	for (i = 1; i <= 20; ++i)
	{

		y = (a *i*i) + (b*i) + c;
		printf("x = %-2d     =>     y = %.2lf\n", i, y);

	}

	return;
}

double inputCoefficientNum(char* str)
{
	double inputDouble;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%lf", &inputDouble);
		if (getchar() != '\n' || res == 0)
		{
			printf("문자를 입력했습니다. 숫자만 입력해주세요!\n\n");
			myfflush();
		}
		else
		{
			break;
		}
	}

	return inputDouble;
}

void myfflush() {

	while (getchar() != '\n')
	{
		;
	}

	return;
}