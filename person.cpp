#include "date.cpp"
#include <string>

class person{
	protected:
		string name;
		date birth;
		int phoneNumber;
		int id;
	public:		
		// function
		virtual void input(){
			cin.ignore();
			cout << "Nhap ho ten: "; getline(cin, this->name);
			cout << "Nhap ngay sinh: "; 
			this->birth.input();
			cout << "Nhap so dien thoai: "; cin >> this->phoneNumber;
			cout << "Nhap so dinh danh ca nhan: "; cin >> this->id;
		}
		
		virtual void display(){
			cout << "			Ho ten: " << this->name << endl;
			cout << "			Ngay sinh: ";
			this->birth.display();
			cout << "			So dien thoai: " << this->phoneNumber <<endl;
			cout << "			So dinh danh ca nhan: " << this->id <<endl;			
		}
};
