#include <iostream>
#include <iomanip>
#include <string.h>
#include <fstream>
#include "SubAdmin.h"
using namespace std;
SubAdmin::SubAdmin(int n)
        :size(n)
{
    if(this->size == 0) this->Subadmin = nullptr;
    else
    {
        this->Subadmin = new Admin[n];
    }
}
SubAdmin::~SubAdmin()
{
    delete[] this->Subadmin;
}
int SubAdmin::GetSize()
{
    return this->size;
}
void SubAdmin::Show()
{
    cout<<"Danh sach nhan vien"<<endl;
    for ( int i = 0; i < this->size; i++)
    {
        cout << i <<". " <<*(this->Subadmin + i) << endl;
    }
}

const SubAdmin& SubAdmin::operator=(const SubAdmin& s)
{
    if( this != &s)
    {
        this->size = s.size;
        for ( int i = 0; i < this->size; i++)
        {
            *(this->Subadmin + i) = s.Subadmin[i];
        }
    }
    return *this;
}
void Add(SubAdmin& s, const Admin& t)
{
    Admin* new_Subadmin = new Admin[s.size + 1];
    for (int i = 0; i < s.size; i++) {
        new_Subadmin[i] = s.Subadmin[i];
    }
    new_Subadmin[s.size] = t;
    delete[] s.Subadmin;
    s.Subadmin = new_Subadmin;
    s.size++;
}
void Delete(SubAdmin& s, int k)
{
    if (k >= 0 && k < s.size)
    {
        for (int i = k; i < s.size - 1; i++)
        {
            s.Subadmin[i] = s.Subadmin[i + 1];
        }
        s.size--;
        cout << "Da xoa nhan vien" << endl;
        OutputFile(s);
    }
    else
    {
        cout << "Vi tri can xoa khong hop le!!!";
    }
}
void InputFile(SubAdmin& s)
{
    ifstream file("SubAdmin.txt");
    if(file.fail())
    {
        cout << "Failed\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
    Admin ad;
    if(iss>>ad ) {
        Add(s,ad);
    }
    }
    file.close();
}

void OutputFile(SubAdmin& a){
    ofstream file("SubAdmin.txt");
    for(int i = 0;i < a.size; i++)
    {
                
        file <<"\n" << a.Subadmin[i].getnameUser() <<"\t";
        file << a.Subadmin[i].getPass()<<"\t";
        file << a.Subadmin[i].getHoten();
    }
    file.close();
}
bool GetID(SubAdmin& l, string id){
    int i=0;
    while (i<l.GetSize()){
        string temp = l.Subadmin[i].getnameUser();
        if (strcmp(id.c_str() ,temp.c_str()) == 0){
            return true;
        }
        i++;
    }return false;
}
bool GetPIN(SubAdmin& sa, string pin){
    int i=0;
    while (i<sa.GetSize()){
        string temp = sa.Subadmin[i].getPass();
        if (strcmp(pin.c_str() ,temp.c_str())==0){ 
            return true;
        }
        i++;
    }return false;
}
int findbyid(SubAdmin& sa,string id){
    int i=0;
    while (i<sa.size){
        if (strcmp(id.c_str() ,sa.Subadmin[i].getnameUser().c_str())==0){ 
            return i;
        }
        i++;
    }return -1;
}
void changepassbyid(SubAdmin& sa,string id){
    int i = findbyid(sa,id);
    if(i>=0) {
        sa.Subadmin[i].ChangePass();
    }
    
}
void changepassbystt(SubAdmin& sa,int k){
    sa.Subadmin[k].ChangePass();
}