#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

// namespace test1 {
//     class A {
//     public: 
//         A (int x): _x(x) {}
//         int get() const {
//             return _x;
//         }
//         void set(int x) {
//             _x = x;
//         }
//         virtual ~A(){}
//     private:
//         int _x;

//     };
//     A::~A() {
//         cout << "A destructor" << endl;
//     }
//     int main() {
//         // const A a(1);
//         // cout << a.get() << endl;
//         // a.set(2);
//         // cout << a.get() << endl;
//         // const A b{2};
//         // cout << b.get() << endl;
//         // b.set(4);
//         // cout << b.get() << endl;
//         priority_queue<int, vector<int>, less<int>> pq;
//         return 0;
//     }
// }

namespace test2
{
    class Foo {
    public:
        Foo() {
            cout << 1 << endl;
        }
        Foo(const Foo& foo) {
            cout << "Foo(const Foo& foo)" << endl;
        }
        Foo(Foo&& foo) {
            cout << "Foo(Foo&& foo)" << endl;
        }
        Foo& operator= (const Foo& foo) {
            cout << "Foo& operator= (const Foo& foo)" << endl;
            return *this;
        }

        Foo& operator= (Foo&& foo) {
            cout << "Foo& operator= (Foo&& foo)" << endl;
            return *this;
        }
    }; 
    Foo GetFoo() {
        Foo foo;
        return foo;
    }

    int main() {
        Foo foo;
        foo = GetFoo();
        return 0;
    }
} // namespace test2


namespace test3
{
   enum People{
       Chinese,
       Americen
   }; 
   People whoAreYou() {
    return Chinese;
    }
    //枚举的内部名称也可以单独使用
    int main() {
        switch(whoAreYou()) {
            case Chinese:
                cout << "Chinese" << endl;
                break;
            case Americen:
                cout << "Americen" << endl;
                break;
        }
    }
} // namespace test3

namespace test4
{
    priority_queue<int, vector<int>, less<int>> que;    
} // namespace test4

namespace test5 {
    int main(){

        map<string, int> m;
        m.insert(make_pair("1", 1));
        m.insert(make_pair("2", 2));
        map<string, int>::iterator iter = m.end();
        m.insert(iter, make_pair("4", 4));
        m.insert(iter, make_pair("3", 3));
        for (auto i : m) {
            cout << i.first << ", " << i.second << endl;
        }
    }
}

int main() {
    // test1::main();
    // test2::main();
    // test3::main();
    // string s("sfsafda");
    // string d(s);
    // cout << d << endl;
    // vector<vector<int>> vec;
    // vec.push_back(vector<int>{1, 2, 3, 4});
    // vector<vector<int>> vec2;
    // vec2 = vec;
    // vector<int> temp = vec2[0];
    // for(int i : temp) {
    //     cout << i << endl;
    // }
    // cout << __FILE__ << sizeof(__FILE__) << endl;
    test5::main();
    return 0;
}

