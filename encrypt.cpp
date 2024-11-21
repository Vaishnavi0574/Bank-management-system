#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<fstream>
using namespace std;
class bank
{   private:
        int pin;
        string id,name ,fname,address,phone,pass;
        double balance;
    public:
        void menu();
        void bank_management();
        void atm_management();
        void new_user();
        void already_a_user();
        void deposit();
        void withdraw();
        void transfer();
        void payment();
        void search_record();
        void edit_record();
        void delete_record();
        void show_all_records();
        void payment_record();
};

void bank::menu()
{    
    p:
    system("cls");
    int choice;
    string email,pin,pass;
    char ch;
    cout<<"\n\n\t\tControl Panel";
    cout<<"\n\n1.Bank MAnagement";
    cout<<"\n2.ATM MAnagement";
    cout<<"\n3.EXIT";
    cout<<"\n\nEnter Your Choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"\n\n\t\tLogin Account";
            cout<<"\n\nEnter Email :";
            cin>>email;
            cout<<"\nEnter PIN :";
            for(int i=0;i<5;i++){
                ch=getch();
                pin+=ch;
                cout<<"*";
            }
            cout<<pin;
            cout<<"\nPassword :";
            for(int i=0;i<5;i++){
                ch=getch();
                pass+=ch;
                cout<<"*";
            }
            cout<<pass;
            if(email=="vaishnavisingh0574@gmail.com" && pin=="12345" && pass=="hello"){
                bank_management();
            }
            else{
                cout<<"\n\nYour credential are wrong";
            }
            break;
        case 2:
            atm_management();
            break;
        case 3:
            exit(0);
        default:
            cout<<"\n\n Invalid Choice...Please try again";
    }
    getch();
    goto p;
}

void bank::atm_management()
{   
    p:
    int choice;
    system("cls");
    cout<<"\n\n\t\tATM Management";
    cout<<"\n\n1.User Login & Check Balance";
    cout<<"\n2.Withraw Amount";
    cout<<"\n3.Account Details";
    cout<<"\n4.GO Back";
    cout<<"\n\nEnter your Choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menu();
        default:
            cout<<"\n\n Invalid Choice...Please try again";
    }
    getch();
    goto p;
}

void bank::bank_management()
{
    p:
    int choice;
    system("cls");
    cout<<"\n\n\t\tBank Management";
    cout<<"\n\n1.New User";
    cout<<"\n2.Already a user";
    cout<<"\n3.Deposit Money";
    cout<<"\n4.Withraw Money";
    cout<<"\n5.Transfer Money";
    cout<<"\n6.Payment";
    cout<<"\n7.Search  User Record";
    cout<<"\n8.Edit Your Records";
    cout<<"\n9.Delete your Records";
    cout<<"\n10.Show All Records";
    cout<<"\n11.Payment All Records";
    cout<<"\n12.GO Back";
    cout<<"\n\nEnter your Choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:
            new_user();
            break;
        case 2:
            already_a_user();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
        transfer();
            break;
        case 6:
        payment();
            break;
        case 7:
            search_record();
            break;
        case 8:
            edit_record();
            break;
        case 9:
            delete_record();
            break;
        case 10:
            show_all_records();
            break;
        case 11:
            payment_record();
            break;
        case 12:
            menu();
        default:
            cout<<"\n\n Invalid Choice...Please try again";
    }
    getch();
    goto p;
}

