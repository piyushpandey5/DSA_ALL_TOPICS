#include<iostream>
using namespace std;

template<class T>
class Vector{
    const int Block_Size=8;

    public:
    T *begin ; 
    T *end;
    int size;
    int capacity;

    Vector(){
        begin = new T[Block_Size];
        size = 0;
        capacity = Block_Size; 
        end = begin;
    }

    void push_back(T elem){
        if(size<capacity){
            end = begin+size;
            *end = elem;
            size++;
        }
        else{
            T *temp = new T[2*capacity];
            for(int i=0;i<size;i++){
                *(temp+i) = *(begin+i);
            }
            delete[] begin;
            begin = temp;
            *(begin+size) = elem;
            capacity=2* capacity;
            size++;


        }
    }

    T operator[](int index){
        if(index<size)
            return *(begin+index);
        else
            return -1;
    }
};

int main()
{
    Vector<int> vec;
    for(int i=0;i<10000;i++){
        vec.push_back(4);
    }
    
    cout<<"capacity is "<<vec.capacity<<endl;
    cout<<"size is "<<vec.size<<endl;
    return 0;
}