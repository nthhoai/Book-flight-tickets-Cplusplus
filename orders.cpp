#include "tickets.cpp"
#include "flights.cpp"
#include <cstring>

class orders{
	private: 
		customers c;
		flights a;
		trlFlights f;
		tickets t;
		int flightDate; // so ngay dat truoc
		float price; // gia ve cuoi cung
		//date flightDate; // option 1 -2 -3 --> cac khoang doi giong mo ta
		float giabienthien2; 
		float giabienthien3;
		float giabienthien4;
		float giabienthien5;
		float tienve; // gia ve cuoi cung
		float initialPrice;
		int dtsd; // nhap lua chon cho doi tuong su dung ve

		
	
	
	public: 
	
		
		
//		//	lay gia khoi diem cua chuyen bay tuong ung voi lua chon cua khach hang
		float calculateInput1(int choice){
			this->initialPrice = this->f.getPriceInitial(choice);
			return this->initialPrice;
		}
		
//		// tinh gia bien thien dua tren input2: ngay khoi hanh	
		float calculateInput2(){
			
			cout << "			Ngay khoi hanh thuoc [1, 30]: 	" << endl;		
			cout << "			Nhap so ngay ban muon dat ve truoc: "; cin >> this->flightDate;
			while (this->flightDate<1 || this->flightDate>30 || cin.fail()){
				cout << "			Nhap ngay khoi hanh khong hop le!" << endl;					
				cout << "			Vui long nhap lai so ngay ban muon dat ve truoc: ";
				cin.clear(); // Xoa cac bit loi trong buffer
		        cin.ignore(10000, '\n'); // Loai bo toan bo du lieu nhap tu ban phim
				cin >> this->flightDate;				
			}
			if (this->flightDate <=7){
				return this->giabienthien2 = this->initialPrice* 0.15;
			}
			else if (this->flightDate <=15){ 
				return this->giabienthien2 = 0;
			}
			else {
				return this->giabienthien2 =  - this->initialPrice * 0.15; 
			}						
		}
//		
		// tinh gia bien thien dua tren input3: hang ghe		
		float calculateInput3(){
			this->t.inputSeatClass();
			if (this->t.getSeatClass() == 1)
				return this->giabienthien3 = 0;
			if (this->t.getSeatClass() == 2)
				return this->giabienthien3 = this->initialPrice * 0.2;
			if (this->t.getSeatClass() == 3)
				return this->giabienthien3 = this->initialPrice * 0.4;
		}
		
		// convert bien hang ghe dang so ve dang chu			
		string convertSeatClass(){
			if (this->t.getSeatClass() == 1)
				return "Pho thong";
			if (this->t.getSeatClass() == 2)
				return "Thuong gia";
			if (this->t.getSeatClass() == 3)
				return "Hang nhat";
		}
		
		float calculateInput4(){
			cout << "			LUA CHON DOI TUONG SU DUNG VE"<< endl;
			cout << "			Nguoi lon - 13 tuoi tro len"<< endl;
			cout << "			Tre em - (0-12 tuoi)"<< endl;
			cout << "			Quy dinh doi tuong su dung may bay: (0 - 100] - tuoi" << endl;
			cout << "			Nhap tuoi cua doi tuong su dung ve: ";	
			cin >> this->dtsd;	
			while (this->dtsd<1 || this->dtsd>100 || cin.fail()){
				cout << "			Nhap tuoi khong hop le!" << endl;					
				cout << "			Vui long nhap lai so so tuoi: 	";
				cin.clear(); // Xoa cac bit loi trong buffer
		        cin.ignore(10000, '\n'); // Loai bo toan bo du lieu nhap tu ban phim
				cin >> this->dtsd;				
			}			
			
			if (this->dtsd <=12){
				
				return this->giabienthien4 = -this->initialPrice*0.1;

			}
			else {
				return this->giabienthien4 = 0;
			}				
		}
		
		string convertAge(){
			if (this->dtsd> 0 && this->dtsd <=12){
				
				return "Tre em";

			}
			if (this->dtsd >12 && this->dtsd <=100){
				return "Nguoi lon";
			}
			
		}
		
		
		
		
		// tinh gia bien thien dua tren input4: loai ve: khu hoi, 1 chieu
		float calculateInput5(){
			t.inputTypeTicket();
			//int temp = this->calculateInput1(choice);
			if (this->t.getTypeTicket() == 1){
				
				return this->giabienthien5 = 0;

			}
			if (this->t.getTypeTicket() == 2) {
				return this->giabienthien5 = this->initialPrice * 0.8;
			}
		}
		
