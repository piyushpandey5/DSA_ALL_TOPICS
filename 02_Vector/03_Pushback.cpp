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
            T *temp = new T[size+Block_Size];
            for(int i=0;i<size;i++){
                *(temp+i) = *(begin+i);
            }
            delete[] begin;
            begin = temp;
            *(begin+size) = elem;
            capacity+= Block_Size;
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
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(87);
    vec.push_back(64);
    vec.push_back(56);
    vec.push_back(51);
    vec.push_back(79);
    vec.push_back(57);
    vec.push_back(56);
    vec.push_back(7);
    vec.push_back(9);
    cout<<vec[0]<<endl;
    cout<<vec[1]<<endl;
    cout<<vec[2]<<endl;
    cout<<vec[3]<<endl;
    cout<<vec[4]<<endl;
    cout<<vec[5]<<endl;
    cout<<vec[6]<<endl;
    cout<<vec[7]<<endl;
    cout<<vec[8]<<endl;
    cout<<vec[9]<<endl;
    
    cout<<"capacity is "<<vec.capacity<<endl;
    cout<<"size is "<<vec.size<<endl;
    return 0;
}