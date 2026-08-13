class Solution {
public:
    struct Node {
        int len;
        char left, right;
        int pref, suff, best;
        
        Node() {
            len = 0;
            left = right = 0;
            pref = suff = best = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        if (a.pref == a.len && a.right == b.left)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.right == b.left)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.right == b.left)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].left = s[l];
            tree[node].right = s[l];
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[node].left = ch;
            tree[node].right = ch;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, ch);
        else
            update(node * 2 + 1, mid + 1, r, pos, ch);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};