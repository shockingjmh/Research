#pragma warning(disable:4996)
#include <stdio.h> 
#include <windows.h> 

void inputPositionNum(char* str, int*, int*, int*, int*);
void box(int, int, int, int);
void gotoxy(int, int);
void myfflush();

int main(void)
{
	int sx, sy, ex, ey;

	sx = sy = ex = ey = 0;

	inputPositionNum("�����ϴ� x, y, ������ x, y�� ���ʴ�� �Է����ּ��� : ",&sx, &sy, &ex, &ey);
	system("cls");
	box(sx, sy, ex, ey);

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void inputPositionNum(char* str, int* sx, int* sy, int* ex, int* ey)
{
	int res;

	while (1)
	{
		printf(str);

		res = scanf("%d %d %d %d", sx, sy, ex, ey);
		if (getchar() != '\n' || res < 4)
		{
			printf("���� ������ �Է����ּ���!\n\n");
			myfflush();
		}
		else if ((*sx < 1 || *sx > 70) || (*sy < 1 || *sy > 20))
		{
			printf("�����ϴ� x �� 1<= x <=70, ���� y �� 1 <= y <= 20 ������ ���ڸ� �Է����ּ���!!\n\n");
		}
		else if (((*ex < (80 - *sx)) || (*ex > 80)) || ((*ey < (25-*sy)) || (*ey > 24)))
		{
			printf("������ x�� %d<= x <=80, y�� %d <= y <= 24 ������ ���ڸ� �Է����ּ���!!\n\n", 80 - *sx, 25 - *sy);
		}
		else
		{
			break;
		}
	}

	return;
}

void box(int sx, int sy, int ex, int ey)
{
	int i;
	int j;

	gotoxy(sx, sy);

	for (i = sy; i < ey + 1; i++)
	{
		for (j = sx; j < ex + 1; j++)
		{
			if (i == sy || i == ey)
			{
				gotoxy(j, i);
				printf("*");
			}
			else
			{
				if ((j == sx) || (j == ex))
				{
					gotoxy(j, i);
					printf("*");
				}
			}
		}
	}
	printf("\n");

	return;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}
}