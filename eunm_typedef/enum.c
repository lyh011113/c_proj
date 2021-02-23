#include<stdio.h>

//일주일

//열거형의 선언 문법

//enum 열거형 이름 { 값들 }

enum week {

	SUN = 10, // 0
	MON = 20, // 1...
	THU = 30,
	WED = 40,
	THURS = 50,
	FRI = 60,
	SAT = 123453333,

};

enum boolean {

	false, true
};

int main01(void){

	enum week w;
	w = SUN;

	if (true) {//enum boolean
		printf("aaaaa\n\n");
	}
	
	printf("Sizeof(week)=%d\n\n", sizeof(enum week));
	printf("SUN = %d, MON = %d\n", SUN, MON);
	printf("THU = %d, THURS = %d\n", THU, THURS);
	printf("FRI = %d, SAT = %d\n", FRI, SAT);

	return 0;

}

