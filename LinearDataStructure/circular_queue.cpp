#include<iostream>
using namespace std;
#define SIZE 5
template< class Type>class QUEUE
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
    if((rear==SIZE-1 && front==0)||(rear==front-1))
    {
        cout<<"Queue is full!!"<<endl;
    }
    else
    {   
        cout<<"Enter the value to insert:"<<endl;
        cin>>value;
        if (front==-1)
            front=0;
        if (rear==SIZE-1)
            rear=-1;
        queue[++rear]=value;
    }
}
template<class Type>void QUEUE<Type>::dequeue()
{   
    if(front==-1 )
        printf("Queue is empty\n");
    else if(rear==front)
    {
        printf("Dequeue element is %d\n",queue[front]);
        front =rear=-1;
    }
    else
    { 
        if(front==SIZE-1)
            front=0;
        printf("Dequeue element is %d\n",queue[front++]);
    }
}
template<class Type>void QUEUE<Type>::display()
{   
    if(front==-1)
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else
    {   
        cout<<"Elements in queue are:";
        if (rear>=front)
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<queue[i]<<"\t";
            }
        }
        else
        {
            for(int i=front;i<SIZE;i++)
            {
                cout<<queue[i]<<"\t";
            }
            for(int i=0;i<=rear;i++)
            {
                cout<<queue[i]<<"\t";
            }
        }
        cout<<endl;
    }
}
int main(void)
{
    QUEUE<int>q;
    int option;
    while(1)
    {
        cout<<"ENQUEUE::1,DEQUEUE::2,DISPLAY::3"<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
            q.enqueue();
            break;
            case 2:
            q.dequeue();
            break;
            case 3:
            q.display();
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
}



