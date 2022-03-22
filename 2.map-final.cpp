/*************************************************************************
    > File Name: 2.map.cpp
    > Author: huguang
    > Mail: hug@haizeix.com
    > Created Time: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define BEGINS(x) namespace x {
#define ENDS(x) }

BEGINS(test1)

int main() {
    set<int> s;
    for (int i = 0; i < 5; i++) {
        int val = rand() % 100;
        cout << "insert : " << val << endl;
        s.insert(val);
    }
    for (auto x : s) {
        cout << "output : " << x << endl;
    }
    return 0;
}

ENDS(test1)

BEGINS(test2)

class base_node {
public :
    base_node(
        int key = 0,
        base_node *father = nullptr,
        base_node *lchild = nullptr,
        base_node *rchild = nullptr
    ) : key(key), father(father), lchild(lchild), rchild(rchild) {}
    virtual ~base_node() {}
    void print() {
        cout << key << " | ";
        if (lchild) cout << lchild->key; 
        else cout << "0";
        cout << " , ";
        if (rchild) cout << rchild->key; 
        else cout << "0";
        cout << endl;
        return ;
    }
    int key;
    base_node *father, *lchild, *rchild;

};

class binary_search_node : public base_node {
public :
    typedef base_node node_t;
    binary_search_node(
        int key = 0, 
        node_t *father = nullptr, 
        node_t *lchild = nullptr, 
        node_t *rchild = nullptr
    ) : base_node(key, father, lchild, rchild) {}
    static node_t *insert(node_t *father, node_t *root, int key) {
        if (root == nullptr) return binary_search_node::getNewNode(father, key);
        if (key == root->key) return root;
        if (key < root->key) {
            root->lchild = insert(root, root->lchild, key);
        } else {
            root->rchild = insert(root, root->rchild, key);
        }
        return root;
    }
    static node_t *getNewNode(node_t *father, int key) {
        return new binary_search_node(key, father);
    }
    static node_t *next(node_t *ptr) {
        if (ptr->rchild) {
            ptr = ptr->rchild;
            while (ptr->lchild) ptr = ptr->lchild;
            return ptr;
        }
        while (ptr->father && ptr != ptr->father->lchild) {
            ptr = ptr->father;
        }
        return ptr->father;
    }
};

class binary_search_node_iterator {
public :
    friend void output_tree(binary_search_node_iterator &);
    typedef base_node node_t;
    typedef binary_search_node_iterator iterator;
    binary_search_node_iterator(node_t *ptr) : ptr(ptr) {}
    bool operator!=(const iterator &iter) {
        return ptr != iter.ptr;
    }
    iterator &operator++() { // ++i
        ptr = binary_search_node::next(ptr);
        return *this;
    }
    iterator operator++(int) { // i++
        iterator ret(ptr);
        ptr = binary_search_node::next(ptr);
        return ret;
    }
    int &operator*() {
        return ptr->key;
    }

private:
    node_t *ptr;
};

class bs_tree {
public :
    typedef base_node node_t;
    typedef binary_search_node_iterator iterator;
    void insert(int key) {
        root.lchild = binary_search_node::insert(&root, root.lchild, key);
        return ;
    }
    node_t *get_root() { return root.lchild; }
    iterator begin() {
        node_t *p = &root;
        while (p->lchild) p = p->lchild;
        return iterator(p);
    }
    iterator end() { return iterator(&root); }

private:
    binary_search_node root;
};

void output_tree(base_node *p) {
    if (p == nullptr) return ;
    p->print();
    cout << "p next ======" << endl;
    binary_search_node::next(p)->print();
    cout << "p next print done ======" << endl << endl;
    output_tree(p->lchild);
    output_tree(p->rchild);
    return ;
}

int main() {
    bs_tree t;
    for (int i = 0; i < 5; i++) {
        int val = rand() % 100;
        cout << "insert : " << val << endl;
        t.insert(val);
    }
    for (auto x : t) {
        cout << x << endl;
    }
    return 0;
}

ENDS(test2)

BEGINS(test3)

template<typename T>
class base_node {
public :
    base_node(
        T key = 0,
        base_node *father = nullptr,
        base_node *lchild = nullptr,
        base_node *rchild = nullptr
    ) : key(key), father(father), lchild(lchild), rchild(rchild) {}
    virtual ~base_node() {}
    void print() {
        cout << key << " | ";
        if (lchild) cout << lchild->key; 
        else cout << "0";
        cout << " , ";
        if (rchild) cout << rchild->key; 
        else cout << "0";
        cout << endl;
        return ;
    }
    T key;
    base_node *father, *lchild, *rchild;
};

template<typename T>
class binary_search_node : public base_node<T> {
public :
    typedef base_node<T> node_t;
    binary_search_node(
        T key = 0, 
        node_t *father = nullptr, 
        node_t *lchild = nullptr, 
        node_t *rchild = nullptr
    ) : base_node<T>(key, father, lchild, rchild) {}
    static node_t *insert(node_t *father, node_t *root, T key) {
        if (root == nullptr) return binary_search_node<T>::getNewNode(father, key);
        if (key == root->key) return root;
        if (key < root->key) {
            root->lchild = insert(root, root->lchild, key);
        } else {
            root->rchild = insert(root, root->rchild, key);
        }
        return root;
    }
    static node_t *getNewNode(node_t *father, T key) {
        return new binary_search_node<T>(key, father);
    }
    static node_t *next(node_t *ptr) {
        if (ptr->rchild) {
            ptr = ptr->rchild;
            while (ptr->lchild) ptr = ptr->lchild;
            return ptr;
        }
        while (ptr->father && ptr != ptr->father->lchild) {
            ptr = ptr->father;
        }
        return ptr->father;
    }
};

template<typename T>
class binary_search_node_iterator {
public :
    friend void output_tree(binary_search_node_iterator<T> &);
    typedef base_node<T> node_t;
    typedef binary_search_node_iterator<T> iterator;
    binary_search_node_iterator(node_t *ptr) : ptr(ptr) {}
    bool operator!=(const iterator &iter) {
        return ptr != iter.ptr;
    }
    iterator &operator++() { // ++i
        ptr = binary_search_node<T>::next(ptr);
        return *this;
    }
    iterator operator++(int) { // i++
        iterator ret(ptr);
        ptr = binary_search_node<T>::next(ptr);
        return ret;
    }
    T &operator*() {
        return ptr->key;
    }

private:
    node_t *ptr;
};

template<typename T>
class bs_tree {
public :
    typedef base_node<T> node_t;
    typedef binary_search_node_iterator<T> iterator;
    void insert(const T &key) {
        root.lchild = binary_search_node<T>::insert(&root, root.lchild, key);
        return ;
    }
    node_t *get_root() { return root.lchild; }
    iterator begin() {
        node_t *p = &root;
        while (p->lchild) p = p->lchild;
        return iterator(p);
    }
    iterator end() { return iterator(&root); }

private:
    binary_search_node<T> root;
};

template<typename T>
class set {
public :
    typedef typename bs_tree<T>::iterator iterator;
    void insert(const T &key) {
        tree.insert(key);
        return ;
    }
    iterator begin() { return tree.begin(); }
    iterator end() { return tree.end(); }

private:
    bs_tree<T> tree;
};

void output_tree(base_node<int> *p) {
    if (p == nullptr) return ;
    p->print();
    cout << "p next ======" << endl;
    binary_search_node<int>::next(p)->print();
    cout << "p next print done ======" << endl << endl;
    output_tree(p->lchild);
    output_tree(p->rchild);
    return ;
}

int main() {
    test3::set<int> t;
    for (int i = 0; i < 5; i++) {
        int val = rand() % 100;
        cout << "insert : " << val << endl;
        t.insert(val);
    }
    for (auto x : t) {
        cout << x << endl;
    }
    return 0;
}

ENDS(test3)

BEGINS(test4)

template<typename T>
class Select1st {
public :
    auto operator()(T a) -> decltype(a.first) {
        return a.first;
    }
};

template<typename T>
class SelectRaw {
public :
    T operator()(T a) {
        return a;
    }
};

template<typename T>
class less {
public :
    bool operator()(const T &a, const T &b) const {
        return a < b;
    }
};

template<typename T>
class base_node {
public :
    base_node(
        T data = T(),
        base_node *father = nullptr,
        base_node *lchild = nullptr,
        base_node *rchild = nullptr
    ) : data(data), father(father), lchild(lchild), rchild(rchild) {}
    virtual ~base_node() {}
    void print() {
        cout << data << " | ";
        if (lchild) cout << lchild->key; 
        else cout << "0";
        cout << " , ";
        if (rchild) cout << rchild->key; 
        else cout << "0";
        cout << endl;
        return ;
    }
    T data;
    base_node *father, *lchild, *rchild;
};

template<typename K, typename T, typename SKEY, typename CompareK>
class binary_search_node : public base_node<T> {
public :
    typedef base_node<T> node_t;
    binary_search_node(
        T key = T(), 
        node_t *father = nullptr, 
        node_t *lchild = nullptr, 
        node_t *rchild = nullptr
    ) : base_node<T>(key, father, lchild, rchild) {}
    static node_t *insert(node_t *father, node_t *root, T data) {
        if (root == nullptr) return binary_search_node<K, T, SKEY, CompareK>::getNewNode(father, data);
        if (comp(SKEY()(data), SKEY()(root->data))) {
            root->lchild = insert(root, root->lchild, data);
        } else if (comp(SKEY()(root->data), SKEY()(data))) {
            root->rchild = insert(root, root->rchild, data);
        }
        return root;
    }
    static node_t *getNewNode(node_t *father, T key) {
        return new binary_search_node<K, T, SKEY, CompareK>(key, father);
    }
    static node_t *next(node_t *ptr) {
        if (ptr->rchild) {
            ptr = ptr->rchild;
            while (ptr->lchild) ptr = ptr->lchild;
            return ptr;
        }
        while (ptr->father && ptr != ptr->father->lchild) {
            ptr = ptr->father;
        }
        return ptr->father;
    }
    static node_t *find(node_t *root, const K &key) {
        node_t *p = root;
        while (p) {
            if (key < SKEY()(p->data)) {
                p = p->lchild;
            } else if (SKEY()(p->data) < key) {
                p = p->rchild;
            } else {
                break;
            }
        }
        return p;
    }
    static CompareK comp;
};
template<typename K, typename T, typename SKEY, typename CompareK>
CompareK binary_search_node<K, T, SKEY, CompareK>::comp;

template<typename K, typename T, typename SKEY, typename CompareK>
class binary_search_node_iterator {
public :
    friend void output_tree(binary_search_node_iterator<K, T, SKEY, CompareK> &);
    typedef base_node<T> node_t;
    typedef binary_search_node_iterator<K, T, SKEY, CompareK> iterator;
    binary_search_node_iterator(node_t *ptr) : ptr(ptr) {}
    bool operator!=(const iterator &iter) {
        return ptr != iter.ptr;
    }
    iterator &operator++() { // ++i
        ptr = binary_search_node<K, T, SKEY, CompareK>::next(ptr);
        return *this;
    }
    iterator operator++(int) { // i++
        iterator ret(ptr);
        ptr = binary_search_node<K, T, SKEY, CompareK>::next(ptr);
        return ret;
    }
    T &operator*() {
        return ptr->data;
    }

private:
    node_t *ptr;
};

template<typename K, typename T, typename SKEY, typename CompareK>
class bs_tree {
public :
    typedef base_node<T> node_t;
    typedef binary_search_node_iterator<K, T, SKEY, CompareK> iterator;
    void insert(T data) {
        root.lchild = binary_search_node<K, T, SKEY, CompareK>::insert(&root, root.lchild, data);
        return ;
    }
    node_t *find(const K &key) {
        return binary_search_node<K, T, SKEY, CompareK>::find(root.lchild, key);
    }
    node_t *get_root() { return root.lchild; }
    iterator begin() {
        node_t *p = &root;
        while (p->lchild) p = p->lchild;
        return iterator(p);
    }
    iterator end() { return iterator(&root); }

private:
    binary_search_node<K, T, SKEY, CompareK> root;
};

template<typename K, typename V, typename CompareK = test4::less<K>>
class map {
public :
    typedef pair<const K, V> value_type;
    typedef bs_tree<K, value_type, Select1st<value_type>, CompareK> BASE_TREE;
    typedef typename BASE_TREE::iterator iterator;
    typedef typename BASE_TREE::node_t node_t;
    V &operator[](const K &key) {
        node_t *val = tree.find(key);
        if (val) {
            return val->data.second;
        }
        tree.insert(value_type(key, V()));
        return tree.find(key)->data.second;
    }
    iterator find(const K &key) {
        node_t *p = tree.find(key);
        if (p == nullptr) return end();
        return iterator(p);
    }
    iterator begin() { return tree.begin(); }
    iterator end() { return tree.end(); }

private:
    BASE_TREE tree;
};

template<typename K, typename CompareK = test4::less<K>>
class set {
public :
    typedef K value_type;
    typedef bs_tree<K, value_type, SelectRaw<value_type>, CompareK> BASE_TREE;
    typedef typename BASE_TREE::iterator iterator;
    typedef typename BASE_TREE::node_t node_t;
    void insert(const value_type &key) {
        tree.insert(key);
        return ;
    }
    iterator find(const K &key) {
        node_t *p = tree.find(key);
        if (p == nullptr) return end();
        return iterator(p);
    }
    
    iterator begin() { return tree.begin(); }
    iterator end() { return tree.end(); }

private:
    BASE_TREE tree;
};

int main() {
    test4::map<int, int> m;
    test4::set<int> s;
    for (int i = 0; i < 5; i++) {
        int key = rand() % 100;
        int val = rand() % 100;
        cout << "key : " << key << ", value : " << val << endl;
        m[key] = val;
        s.insert(val);
    }
    for (auto x : m) {
        cout << x.first << " " << x.second << endl;
    }
    for (auto x : s) {
        cout << x << endl;
    }
    return 0;
}

ENDS(test4)

BEGINS(test5)

class A {
public :
    A() : x(rand() % 100), y(rand() % 100) {}
    int x, y;
};

class CMP {
public :
    bool operator()(const A &a, const A &b) const {
        if (a.x - b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

ostream &operator<<(ostream &out, const A &a) {
    cout << "(" << a.x << ", " << a.y << ")";
    return out;
}

int main() {
    test4::set<A, CMP> s;
    for (int i = 0; i < 5; i++) s.insert(A());
    for (auto x : s) {
        cout << x << endl;
    }
    return 0;
}

ENDS(test5)

int main() {
    // test1::main();
    // test2::main();
    // test3::main();
    // test4::main();
    test5::main();
    return 0; 
}
