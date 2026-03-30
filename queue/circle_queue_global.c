#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

// 데이터 타입을 typedef로 설정하여 수정 용이하게 함.
typedef int element;

// 1. 구조체로 큐 메모리 및 위치 변수 선언
element data[MAX_SIZE];
// 데이터가 나가는 쪽(삭제)의 인덱스를 가리킴
int front;
// 데이터가 들어오는 쪽(삽입)의 마지막 인덱스를 가리킴
int rear;


// 1. 큐 초기화 함수
void init()
{
    front = 0;   // 인덱스를 0으로 초기화
    rear = 0;
}

// 2. 큐 상태 확인 함수
int is_empty()
{
    // front와 rear가 같으면 큐가 비어있는 것입니다.
    return (front == rear);
}

int is_full()
{
    // rear의 인덱스가 front의 바로 뒤에 있다면 가득 차있는 것입니다.
    return (front == (rear + 1) % MAX_SIZE);
}

// 3. 데이터 삽입 함수 (Enqueue)
void enqueue(element item)
{
    if (is_full())
    {
        fprintf(stderr, "큐 포화 에러\n");
    }
    // rear를 1 증가시킨 후, 그 자리에 데이터를 넣습니다.
    else
    {
        rear = (rear + 1) % MAX_SIZE;
        data[rear] = item;
    }
}

// 4. 데이터 추출 함수 (Dequeue)
element dequeue()
{
    if (is_empty())
    {
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    // 해당 인덱스의 데이터를 반환하고 front를 1 증가시킨다.
    else
    {
        front = (front + 1) % MAX_SIZE;
        return data[front];
    }
}

// 5. 데이터 확인 함수 (Peek)
element peek()
{
    if (is_empty())
    {
        fprintf(stderr, "큐 공백 에러\n");
        exit(1);
    }
    // 데이터를 빼지 않으므로 front 변수를 증가시키지 않고 값만 읽어옵니다.
    else
    {
        return data[(front + 1) % MAX_SIZE];
    }
}

int main()
{

    // 큐 초기화.
    init();

    // 데이터 삽입 (FIFO: 10 -> 20 -> 30 순서로 줄을 섬)
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // 데이터 추출 (FIFO: 대기줄에 가장 먼저 선 10부터 출력됨)
    printf("%d\n", peek());    // 10 출력
    printf("%d\n", dequeue()); // 10 출력
    printf("%d\n", dequeue()); // 20 출력
    printf("%d\n", dequeue()); // 30 출력

    enqueue(10);
    printf("%d\n", peek());    // 10 출력
    printf("%d\n", dequeue()); // 10 출력

    return 0;
} 