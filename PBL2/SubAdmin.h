#ifndef SUBADMIN_H
#define SUBADMIN_H
#include <iostream>
#include "Admin.h"
using namespace std;
class SubAdmin 
{
    private:
        Admin* Subadmin;
        int size;
    public:
        SubAdmin(int = 0);
        ~SubAdmin();
        int GetSize();
        void Show();
        const SubAdmin& operator=(const SubAdmin&);
        friend void Delete(SubAdmin&, int);
        friend void Add(SubAdmin&, const Admin&);
        friend void InputFile(SubAdmin&);
        friend void OutputFile(SubAdmin&);
        friend bool GetID(SubAdmin& , string );
        friend bool GetPIN(SubAdmin& , string );
        friend int findbyid(SubAdmin&, string);
        friend void changepassbyid(SubAdmin&, string);
        friend void changepassbystt(SubAdmin& ,int);
};
#endif
