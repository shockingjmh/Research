#include <stdio.h>

int main(void) {

	int inputUnit;
	int tempUnit;
	int mUnit;
	int cmUnit;

	printf("cm단위로 입력하세요 : ");
	scanf("%d", &tempUnit);

	inputUnit = tempUnit;
	mUnit = tempUnit / 100;
	cmUnit = tempUnit - (mUnit * 100);

	printf("%dcm => %dM %dcm\n", inputUnit, mUnit, cmUnit);

	return 0;
}