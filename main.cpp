#include <iostream>
#include <uniquepointer.hpp> // custom unique pointer implementation

int main()
{   
    UniquePointer<double> ptr(new double(5));

    {
        UniquePointer<int> ptr(new int(5));
        {
            UniquePointer<float> ptr2(new float(10));
        }
        ptr.reset(new int(10));
    }

    return 0;

}   