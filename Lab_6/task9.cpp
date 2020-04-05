#include <iostream>
using namespace std;

class queue
{
    static const int MAX=4;
    int st[MAX];
    int head, tail;
public:
    queue(){head=MAX,tail=-1;}
    void put(int var)
    {
        st[++tail]=var;
        if(tail==MAX-1)
            tail=-1;
    }
    int get()
    {
        if(head==0)
            head=MAX;
        return st[MAX-head--];
    }
};

int main()
{
    queue q1;
    q1.put(1);
    q1.put(2);
    q1.put(3);
    q1.put(4);
    q1.put(5);
    q1.put(6);
    cout <<q1.get() <<endl;
    cout <<q1.get() <<endl;
    cout <<q1.get() <<endl;
    cout <<q1.get() <<endl;
    system("pause");
}
