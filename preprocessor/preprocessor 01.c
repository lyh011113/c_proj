//전처리기란 : #을 쓴 모든 것

#include<stdio.h>
#define PI 3.14
#define STR_STRING "HELLO WORLD"
#define OUTPUT printf
#define AGE int
//메크로 함수
#define ADD(x, y)x+y

int main02(void) {


	AGE age = 20;

	printf("PI = %f\n", PI);
	printf("STR_STRING = %s\n",  STR_STRING);
	OUTPUT("STR_STRING_OUT = %s \n", STR_STRING);
	
	
	printf("%d\n", ADD(1,2));

	return 0;

}

