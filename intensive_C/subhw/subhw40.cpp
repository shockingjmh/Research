#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SWAP(x, y) {int t; t=x; x=y; y=t;}

int menu();
int inputIntNum(char*, int);
void personalPractice();
void computerBattle();
int playGame(int**, int**, int, int);
void computerGame(int**, int**, int);
int checkBingo(int**, int);
void makeRandomNumber(int**, int**, int);
void output(int**, int);
void outputComputer(int**, int**, int);
void myFree(int**, int**, int);
void myfflush();


int main()
{
	srand((unsigned int)time(NULL));
	int menuNum;

	void(*fptr[2])() = { personalPractice, computerBattle };

	while (1)
	{
		menuNum = menu();

		if (menuNum < 3)
		{
			fptr[menuNum - 1]();
		}
		else
		{

			break;
		}
	}

	return 0;
}

int menu()
{
	int menuNum = 0;

	while (1)
	{
		printf("1. 연습게임(개인 연습용)\n");
		printf("2. 대전게임(컴퓨터와 대전용)\n");
		printf("3. 종료\n\n");

		menuNum = inputIntNum("# 메뉴선택 : ", menuNum);
		if (menuNum < 0 || menuNum > 3)
		{
			printf("1 ~ 3 중 하나만 선택해주세요!\n\n");
		}
		else
		{
			break;
		}
	}

	return menuNum;
}

int inputIntNum(char *str, int cnt)
{
	int number;
	int res;

	while (1)
	{
		printf(str, cnt);
		res = scanf("%d", &number);

		if (getchar() != '\n' || res < 1)
		{
			myfflush();
			number = -1;
			break;
		}
		else if (number <= 0)
		{
			number = -1;
			break;
		}
		else
		{
			break;
		}
	}

	return number;
}

void myfflush()
{
	while (getchar() != '\n')
	{
		;
	}

	return;
}

void personalPractice()
{
	int **panel = 0;
	int **backPanel = 0;//중복 선택을 확인하기 위한 2차원 변수
	int bingoSize;
	int inputNum;
	int selectNum;
	int bingoCount = 0;
	int i;

	bingoSize = inputIntNum("# 빙고판의 가로, 세로 크기를 입력해주세요(양수값 입력) : ", bingoCount);

	panel = (int**)malloc(sizeof(int*)*bingoSize);
	backPanel = (int**)malloc(sizeof(int*)*bingoSize);
	assert(panel != NULL);
	assert(backPanel != NULL);
	for (i = 0; i < bingoSize; i++)
	{
		*(panel + i) = (int*)malloc(sizeof(int)*bingoSize);
		*(backPanel + i) = (int*)malloc(sizeof(int)*bingoSize);
		assert(*(panel + i) != NULL);
		assert(*(backPanel + i) != NULL);
	}

	makeRandomNumber(panel, backPanel, bingoSize);

	while (1)
	{
		output(panel, bingoSize);
		while (1)
		{
			inputNum = inputIntNum("\n# 지울 숫자 입력(1~%d) : ", bingoSize*bingoSize);
			if (inputNum > bingoSize*bingoSize || inputNum == -1)
			{
				printf("* 1 ~ %d사이의 숫자만 입력해주세요!\n\n", bingoSize*bingoSize);
			}
			else
			{
				selectNum = playGame(panel, backPanel, bingoSize, inputNum);

				if (selectNum == -1)
				{
					printf("* 이미 지워진 숫자입니다. 다시 입력하세요.\n\n");
				}
				else
				{
					bingoCount = checkBingo(panel, bingoSize);

					if (bingoCount >= bingoSize)
					{
						output(panel, bingoSize);
						printf("빙고게임이 끝났습니다. 주메뉴로 돌아갑니다.\n\n");
					}
				}
				break;
			}
		}
		if (bingoCount >= bingoSize)
		{
			break;
		}
	}

	myFree(panel, backPanel, bingoSize);

	return;
}

