#include <stdio.h>

int main(void) {

	int inputUnit;
	int tempUnit;
	int mUnit;
	int cmUnit;

	printf("cm������ �Է��ϼ��� : ");
	scanf("%d", &tempUnit);

	inputUnit = tempUnit;
	mUnit = tempUnit / 100;
	cmUnit = tempUnit - (mUnit * 100);

	printf("%dcm => %dM %dcm\n", inputUnit, mUnit, cmUnit);

	return 0;
}