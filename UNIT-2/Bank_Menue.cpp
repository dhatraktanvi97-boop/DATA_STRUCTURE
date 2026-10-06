
#include<iostream>
using namespace std;

int main()
{
    int q[100];
    int front=0, rear=0, ch, n;

    do
    {
        cout<<"\n1. Issue Token";
        cout<<"\n2. Display Tokens";
        cout<<"\n3. Serve Customer";
        cout<<"\n4. Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        if(ch==1)
        {
            cout<<"Enter token number: ";
            cin>>n;
            q[rear]=n;
            rear++;
        }
        else if(ch==2)
        {
            for(int i=front; i<rear; i++)
                cout<<q[i]<<" ";
            cout<<endl;
        }
        else if(ch==3)
        {
            if(front<rear)
            {
                cout<<"Serving token: "<<q[front]<<endl;
                front++;
            }
            else
                cout<<"No customer available";
        }
        else if(ch==4)
            cout<<"Exit";
        else
            cout<<"Invalid choice";

    }while(ch!=4);

    return 0;
}
