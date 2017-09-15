#include <stdio.h>
#include <stdlib.h>

void print_age(int);
void print_height(int);

int main(void) {

	int my_age = 26;
	int my_height = 172;

	printf("성명: 전민호\n");

	print_age(my_age);
	print_height(my_height);

	system("pause");

	return 0;
}

void print_age(int age) {

	printf("나이: %d\n", age);

	return;
}

void print_height(int height) {

	printf("키: %d\n", height);

	return;
}
