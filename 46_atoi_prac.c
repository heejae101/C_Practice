/* 먼저 문자열을 정수로 바꾸는 방법
atoi 함수를 사용하면 10진법으로 표기된 문자열을 정수로 바꿀수 있습니다. 함수 이름은 (ASCII string to integer) (stdlib.h 헤더 파일에 선언)
atoi(문자열);
int atoi(char const *_String);
성공하면 변환된 정수를 반환, 실패하면 0을 반환
*/

#include <stdio.h>
#include <stdlib.h>    // atoi 함수가 선언된 헤더 파일

int main()
{
    char *s1 = "283";   // "283"은 문자열
    int num1;

    num1 = atoi(s1);        // 문자열을 정수로 변환하여 num1에 할당

    printf("%d\n", num1);   // 283

    return 0;
}
/*
toi 함수에 문자열을 넣어주면 정수가 반환됩니다. 단, 문자열은 정수로 되어있어야 하며 알파벳 영문자, 특수 문자가 포함되면 해당 문자부터는 변환을 하지 않습니다. 
또한, 처음부터 숫자가 아니면 0으로 변환됩니다. 
다음은 정수에 영문자, 특수 문자가 섞여있을 때의 변환 예입니다.

283a → 283
283a30 → 283
283! → 283
283!30 → 283
a30 → 0
!30 → 0
abc → 0
!@# → 0 
*/

/*
이번에는 특정 진법으로 표기된 문자열을 정수로 변환해보겠습니다. 
strtol 함수를 사용하면 16진법으로 표기된 문자열을 정수로 바꿀 수 있으며 함수 이름은 string to long에서 따왔습니다
(stdlib.h 헤더 파일에 선언되어 있습니다).

strtol(문자열, 끝포인터, 진법);
long strtol(char const *_String, char **_EndPtr, int _Radix);
성공하면 변환된 정수를 반환, 실패하면 0을 반환
*/

#include <stdio.h>
#include <stdlib.h>    // strtol 함수가 선언된 헤더 파일

int main()
{
    char *s1 = "0xaf10";    // "0xaf10"은 문자열
    int num1;

    num1 = strtol(s1, NULL, 16);    // 16진법으로 표기된 문자열을 정수로 변환

    printf("%x %d\n", num1, num1);  // af10 44816

    return 0;
}

/*num 1 = strtol(s1,NULL,16); 처럼 변환할 문자열을 저장한 배열(또는 동적 메모리를 할당한 포인터)를 넣어주고 16 16을 지정하면 16진법으로 표기된 문자열을 정수로 변환할 수 있습니다. 
물론 10을 지정하면 10진법으로 표기된 문자열을 정수로 변환할 수 있습니다. 
strtol 함수의 두 번째 인수(끝 포인터)에 NULL을 넣었는데 이 부분은 여러 개의 정수로 된 문자열을 변환할 때 사용합니다. 
예를 들어 16진법, 10진법, 16진법, 10진법으로 표기된 문자열 "0xaf10 42 0x27C 9952"를 4개로 잘라서 각각을 저장하고 싶을 수도 있겠죠?
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* s1 = "0xaf10 42 0x27C 9952";
    int num1,num2,num3,num4;
    char* end;

    num1 = strtol(s1,&end,16);
    num1 = strtol(s1,&end,10);
    num1 = strtol(s1,&end,16);
    num1 = strtol(s1,NULL,10);

    printf("%x\n",num1);
    printf("%x\n",num2);
    printf("%x\n",num3);
    printf("%x\n",num4);

    return 0;

}
//여기서 끝 포인터는 &end처럼 end의 메모리 주소를 넣어줍니다. 이렇게 하면 strtol 함수가 실행된 뒤에는 끝 포인터가 " 42 0x27C 9952"처럼 이전 숫자의 끝 부분부터 시작하게 됩니다.

/* 문자열을 실수로 바꾸기 atof 함수를 사용하면 문자열을 실수로 바꿀 수 있으며 함수 이름은 ASCII string to float에서 따와습니다.
(stdlib.h 헤더 파일에 선언되어 있습니다.)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* s1 = "35.282672";
    float num1;

    num1 = atof(s1);

    printf("%f\n", num1);

    return 0;
}

// 계속 반복적임으로 다른 내용만 작성
/*
정수를 문자열 형태로 반환하는 방법 sprint 함수 stdio.h 헤더 파일에 선언되어있습니다.
sprint(문자열,%d,정수);
sprint(문자열,%x,정수);
sprint(문자열,%X,정수);
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char s1[10]; 
    int num1 = 283;

    sprintf(s1,"%d",num1); // 16진수 일때 %d 대신 %x를 지정하여 정수를 16진법으로 표기된 문자열로 저장 16진수라는걸 나타내기 위해 앞에 0X를 붙임 "0x%x"
    // 실수도 마찬가지로 문자열로 할때 sprintf 함수를 사용한다. %f 는 실수를 문자열로 저장 %e 는 실수를 지수 표기법으로 문자열 저장
    printf("%s\n",s1);

    return 0;
}



