#include <stdio.h>

int main(void) {

	int historyScore;
	int literatureScore;
	int entertainmentScore;
	int totalScore;

	printf("����, ����, ���� ������ �Է��ϼ��� : ");
	scanf("%d %d %d", &historyScore, &literatureScore, &entertainmentScore);

	totalScore = historyScore + literatureScore + entertainmentScore;

	printf("������ %d�̰� ����� %.6lf �Դϴ�.\n", totalScore, ((double)totalScore)/3);

	return 0;
}