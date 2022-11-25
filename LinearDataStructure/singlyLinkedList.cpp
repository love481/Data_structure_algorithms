#include<iostream>
using namespace std;
enum pos_edges{Beg,Between,End};
template<class Type>class singleLink{
   static int numOfElem;
   class Node
    {
        public:
            Type data;
            Node *next; 
    };
   class Node *start;
   public:
        singleLink();
        void Insert(enum pos_edges,Type *);
        void Delete(enum pos_edges);
        void Search(Type);
        static int Count_elem();
        void show();
        void reverse();
};
template<class Type>int singleLink<Type>::numOfElem=0;
template<class Type>int singleLink<Type>::Count_elem(){return numOfElem;}
template<class Type>singleLink<Type>::singleLink() :start(NULL){};
template<class Type>void singleLink<Type>::Insert(enum pos_edges loc,Type *data)
{ 
    Node *ptr=new Node();
    Node *temp;int pos;
    ptr->data=*data;
    if(start==NULL)
    {
        ptr->next=NULL;
        start=ptr;
        numOfElem++;
    }
    else if(loc==Beg)
    {  
        ptr->next=start;
        start=ptr;
        numOfElem++;
    }
    else if(loc==Between)
    {  
        cout<<"Enter the position:\n";
        cin>>pos;
        temp=start;
        if(pos>numOfElem+1 || pos<1)
            cout<<"Enter the valid position!!\n";
        else
        {   for(int i=1;i<pos-1;i++)
                temp=temp->next;
            ptr->next=temp->next;
            temp->next=ptr;
            numOfElem++;
        }
    }
    else
    {   
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        ptr->next=NULL;
        temp->next=ptr;
        numOfElem++;
    }
}
template<class Type>void singleLink<Type>::Delete(enum pos_edges loc)
{ 
    Node *prev,*temp;
    int pos;
    if(start==NULL)
    cout<<"LinkedList is empty!!\n";
    else if(loc==Beg)
    { 
        temp=start;
        start=start->next;
        cout<<"Deleted Element from start is:"<<temp->data<<endl;
        delete [] temp;
        numOfElem--;
    }
    else if(loc==End)
    {    
        prev=temp=start;  
        while(temp->next!=NULL)
        {  
            prev=temp;
            temp=temp->next;
        }
        cout<<"Deleted Element from end is:"<<temp->data<<endl;
        if(prev==temp)
            start=start->next;
            else
            prev->next=NULL;
        delete [] temp;
        numOfElem--;
    }
    else
    {  
        cout<<"Enter the position:\n";
        cin>>pos;
        prev=temp=start;
        if(pos>numOfElem || pos<1)
            cout<<"Enter the valid position!!\n";
        else
        { 
            for(int i=1;i<pos;i++)
            {   
                prev=temp;
                temp=temp->next;
            }
            if(prev==temp)
                start=start->next;
            else
                prev->next=temp->next;
            cout<<"Deleted Element from between is:"<<temp->data<<endl;
            delete [] temp;
            numOfElem--;
        }  
    }
}
template <class Type>void singleLink<Type>::Search(Type value)
{   int pos=0;
    Node *temp;
    temp=start;
    while(temp!=NULL)
    {   
        pos++;
        if(temp->data==value)
        {
            cout<<"Data is found at position:"<<pos<<endl;
            return;
        }
        temp=temp->next;
    }
    if(temp==NULL)
        cout<<"Data is not found!!"<<endl;
}
template<class Type>void singleLink<Type>::show() 
{  
    if(start==NULL)
        cout<<"LinkedList is empty!!\n";
    else
    {
        Node *ptr;
        ptr=start;
        cout<<"Total Elements in List are:"<<Count_elem()<<endl;
        cout<<"Elements in the list are: ";
        while(ptr!=NULL)
        { 
            cout<<ptr->data<<"\t";
            ptr=ptr->next;
        }
        cout<<endl; 
    }
}
template <class Type>void singleLink<Type>::reverse()
{
    Node *prev,*curr,*nex;
    prev=NULL;
    curr=start;
    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;curr=nex;
    }
    start=prev;
}
int main(void)
{
    singleLink<float> sl;
    while(1)
    {   
        int option,pos;
        float value;
        cout<<"1::InsertAtBeg 2::InsertAtEnd 3::InsertAtBetween 4::DeleteAtBeg 5::DeleteAtEnd 6::DeleteAtBetween 7::search 8::show 9::reverse"<<endl;
        cin>>option;
        switch(option)
        {   
            case 1:
                cout<<"Enter the value:\n";
                cin>>value;
                sl.Insert(Beg,&value);
                break;
            case 2:
                cout<<"Enter the value:\n";
                cin>>value;
                sl.Insert(End,&value);
                break;
            case 3:
                cout<<"Enter the value:\n";
                cin>>value;
                sl.Insert(Between,&value);
                break;
            case 4:
                sl.Delete(Beg);
                break;
            case 5:
                sl.Delete(End);
                break;
            case 6:
                sl.Delete(Between);
                break;
            case 7:
                cout<<"Enter the value u want to search:\n";
                cin>>value;
                sl.Search(value);
                break;
            case 8:
                sl.show();
                break;
            case 9:
                sl.reverse();
                break;
            default:
                cout<<"Invalid option!!\n";
                break;
        }
    }
}