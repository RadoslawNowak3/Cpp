#ifndef STACK_H
#define STACK_H
#include <string>
#define SIZE 50
template <class T>
class Stack {

private:
    T arr[SIZE];
    int last=0;
public:
    void Push(T x){
        if(last==SIZE){
            std::cout<<"Stack is FULL"<< std::endl;
            return;
        }else{
            arr[last]=x;
            last++;
        }
    }
    void Pop(){
        if(last==0){
			std::cout<<"Stack is empty"<< std::endl;
        }else{
            last--;
        }
    }
    int Top() {

        if(last==0){
			std::cout<<"Stack is empty" << std::endl;
           return 0;
        }else{
            return arr[last-1];
        }
    }
    int size(){
        return last;
    }
    void Print(){
        for(int i=0;i<last;i++){
			std::cout<<arr[i] << std::endl;

        }
    }
    bool isEmpty(){
        return (last==0);
    }
};
#endif 