void bank::new_user()
{     p:
      system("cls");
      fstream file;
      int p;
      float b;
      string n,f,pa,ph,a,i;
      cout<<"\n\n\t\tAdd New User :";
      cout<<"\n\nUser Id :";
      cin>>id;
      cout<<"\nName :";
      cin>>name;
      cout<<"\nPIN :";
      cin>>pin;
      cout<<"\nPassword :";
      cin>>pass;
      cout<<"\nFather's Name:";
      cin>>fname;
      cout<<"\nAddress :";
      cin>>address;
      cout<<"\nPhone :";
      cin>>phone;
      cout<<"\nCurrent Balnace :";
      cin>>balance;
      file.open("bank.txt",ios::in);
      if(!file){
        file.open("bank.txt",ios::app|ios::out);
        file<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n"; 
        file.close();
      }
      else{
        file>>i>>n>>p>>pa>>f>>a>>ph>>b;
        while(!file.eof()){
            if(id==i){
                cout<<"\n\nUser Id already exist...Please try with another id";
                getch();
                goto p;
            }
            file>>i>>n>>p>>pa>>f>>a>>ph>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n"; 
        file.close();
        cout<<"\n\n\t\tNew User Account created Successfully"; 
      }
     
}

void bank::already_a_user()
{
    string test_id;
    bool found=false;
    system("cls");
    fstream file;
    cout<<"\n\n\t\tAlready A User";
    file.open("bank.txt",ios::in);
    if(!file) 
    {
        cout<<"\n\n\t\tError Opening a file..";
    }
    else
    {
        cout<<"\n\nEnter Your User Id : ";
        cin>>test_id;
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        while(!file.eof())
        {
            if(test_id==id)
            {
                system("cls");
                cout<<"\n\n\t\tAlready User Account";
                cout<<"\n\nUser Id : "<<id<<"\nName :"<<name;
                found=true;
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        }
        file.close();
        if(found==false)
        {
            cout<<"\n\n\t\tUser Id Not Found";
        }
    }
}

void bank::deposit()
{
    bool found=false;
    string test_id;
    fstream file,file1;
    float dep;
    system("cls");
    cout<<"\n\n\t\tDeposit Money";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\tError Opening a file..";
    }
    else{
        cout<<"\n\nEnter Your User Id : ";
        cin>>test_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        while(!file.eof())
        {
            if(test_id==id)
            {
                cout<<"\n\nAmount For Deposit :";
                cin>>dep;
                balance+=dep;
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n"; 
                found=true;
                cout<<"\n\n\t\tAmount->"<<dep<<"  Deposit Successfully";
            }
            else{
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==false)
        {
            cout<<"\n\n\t\tUser Id Not Found";
        }

    }
}

void bank:: withdraw()
{ 
    bool found=false;
    string test_id;
    fstream file,file1;
    float with;
    system("cls");
    cout<<"\n\n\t\tDeposit Money";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\tError Opening a file..";
    }
    else{
        cout<<"\n\nEnter Your User Id : ";
        cin>>test_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        while(!file.eof())
        {
            if(test_id==id)
            {
                cout<<"\n\nAmount For Withdraw :";
                cin>>with;
                if(balance>=with)
                {
                    balance-=with;
                    file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n"; 
                    found=true;
                    cout<<"\n\n\t\tYour Amount->"<<with<<" withdraw Successfully";
                }
                else
                {
                    cout<<"\n\n\t\tInsufficient Balance. \nCurrent Balance"<<balance;
                    found=true;
                }
            }
            else{
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==false)
        {
            cout<<"\n\n\t\tUser Id Not Found";
        }

    }
}

void bank::transfer()
{
    fstream file,file1;
    system("cls");
    string s_id,r_id;
    float amt;
    int count=0;
    cout<<"\n\t\tPayment transfer option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\tError Opening a file..";
    }
    else
    {
       cout<<"\n\nEnter Sender User id :";
       cin>>s_id;
       cout<<"\n\nEnter Reciever User id :";
       cin>>r_id;
       cout<<"\n\nEnter Amount To Transfer :";
       cin>>amt; 
       file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance; 
       while(!file.eof())
       { 
            if(id==s_id && amt<=balance )
            {
                count++;
            }
            else if(id==r_id)
            {
                count++;
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance; 
        }
        file.close();
        // cout<<"\n"<<count;
        if(count==2)
        {
            file.open("bank.txt",ios::in);
            file1.open("temp.txt",ios::app|ios::out);
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
            while(!file.eof())
            {
                if(id==s_id )
                {
                    balance-=amt;
                    file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
                }
                else if(id==r_id)
                {
                    balance+=amt;
                    file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
                }
                else
                {
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
            }
            cout<<"\nPayment done Successfully";
            file1.close();
            file.close();
            remove("bank.txt");
            rename("temp.txt","bank.txt");
        }
        else 
        {
            cout<<"\nTransaction id not found or Current balance is low..";
        }
    }
}

void bank::payment()
{
    system("cls");
    fstream file,file1;
    string t_id,b_name;
    float amount;
    bool found;
    SYSTEMTIME x;
    cout<<"\n\t\tBills Payment Option";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nError opening the file..";
    }
    else
    {
        cout<<"\n\nEnter User ID :";
        cin>>t_id;
        cout<<"\nBill Name :";
        cin>>b_name;
        cout<<"\nBill Amount :";
        cin>>amount;
        file1.open("temp.txt",ios::app|ios::out);
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance; 
        while(!file.eof())
        {
            if(t_id==id && amount<=balance)
            {
                balance-=amount;
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";

                found=true;
            }
            else
            {
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance; 
        }
        file1.close();
        file.close();
        remove("bank.txt");
        rename("temp.txt","bank.txt");
        if(found)
        {
            GetSystemTime(&x);
            file.open("bill.txt",ios::app|ios::out);
            file<<t_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
            file.close();
            cout<<"\n"<<b_name<<" Bill Paid Successfully";
        }
        else
        {
            cout<<"\nWrong ID or Amount Invalid ...";
        }
    }
}

void bank:: search_record()
{
    system("cls");
    fstream file;
    string t_id;
    bool found =false;
    cout<<"\n\n\t\tSearch User Record";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nError opening file";
    } 
    else
    {
        cout<<"\n\nEnter Uder Id :";
        cin>>t_id;
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance; 
        while(!file.eof())
        {
            if(id==t_id)
            {
                system("cls");
                cout<<"\nUser Id-"<<id<<" "<<"\nName-"<<name<<" ";
                cout<<"\nFather's name-"<<fname<<"\nAddres-"<<address<<"\nPhone-"<<phone<<"\nBalance-"<<balance<<"\n";
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        }
        file.close();
        if(found==false){
            cout<<"\nRecord not found";
        }
    }
}

void bank::edit_record()
{
   system("cls");
   fstream file,file1;
   string t_id,f,n,pa,a,ph;
   bool found;
   int p;
   cout<<"\n\n\t\tEdit User Record";
   file.open("bank.txt",ios::in);
   if(!file)
   {
       cout<<"\n\nError openoing file..";
   }
   else
   {
       cout<<"\n\nEnter Uder Id :";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance; 
        while(!file.eof())
        {
            if(id==t_id)
            {
                cout<<"\nName :";
                cin>>n;
                cout<<"\nPIN :";
                cin>>p;
                cout<<"\nPassword :";
                cin>>pa;
                cout<<"\nFather's Name:";
                cin>>f;
                cout<<"\nAddress :";
                cin>>a;
                cout<<"\nPhone :";
                cin>>ph;
                file1<<id<<" "<<n<<" "<<p<<" "<<pa<<" "<<f<<" "<<a<<" "<<ph<<" "<<balance<<"\n";
                cout<<"\nRecord Updated Successfully";
                found=true;
            }
            else
            {
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        }
        file1.close();
        file.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==false){
            cout<<"\nRecord not found";
        }
   }
}

void bank:: delete_record()
{
    system("cls");
   fstream file,file1;
   string t_id;
   bool found;
   cout<<"\n\n\t\tEdit User Record";
   file.open("bank.txt",ios::in);
   if(!file)
   {
       cout<<"\n\nError openoing file..";
   }
   else
   {
       cout<<"\n\nEnter Uder Id :";
        cin>>t_id;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance; 
        while(!file.eof())
        {
            if(id==t_id)
            {
                cout<<"\nRecord deleted Successfully";
                found=true;
            }
            else
            {
                file1<<id<<" "<<name<<" "<<pin<<" "<<pass<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        }
        file1.close();
        file.close();
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        if(found==false){
            cout<<"\nRecord not found";
        }
   }
}

void bank:: show_all_records()
{
    system("cls");
    fstream file;
    cout<<"\n\n\t\tAll Records";
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nError opening the records";
    }
    else
    {
        file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        cout<<"\n\nID     "<<"  Name"<<"     fname"<<"      Phone"<<"     balance"<<"\n"; 
        while(!file.eof())
        {
            cout<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<phone<<" "<<balance<<"\n";
            file>>id>>name>>pin>>pass>>fname>>address>>phone>>balance;
        }
        file.close();
    }
}

void bank:: payment_record()
{
    system("cls");
    fstream file;
    bool found=false;
    float amount;
    string c_date;
    cout<<"\n\n\t\tAll Bills Records";
    file.open("bill.txt",ios::in);
    if(!file)
    {
        cout<<"\nError opening the records";
    }
    else
    {
        file>>id>>name>>amount>>c_date;
        while(!file.eof())
        {
            cout<<"\n\nUser ID :"<<id;
            cout<<"\n\nBill Name:"<<name;
            cout<<"\n\nBill Amount :"<<amount;
            cout<<"\n\nDate :"<<c_date;
            cout<<"\n\n==================================================";
            file>>id>>name>>amount>>c_date;
            found=true;
        }
        file.close();
        if(found==false)
        {
            cout<<"No Data Available..";
        }
    }
}


int main(){
    bank obj;
    obj.menu();
}