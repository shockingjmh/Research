#pragma warning(disable:4996)
#include <stdio.h>

double input_weight();
double input_height();
double cal_BMI(double, double);
void output(double);

int main(void) {

	double weight;
	double height;
	double bmi;

	weight = input_weight();
	height = input_height();
	bmi = cal_BMI(weight, height);
	output(bmi);

	return 0;
}

double input_weight() {

	double weight;

	printf("몸무게를 입력하세요(kg) : ");
	scanf("%lf", &weight);

	return weight;
}

double input_height() {

	double height;

	printf("키를 입력하세요(m) : ");
	scanf("%lf", &height);

	return height;
}

double cal_BMI(double weight, double height) {

	double bmi;

	bmi = weight / (height * height);

	return bmi;
}

void output(double bmi) {

	if (bmi < 18.5) {
		printf("당신의 BMI는 %.1lf으로 저체중입니다.\n", bmi);
	}
	else if (bmi < 25.0){
		printf("당신의 BMI는 %.1lf으로 정상체중입니다.\n", bmi);
	}
	else if (bmi < 30.0) {
		printf("당신의 BMI는 %.1lf으로 과체중입니다.\n", bmi);
	}
	else if (bmi < 40.0) {
		printf("당신의 BMI는 %.1lf으로 비만입니다.\n", bmi);
	}
	else {
		printf("당신의 BMI는 %.1lf으로 고도비만입니다.\n", bmi);
	}

	return;
}

