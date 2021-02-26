#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h> //strcmp(); strncmp()... 등등
#include<stdlib.h>


//--우리는 책이름과 작가를 받을 것이다 (배열로) (3)
//--책장의 크기는 총 100권이 들어갈 수 있다.

#define MAX_CAPACITY 100 //100여권이 들어갈 수 있는 책장 (4)

char* book_name[MAX_CAPACITY]; // 책이름 (5)
char* book_author[MAX_CAPACITY]; // 작가이름

int book_idx = 0; // 배열 인덱스

//함수 선언부 (1)

void add();  // 책을 추가하는 함수

// -- 배열로 입력된 값들을 검색해서, 해당 배열 index를 가지고
// -- 그 index에 있는 값을 삭제(NULL)

void del();  // 책을 삭제하는 함수
void list(); // 책목록을 출력하는 함수
void find(); // 책을 찾는 함수
void save(); // 파일을 저장하는 함수
void read(); // 파일을 읽어들이는 함수
void help(); // 도움말을 출력하는 함수
char* ex_strdup(char*);//strdup 구현

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
	//strcoy ( 복사될 변수, 복사할 변수)
	book_name[book_idx] = _strdup(buf1);
	book_author[book_idx] = _strdup(buf2);

	printf("'%s'를 저장하였습니다.\n", book_name[book_idx]);
		book_idx++;
}
// -- 배열로 입력된 값들을 검색해서, 해당 배열 index를 가지고
// -- 그 index에 있는 값을 삭제(NULL)

void del() {

	//책이름을 검색하고, 그 책이름이 있는 배열 index를 추출

	char* search_txt[100];


	scanf("%s", search_txt);

	// 사용자로 부터 받은 값, '검색어'와 book_names[x]에 있는 '책이름'이 일치하는지 확인
	// 그 index 삭제
/*
	for (int i = 0; i < book_idx; i++) {
		// 문자열 비교가 필요함, strcmp()
		// 배열의 인덱스는 0부터 시작한다.
		// 퀴즈 배열이 "크기"(총 방의 숫자)가 150개
		// 그럼 배열의 마지막 인덱스는 몇일까요?
		// 배열의 크기가 10인 배열
		// 0 1 2 3 4 5 6 7 8 9 ( 10 -1)
		// 배열의 크기가 150 이라고 하면 배열의 마지막 인덱스 150 - 1 = 149 (배열의 크기 - 1)


		if (strcmp(book_name[i], search_txt) == 0) {
			book_name[i] = book_name[book_idx-1];
			book_author[i] = book_author[book_idx-1];
			printf("%s가 삭제되었습니다.\n", search_txt);
			book_idx--;
			return;
		}
		*/
		/*
	int temp_idx;
	for(temp_idx = 0; temp_idx < book_idx; temp_idx++){
		if (strcmp(book_name[temp_idx], search_txt) == 0) {
			printf("%s가 삭제되었습니다.\n", search_txt);
			break;
		}
	}
	if (temp_idx != book_idx) {
		for (int i = temp_idx ; i < book_idx; i++) {
			book_name[i] = book_name[i + 1];
			book_author[i] = book_author[i + 1];

		}
		book_idx--;
		return;
	}

	*/

	for (int D = 0; D < book_idx; D++) {
		if (strcmp(book_name[D], search_txt) == 0) {
			for (int i = D; i < book_idx; i++) {
				book_name[i] = book_name[i + 1];

				book_author[i] = book_author[i + 1];

			}
			printf("%s가 삭제되었습니다.\n", search_txt);
			book_idx--;
			return;
		}
		// search_txt!=book_name[i] 같지 않은 경우는 i == book_idx
		// 책이름이 'ABC', 'BBB', 'CCC', 'DDD' 라고 총 4개가 있을 경우
		
	}
	printf("책이름이 %s인 책은 존재하지 않습니다.\n", search_txt);
}


void find() {
	//book_name[] = 10개가 있다.
	//10번을 돌면서 같은 이름이 있는지 확인하고, 있으면
	//그 index를 사용하여 책을 사용한다
	//>find 책이름 [엔터];
	char buf1[100];
	scanf("%s", buf1);

	for (int i = 0; i < book_idx; i++) {
	//문자열 비교는? strcmp
		if (strcmp(buf1, book_name[i]) == 0) {
			printf("%-10s %-10s\n", book_name[i], book_author[i]);
			return;
		}
	}
	// 같은 이름을 가진 책이 없을 때 실행
	printf("책 목록 중, '%s'라는 책은 없습니다.\n", buf1);
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

//--- strdup 내부 구현

char* ex_strdup(char* source) {
	

	char*tmp =(char*) malloc(strlen(source)+1);
	if (tmp == NULL) {

		return NULL;
	}
	//메모리 할당 성공
	strcpy(tmp, source);
	return tmp;
}
