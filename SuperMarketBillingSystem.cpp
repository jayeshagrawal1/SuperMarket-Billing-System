#include "iostream"
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int mainmenu(void);
void error(void);
void add(void);
void modfy(void);
int modify(void);
int billing_items(void);
void del(void);
class item{
    // friend void list(void);
    int item_code;
    int quantity=0;
    float price=0;
    string name;
    public:
    item(){}
    item(int ic,int q,float p,string n){
        item_code=ic;
        quantity=q;
        price=p;
        name=n;
    }
    int update(int x){
        ofstream neww;
        ifstream old;
        neww.open("it.txt",ios::out|ios::binary);
        old.open("ItemList.txt",ios::in|ios::binary);
        if(!old){
            cout<<"No Records"<<endl;
            return 0;
        }
        old.seekg(0);
        while (old>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price)
        {   
            // fin>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price;
            if(x==item_code){
                gotoxy(20,2);
                cout<<"Enter what you want to change:"<<endl;
                gotoxy(20,3);
                cout<<"1.Itemcode"<<endl;
                gotoxy(20,4);
                cout<<"2.Name"<<endl;
                gotoxy(20,5);
                cout<<"3.Quantity"<<endl;
                gotoxy(20,6);
                cout<<"4.Price"<<endl;
                gotoxy(20,7);
                int a;
                cin>>a; 
                switch(a){
                    case 1:{
                        cout<<"Enter the new \'Item Code\' of the product:"<<endl;
                        cin>>item_code;
                        break;
                    }
                    case 2:{
                        cout<<"Enter the new \'Name\' of the product:"<<endl;
                        cin.ignore();
                        getline(cin,name);
                        break;
                    }
                    case 3:{
                        cout<<"Enter the new \'Quantity\' of the product:"<<endl;
                        cin>>quantity;
                        break;
                    }
                    case 4:{
                        cout<<"Enter the new \'Price\' of the product:"<<endl;
                        cin>>price;
                        break;
                    }
                    default:{
                        cout<<"Invalid option"<<endl;
                        getch();
                    }
                }
                // fin.seekp(fin.tellp()-sizeof(*this));
                // fin<<endl;
            }
            neww<<item_code<<setw(30)<<name<<setw(20)<<quantity<<setw(20)<<price<<endl;
        }
        old.close();
        neww.close();
        remove("Itemlist.txt");
        rename("it.txt","ItemList.txt");
        return(0);
    }
    int update(string x){
        ofstream neww;
        ifstream old;
        neww.open("it.txt",ios::out|ios::binary);
        old.open("ItemList.txt",ios::in|ios::binary);
        if(!old){
            cout<<"No Records"<<endl;
            return 0;
        }
        old.seekg(0);
        while (old>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price)
        {   
            // fin>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price;
            if(x==name){
                gotoxy(20,2);
                cout<<"Enter what you want to change:"<<endl;
                gotoxy(20,3);
                cout<<"1.Itemcode"<<endl;
                gotoxy(20,4);
                cout<<"2.Name"<<endl;
                gotoxy(20,5);
                cout<<"3.Quantity"<<endl;
                gotoxy(20,6);
                cout<<"4.Price"<<endl;
                gotoxy(20,7);
                int a;
                cin>>a; 
                switch(a){
                    case 1:{
                        cout<<"Enter the new \'Item Code\' of the product:"<<endl;
                        cin>>item_code;
                        break;
                    }
                    case 2:{
                        cout<<"Enter the new \'Name\' of the product:"<<endl;
                        cin.ignore();
                        getline(cin,name);
                        break;
                    }
                    case 3:{
                        cout<<"Enter the new \'Quantity\' of the product:"<<endl;
                        cin>>quantity;
                        break;
                    }
                    case 4:{
                        cout<<"Enter the new \'Price\' of the product:"<<endl;
                        cin>>price;
                        break;
                    }
                    default:{
                        cout<<"Invalid option"<<endl;
                        getch();
                    }
                }
                // fin.seekp(fin.tellp()-sizeof(*this));
                // fin<<endl;
            }
            neww<<item_code<<setw(30)<<name<<setw(20)<<quantity<<setw(20)<<price<<endl;
        }
        old.close();
        neww.close();
        remove("Itemlist.txt");
        rename("it.txt","ItemList.txt");
        return(0);
    }   
     void file(void){
        ofstream fout;
        fout.open("ItemList.txt",ios::app|ios::binary);
        fout<<item_code<<setw(30)<<name<<setw(20)<<quantity<<setw(20)<<price<<endl;
        fout.close();
    }
    void removee(int ic){
        ofstream neww;
        ifstream old;
        neww.open("it.txt",ios::out|ios::binary);
        old.open("ItemList.txt",ios::in|ios::binary);
        while (old>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price)
        {
            // old>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price;
            if(ic!=item_code){
            neww<<item_code<<setw(10)<<name<<setw(10)<<quantity<<setw(10)<<price<<endl;
            }
        }
        neww.close();
        old.close();
        remove("Itemlist.txt");
        rename("it.txt","ItemList.txt");
    }
    int display(void){
        ifstream fin;
        float total=0;
        fin.open("Itemlist.txt",ios::in|ios::binary);
        if(!fin){
            cout<<"No Records"<<endl;
            return 0;
        }
        while (fin>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price)
        {   
            // fin>>item_code>>setw(10)>>name>>setw(10)>>quantity>>setw(10)>>price;
            cout<<item_code<<setw(20)<<name<<setw(20)<<quantity<<setw(15)<<"Rs"<<price<<endl;
            total+=(price*quantity);
        }
        cout<<"***********************************************************************"<<endl;
        cout<<setw(57)<<"Grand Total: Rs"<<total<<endl;
        cout<<"***********************************************************************"<<endl;
        cout<<"\n"<<setw(10)<<"Press any key to exit."<<endl;
        fin.close();
        return(0);
    }
};
void list(void){
    system("cls");
    int x;
    gotoxy(30,2);
    cout<<"Item List"<<endl;
    gotoxy(27,4);
    cout<<"+-+-+-+-+-+-+-+"<<endl;
    cout<<endl;
    cout<<"Enter the variety of products you wanna buy:";
    cin>>x;
    item i[x];
    for (int j = 0; j < x; j++){
        int ic;int q;float p;string n;
        cout<<"Enter the name of "<<j+1<<" item:";
        cin.ignore();
        getline(cin,n);
        cout<<"Enter its price:";
        cin>>p;
        cout<<"Enter its Itemcode:";
        cin>>ic;
        cout<<"Enter its Quantity:";
        cin>>q;
        i[j]={ic,q,p,n};
        i[j].file();
    }
}
int billing_items(void){
    int a;
    system("cls");
    gotoxy(30,2);
    cout<<"Billing Items"<<endl;
    gotoxy(27,4);
    cout<<"+-+-+-+-+-+-+-+"<<endl;
    gotoxy(27,6);
    cout<<"1.Item list"<<endl;
    gotoxy(27,7);
    cout<<"2.Back to mainmenu"<<endl;
    gotoxy(27,9);
    cout<<"Please Enter Required Option:";
    cin>>a;
    try{
        if(a==1){
            list();
            return 0;
        }
        if(a==2){
            mainmenu(); 
            return 0;
        }
        Beep(400,1000);
        throw a;
    }
    catch(int a){
        error();
        cin>>a;
        if(a==1){
            list();
            return 0;
        }
        else if(a==2){
            mainmenu();
            return 0;
        }
        else{
            Beep(400,1000);
            exit(0);
        }
    }
}
int modify(void){
    system("cls");
    int a;
    gotoxy(35,3);
    cout<<"Bill Editor "<<endl;
    gotoxy(32,4);
    cout<<"*****************"<<endl;
    gotoxy(26,6);
    cout<<"1. Add item details"<<endl;
    gotoxy(26,7);
    cout<<"2. Edit item details"<<endl;
    gotoxy(26,8);
    cout<<"3. Delete item details"<<endl;
    gotoxy(26,9);
    cout<<"4. Back to main menu"<<endl;
    gotoxy(26,10);
    cout<<"Enter appropriate option"<<endl;
    cin>>a;
    try{
        if(a==1){
            add();
            return 0;
        }
        else if(a==2){
            modfy();
            return 0;
        }
        else if(a==3){
            del();
            return 0;
        }
        else if(a==4){
            mainmenu();
            return 0;
        }
        else{
            Beep(400,1000);
            throw a;
        }
    }
    catch(int a){
        error();
        cin>>a;
        if(a==1){
            add();
            return 0;
        }
        else if(a==2){
            modfy();
            return 0;
        }
        else if(a==3){
            del();
            return 0;
        }
        else if(a==4){
            mainmenu();
            return 0;
        }
        else{
        Beep(400,1000);
        exit(0);
        }
    }
}
void add(void){
    system("cls");
    list();
}
void del(void){
    system("cls");
    item n;
    int ic;
    gotoxy(32,3);
    cout<<"Enter the Item Details Code you want to delete:"<<endl;
    cin>>ic;
    n.removee(ic);
}
void modfy(void){
    system("cls");
    gotoxy(32,3);
    cout<<"Choose in what way you want to change:"<<endl;
    gotoxy(32,4);
    cout<<"1.Item Code"<<endl;
    gotoxy(32,5);
    cout<<"2.Name"<<endl;
    gotoxy(32,7);
    cout<<"Enter your choice:"<<endl;
    int a;
    cin>>a;
    item i;
    switch(a){
        case 1:
        {
            cout<<"Enter the Item Code:"<<endl;
            int ic; 
            cin>>ic;
            system("cls");
            i.update(ic);
            break;
        }
        case 2:
        {
            cout<<"Enter the name :"<<endl;
            string n; 
            cin.ignore();
            getline(cin,n);
            system("cls");
            i.update(n);
            break;
        }
        default:{
            cout<<"Choose a valid option."<<endl;
            getch();
            modfy();
        }    
    }
}
void bill_details(void){
    system("cls");
    item i;
    cout<<"***********************************************************************"<<endl;
    cout<<setw(42)<<"Bill Details "<<endl;
    cout<<"***********************************************************************"<<endl;
    cout<<"Item Code"<<setw(20)<<"Name of Item"<<setw(16)<<"Quantity"<<setw(15)<<"Price"<<endl;
    cout<<"***********************************************************************"<<endl;
    i.display();
}

