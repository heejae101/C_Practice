#define _CRT_SECRUE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num1;

    scanf("%d",&num1);

    if (num1 == 1)
        goto ONE;
    else if (num1 == 2)
        goto TWO;
    else
        goto EXIT;
    
    ONE:
        printf("1입니다.");
        goto EXIT;
    TWO:
        printf("2입니다.");
        goto EXIT;
    EXIT:
        return 0;
}
// if 문이 더 간단하다.
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num1;

    scanf("%d", &num1);

    if (num1 == 1)         // num1이 1이면
        printf("1입니다.\n");
    else if (num1 == 2)    // num1이 2이면
        printf("2입니다.\n");

    return 0;
}*/

/* 중첩 루프 빠져나오기 
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num1=0;

    bool exitOuterLoop = flase;
    for (int j = 0; j < 10; j++)
    {
        if(num1 == 20)
        {
            exitOuterLoop = true;
            break;
        }
        num1++;
    }
    
    if (exitOuterLoop == true)
        break;

    return 0;
}

이거보단 goto 문이 더 간결하다.

#include <studio.h>
int main()
{
    int num1 = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (num1 == 20)
                goto EXIT;

            num1++;
        }
    }

    EXIT:
        printf("%d\n",num1);

    return 0;
}
*/

/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int gender;      // 성별: 남자 1, 여자 2
    int age;         // 나이
    int isOwner;     // 주택 소유 여부: 자가 1, 전월세 0

    scanf("%d %d %d", &gender, &age, &isOwner);

    printf("안녕하세요.\n");
    printf("문을 연다.\n");

    if (gender == 2)                 // 여자라면
    {
        printf("안녕히계세요.\n");    // 중복 코드
        printf("문을 닫는다.\n");     // 중복 코드
        return 0;                    // 프로그램 종료
    }

    if (age < 30)                    // 30세 미만이라면
    {
        printf("안녕히계세요.\n");    // 중복 코드
        printf("문을 닫는다.\n");     // 중복 코드
        return 0;                    // 프로그램 종료
    }

    if (isOwner == 0)                // 전월세라면
    {
        printf("안녕히계세요.\n");    // 중복 코드
        printf("문을 닫는다.\n");     // 중복 코드
        return 0;                    // 프로그램 종료
    }
 
    return 0;                        // 프로그램 종료
}

중복되는 코드를 goto 문으로 좀더 간결하게 표현가능하다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int gender;      // 성별: 남자 1, 여자 2
    int age;         // 나이
    int isOwner;     // 주택 소유 여부: 자가 1, 전월세 0

    scanf("%d %d %d", &gender, &age, &isOwner);

    printf("안녕하세요.\n");
    printf("문을 연다.\n");

    if (gender == 2)
        goto EXIT;    // 에러가 발생했으므로 EXIT로 이동

    if (age < 30)
        goto EXIT;    // 에러가 발생했으므로 EXIT로 이동

    if (isOwner == 0)
        goto EXIT;    // 에러가 발생했으므로 EXIT로 이동
 
EXIT:
    printf("안녕히계세요.\n");    // 에러 처리 코드를
    printf("문을 닫는다.\n");     // 한 번만 사용함

    return 0;    // 프로그램 종료
}
*/