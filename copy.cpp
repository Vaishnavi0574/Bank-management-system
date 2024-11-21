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
        float balance;
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
    cout<<"\n3.Deposit";
    cout<<"\n4.Withraw";
    cout<<"\n5.Transfer";
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
      }
     cout<<"\n\n\t\tNew USer Account created Successfully"; 
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

void deposit()
{

}

void withdraw()
{ 

}

void transfer()
{

}

void payment()
{

}

void search_record()
{

}

void edit_record()
{

}

void delete_record()
{

}

void show_all_records()
{

}

void payment_record()
{

}


int main(){
    bank obj;
    obj.menu();
}