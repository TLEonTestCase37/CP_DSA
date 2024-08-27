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

//Problem 1->
// https://codeforces.com/contest/339/submission/278431931

