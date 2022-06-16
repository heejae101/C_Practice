/*sprintf 함수를 사용하면 서식(format)을 지정하여 문자열을 만들 수 있습니다(stdio.h 헤더 파일에 선언되어 있습니다).
sprintf(배열, 서식, 값);
sprintf(배열, 서식, 값1, 값2, ...);
int sprintf(char * const _Buffer, char const * const _Format, ...);
성공하면 만든 문자열의 길이를 반환, 실패하면 음수를 반환
*/

#define _CRT_SECURE_NO_WARNINGS    // sprintf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // sprintf 함수가 선언된 헤더 파일

int main()
{
    char s1[20];    // 크기가 20인 char형 배열을 선언

    sprintf(s1, "Hello, %s", "world!");    // "Hello, %s"로 서식을 지정하여 s1에 저장

    printf("%s\n", s1);    // Hello, world!: 문자열 s1 출력

    return 0;
}

/*
sprintf(s1, "Hello, %s", "world!");처럼 sprintf 함수에 문자열을 저장할 배열과 문자열을 만들 서식 그리고 문자열을 만들 값(문자열)을 순서대로 넣습니다. 
이렇게 하면 "Hello, %s"에서 서식 지정자 %s 부분이 "world!"로 바뀌면서 s1에 "Hello, world!"가 저장됩니다.
보통 s1과 같이 문자열을 저장할 빈 배열을 버퍼(buffer)라고 부릅니다.
*/

/*서식을 지정하여 문자열 포인터에 문자열 만들기
문자열 포인터에 문자열을 만들어보겠습니다. 문자열 포인터를 사용하려면 먼저 malloc 함수로 메모리를 할당한 뒤 sprintf 함수로 문자열을 만들면 됩니다.
*/
#define _CRT_SECURE_NO_WARNINGS    // sprintf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // sprintf 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
    
int main()
{
    char *s1 = malloc(sizeof(char) * 20);  // char 20개 크기만큼 동적 메모리 할당

    sprintf(s1, "Hello, %s", "world!");    // "Hello, %s"로 서식을 지정하여 s1에 저장

    printf("%s\n", s1);    // Hello, world!: 문자열 s1 출력

    free(s1);    // 동적 메모리 해제

    return 0;
}

//배열과 마찬가지로 s1과 같이 문자열을 생성할 메모리 공간도 버퍼입니다.
//문자열 사용이 끝났다면 반드시 free 함수로 동적 할당한 메모리를 해제합니다. 즉, 문자열 포인터 사용은 항상 malloc, 사용, free 패턴입니다.

//심사문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int number;
    char name[31], result[40];

    scanf("%d %s",&number,name);

    if (number == 1)
        sprintf(result,"%dst %s",number,name);
    else if (number == 2)
        sprintf(result,"%dnd %s",number,name);
    else if (number == 3)
        sprintf(result,"%drd %s",number,name);
    else
        sprintf(result,"%dth %s",number,name);

    printf("%s\n", result);

    return 0;
}