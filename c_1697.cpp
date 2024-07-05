#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int check = 9999999;

void bfs(int n, int k);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    
    bfs(n, k);
    
    cout << check << endl;
    return 0;
}

void bfs(int start, int target)
{
    queue<pair<int, int> > q; // 큐: pair(현재 위치, 이동 횟수)
    vector<bool> visited(100001, false); // 방문 확인 배열, n, k <= 100000 가정

    q.push(make_pair(start, 0));
    visited[start] = true;

    while (!q.empty())
    {
        pair<int, int> current_pair = q.front();
        int current = current_pair.first;
        int count = current_pair.second;
        q.pop();

        if (current == target)
        {
            check = min(check, count);
            continue;
        }

        if (current - 1 >= 0 && !visited[current - 1])
        {
            q.push(make_pair(current - 1, count + 1));
            visited[current - 1] = true;
        }

        if (current + 1 <= 100000 && !visited[current + 1])
        {
            q.push(make_pair(current + 1, count + 1));
            visited[current + 1] = true;
        }

        if (current * 2 <= 100000 && !visited[current * 2])
        {
            q.push(make_pair(current * 2, count + 1));
            visited[current * 2] = true;
        }
    }
}




/*
숨바꼭질 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	128 MB	253098	74655	47400	25.926%
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

예제 입력 1 
5 17
예제 출력 1 
4
*/