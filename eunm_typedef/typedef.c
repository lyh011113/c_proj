#include<stdio.h>

//typedef
//typedef �⺻�ڷ���(int, char, struct, eunm, union...) ���� �� �ڷ��� �̸� (Alias)

typedef int AGE;//int age
typedef char* NAME;//char*NAME
typedef enum _week { S, M, T, W, TH, F, SAT } WEEK; //������ ����� ���� ������Ÿ��
typedef struct _student {
	int hakno;
	char* name;

}STUDENT;


int main(void) {

	AGE age = 21; //AGE ������ Ÿ��

	NAME name = "�̿���";//NAME ������ Ÿ��
	WEEK w = S;
	STUDENT std;

	std.hakno = 10000;
	std.name = "�̿���";

	//������ ���

	return 0;
}