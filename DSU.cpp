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