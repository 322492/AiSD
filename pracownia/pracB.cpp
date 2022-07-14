#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

int n, m, t;
int a1, b1, a2, b2;
const long long mod = 999979;
vector<pair<int, int>> format;
vector<pair<pair<int, int>, pair<int, int>>> wej;
vector<int> graf[1'000'006];
long long dp[1'000'006];

int FIND(pair<int, int> x) // zwraca jakÄ liczbÄ jest liczba x po przeformatowaniu
{
    int a = 0;
    int b = format.size();
    int c;

    while (b - a != 1)
    {
        c = (a + b) / 2;

        if (format[c] > x)
            b = c;
        else
            a = c;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t;
    format.push_back({0, 0});
    format.push_back({n, m});

    for (int i = 0; i < t; i++)
    {
        cin >> a1 >> b1 >> a2 >> b2;
        wej.push_back({{a1, b1}, {a2, b2}});
        format.push_back({a1, b1});
        format.push_back({a2, b2});
    }

    sort(format.begin(), format.end());
    format.resize(unique(format.begin(), format.end()) - format.begin()); // funckje zwracajÄ mi wektor wartoÅci bez powtÃ³rzeÅ posortowany rosnÄco

    for (int i = 0; i < t; i++) // robienie grafu
        graf[FIND(wej[i].f)].push_back(FIND(wej[i].s));

    dp[0] = 1;
    for (int i = 0; i < format.size(); i++)
        for (int j = 0; j < graf[i].size(); j++)
            dp[graf[i][j]] = (dp[graf[i][j]] + dp[i]) % mod;

    cout << dp[format.size() - 1];

    return 0;
}