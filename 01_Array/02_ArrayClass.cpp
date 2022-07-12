#include<iostream>
using namespace std;

template<class T>
class Array{
    public:
    T *begin;
    unsigned size;

    Array(){
        size = 1;
        begin = new T [size];
    }

    Array(int size){
        this->size=size;
        begin = new T [size];
    }
    Array(int size, T data){
        this->size=size;
        for(int i=0;i<size;i++){
            *(begin+i) =data;
        }
    }
    
    T at(int index){
        if(index < size){
            return *(begin+index);
        }
        else{
            cout<<"index out of range"<<endl;
            return -1;
        }
    }
    T find(T data){
        for(int i=0;i<size;i++){
            if(*(begin+i)==data)
            return i;
        }
        return -1;

    }
    int find_binary(T data1){
            int i=0;
            int j=size;
        while(i<j){
            int mid = (i+j)/2;
            if(*(begin+mid)==data1){
                return mid;
            }
            else{
                if(*(begin+mid)>data1){
                    j=mid;
                }
                else{
                    i = mid+1;
                }
            }
        }
        return -1;
    }
    



};

int main()
{
    Array<int> arr(5);
    for(int i=0;i<5;i++){
        cin>>*(arr.begin+i);
    }

    // for(int i=0;i<5;i++){
    //     cout<<*(arr.begin+i)<<endl;
    // }
    // Array <int>arr2(4,5);
    // for(int i=0;i<4;i++){
    //     cout<<*(arr2.begin+i)<<endl;
    // }
    // cout<<arr.size<<endl;
    // cout<<arr.at(3)<<endl;
    // cout<<arr.find(3)<<endl;
    cout<<arr.find_binary(10)<<endl;
    return 0;
}