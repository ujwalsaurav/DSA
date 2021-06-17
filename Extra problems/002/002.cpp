/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
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
    ll n;
    cin >> n;
    vector<ll> nums;
    vector<ll> answer;
    ll x;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }
    ll left[n], right[n];
    left[0] = 1;
    right[n - 1] = 1;

    for (ll i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }
    for (ll i = 0; i < n; i++)
    {
        x = left[i] * right[i];
        answer.push_back(x);
    }
    cout << "[ ";
    for (ll i = 0; i < n; i++)
    {
        cout << answer[i] << " ";
    }
    cout << "]\n";
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