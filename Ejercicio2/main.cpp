#include <iostream>

class claseA;
class claseB;
class claseC;

#include "A.h"
#include "B.h"
#include "C.h"

int main(int argc, char** argv) {

	claseA *_a = new claseA();
	claseB *_b = new claseB();
	claseC *_c = new claseC();

    _c->setC(3);
    _b->setB(2);
    _a->setA(1);

    _a->setC(*_c);
    _a->setB(*_b);

    _b->setA(*_a);
    _b->setC(*_c);

    _c->setA(*_a);
    _c->setB(*_b);

    std::cout << "\e[1;95m\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\e[0m" ;
    _a->printA();
    _b->printB();
    _c->printC();

    std::cout << "Accedemos al valor de B desde A: " << _a->getValB();
    std::cout << "\e[1;95m\n/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\e[0m" ;
    return 0;
}
