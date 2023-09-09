#include "person.cpp"

class customers: protected person{
	public:
		void input(){
			person :: input();
		}
		void display(){
			person :: display();
		}
	
	
};
