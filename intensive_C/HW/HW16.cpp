#pragma warning(disable:4996)
#include <stdio.h>

int input(char*);
int calcDays(int);
void output(int, int);

int main()
{
	int wellDepth;
	int daysForEscape;

	while (1)
	{
		wellDepth = input("* �칰�� ���̸� �Է��Ͻÿ�(cm ����) : ");
		if (wellDepth == -999)
		{
			break;
		}
		else
		{
			daysForEscape = calcDays(wellDepth);
			output(wellDepth, daysForEscape);
		}
		
	}

	return 0;
}

int input(char *str) 
{
	int wellDepth = 0;
	int res;

	while (1)
	{
		printf(str);
		res = scanf("%d", &wellDepth);
		if (getchar() != '\n' || res == 0)
		{
			printf("���ڸ� �Է��߽��ϴ�. ���α׷��� �����մϴ�.\n\n");
			wellDepth = -999;
			break;	
		}
		else if (wellDepth < 0)
		{
			printf("����� �Է����ּ���!\n\n");
		}
		else
		{
			
			break;
		}
	}

	return wellDepth;
}

int calcDays(int wellDepth)
{
	int climbingDistance = 0;
	int climbingDays = 0;;

	while (1)
	{
		if (wellDepth == 0)
		{
			break;
		}
		else
		{
			climbingDistance += 50;
			climbingDays += 1;
			if (climbingDistance >= wellDepth)
			{
				break;
			}
			climbingDistance -= 20;
		}
	}

	return climbingDays;
}

void output(int wellDepth, int daysForEscape)
{
	printf("�칰���� %.2lfm : %d��\n", wellDepth / 100.0, daysForEscape);
}