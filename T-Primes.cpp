#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void sieveoferatosthene(lli num, vector<bool> &prime)
{
    prime[0] = false;
    prime[1] = false;
    for (lli p = 2; p * p <= num; p++)
    {
        if (prime[p] == true)
        {
            for (lli i = p * p; i <= num; i += p)
            {
                prime[i] = false;
            }
        }
    }
}
int main()
{
    lli num = 1000000;
    vector<bool> prime(num + 1, true);
    sieveoferatosthene(num, prime);

    vector<lli> p;
    for (lli i = 0; i < prime.size(); i++)
    {
        if (prime[i] == true)
        {
            p.push_back(i);
        }
    }

    unordered_set<int> myset;

    // for (lli i = 0; i < p.size(); i++)
    // {
    //     for (lli j = 0; j < p.size(); j++)
    //     {
    //         if (i != j)
    //         {
    //             myset.insert(p[i] * p[j]);
    //         }
    //     }
    // }
    for (lli i = 0; i < p.size(); i++)
    {
        myset.insert(p[i]);
    }

    lli t;
    //cout << "hello" << endl;
    cin >> t;
    while (t--)
    {
        lli x;
        cin >> x;

        lli sq = sqrt(x);
        if (sq * sq == x)
        {
            if (prime[sq])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
