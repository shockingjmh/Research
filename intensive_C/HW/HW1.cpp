#include <stdio.h>
#include <stdlib.h>

void print_age(int);
void print_height(int);

int main(void) {

	int my_age = 26;
	int my_height = 172;

	printf("����: ����ȣ\n");

	print_age(my_age);
	print_height(my_height);

	system("pause");

	return 0;
}

void print_age(int age) {

	printf("����: %d\n", age);

	return;
}

void print_height(int height) {

	printf("Ű: %d\n", height);

	return;
}
