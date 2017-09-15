#pragma warning(disable:4996)
#include <stdio.h>

int inputIntNum(char *);
double inputDoubleNum(char *);
int ipow(int, int);
double dpow(double, int);
void printIntPow(int, int);
void printDoublePow(double, int);
void myfflush();

int main()
{
	int iBase;
	int iExponent;
	double dBase;

	iBase = inputIntNum("������ ���� �Է��Ͻÿ� : ");
	iExponent = inputIntNum("�������� �Է��Ͻÿ�(������) : ");
	printIntPow(iBase, iExponent);

	dBase = inputDoubleNum("�Ǽ��� ���� �Է� �Ͻÿ� : ");
	iExponent = inputIntNum("�������� �Է��Ͻÿ�(������) : ");
	printDoublePow(dBase, iExponent);

	return 0;
}

int inputIntNum(char* str)
{
	int inputInt;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d", &inputInt);
		if (getchar() != '\n' || res == 0)
		{
			printf("���ڸ� �Է��߽��ϴ�. ����� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputInt < 0)
		{
			printf("����� �Է����ּ���!\n\n");
		}
		else
		{

			break;
		}
	}

	return inputInt;
}

double inputDoubleNum(char* str)
{
	double inputDouble;
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%lf", &inputDouble);
		if (getchar() != '\n' || res == 0)
		{
			printf("���ڸ� �Է��߽��ϴ�. ���� �Ǽ��� �Է����ּ���!\n\n");
			myfflush();
		}
		else if (inputDouble < 0)
		{
			printf("���� �Ǽ��� �Է����ּ���!\n\n");
		}
		else
		{

			break;
		}
	}

	return inputDouble;
}

int ipow(int iBase, int iExponent)
{
	int i = 0;
	int multipleBase = 1;

	while (i < iExponent)
	{
		if (iBase == 0)
		{
			multipleBase = 0;
			break;
		}
		else if (iExponent == 0)
		{
			multipleBase = 1;
			break;
		}

		multipleBase *= iBase;
		i += 1;
	}

	return multipleBase;
}

double dpow(double dBase, int iExponent)
{
	int i = 0;
	double multipleBase = 1;

	while (i < iExponent)
	{
		if (dBase == 0)
		{
			multipleBase = 0;
			break;
		}
		else if (iExponent == 0)
		{
			multipleBase = 1;
			break;
		}

		multipleBase *= dBase;
		i += 1;
	}

	return multipleBase;
}

void printIntPow(int iBase, int iExponent)
{

	printf("%d�� %d���� %d�Դϴ�.\n\n", iBase, iExponent, ipow(iBase, iExponent));

	return;
}

void printDoublePow(double dBase, int iExponent)
{

	printf("%.1lf�� %d���� %.2lf�Դϴ�.\n", dBase, iExponent, dpow(dBase, iExponent));

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