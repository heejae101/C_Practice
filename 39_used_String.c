#include <stdio.h>
int main()
{
    char s1 = "hello";

    printf("%s", s1);

    return 0;
}
// 컴파일은 되지만 실행은안됨..

/* 문자열은 char 포인터 형식을 사용함
char *변수이름 = "문자열";
*/

#include <stdio.h>

int main()
{
    char c1 = 'a'; //변수안에 a가 그대로 저장됨
    char *s1 = "hello"; // 문자열 리터럴이 있는 곳의 메모리 주소만 저장

    printf("%c\n", c1);
    printf("%s\n", s1);

    return 0;
}

// 포인터도 [] 를 통해 인덱스로 접근가능하다.

#include <stdio.h>

int main()
{
    char *s1 = "Hello";       // 포인터에 문자열 Hello의 주소 저장

    printf("%c\n", s1[1]);    // e: 인덱스 1(두 번째)의 문자 출력
    printf("%c\n", s1[4]);    // o: 인덱스 4(다섯 번째)의 문자 출력
    printf("%c\n", s1[5]);    // 문자열 맨 뒤의 NULL(\0) 출력. NULL은 화면에 표시되지 않음

    return 0;
}

// 문자열 포인터에 인덱스로 문자를 할당할 때 에러가 발생하는데 문자열 리터럴이 있는 메모리주소는 읽기 전용이기 때문입니다.
#include <stdio.h>

int main()
{
    char *s1 = "Hello";    // 포인터에 문자열 Hello의 주소 저장
                           // Hello가 있는 메모리 주소는 읽기 전용

    s1[0] = 'A';           // 문자열 포인터의 인덱스 0에 문자 A를 할당
                           // 실행 에러

    printf("%c\n", s1[0]);

    return 0;
}

// 문자열은 문자배열에 저장할 수 있다.
int main()
{
    char s1[10] = "hello";

    printf("%s\n",s1);

    return 0;
}
// 배열로 문자열을 사용할 때 한가지 주의할 점은 배열을 선언한 즉시 문자열로 초기화 해야한다..
// 문자열을 저장할때 n+1 만큼은 크기로 넣어줘야한다.
char s1[6] = "Hello";

//다음과 같이 문자 배열을 선언하면서 문자열을 바로 할당할 때는 배열의 크기를 생략가능
#include <stdio.h>
int main()
{
    char s1[] = "hello";

    printf("%s\n", s1);

    return 0;
}
// 배열에 문자열을 저장한다면 당연히 인덱스로 접근가능하다.

#include <stdio.h>

int main()
{
    char s1[10] = "Hello";    // 크기가 10인 char형 배열을 선언하고 문자열 할당

    printf("%c\n", s1[1]);    // e: 인덱스 1(두 번째)의 문자 출력
    printf("%c\n", s1[4]);    // o: 인덱스 4(다섯 번째)의 문자 출력
    printf("%c\n", s1[5]);    // 문자열 맨 뒤의 NULL(\0) 출력. NULL은 화면에 표시되지 않음

    return 0;
}

// 문자열 바꾸기

#include <stdio.h>

int main()
{
    char s1[10] = "Hello";    // 크기가 10인 char형 배열을 선언하고 문자열 할당
                              // 배열에 문자열이 복사됨

    s1[0] = 'A';              // 문자 배열의 인덱스 0에 문자 A를 할당

    printf("%s\n", s1);       // Aello: 바뀐 문자열이 출력됨

    return 0;
}
