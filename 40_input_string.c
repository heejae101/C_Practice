/*
scanf 함수에서 서식 지정자로 %s를 사용하면 입력 값을 배열 형태의 문자열에 저장할 수 있습니다(stdio.h 헤더 파일에 선언되어 있습니다).

scanf("%s", 배열);
int scanf(char const * const _Format, ...);
성공하면 가져온 값의 개수를 반환, 실패하면 EOF(-1)를 반환
*/

#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main()
{
    char s1[10];    // 크기가 10인 char형 배열을 선언

    printf("문자열을 입력하세요: ");
    scanf("%s", s1);     // 표준 입력을 받아서 배열 형태의 문자열에 저장

    printf("%s\n", s1);  // 문자열의 내용을 출력

    return 0;
}
// 일반배열은 앞에 &를 붙이지만 배열은 앞에 &를 붙이지 않음

// scanf 함수에서 서식 지정자를 "%[^\n]s"와 같이 지정하면 공백까지 포함하여 문자열을 입력받을 수 있습니다.
char s1[30];

printf("문자열을 입력하세요: ");
scanf("%[^\n]s", s1);    // 공백까지 포함하여 문자열 입력받기

printf("%s\n", s1);

//EOF는 End of File의 약자인데 더 이상 값을 읽을 수 없는 상태를 나타냅니다.
int c1 = getchar();     // 문자를 입력받음
printf("%d\n", c1);
printf("%d\n", EOF);    // -1

// 입력 값을 문자열 포인터에 저장하기 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char *s1 = "hello";

    printf ("문자열을 입력하세요 :");
    scanf("%s",s1);

    printf("%s\n",s1);

    return 0;
}
// 메모리 선언은 읽기 전용이기 때문에 값을 할당 불가하다.

// 입력 값을 문자열 포인터에 저장하려면 문자열이 들어갈 공간을 따로 마련해야 됩니다. 따라서 다음과 같이 malloc 함수로 메모리를 할당한 뒤 문자열을 저장합니다.
// scanf("%s",문자열 포인터);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s1 = malloc(sizeof(char)* 10); // char 10개 크기만큼 동적 메모리 할당
    
    printf("문자열을 입력하게요.: ");
    scanf("%s",s1); // 포인터는 &를 붙이지 않고 그대로 넣음

    printf("%s\n", s1);

    free(s1);

    return 0;
}

/* 
char s1[10], char *s1 = malloc(sizeof(char) * 10)인데도 9개 넘게 입력받을 수 있던데요?
컴파일러나 운영체제에 따라서 배열이 선언된 메모리나 동적으로 할당한 메모리 뒷부분에 공간이 더 있을 수도 있습니다. 
그래서 한 두 개까지는 더 입력할 수 있을 것입니다. 
하지만 많은 문자열을 입력하면 다른 데이터가 있는 메모리 공간을 침범하게 되므로 에러가 발생합니다. 
따라서 원칙적으로는 배열의 크기 - 1, 메모리 공간 - 1보다 긴 문자열은 입력받을 수 없습니다.

입력 길이 문제로 인해 버퍼 오버플로우(buffer overflow) 공격, 스택 오버플로우(stack overflow) 공격을 이용한 해킹이 많았습니다. 
실무에서는 보안을 위해 미리 입력 값을 검사하거나 입력 값의 길이를 제한하는 함수를 주로 사용합니다. 
특히 Visual Studio에서는 scanf 대신 scanf_s, sprintf 대신 sprintf_s처럼 안전한(secure) 함수를 쓰라고 강제하고 있죠. 
그래서 지금까지 소스 코드에 #define _CRT_SECURE_NO_WARNINGS를 넣어주지 않으면 컴파일 에러가 발생했던 것입니다.
*/

// 지금까지 문자열(단어) 하나만 입력받았습니다. 이번에는 공백으로 구분된 문자열 두 개를 입력받아보겠습니다.
/*
scanf("%s %s ...", 배열1, 배열2, ...);
scanf("%s %s ...", 문자열포인터1, 문자열포인터2, ...);
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char s1[10];
    char s2[10];

    printf("문자열을 두 개 입력하세요 ");
    scanf("%s %s",s1,s2);

    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}

//더 입력 받고 싶을땐 
char s1[10], s2[10], s3[10], s4[10], s5[10];

scanf("%s %s %s", s1, s2, s3);                  // 문자열 세 개 입력받기
scanf("%s %s %s %s", s1, s2, s3, s4);           // 문자열 네 개 입력받기
scanf("%s %s %s %s %s", s1, s2, s3, s4, s5);    // 문자열 다섯 개 입력받기
