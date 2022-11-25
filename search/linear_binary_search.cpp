#include"iostream"
#define SIZE 5
using namespace std;
//Time Complexity: O(N) & O(logN) & O(logN)  respectively
enum searchMethod{linearSearch,BinarySearch1,BinarySearch2};
template<class Type>
class Search
{
    private:
    Type *A;
    int pos=-1,beg=0,end=SIZE-1;
    public:
    Search():A(new float[SIZE]){}
    Search(Type *arr):A(arr){}
    ~Search(){}
    void getPosition(Type value,searchMethod sm)
    {   pos=-1;
        if(sm==searchMethod::linearSearch)
        {  
            for(int i=0;i<SIZE;i++)
            {  
                if(*(A+i)==value)
                {   
                    pos=i+1;
                    cout<<"Value is found at position:"<<pos;
                    cout<<endl;
                    return;
                }
            }
        }
        else if(sm==searchMethod::BinarySearch1)
        {
            while(beg<=end)
            {
                int mid=(beg+end)/2;
                if(*(A+mid)==value)
                {
                    pos=mid+1;
                    cout<<"Value is found at position:"<<pos;
                    cout<<endl;
                    return;
                }
                else if(*(A+mid)>value) end=mid-1;
                else beg=mid+1;
            }
        }
        else
        {
            pos=0;
            for (int a=SIZE/2; a>0; a/=2)
            {
                while (pos+a < SIZE && *(A+pos+a) <= value)
                    pos += a;
            }
            if(*(A+pos)==value)
                {
                    cout<<"Value is found at position:"<<pos+1;
                    cout<<endl;
                    return;
                }
        }
        if (pos==-1)
        cout<<"Value is not found in array";
    }
};
int main(void)
{
    float* A;
    float value;
    A=new float[SIZE];
    cout<<"Enter the array:"<<endl;
    for (int i=0;i<SIZE;i++)
    {
        cin>>A[i];
    }
    Search<float> sr(A);
    cout<<"Enter the value to search:"<<endl;
    cin>>value;
    sr.getPosition(value,searchMethod::linearSearch);
    //must be sorted before searching
    sr.getPosition(value,searchMethod::BinarySearch1); 
    //alternating method of binary search
    sr.getPosition(value,searchMethod::BinarySearch2);
}

