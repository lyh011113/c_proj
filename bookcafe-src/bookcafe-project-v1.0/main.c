#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h> //strcmp(); strncmp()... 등등


//--우리는 책이름과 작가를 받을 것이다 (배열로) (3)
//--책장의 크기는 총 100권이 들어갈 수 있다.

#define MAX_CAPACITY 100 //100여권이 들어갈 수 있는 책장 (4)

char* book_name[MAX_CAPACITY]; // 책이름 (5)
char* book_author[MAX_CAPACITY]; // 작가이름

int book_idx = 0; // 배열 인덱스

//함수 선언부 (1)

void add();  // 책을 추가하는 함수
void del();  // 책을 삭제하는 함수
void list(); // 책목록을 출력하는 함수
void find(); // 책을 찾는 함수
void save(); // 파일을 저장하는 함수
void read(); // 파일을 읽어들이는 함수
void help(); // 도움말을 출력하는 함수

int main(void) {

	// add, list, del ...
	char command[100];

	while (1) {
	
		printf("명령어를 입력하세요 >");
		scanf("%s", command);
		// command = "add" 추가 액션
		// command = find" 검색 액션
		// 문자열 비교시에는 strcmp(); 함수를 사용하여
		// 포인터가 가르치는 문자의 값들 자체를 비교해야한다.
		// if(*command == "add")
		// srrcmp (비교문자열1, 비교문자열2)
		// 만약에 같으면 문자열이다 -> 0 / 그렇지 않으면 -> 1
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
			printf("맞는 명령어가 없습니다.\n");
			
		}
	
	
	}





	return 0;
}

//함수 정의부 (2)
void add() {
	// printf("add함수 호출!\n");
	// add 책제목 작가명 [엔터]
	// add -> command 변수
	// 책이름->buf1
	// 작가명 -> buf2
	char buf1[100], buf2[100]; // buf1 책이름, buf2는 작가명
	scanf("%s", buf1);
	scanf("%s", buf2);

	//strcpy(), strdup()
	//book_name[book_idx] = buf1;
	//book_author[book_idx] = buf2;

	// strdup(복사할 문자열) -> return 으로 복제된  문자열의 포인터를 넘겨줍니다.
	// strdup -> malloc (메모리 동적할당) 힙 영역에 문자열 객체가 저장된다.
	// sstring duplication / string copy (strcpy)
	book_name[book_idx] = _strdup(buf1);
	book_author[book_idx] = _strdup(buf2);

	printf("'%s'를 저장하였습니다.\n", book_name[book_idx]);
		book_idx++;
}
void del() {
	printf("del함수 호출!\n");
}
void find() {
	printf("list함수 호출!\n");
}
void list() {
	for (int i = 0; i < book_idx; i++) {
		printf("%-10s %-10s\n", book_name[i], book_author[i]);
	}
}
void save() {
	printf("save함수 호출!\n");
}
void read() {
	printf("read함수 호출!\n");
}
void help() {
	printf("help함수 호출!\n"); 
}
