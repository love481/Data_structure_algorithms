#include<iostream>
using namespace std;
template<class Type>class QUEUE{
    class Node{
        public:
            Type data;
            Node *next;
    }*front=NULL,*rear=NULL;
    public:
        void enqueue();
        void dequeue();
        void display();
    };
template<class Type>void QUEUE<Type>::enqueue()
{   Type value;
    cout<<"Enter the value to be inserted:\n";
    cin>>value;
    Node *ptr=new Node();
    ptr->data=value;
    if(front==NULL)
    {
        ptr->next=NULL;
        rear=front=ptr;
    }
    else
    {   
        rear->next=ptr;
        rear=ptr;
        ptr->next=NULL;
    }
}
template<class Type>void QUEUE<Type>::dequeue()
{   Node *temp;
    if(front==NULL)
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else
    {   
        temp=front;
        cout<<"dequeue element form queue is:"<<front->data<<endl;
        front=front->next;
        delete [] temp;
    }
}
template<class Type>void QUEUE<Type>::display()
{   Node *temp;
    if(front==NULL)
    {
        cout<<"Queue is empty!!"<<endl;
    }
    else
    { 
        temp=front;
        cout<<"Elements in the queue are:";
        while(temp!=NULL)
        {   
            cout<<temp->data<<"\t";
            temp=temp->next;
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