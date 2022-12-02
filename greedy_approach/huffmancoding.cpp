#include <bits/stdc++.h>
using namespace std;
#define N 6
struct node{
    pair<char,int>data;
    node* left,*right;
    node(pair<char,int>data)
    {
        this->data=data;
        left=right=NULL;
    }
};
struct compare {
 
    bool operator()(node* l, node* r)
 
    {
        return (l->data.second > r->data.second);
    }
};
void printHuffmanCodes(struct node*root,string str)
{
    if (root==NULL)
        return;
    else if(root->data.first!='$'){
        cout<<root->data.first<<": "<<str<<endl;
    }
    printHuffmanCodes(root->left,str+"0");
    printHuffmanCodes(root->right,str+"1");
}
void huffmanCode(priority_queue<node*, vector<node*>, compare>&sorted_data)
{
  struct node *top,*left,*right;
  while (sorted_data.size()!=1)
  {
    left=sorted_data.top();
    sorted_data.pop();
    right=sorted_data.top();
    sorted_data.pop();
    top=new node(make_pair('$',left->data.second+right->data.second));
    top->left=left;
    top->right=right;
    sorted_data.push(top);

  }
  struct node* root=sorted_data.top();
  printHuffmanCodes(root,"");
}
int main(void){
     
    char arr[N] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[N] = { 5, 61, 12, 8, 16, 21 };
    priority_queue<node*, vector<node*>, compare> data;
    for (int i=0;i<N;i++)
    {
        data.push(new node(make_pair(arr[i],freq[i])));
    }
    huffmanCode(data);

}