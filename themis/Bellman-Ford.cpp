#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

int n, m, start;
const long long INF = 9 * 1e18;
vector<pair<int, int>> graf[503];
long long dist[503];

bool relax()
{
    bool any = false;

    for (int i = 0; i <= n; i++)
        for (auto p : graf[i])
            if (dist[i] < INF) //aby nie zmieniac dist dla wierzcholkow jeszcze nieosiagalnych
                if (dist[p.f] > dist[i] + p.s)
                {
                    dist[p.f] = dist[i] + p.s;
                    any = true;
                }

    return any;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> start;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graf[a].push_back({b, c});
    }

    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    dist[start] = 0;

    bool czy = 0;
    for (int i = 0; i <= n; i++)
        czy = relax();

    //sprawdzenie czy wystepuje cykl ujemny - tak jesli przy n-tej relaksacji sie cos zmieni
    czy = relax();
    if (czy) //cykl ujemny
    {
        cout << "NIE";
        return 0;
    }

    for (int i = 0; i <= n; i++)
    {
        if (i != start && dist[i] != INF)
            cout << i << " " << dist[i] << "\n";
    }

    return 0;
}