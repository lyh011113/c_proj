#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


// File IO (File Input / Output)
// ex) Printf - std Ouput -> ����� ��� ����? (�����) standard Output
// ex) scanf - std Input -> �Է��� ���� ����? (Ű����) Standard Input
// File IO �������
// 1. Ž���⸦ ���� -> 2. ������ ��ġ�� ã�´� -> 3. ������ ���� -> 4. ������ ���� -> 5. ������ �ݴ´�

//C���
// ���Ͽ���/�ݰ� ( 1,2 -> 5 )
// fopen(), fclose();
// fopen(" ������ ��ġ - ���� Path ", "���� ���")
// fclose (���� ������);


int main01(void) {
	
	FILE* stream;

	stream = fopen("data.txt", "a");//������ ����
	if (stream == NULL) {
		printf("������ �������� ���߽��ϴ�.");
		return;
	}

	//fgetc(), fputc()
	//file get char(); �б� file put char()// ����
	//fputc('������', ����������-��Ʈ��);

	fputc('h', stream);
	fputc('e', stream);
	fputc('l', stream);
	fputc('l', stream);
	fputc('o', stream);
	fputc('~', stream);
	
	fclose(stream);


	stream = fopen("data.txt", "r");

	char tmp;

	tmp = fgetc(stream);

	printf('%c\n', tmp);

	// �۾��� ���ϰ� xxx
	fclose(stream);//������ �׻� close

	return 0;
}