#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;

// 1. 전역 변수로 큐 메모리 및 위치 변수 선언
element data[MAX_SIZE];
int front = -1; // 데이터가 나가는 쪽(삭제)의 인덱스를 가리킴
int rear = -1;  // 데이터가 들어오는 쪽(삽입)의 마지막 인덱스를 가리킴

// 2. 큐 상태 확인 함수
int is_empty()
{
    // 들어온 횟수(rear)와 나간 횟수(front)가 같으면 큐가 비어있는 것입니다.
    return (front == rear);
}

int is_full()
{
    // rear가 배열의 맨 끝(MAX_SIZE - 1)에 도달하면 가득 찬 것입니다.
    return (rear == MAX_SIZE - 1);
}

// 3. 데이터 삽입 함수 (Enqueue)
void enqueue(element item)
{
    if (is_full()) 
    {
        fprintf(stderr, "큐 포화 에러\n");
    }
    else 
    {
        // rear를 1 증가시킨 후, 그 자리에 데이터를 넣습니다.
        data[++rear] = item;
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
    else 
    {
        // front를 1 증가시킨 후, 그 자리의 데이터를 반환합니다.
        return data[++front];
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
    else 
    {
        // 데이터를 빼지 않으므로 front 변수를 증가시키지 않고 값만 읽어옵니다.
        // front는 '마지막으로 꺼낸 위치'를 가리키므로, 다음 꺼낼 데이터는 front + 1에 있습니다.
        return data[front + 1];
    }
}

int main()
{
    // 데이터 삽입 (FIFO: 10 -> 20 -> 30 순서로 줄을 섬)
    enqueue(10);
    enqueue(20);
    enqueue(30);

    // 데이터 추출 (FIFO: 대기줄에 가장 먼저 선 10부터 출력됨)
    printf("%d\n", peek()); // 10 출력
    printf("%d\n", dequeue()); // 10 출력
    printf("%d\n", dequeue()); // 20 출력
    printf("%d\n", dequeue()); // 30 출력

    return 0;
}