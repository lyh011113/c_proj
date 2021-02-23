//#if, #ifdef,#ifndef,#else, #endif
//#if->if
//#ifdef -> 만약에 정의되어 있다면(참)
//#ifndef(if not def) -> 만약에 정의되어 있지 않다면 (참)
//#else -> else
//#elif -> else if
//#endif -> if문의 끝

#include<stdio.h>
#define DEBUG 1//--디버그 모드
#define NAME "HARRY"

int main(void) {

#if DEBUG
	printf("디버깅 모드입니다.");
#else
	printf("운영모드 입니다.");
#endif

#ifdef NAME // 만약 NAME이라는 메크로 상수가 있다면
#undef NAME//un def NAME -> NAME 이라는 메크로 상수를 삭제한다.
#define NAME "KIM"

#else 

#define NAME "nothinng"

#endif
	printf("%s\n\n", NAME);

	return 0;
}