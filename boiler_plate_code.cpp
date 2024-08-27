#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define all(v) v.begin(), v.end()
#define read(n)  \
    long long n; \
    cin >> n;
#define umap unordered_map
#define vin(v, n)               \
    vector<long long> v(n);     \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> v[i];            \
    }
#define endl "\n"
#define tezi_se_karo         \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    std::cout.tie(0);
#define tab " "
#define YES "YES"
#define NO "NO"

class segTree
{
private:
    vector<int> seg;

public:
    segTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int low, int high, int index, vector<int> &arr)
    {
        if (low == high)
        {
            seg[index] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(low, mid, 2 * index + 1, arr);
        build(mid + 1, high, 2 * index + 2, arr);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int low, int high, int l, int r, int index)
    {
        // no overlap
        if (r < low || l > high)
            return INT_MAX;

        // complete overlap
        if (l <= low && high <= r)
            return seg[index];

        // partial overlap
        int mid = low + (high - low) / 2;
        int left = query(low, mid, l, r, 2 * index + 1);
        int right = query(mid + 1, high, l, r, 2 * index + 2);
        return min(left, right);
    }

    void update(int index, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[index] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * index + 1, low, mid, i, val);
        else
            update(2 * index + 2, mid + 1, high, i, val);

        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }
};

class DSU
{
private:
    map<int, int> parent;
    map<int, pair<ll, ll>> rep;

public:
    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v)
    {
        parent[v] = v;
        rep[v].first = 0;
        rep[v].second = 1;
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rep[a].first < rep[b].first)
                swap(a, b);
            parent[b] = a;
            if (rep[a].second == rep[b].first)
                rep[a].first++;
            rep[a].second += rep[b].second;
        }
    }
    ll getS(int a)
    {
        a = find_set(a);
        return rep[a].second;
    }

    ll getR(int a)
    {
        a = find_set(a);
        return rep[a].first;
    }
};

void solve()
{

}

int32_t main()
{
    tezi_se_karo
    // int t;
    // cin >> t;

    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
