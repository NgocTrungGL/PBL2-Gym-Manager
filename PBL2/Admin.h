#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
using namespace std;

class Admin 
{
    private:
        string Ho_ten;
        string name_user;
        string password;
    public:
        Admin(string = "", string = "", string ="");
        ~Admin();
        void ChangePass();
        void Nhap();
        string getHoten();
        string getnameUser();
        string getPass();
        friend bool GetUser(Admin&, string);
        friend bool GetPass(Admin&, string);
        friend ostream& operator<<(ostream& , Admin&);
        friend istream& operator>>(istream& , Admin&);
        friend void InputFile(Admin&);
        friend void OutputFile(Admin&);
};
#endif

