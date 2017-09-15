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

	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%lf", &weight);

	return weight;
}

double input_height() {

	double height;

	printf("Ű�� �Է��ϼ���(m) : ");
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
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�.\n", bmi);
	}
	else if (bmi < 25.0){
		printf("����� BMI�� %.1lf���� ����ü���Դϴ�.\n", bmi);
	}
	else if (bmi < 30.0) {
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�.\n", bmi);
	}
	else if (bmi < 40.0) {
		printf("����� BMI�� %.1lf���� ���Դϴ�.\n", bmi);
	}
	else {
		printf("����� BMI�� %.1lf���� �����Դϴ�.\n", bmi);
	}

	return;
}

