#include <iostream>
using namespace std;

#include "ConcreteSubject.h"
#include "Observer.h"

// Die Concreten Observer sind vollst�ndig unabh�ngig vom Observer
// sie sind nicht von Observer abgeleitet, sondern werden durch den 
// "Kit" mit der Anwendung miteinander verbunden
#include "ConcreteObserver.h"

class MainClass {
public:
	static void main() {
		ConcreteSubject s1("Subject1");
		ConcreteSubject s2("Subject2");

		ConcreteObserver1 o("o meldet sich selbst bei s2 an", s2);

		ConcreteObserver1 o1("o1");
		AdapterTemplate< ConcreteObserver1> adapter1(o1, &ConcreteObserver1::operation1, s1);

		AdapterTemplate< ConcreteObserver1> adapter2(o1, &ConcreteObserver1::operation2, s2);

		Kit < ConcreteObserver1> bridge(o1, s1);
//		s1.addListener(bridge); //protected, keine falsche anmeldung m�glich

		ConcreteObserver2 o2("o2");
		Kit < ConcreteObserver2 > bridge2(o2, s1);
		//
		s1.changeState();
		s2.changeState();


		/*
		ConcreteObserver1* po3 = new ConcreteObserver1("new po3");
		Kit<ConcreteObserver1>* pKit1 
			= new Kit<ConcreteObserver1>(*po3, s1);

		ConcreteObserver2* po4 = new ConcreteObserver2("new po4");
		Kit<ConcreteObserver2>* pKit2 
			= new Kit<ConcreteObserver2>(*po4, s1);

		s1.changeState();
		s2.changeState();

		
		delete pKit1;
		delete po3;
		delete pKit2;
		delete po4;

		s1.changeState();
		s2.changeState();
		*/
		
	}//end of static main
};


int main() {
	cout << "vor MainClass::main()"<<endl;
	MainClass::main();
	cout << "nach MainClass::main()"<<endl;
}
