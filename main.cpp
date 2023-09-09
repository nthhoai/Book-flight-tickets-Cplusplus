#include "orders.cpp"

int main()
{
	while (true){
	    cout << "				------------------------" << endl;
	    cout << "				QUAN LY DAT VE" << endl << endl << endl;
	    cout << "				1. Vai tro nhan vien" << endl;
	    cout << "				2. Vai tro khach hang" << endl;
	    cout << "				0. Thoat" << endl << endl << endl;
	    cout << "				Nhap lua chon: ";
	 
	    int choice;
	    cin >> choice;

		orders o;
	    if (choice == 1){
	    	string username;
	    	int password;
	    	do {
	    		cout << endl << endl << endl;
	    		cout << "				GIAO DIEN DANG NHAP" <<endl << endl << endl;
	    		cout << "				Nhap Username Va Password" << endl;
	    		cout << "				Username: "; cin >> username;
	    		cout << "				Passrord: "; cin >> password;	    		
			} while (username != "group3" && password != 3);
			o.menuEmployee(); 
		}
		
		else if (choice == 2){
			while (true)
			{
				int action;
				cout << "				------------------------" << endl;
			    cout << "				VAI TRO KHACH HANG" << endl << endl << endl;
			    cout << "				1. Lua chon ve" << endl;
			    cout << "				0. Thoat" << endl << endl << endl;
			    cout << "				Nhap lua chon: "; cin>> action;
			    if (action ==1)
			    	o.placeAnOrder();
			    else if (action == 0){
			    	return 0;
				}	    
			    
			}

		}
		else if (choice == 0){
			return 0;
		}
		else {
			cout << "			Nhap khong hop le!" << endl;
		}
		
	}
	
};




