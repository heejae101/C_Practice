// sizeof 구조체의 크기
struct Data
{
    char mode;
    int count;
};

// 8 바이트를 출력 z가장 큰 자료형 크기의 배수로 정렬하므로 

struct Data
{
    char flags;
    int seq;
}

// 구조체의 순서는 맴버뒤에 항상 패딩을 넣으며 맴버의 순서를 바꾸지 않습니다.
// 따라서 구조체 data는 1,3(패딩),4입니다.

// cpu 비트수에 맞게 최적화 하는 방법이 있나여?
// char만 모여있거나 short만 모여있는 구조체는 일부러 int나 longlong 맴버를 넣어서 cpu를 최적화를 하기도함
struct Data
{
    char mode;
    char count;
    int alignment;
};

//마찬가지로 short만 모여있는 구조체에 long long 맴버를 넣으면 8바이트 단위로 정렬되므로 64비트 cpu에 최적화 됩니다.

struct Data
{
    short mode;
    short count;
    long long alignment;
};

// size_t 자료형은 무엇인가요?
// size_t은 부호없는 정수 자ㅏ료형인데 sizeof 연산자나 offsetof 매크로의 결과가 size_t입니다.

#include <stdio.h>
#include <stddef.h>

struct Data
{
    char mode;
    int count;
};

int main()
{
    size_t size = sizeof(int);
    size_t offset = offsetof(struct Data, count);

    printf("%zd %zd\n",size,offset);

    return 0;
}

// size_t형 변수를 출력할 때는 서식 지정자에 z를 붙입니다. 