void computerBattle()
{
	int **panel = 0;
	int **backPanel = 0;//중복 선택을 확인하기 위한 2차원 변수
	int **panelComputer = 0;
	int **backPanelComputer = 0;
	int bingoSize;
	int inputNum;
	int selectNum;
	int bingoCount = 0;
	int bingoCountComputer = 0;
	int i;

	bingoSize = inputIntNum("# 빙고판의 가로, 세로 크기를 입력해주세요(양수값 입력) : ", bingoCount);

	panel = (int**)malloc(sizeof(int*)*bingoSize);
	backPanel = (int**)malloc(sizeof(int*)*bingoSize);
	panelComputer = (int**)malloc(sizeof(int*)*bingoSize);
	backPanelComputer = (int**)malloc(sizeof(int*)*bingoSize);
	assert(panel != NULL);
	assert(backPanel != NULL);
	assert(panelComputer != NULL);
	assert(backPanelComputer != NULL);
	for (i = 0; i < bingoSize; i++)
	{
		*(panel + i) = (int*)malloc(sizeof(int)*bingoSize);
		*(backPanel + i) = (int*)malloc(sizeof(int)*bingoSize);
		*(panelComputer + i) = (int*)malloc(sizeof(int)*bingoSize);
		*(backPanelComputer + i) = (int*)malloc(sizeof(int)*bingoSize);
		assert(*(panel + i) != NULL);
		assert(*(backPanel + i) != NULL);
		assert(*(panelComputer + i) != NULL);
		assert(*(backPanelComputer + i) != NULL);
	}

	printf("\n사용자 빙고게임판 내용을 생성중입니다.\n");
	makeRandomNumber(panel, backPanel, bingoSize);
	printf("컴퓨터 빙고판 내용을 생성중 입니다.\n\n");
	makeRandomNumber(panelComputer, backPanelComputer, bingoSize);

	while (1)
	{
		outputComputer(panel, panelComputer, bingoSize);
		while (1)
		{
			inputNum = inputIntNum("\n# 지울 숫자 입력(1~%d) : ", bingoSize*bingoSize);
			if (inputNum > bingoSize*bingoSize || inputNum == -1)
			{
				printf("* 1 ~ %d사이의 숫자만 입력해주세요!\n\n", bingoSize*bingoSize);
			}
			else
			{
				selectNum = playGame(panel, backPanel, bingoSize, inputNum);

				if (selectNum == -1)
				{
					printf("* 이미 지워진 숫자입니다. 다시 입력하세요.\n\n");
				}
				else
				{
					computerGame(panelComputer, backPanel, bingoSize);//사용자가 이미 지워진 숫자가 아닐 때 컴퓨터 게임 진행

					bingoCount = checkBingo(panel, bingoSize);
					bingoCountComputer = checkBingo(panelComputer, bingoSize);

					if (bingoCount >= bingoSize || bingoCountComputer >= bingoSize)
					{
						outputComputer(panel, panelComputer, bingoSize);
						if (bingoCount > bingoCountComputer)
						{
							printf("# 사용자 승!\n\n");
						}
						else if (bingoCount < bingoCountComputer)
						{
							printf("# 컴퓨터 승!\n\n");
						}
						else
						{
							printf("# 사용자, 컴퓨터 무승부!\n\n");
						}
					}
				}
				break;
			}
		}
		if (bingoCount >= bingoSize || bingoCountComputer >= bingoSize)
		{
			break;
		}
	}

	myFree(panel, backPanel, bingoSize);
	myFree(panelComputer, backPanelComputer, bingoSize);

	return;
}


int playGame(int **panel, int **backPanel, int cnt, int inputNum)
{
	int result = 0;
	int i, j;

	for (i = 0; i < cnt; i++)
	{
		for (j = 0; j < cnt; j++)
		{
			if (inputNum == *(*(backPanel + i) + j))
			{
				if (*(*(panel + i) + j) == 0)
				{
					result = -1;
					break;
				}
				else
				{
					*(*(panel + i) + j) = 0;
					break;
				}
			}
		}
		if (*(*(panel + i) + j) == 0 || result == -1) break;
	}

	return result;
}

