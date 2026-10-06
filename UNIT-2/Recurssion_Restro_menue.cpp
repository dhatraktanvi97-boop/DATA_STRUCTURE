# include <iostream>
using namespace std;

void menu()
{
  int choice;
cout<<"1. Pizza \n";
cout<<"2. Pasta\n";
cout<<"3.Cold Coffee\n";
cout<<"4. EXIT."<<endl ;
cout<<"PLEASE ENTER YOUR CHOICE  :  \n";
cin>>choice;

if(choice==1 )
{

cout<< "You have selected ==PIZZA==\n";

}

else if(choice==2)
{
cout<<"You have selected ==Pasta==\n";
}

else if(choice==3)
{
cout<<"You have choose ==Cold Coffee==\n";
}

else if (choice == 4)
{
cout<<"***Exiting***";
}
else
{
cout<<"/ / / / INVALID CHOICE/ / / / / \n";
}


menu();
}
 int main()
{
menu();

return 0;
}
