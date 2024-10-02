#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>
using namespace std;
class Device
{
    public:
        string tenTb;
        string MaQl;
        bool tinhTrang;
        int ngayNhap;
        float giaNhap;
        Device();
        Device(float, string, string, bool, int);
        ~Device();
        const Device& operator=(const Device&);
        float KhauHao(const Device&);
        friend istream& operator>>(istream&, Device&);
        friend ostream& operator<<(ostream&, const Device&);
        void Show();
};
#endif