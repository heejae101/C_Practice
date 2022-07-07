/* C언어 에서는 return 10, 20, 30 이러한 문법은 지원하지 않습니다.
C 언어에서 값을 여러 개 반환하는 함수를 만들 때는 주로 포인터 매개변수를 사용합니다. 지금가지 매개변수는 함수에 값을 전달할 때 사용했고,
함수 바깥에서 값을 가져오는 용도로는 사용할 수 없었습니다. 

int swapNumber(int *first, int *second) // 함수 바깥에서도 사용할 수 있음
{
    int temp;
    
    temp = first;
    first = second;
    second = temp;
}

*/

#include <stdio.h>

void swapNumber(int first, int second)
{
    int temp;

    temp = first;
    first = second;
    second = temp;
}

int main()
{
    int num1 = 10;
    int num2 = 20;

    swapNumber(num1, num2);

    printf("%d %d\n",num1,num2);

    return 0;
}

#include <stdio.h>

void swapNumber(int *first, int *second)
{
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

int main()
{
    int num1 = 10;
    int num2 = 20;

    swapNumber(&num1,&num2); // &를 사용하여 num1과 num2의 메모리 주소를 넣어줌
 
    printf("%d %d\n",num1,num2); // 20 10: swapNumber에 의해서 num1과 num2의 값이 서로 바뀜
    
    return 0;
}

// 함수의 반환값은 값을 하나만 반환할 수 있는데 이처럼 매개변수를 포인터로 사용하면 함수 바깥으로 여러개의 값을 전달할 수 있습니다.

// 매개변수 포인터와 IN,OUT
/* C 언어로 작성된 여러 프로그램들을 보면 매개변수 부분에 IN,OUT,in,out 등의 단어가 추가로 붙어있는 경우가 있습니다.

void GetValue(IN int a, OUT int *b)
{
    print("%d\n",a);

    *b = 10;
}

IN은 함수 안으로 들어가기만 하는 일반적인 매개변수라는 표시 OUT은 함수 바깥으로 값이 나오는 매개변수라는 표시입니다.
*/

// void 포인터 매개변수를 사용하면 자료형 변환을 하지 않아도 모든 자료형을 함수에 넣을 수 있습니다. 이번에는 char, int, float형을 매개변수로 받아서 값을 바꿔보겠습니다.
#include <stdio.h>

enum TYPE{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT
};

void swapValue(void *ptr1, void *ptr2, enum TYPE t)
{
    switch (t)
    {
        {
        case TYPE_CHAR:
        {
            char temp;
            temp = *(char *)ptr1;
            *(char *)ptr1 = *(char *)ptr2;
            *(char *)ptr2 = temp;
            break;
        }
        case TYPE_INT:
        {
            int temp;
            temp = *(int *)ptr1;
            *(int *)ptr1 = *(int *)ptr2;
            *(int *)ptr2 = temp;
            break;
        }
        case TYPE_FLOAT
        {
        float temp;
        temp = *(float *)ptr1;
        *(float *)ptr1 = *(float *)ptr2;
        *(float *)ptr2 = temp;
        break;
    }
    }
}

int main()
{
    char c1 = 'a';
    char c2 = 'b';
    swapValue(&c1, &c2, TYPE_CHAR);
    printf("%c %c\n",c1,c2);

    int num1 = 10;
    int num2 = 20;
    swapNumber(&num1,&num2,TYPE_INT);
    printf("%d %d\n",num1,num2);

    float num3 = 1.234567f;
    float num4 = 7.654321f;
    swapNumber(&num3,&num4,TYPE_FLOAT);
    printf("%f %f\n",num3, num4);

    return 0;
}

// 지금까지 함수에서 포인터 매개변수를 이용해서 정수, 실수 등의 값을 가져왔습니다. 그러면 일반적인 값 대신 포인터를 얻어오려면 어떻게 해야할까요?
// 먼저 함수에 포인터를 넘겨준 뒤 메모리를 할당해보겠습니다.
#include <stdio.h>
#include <stdlib.h>

void allocMemory(void *ptr,int size) // 반환값 없음, void 포인터 매개변수 지정 결국 메모리 누수가 발생 
{
    ptr = malloc(size); // ptr은 allocMemory를 벗어나면 사용할 수 없음
}

int main()
{
    long long *numPtr = NULL;
    allocMemory(numPtr,sizeof(long long));
    *numPtr = 10;
    printf("lld\n",*numPtr);
    free(numPtr);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void allocMemory(void **ptr,int size) // 반환값 없음, void 포인터 매개변수 지정
{
    *ptr = malloc(size); // void **ptr을 역참조하여 void *ptr에 메모리 할당
}

int main()
{
    long long *numPtr;

    // 단일 포인터 long long *numPtr의 메모리 주소는 long long **와 같음 할당할 크기도 넣음
    allocMemory((void **)&numPtr,sizeof(long long));

    *numPtr = 10;
    printf("lld\n",*numPtr);

    free(numPtr); // 동적 메모리 해제 

    return 0;
}

// 함수에서 매개변후로 문자열을 받으려면 다음과 같이 매개변수를 문자열 포인터로 지정하면 됩니다.
#include <stdio.h>
void helloString(char *s1); // 반환값 없음, char 포인터 매개변수 한개 지정
{
    printf("Hello, %s\n",s1); // hello, 와 매개변수를 조합하여 문자열 출력 
}

int main()
{
    helloString("world");

    return 0;
}

// 매개변수로 문자 배열을 받는다는 것은 확실히 해주려면 다음과 같이 매개변수 뒤에 [] (대괄호)를 붙여주면 됩니다.

#include <stdio.h>

void helloString(char s1[])
{
    printf("Hello, %s\n",s1);
}

int main()
{
    char s1[10] = "world";

    helloString(s1);
    helloString("world");

    return 0;
}

// 연습문제 
#include <stdio.h>

int getNumber(int* a, int* b)
{
    *a = 10;
    *b = 20;
    return 30;
}

int main()
{
    int num1 = 0;
    int num2 = 0;
    int result = 0;

    result = getNumber(&num1, &num2);

    printf("%d %d %d\n", num1, num2, result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void allocMatrix(void ***ptr, int m, int n, int elementSize)
{
    *ptr = malloc(sizeof(void *) * m); // *ptr을 역참조한 뒤 메모리 할당

    for(int i = 0; i < m; i++)
    {
        (*ptr)[i] = malloc(elementSize * n); // ptr을 먼저 역참조한 뒤 인덱스로 접근
    }
}

void freeMatrix(void ***ptr, int m)
{
    for (int i = 0; i < m; i++)
    {
        free((*ptr)[i]);
    }

    free(*ptr);
}

int main()
{
    short **matrix;  // 2중포인트 이므로 메모리를 할당해서 가져오려면 삼중포인트를 해야한다.

    allocMemory(&matrix, 3, 3, sizeof(short));

    matrix[0][2] = 10;
    matrix[1][1] = 20;
    printf("%d %d\n", matrix[0][2], matrix[1][1]);

    freeMatrix(&matrix, 3);

    return 0;
}

// 연습문제 3 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compareString (char *s1, char *s2)
{
    if (strcmp(s1,s2) == 0 )
        printf("같음");
    else 
        printf("다름");
}

int main()
{
    char *s1 = malloc(sizeof(char)* 10 );

    strcpy(s1, "Venus");

    compareString(s1, "Venus");

    free(s1);

    return 0;
}

// 심사문제 1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getQuotientAndRemainder(int a, int b, int* remainder)
{
    int quotient = a / b;
    *remainder = a % b;
    return quotient;
}

int main()
{
    int num1;
    int num2;
    int quotient;     // 몫
    int remainder;    // 나머지

    scanf("%d %d", &num1, &num2);

    quotient = getQuotientAndRemainder(num1, num2, &remainder);

    printf("%d %d\n", quotient, remainder);

    return 0;
}

// 심사문제  2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void allocArray(void** ptr, int a, int elementSize)
{
    *ptr = malloc(sizeof(elementSize));
}

int main()
{
    long long *numArr1;
    int *numArr2;

    allocArray((void **)&numArr1, 10, sizeof(long long));
    allocArray((void **)&numArr2, 3, sizeof(int));

    scanf("%lld %d", &numArr1[9], &numArr2[2]);
    printf("%lld %d\n", numArr1[9], numArr2[2]);

    free(numArr2);
    free(numArr1);

    return 0;
}

// 심사문제 3 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printFullName(char* familyName, char* givenName)
{
    printf("%c%c", familyName, givenName);
}
int main()
{
    char familyName[31];
    char givenName[31];

    scanf("%s %s", familyName, givenName);

    printFullName(familyName, givenName);

    return 0;
}