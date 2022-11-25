#include<iostream>
using namespace std;
namespace BST{
    class Node
    {
        public:
            int data;
            Node *left;
            Node *right;
        Node(int data)
        {
            this->data=data;
            left=right=NULL;
        }
    };
    void insertNode(Node **root,int data)
    {
        if(*root==NULL)
        {
            *root=new Node(data);
            return;
        }
        if(data<(*root)->data)
            insertNode(&((*root)->left),data);
        else
            insertNode(&((*root)->right),data);
    }
    void inorder(Node *root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void preorder(Node *root)
    {
        if(root==NULL)
            return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node *root)
    {
        if(root==NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    void deleteNode(Node **root,int data)
    {
        if(*root==NULL)
            return;
        if(data<(*root)->data)
            deleteNode(&((*root)->left),data);
        else if(data>(*root)->data)
            deleteNode(&((*root)->right),data);
        else
        {
            if((*root)->left==NULL)
            {
                Node *temp=*root;
                *root=(*root)->right;
                delete temp;
            }
            else if((*root)->right==NULL)
            {
                Node *temp=*root;
                *root=(*root)->left;
                delete temp;
            }
            else
            {
                Node *temp=(*root)->right;
                while(temp->left!=NULL)
                    temp=temp->left;
                (*root)->data=temp->data;
                deleteNode(&((*root)->right),temp->data);
            }
        }
    }
    void search(Node *root,int data)
    {
        if(root==NULL)
        {
            cout<<"Not Found"<<endl;
            return;
        }
        if(data<root->data)
            search(root->left,data);
        else if(data>root->data)
            search(root->right,data);
        else
            cout<<"Found"<<endl;
    }
    void minNode(Node *root)
    {
        if(root==NULL)
            return;
        while(root->left!=NULL)
            root=root->left;
        cout<<root->data<<endl;
    }
    void maxNode(Node *root)
    {
        if(root==NULL)
            return;
        while(root->right!=NULL)
            root=root->right;
        cout<<root->data<<endl;
    }
    int getHeight(Node *root)
    {
        if(root==NULL)
            return 0;
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        return max(left,right)+1;
    }
    int getWidth(Node *root)
    {
        if(root==NULL)
            return 0;
        int left=getWidth(root->left);
        int right=getWidth(root->right);
        return left+right+1;
    }
    int sumofNodes(Node *root)
    {
        if(root==NULL)
            return 0;
        int left=sumofNodes(root->left);
        int right=sumofNodes(root->right);
        return left+right+root->data;
    }
};
int main()
{
    BST::Node *root=NULL;
    BST::insertNode(&root,5);
    BST::insertNode(&root,3);
    BST::insertNode(&root,7);
    BST::insertNode(&root,1);
    BST::insertNode(&root,4);
    BST::insertNode(&root,6);
    BST::insertNode(&root,8);
    BST::inorder(root);
    cout<<endl;
    BST::preorder(root);
    cout<<endl;
    BST::postorder(root);
    cout<<endl;
    BST::deleteNode(&root,5);
    BST::inorder(root);
    cout<<endl;
    BST::search(root,5);
    BST::search(root,3);
    BST::minNode(root);
    BST::maxNode(root);
    cout<<BST::getHeight(root)<<endl;
    cout<<BST::getWidth(root)<<endl;
    cout<<BST::sumofNodes(root)<<endl;
    return 0;
}