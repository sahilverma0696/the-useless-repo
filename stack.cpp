#include<iostream>


class Stack
{
private:
    const static int MAX = 100;
    int array[MAX];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    bool isFull();
    bool isEmpty();
    bool Push(int value);
    void Pop(int &value);
    int  Peek(int position);
    int  Size();

};

bool Stack::isFull()
{
    if(top == MAX -1)
        return true;
    return false;
}

bool Stack::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

bool Stack::Push(int value)
{
    if(top == MAX -1)
        return false;
    else
    {
        array[top++] = value;
        return false;
    }
    
}

void Stack::Pop(int &value)
{
    if(top == -1);
    else
    {
        value = array[--top];
    }
    
}

int Stack::Peek(int position)
{
    if(-1<position<MAX)
        return array[position];

}

int Stack::Size()
{
    return top;
}

int main()
{
    Stack sample;
    std::cout<<"Is Empty\t"<<sample.isEmpty()<<std::endl;
    std::cout<<"Is Full\t"<<sample.isFull()<<std::endl;

    for( int i = 0; i<10;i++)
        sample.Push(i);

    int value = 0;
    sample.Pop(value);
    std::cout<<"Pop Value\t"<<value<<std::endl;

    std::cout<<"Peek\t"<<sample.Peek(5)<<std::endl;

    std::cout<<"Size\t"<<sample.Size()<<std::endl;

    return 0;
}
