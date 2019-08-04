#include "Pair.h"
#include"time.h"
#include <string>
#include <iostream>
using namespace std;


Pair::Pair(int vertex){
	this->name = vertex;
	this->cost=1000;
}
Pair::Pair(int vertex, int costs){
  this->name = vertex;
  this->cost=costs;
}
void Pair::updateCost(int newcost){
  cost = newcost;
}
bool operator<(Pair &Pair1,Pair &Pair2){
	 return(Pair1.cost <Pair2.cost);
}
bool operator>(Pair &Pair1,Pair &Pair2){
	 return(Pair1.cost > Pair2.cost);
}
bool operator==(Pair &Pair1,Pair &Pair2){
	 return(Pair1.cost == Pair2.cost);
}
bool operator!=(Pair &Pair1,Pair &Pair2){
	 return(Pair1.cost != Pair2.cost);
}
bool operator<=(Pair &Pair1,Pair &Pair2){
	 return(Pair1.cost <=Pair2.cost);
}
bool operator>=(Pair &Pair1,Pair &Pair2){
	 return(Pair1.cost >=Pair2.cost);
}
Pair::Pair(const Pair & Paired){
	name = Paired.name;
	cost = Paired.cost;
	//cout<<"Copy Paired"<<endl;
}
int Pair::getName(){
	return name;
}


//ostream & operator<<(ostream& out,const ItemToPurchase & f){
//	double price = f.price;
//	int quantity = f.quantity;
//	double total = price*quantity;
//	string info = f.name +" " +to_string(quantity)+ " $" + to_string(price) + " = $"+to_string(total);
//	out<<info;
//	return out;
//}
