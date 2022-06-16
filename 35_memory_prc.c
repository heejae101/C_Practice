// malloc --> 사용 --> free
/* 메모리를 사용하려면 malloc 함수로 사용할 공간을 확보해야 합니다.(memory allocation). 
이때 메모리 크기는 바이트 단위로 지정합니다. (메모리 할당, 해제 함수는 stdlib.h 헤더 파일에 선언)
    포인터 = malloc(크기);
    void *malloc(size_t_Size);
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 20;
    int *numPtr1;

    numPtr1 = &num1;

    int *numPtr2;

    numPtr2 = malloc(sizeof(int));

    printf("%p\n",numPtr1);
    printf("%p\n",numPtr2);

    return 0; 

}
/* 메모리를 할당할 때는 malloc 함수를 사용하여 할당할 메모리 공간의 크기를 넣어줍니다.
여기서는 sizeof 연산자를 사용하여 int의 크기(4바이트) 만큼 메모리를 할당 했습니다. 
특히 원하는 시점에 원하는 만큼 메모리를 할당할 수 있다고 하여 동적 메모리 할당(dynamic memory allocation)이라고 합니다.

numPtr2 = malloc(sizeof(int)); // int의 크기 4바이트만큼 동적 메모리 할당

printf("%p\n", numPtr1);    // 006BFA60: 변수 num1의 메모리 주소 출력
                            // 컴퓨터마다, 실행할 때마다 달라짐

printf("%p\n", numPtr2);    // 009659F0: 새로 할당된 메모리의 주소 출력
                            // 컴퓨터마다, 실행할 때마다 달라짐

여기서 numPtr1에는 일반 변수의 메모리 주소를 할당했고, numPtr2에는 malloc 함수로 메모리를 할당했습니다.
같은 메모리 주소라도 내부적으로는 약간의 차이가 있습니다. 스택과 힙 두 가지인데 변수는 스택(stack)에 생성되며 malloc 함수는 힙(heap) 부분의 메모리를 사용합니다.

스택과 힙의 차이점은 메모리 해제입니다. 스택에 생성된 변수는 사용한 뒤 따로 처리를 하지않아도 되지만
malloc함수를 사용하여 힙에 메모리 할당한 것은 반드시 해제를 해줘야한다. 
해제는 free 함수로 메모리를 해제합니다.

free(numPtr2);

메모리 해제는 선택이 아닌 필수입니다.
메모리를 할당만 하고 해제를 해주지 않으면 결국에는 시스템의 메모리가 부족해지므로 운영체제가 프로그램을 강제로 종료시키거나 메모리 할당에 실패하게 됩니다.
특히 메모리를 해제하지 않아 메모리 사용량이 계속 증가하는 현상을 메모리 누수(memory leak)라 부릅니다.
*/

//메모리에 값 저장하기
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numPtr;

    numPtr = malloc(sizeof(int));

    *numPtr = 10;

    printf("%d\n",*numPtr);

    free(numPtr);

    return 0;
}

/* 참고 
다음과 같이 malloc 함수에 sizeof(int)* 1024 * 1024 * 1024);
numPtr2 = malloc(sizeof(int)) * 1024 * 1024 * 1024);

문제없이 할당은 되지만 계산을 해보면 4294967296입니다. 4GiB
더 큰 메모리도 할당 할 수 있지만 실제로 값을 저장할 때는 시스템의 한계를 저장할 수 없습니다.
*/


/*포인터를 역참조 한 뒤 값을 할당할 때는 자료형 크기만큼만 할당 할 수 있습니다.
memset 함수를 사용하면 메모리의 내용을 원하는 크기만큼 특정값으로 설정할 수 있으며 이름은 memoryset에서 따왔습니다.

memset(포인터, 설정할값, 크기);
    void*memset(void*_Dst,int_Val,size_t_Size);
    값 설정이 끝난 포인터를 반환
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long *numPtr = malloc(sizeof(long long));

    memset(numPtr, 0x27, 8);

    printf("0x%11x\n",*numPtr); //0x2727272727272727

    free(numPtr);

    return 0;
}

/* memset 함수를 사용하려면 string.h memory.h 헤더 파일을 포함해야한다.
memset 함수에 포인터, 설정할 값, 설정할 크기를 넣으면 된다.
여기서는 memset(numPtr, 0x27, 8); numPtr이 가르키는 메모리에는 16진수 27이 8개 들어가게 됩니다.
*/
