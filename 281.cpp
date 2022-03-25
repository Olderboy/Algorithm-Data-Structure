/*
题目描述
​ 给定 N 个字符串 S1,S2...SN，接下来进行 M 次询问，每次询问给定一个字符串 T，
求 S1−SN中有多少个字符串是 T 的前缀。输入字符串的总长度不超过 10^6，仅包含小
写字母。

输入
​ 第一行两个整数 N,M。接下来 N 行每行一个字符串 Si。接下来 M 行每行一个字符串表示询问。

输出
​ 对于每个询问，输出一个整数表示答案。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    Node(){
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        _f = 0;
    }
    
    Node *insert(char c) {
        // cout << (next[c - 'a'] == nullptr) << endl;
        if (next[c - 'a'] == nullptr) {
            return (next[c - 'a'] = new Node);
        }
        else { 
            return next[c - 'a'];
        }
    }
    Node *Next(char c) {
        return next[c - 'a'];
    }
    void setf() {
        this->_f = 1;
    }
    int getf() {
        return _f;
    }
    virtual ~Node(){
        for (int i = 0; i < 26; i++) {
            if (next[i] != nullptr) {
                delete next[i];
            }
        }
    }
private:
    int _f;
    Node *next[26];
};

class DirctTree {
public:
    DirctTree() {
        root = new Node;
    }
    void insert(const string& s) {
        Node *temp = root;
        for (int i = 0; i < s.size(); i++) {
            temp = temp->insert(s[i]);
            cout << temp << endl;
        }
        temp->setf();
    }
    int check(const string& s) {
        int count = 0;
        Node *temp = root;
        for (int i = 0; i < s.size(); i++) {
            temp = temp->Next(s[i]);
            if (temp == nullptr) count;
            else {
                if (temp->getf()) count++;
            }
        }
        return count;
    }
    void output() {
        string s;
        for (int i = 0; i < 26; i++) {
            Node *temp = root->Next(i + 'a');
            if (temp != nullptr) s += (i + 'a');
            else if (temp->getf()) cout << s << endl;
        }
    }
    virtual ~DirctTree() {
        delete root;
    }
private:
    Node *root;
};

int main() {
    DirctTree dt;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dt.insert(s);
    }
    dt.output();
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << dt.check(s) << endl;
    }
    return 0;
}