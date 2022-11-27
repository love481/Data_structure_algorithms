#include"iostream"
using namespace std;
class Fibonacci
{
    public:
        int fibonacci(int);
};
int Fibonacci:: fibonacci(int value)
{
    if (value<=1)
        return value;
    else
        return fibonacci(value-2)+fibonacci(value-1);
}
int main(void)
{ 
    int n;
    cout<<"Enter the term up to which u want to find out the Fibonacci:";
    cin>>n;
    Fibonacci s;
    cout<<"Fibonacci Series are:";
    for (int i=0;i<=n;i++)
        cout<<s.fibonacci(i)<<"\t";
}