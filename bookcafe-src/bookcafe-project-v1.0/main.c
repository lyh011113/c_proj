#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h> //strcmp(); strncmp()... ���
#include<stdlib.h>


//--�츮�� å�̸��� �۰��� ���� ���̴� (�迭��) (3)
//--å���� ũ��� �� 100���� �� �� �ִ�.

#define MAX_CAPACITY 100 //100������ �� �� �ִ� å�� (4)

char* book_name[MAX_CAPACITY]; // å�̸� (5)
char* book_author[MAX_CAPACITY]; // �۰��̸�

int book_idx = 0; // �迭 �ε���

//�Լ� ����� (1)

void add();  // å�� �߰��ϴ� �Լ�
void del();  // å�� �����ϴ� �Լ�
void list(); // å����� ����ϴ� �Լ�
void find(); // å�� ã�� �Լ�
void save(); // ������ �����ϴ� �Լ�
void read(); // ������ �о���̴� �Լ�
void help(); // ������ ����ϴ� �Լ�
char* ex_strdup(char*);//strdup ����

int main(void) {

	// add, list, del ...
	char command[100];

	while (1) {
	
		printf("��ɾ �Է��ϼ��� >");
		scanf("%s", command);
		// command = "add" �߰� �׼�
		// command = find" �˻� �׼�
		// ���ڿ� �񱳽ÿ��� strcmp(); �Լ��� ����Ͽ�
		// �����Ͱ� ����ġ�� ������ ���� ��ü�� ���ؾ��Ѵ�.
		// if(*command == "add")
		// srrcmp (�񱳹��ڿ�1, �񱳹��ڿ�2)
		// ���࿡ ������ ���ڿ��̴� -> 0 / �׷��� ������ -> 1
		if (strcmp(command,"add") == 0) {
			add();
		}
		else if (strcmp(command, "del") == 0) {
			del();
		}
		else if (strcmp(command, "list") == 0) {
			list();
		}
		else if (strcmp(command, "find") == 0) {
			find();
		}
		else if (strcmp(command, "save") == 0) {
			save();
		}
		else if (strcmp(command, "read") == 0) { 
			read();
		}
		else if (strcmp(command, "help") == 0) {
			help();
		}
		else if (strcmp(command, "q") == 0) {
			break;
		}
		else {
			printf("�´� ��ɾ �����ϴ�.\n");	
		}
	
	}

	return 0;
}

//�Լ� ���Ǻ� (2)
void add() {
	// printf("add�Լ� ȣ��!\n");
	// add å���� �۰��� [����]
	// add -> command ����
	// å�̸�->buf1
	// �۰��� -> buf2
	char buf1[100], buf2[100]; // buf1 å�̸�, buf2�� �۰���
	scanf("%s", buf1);
	scanf("%s", buf2);

	//strcpy(), strdup()
	//book_name[book_idx] = buf1;
	//book_author[book_idx] = buf2;

	// strdup(������ ���ڿ�) -> return ���� ������  ���ڿ��� �����͸� �Ѱ��ݴϴ�.
	// strdup -> malloc (�޸� �����Ҵ�) �� ������ ���ڿ� ��ü�� ����ȴ�.
	// sstring duplication / string copy (strcpy)
	//strcoy ( ����� ����, ������ ����)
	book_name[book_idx] = _strdup(buf1);
	book_author[book_idx] = _strdup(buf2);

	printf("'%s'�� �����Ͽ����ϴ�.\n", book_name[book_idx]);
		book_idx++;
}
void del() {
	printf("del�Լ� ȣ��!\n");
}
void find() {
	//book_name[] = 10���� �ִ�.
	//10���� ���鼭 ���� �̸��� �ִ��� Ȯ���ϰ�, ������
	//�� index�� ����Ͽ� å�� ����Ѵ�
	//>find å�̸� [����];
	char buf1[100];
	scanf("%s", buf1);

	for (int i = 0; i < book_idx; i++) {
	//���ڿ� �񱳴�? strcmp
		if (strcmp(buf1, book_name[i]) == 0) {
			printf("%-10s %-10s\n", book_name[i], book_author[i]);
			return;
		}
	}
	// ���� �̸��� ���� å�� ���� �� ����
	printf("å ��� ��, '%s'��� å�� �����ϴ�.\n", buf1);
}
void list() {
	for (int i = 0; i < book_idx; i++) {
		printf("%-10s %-10s\n", book_name[i], book_author[i]);
	}
}
void save() {
	printf("save�Լ� ȣ��!\n");
}
void read() {
	printf("read�Լ� ȣ��!\n");
}
void help() {
	printf("help�Լ� ȣ��!\n"); 
}

//--- strdup ���� ����

char* ex_strdup(char* source) {
	

	char*tmp =(char*) malloc(strlen(source)+1);
	if (tmp == NULL) {

		return NULL;
	}
	//�޸� �Ҵ� ����
	strcpy(tmp, source);
	return tmp;
}
