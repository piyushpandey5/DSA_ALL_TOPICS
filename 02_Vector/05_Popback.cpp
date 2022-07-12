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

    // void pop_back(){
    //     size--;
    //     if(size%Block_Size==0 ){
    //         if(capacity != size+Block_Size){
    //             T *temp = new T[size+Block_Size];
    //             for(int i=0;i<size;i++){
    //                 *(temp+i) = *(begin+i);
                    
    //             }
    //             delete[] begin;
    //             begin = temp;
    //             capacity = capacity+Block_Size;
    //             end = begin+size;
    //         }
    //     }
    //     else
    //         end--;
    // }

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
    for(int i=0;i<24;i++){
        vec.push_back(4);
    }
    for(int i=0;i<14;i++){
        vec.pop_back();
    }
    
    cout<<"capacity is "<<vec.capacity<<endl;
    cout<<"size is "<<vec.size<<endl;
    return 0;
}