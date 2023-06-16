#include <iostream>
#include "Vector.hpp"

int main() {
    Vector<int> v(3); // test ctor Vector(int size); 
    
    for (int i = 0; i < 4; ++i) {
        // hen i = 3, the vector automatically inflates
        v.push_back(i); // test push_back() and inflate()
    }
        
    std::cout << "v.size = " << v.size() << std::endl; // test size()

    for (int i = 0; i < 4; ++i) {
        std::cout << "v[" << i << "] = " << v[i] << std::endl; // test operator[](T index)
    }

    Vector<double> w; // test ctor Vector(); 
    std::cout << "w.empty = " << v.empty() << std::endl;
    try {
        w.at(0); // test 
    }
    catch(std::out_of_range e) {
        std::cout << e.what() << std::endl; // test throwing exception out_of_range
    }

    auto x = v; // test ctor Vector(const Vector& r); 

    for (int i = 0; i < 4; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }
    
    x.clear(); // test clear()
    std::cout << "x.size = " << x.size() << std::endl;

    return 0;
}