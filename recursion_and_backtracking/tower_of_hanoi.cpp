#include"iostream"
using namespace std;
class Tower
{
    public:
    void Process(int,char,char,char);
};
void Tower:: Process(int n,char src,char ref,char des)
{
    if(n==1)
    {
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<des<<endl;
        return;
    }
    Process(n-1,src,des,ref);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<des<<endl;
    Process(n-1,ref,src,des);
}
int main(void)
{ 
    char src='A',ref='B',des='C';
    int n;
    cout<<"Enter the number of disks u want to shift from peg A to peg C:";
    cin>>n;
    Tower t;
    t.Process(n,src,ref,des);
}