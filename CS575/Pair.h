#ifndef pair
#define pair
#include <iostream>
#include <string>
using namespace std;
class Pair{
	public:
		Pair(int vertex);
		//constructor with properly generated data members
		Pair(int vertex, int costs);
		//Constructor with 0 in all data members
		Pair(const Pair & Paired);
		//Copy constructor
		void updateCost();

		int getName();
		//returns timer
		//decrements Pairtime
		friend bool operator<(Pair &Pair1,Pair &Pair2);
		//overrides < operator
		friend bool operator<=(Pair &Pair1,Pair &Pair2);
		//overrides <= operator
		friend bool operator>(Pair &Pair1,Pair &Pair2);
		//overrides > operator
		friend bool operator>=(Pair &Pair1,Pair &Pair2);
		//overrides >= operator
		friend bool operator==(Pair &Pair1,Pair &Pair2);
		//overrides == operator
		friend bool operator!=(Pair &Pair1,Pair &Pair2);
		//overrides != operator
//		friend ostream& operator<<(ostream & out, const ItemToPurchase & f);
	private:
		int name;
		int cost;
};

#endif
