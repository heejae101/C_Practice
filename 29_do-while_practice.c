#include <stdio.h>

int main()
{
    int i = 0;

    do
    {
        printf("hello, world! %d\n",i);
        i++;
    } while (i <100);
    
    return 0;
}

/* 초기식
do 
{
    반복할 코드
    변화식
} while (조건식);
*/

/* 
int main()
{
    int i = 0;
    
    do
    {
        printf("hello, world! %d\n",i);
        i++;
    } while (i <100);
    
    return 0;
}
*/ 

/* 초기값 1로 초기화
int main()
{
    int i = 1;

    do
    {
        printf("hello, world! %d\n",i);
        i++;
    } while (i <=100);
    
    return 0;
}
*/

/* 감소시키면서 반복 
int main()
{
    int i = 100;

    do
    {
        printf("hello, world! %d\n",i);
        i--;
    } while (i > 0);
    
    return 0;
}
*/

/* 입력한 횟수대로 반복
#denfine _CRT_SECURE_NO_WARNING scanf 보안 경고로 인한 컴파일 에러 방지
int main()
{
    int count;

    scanf("%d",&count);

    int i = 0;
    do
    {
        printf("hello, world! %d\n",i);
        i++;
    } while (i < count);
    
    return 0;
}
*/

/*

int main()
{
    int count;

    scanf("%d",&count);

    do
    {
        printf("hello, world! %d\n",count);
        i--;
    } while (i > count);
    
    return 0;
}
*/

/* 반복횟수가 정해지지 않은 경우
#include <stdio.h>
#include <stdlib.h>
#include <tim.h>

int main()
{
    int i = 0;

    sarnd(time(NULL));

    do
    {
        i = rand() % 10
        printf("%d\n",i);
    } while (i !=3);
    
    return 0;
}
*/

/* 무한 루프 만들기
int main()
{
    do
    {
        printf("Hello, world!\n");
    } while (1);
    
    return 0;
}
*/

/* 한번만 실행 하기
int main()
{
    do
    {
        printf("Hello, world!\n");
    } while (0);
    
    return 0;
}
*/

/* 숫자의 합구하기 
sum+=i;
i++;s
*/

