
#include <iostream>
using namespace std;

int main()
{
    int q[5];

    cout << "Enter 5 token numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> q[i];
    }

    cout << "Customers served in order: ";
    for (int i = 0; i < 5; i++)
    {
        cout << q[i] << " ";
    }

    return 0;
}
