#include <stdio.h>

int main(void) {

	int historyScore;
	int literatureScore;
	int entertainmentScore;
	int totalScore;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &historyScore, &literatureScore, &entertainmentScore);

	totalScore = historyScore + literatureScore + entertainmentScore;

	printf("총점은 %d이고 평균은 %.6lf 입니다.\n", totalScore, ((double)totalScore)/3);

	return 0;
}