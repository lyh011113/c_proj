#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



// fgets(), fputs()
// file get string(), flie put string()
// ���δ����� �д´�


int main(void) {

	FILE* p = fopen("data.txt", "r");

	if (p == NULL) {
		printf("file open error!");
		return;
	}

	char readLine[200];

	//fgetc(����� ���� (������), ������ ũ��, ���� ������(��Ʈ��))
	/*
	�� ���ξ� �д´�
	fgets(readLine, sizeof(readLine), p);
	printf("%s", readLine);*/

	// Ŀ���� ���ϳ�(EOF - End Of File)�� �����ϸ� feof()�Լ��� '��'�� �����Ѵ�.

	while (!feof(p)) {
		fgets(readLine, sizeof(readLine), p);
		printf("%s", readLine);
	}

	fclose(p);


	FILE* wp = fopen("data.txt", "a");

	//fput(����, ����������-��Ʈ��)
	fputs("TEST�Դϴ�", wp);
	fclose(wp);

	return 0;
}