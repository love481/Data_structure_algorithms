#include<iostream>
using namespace std;
#define SIZE 5
template<class Type>class QUEUE
{
    Type queue[SIZE];
    int front,rear;
    public:
    QUEUE()
    {
        front=rear=-1;
    }
    void enqueue();
    void dequeue();
    void display();
};
template<class Type>void QUEUE<Type>::enqueue()
{   Type value;
    if(rear==SIZE-1)
    {
        cout<<"Queue is full!!"<<endl;
    }
    else
    {   
        cout<<"Enter the value to insert:"<<endl;
        cin>>value;
        if (front==-1)
        front=0;
        queue[++rear]=value;
    }
}
template<class Type>void QUEUE<Type>::dequeue()
{   
    if((front==-1) || front>rear)
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else
    {   
        cout<<"Dequeue element is "<<queue[front++]<<endl;
    }
}
template<class Type>void QUEUE<Type>::display()
{   
    if((front==-1) || front>rear)
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else
    {   
        cout<<"Elements in queue are:";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<"\t";
        }
        cout<<endl;
    }
}
int main(void)
{
    QUEUE<float> sl;
    while(1)
    {   int option;
        cout<<"1::ENQUEUE\n2::DEQUEUE\n3::DISPLAY"<<endl;
        cin>>option;
        switch(option)
        {   case 1:
                sl.enqueue();
                break;
            case 2:
                sl.dequeue();
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