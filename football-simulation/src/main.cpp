#include <iostream>
#include "../include/team.h"
#include "../include/league.h"
#include <vector>

int main()
{
	
	// temporary teams
	Team madrid = Team("Real Madrid", "RMA", 91);
	Team barca = Team("FC Barcelona", "FCB", 93);
	Team liverpool = Team("Liverpool", "LFC", 83);
	Team psg = Team("Paris Saint Germain", "PSG", 97);
	Team dortmund = Team("Borussia Dortmund", "BVB", 85);




	League myLeague("Champions League", 5);
	myLeague.addTeam({madrid, barca, liverpool, psg, dortmund});
	myLeague.generateSchedule();
	myLeague.printLeague();



	

	return 0;
}
