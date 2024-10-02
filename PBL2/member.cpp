#include <iostream>
#include "member.h"
using namespace std;
member::member() 
    :  hoten(""),  gender(true), sdt("")
{
    for(int i = 0;i < 7; i++)
    {
        lichtap[i] = false;
    }
    Setbirthday(0,0,0);
    SetNgayDangKy(0,0,0);
    SetNgayHetHan(0,0,0);
}
member::member(string hoten,bool gender,int dd,int mm, int yy, string sdt)
 :  hoten(hoten), gender(gender), sdt(sdt) 
{
    Setbirthday(dd,mm,yy);
    for(int i = 0;i < 7; i++)
    {
        lichtap[i] = false;
    }
    SetNgayDangKy(0,0,0);
    SetNgayHetHan(0,0,0);
}

string member::GetHoten() {
        return hoten;
    }

unsigned int member::GetTuoi() {
        return tuoi;
    }

bool member::GetGender() {
        return gender;
    }

struct tm member::GetBirthday() {
        return birthday;
    }

string member::GetSdt(){
        return sdt;
    }

bool member::GetLichtap(int index) {
        if (index >= 0 && index < 7) {
            return lichtap[index];
        }
        return false;
    }

struct tm member::GetNgayDangKy() {
        return ngayDangKy;
    }

struct tm member::GetNgayHetHan(){
        return ngayHetHan;
    }


void member::Setbirthday(int day, int month, int year) {
    birthday.tm_mday = day;
    birthday.tm_mon = month - 1; 
    birthday.tm_year = year - 1900; 
    time_t now = time(0);
    tm *currentTime = localtime(&now);

    tuoi = currentTime->tm_year - birthday.tm_year;

    if (currentTime->tm_mon < birthday.tm_mon || (currentTime->tm_mon == birthday.tm_mon && currentTime->tm_mday < birthday.tm_mday)) {
        tuoi--;
    }
}
void member::SetNgayDangKy(int day, int month, int year) 
{
    ngayDangKy.tm_mday = day;
    ngayDangKy.tm_mon = month - 1; 
    ngayDangKy.tm_year = year - 1900; 
}

void member::SetNgayHetHan(int day, int month, int year) 
{
    ngayHetHan.tm_mday = day;
    ngayHetHan.tm_mon = month - 1; 
    ngayHetHan.tm_year = year - 1900; 
}
bool member::isValidDate(int dd, int mm, int yy) {
   
    if (mm < 1 || mm > 12 || dd < 1 || dd > 31 || yy < 1900) {
        return false;
    }

   
    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) {
        return false; 
    } else if (mm == 2) {
        
        if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0 && yy % 100 == 0)) {
            if (dd > 29) {
                return false; 
            }
        } else {
            if (dd > 28) {
                return false; 
            }
        }
    }

    return true;
}
void member::Nhap() 
{
    cout << "Nhap thong tin cua hoi vien :" << endl;
     
    cout << "Ho va ten : "; 
    cin.ignore();
    getline(cin, hoten);
    
    cout << "Gioi tinh (Nam - 0, Nu - 1): ";
    while (!(cin >> gender) || (gender != 0 && gender != 1)) {
        cout << "Invalid input. Please enter 0 or 1 for gender: ";
        cin.clear();
        cin.ignore();
    }

    int dd, mm, yy;
    cout << "Nhap ngay thang va nam sinh (DD MM YYYY): ";
    while (!(cin >> dd >> mm >> yy) || !isValidDate(dd, mm, yy)) {
        cout << "Invalid date. Please enter a valid date: ";
        cin.clear();
        cin.ignore();
    }
    Setbirthday(dd, mm, yy);

    cout << "Sdt: "; 
    while (!(cin >> sdt)) {
        cout << "Invalid input. Please enter a valid phone number: ";
        cin.clear();
        cin.ignore();
    }
    cin.ignore();
}


