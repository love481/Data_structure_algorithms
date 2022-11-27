#include"iostream"
using namespace std;
class Factorial
{
    int value;
    public:
        Factorial():value(0){}
        Factorial(int value){this->value=value;}
        friend int factorial(Factorial*n);
};
int factorial(Factorial * f)
{
    if (f->value==0)
        return 1;
    else
        return (f->value--)*factorial(f);
}
int main(void)
{   
    int x;
    cout<<"Enter the value whose Factorial u want to find out:";
    cin>>x;
    Factorial x1(x);
    cout<<"Required Factorial is:"<<factorial(&x1);
}