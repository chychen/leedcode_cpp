#include <iostream>
#include <set>

using namespace std;

struct A
{
    int a=2;
    int b=2;
    char c='5';
};

int main()
{
    A *temp = new A[10];
    temp[0].a = 10;
    temp[1].b = 11;
    cout<<temp[0].a<<endl;
    cout<<temp[1].b<<endl;
    cout<<temp[3].c<<endl;
    cout<<temp[110].c<<endl;

    int a[10] = {0};
    cout<<a[1]<<endl;
    cout<<a[11]<<endl;

    return 0;
}