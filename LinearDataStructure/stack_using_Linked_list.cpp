#include<iostream>
using namespace std;
template<class Type>class Stack{
    class Node
    {
        public:
            Type data;
            Node *next;
    }*top=NULL;

    public:
        void push();
        void pop();
        void display();
};
template<class Type>void Stack<Type>::push()
{   
    Type value;
    cout<<"Enter the value to be inserted:\n";
    cin>>value;
    Node *ptr=new Node();
    ptr->data=value;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
}
template<class Type>void Stack<Type>::pop()
{ 
    Node *temp;
    if(top==NULL)
        cout<<"Stack is empty!!"<<endl;
    else
    { 
        temp=top;
        cout<<"Poped element form stack is:"<<top->data<<endl;
        top=top->next;
        delete [] temp;
    }
}

template<class Type>void Stack<Type>::display()
{   Node *temp;
    if(top==NULL)
        cout<<"Stack is empty!!"<<endl;
    else
    {   
        temp=top;
        cout<<"Elements in the stack are:";
        while(temp!=NULL)
        {   cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int main(void)
{
    Stack<float> sl;
    while(1)
    {   
        int option;
        cout<<"1::PUSH\n2::POP\n3::DISPLAY"<<endl;
        cin>>option;
        switch(option)
        {   
            case 1:
                sl.push();
                break;
            case 2:
                sl.pop();
                break;
            case 3:
                sl.display();
                break;
            default:
                cout<<"Invalid option!!\n";
                break;
        }
    }
}