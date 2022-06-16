/*
특정 문자로 검색하는 방법입니다. strchr 함수를 사용하면 문자열에서 특정 문자로 검색할 수 있으며 함수 이름은 string character에서 따왔습니다(string.h 헤더 파일에 선언되어 있습니다)
strchr(대상문자열, 검색할문자);
char *strchr(char * const _String, int const _Ch);
문자를 찾았으면 문자로 시작하는 문자열의 포인터를 반환, 문자가 없으면 NULL을 반환
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30] = "A Graden Diary";

    char* ptr = strchr(s1,'a');

    while (ptr != NULL)
    {
        printf("%s\n",ptr);
        ptr = strchr(ptr+1,'a');
    }

    return 0;

}

//실행 결과 arden Diary ary

/*
strchr 함수는 문자열의 처음부터 문자를 검색해서 반환하지만 strrchr함수는 문자열의 끝에서부터 문자를 검색하며 
함수 이름은 문자열 오른쪽에서부터 문자를 찾아라(string (find from the right) character)에서 따왔습니다
(string.h 헤더 파일에 선언되어 있습니다).
strrchr(대상문자열, 검색할문자);
char *strrchr(char * const _String, int const _Ch);
문자열의 끝에서부터 역순으로 검색해서 문자를 찾았으면 해당 문자로 시작하는 문자열의 포인터를 반환, 문자가 없으면 NULL을 반환
*/
#include <stdio.h>
#include <string.h>   // strrchr 함수가 선언된 헤더 파일

int main()
{
    char s1[30] = "A Garden Diary";    // 크기가 30인 char형 배열을 선언하고 문자열 할당

    char *ptr = strrchr(s1, 'a');      // 문자열 끝에서부터 'a'로 시작하는 문자열 검색. 포인터 반환

    printf("%s\n", ptr);   // ary

    return 0;
}

/*
문자열 안에서 문자열로 검색하는 방법을 알아보겠습니다. strstr 함수는 문자열 안에서 문자열을 검색하며 string (find) string에서 따왔습니다(string.h 헤더 파일에 선언되어 있습니다).

strstr(대상문자열, 검색할문자열);
char *strstr(char * const _String, char const * const _SubString);
문자열을 찾았으면 문자열로 시작하는 문자열의 포인터를 반환, 문자열이 없으면 NULL을 반환
*/

#include <stdio.h>
#include <string.h>    // strstr 함수가 선언된 헤더 파일

int main()
{
    char s1[30] = "A Garden Diary";     // 크기가 30인 char형 배열을 선언하고 문자열 할당

    char *ptr = strstr(s1, "den");      // den으로 시작하는 문자열 검색, 포인터 반환

    printf("%s\n", ptr);    // den Diary

    return 0;
}

//연습문제 1 
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30] = "Alice in Wonderland";
    
    char* ptr = strchr(s1,'n');

    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strchr(ptr+1,'n');
    }

    return 0;
}

//연습문제 2
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[30] = "The Little Prince";

    char* ptr =strrchr(s1,'i');

    printf("%s\n", ptr);

    return 0;
}

// 심사문제 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char strw[1001];
    int count = 0;

    scanf("%[^\n]s",strw);

    char* ptr = strchr(strw,' ');

    while (strw != NULL)
    {
        count ++;
        ptr = strchr(ptr+1,' ');
    }

    printf("%d\n",count);

    return 0;
}