void member::Xuat() 
{
    cout << setw(1) <<"*Name: " << setw(15) << hoten<<"\t*GT: ";
    if (gender) cout<<"Nu";
    else cout<<"Nam";
    cout<<"*Age: "<<setw(2)<<tuoi;
    cout <<"\t*NS: " << birthday.tm_mday << "/" << birthday.tm_mon + 1 << "/" << birthday.tm_year + 1900 << "\t*Sdt: " << sdt << "\t*Lich:  -";
    for (int i = 2; i < 8; i++) {
        if (lichtap[i - 2] == 1) {
            cout << "T" << i << "-";
        }
    }
    if (lichtap[6] == 1) {
        cout << "CN-";
    }
    if(ngayDangKy.tm_mday==0){
        cout<<"\tChua dang ki goi tap";
    }
    else{
        cout << " *RegDay: " << ngayDangKy.tm_mday << "/" << ngayDangKy.tm_mon + 1 << "/" << ngayDangKy.tm_year + 1900 ;
        cout << "  *ExpDay: " << ngayHetHan.tm_mday << "/" << ngayHetHan.tm_mon + 1 << "/" << ngayHetHan.tm_year + 1900 ;
    }
}

ostream& operator<<(ostream& out, const member& hv) 
{
    out << setw(1) << " *Name: " << setw(20) << hv.hoten << " *GT: ";
    if (hv.gender) 
        out << "Nu ";
    else 
        out << "Nam";
    cout<<"\t*Age: "<<setw(2)<<hv.tuoi;
    out << "\t*NS: " << setw(2) << hv.birthday.tm_mday << "/" << setw(2) << hv.birthday.tm_mon + 1 << "/" << hv.birthday.tm_year + 1900
        << "\t*Sdt: " <<setw(10)<< hv.sdt << "\t*Lich:  -";

    for (int i = 2; i < 8; i++) {
        if (hv.lichtap[i - 2] == 1) {
            out << "T" << i << "-";
        }
    }

    if (hv.lichtap[6] == 1) 
    {
        out << "CN-";
    }

    if (hv.ngayDangKy.tm_mday == 0) {
        out << "\tChua dang ki goi tap";
    } 
    else 
    {
        out << " *RegDay: " << setw(2) << hv.ngayDangKy.tm_mday << "/" << setw(2) << hv.ngayDangKy.tm_mon + 1 << "/" << hv.ngayDangKy.tm_year + 1900;
        out << "  *ExpDay: " << setw(2) << hv.ngayHetHan.tm_mday << "/" << setw(2) << hv.ngayHetHan.tm_mon + 1 << "/" << hv.ngayHetHan.tm_year + 1900;
    }

    return out;
}
void member::UpdateSDT(){
    cout<<"Nhap SDT moi: ";
    cin >> sdt;
}
void member::Dangki()
{
    cout<<"Chon ngay dang ki trong tuan : "<<endl;
    cout<<"Chon (1) - Bo (0)"<<endl;
    int i= 2;
    do{
        if(i!=8) cout<<"Thu "<<i<<": ";
        else cout<<"Chu nhat: ";
        cin>>lichtap[i-2];
        while(lichtap[i-2]!=0 && lichtap[i-2]!=1)
        {
            cout<<"\nNhap khong hop le!! Vui long nhap lai:"<<endl;
            cin>>lichtap[i-2];
        } i++;
        
    } while(i < 9);
}
void member::DangkyGoiTap()
{
    int dd,mm,yy;
    cout<<"Nhap ngay thang va nam dang ky goi tap: ";
    cin>>dd>>mm>>yy;
    SetNgayDangKy(dd,mm,yy);
    cout<<"Nhap ngay thang va nam het han goi tap: ";
    cin>>dd>>mm>>yy;
    SetNgayHetHan(dd,mm,yy);
}
istream& operator>>(istream& in, member& mb) 
{
    in >> mb.gender;
    int day, month, year;
    in >> day >> month >> year;
    mb.Setbirthday(day, month, year);
    in >> mb.sdt;
    for (int i = 0; i < 7; i++) 
    {
        in >> mb.lichtap[i];
    }
    in >> day >> month >> year;
    mb.SetNgayDangKy(day, month, year);
    in >> day >> month >> year;
    mb.SetNgayHetHan(day, month, year);
    getline(in, mb.hoten);
    return in;
}