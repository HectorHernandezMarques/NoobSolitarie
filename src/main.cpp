//============================================================================
// Name        : NoobSoltaire.cpp
// Author      : AntonioMontana
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "NoobSolitarie.h"
#include "Controllers/Local/Logic.h"
#include "Views/Console/NoobSolitarieView.h"

int main() {
	NoobSolitarie noobSolitarie(*new Controllers::Local::Logic(), *new Views::Console::NoobSolitarieView());
	noobSolitarie.run();

	std::getchar();
	return 0;
}
