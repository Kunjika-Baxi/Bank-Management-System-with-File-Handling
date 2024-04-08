#include<iostream>
#include<fstream>
using namespace std;
class Account 
{
   public : 
   int accno;float opbal;string cname;
   void get()
   {
      cout<<"\nEnter Customer's Details : ";
      accno = (rand()%500)+1;
      cout<<"\nEnter Customer's Name : ";
      cin>>cname;
      cout<<"\nEnter Opening Balance : ";
      cin>>opbal;
      cout<<"\nYour Account Number is : "<<accno;
   }
   void display()
   {
       cout<<"\n-------------------------------------\n";
       cout<<"\n\tDetails : ";
       cout<<"\nAccount Number : "<<accno;
       cout<<"\nCusotmer Name : "<<cname;
       cout<<"\nOpening Balance : "<<opbal;
       cout<<"\n-------------------------------------\n";
   }
};
Account a;
void write()
{
    ofstream fout;
    fout.open("Bank.dat",ios::app|ios::binary);
    a.get();
    fout.write((char*)&a,sizeof(a));
    fout.close();
    cout<<"\nData Added Successfully...";
}
void read()
{
    ifstream fin;
    fin.open("Bank.dat",ios::in|ios::binary);
    while(fin.read((char*)&a,sizeof(a)))
    {
        a.display();
    }
    fin.close();
}
void search()
{
    fstream fin;
    int acc,flag=0;
    fin.open("Bank.dat",ios::in|ios::binary);
    cout<<"\nEnter the Account Number whose details you want to search : ";
    cin>>acc;
    while(fin.read((char*)&a,sizeof(a)))
    {
        if(a.accno==acc)
        {
            flag=1;
            cout<<"\nRecord Found";
            a.display();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    fin.close();
}

void update()
{
    int ac,amt,fl=0;
    fstream f;
    f.open("Bank.dat",ios::out|ios::in|ios::binary);
    cout<<"\nEnter the Account Number whose Opening Balance you want to Update : ";
    cin>>ac;
    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.accno==ac)
        {
            fl=1;
            cout<<"\nRecord Found";
            cout<<"\nEnter the New Opening Balance : ";cin>>amt;
            int t=f.tellp();
            a.opbal=amt;
            f.seekp(t-sizeof(a));
            f.write((char*)&a,sizeof(a));
            cout<<"\nData Updated Successfully.....";
            break;
        }
    }
    if(fl==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    f.close();
}
void delete_specific()
{
    int ac,fl=0;
    fstream f;
    f.open("Bank.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("new.dat",ios::app|ios::binary);
    cout<<"\nEnter Account Number of the Account you want to close : ";
    cin>>ac;
    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.accno!=ac)
        {

            fout.write((char*)&a,sizeof(a));
        }
        else{
            fl=1;
        }
    }
    f.close();
    fout.close();
    remove("Bank.dat");
    rename("new.dat","bank.dat");
    cout<<"\nSuccessful";

}
void usera()
{
     fstream fin;
    int acc,flag=0;string pass;
    fin.open("Bank.dat",ios::in|ios::binary);
    cout<<"\nEnter the Account Number for Verification : ";
    cin>>acc;
    cout<<"\nEnter Password : ";
    cin>>pass;
    while(fin.read((char*)&a,sizeof(a)))
    {
        if((a.accno==acc) && (pass=="user_123#"))
        {
            flag=1;
            cout<<"\nAuthenticated User";
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nNot an Authenticated User!!!";
    }
    fin.close();
}
void deposit()
{
     fstream f;
    int acc,flag=0;float amtd;
    f.open("Bank.dat",ios::in|ios::out|ios::binary);
    cout<<"\nEnter the Account Number to which you want to deposit : ";
    cin>>acc;
    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.accno==acc)
        {
            flag=1;
            cout<<"\nRecord Found";
            cout<<"\nEnter the Amount you want to deposit : ";
            cin>>amtd;
            int t=f.tellp();
            a.opbal=a.opbal+amtd;
            f.seekp(t-sizeof(a));
            f.write((char*)&a,sizeof(a));
            cout<<"\nAmount Deposited Successfully.....";
            a.display();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    f.close();
}
void withdrawl()
{
      fstream f;
    int acc,flag=0;float amtd;
    f.open("Bank.dat",ios::in|ios::out|ios::binary);
    cout<<"\nEnter the Account Number from which you want to Withdraw : ";
    cin>>acc;
    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.accno==acc)
        {
            flag=1;
            cout<<"\nRecord Found";
            cout<<"\nEnter the Amount you want to Withdraw : ";
            cin>>amtd;
            if(amtd>a.opbal)
            {
                cout<<"\nYou cannot Withdraw!!!";break;
            }
            else if(a.opbal-amtd <1000)
            {
                cout<<"\nInsufficient Balance to Withdraw";break;
            }
            int t=f.tellp();
            a.opbal=a.opbal-amtd;
            f.seekp(t-sizeof(a));
            f.write((char*)&a,sizeof(a));
            a.display();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    f.close();
}
void check_balance()
{
     fstream f;
    int acc,flag=0;
    f.open("Bank.dat",ios::in|ios::out|ios::binary);
    cout<<"\nEnter the Account Number whose balance you want to search : ";
    cin>>acc;
    while(f.read((char*)&a,sizeof(a)))
    {
        if(a.accno==acc)
        {
            flag=1;
            cout<<"\nRecord Found";
            cout<<"\nYour Current Available Balance : "<<a.opbal;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    f.close();
}
int main()
{
    int ch;
    remove("Bank.dat");
    while(1)
    {
        cout<<"\nEnter\n1.Create Account\n2.Display All The Accounts\n3.Search specific Account\n4.Update Specific Account Opening Balance\n5.Close Account\n6.User Authentication\n7.Deposit\n8.Withdrawl\n9.Check Bank Balance\n10.EXIT";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:write();break;
            case 2:read();break;
            case 3:search();break;
            case 4:update();break;
            case 5:delete_specific();break;
            case 6:usera();break;
            case 7:deposit();break; 
            case 8:withdrawl();break;   
            case 9:check_balance();break;       
            case 10:exit(0);
            default:cout<<"\nInvalid Choice";
        }
    }
}