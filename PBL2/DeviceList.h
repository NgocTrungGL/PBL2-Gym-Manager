#ifndef DEVICELIST_H
#define DEVICELIST_H
#include <iostream>
#include "Device.h"
using namespace std;
class DeviceList 
{
    private:
        int size;
        Device *data;
    public:
        DeviceList(int = 0);
        ~DeviceList();
        void Show();
        const DeviceList& operator=(const DeviceList&);
        friend void Delete(DeviceList&, int);
        friend void Add(DeviceList&, const Device&);
        friend void Update(DeviceList&, int);
        friend void BaoLoi(DeviceList&, int);
        friend void InputFile(DeviceList&);
        friend void OutputFile(DeviceList&);
};
#endif