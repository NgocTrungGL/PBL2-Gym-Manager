#ifndef QLMEMBER_H
#define QLMEMBER_H  
#include <iostream>
#include "member.h"
class qlmember 
{
private:
    int size;
    member* data;
public:
    qlmember(int =0);
    ~qlmember();
    void show();
    friend void Delete(qlmember&, int);
    friend void Add(qlmember&, const member&);
    friend void Update(qlmember&, int);
    friend void Statistic(qlmember&);
    friend void InputFile(qlmember&);
    friend void OutputFile(qlmember&);
    friend void Dkgoitap(qlmember&, int);
    friend void Dk_lichtap(qlmember&, int);
};
#endif