void computerGame(int **panelComputer, int **backPanelComputer, int cnt)
{
	int result = 0;
	int flag;
	int i, j;

	while (1)
	{
		flag = 0;
		result = rand() % (cnt*cnt) + 1;

		for (i = 0; i < cnt; i++)
		{
			for (j = 0; j < cnt; j++)
			{
				if (result == *(*(backPanelComputer + i) + j))
				{
					if (*(*(panelComputer + i) + j) == 0)
					{
						flag = -1;
						break;
					}
					else
					{
						*(*(panelComputer + i) + j) = 0;
						break;
					}
				}
			}
			if (flag == -1) break;
		}

		if (flag == 0)break;
	}

	printf("\n# 컴퓨터가 선택한 숫자는 (%d)입니다.\n\n", result);

	return;
}


int checkBingo(int **panel, int cnt)
{
	int countRow = 0;
	int countCol = 0;
	int countDia = 0;
	int countReverseDia = 0;
	int sumOfLine = 0;
	int i, j;

	for (i = 0; i < cnt; i++)
	{
		for (j = 0; j < cnt; j++)
		{
			if (*(*(panel + i) + j) == 0)
			{
				countRow++;
			}
			if (*(*(panel + j) + i) == 0)
			{
				countCol++;
			}
		}
		if (countRow == cnt)
		{
			sumOfLine += 1;
		}
		if (countCol == cnt)
		{
			sumOfLine += 1;
		}
		countRow = 0;
		countCol = 0;
	}

	for (i = 0; i < cnt; i++)
	{
		if (*(*(panel + i) + i) == 0)
		{
			countDia++;
		}
		if (*(*(panel + cnt-(i+1)) + i) == 0)
		{
			countReverseDia++;
		}
	}

	if (countDia == cnt)
	{
		sumOfLine += 1;
	}
	if (countReverseDia == cnt)
	{
		sumOfLine += 1;
	}

	return sumOfLine;
}


void makeRandomNumber(int **panel, int **backPanel, int cnt)
{
	int *randNum;
	int i, j;

	randNum = (int*)malloc(sizeof(int)*cnt*cnt);
	assert(randNum != NULL);

	for (i = 0; i < cnt*cnt; i++)
	{
		*(randNum + i) = i + 1;
	}

	for (i = 0; i < cnt*cnt; i++)
	{
		j = rand() % cnt*cnt;

		SWAP(*(randNum + j), *(randNum + i));
	}

	for (i = 0; i < cnt; i++)
	{
		for (j = 0; j < cnt; j++)
		{
			*(*(panel + i) + j) = *(randNum + i * cnt + j);
			*(*(backPanel + i) + j) = *(randNum + i * cnt + j);
		}
	}

	return;
}

void output(int **panel, int cnt)
{
	int i, j;

	printf("\n");
	for (i = 0; i < cnt; i++)
	{
		printf("| ");
		for (j = 0; j < cnt; j++)
		{
			if (*(*(panel + i) + j) == 0)
			{
				printf(" X ");
			}
			else
			{
				printf("%2d ", *(*(panel + i) + j));
			}
		}
		printf("|\n");
	}
	printf("\n");
	
	return;
}

void outputComputer(int **panel, int **panelComputer, int cnt)
{
	int i, j;

	for (i = 0; i < cnt; i++)
	{
		printf(" ");
	}
	printf("%*s", cnt, "[user]");

	for (i = 0; i < cnt; i++)
	{
		if (i % 2 == 0)
		{
			printf("  ");
		}
		else
		{
			printf("   ");
		}
	}
	printf("\t%*s\n", cnt*2, "[computer]");

	for (i = 0; i < cnt; i++)
	{
		printf("| ");
		for (j = 0; j < cnt; j++)
		{
			if (*(*(panel + i) + j) == 0)
			{
				printf(" X ");
			}
			else
			{
				printf("%2d ", *(*(panel + i) + j));
			}
		}
		printf("|\t");

		printf("| ");
		for (j = 0; j < cnt; j++)
		{
			if (*(*(panelComputer + i) + j) == 0)
			{
				printf(" X ");
			}
			else
			{
				printf(" ? ");
			}
		}
		printf("|\n");
	}
	printf("\n");

	return;
}

void myFree(int **panel, int **backPanel, int cnt)
{
	int i;

	for (i = 0; i < cnt; i++)
	{
		free(*(panel + i));
		free(*(backPanel + i));
	}
	free(panel);
	free(backPanel);

	return;
}
