/*
This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef long long ll;
typedef long double ld;
typedef map<ll, ll> mp;
typedef unordered_map<ll, ll> ump;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef priority_queue<int> maxHeapll;
typedef priority_queue<int, vector<int>, greater<int>> minHeap;

void solve()
{
    ll n, k, x;
    cin >> n >> k;
    vector<ll> v1;
    ump m;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        if (m[v1[i]])
            flag = true;
        m[k - v1[i]] = 1;
    }
    if (flag == true)
        cout << "true\n";
    else
        cout << "false\n";
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}