int mainmenu(void){
    system("cls");
    int a;
    gotoxy(30,3);
    for(int i=0;i<32;i++){
        cout<<"=";
    }
    cout<<endl;
    gotoxy(32,5);
    cout<<"SUPER MARKET BILLING SYSTEM"<<endl;
    gotoxy(30,7);
    for(int i=0;i<32;i++){
        cout<<"=";
    }
    cout<<endl;
    gotoxy(28,9);
    cout<<"1. Billing Items"<<endl;
    gotoxy(28,10);
    cout<<"2. Add/Remove/Edit Item"<<endl;
    gotoxy(28,11);
    cout<<"3. Show Item Details"<<endl;
    gotoxy(28,12);
    cout<<"4. Exit"<<endl;
    gotoxy(28,14);
    a=0;
    cout<<"Please Enter Required Option:";
    cin>>a;
    try{
        if(a==1){
            billing_items();
            return 0;
        }
        if(a==2){
            modify();
            return 0;
        }
        if(a==3){
            bill_details();
            return 0;
        }
        if(a==4){
            exit(0);
            return 0;
        }
        else{
            Beep(500,1000);
            throw a;
        }
    }
    catch(int){
        error();
        cin>>a;
        if(a==1){
            billing_items();
            return 0;
        }
        if(a==2){
            modify();
            return 0;
        }
        if(a==3){
            bill_details();
            return 0;
        }
        if(a==4){
            exit(0);
            return 0;
        }
        else {
            Beep(500,1000);
            exit(0);
        }
    }
}
void error(void){
    cout<<"Please Enter a valid option :";    
}
int main()
{
    mainmenu();
    getch();
    return(0);
}