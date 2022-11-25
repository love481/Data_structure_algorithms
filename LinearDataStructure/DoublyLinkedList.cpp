#include<iostream>
using namespace std;
template<class Type>
class doublyLink
{
    private:
    struct Node
    {
        Type data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Type value;
    int pos;
    public:
    doublyLink();
    void GetData();
    void InsertAtBeg();
    void InsertAtEnd();
    void InsertAtBetween();
    void DeleteAtBeg();
    void DeleteAtEnd();
    void DeleteAtBetween();
    void show();
    void reverse();
};
template<class Type>
doublyLink<Type>::doublyLink()
{
    head=NULL;
}
template<class Type>
void doublyLink<Type>::GetData()
{
    cout<<"Enter the data:\n";
    cin>>value;
}
template<class Type>
void doublyLink<Type>::InsertAtBeg()
{
    Node *ptr=new Node();
    GetData();
    ptr->data=value;
    ptr->next=head;
    ptr->prev=NULL;
    if(head!=NULL)
        head->prev=ptr;
    head=ptr;
}
template<class Type>
void doublyLink<Type>::InsertAtEnd()
{
    Node *ptr=new Node();
    Node *temp;
    GetData();
    ptr->data=value;
    ptr->next=NULL;
    if(head==NULL)
    {
        ptr->prev=NULL;
        head=ptr;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=ptr;
        ptr->prev=temp;
    }
}
template<class Type>
void doublyLink<Type>::InsertAtBetween()
{
    Node *ptr=new Node();
    Node *temp;
    GetData();
    ptr->data=value;
    cout<<"Enter the position:\n";
    cin>>pos;
    if(pos==1)
    {
        ptr->next=head;
        ptr->prev=NULL;
        if(head!=NULL)
        head->prev=ptr;
        head=ptr;
    }
    else
    {
        temp=head;
        for(int i=1;i<pos-1;i++)
        {
            if(temp->next==NULL)
            {
                cout<<"Enter the valid location:"<<endl;
                exit(0);
            }
            temp=temp->next;
        }
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next->prev=ptr;
        temp->next=ptr;
    }
}
template<class Type>
void doublyLink<Type>::DeleteAtBeg()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        exit(0);
    }
    else
    {
        Node *ptr;
        ptr=head;
        cout<<"Deleted element is:"<<ptr->data<<endl;
        head=head->next;
        head->prev=NULL;
        delete [] ptr;
    }
}
template<class Type>
void doublyLink<Type>::DeleteAtEnd()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        exit(0);
    }
    else
    {
        Node *ptr,*temp;
        ptr=head;
        while(ptr->next!=NULL)
        {
            temp=ptr;
            ptr=ptr->next;
        }
        cout<<"Deleted element is:"<<ptr->data<<endl;
        temp->next=NULL;
        delete [] ptr;
    }
}
template<class Type>
void doublyLink<Type>::DeleteAtBetween()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        exit(0);
    }
    else
    {
        Node *ptr,*temp;
        ptr=head;
        cout<<"Enter the position:\n";
        cin>>pos;
        if(pos==1)
        {
            ptr=head;
            cout<<"Deleted element is:"<<ptr->data<<endl;
            head=head->next;
            head->prev=NULL;
            delete [] ptr;
        }
        else
        {
            for(int i=1;i<pos;i++)
            {
                if(ptr->next==NULL)
                {
                    cout<<"Enter the valid location:"<<endl;
                    exit(0);
                }
                temp=ptr;
                ptr=ptr->next;
            }
            cout<<"Deleted element is:"<<ptr->data<<endl;
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
            delete [] ptr;
        }
    }
}
template<class Type>
void doublyLink<Type>::show()
{
    Node *ptr;
    ptr=head;
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        exit(0);
    }
    else
    {
        cout<<"The list is:"<<endl;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
template<class Type>
void doublyLink<Type>::reverse()
{   
    Node *ptr,*temp=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        temp=ptr->prev;
        ptr->prev=ptr->next;
        ptr->next=temp;
        ptr=ptr->prev;
    }
    temp=temp->prev;
    head=temp;
    cout<<"The reversed list is:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    doublyLink<int> obj;
    int choice;
    while(1)
    {
        cout<<"1.Insert at beginning\n2.Insert at end\n3.Insert at between\n4.Delete at beginning\n5.Delete at end\n6.Delete at between\n7.Display\n8.Reverse\n9.Exit\n";
        cout<<"Enter your choice:\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            obj.InsertAtBeg();
            break;
            case 2:
            obj.InsertAtEnd();
            break;
            case 3:
            obj.InsertAtBetween();
            break;
            case 4:
            obj.DeleteAtBeg();
            break;
            case 5:
            obj.DeleteAtEnd();
            break;
            case 6:
            obj.DeleteAtBetween();
            break;
            case 7:
            obj.show();
            break;
            case 8:
            obj.reverse();
            break;
            case 9:
            exit(0);
            break;
            default:
            cout<<"Invalid option!!\n";
            break;
        }
    }
}
