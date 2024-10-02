#include <iostream>
#include <iomanip>
#include "Device.h"
using namespace std;
Device::Device()
{
    this->giaNhap = 10000;
    this->tenTb = "MSC";
    this->tinhTrang = 1;
    this->MaQl = "000";
    this->ngayNhap = 0;
}
Device::Device(float gia, string name, string ms, bool x, int day)
    :giaNhap(gia), tenTb(name), MaQl(ms), tinhTrang(x), ngayNhap(day)
{

}
Device::~Device()
{

}
istream& operator>>(istream& i, Device& t)
{
    
    cout <<"Nhap ten thiet bi:";
    cin.ignore();
    getline(i,t.tenTb);
    
    cout <<"Nhap MaQl: ";
    
    i >> t.MaQl;
    
    cout <<"Nhap gia thiet bi:";
    cin.ignore();
    i >> t.giaNhap;
    
    cout <<"Nhap tinh trang ban dau: ";
    cin.ignore();
    i >> t.tinhTrang;
    
    cout <<"Nam nhap thiet bi: ";
    cin.ignore();
    i >>t.ngayNhap;
    return i;
}
ostream& operator<<(ostream& o, const Device& t)
{
    o <<"TenTB:" << setw(20) << t.tenTb <<"\tMaQL: "<< t.MaQl <<"\tTinhTrang: "<<setw(8) ;
    if(t.tinhTrang) o<<"Tot";
    else o<<"Bi hong";
     o <<"\tNam nhap:"<< t.ngayNhap;
    return o;
}
void Device::Show()
{
    cout<<"TenTB:"<<setw(10)<<this->tenTb<<"\tMaQL: "<<this->MaQl<<"\tTinhTrang: "<<this->tinhTrang<<setw(5) << this->ngayNhap;
}
const Device& Device::operator=(const Device& d)
{
    if(this != &d)
    {
        this->tenTb = d.tenTb;
        this->MaQl = d.MaQl; 
        this->tinhTrang = d.tinhTrang; 
        this->ngayNhap = d.ngayNhap;
        this->giaNhap = d.giaNhap;
    }
    return *this;
}
float Device::KhauHao(const Device& t)
{
    return this->giaNhap / t.ngayNhap;
}

