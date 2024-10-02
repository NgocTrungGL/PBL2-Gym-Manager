#include <iostream>
#include "member.h"
#include "manage.h"
#include "SubAdmin.h"
#include "DeviceList.h"
using namespace std;
int main()
{
    List a;
    CreateList(a);
    InputFileAdmin(a);
    qlmember l;
    InputFile(l);
    DeviceList ds;
    InputFile(ds);
    SubAdmin(sub);
    InputFile(sub);
    Menu_chinh(a, sub, l, ds);
    return 0;
}