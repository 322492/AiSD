#include <bits/stdc++.h>

using namespace std;

int n, m, res = 0;
string tab[2005];
queue<tuple<int, pair<int, int>, char>> kol;

bool czy_gorna(char a, char b)
{
    return ((a == 'C' || a == 'D' || a == 'F') && (b == 'B' || b == 'E' || b == 'F'));
}
bool czy_dolna(char a, char b)
{
    return ((a == 'B' || a == 'E' || a == 'F') && (b == 'C' || b == 'D' || b == 'F'));
}
bool czy_lewa(char a, char b)
{
    return ((a == 'B' || a == 'C' || a == 'F') && (b == 'D' || b == 'E' || b == 'F'));
}
bool czy_prawa(char a, char b)
{
    return ((a == 'D' || a == 'E' || a == 'F') && (b == 'B' || b == 'C' || b == 'F'));
}

void fun()
{
    while (!kol.empty())
    {
        auto p = kol.front();
        kol.pop();
        int prz = get<0>(p);
        pair<int, int> akt = get<1>(p);
        char c = get<2>(p);
        int i = akt.first;
        int j = akt.second;

        if (prz != 1 && i > 0 && tab[i - 1][j] != 'A' && czy_gorna(c, tab[i - 1][j]))
        {
            kol.push({3, {i - 1, j}, tab[i - 1][j]});
            tab[i - 1][j] = 'A';
        }

        if (prz != 3 && i < n - 1 && tab[i + 1][j] != 'A' && czy_dolna(c, tab[i + 1][j]))
        {
            kol.push({1, {i + 1, j}, tab[i + 1][j]});
            tab[i + 1][j] = 'A';
        }

        if (prz != 2 && j < m - 1 && tab[i][j + 1] != 'A' && czy_prawa(c, tab[i][j + 1]))
        {
            kol.push({4, {i, j + 1}, tab[i][j + 1]});
            tab[i][j + 1] = 'A';
        }

        if (prz != 4 && j > 0 && tab[i][j - 1] != 'A' && czy_lewa(c, tab[i][j - 1]))
        {
            kol.push({2, {i, j - 1}, tab[i][j - 1]});
            tab[i][j - 1] = 'A';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> tab[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tab[i][j] != 'A')
            {
                res++;
                kol.push({0, {i, j}, tab[i][j]});
                tab[i][j] = 'A';
                fun();
            }

    cout << res;

    return 0;
}