#include <iostream>
#include "../include/team.h"
#include "../include/league.h"
#include <vector>

int main()
{

	League myLeague("My League", 20);
	myLeague.createMockLeague();
	myLeague.printLeague();



	

	return 0;
}
