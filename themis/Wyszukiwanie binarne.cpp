#include <bits/stdc++.h>

using namespace std;

int n, m, x;
int tab[1000'006];

int binsearch(int x)
{
    int l = -1, r = n;

    while (r - l > 1)
    {
        int s = (l + r) / 2;

        if (tab[s] < x)
            l = s;
        else
            r = s;
    }

    return n - r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tab[i];

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cout << binsearch(x) << " ";
    }

    return 0;
}