#include "person.cpp"

class employees: protected person{
	private:
		int idEmployee;
	public:
		
		void input (){
			cout << "Nhap ma nhan vien: "; cin >> this->idEmployee;
			person :: input();
		}
		
		void display(){
			cout << "Ma nhan vien: " << this->idEmployee << endl;
			person :: display();
		}
		
};
