#include <iostream>

using namespace std;

class A {
public: 
    A (int x): _x(x) {}
    int get() const {
        return _x;
    }
    void set(int x) {
        _x = x;
    }
    virtual ~A(){}

private:
    int _x;

};

int main() {
    const A a(1);
    cout << a.get() << endl;
    a.set(2);
    cout << a.get() << endl;
    const A b{2};
    cout << b.get() << endl;
    b.set(4);
    cout << b.get() << endl;
    return 0;
}