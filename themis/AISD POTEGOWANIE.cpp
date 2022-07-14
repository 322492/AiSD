#include <bits/stdc++.h>

using namespace std;

long long pow(long long a, long long b, long long m)
{
    long long aux = 1;
    if (b == 0)
        return 1ll;
    if (b % 2 == 1)
        return (a * pow(a, b - 1, m)) % m;
    aux = pow(a, b / 2, m);
    return (aux * aux) % m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long t, a, b, m;
    cin >> t;

    while (t > 0)
    {
        cin >> a >> b >> m;
        cout << pow(a, b, m) << "\n";
        t--;
    }

    return 0;
}