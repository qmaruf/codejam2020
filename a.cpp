#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int main()
{
    freopen("ain.txt", "r", stdin);
    freopen("aout.txt", "w", stdin);
    int n, m, ca = 1;
    int A[101][101];
    int a, b, c;
    cin>>n;
    while(n--)
    {
        cin>>m;
        a = b = c = 0;

        for (int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                cin>>A[i][j];

        for (int i = 0; i < m; i++){
            set<int> row, col;
            for(int j = 0; j < m; j++){
                row.insert(A[i][j]);
                col.insert(A[j][i]);
                if (i==j)
                    a+=A[i][j];
            }
            if (row.size() != m)
                b++;
            if (col.size() != m)
                c++;
        }
        printf("Case #%d: %d %d %d\n", ca, a, b, c);
        ca += 1;
    }
    return 0;
}