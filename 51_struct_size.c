/* 이번에는 구조체가 메모리에 올라갔을 때 멤버를 정렬(alignment)하는 기능
컴퓨터에서 cpu가 메모리에 접근할 때 32비트 cpu는 4바이트 단위, 64비트는 8바이트 단위로 접근합니다.
만약 32비트 cpu에서 4바이트보다 작은 데이터에 접근할 경우 내부적으로 시프트 연산이 발생해서 효율이 떨어집니다.
그래서 c언어 컴파일러는 CPU가 메모리의 데이터에 효율적으로 접근할 수 있도록 구조체를 일정한 크기로 정렬하게 됩니다.

하지만 구조체 맴버를 정렬하면 안되는 경우가 있습니다. 
사진같은 파일 을 저장할때마다 정렬이 일어나면 깨지는 현상이 일어나고 네트워크로 데이터를 전송할 때
몇 바이트씩 어떤 순서로 보낼지 규약을 정해 놓았습니다. 이때 정렬이 발생해버리면 정해놓은 규약에서 벗어나게 되므로 
받는쪽에서 데이터를 알아볼 수 없습니다.

구조체를 정렬하기 전에 먼저 구조체의 크기 부터 알아봅니다.

sizeof(struct 구조체)
sizeof(구조체 별칭)
sizeof(구조체 변수)
sizeof 구조체 변수

*/
#include <stdio.h>

struct PacketHeader
{
    char flags;
    int seq;
};

int main()
{
    struct PacketHeader header;

    printf("%d\n",sizeof(header.flags));
    printf("%d\n",sizeof(header.seq));
    printf("%d\n",sizeof(header));
    printf("%d\n",sizeof(struct PacketHeader));

    return 0;
    
}

// PecketHeader 구조체 안에는 1바이트 크기의 char와 4바이트 크기의 int가 들어있어 전체크기는 5바이트가 나와야할 것같은데 8바이트가 나옵니다.

/* c 언어에서는 구조체를 정렬할 때 멤버 중에서 가장 큰 자료형 크기의 배수로 정렬합니다. 여기서 가장 큰 자료형은 int 형이므로 4바이트 기준으로 정렬합니다.
1바이트 크기의 char flags 뒤에는 4바이트를 맞추기 위해 남는 공간 3바이트가 더 들어갑니다. 이렇게 구조체를 정렬할 때 남는 공간을 채우는 것을 패딩(padding)이라고 합니다.
*/

// 정말 구조체를 정렬한 뒤 멤버의 위치가 설정되었는지 확인합니다. 구조체에서 맴버의 위치(offset)을 구할 때는 offsetof 매크로를 사용합니다.(stddef.h 헤더파일에 정의되어있습니다.)

#include <stdio.h>
#include <stddef.h>

struct PacketHeader
{
    char flags;
    int seq;
};

int main()
{
    printf("%d\n",offsetof(struct PacketHeader, flags));
    printf("%d\n",offsetof(struct PacketHeader, seq));

    return 0;
}

//결과 0 4

/* 데이터 전송이나 저장할 때 구조체 정렬을 피하려면 어떻게 해야 할까요? 그런데 C언어에서는 구조체를 정렬하는 표준 방법이 없습니다.
각 컴파일러 에서 제동하는 특별한 지시자를 사용하면 구조체 정렬 크기를 조정할 수 있습니다.

visual studio, GCC 4.0 이상
#pragma pack(push, 정렬의 크기)
#pragma pack(pop)

GCC 4.0 미만
__attribute__((aligned(정렬 크기), packed))
*/

#include <stdio.h>

#pragma pack(push, 1) // 1바이트 단위로 정렬하게 되므로 남은공간 없이 자료형 크기 그대로 메모리에 올라갑니다.
struct PacketHeader
{
    char flags;
    int seq;
};
#pragma pack(pop) // #pragma pack(push, 1)을 한번 사용하면 그 아래에 오는 구조체에 영향을 주므로 정렬설정뒤에는 pragma pack (pop)을 사용하여 이전상태로 되돌립니다.

int main()
{
    struct PacketHeader header;

    printf("%d\n",sizeof(header.flags));
    printf("%d\n",sizeof(header.seq));
    printf("%d\n",sizeof(header));

    return 0;
    
}

//결과 1 4 5

// #pragma pack (push, 1), __attribute__((aligned(1)), packed)) 에는 1이외에도 2,4,8,16 도 지정할 수 있습니다.
// 이 상태에서 8, 16바이트로 구조체를 정렬하더라도 구조체의 크기는 8이 나올 것입니다. 왜냐하면 구조체 안에서 가장 큰 자료형의 크기(4)보다 정렬 설정 크기(8, 16)가 크기 때문입니다. 보통 #pragma pack(push, 1)을 주로 사용하므로 신경 쓰지 않아도 됩니다.

// 연습문제

#include <stdio.h>

struct CompressHeader
{
    char flags;
    int version;
};

int main()
{
    struct CompressHeader header;
    printf("%d\n",sizeof(header));

    return 0;
}

//실행 결과 8

//연습문제 패킷 크기 조절하기 
#include <stdio.h>

#pragma pack (push, 1)
struct Packet
{
    short length;
    int seq;
};
#pragma pack(pop)

int main()
{
    struct Packet pkt;
    printf("%d\n",sizeof(pkt));
    return 0;
    
}

//심사문제
#include <stdio.h>

struct EncryptionHeader
{
    char flags; // 1바이트 이므로 12바이트면 4비트 2개만있으면댐 제한하는게 없으므로 

};

int main()
{
    struct EncryptionHeader header;
    printf("%d\n",sizeof(header));

    return 0;
}

#include <stdio.h>

int main()
{
    struct Packet pkt;

    printf("%d\n", sizeof(pkt));

    return 0;
}

