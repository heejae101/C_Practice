
/* 배열은 이름 뒤에 [] (대괄호)를 붙인 뒤 크기를 설정합니다. 
그리고 배열을 선언하면서 값을 초기화할 때는 {} (중괄호)를 사용합니다.

자료형의 배열이름[크기];
자료형의 배열이름[크기] = {값,값,값}
*/

#include <stdio.h>

int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};

    printf("%d\n",numArr[0]);
    printf("%d\n",numArr[5]);
    printf("%d\n",numArr[9]);

    return 0;
}

/* 배열을 선언하면서 값을 초기화 할 때는 {} 안의 값 개수는 크기보다 작아도 되지만
크면 안된다. 또한 { }를 사용하여 배열에 값을 할당하는 방법은 배열을 선언할 때만 사용
가능 이미 선언된 배열에는 사용할 수 없습니다.

numArr[0]; 첫번째 요소 인덱스 0
numArr[5]; 여섯번째 요소 인덱스 5
numArr[9]; 열 번째 요소 인덱스 9

배열에 저장된 공간을 요소(element) 
각 요소에 접근하려면 배열 뒤에 [ ]를 사용하며 각요소의 인덱스를 지정해 주면된다.

배열을 선언,배열요소에 접근할때도 [ ]를 사용하는데 배열을 선언할 때에는 크기를 알 수 있고
배열을 사용할 때는 배열의 요소에 접근하겠다라는 뜻입니다.

배열 인덱스가 0으로 시작하는 이유는 메모리 주소가 0부터 시작하기 때문이다.
배열도 포인터이므로 인덱스가 0부터 시작하면 요소 접근과 포인터 연산이 일치하게 됩니다.

배열을 선언할 떄 값을 초기화 한다면 배열의 크기를 생략가능합니다.

int numArr1p[] = {11,22,33,44,221};
int numArr2[]; 오류 발생
*/

#include <stdio.h>

int main()
{
    int numArr[10] = {0, };

    printf("%d\n", numArr[0]);
    printf("%d\n", numArr[5]);
    printf("%d\n", numArr[9]);

    return 0;
}

// 배열 요소에 값 할당
#include <stdio.h>

int main()
{
    int numArr[10];

    numArr[0] = 11;
    numArr[5] = 22;
    numArr[9] = 33;

    printf("%d\n", numArr[0]);
    printf("%d\n", numArr[5]);
    printf("%d\n", numArr[9]);

    return 0;
}

// 만약 범위를 벗어난 인덱스에 접근하면? 쓰레기값 출력
int main()
{
    int numArr[10];

    numArr[0] = 11;
    numArr[5] = 22;
    numArr[9] = 33;

    printf("%d\n", numArr[0]);
    printf("%d\n", numArr[5]);
    printf("%d\n", numArr[9]);

    return 0;
}

//크기가 10인 배열의 요소를 모두 출력
int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};

    for (int i = 0; i < 10; i++)
    {
        printf("%d",i);
    }

    return 0;
}

// 이미 선언된 배열의 크기를 구하려면? 전체공간과 요소의 개수는 sizeof 연산자를 활용한다.

#include <stdio.h>

int main()
{
    int numArr[5] = {1,2,3,4,5};

    printf("%d\n",sizeof(numArr)); //4 바이트 배열 5개이므로 20 
    printf("%d\n",sizeof(numArr)/sizeof(int)); // 20/4= 5

    return 0;
}

// C 언어는 인덱스 배열의 범위를 벗어났는지 검사하지 않으므로 프로그래머가 항상 생각해야함
// 배열에 접근하기 전에 인덱스가 요수 개수 -1을 넘지 않는지 확인

#include <stdio.h>

int main()
{
    int numArr[10];
    int index = 10;
    int count = sizeof(numArr) / sizeof(int);

    if (index <= count - 1)
    {
           numArr[index] = 999;
    }
}

// 반복문을 사용해서 배열의 요소를 모두 출력
#include <stdio.h>

int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};

    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
    {
        printf("%d\n",numArr[i]);
    }

    return 0;
}

//역순으로 출력 

