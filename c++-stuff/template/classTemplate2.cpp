#include <iostream>

template <class T>
class Position
{
public:
    Position(T x, T y): x(x), y(y) {}
    void Print()
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
private:
    T x,y;
};

int main() {
    Position<int> p{1,1};
    p.Print();

    Position<double> q = {10.0, 2.2};
    q.Print();

    return 0;
}
