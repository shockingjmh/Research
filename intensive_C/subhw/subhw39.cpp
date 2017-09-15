#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH 13

int availability_check(char *resident_number);
int length_character_check(char *resident_number);
int date_check(char *resident_number);
int identification_check(char *resident_number);
int gender_check(char *resident_number);
int year_check(int year);

int main()
{
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179", "0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219", "8100122042213", "8112002042213", "9210101069415", "0802294012345", "8806311069417", "8807311069418" };
	int i, count;

	count = sizeof(resident_number) / sizeof(resident_number[0]);
	for (i = 0; i < count; i++)
	{
		if (availability_check(resident_number[i]) == TRUE)
		{
			printf("(+) 주민번호 %s 는(은) 유효한 번호입니다.\n", resident_number[i]);
		}
		else
		{
			printf("(-) 주민번호 %s 는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
		}
	}

	return 0;
}

int availability_check(char *resident_number)
{
	if (length_character_check(resident_number))//길이 및 숫자문자 유효성 검사
	{
		if (date_check(resident_number))//날짜 검사
		{
			if (identification_check(resident_number))//인식자 오류체크
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}

int length_character_check(char *resident_number)
{
	int lengthCount = 0;
	int result = FALSE;

	while (1)
	{
		if (lengthCount == RESIDENT_NUMBER_LENGTH && resident_number[lengthCount] == '\0')
		{
			result = TRUE;
			break;
		}
		else if (lengthCount < RESIDENT_NUMBER_LENGTH)
		{
			if (resident_number[lengthCount] < '0' || resident_number[lengthCount] > '9')
			{
				result = FALSE;
				break;
			}
		}
		else
		{
			break;
		}
		lengthCount++;
	}

	return result;
}
int date_check(char *resident_number)
{
	int dayList[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int result = FALSE;
	int year = 0;
	int month = 0;
	int day = 0;

	if (gender_check(resident_number) == TRUE)
	{
		if (resident_number[6] == '1' || resident_number[6] == '2')
		{
			year += 1900;
			year += ((resident_number[0] - '0') * 10);
			year += (resident_number[1] - '0');

			month += ((resident_number[2] - '0') * 10);
			month += (resident_number[3] - '0');

			day += ((resident_number[4] - '0') * 10);
			day += (resident_number[5] - '0');

			if (month == 2)//2월일 경우
			{
				if (year_check(year) == 0 && (day > 0 && day <= dayList[month - 1]))
				{
					result = TRUE;
				}
				else if (year_check(year) == 1 && (day > 0 && day <= 29))
				{
					result = TRUE;
				}
			}
			else// 2월 이외 경우
			{
				if (day > 0 && day <= dayList[month - 1])
				{
					result = TRUE;
				}
			}

		}
		else
		{
			year += 2000;
			year += ((resident_number[0] - '0') * 10);
			year += (resident_number[1] - '0');

			month += ((resident_number[2] - '0') * 10);
			month += (resident_number[3] - '0');

			day += ((resident_number[4] - '0') * 10);
			day += (resident_number[5] - '0');

			if (month == 2)//2월일 경우
			{
				if (year_check(year) == 0 && day <= dayList[month - 1])
				{
					result = TRUE;
				}
				else if (year_check(year) == 1 && day <= 29)
				{
					result = TRUE;
				}
			}
			else// 2월 이외 경우
			{
				if (day <= dayList[month - 1])
				{
					result = TRUE;
				}
			}
		}
	}

	return result;
}

int identification_check(char *resident_number)
{
	int i;
	int sum = 0;
	int result = FALSE;

	for (i = 0; i < RESIDENT_NUMBER_LENGTH - 1; i++)
	{
		sum += (resident_number[i] - '0');
	}

	if ((sum % 10) == resident_number[RESIDENT_NUMBER_LENGTH - 1] - '0')
	{
		result = TRUE;
	}

	return result;
}

int gender_check(char *resident_number)
{
	int result = FALSE;

	if (resident_number[6] - '0' > 0 && resident_number[6] - '0' < 5)
	{
		result = TRUE;
	}

	return result;
}

int year_check(int year)
{
	int result;

	if (year % 4 != 0)
	{
		result = 0;//평년
	}
	else if (year % 100 != 0)
	{
		result = 1;//윤년
	}
	else if (year % 400 != 0)
	{
		result = 0;//평년
	}
	else
	{
		result = 1;//윤년
	}

	return result;
}