#include <stdio.h>

void hanoi_tower_no_stack(int n, char from, char tmp, char to) 
{
    // 기둥을 배열로 매핑 (0: 출발지, 1: 경유지, 2: 목적지)
    char pegs[3] = {from, tmp, to};
    
    // 전체 이동 횟수: 2^n - 1
    int total_moves = (1 << n) - 1;

    for (int i = 1; i <= total_moves; i++) 
    {
        // 1. 이번 턴에 움직일 원판 번호 구하기 (1번부터 시작)
        // 규칙: i를 이진수로 표현했을 때 오른쪽부터 연속된 0의 개수 + 1
        int disk = 1;
        int temp = i;
        while ((temp % 2) == 0) {
            disk++;
            temp /= 2;
        }

        // 2. 해당 원판이 지금까지 '몇 번' 이동했는지 계산
        // 규칙: 현재 단계(i)를 2의 disk 제곱으로 나눈 몫
        int moves_before = i >> disk; 

        // 3. 원판의 이동 방향 결정 (1: 순방향, 2: 역방향)
        // 짝수/홀수 규칙에 따라 원판마다 도는 방향이 다릅니다.
        int dir;
        if ((n % 2) == (disk % 2)) {
            dir = 2; // 역방향 (A -> C -> B -> A ...)
        } else {
            dir = 1; // 순방향 (A -> B -> C -> A ...)
        }

        // 4. 출발지와 도착지 기둥 인덱스 계산
        int from_idx = (moves_before * dir) % 3;
        int to_idx = ((moves_before + 1) * dir) % 3;

        printf("원판 %d 을 %c 에서 %c 으로 옮긴다.\n", disk, pegs[from_idx], pegs[to_idx]);
    }
}

int main(void) 
{
    hanoi_tower_no_stack(3, 'A', 'B', 'C');

    return 0;
}