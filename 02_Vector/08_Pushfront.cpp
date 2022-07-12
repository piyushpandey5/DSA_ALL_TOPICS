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
            end = begin+size;


        }
    }
    void pop_back(){
        size--;
        if(size%Block_Size==0 ){
            if(size == (capacity - 2*Block_Size)){
                T *temp = new T[size+Block_Size];
                for(int i=0;i<size;i++){
                    *(temp+i) = *(begin+i);
                    
                }
                delete[] begin;
                begin = temp;
                capacity = size+Block_Size;
                end = begin+size;
            }
        }
        else
            end--;
    }

    T operator[](int index){
        if(index<size)
            return *(begin+index);
        else
            return -1;
    }
    void push_front(T elem){
        if(size<capacity){
            for(int i=0;i<size;i++){
                *(end-i+1) = *(end-i);
            }
            size++;
            end++;
            *begin=elem;
        }
        else{
            T * temp = new T[capacity+Block_Size];
            *temp = elem;
            for(int i=0;i<size;i++){
                *(temp+i+1) = *(begin + i);
            }
            size++;
            delete[] begin;
            begin= temp;
            capacity= capacity+Block_Size;
            end= begin+size;
        }
    }

    void pop_front(){
        size--;
        if(size%Block_Size==0  && capacity!=size+Block_Size)
        {
            T *temp=new T[size+Block_Size];
            for(int i=0;i<size;i++){
                *(temp+i)= *(begin+i+1);
            }
            begin=temp;
            capacity=size+Block_Size;
            end = begin+size;
        }
        else{
            for(int i=0;i<size;i++){
                *(begin+i)= *(begin+i+1);
            }
            end--;
        }
    }
};

int main()
{
    Vector<int> vec;
    for(int i=0;i<25;i++){
        vec.push_back(4);
    }
    vec.push_front(7);

    cout<<endl;
    for(int i=0;i<11;i++){
        vec.pop_front();
    }
    for(int i=0;i<vec.size;i++){
        cout<<vec[i]<<" ";
    }
    // for(int i=0;i<17;i++){
    //     vec.pop_back();
    // }
    
    cout<<"capacity is "<<vec.capacity<<endl;
    cout<<"size is "<<vec.size<<endl;
    return 0;
}