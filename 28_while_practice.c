#include <stdio.h>

int main()
{
    int i = 0;
    while(i<100)
    {
        printf("hello, world!\n");
        i++;
    }
    return 0;
}

/* 
초기식
while (조건식) <- 루프 선언문
{
    반복할 코드
    변화식
}
*/

/* 1부터 시작하기 
int main()
{
    int i = 1;
    while(i<=100)
    {
        printf("hello, world!\n");
        i++;
    }
    return 0;
}
*/

/* 초기값 많이주고 변수 감소
int main()
{
    int i = 100;
    while(i>0)
    {
        printf("hello, world!\n");
        i--;
    }
    return 0;
}
*/

/* 조건식에 세미콜론(;) 붙이면 안됨
int main()
{
    int i = 0;
    while(i<100);
    {
        printf("hello, world!\n");
        i++;
    }
    return 0;
}
*/

/* 입력한 횟수대로 반복
#defin _CRT_SECURE_NO_WARNINGS scanf 보안 경고로 인한 컴파일 에러 방지
int main()
{
    int count;

    scanf("%d",%count)

    while(i<count)
    {
        printf("hello, world!%d\n",i);
        i++;
    }
    return 0;
}
*/

/* 반복횟수가 정해지지 않은 경우
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); 현재 시간값으로 시드 설정 

    int i = 0;

    while(i != 3)
    {
        i = rand()%10; rand 함수를 사용해 무작위로 정수를 생성한 뒤 10 미만의 숫자로 만듦
        print("%d\n",i);
    }
    return 0;
}

*/

/* 무한루프
int main()
{
    while(1) 1 or true 면 무한루프 bool 값을 사용하면  include <stdbool.h> 추가해줘야함
    {
        printf("hello, world!\n");
        i++;
    }
    return 0;
}
*/

/* 중괄호 생략 가능 
int main()
{
    while(1)
        printf("hello, world!\n");
    return 0;
}
대신 무한루프만 가능할듯 
*/

/* 1회요금 1200원 교통카드를 사용했을 때 마다 잔액을 각줄에 출력하는 프로그램 만들기
int main()
{
    int money;

    scanf("%d",&money);
    

    while (money>=1200)
    {
        money -= 1200;
        printf("%d\n",money);
    }

    return 0;
}
*/