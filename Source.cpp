#include "amap.h"
#include <iostream>
#include <conio.h>
using namespace std;


int GetKey()
{
    int k;
    cin >> k;
    if ((k == 0) || (k == 224)) cin>>k;
    return k;
   
}

int Menu_()
{
    system("cls");
    cout << "Choose function:\n\n 1-print map\n 2-erase element\n 3-insert element\n 4-find element\n\n 5 - Exit\n";
    while (true)
    {
        int k = GetKey();
        if ((k == 1) || (k == 2) || (k == 3) || (k == 4) || (k == 5)) return k;
    }
}



int Menu2()
{
    cout << "Yes -  Enter\nNo - Esc\n";
    while (true)
    {
        int key = GetKey();
        if ((key == 27) || (key == 13)) return key;
    }
}


int main() 
{
	int  answer = Menu_();
    if (answer == 5) return 0;
    string str;
    int key;
    string result;
    bool a, b;
    amap Cont;
    system("cls");
    while (answer != 5)
    {
        switch (answer)
        {
        case 1:
            system("cls");
            Cont.print();
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "integer Key: " << endl;
            while (!(cin >> key) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "enter the integer key again" << endl;
            }
            a = Cont.erase(key);
            if (a)
            {
                cout << "ready" << endl;
            }
            else
            {
                cout << "key is not used" << endl;
            }
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "integer Key: " << endl;
            while (!(cin >> key) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "enter the integer key again" << endl;
            }
            cout << "String: " << endl;
            cin >> str;
            b = Cont.insert(key, str);
            if (b)
            {
                cout << "ready" << endl;
            }
            else
            {
                cout << "key is already in use" << endl;
            }
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "integer Key: " << std::endl;
            while (!(cin >> key) || (cin.peek() != '\n'))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "enter the integer key again" << endl;
            }
            result = Cont.find(key);
            if (result != "/0")
            {
                cout << result << endl;
            }
            else
            {
                cout << "Element not found" << endl;
            }
            system("pause");
            break;
        }
        
        answer = Menu_();
    }
	return 0;
}