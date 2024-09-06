
class DSU
{
private:
    umap<int, int> parent;
    // map<int, pair<ll, ll>> rep;
    umap<int,int>ranK;
    umap<int,int>sizE;

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
        ranK[v]=0;
        sizE[v]=1;
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (ranK[a] < ranK[b])
                swap(a, b);
            parent[b] = a;
            if (sizE[a] == sizE[b])
                ranK[a]++;
            sizE[a] += sizE[b];
        }
    }
    ll getS(int a)
    {
        a = find_set(a);
        return sizE[a];
    }

    ll getR(int a)
    {
        a = find_set(a);
        return ranK[a];
    }
};
