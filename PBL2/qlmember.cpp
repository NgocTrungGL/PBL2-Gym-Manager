#include <iostream>
#include <iomanip>
#include <fstream>
#include "qlmember.h"
using namespace std;
qlmember::qlmember(int n) 
 :size(n)
{
    if(size == 0) this->data = nullptr;
    else
    {
        this->data=new member[n];
    }
}
qlmember::~qlmember(){
    delete[] data;
}
void qlmember::show(){
    cout << "Danh Sach Thanh Vien " << endl;
    for (int i = 0; i < this->size; i++)
    {
        cout<<i<<"."<<*(this->data + i)<<endl;
    }
}
void Add(qlmember& ds,const member& a)
{
    member* new_data= new member[ds.size+1];
    for (int i = 0; i < ds.size; i++)
    {
        new_data[i]=*(ds.data+i);
    }
    new_data[ds.size] = a;
    ds.data = new_data;
    ds.size++;
}
void Delete(qlmember& ds,int k)
{
    {
    if (k >= 0 && k < ds.size)
    {
        for (int i = k; i < ds.size - 1; i++)
        {
            ds.data[i] = ds.data[i + 1];
        }
        ds.size--;
        cout << "Xoa thanh cong" << endl;
        //OutputFile(ds);
    }
    else
    {
        cout << "Vi tri can xoa khong hop le!!!";
    }
}
}
void OutputFile(qlmember& ds) {
    ofstream outFile("member.txt");

    if (!outFile.is_open()) {
        cerr << "Khong the mo file de ghi du lieu." << endl; 
        return;
    }

    for (int i = 0; i < ds.size; i++) {
        
        outFile << "\n" << ds.data[i].GetGender() << " ";
        outFile << ds.data[i].GetBirthday().tm_mday << " " << ds.data[i].GetBirthday().tm_mon + 1 << " " << ds.data[i].GetBirthday().tm_year + 1900 << " ";
        outFile << ds.data[i].GetSdt() << " ";

        for (int j = 0; j < 7; ++j) {
            outFile << ds.data[i].GetLichtap(j) << " ";
        }
        
        outFile << ds.data[i].GetNgayDangKy().tm_mday << " " << ds.data[i].GetNgayDangKy().tm_mon + 1 << " " << ds.data[i].GetNgayDangKy().tm_year + 1900 << " ";
        outFile << ds.data[i].GetNgayHetHan().tm_mday << " " << ds.data[i].GetNgayHetHan().tm_mon + 1 << " " << ds.data[i].GetNgayHetHan().tm_year + 1900 << " ";
        outFile << ds.data[i].GetHoten();
    }

    outFile.close();
}

void Statistic(qlmember& ds) {
    unsigned int slnam = 0;
    unsigned int slnu = 0;
    float average = 0;

    if (ds.size == 0) {
        cout << "Phong tap chua co thanh vien!!";
        return;
    }

    for (int i = 0; i < ds.size; i++) {
        average += ds.data[i].GetTuoi();
        if (ds.data[i].GetGender()) slnu++;
        else slnam++;
    }

    average = float(average) / ds.size;

    cout << "Phong tap co " << ds.size << " thanh vien\n";
    cout << "So luong nam: " << slnam << "\n";
    cout << "So luong nu: " << slnu << "\n";
    cout << "Do tuoi trung binh cua phong tap la: " << average << "\n";
}

void InputFile(qlmember& ds) {
    ifstream file("member.txt");

    if (file.fail()) {
        cout << "Khong the mo file de doc du lieu.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        member temp;

        if (iss >> temp) {
            Add(ds, temp);
        }
    }

    file.close();
}
void Update(qlmember& s, int k)
{
    if(k >= 0 && k < s.size)
    {
        
        s.data[k].UpdateSDT();

        cout <<"Cap nhat thanh cong" << endl;
        OutputFile(s);
    }
    else cout <<"Vi tri cap nhat khong hop le!!!" << endl;
}
void Dkgoitap(qlmember& s, int k)
{
    if(k >= 0 && k < s.size)
    {
        
        s.data[k].DangkyGoiTap();

        cout <<"Cap nhat thanh cong" << endl;
        OutputFile(s);
    }
    else cout <<"Vi tri cap nhat khong hop le!!!" << endl;
}
void Dk_lichtap(qlmember& s, int k)
{
    if(k >= 0 && k < s.size)
    {
        
        s.data[k].Dangki();

        cout <<"Cap nhat thanh cong" << endl;
        OutputFile(s);
    }
    else cout <<"Vi tri cap nhat khong hop le!!!" << endl;
}