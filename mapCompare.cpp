#include <iostream>
#include <map>
using namespace std;

class Point {
public:
    friend ostream& operator<<(ostream& , const Point&);
    friend bool operator< (const Point& p1, const Point& p2);
    friend class PointCompare;
public:
    Point(int x, int y):_x(x), _y(y) {}
    // bool operator<(const Point& p) {
    //     if (this->_x == p._x) {
    //         return this->_y < p._y;
    //     }
    //     return this->_x < p._x;
    // }
    
    virtual ~Point(){}

private:
    int _x, _y;
};

ostream& operator<<(ostream& os, const Point &p) {
    os << "(" << p._x << "," << p._y << ")";
    return os;
}

bool operator<(const Point& p1, const Point& p2) {
    if (p1._x == p2._x) {
        return p1._y < p2._y;
    }
    return p1._x < p2._x;
}

class PointCompare {
public:
    PointCompare() = default;
    bool operator() (const Point& p1, const Point& p2) {
        if (p1._x == p2._x) {
            return p1._y < p2._y;
        } 
        return p1._x < p2._x;
    }
    virtual ~PointCompare() {};
};

int main() {
    Point a(1, 2), b(1, 3), c(2, 3);
    // map<Point, int, less<Point>> m;
    map<Point, int, PointCompare> m;
    m.insert(make_pair(a, 10));
    m.insert(make_pair(c, 20));
    m.insert(make_pair(b, 30));

    for (auto i : m) {
        cout << "(" << i.first << " , " << i.second << ")" << endl;
    }
    return 0;
}