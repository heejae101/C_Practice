/*
문자열을 자르는 함수는 strtok 이며 함수 이름은 문자열을 조각(token)으로 나누다(string tokenize)에서 따왔습니다(string.h 헤더 파일에 선언되어 있습니다).
strtok(대상문자열, 기준문자);
char *strtok(char *_String, char const *_Delimiter);
자른 문자열을 반환, 더 이상 자를 문자열이 없으면 NULL을 반환
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30] = "The Little Prince";

    char *ptr = strtok(s1,' ');

    while (ptr != NULL)
    {
        printf("%s\n",ptr);
        ptr = strtok(NULL," ");
    }
    return 0;

}
/* 
여기서 while 반복문 안의 strtok 함수는 ptr = strtok(NULL, " ");처럼 자를 문자열 부분에 NULL을 넣어줍니다. 
자세히 설명하자면 NULL을 넣었을 때는 직전 strtok 함수에서 처리했던 문자열에서 잘린 문자열만큼 다음 문자로 이동한 뒤 다음 문자열을 자릅니다. 
만약 ptr = strtok(ptr, " ");처럼 잘린 문자열의 포인터를 다시 넣었을 때는 다음 문자로 이동하지 못하고 처음에 나오는 문자열만 계속 자르게 됩니다. 
즉, 다음과 같은 결과가 나옵니다.
*/

//문자열 포인터에 문자열 리터럴이 들어 있어서 읽기 전용 상태면 strtok사용 불가

char *s1 = "The Little Prince";   // 포인터에 문자열 리터럴 "The Little Prince"의 주소 저장

char *ptr = strtok(s1, " ");      // 실행 에러

while (ptr != NULL)
{
   printf("%s\n", ptr);
   ptr = strtok(NULL, " ");
}

// 동적 메모리에 할당하면 이문제를 해결할 수 있습니다.
char *s1 = malloc(sizeof(char) * 30);    // char 30개 크기만큼 동적 메모리 할당

strcpy(s1, "The Little Prince");    // s1에 문자열 복사

char *ptr = strtok(s1, " ");    // 동적 메모리에 들어있는 문자열은 자를 수 있음

while (ptr != NULL)
{
   printf("%s\n", ptr);
   ptr = strtok(NULL, " ");
}

free(s1);    // 동적 메모리 해제

/*
strtok 함수는 공백 문자뿐만 아니라 다양한 특수 문자와 알파벳 영문자를 기준으로 문자열을 자를 수 있습니다. 
특히 기준 문자는 한 번에 여러 개를 지정할 수 있습니다.
*/
#define _CRT_SECURE_NO_WARNINGS    // strtok 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strtok 함수가 선언된 헤더 파일

int main()
{
    char s1[30] = "2015-06-10T15:32:19";    // 크기가 30인 char형 배열을 선언하고 문자열 할당

    char *ptr = strtok(s1, "-T:");    // -, T, 콜론을 기준으로 문자열을 자름
                                      // 포인터 반환

    while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
    {
        printf("%s\n", ptr);          // 자른 문자열 출력
        ptr = strtok(NULL, "-T:");    // 다음 문자열을 잘라서 포인터를 반환
    }

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30] = "The Little Prince";
    char* sArr[10] = {NULL ,};
    int i = 0;

    char *ptr = strtok(s1," ");

    while (ptr != NULL)
    {
        sArr[i]=ptr;
        i++;
    }
    ptr = strtok(NULL," ");
    
    for (int i = 0; i < 10; i++)
    {
        if (sArr[i] != NULL)
            printf("%s\n",sArr[i]);
    }

    return 0;
}

//연습문제 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[40] = "Alice's Adventures in Wonderland";

    char* tok = strtok(s1," ");

    while (tok != NULL)                     
    {
        printf("%s\n", tok);
        strtok(NULL,' ');
    }

    return 0;
}

//심사문제
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[61];

    scanf("%s",s1);

    char* ptr = strtok(s1,'.');

    while (ptr != NULL)
    {
        printf("%s",ptr);
        strtok(NULL,'.');
    }

    return 0;
    
}
