/* 문자열은 다른 배열이나 포인터(메모리)로 복사 할 수 있습니다. strcpy 함수는 문자열을 다른 곳으로 복사하며
함수 이름은 string copy에서 따왔습니다. (string.h 헤더 파일에 선언)

strcpy
char*strcpy(char*_Dest,char const*_Source);
대상 문자열의 포인터를 반환 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[10]="hello";
    char s2[10];

    strcpy(s2,s1);

    printf("%s\n",s2);
    return 0;
}

// 복사된 결과가 저장될 배열의 크기는 반드시 null까지 들어갈 수 있어야한다. 

#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일

int main()
{
    char *s1 = "Hello";    // 문자열 포인터
    char *s2 = "";         // 문자열 포인터

    strcpy(s2, s1);    // 실행 에러

    printf("%s\n", s2);

    return 0;
}

// 문자열을 포인터에 복사해서 ptrcpy를 하면 오류 발생한다. s2에 저장된 메모리 주소는 복사할 공간도 없고, 읽기만 할 수 있기때문에 쓰기가 막혀있다.

/*
char *s1 = "Hello"; char *s2 = "";과 같은 문자열 포인터에 할당된 문자열 리터럴은 왜 읽기 전용일까요?

C 언어 컴파일러는 문자열 포인터에 할당한 문자열 리터럴을 실행 파일의 읽기 전용 데이터 섹션(데이터 세그먼트)에 배치하기 때문입니다. 따라서 실행 파일이 실행된 뒤에는 읽기 전용 메모리가 되며 쓰기를 할 수 없습니다. 다음은 각 운영체제별 읽기 전용 데이터 섹션 이름입니다.

Windows PE: .rdata
리눅스 ELF: .rodata
OS X Mach-O: __TEXT, __cstring
*/

//문자열 포인터에 문자열을 복사하려면 malloc 함수를 이용해야한다.
#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strcpy 함수가 정의된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    char* s1 = "hello";                      // 문자열 포인터
    char* s2 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당

    strcpy(s2, s1);        // s1의 문자열을 s2로 복사

    printf("%s\n", s2);    // Hello

    free(s2);    // 동적 메모리 해제

    return 0;
}

/*문자열은 strcat함수를 사용하여 서로 붙일 수 있으며 함수 이름은 문자열을 연결시키다(string concatenate) 에서 따왔다.
(string.h 헤더 파일에 선언되어 있다.)

strcat(최종문자열,붙일문자열);
char *strcat(char*_Destination,char const*_Source);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[10]="world";
    char s2[20]="Hello";

    strcat(s2,s1);

    printf("%s\n",s2);

    return 0;
}

// 마찬가지로 포인터 선언을 하지말고 malloc 함수로 동적 메모리를 할당한다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* s1 = "world";
    char* s2 = malloc(sizeof(char) * 20);

    strcpy(s2,"hello");
    strcat(s2,s1);

    printf("%s\n", s2);

    free(s2);

    return 0;
}

// 배열 형태의 문자열을 문자열 포인터에 복사
#define _CRT_SECURE_NO_WARNINGS    // strcpy 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <iso646.h> //상수 우선, iso, _a, 부호는 오른쪽으로 해줬으면 좋겠다.
#include <string.h>    // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    char s1[10] = "Hello";                   // 크기가 10인 char형 배열을 선언하고 문자열 할당
    char *s2 = malloc(sizeof(char) * 10);    // char 10개 크기만큼 동적 메모리 할당

    strcpy(s2, s1);        // s1의 문자열을 s2로 복사

    printf("%s\n", s2);    // Hello

    free(s2);    // 동적 메모리 해제

    return 0;
}

//배열 형태의 문자열을 문자열 포인터에 붙이기
#define _CRT_SECURE_NO_WARNINGS    // strcpy, strcat 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strcpy, strcat 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

int main()
{
    char s1[10] = "world";                  // 크기가 10인 char형 배열을 선언하고 문자열 할당
    char *s2 = malloc(sizeof(char) * 20);    // char 20개 크기만큼 동적 메모리 할당

    strcpy(s2, "Hello");   // s2에 Hello 문자열 복사

    strcat(s2, s1);        // s2 뒤에 s1을 붙임

    printf("%s\n", s2);    // Helloworld

    free(s2);  // 동적 메모리 해제

    return 0;
}

//연습문제 1 문자열 포인터를 배열에 복사하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char* s1 = "C Language";
    char s2[20];

    strcpy(s2,s1);

    return 0;

}
// 연습문제 2 문자열 포인터를 동적 메모리에 복사하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* s1 = "The Little prince";
    char* s2 = malloc(sizeof(char) * 20);

    strcpy(s2,"Alice in ");
    strcat(s2,s1);

    printf("%s\n",s2);
    free(s2);

    return 0;
}

//연습문제 3 문자 배열 붙이기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[20] = " 9th Symphony";
    char s2[40] = "Beethoven";

    strcat(s2,s1);

    printf("%s\n", s2);

    return 0;
}

// 연습문제 4 문자열 리터럴과 동적 메모리 붙이기 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *s1 = " Wonderland";
    char *s2 = malloc(sizeof(char) * 30);

    strcat(s2,s1);


    printf("%s\n", s2);

    free(s2);

    return 0;
}

//심사문제

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[31];
    char s2[31];

    scanf("%s",s1);
    strcpy(s2,s1);
 
    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}

//심사문제 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[40];

    scanf("%s",s1);
    strcat (s1,"th");

    printf("%s\n", s1);

    return 0;
}