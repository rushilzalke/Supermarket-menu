#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
  int pcode;           //pcode = product code
  float price;         //price = product price
  float dis;           //dis=discount
  string pname;        //pname = product name

public:
  void menu ();
  void adminstrator ();
  void buyer ();
  void add ();
  void edit();
  void rem();
  void list ();
  void receipt ();
};

void shopping :: menu ()
{
    m:
  int choice;
  string email;
  string password;
  cout << "\t\t\t\t_____________________________________\n";
  cout << "\t\t\t\t                                     \n";
  cout << "\t\t\t\t         SUPERMARKET MAIN MENU       \n";
  cout << "\t\t\t\t                                     \n";
  cout << "\t\t\t\t_____________________________________\n";
  cout << "\t\t\t\t                                     \n";
  cout << "\t\t\t\t|   1) Adminstrator   |\n";
  cout << "\t\t\t\t|                    |\n";
  cout << "\t\t\t\t|   2) Buyer         |\n";
  cout << "\t\t\t\t|                    |\n";
  cout << "\t\t\t\t|   3) Exit          |\n";
  cout << "\t\t\t\t|                    |\n";
  cout << "\n\t\t\t Please Select! \n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email \n";
        cin>>email;
        cout<<"\t\t\t Password \n";
        cin>>password;

        if(email=="dsa@email.com" && password=="dsa123")
        {
            adminstrator();
        }
        else
        {
            cout<<" Invalid email/password ";
        }
        break;

        case 2:
        {
            buyer();
        }

        case 3:
        {
            exit(0);
        }
        default :
        {
            cout<<" Please select from the given options ";
        }
    }
goto m;
}

void shopping :: adminstrator()
{
    a:
    int choice;
    cout<<"\n\t\t\t|      Adminstrator menu        |";
    cout<<"\n\t\t\t|     1) Add the product         |";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|     2) Modify the product      |";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|     2) Delete the product      |";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|     4) Back to main menu       |";

    cout<<"\n\t\t   Please enter your choice :    ";
    cin>>choice;

    switch (choice)
    {
        case 1:
        add();
        break;

        case 2:
        edit();
        break;

        case 3:
        rem();
        break;

        case 4:
        menu();
        break;

        default :
        cout<<" Invalid choice ";

    }
    goto a;
}

void shopping :: buyer()
{
    b:
    int choice;
    cout<<"\t\t\t\t|     Buyer            |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|  1) Buy product      |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|  2) Go back          |\n";
    cout<<"\n\t\t\t|   Enter your choice :  ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();
        break;

        default :
        cout<<"Invalid Choice";

    }
    goto b;
}

void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product         " ;
    cout<<"\n\t\t\t  Product Code of Product :" ;
    cin>>pcode;
    cout<<"\n\n\t  Name of the Product:        ";
    cin>>pname;
    cout<<"\n\n\t  Price of the Product:       ";
    cin>>price;
    cout<<"\n\n\t  Discount on Product :       ";
    cin>>dis;

    data.open("datadsa.txt",ios::in);

    if(!data)
    {
        data.open("datadsa.txt",  ios::app|ios::out);
        data<<" "<<pcode<<"  "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c ==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    if(token==1)
    goto m;
    else{
        data.open("datadsa.txt",  ios::app|ios::out);
        data<<" "<<pcode<<"  "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
        }
}
    cout<<"\n\n\t\t   Record Inserted !";

}
void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c=0;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record  ";
    cout<<"\n\t\t\t Product code  ";
    cin>>pkey;

    data.open("datadsa.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File dosen't exist !";
    }
    else{
        data1.open("data1dsa.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t\t Product new code   : ";
                cin>>c;
                cout<<"\n\t\t\t Name of the product: ";
                cin>>n;
                cout<<"\n\t\t\t Price  :  ";
                cin>>p;
                cout<<"\n\t\t\t  Discount  : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\t\t  Record edited  ";
                token++;
            }
            else
            {
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("datadsa.txt");
        rename("data1dsa.txt","datadsa.txt");
        if (token==0)
        {
            cout<<"\t\t  Record not found !";
        }
    }
}
void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t\t\t\t  Delete product ";
    cout<<"\n\n\t\t\t\t  Product code  :";
    cin>>pkey;
    data.open("datadsa.txt", ios::in);
    if(!data)
    {
        cout<<"File dosent exist";
    }
    else
    {
        data1.open("datadsa.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t\t\t  Product deleted succesfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("datadsa.txt");
        rename("data1dsa.txt","datadsa.txt");
        if(token==0)
        {
            cout<<"\n\t\t\t Record not found";
        }
    }
}
void shopping:: list()
{
    fstream data;
    data.open("datadsa.txt",ios::in);
    cout<<"\n\t\t-----------------------------------------\n";
    cout<<"\tProno\t\tName\t\tPrice\n";
    cout<<"\n\t\t-----------------------------------------\n";
    data>>pcode>>pname>>price>>dis;
    while(data.eof())
    {
    data<<pcode<<"\t"<<pname<<"\t"<<price<<"\n";
    data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping:: receipt()
{
    fstream data;

    int arrc[100];    //c=code
    int arrq[100];    //q=Quantity
    char choice,y;
    int a=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t   RECEIPT   ";
    data.open("datadsa.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty  Datadsa   ";
    }
    else{
        data.close();

        list();
        cout<<"\n\t\t    -----------------------         \n";
        cout<<"\n\t\t    -----------------------         \n";
        cout<<"\n\t\t    Please place your order         \n";
        cout<<"\n\t\t    -----------------------         \n";
        cout<<"\n\t\t    -----------------------         \n";
    do
    {
        e:
        cout<<"\n\nEnter Product code";
        cin>>arrc[a];
        cout<<"\n\nEnter the quantity of product :";
        cin>>arrq[a];
        for(int i=0;i<a;i++)
        {
            if(arrc[a]==arrq[i])
            {
                cout<<"\n\n Duplicate product code. Please try again";
                goto e;
            }
        }
        a++;
        cout<<"\n\n  Do you want to buy another product ? if yes then press y else no";
        cin>>choice;
    }
        while(choice ==y);
        cout<<"\n\n\t\t\t__________________-Receipt-____________________\t\t\n";
        cout<<"\nproduct no\t product name\tproduct quantity\tprice\tamount\tamount of discount\n";

        for(int i=0;i<a;i++)
        {
            data.open("datadsa.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }

    cout<<"\n\n\t_______________________________________________________________";
    cout<<"\n Total Amount : "<<total;
}


int main()
{
    shopping r;
    r.menu();
}

