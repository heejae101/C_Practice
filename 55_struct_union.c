// 구조체와 공용체를 단독으로 사용했습니다. 하지만 구조체안에 구조체와 공용체가 들어갈 수 있고,
// 반대로 공용체 안에 구조체와 공용체가 들어갈 수도 있습니다. 

#include <stdio.h>

struct Phone
{
    int areacode;
    unsigned long long number;
};

struct Person
{
    char name[20];
    int age;
    struct Phone phone; //구조체 맴버로 가지려면 다음과 같이 구조체안에 구조체변수를 선언
};

int main()
{
    struct Person p1;  

    p1.phone.areacode =82; //맴버에 접근할 때는 . 을 사용하며 가지고 있는 구조체에 계층적으로 접근 
    p1.phone.number = 3045671234;

    printf("%d %llu\n",p1.phone.areacode, p1.phone.number);

    return 0;
}

// Phone 구조체를 Person 보다 나중에 쓴다면 즉 지금은 phone->person이지만 person->phone 이라면 에러 메세지가 나온다. 
// 구조체 안에 구조체가 변수로 들어갈 때는 안에 들어가는 구조체를 먼저 선언해 줍니다.

struct Person
{
    char name[20];
    int age;
    struct Phone
    {
        int areacode;
        unsigned long long number;
    }phone;
};

// 구조체 변수를 선언하는 동시에 초기화하기
// 구조체 변수를 선언하면서 안에 들어있는 구조체까지 초기화하려면 {} 안에 중괄호를 사용합니다.

#include <stdio.h>

struct Phone
{
    int areacode;
    unsigned long long number;
};

struct Person
{
    char name[20];
    int age;
    struct Phone phone;
};

int main()
{
    struct Person p1 = {.name = "Andrew",.age = 25, {.areacode =82,.number = 3045671234}};
    printf("%d %llu\n", p1.phone.areacode, p1.phone.number);

    struct Person p2 = {"Maria",19,{82,3087654321}};
    printf("%d %llu\n",p2.phone.areacode, p2.phone.number);

    return 0;
}

// 구조체 안에 구조체 맴버에 메모리를 할당

#include <stdio.h>
#include <stdlib.h> // malloc , free 함수가 선언된 헤더  파일

struct Phone
{
    int areacode;
    unsigned long long number;
};

struct Person
{
    char name[20];
    int age;
    struct Phone phone;
};

int main()
{
    struct Person *p1 = malloc(sizeof(struct Person)); //사람구조체 포인터에 메모리 할당 
    p1 ->phone.areacode =82;                           //포인터-> 맴버.맴버 순으로 접근하여 값 할당
    p1 ->phone.number = 3045671234;                    //포인터 -> 맴버.맴버 순으로 접근하여 값 할당

    printf("%d %llu\n",p1->phone.areacode, p1->phone.number); //82,32045671234

    free(p1);       //동적메모리 해제

    return 0;
}

/* p1은 포인터이므로 ->(화살표연산자)를 사용하여 멤버에 접근합니다. 하지만 phone은 포인터가 아닌 일반변수이므로
.점을 사용하여 멤버에게 접근합니다. 포인터->맴버.맴버 모양이죠
*/

#include <stdio.h>
#include <stdlib.h>

struct Phone
{
    int areacode;
    unsigned long long number;
};

struct Person
{
    char name[20];
    int age;
    struct Phone *phone;
};

int main()
{
    struct Person *p1 = malloc(sizeof(struct Person)); // 바깥 구조체의 포인터에 메모리 할당
    p1->phone = malloc(sizeof(struct Phone)); //맴버 포인터에 메모리 할당

    p1->phone->areacode = 82;   //포인터->포인터->맴버 순으로 접근하여 값 할당
    p1->phone->number = 3045671234; // 포인터->포인터->맴버 순으로 접근하여 값할당

    printf("%d %llu\n", p1->phone->areacode, p1->phone->number);

    free(p1->phone); // 구조체 포인터사용이 끝났으면 메모리 해제해야 하는데 반드시 안쪽에 있는 맴버부터 해제
    free(p1); // 구조체 메모리 해제

    // 바깥에 있는 구조체 포인터를 먼저 해제하면 데이터가 사라지므로 안에 있는 맴버에 더이상 접근 불가입니다. 
    // 그래서 맴버 포인터에 저장된 주소도 알 수 없으므로 해제 할 수 없습니다. 
    // 맴버 포인터의 주소를 미리 다른곳에 저장해 두었다면 바같에 있는 구조체 포인터를 해제해도 됩니다.
    return 0;
}

// 구조체 정의 순서
/* 구조체를 Phone -> Person 순서가 아니라 Person -> phone 순서로 정의하면 문제가 있다. 
struct Phone; 전방선언(forward declaration)을 사용하면 정의되지 않은 구조체를 먼저 사용할 수 있습니다.

struct Person
{
    char name[20];
    int age;
    struct Phone *phone;
};

struct Phone
{
    int areacode;
    unsigned long long number;
}
*/

#include <stdio.h>

struct Vetor3
{
    union 
    {
        struct 
        {
            float x;
            float y;
            float z;
        };
        float v[3];     // float x,y,z는 변수 3개이고 v[3]은 배열의 요소가 3개입니다. 따라서 공용체로 묶어주면 x,y,z와 v[3]는 같은공간을 공유합니다.
    };
    
};


int main()
{
    struct Vector3 pos;

    for (int i=0;i < 3; i++)
    {
        pos.v[i]=1.0f;
    }

    printf("%f %f %f \n",pos.x,pos.y,pos.z);

    return 0;
}

