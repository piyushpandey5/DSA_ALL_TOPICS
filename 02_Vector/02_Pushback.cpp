#include<iostream>
using namespace std;

template<class T>
class Vector{
    public:
        T *begin = new T[1]; 
        int size=0;
        int capacity= 1;

    void push_back(T elem){
        int *temp = new T[size+1];
        for(int i=0;i<size;i++){
            *(temp+i) = *(begin+i);
        }
        *(temp+size) = elem;
        delete[] begin;
        begin = temp;
        size+=1;
        capacity+=1;
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
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(3);
    cout<<vec[0]<<endl;
    cout<<vec[1]<<endl;
    cout<<vec[2]<<endl;
    
    cout<<"capacity is "<<vec.capacity<<endl;
    cout<<"size is "<<vec.size<<endl;
    return 0;
}