		// chuyen doi lua chon (1,2 dang so) sang chu 
		string convertTypeTicket(){
			if (this->t.getTypeTicket() == 1)
				return "Mot chieu";
			if (this->t.getTypeTicket() == 2)
				return "Khu hoi";
		}		
//		
		int calculatePriceTicket(){
			
			this->tienve = this->initialPrice + this->giabienthien2 + this->giabienthien3 + this->giabienthien4 + this->giabienthien5;
			return this->tienve;			
		}


		
		// hien thi thong tin ve ma khach chon
		void detailTicket(int choice){
			cout << "			THONG TIN VE NHU SAU: "<< endl << endl << endl;
			cout << "			"; f.chooseFlights(choice); cout<<endl;
			cout << "			Dat truoc: " << this->flightDate << "- ngay" << endl;
			cout << "			Hang ghe: " << this->convertSeatClass() <<endl;
			cout << "			Doi tuong su dung: " << this->convertAge()<<endl;
			cout << "			Loai ve: " << this->convertTypeTicket()  <<endl;
			cout << "			Gia ve: " << this->calculatePriceTicket() << endl;			
		}
		

		
		
		
		// tuong duong voi menu khach hang
		void placeAnOrder(){
			this->f.displayCustomers();
			int choice;
			cout << "Chon chuyen bay: "; cin >> choice;
			f.chooseFlights(choice); 

			this->calculateInput1(choice);
	

			cout << this->calculateInput2();				
			//cout << "Gia bien thien 2: " << this->calculateInput2(this->flightDate, this->initialPrice, this->giabienthien2) << endl;
			cout << "Gia bien thien 3: " << this->calculateInput3() << endl;							
			cout << "Gia bien thien 4: " << this->calculateInput4() << endl;
			cout << "Gia bien thien 5: " << this->calculateInput5() << endl;
			cout << "			--------------------------" << endl;
			this->detailTicket(choice);
			while (true){
				cout << "			----------------------"<< endl;
				cout << "			GIAO DIEN DAT VE" << endl << endl;
				cout << "			1. Dat ve" << endl;
				cout << "			0. Thoat!"<< endl;
				cout << "			----------------------" << endl << endl;
				cout << "			Nhap lua chon: ";
				
				int choicePlaceAnOrder;
				cin >> choicePlaceAnOrder;
				if (choicePlaceAnOrder == 1){
					this->c.input();
					
					this->detailTicket(choice);
					cout << "			THONG TIN KHACH HANG NHU SAU:" << endl;
					this->c.display();
					cout << "			DAT VE THANH CONG !			" << endl << endl;
					return ;
				}
				
	
				else if (choicePlaceAnOrder == 0){
					return;
				}
				else {
					cout << "			Lua chon khong hop le!" << endl;
				}	
					
			}		
				
			
		}
		
		
		
		void menuEmployee(){
			while (true){
				cout << "				------------------------" << endl;
		        cout << "				GIAO DIEN NHAN VIEN" << endl << endl;
			    cout << "				1. Them chuyen bay" << endl;
			    cout << "				2. Xem thong tin chuyen bay" << endl;
			    cout << "				0. Thoat" << endl << endl << endl;
			    cout << "				Nhap lua chon: ";
				
				int choiceEmployee;
				cin >> choiceEmployee;
				
				if (choiceEmployee == 1){
					this->f.input();
				}
				else if (choiceEmployee == 2){
					this->f.displayEmployees();
				}
				else if (choiceEmployee == 0){
					return ;
				}
				else {
					cout << "			Lua chon khong hop le!" << endl;
				}				
			}			
		}			
	
};


//		// tinh gia bien thien dua tren input4: doi tuong su dung	
//		
//		float calculateInput4(){
//
//			cout << "			LUA CHON DOI TUONG SU DUNG VE"<< endl;
//			cout << "			1. Nguoi lon - 13 tuoi tro len"<< endl;
//			cout << "			2. Tre em - (0-12 tuoi)"<< endl;
//			cout << "			Nhap doi tuong su dung ve: ";	
//			cin >> this->dtsd;
//			
//			if (this->dtsd == 1){		
//				return this->giabienthien4 = 0;
//			}
//			if (this->dtsd == 2){
//				return this->giabienthien4 = -this->initialPrice*0.1;
//			}				
//		}
//		
//		string convertDtsd(){
//			if (this->dtsd == 1){
//				
//				return "Nguoi lon";
//
//			}
//			if (this->dtsd == 2){
//				return "Tre em";
//			}
//			
//		}
