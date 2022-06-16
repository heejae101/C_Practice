/* 문자열은 문자가 여러 개 모여있으므로 길이가 있다. 
문자열 길이는 strlen함수로 구할 수 있으며 함수 이름은 문자열 길이(string length)에서 따왔다.
(string.h 헤더 파일에 선언되어 있다.)

strlen(문자열 포인터);
strlen(문자배열);
size_t strlen(const*Str);
*/

#include <stdio.h>
#include <string.h>

int main ()
{
    char *s1 = "hello";
    char s2[10] = "hello";

    printf("%d\n",strlen(s1));
    printf("%d\n",strlen(s2));

    return 0;
}

//null을 포함하지 않고 문자열이 들어있는 배열을 넣으면 배열 안에 들어있는 문자열의 길이가 반환된다.

/* strcmp 함수를 사용하면 두 문자열이 같은지 비교할 수 있으며 함수 이름은 문자열을 비교하다 (string compare)에서 따왔습니다. 
(string.h 헤더파일에 선언되어 있습니다.)

strmp(문자열1, 문자열2;);
int stcmp(const*_str1,char*_Str2);
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[10] = "hello";
    char *s2 = "hello";

    int ret = strcmp(s1,s2);

    printf("%d\n",ret);

    return 0;
}

/* strcmp 함수에 비교할 문자열을 넣어주면 결과를 정수로 반환합니다.
-1: ASCII 코드 기준으로 문자열2(s2)가 클 때
0: ASCII 코드 기준으로 두 문자열이 같을 때
1: ASCII 코드 기준으로 문자열1(s1)이 클 때
s1과 s2의 문자열이 같으므로 0을 반환합니다. 그리고 배열 형태의 문자열, 문자열 포인터등 문자열의 저장방식은 비교에 영향을 주지 않는다.
*/
#include <stdio.h>
#include <string.h>    // strcmp 함수가 선언된 헤더 파일

int main()
{
    // aaa는 ASCII 코드로 97 97 97
    // aab는 ASCII 코드로 97 97 98
    // aac는 ASCII 코드로 97 97 99

    printf("%d\n", strcmp("aaa", "aaa"));    //  0: aaa와 aaa는 같으므로 0
    printf("%d\n", strcmp("aab", "aaa"));    //  1: aab와 aaa 중에서 aab가 크므로 1
    printf("%d\n", strcmp("aab", "aac"));    // -1: aab와 aac 중에서 aac가 크므로 -1

    return 0;
}
// 결과 0 1 -1

// 사용자가 입력한 두문자열을 비교 
#define _CRT_SECURE_NO_WARNINGS    // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <string.h>    // strcmp 함수가 선언된 헤더 파일

int main()
{
    char s1[20];
    char s2[20];

    printf("문자열 두 개를 입력하세요: ");
    scanf("%s %s", s1, s2);

    int ret = strcmp(s1, s2);    // 입력된 문자열 비교

    switch (ret)
    {
    case 0:
        printf("두 문자열이 같음\n");
        break;
    case 1:
        printf("%s보다 %s가 큼\n", s2, s1);
        break;
    case -1:
        printf("%s보다 %s가 큼\n", s1, s2);
        break;
    }

    return 0;
}

// visual studio에서는 문자열이 다르면 1과 -1을 반환하지만 리눅스에서는 ASCII 코드 값의 차이를 반환함 
// 그래서 리눅스에서는 strmp의 반환값을 판단할 때는 switch문 보다 if문을 사용
#include <stdio.h>
#include <string.h>    // strcmp 함수가 선언된 헤더 파일

int main()
{
    char s1[20];
    char s2[20];

    printf("문자열 두 개를 입력하세요: ");
    scanf("%s %s", s1, s2);

    int ret = strcmp(s1, s2);    // 입력된 문자열 비교
    printf("반환값: %d\n", ret);

    // 리눅스와 OS X에서는 ASCII 코드값의 차이를 반환하므로
    // if 조건문으로 판단
    if (ret == 0)
    {
        printf("두 문자열이 같음\n");
    }
    else if (ret > 0)    // 양수일 때
    {
        printf("%s보다 %s가 큼\n", s2, s1);
    }
    else if (ret < 0)    // 음수일 때
    {
        printf("%s보다 %s가 큼\n", s1, s2);
    }

    return 0;
}

//연습문제
#include <stdio.h>
#include <string.h>

int main()
{
    char *s1 = "C Language";

    printf("%d\n",strlen(s1));

    return 0;
}

//연습문제 2
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "Pachelbel Canon";
    char *s2 = "Pachelbel Canon";

    printf("%d",strcmp(s1,s2));

    return 0;
}

// 심사 문제 문자열 길이 구하기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char *s1;

    scanf("%s",s1);

    printf("%d",strlen(s1));

}

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    char s1[31] ={0 ,};

    scanf("%s",s1);

    printf("%d",strlen(s1));

}
// 심사문제 문자열 비교하기
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

int main()
{
    char s1[31];
    char *s2; // 이부분 s2[31];

    scanf("%s,%s",s1,s2);

    printf("%d",strcmp(s1,s2));

    return 0;
}