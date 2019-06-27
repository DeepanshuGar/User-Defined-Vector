#include <iostream>
using namespace std;

class vector{
    int *arr;
    int cs;
    int maxSize;
    public:
    vector(int defaultSize = 4)
    {
        maxSize = defaultSize;
        cs = 0;
        arr = new int[maxSize];
    }
    void push_back(int data)
    {
        if(cs==maxSize)
        {
            int *oldArray = arr;
            maxSize *=2;
            arr = new int[2*maxSize];
            for(int i=0;i<cs;i++)
            {
                arr[i] = oldArray[i];
            }
            delete [] oldArray;
        }
        arr[cs] = data;
        cs++;
    }
    bool empty()
    {
        return cs==0;
    }
    void pop_back()
    {
        if(!empty())
        cs--;
    }
    void print()
    {
        for(int i=0;i<cs;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    int& operator[](int i)
    {
        return arr[i];
    }
    int getElement(int i)
    {
        return arr[i];
    }
    int getSize()
    {
        return maxSize;
    }
};
void operator << (ostream &os,vector &v)
{
    v.print();
}
int main()
{
    vector v(1000);
    for(int i=0;i<=3;i++)
    {
        v.push_back(i*i);
    }
    v[2] = 6;
    v.print();
    return 0;
}
