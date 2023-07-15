#include <iostream>

/*
 * 1. Type safety (avoid unnecessary casts)
 * 2. abstraction (type independent containers and algorithms)
 * 3. flexible parameterization
*/

template <class T>
class my_node {
private:
    T data;
    my_node* next;
public:
    my_node(T data, my_node* next) : data(data), next(next) {}
    T get() { return data; }
    my_node* next_node() { return next; }
};

template<class T>
void swap(T &x, T &y) {
    T z = x;
    x = y;
    y = z;
}

int main() {
    int a = 1;
    int b = 2;
    double c = 3.0;
    swap(a,b);
    std::cout << "a, b: " << a << ", " << b << "\n";
   // swap(a, c); //type error?
    my_node<int> n(a, nullptr);
    my_node<int> m(b, &n);
   // my_node<double> p(c, &n ); //type error: cannot mix int and double

    return 0;
}
/*
 * avoid overusing of templates!
 * use only when necessary
*/
