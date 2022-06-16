#include <stdio.h>

int main()
{
    int num1;
    int num2;
    
    scanf("%d %d",&num1,&num2);
    
    for (num1; num1 <= num2; num1++)
    {
        if (num1 % 5 == 0 && num1 % 11 == 0)
            printf("FizzBuzz");
        else if (num1 % 5 == 0)
            printf("Fizz");
        else if (num1 % 11 == 0)
            printf("Buzz");
        else
            printf("%d",num1);
    }
    return 0;
}

/*#include <stdio.h>
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        printf("%d",i);
    }

    return 0;
}
*/
/* 3의 배수, 5의 배수 
int main()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0)
            printf("Fizz");
        if (i % 5 == 0)
            printf("Buzz");
        else
            printf("%d",i);

        return 0;
    }
}

3과 5의 공배수
#include <stdio.h>

int main()
{
    for (int i = 1; i <= 100; i++)      // 1부터 100까지 100번 반복
    {
        if (i % 3 == 0 && i % 5 == 0)   // 3과 5의 공배수일 때
            printf("FizzBuzz\n");       // FizzBuzz 출력
        else if (i % 3 == 0)            // 3의 배수일 때
            printf("Fizz\n");           // Fizz 출력
        else if (i % 5 == 0)            // 5의 배수일 때
            printf("Buzz\n");           // Buzz 출력
        else
            printf("%d\n", i);          // 아무것도 해당되지 않을 때 숫자 출력
    }

    return 0;
}

i가 30인데 if에서 3이나 5의 배수를 먼저 검사해버리면 3과 5의 공배수는 검사를 하지 않고 그냥 넘어가게 되므로 주의

#include <stdio.h>

int main()
{
    for (int i = 1; i <= 100; i++)   // 1부터 100까지 100번 반복
    {
        if (i % 15 == 0)             // 15의 배수(3과 5의 공배수)일 때
            printf("FizzBuzz\n");    // FizzBuzz 출력
        else if (i % 3 == 0)         // 3의 배수일 때
            printf("Fizz\n");        // Fizz 출력
        else if (i % 5 == 0)         // 5의 배수일 때
            printf("Buzz\n");        // Buzz 출력
        else
            printf("%d\n", i);       // 아무것도 해당되지 않을 때 숫자 출력
    }

    return 0;
}

#include <stdio.h>
{
    for (int i = 0; ++i <= 100;)
    printf(i % 3 ? i % 5 ? "%d\n":"Buzz\n" : i % 5 ? "Fizz\n : "FizzBuzz\n", i);

    return 0;
}
*/