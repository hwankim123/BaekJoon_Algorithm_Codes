#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 51
#define MAXM 10001

int N, M;
int crain[MAXN], box[MAXM];
bool visited[MAXM];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> crain[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> box[i];
    }
    sort(crain, crain + N, greater<int>());
    sort(box, box + M, greater<int>());
    if (crain[0] < box[0])
    {
        cout << -1;
        return 0;
    }
    int count = 0;
    int startBox = 0;
    int pickUpCnt = 0;
    while (pickUpCnt < M)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = startBox; j < M; j++)
            {
                if (!visited[j] && box[j] <= crain[i])
                {
                    visited[j] = true;
                    pickUpCnt++;
                    if (startBox == j)
                        startBox++;
                    break;
                }
            }
        }
        count++;
    }

    cout << count;
}