#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "Admin.h"
using namespace std;

Admin::Admin(string name, string user, string pass)
    :Ho_ten(name),name_user(user), password(pass)
{

}
Admin::~Admin()
{

}
void Admin::ChangePass()
{
    string newPass;
    cout <<"Nhap Mat khau moi: " << endl;
    cin.ignore();
    getline(cin, newPass);
    this->password = newPass;
    cout<<"Thay doi mat khau thanh cong";
}
ostream& operator<<(ostream& o, Admin& a){
    o<<" User:"<<setw(10)<<a.name_user<<"\tPassword:"<<setw(10)<<a.password<<"\tHo ten: "<<a.Ho_ten;
    return o;
}
istream& operator>>(istream& in, Admin& a){
    in >> a.name_user;
    in >> a.password;
    in >> a.Ho_ten;
    return in;
}
void Admin::Nhap(){
    cout<<"Nhap thong tin nhap vien: "<<endl;
    cout<<"Ho ten: ";
    cin.ignore();
    getline(cin,Ho_ten);
    cout<<"User: ";
    cin >> name_user;
    cout<<"Password: ";
    cin >> password;
    

}
string Admin::getHoten()
{
    return this->Ho_ten;
}
string Admin::getnameUser()
{
    return this->name_user;
}
string Admin::getPass()
{
    return this->password;
}
bool GetPass(Admin& a, string pin)
{
    string temp = a.getPass();
    if(strcmp(temp.c_str(), pin.c_str()))
    {
        return 1;
    }
    else return 0;
}
bool GetUser(Admin& a, string id)
{
    string temp = a.getnameUser();
    if ( strcmp(temp.c_str() , id.c_str()) == 0) 
    {
        return true;
    } else return false;
}
void InputFile(Admin& s)
{
    ifstream file("admin.txt");
    if(file.fail())
    {
        cout << "Failed\n";
        return;
    }
    Admin ad;
    while (file >> ad.name_user >> ad.password) {
        cout <<"Ho ten: " << ad.Ho_ten << "User: " << ad.name_user << ", Password: " << ad.password << endl;
    }
    file.close();
}
void OutputFile(Admin& a)
{
    ofstream file("admin.txt");
    file << a.Ho_ten;
    file <<"\n" << a.name_user<<"\t";
    file << a.password;
    file.close();
}