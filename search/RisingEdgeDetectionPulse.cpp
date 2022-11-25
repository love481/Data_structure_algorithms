#include<iostream>
using namespace std;
#define SIZE 10
//Time Complexity: O(logN)
int findPosition(int pulse_t[10])
{
    int pos=0;
    for (int a=SIZE; a>0; a/=2)
    {
        while (!pulse_t[pos+a])
            pos += a;
    }
    return pos;
}
int main(){
    int pulse_t[SIZE]={0,0,0,0,1,1,1,1,1,1};
    int pos=findPosition(pulse_t);
    cout<<"Rising Edge found at index between: "<<pos<<" and "<<pos+1<<endl;
    return 0;
}