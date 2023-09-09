#include <iostream>
using namespace std;

class date{
	public:
		int day, month, year;
		
		// function
		void input(){
			cout << "Nhap ngay: "; cin >> this->day;
			cout << "Nhap thang: "; cin >> this->month;
			cout << "Nhap nam: "; cin>> this->year;
		}
		
		void display(){
			cout << this->day <<"/ " << this->month <<"/ " << this->year << endl; 
		}
};

