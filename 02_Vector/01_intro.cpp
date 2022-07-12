#include <iostream>
using namespace std;

template <class T>

class Vector
{

    unsigned _size;     // number of elements in vector
    unsigned _capacity; // memory allocated to vector
public:
    T *begin;
    T * end;
    Vector()
    {
        _size = 0;
        _capacity = 1;
        begin = new T[_capacity];
        end = begin;
    }
    unsigned size()
    {
        return _size;
    }
    T operator[](unsigned index)
    {
        if (index > _size)
            return -1;
        else
            return *(begin + index);
    }
    void push_back(T element)
    {
        *(begin + _size) = element;
        _size += 1;
    }
    
};

int main()
{
    Vector<int> vec;
    cout<<vec.size()<<endl;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(9);
    cout<<vec[0]<<endl;
    cout<<vec[1]<<endl;
    cout<<vec[2]<<endl;
    
}