#include <stdio.h>

int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};

    for (int i = sizeof(numArr) / sizeof(int) - 1;i >= 0; i--)
    {
        printf("%d\n",numArr[i]);
    }

    return 0;
}

// 배열의 요소의 합 구하기

#include <stdio.h>

int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};
    int sum = 0;

    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
    {
        sum += numArr[i];
    }
    
    printf("%d\n",sum);

    return 0;
}

// 배열의 요소에 저장된 값을 두 배로 만들기

#include <stdio.h>

int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};

    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++)
    {
        numArr[i] *= 2;
        printf("%d\n",numArr[i]);
    }

    return 0;
}

/* 배열을 포인터에 넣기 배열은 사실 첫 번째 요소의 주솟값만 담고 있습니다.
배열은 주솟값이기 때문에 포인터에 넣을 수 있다. 따라서 다음과 같이 포인터에 배열을 넣은 뒤 포인터에서 
인덱스로 요소에 접근 가능 */

#include <stdio.h>

int main()
{
    int numArr[10] = {11,22,33,44,55,66,77,88,99,110};
    int *numPtr = numArr;

    printf("%d\n",*numPtr); // 11 배열의 주소가 들어가있는 포인터를 역참조하면 배열의 첫번째 요소

    printf("%d\n",*numArr); // 11 배열 자체를 역참조해도 배열의 첫번째 요소에 접근
 
    printf("%d\n",numPtr[5]); // 66 배열의 주소가 들어있는 포인터는 인덱스로 접근가능

    printf("%d\n",sizeof(numPtr)); // 4 sizeof로 배열의 주소가 들어있는 포인터 크기를 구하면 포인터의 크기가 됨

    printf("%d\n",sizeof(numArr)); // 40 sizeof로 배열의 크기를 구하면 배열이 메모리에 차지하는 공간이됨

    return 0;
}

//배열을 활용하여 10진수를 2진수로 변환하기

#include <stdio.h>

int main()
{
    int decimal = 13;
    int binary[20] = {0, };

    int position = 0;
    while (1)
    {
        binary[position] = decimal % 2;
        decimal = decimal/2;

        position++;

        if (decimal == 0)
            break;
    }

    for (int i = position -1; i >= 0; i--)
    {
        printf("\n");
    }

    return 0;
    
}

//연습문제 점수 평균 구하기

#include <stdio.h>

int main()
{
    float scores[10] = {67.2f,67.2f, 84.3f, 97.0f, 87.1f, 71.9f, 63.0f, 90.1f, 88.0f, 79.7f, 95.3f };
    float sum = 0.0f;
    float average;

    for (int i = 0; i < sizeof(scores)/sizeof(float); i++)
    {
        sum += scores[i];
    }
    average = sum / sizeof(scores)/sizeof(float);

    printf("%f\n",average);

    return 0;
}

// 연습문제 2진수를 10진수로 변환하기
#include <stdio.h>

int main()
{
    int decimal = 0;
    int binary[4] = {1,1,0,1};
    int position = 0;
    
    for (int i = sizeof(binary) / sizeof(int) - 1; i >= 0; i--)
    {
        if (binary[i] == 1)
            decimal +=1 << position;

        position++;
    }

    printf("%d\n",decimal);

    return 0;
}

/* 심사 문제 
표준 입력으로 정수 다섯 개가 입력됩니다(입력 값의 범위는 -2147483648~2147483647). 
다음 소스 코드를 완성하여 입력된 정수 중에서 가장 작은 수가 출력되게 만드세요.
정답에는 밑줄 친 부분에 들어갈 코드만 작성해야 합니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int numArr[5];
    int smallestNumber;

    scanf("%d %d %d %d %d", &numArr[0], &numArr[1], &numArr[2], &numArr[3], &numArr[4]);

    smallestNumber = numArr[0];

    for (int i = 0; i < sizeof(numArr)/sizeof(int); i++)
    {
        if (numArr[i] < smallestNumber)
        {
            smallestNumber = numArr[i];
        }
    }

    printf ("%d\n",smallestNumber);

    return 0;
}


