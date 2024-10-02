#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
class member {
    private:
        string hoten;
        unsigned int tuoi;
        bool gender;
        struct tm birthday;
        string sdt;
        bool lichtap[7];
        struct tm ngayDangKy;
        struct tm ngayHetHan;
    public:
        member();
        member(string ,bool ,int ,int ,int ,string);
        string GetHoten();
        unsigned int GetTuoi();
        bool GetGender();
        struct tm GetBirthday();
        string GetSdt();
        bool GetLichtap(int index);
        struct tm GetNgayDangKy();
        struct tm GetNgayHetHan();
        friend istream& operator>>(istream&, member&);    
        friend ostream &operator<<(ostream&, const member&);
        void Nhap();
        void Xuat();
        void UpdateSDT();
        void Dangki();
        void Setbirthday(int, int, int);
        void SetNgayDangKy(int, int, int);
        void SetNgayHetHan(int, int, int);
        void DangkyGoiTap();
        bool isValidDate(int ,int ,int);
};
#endif





