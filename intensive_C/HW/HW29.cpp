#pragma warning(disable:4996)
#include <stdio.h>

int inputDateNum(int*, int*, int*);
int checkDate(int*, int*, int*, int);
int calcTotalDays(int, int, int);
void output(int, int, int, int);
int leapYearCheck(int);

int main()
{
	int year = 0;
	int month = 0;
	int day = 0;
	int exit = 0;
	int totalDays = 0;

	while (1)
	{
		exit = inputDateNum(&year, &month, &day);
		if (exit == -1)
		{
			break;
		}
		totalDays = calcTotalDays(year, month, day);
		output(year, month, day, totalDays);
	}

	return 0;
}

int inputDateNum(int* year, int* month, int* day)
{
	
	int res;
	int check = 0;

	while (1)
	{
		printf("* ������� �Է��Ͻÿ� : ");

		res = scanf("%d %d %d", year, month, day);
		check = checkDate(year, month, day, res);

		if (check == 0 || check == -1)//����� �Է� 0, ���� �Է� -1
		{
			break;
		}		
	}

	return check;
}

int checkDate(int* year, int* month, int* day, int res)
{
	int check = 0;
	int leapYear;
	char what;

	if ((what = getchar()) != '\n' || res < 3)
	{
		check = -1;//���α׷� ����
		printf("���ڰ� �ԷµǾ����ϴ�. �����մϴ�!\n\n");
	}
	else if ((*year < 1) || (*month < 1 || *month > 12) || (*day < 1 || *day > 31))
	{
		check = 1;//���Է� �䱸
		printf("�ùٸ� �������� �Է����ּ���!\n\n");
	}
	else
	{
		if (*month == 2 && *day == 29)
		{
			leapYear = leapYearCheck(*year);
			if (leapYear != 0)
			{
				check = 1;//���Է� �䱸
				printf("%d���� ����Դϴ�. �׷��� 2���� 28�ϱ����� �ֽ��ϴ�. �ٽ� �Է����ּ���\n\n", *year);
			}
		}
		else if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
		{
			if (*day > 30)
			{
				check = 1;//���Է� �䱸
				printf("%d���� 30�ϱ����� �ֽ��ϴ�. �ٽ� �Է����ּ���.\n\n", *month);
			}
		}
	}

	return check;
}
int calcTotalDays(int year, int month, int day)
{
	int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int totalDays = 0;
	int i;

	for (i = 1; i < year; i++)
	{
		if (leapYearCheck(i) == 1)//����̶��
		{
			totalDays += 365;
		}
		else//�����̶��
		{
			totalDays += 366;
		}
	}

	for (i = 1; i < month; i++)
	{
		totalDays += monthDay[i];
	}

	totalDays += day;

	if (leapYearCheck(year) == 0 && month > 2)//���⿡ 3���� �̻��̶�� �Ϸ� �߰�
	{
		totalDays += 1;
	}

	return totalDays;
}
void output(int year, int month, int day, int totalDays)
{
	char dayName[7][3] = {"��", "��", "ȭ", "��", "��", "��", "��"};

	printf("%d�� %d�� %d���� %s���� �Դϴ�.\n\n", year, month, day, dayName[totalDays%7]);

	return;
}

int leapYearCheck(int inputYear) {

	int leapYear;

	if (inputYear % 4 != 0) {
		leapYear = 1;//1�� ���
	}
	else if (inputYear % 100 != 0) {
		leapYear = 0;//0�� ����
	}
	else if (inputYear % 400 != 0) {
		leapYear = 1;//1�� ���
	}
	else 
	{
		leapYear = 0;//1�� ����
	}

	return leapYear;
}