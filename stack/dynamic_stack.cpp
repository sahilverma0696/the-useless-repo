#include<stdlib.h>
#include<iostream>

const int INT_MIN = 999;

struct ds_node
{
    int top;
    int capacity;
    int *array;
    ds_node()
    {
        top = -1;
        capacity = 1;
        array = nullptr;
    }
};

class DynamicStack
{
private:
    ds_node* head;

    bool isFull()
    {
        return(head->top == head->capacity-1);

    }

    void doubleCapacity()
    {
        head->capacity =2;
        head->array = (int*)realloc(head->array,sizeof(int)*head->capacity);
    }

    int isEmpty()
    {
        return head->top ==-1;
    }
public:

    DynamicStack()
    {
        head = (ds_node*)malloc(sizeof(ds_node));
        head->array = (int*)malloc(head->capacity*sizeof(int));
    }

    void push(int value)
    {
        if(isFull())
            doubleCapacity();
        head->array[++(head->top)] = value;
    }

    int pop()
    {
        if(isEmpty())
            return INT_MIN;
        return head->array[--(head->top)];
    }

    int peek(int position)
    {
        if(-1<position<=head->top)
            return head->array[position];
    }
    ~DynamicStack()
    {
        if(head){
            if(head->array)
                free(head->array);
            free(head);
        }
    }

};

int main()
{   
    DynamicStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    for(int i = 0;i<3;i++){
        std::cout<<stack.peek(i);
    }
    std::cout<<stack.pop();
    return 0;
}