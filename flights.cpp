#include <cstdlib>
#include "customers.cpp"


class flights{
	private:
		int id;
		string origin; // diem khoi hanh
		string destination; // diem den
		float intialPrice;
		
	public:
		// function
		void input(){
			cin.ignore();
			cout << "Nhap ma chuyen bay: "; cin >> this->id;
			//this->id = rand(); // ma tu sinh ngau nhien
			cin.ignore();
			cout << "Nhap diem khoi hanh: "; getline(cin, this->origin);
			cout << "Nhap diem den: "; getline (cin, this->destination);
			cout << "Nhap gia khoi diem: "; cin >> this->intialPrice;
		}
		
		void displayCustomers(){
				cout << "			"<< this->id << ".	 "<<this->origin << " - " << this->destination << endl;			
		}
		
		void displayEmployees(){
				cout<< "			" <<this->id  << ".    " << this->origin << " - " << this->destination << "    "
				<< this->intialPrice << endl;						
		}
		
		float getInitialPrice(){
			return this->intialPrice;
		}
};



class trlFlights{
	private: 
		flights* listFlight;
		int num; // so luong chuyen bay can quan ly
	public:
		void input(){		
			cout << "			Nhap so luong thong tin chuyen bay muon them: "; cin >> this->num;
			// khoi tao + cap phat vung nho
			this->listFlight = new flights [this->num];
			for (int i = 0; i < this->num; i++){
				cout << endl;
				cout << "		Nhap thong tin chuyen bay thu " << i+1 << endl;
				this->listFlight[i].input();				
			}
			cout << "			Them thong tin chuyen bay thanh cong!" << endl << endl;
		}
		void displayCustomers(){
			cout << endl << endl;
			cout << "			-----------------------"<<endl;
			cout << "			DANH SACH CHUYEN BAY  "<< endl;
			for (int i = 0; i < this->num; i++){
				//cout << endl << endl << "             " << i+1 <<".    ";
				this->listFlight[i].displayCustomers();					
			}		
		}
		//array[0] cua mang luu thong tin chuyen bay
		void displayEmployees(){
			cout << endl << endl;
			cout << "			---------------------"<<endl;
			cout << "			DANH SACH CHUYEN BAY "<< endl;
			for (int i = 0; i < this->num; i++){
				//cout << endl << endl << "             " << i+1 <<".    ";
				this->listFlight[i].displayEmployees();					
			}					
		}
		
		
		
		
		// ham nay dung de hien thi thong tin chuyen bay ma khach hang chon
		int chooseFlights (int choice) {
//			int choice;
//			choice = this->pressChoice();
			int i;
			for (int i = 0; i < this->num; i++) {
				if (i + 1 == choice) {
					//return 1;
					this->listFlight[i].displayCustomers();
				}
			}
		}	
		
		// ham nay dung de lay gia cua chuyen bay
		float getPriceInitial(int choice){
			int i;
			int price;
			for (int i = 0; i < this->num; i++) {
				if (i + 1 == choice) {
					price = this->listFlight[i].getInitialPrice();
				}
			}
			return price; 			
		}	

};
