#include <stdio.h>

int main(void) {

	double distance;
	double perHour;
	double currentDistance;
	int hour;
	int minute;
	double second;

	printf("* 거리를 입력하시오(km단위) : ");
	scanf("%lf", &distance);

	printf("* 시속을 입력하시오(km/h) : ");
	scanf("%lf", &perHour);

	hour = distance / perHour;
	currentDistance = distance - (hour*perHour);

	minute = currentDistance / (perHour / 60);
	currentDistance = currentDistance - (minute*(perHour / 60));

	second = currentDistance / (perHour / 3600);
	

	printf("%.2lf km = >%d시간 %d분 %.3lf 초 소요됨\n", distance, hour, minute, second);

	return 0;
}