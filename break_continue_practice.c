/*
#include <stdio.h>

int main()
{
    int num1 = 0;

    while (1)
    {
        num1++;

        printf("%d\n",num1);

        if (num1 == 100)
            break;
    }
    
    return 0;
}
*/

/* for문 무한 루프 break 
int main()
{
    int num1 = 0;

    for(;;)
    {
        num1++;

        printf("%d",num1);

        if (num1==100)
            break;

    }

    return 0;
}
*/

/*
int main()
{
    for (int i = 1; i <= 100; i++)    // 1부터 100까지 증가하면서 100번 반복
    {
        if (i % 2 != 0)               // i를 2로 나누었을 때 나머지가 0이 아니면 홀수
            continue;                 // 아래 코드를 실행하지 않고 건너뜀

        printf("%d\n", i);
    }

    return 0;
}
*/

/*
int main()
{
    int i = 1;
    while (i<=100)
    {
        i++;
        if (i % 2 ! = 0)
            countinue;

        printf("%d\n");
    }
    return 0;
}
*/

/* 입력한 횟수대로 반복
int main()
{
    int count;

    scanf("%d\n",&count);

    int i = 1;

    while(1)
    {
        printf("%d\n",i)

        if(i == count)
            break;

        i++;
    }

    return 0;
}
*/

/* 입력한 숫자까지 짝수 출력하기
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

int main()
{
    int count;

    scanf("%d",count);

    for(int i= 0;i <= count;i++)
    {
        if(i % 2 != 0)
            continue;

        printf("%d\n",i);
    }

    return 0;
}
*/

//표준 입력 정수 2개 받고 첫번재와 두번째 정수 사이의 숫자중 7로 끝나지 
//않는 숫자를 출력
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num1;
    int num2;
    int i;

    scanf("%d %d",&num1,&num2);

    i = num1;

    while(1)
    {
        if (i > num2)
            break;
        
        if (i % 10 != 7)
            i += 1;
            continue;

        printf("%d",i);
        i++;
    }

    return 0;
}