#include <iostream>
#include "../include/team.h"

class Match
{

private:
	Team home, away;

public:


	Match(Team home, Team away);


	Team returnHome() { return home; }
	Team returnAway() { return away; }

};