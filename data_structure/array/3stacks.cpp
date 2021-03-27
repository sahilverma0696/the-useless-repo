//  Not tested 
#include<bits/stdc++.h>
using namespace std;

class Stack {
private:
    const int SIZE = 300;
    const int array[SIZE] ={0};
    
    const   int start_stack1 = 0;
    const   int start_stack2 = 101;
    const   int start_stack3 = 300;
            int size_stack1 = 0;
            int size_stack2 = 0;
            int size_stack3 = 0;

public:
    void    push( int value, int stack_number);
    void    pop ( int stack_number);
    int     top ( int stack_number);
    bool    isEmpty( int stack_number);
};

void Stack::push(int value, int stack_number) {
    if(stack_number == 1) {
        if(!array[start_stack1+size_stack1])
        {
            array[start_stack1+size_stack1] = value;
            size_stack1++;
        }
    }
    else if( stack_number == 2) {
        if(!array[start_stack2+size_stack2])
        {
            array[start_stack2+size_stack2] = value;
            size_stack2++;
        }
    }
    else if(stack_number == 3) {
        if(!array[start_stack3-size_stack3] && start_stack3-size_stack3 < SIZE && start_stack3-size_stack3 > start_stack2)
        {
            array[start_stack3-size_stack3] = value;
            size_stack3++;
        }
    }
    else 
        cout<<"Stack not found";
}

void Stack::pop(int stack_number)
{
    if(stack_number == 1) {
        if(size_stack1 > 0) {
            array[start_stack1 + size_stack1] = 0;
            size_stack1--;
        }
        else
            cout<<"Stack "<<stack_number<<" is empty";
    }
    else if(stack_number == 2) {
        if(size_stack2 > 0) {
                array[start_stack2 + size_stack2] = 0;
                size_stack2--;
            }
        else
            cout<<"Stack "<<stack_number<<" is empty";
    }
    else if(stack_number == 3) {
        if(size_stack3 > 0){
            array[start_stack3 - size_stack3] = 0;
            size_stack3--;
        }
        else
            cout<<"Stack "<<stack_number<<" is empty";

    }
    else
        cout<<"stack not found";
}

int Stack::top(int stack_number) {
    if(stack_number == 1) {
        if(!size_stack1)
            return array[size_stack1];
        else 
            return INT_MIN;
    }
    else if(stack_number == 2) {
        if(!size_stack2)
            return array[size_stack2];
        else 
            return INT_MIN;
    }
    else if(stack_number == 3) {
        if(!size_stack3)
            return array[size_stack3];
        else 
            return INT_MIN;
    }
    else 
        return INT_MIN;
}

bool Stack::isEmpty(int stack_number)
{
    if(stack_number == 1) {
        if(size_stack1 == 0)
            return true;
        return false;
    }
    else if(stack_number == 2) {
        if(size_stack2 == 0)
            return true;
        return false;
    }
    else if(stack_number ==  3) {
        if(size_stack3 == 0)
            return true;
        return false;
    }
    else 
        cout<<"stack not found";
        return false;
}

int main()
{
	return 0;
}