#pragma warning(disable:4996)
#include <stdio.h>

void input_double(double*, int);
double max_double(double*, int);
double min_double(double*, int);
void output(double, double);
void myfflush();

int main()
{	
	double input[5];
	int sizeArray = sizeof(input) / sizeof(input[0]);
	double max, min;

	input_double(input, sizeArray);
	max = max_double(input, sizeArray);
	min = min_double(input, sizeArray);
	output(max, min);

	return 0;
}

void input_double(double *input, int sizeArray)
{
	int res, i;
	double temp;

	for (i = 0; i < sizeArray; i++)
	{
		printf("%d �� �� �� : ", i);
		res = scanf("%lf", &temp);

		if (getchar() != '\n' || res < 1)
		{
			printf("* ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���!\n\n");
			i -= 1;
			myfflush();
		}
		else
		{
			input[i] = temp;
		}
	}

	return;
}

double max_double(double *input, int sizeArray)
{
	double max;
	int i;

	for (i = 0; i < sizeArray; i++)
	{
		if (i == 0 || input[i] > max)
		{
			max = input[i];
		}
	}

	return max;
}
double min_double(double *input, int sizeArray)
{
	double min;
	int i;

	for (i = 0; i < sizeArray; i++)
	{
		if (i == 0 || input[i] < min)
		{
			min = input[i];
		}
	}

	return min;
}

void output(double max, double min)
{

	printf("\n���� ū �� : %.2lf\n", max);
	printf("���� ���� �� : %.2lf\n", min);

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