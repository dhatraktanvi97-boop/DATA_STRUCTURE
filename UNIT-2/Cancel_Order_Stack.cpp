
# include <iostream>
using namespace std;

int main()
{
int  Cancel[5];// Array Created...
int top =4;
cout<<"====CANCELLED ORDERS LIST===="<<endl;

// Storing the values in the array

Cancel[0]=100;
Cancel[1]=101;
Cancel[2]=102;
Cancel[3]=103;
Cancel[4]=104;
for (int i=4; i>=0; i--)
{
  cout<<Cancel[i]<<endl;
}
return 0;
}




