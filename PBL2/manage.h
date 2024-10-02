#ifndef MANAGE_H
#define MANAGE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <conio.h>
#include "qlmember.h"
#include "SubAdmin.h"
#include "DeviceList.h"
struct Node{
    Admin data;
    Node* next;
};
struct List{
    Node* head;
    Node* tail;
};
//Tao node
Node* CreateNode(const Admin hv){
    Node* node = new Node;
    node->data = hv;
    node->next = NULL;
    return node;
}
//Tao ds
void CreateList(List& l){
    l.head=NULL;
    l.tail=NULL;
}
//Them node vao dau ds
void AddHead(List& l,Node* node){
    if(l.head==NULL){
        l.head=node;
        l.tail=node;
    }
    else{
        node->next=l.head;
        l.head=node;
    }
}
//Them node vao cuoi ds
void AddTail(List& l,Node* node){
    if(l.head==NULL)
    {
        l.head = node;
        l.tail = node;
    }
    else{
        l.tail->next = node;
        l.tail = node;
    }
}
//Them node p vao sau node q bat ki
void InsertAfterQ(List& l,Node* p,Node* q){
    if(q!=NULL){
		p->next=q->next;
		q->next=p;
		if (l.tail==q) l.tail=p;
	}
	else AddHead(l,p);
}
//Them node p vao sau vi tri k bat ki
void InsertAtK(List& l, Node* p, int k){
	if(k == 0 || l.head == NULL){
		AddHead(l,p);
	}
	else{
		//Tim vi tri can them
		Node* node = l.head;
		int i = 1;
		while (node->next != NULL && i != k){
			node = node->next;
			i++;
		}
		if(i != k){
			AddTail(l,p); // duyet het ds ma van chua den k, mac dinh them vao cuoi ds
		}
		else{
			p->next = node->next;
			node->next = p;
			if (l.tail==node) l.tail=p;
		}
	}
}
//Xoa node o dau ds
// int RemoveHead(List& l, member& x){
int RemoveHead(List& l){
	if(l.head!=NULL){
		Node* node=l.head;
		// x=node->data;//Luu gia tri cua node head
		l.head=node->next;
		delete node;//Huy node head
		if (l.head==NULL) l.tail=NULL;
		return 1;
	}
	return 0;
}
//Xoa node o cuoi ds
// int RemoveTail(List& l, member& x){
int RemoveTail(List& l){
	if(l.head==NULL || l.head->next==NULL){
		return RemoveHead(l);
	}
	Node* node = l.head;
	while (node->next->next != NULL) node = node->next;
	// x = node->next->data;//Luu gia tri cua node tail
	node->next = NULL;
	delete l.tail;//Xoa vung nho truoc day l.tail tro den
	l.tail = node;
	return 0;
}
//Xoa node o sau node q bat ki
// int RemoveAfterQ(List& l, Node* q, member& x){
int RemoveAfterQ(List& l, Node* q){
	if (q!=NULL){
		Node* p=q->next;
		if (p!=NULL){
			if(l.tail==p) l.tail=q;
			q->next=p->next;
			// x=p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}
//Xoa node sau vi tri k bat ki
// int RemoveAtK(List& l, int k, member& x){
int RemoveAtK(List& l, int k){
	if(k == 0 || l.head == NULL || l.head->next == NULL){
		return RemoveHead(l);
	}
	else{
		//Tim vi tri can xoa
		Node* node = l.head;
		int i = 1;
		while (node->next != NULL && i != k){
			node = node->next;
			i++;
		}
		if(i != k){
			return RemoveTail(l);// duyet het ds ma van chua den k, mac dinh xoa node cuoi ds
		}
		else{
			Node* p=node->next;
			if (p!=NULL){
				if(l.tail==p) l.tail=node;
				node->next=p->next;
				// x=p->data;
				delete p;
				return 1;
			}
			return RemoveTail(l);
		}
	}
}
//In ds
void PrintList(List l){
	if (l.head!=NULL){
		Node* node=l.head;
        cout << "Danh sach hoc vien: " << endl;
		while (node!=NULL){
			cout << node->data << endl;
			node=node->next;//Chuyen sang node tiep theo
		}
        cout << endl;
	}
}
//Tim kiem phan tu trong ds
// Node* Search(List& l,const Admin& x){
// 	Node* node = l.head;
// 	while (node != NULL && node->data != x) node = node->next;
// 	if (node != NULL) return node;
// 	return NULL;
// }
//Tim kiem phan tu theo id
Node* SearchID(List& l, string id) {
    Node* node = l.head;
    while (node != NULL) {
        if (strcmp(node->data.getnameUser().c_str(), id.c_str()) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

//Xoa phan tu theo id
int RemoveID(List& l,string id){
    if (l.head == NULL) return 0;
    if (strcmp(l.head->data.getPass().c_str(), id.c_str())==0){
        
        // member h;
        return RemoveHead(l);
    }
    Node* node = l.head;
	while (node->next != NULL && strcmp(node->next->data.getnameUser().c_str(), id.c_str()) != 0) node = node->next;
    if (node->next != NULL) return RemoveAfterQ(l,node);
    else return 0;
}
//Xuat phan tu theo id
// void XuatTheoID(List& l, string id)
// {
//     Node* node = SearchID(l,id);
//     node->data.Xuat();
// }
// Lay phan tu thu index
Node* GetNode(List& l, int index){
	Node* node = l.head;
	int i = 1;
	while (node != NULL && i != index){
		node = node->next;
		i++;
	}
	if (i == index && node != NULL) return node;
	return NULL;
}
//Dem so phan tu trong ds
int Length(List& l){
	int count=0;
	Node* node=l.head;
	while(node!=NULL){
		count++;
		node=node->next;
	}
	return count;
}
//Xoa danh sach
void RemoveList(List& l){
	// member x;
	Node* node=l.head;
	while(node!= NULL){
		RemoveHead(l);
		node=l.head;
	}
	l.tail=NULL;
}

void InputFileAdmin(List& s)
{
    ifstream file("admin.txt");
    if(file.fail())
    {
        cout << "Failed\n";
        return;
    }
    string line;
    Admin ad;
    while (getline(file, line))
    {
        istringstream iss(line);
        Admin a;
        // if (iss >> a.getHoten() >> a.getnameUser() >> a.getPass())
        if( iss >> a)
        {
            Node* Node_admin = CreateNode(a);
            AddTail(s, Node_admin);
        }
    }
}
// Xuat ds vao file
void PrintListFile(List& l){
    ofstream file("admin.txt");
    if (l.head != NULL)
    {
        Node* node = l.head;
        while (node != NULL)
        {
            file << endl << node->data.getHoten() << "\t";
            file << node->data.getnameUser() << "\t";
            file << node->data.getPass() << "\t";
            node = node->next; // Chuyen sang node tiep theo
        }
    }
    file.close();
}
//check id
bool GetUser(List& l, string id){
    Node* node = l.head; 
    while (node != NULL){
        if (strcmp(id.c_str() ,node->data.getnameUser().c_str())==0){
            return true;
        }
        node = node->next;
    }return false;
}
//check pin
bool GetPass(List l, string pin){
    Node* node = l.head;
    while (node != NULL){
        if (strcmp(pin.c_str() ,node->data.getPass().c_str())==0){ 
            return true;
        }
        node = node->next;
    }return false;
}
void Doi_PIN(List& l, string id){
    int pin_moi;
    cout << "Nhap PIN moi : ";cin>>pin_moi;
    Node* h = l.head;
    while(h != NULL){
        if (strcmp(h->data.getnameUser().c_str(),id.c_str())==0) {
            h->data.ChangePass();
			break;
        }
        h = h->next;
    }
}
//doi thong tin theo id
void Tro_lai_Menu_admin(){
    int option ;
    cout << "Bam [0] de tro lai MENU ADMIN: ";
    while (cin>>option) {
        if (option==0) {
            break;
        }else{
            system("cls");
            cout << "Khong hop le, vui long nhap lai : ";
        }
    }
}
void Tro_lai_Menu_User(){
    int option ;
    cout<<"\nBam 0 de tro lai MENU: ";
    while (cin>>option) {
        if (option==0) {
            break;
        }else{
            system("cls");
            cout<<"Khong hop le, vui long nhap lai: ";
        }
    }
}
void Menu_Admin(List& a, SubAdmin& sa,qlmember &l,DeviceList& ds, string& id)
{
    system("cls");
    int option;
    cout << "===========MENU ADMIN===========" << endl;
    cout << "[-] Quan ly khach hang:\n";
    cout << "1. Xem danh sach khach hang\n";
    cout << "2. Dang ky goi tap cho khach hang\n";
    cout << "3. Them khach hang\n";
    cout << "4. Xoa khach hang\n";
    cout << "5. Cap nhat thong tin khac hang\n";
    cout << "6. Dang ky lich tap cho khach hang\n";
    cout << "7. Xem thong ke phong tap\n";
    cout << "[-] Quan ly thiet bi:\n";
    cout << "8. Xem danh sach thiet bi\n";
    cout << "9. Them thiet bi\n";
    cout << "10. Xoa thiet bi\n";
    cout << "11. Update thiet bi \n";
    cout << "[-] Quan ly nhan vien:\n";
    cout << "12. Xem danh sach nhan vien\n";
    cout << "13. Them nhan vien\n";
    cout << "14. Xoa nhan vien\n";
    cout << "15. Update nhan vien\n";
    cout << "[-] Tai khoan:\n";
    cout << "16. Doi mat khau tai khoan\n";
    cout << "0. Dang xuat\n";
    cout << "Nhap lenh :";
    cin>>option;
    switch (option) {
        case 1:{
            system("cls");
            l.show();
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;
        case 2:{
            system("cls");
            l.show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Dkgoitap(l,stt);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;    
        case 3:{
            system("cls");
            member temp;
            temp.Nhap();
            Add(l,temp);
            cout<<"Them thanh vien thanh cong!!";
            Tro_lai_Menu_User();
            OutputFile(l);
            Menu_Admin(a,sa,l,ds,id);
        }
            break;
        case 4:{
            system("cls");
            l.show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Delete(l,stt);
            OutputFile(l);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;
        case 5:{
            system("cls");
            l.show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Update(l,stt);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;    
        case 6:{
            system("cls");
            l.show();
            
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Dk_lichtap(l,stt);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;
        case 7:{
            system("cls");
            Statistic(l);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }   
            break;    
        case 8:{
            system("cls");
            ds.Show();
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }   
            break;
        case 9:{
            system("cls");
            Device tb;
            cin >> tb;
            Add(ds,tb);
            cout << "Them thiet bi moi thanh cong \n" << endl;
            OutputFile(ds);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;
        case 10:{
            system("cls");
            ds.Show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Delete(ds,stt);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;
        case 11:{
            system("cls");
            ds.Show();
            int stt,t;
            cout << "Nhap stt: ";
            cin>>stt;
            Update(ds,stt);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }
            break;
        case 12:{
            system("cls");
            sa.Show();
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }    
            break;
        case 13:{
            system("cls");
            Admin temp;
            temp.Nhap();
            Add(sa,temp);
            cout<<"Them nhan vien thanh cong!!";
            Tro_lai_Menu_User();
            OutputFile(sa);
            Menu_Admin(a,sa,l,ds,id);
        }    
            break;
        case 14:{
            system("cls");
            sa.Show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Delete(sa,stt);
            OutputFile(sa);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }    
            break;
        case 15:{
            system("cls");
            sa.Show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            changepassbystt(sa,stt);
            OutputFile(sa);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }    
            break;   
        case 16:{
            system("cls");
            Doi_PIN(a,id);
            // changepassbyid(sa,id);
            OutputFile(sa);
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
        }    
            break;           
        case 0: break;
        default:
            system("cls");
            cout<<"Lua chon khong hop le, tro ve Menu admin\n";
            Tro_lai_Menu_User();
            Menu_Admin(a,sa,l,ds,id);
            break;
    }
}

void Dang_Nhap_Admin(List& a, SubAdmin& sa,qlmember &l,DeviceList& ds){
    system("cls");
    int option;
    cout<<"============================================================="<<endl;
    cout<<"                          ADMIN LOGIN                        "<<endl;
    cout<<"============================================================="<<endl;
    string id;
    char ch;
    cout <<"User: "; cin >> id;
    if (GetUser(a, id)){
        string pin;
        cout << "Password: ";
        
        while (true) {
        ch = _getch(); // Read a character without echoing it to the console
        if (ch == 27) exit(0);
        if (ch == 13) // Enter key (ASCII code 13) to indicate the end of input
            break;
        if (ch == 8) { // Backspace (ASCII code 8) to handle erasing characters
            if (!pin.empty()) {
                pin.pop_back();
                cout << "\b \b"; // Erase the character from the console
            }
        }
        else if (ch == -32 || ch == 77 || ch == 75 ) { 
            }
        else {
            pin += ch;
            cout << "*"; 
        }
    }
        if(GetPass(a,pin)) 
        {
            Menu_Admin(a,sa,l,ds,id);
        }
        else
        {
            system("cls");
            int option;
            cout << "Sai Password! \n";
            cout << "Bam 1. de dang nhap lai \n";
            cout << "Bam 0. de tro ve Menu Chinh \n";
            cout << "Nhap lua chon : ";
            cin>>option;
            switch (option) {
                case 1:
                    Dang_Nhap_Admin(a, sa, l,ds);
                    return;
                case 0: return;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le, tro ve Menu Chinh\n";
                    system("pause");
                    return;
            }
        }
    }
    else{
        system("cls");
        int option;
        cout << "ID khong hop le!\n";
        cout << "Bam 1. de dang nhap lai \n";
        cout << "Bam 0. de tro ve Menu Chinh \n";
        cout << "Nhap lua chon : ";
        cin>>option;
        switch (option) {
            case 1:
                Dang_Nhap_Admin(a, sa, l,ds);
                return;
            case 0: return;
            default:
                system("cls");
                cout << "Lua chon khong hop le, tro ve Menu Chinh \n";
                 system("pause");
                return;
        }
    }
}
void Menu_User(List& a,SubAdmin& sa,qlmember &l,DeviceList& ds,string &id){
    system("cls");
    int option;
    cout << "===========MENU NHAN VIEN===========" << endl;
    cout << "[-] Quan ly khach hang:\n";
    cout << "1. Xem danh sach khach hang\n";
    cout << "2. Dang ky goi tap cho khach hang\n";
    cout << "3. Them khach hang\n";
    cout << "4. Xoa khach hang\n";
    cout << "5. Cap nhat thong tin khac hang\n";
    cout << "6. Dang ky lich tap cho khach hang\n";
    cout << "7. Xem thong ke phong tap\n";
    cout << "[-] Quan ly thiet bi:\n";
    cout << "8. Xem danh sach thiet bi\n";
    cout << "9. Them thiet bi\n";
    cout << "10. Xoa thiet bi\n";
    cout << "11. Update thiet bi \n";
    cout << "[-] Tai khoan:\n";
    cout << "12. Doi mat khau tai khoan\n";
    cout << "0. Dang xuat\n";
    cout << "Nhap lenh :";
    cin>>option;
    switch (option) {
        case 1:{
            system("cls");
            l.show();
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;
        case 2:{
            system("cls");
            l.show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Dkgoitap(l,stt);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;    
        case 3:{
            system("cls");
            member temp;
            temp.Nhap();
            Add(l,temp);
            cout<<"Them thanh vien thanh cong!!";
            Tro_lai_Menu_User();
            OutputFile(l);
            Menu_User(a,sa,l,ds,id);
        }
            break;
        case 4:{
            system("cls");
            l.show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Delete(l,stt);
            OutputFile(l);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;
        case 5:{
            system("cls");
            l.show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Update(l,stt);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;       
        case 6:{
            system("cls");
            l.show();
            
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Dk_lichtap(l,stt);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;
        case 7:{
            system("cls");
            Statistic(l);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }   
            break;    
        case 8:{
            system("cls");
            ds.Show();
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }   
            break;
        case 9:{
            system("cls");
            Device tb;
            cin >> tb;
            Add(ds,tb);
            cout << "Them thiet bi moi thanh cong \n" << endl;
            OutputFile(ds);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;
        case 10:{
            system("cls");
            ds.Show();
            int stt;
            cout << "Nhap stt: ";
            cin >> stt;
            Delete(ds,stt);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;
        case 11:{
            system("cls");
            ds.Show();
            int stt,t;
            cout << "Nhap stt: ";
            cin>>stt;
            Update(ds,stt);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }
            break;
        case 12:{
            system("cls");
            changepassbyid(sa,id);
            OutputFile(sa);
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
        }    
            break;
        case 0: break;
        default:
            system("cls");
            cout<<"Lua chon khong hop le, tro ve Menu admin\n";
            Tro_lai_Menu_User();
            Menu_User(a,sa,l,ds,id);
            break;
    }
}
void Dang_Nhap_User(List& a, SubAdmin& sa,qlmember &l,DeviceList& ds){
    system("cls");
    cout<<"============================================================="<<endl;
    cout<<"                     DANG NHAP NHAN VIEN                     "<<endl;
    cout<<"============================================================="<<endl;
    string id;
    char ch;
    cout <<"User: "; cin >> id;
    if (GetID(sa, id)){
        string pin;
        cout << "Password: ";
        
        while (true) {
        ch = _getch(); // Read a character without echoing it to the console
        if (ch == 27) exit(0);
        if (ch == 13) // Enter key (ASCII code 13) to indicate the end of input
            break;
        if (ch == 8) { // Backspace (ASCII code 8) to handle erasing characters
            if (!pin.empty()) {
                pin.pop_back();
                cout << "\b \b"; // Erase the character from the console
            }
        }
        else if (ch == -32 || ch == 77 || ch == 75 ) { 
            }
        else {
            pin += ch;
            cout << "*"; 
        }
    }

        if( GetPIN(sa,pin)) 
        {
            Menu_User(a,sa,l,ds,id);
        }
        else
        {
            system("cls");
            int option;
            cout << "Sai Password! \n";
            cout << "Bam 1. de dang nhap lai \n";
            cout << "Bam 0. de tro ve Menu Chinh \n";
            cout << "Nhap lua chon : ";
            cin>>option;
            switch (option) {
                case 1:
                    Dang_Nhap_User(a,sa,l,ds);
                    return;
                case 0: return;
                default:
                    system("cls");
                    cout << "Lua chon khong hop le, tro ve Menu Chinh\n";
                    system("pause");
                    return;
            }
        }
    }
    else{
        system("cls");
        int option;
        cout << "ID khong hop le!\n";
        cout << "Bam 1. de dang nhap lai \n";
        cout << "Bam 0. de tro ve Menu Chinh \n";
        cout << "Nhap lua chon : ";
        cin>>option;
        switch (option) {
            case 1:
                Dang_Nhap_User(a,sa,l,ds);
                return;
            case 0: return;
            default:
                system("cls");
                cout << "Lua chon khong hop le, tro ve Menu Chinh \n";
                 system("pause");
                return;
        }
    }
}
//Menu chinh
void Menu_chinh(List& a,SubAdmin& sa,qlmember& l,DeviceList& ds){
    system("cls");
    int option = 0;
    
    cout << "=============================================================" << endl;
    cout << "                 Menu quan ly phong GYM-FITNESS              " << endl;
    cout << "=============================================================" << endl;
    cout << "1. Nhan vien login\n";
    cout << "2. Admin login\n";
    cout << "3. Exit\n";
    cout << "Chon lenh : ";
    cin>>option;
    switch (option) {
        case 1:
            Dang_Nhap_User(a,sa,l,ds);
            break;
        case 2:
            Dang_Nhap_Admin(a, sa, l,ds);
            break;
        case 3:
            return;
        default:
            system("cls");
            cout << "Lua chon khong hop le!! Vui long chon lai! \n";
            system("pause");
            break;
    }
    Menu_chinh(a,sa,l,ds);
}
#endif
