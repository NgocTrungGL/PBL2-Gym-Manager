#include <iostream>
#include <iomanip>
#include <fstream>
#include "DeviceList.h"
using namespace std;
DeviceList::DeviceList(int n)
        :size(n)
{
    if(this->size == 0) this->data = nullptr;
    else
    {
        this->data = new Device[n];
    }
}
DeviceList::~DeviceList()
{
    delete[] this->data;
}
void DeviceList::Show()
{
    cout <<"Danh sach thiet bi" << endl;
    for ( int i = 0; i < this->size; i++)
    {
        cout <<i<<". "<< *(this->data + i)<<endl;
    }
}
const DeviceList& DeviceList::operator=(const DeviceList& s)
{
    if( this != &s)
    {
        this->size = s.size;
        for ( int i = 0; i < this->size; i++)
        {
            *(this->data + i) = s.data[i];
        }
    }
    return *this;
}
void Add(DeviceList& s, const Device& t)
{
    Device* new_data = new Device[s.size + 1];
    for (int i = 0; i < s.size; i++) {
        new_data[i] = s.data[i];
    }
    new_data[s.size] = t;
    delete[] s.data;
    s.data = new_data;
    s.size++;
}
void Delete(DeviceList& s, int k)
{
    if (k >= 0 && k < s.size)
    {
        for (int i = k; i < s.size - 1; i++)
        {
            s.data[i] = s.data[i + 1];
        }
        s.size--;
        cout << "Xoa thiet bi thanh cong" << endl;
        OutputFile(s);
    }
    else
    {
        cout << "Vi tri can xoa khong hop le!!!";
    }
}

void BaoLoi(DeviceList& s, int k)
{
    if(k >= 0 && k < s.size)
    {
        cout <<" Vi tri may bi loi : " << k << endl;
        cout << "Ma so may loi : " << s.data[k].MaQl;
        cout <<"Bao hong thanh cong ";
        OutputFile(s); 
    }
    else 
    {
        cout <<"Vi tri bao loi khong hop le!!!" << endl;
    }
}
void Update(DeviceList& s, int k)
{
    if(k >= 0 && k < s.size)
    {
        cout <<"Cap nhat tinh trang may : ";
        cin >> s.data[k].tinhTrang;
        cout <<"Cap nhat thanh cong" << endl;
        OutputFile(s);
    }
    else cout <<"Vi tri cap nhat khong hop le!!!" << endl;
}
void InputFile(DeviceList& s){
    ifstream file("Thietbi.txt");
    if(file.fail()){
        cout << "Failed\n";
        return;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
    Device tb;
         if(iss >> tb.MaQl) {
            iss >> tb.ngayNhap;
            iss >> tb.giaNhap;
            iss >> tb.tinhTrang;
            getline(iss,tb.tenTb);
            Add(s,tb);
         }
    }
    file.close();
}
void OutputFile(DeviceList& ds){
    ofstream file("Thietbi.txt");
    for(int i = 0;i < ds.size; i++){
        file << ds.data[i].MaQl <<" ";
        file << ds.data[i].ngayNhap <<" ";
        file << ds.data[i].giaNhap <<" ";
        file << ds.data[i].tinhTrang <<" ";
        file << ds.data[i].tenTb;
        file <<"\n";
    }
    file.close();
}