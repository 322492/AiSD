#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

const int MAX = 2 * 1'000'000 + 2;
int n;
char wej[MAX][3];
bool blocked[MAX][3];
int ile[MAX][3];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> kol; //{ile pol zablokuje, {x, y}}
int wyn = 0;

bool in(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < 3;
}

void zlicz(int x, int y)
{
    int cnt = 0;
    if (wej[x][y] != '.')
        return;
    if (in(x - 1, y - 2) && wej[x - 1][y - 2] == '.')
        cnt++;
    if (in(x - 1, y + 2) && wej[x - 1][y + 2] == '.')
        cnt++;
    if (in(x - 2, y - 1) && wej[x - 2][y - 1] == '.')
        cnt++;
    if (in(x - 2, y + 1) && wej[x - 2][y + 1] == '.')
        cnt++;
    if (in(x + 1, y - 2) && wej[x + 1][y - 2] == '.')
        cnt++;
    if (in(x + 1, y + 2) && wej[x + 1][y + 2] == '.')
        cnt++;
    if (in(x + 2, y - 1) && wej[x + 2][y - 1] == '.')
        cnt++;
    if (in(x + 2, y + 1) && wej[x + 2][y + 1] == '.')
        cnt++;

    kol.push({cnt, {x, y}});
    ile[x][y] = cnt;
    return;
}

void przelicz(int x, int y)
{
    if (in(x - 1, y - 2) && !blocked[x - 1][y - 2])
    {
        ile[x - 1][y - 2]--;
        kol.push({ile[x - 1][y - 2], {x - 1, y - 2}});
    }
    if (in(x - 1, y + 2) && !blocked[x - 1][y + 2])
    {
        ile[x - 1][y + 2]--;
        kol.push({ile[x - 1][y + 2], {x - 1, y + 2}});
    }
    if (in(x - 2, y - 1) && !blocked[x - 2][y - 1])
    {
        ile[x - 2][y - 1]--;
        kol.push({ile[x - 2][y - 1], {x - 2, y - 1}});
    }
    if (in(x - 2, y + 1) && !blocked[x - 2][y + 1])
    {
        ile[x - 2][y + 1]--;
        kol.push({ile[x - 2][y + 1], {x - 2, y + 1}});
    }
    if (in(x + 1, y - 2) && !blocked[x + 1][y - 2])
    {
        ile[x + 1][y - 2]--;
        kol.push({ile[x + 1][y - 2], {x + 1, y - 2}});
    }
    if (in(x + 1, y + 2) && !blocked[x + 1][y + 2])
    {
        ile[x + 1][y + 2]--;
        kol.push({ile[x + 1][y + 2], {x + 1, y + 2}});
    }
    if (in(x + 2, y - 1) && !blocked[x + 2][y - 1])
    {
        ile[x + 2][y - 1]--;
        kol.push({ile[x + 2][y - 1], {x + 2, y - 1}});
    }
    if (in(x + 2, y + 1) && !blocked[x + 2][y + 1])
    {
        ile[x + 2][y + 1]--;
        kol.push({ile[x + 2][y + 1], {x + 2, y + 1}});
    }

    return;
}

void zablokuj(int x, int y)
{
    if (in(x - 1, y - 2) && wej[x - 1][y - 2] == '.')
    {
        if (!blocked[x - 1][y - 2])
            przelicz(x - 1, y - 2);
        blocked[x - 1][y - 2] = 1;
    }

    if (in(x - 1, y + 2) && wej[x - 1][y + 2] == '.')
    {
        if (!blocked[x - 1][y + 2])
            przelicz(x - 1, y + 2);
        blocked[x - 1][y + 2] = 1;
    }
    if (in(x - 2, y - 1) && wej[x - 2][y - 1] == '.')
    {
        if (!blocked[x - 2][y - 1])
            przelicz(x - 2, y - 1);
        blocked[x - 2][y - 1] = 1;
    }
    if (in(x - 2, y + 1) && wej[x - 2][y + 1] == '.')
    {
        if (!blocked[x - 2][y + 1])
            przelicz(x - 2, y + 1);
        blocked[x - 2][y + 1] = 1;
    }
    if (in(x + 1, y - 2) && wej[x + 1][y - 2] == '.')
    {
        if (!blocked[x + 1][y - 2])
            przelicz(x + 1, y - 2);
        blocked[x + 1][y - 2] = 1;
    }
    if (in(x + 1, y + 2) && wej[x + 1][y + 2] == '.')
    {
        if (!blocked[x + 1][y + 2])
            przelicz(x + 1, y + 2);
        blocked[x + 1][y + 2] = 1;
    }
    if (in(x + 2, y - 1) && wej[x + 2][y - 1] == '.')
    {
        if (!blocked[x + 2][y - 1])
            przelicz(x + 2, y - 1);
        blocked[x + 2][y - 1] = 1;
    }
    if (in(x + 2, y + 1) && wej[x + 2][y + 1] == '.')
    {
        if (!blocked[x + 2][y + 1])
            przelicz(x + 2, y + 1);
        blocked[x + 2][y + 1] = 1;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> wej[i][0] >> wej[i][1] >> wej[i][2];

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 2; j++)
        {
            if (wej[i][j] == '.')
                zlicz(i, j);
            else
                blocked[i][j] = 1;
        }

    while (!kol.empty())
    {
        auto pp = kol.top();
        kol.pop();
        auto p = pp.s;
        if (!blocked[p.f][p.s])
        {
            blocked[p.f][p.s] = 1;
            wej[p.f][p.s] = 'S';
            wyn++;
            zablokuj(p.f, p.s);
        }
    }

    cout << wyn << "\n";
    for (int i = 0; i < n; i++)
        cout << wej[i][0] << wej[i][1] << wej[i][2] << "\n";

    return 0;
}