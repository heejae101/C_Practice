#include <stdio.h>

int main(){
    for (int i=0; i<100;i++)
    {
        printf("hello , world \n");
    }
    return 0;
}
/* 조건식 
for (초기식; 조건식; 변화식)
{
    반복할 코드
}

/* 옛날 방식이면 i값을 출력할 수 있음
int main(){
    int i;
    for(i = 0; i<100; i++){
        printf("hello, word\n");
    }
    printf("%d\n",i);
    return 0;
}
*/

/* int = 1 로 선언하면 1부터 100까지 출력 가능 
int main(){
    for (int i=1; i<=100;i++)
    {
        printf("hello , world \n");
    }
    return 0;
}
*/

/* 초깃값을 크게 주고 변수를 감소시키는 방법
int main(){
    for (int i=100; i>0;i--)
    {
        printf("hello , world \n");
    }
    return 0;
}
*/

/* for 반복문은 if 조건문과 마찬가지로 ;(세미콜론)을 붙이면 안됨.
int main(){
    for (int i=1; i<=100;i++);
    {
        printf("hello , world \n");
    }
    return 0;
}

for (int i = 0; i<100; i++);
printf("hello")
의 코드와 똑같음 따라서 반복 되지 않고 한번만 실행됩니다.
*/

/* 중괄호 생략가능 하지만 반복할 코드가 두개 이상일때 중괄호 생략은 주의해야한다.
int main(){
    for (int i=1; i<=100;i++)
        printf("hello , world \n");
    return 0;
}
*/

/* 입력한 횟수대로 반복
int main(){
    int count;

    scanf("%d",&count);

    for (int i=0; i < count;i++)
    {
        printf("hello , world %d\n",i);
    }
    return 0;
}
*/

/* i를 따로 선언하지 않고, count를 그대로 사용할 수도 있다.
int main()
{
    int count;

    scanf("%d",&count);


    for (; count > 0; count --)
    {
        printf("hello , world \n");
    }

    return 0;

}

for (scanf("%d",&count);count > 0; count--) 로 가능
*/

/* for문에 반복문 변수 두개 사용
int main()
{
    for (int i= 0,j = 0; i<10;i++,j+=2)
    {
        printf("i: %d, j : %d\n", i, j);
    }
    return 0;
}
*/

/* for반복문 무한루프 
int main()
{
    for (;;)
    {
        printf("hello , world \n");
    }
    return 0;
}
*/

/* a를 입력받는데 a부터 z 까지 출력하기
int main()
{
    char count;
    scanf("%c",&count);

    for(int i = count ;i<=122;i++)
    {
        printf("%c",i);
    }

    return 0;
}
*/