#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

const int MAX = 5 * 100'000;
int d, n, a, b;
bool res;
string k1, k2;
pair<int, int> c1, c2;
vector<int> T1[MAX + 3]; //drzewo 1
vector<int> T2[MAX + 3]; //drzewo 2

void reset()
{
    for (int i = 1; i <= n; i++)
    {
        T1[i].clear();
        T2[i].clear();
    }
    c1 = {0, 0};
    c2 = {0, 0};
    res = 0;
}

void wczytaj()
{
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        T1[a].push_back(b);
        T1[b].push_back(a);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        T2[a].push_back(b);
        T2[b].push_back(a);
    }
    return;
}

pair<int, int> centrum(int np)
{
    int deg[MAX + 3];
    queue<int> kol;
    int zost = n;

    if (np == 1)
        for (int i = 1; i <= n; i++)
        {
            deg[i] = T1[i].size();
            if (deg[i] == 1)
                kol.push(i);
        }

    if (np == 2)
        for (int i = 1; i <= n; i++)
        {
            deg[i] = T2[i].size();
            if (deg[i] == 1)
                kol.push(i);
        }
    kol.push(0);

    while (zost > 2)
    {
        while ((a = kol.front()) != 0)
        {
            kol.pop();
            zost--;
            if (np == 1)
                for (auto v : T1[a])
                {
                    deg[v]--;
                    if (deg[v] == 1)
                        kol.push(v);
                }
            if (np == 2)
                for (auto v : T2[a])
                {
                    deg[v]--;
                    if (deg[v] == 1)
                        kol.push(v);
                }
        }
        kol.pop();
        kol.push(0);
    }

    a = kol.front();
    kol.pop();
    b = kol.front();
    kol.pop();

    return {a, b};
}

string koduj(int v, int np, int par)
{
    vector<string> wek;

    if (np == 1) // drzewo T1
    {
        for (auto u : T1[v])
            if (u != par)
                wek.push_back(koduj(u, 1, v));
    }
    if (np == 2) // drzewo T2
    {
        for (auto u : T2[v])
            if (u != par)
                wek.push_back(koduj(u, 2, v));
    }

    sort(wek.begin(), wek.end());
    string k = "";
    for (int i = 0; i < wek.size(); i++)
        k += wek[i];
    k = "(" + k + ")";
    return k;
}

bool check(int r1, int r2)
{
    k1 = koduj(r1, 1, 0);
    k2 = koduj(r2, 2, 0);
    return k1 == k2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d; //liczba przypadkow testowych

    while (d > 0)
    {
        cin >> n; //liczba wierzcholkow w drzewach
        reset();
        wczytaj();
        c1 = centrum(1);
        c2 = centrum(2);

        if (c1.s == 0 && c2.s == 0)
            res = check(c1.f, c2.f);
        else if (c1.s != 0 && c2.s != 0)
            res = (check(c1.f, c2.f) || check(c1.f, c2.s));

        if (res)
            cout << "TAK\n";
        else
            cout << "NIE\n";

        d--;
    }

    return 0;
}