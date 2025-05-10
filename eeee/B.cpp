#include<iostream>
#include<vector>
using namespace std;

struct BTreeNode
{
    int *keys; // 元素数组
    int t; // 最小度t
    BTreeNode **C; // 子节点数组
    int n;      // 当前节点元素个数
    bool leaf; // 是否是叶子节点

    BTreeNode(int _t, bool _leaf); // 构造函数
    void insertNonFull(int k); // 当前节点未满，插入
    void splitChild(int i, BTreeNode *y); // 分裂节点
    void traverse(); // 遍历
    BTreeNode *search(int k); // 查找
};

class BTree
{
    BTreeNode *root; // B树根节点
    int t; // 最小度t
public:
    BTree(int _t)
    {  root = NULL;  t = _t; }

    void traverse()
    {  if (root != NULL) root->traverse(); }

    BTreeNode* search(int k)
    {  return (root == NULL)? NULL : root->search(k); }

    void insert(int k);
};

BTreeNode::BTreeNode(int t1, bool leaf1)
{
    t = t1;
    leaf = leaf1;

    keys = new int[2*t-1];
    C = new BTreeNode *[2*t];

    n = 0;
}

void BTreeNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (leaf == false)
            C[i]->traverse();
        cout << keys[i] << endl;
    }
    if (leaf == false)
        C[i]->traverse();
}

BTreeNode *BTreeNode::search(int k)
{
    int i = 0;
    while (i < n && k > keys[i])
        i++;
    if (i < n && keys[i] == k)
        return this;
    if (leaf)
        return NULL;
    return C[i]->search(k);
}

void BTree::insert(int k)
{
    if (root == NULL)
    {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else
    {
        if (root->n == 2*t-1)
        {
            BTreeNode *s = new BTreeNode(t, false);
            s->C[0] = root;
            s->splitChild(0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->C[i]->insertNonFull(k);
            root = s;
        }
        else
            root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k)
{
    int i = n-1;

    if (leaf == true)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }

        keys[i+1] = k;
        n = n+1;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i+1]->n == 2*t-1)
        {
            splitChild(i+1, C[i+1]);

            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y)
{
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t-1; j++)
        z->keys[j] = y->keys[j+t];

    if (y->leaf == false)
    {
        for (int j = 0; j < t; j++)
            z->C[j] = y->C[j+t];
    }

    y->n = t - 1;
    for (int j = n; j >= i+1; j--)
        C[j+1] = C[j];

    C[i+1] = z;

    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    keys[i] = y->keys[t-1];

    n = n + 1;
}

int main()
{
    int t, n, m;
    cin>>t>>n>>m;
    BTree tree(t);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        tree.insert(a[i]);
    }

    tree.traverse();

    for (int i = 0; i < m; i++)
    {
        int q;
        cin>>q;
        BTreeNode *res = tree.search(q);
        if (res)
        {
            for (int j = 0; j < res->n; j++)
            {
                cout << res->keys[j];
                if (j < res->n - 1) cout << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}