#include <iostream>
#include "../include/team.h"
#include "../include/league.h"
#include <vector>

int main()
{

	League myLeague("My League", 10);
	myLeague.createMockLeague();
	//myLeague.printLeague();
	myLeague.generateSchedule();



	

	return 0;
}
