#include <stdio.h>

int main(void) {

	double distance;
	double perHour;
	double currentDistance;
	int hour;
	int minute;
	double second;

	printf("* �Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf("%lf", &distance);

	printf("* �ü��� �Է��Ͻÿ�(km/h) : ");
	scanf("%lf", &perHour);

	hour = distance / perHour;
	currentDistance = distance - (hour*perHour);

	minute = currentDistance / (perHour / 60);
	currentDistance = currentDistance - (minute*(perHour / 60));

	second = currentDistance / (perHour / 3600);
	

	printf("%.2lf km = >%d�ð� %d�� %.3lf �� �ҿ��\n", distance, hour, minute, second);

	return 0;
}