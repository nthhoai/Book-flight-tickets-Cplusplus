#include <iostream>
#include <string>
using namespace std;

class tickets {
	private:
		int typeTicket; // loai ve {Khu hoi; Mot chieu}
		int seatClass; //hang ghe {Binh thuong, thuong gia, hang nhat..}
		
	public:
		// loai ve
		void inputTypeTicket(){
			cout << "			LUA CHON LOAI VE"<< endl;
			cout << "			1. Mot chieu"<< endl;
			cout << "			2. Khu hoi" << endl;
			cout << "			Nhap loai ve: ";	
			cin >> this->typeTicket;
		
		}
		
		// nhap hang ghe
		void inputSeatClass(){
			cout << "			LUA CHON HANG GHE"<< endl;
			cout << "			1. Pho thong"<< endl;
			cout << "			2. Thuong gia"<< endl;
			cout << "			3. Hang nhat" << endl;
			cout << "			Nhap hang ghe: ";
			cin >> this->seatClass;
		}
		
		void display(){
			cout << "Loai ve: " << this->typeTicket << endl;
			cout << "Hang ghe ngoi: " << this->seatClass;
		}
		
		int getTypeTicket(){
			return this->typeTicket;
		}
		
		int getSeatClass(){
			return this->seatClass;
		}
};
