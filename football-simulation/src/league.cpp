#include "../include/league.h"

League::League(std::string name, int teamLimit) : name(name), teamLimit(teamLimit)
{

}

void League::addTeam(std::initializer_list<Team> teamsToAdd)
{
	for (Team teamToAdd : teamsToAdd) {
		teams.push_back(teamToAdd);
	}
}


int League::getRandomNumber(int min, int max)
{
	// i dont even know what these lines do
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(min, max);
	return distrib(gen);
}

void League::createMockLeague()
{
	for (int i = 0; i < teamLimit; i++)
	{
		Team mockTeam = Team("Team " + std::to_string(i), "TM" + std::to_string(i), getRandomNumber(0, 99));
		teams.push_back(mockTeam);
	}
}

void League::mirrorSchedule()
{

	int matchSize = matches.size(); // define before so it doesnt loop forever
	for (int i = 0; i < matchSize; i++) {
		Match mirroredMatch = Match(matches[i].returnAway(), matches[i].returnHome());
		matches.push_back(mirroredMatch);
	}

}


void League::generateSchedule()
{

	if (teams.size() > teamLimit)
	{
		std::cerr << "Team Count Exceeds Limit!" << std::endl;
	}

	std::vector<Team> anchorList = teams; // put teams into temp vector to allow shifting



	matchCount = teams.size() * (teams.size() - 1) / 2; // standard *single* round robin formula
	matchCount *= 2; // (doubled for double ig)

	int roundsToPlay = teams.size() / 2; 



	for (int round = 0; round < matchCount; round+=roundsToPlay) // increment for each matchday ( for 45 games, each increment is 5 which makes 9 matchdays )
	{
		
		matchdays = (round / roundsToPlay) + 1; // don't know how i made this up
		for (int i = 0; i < roundsToPlay + 1; i++)
		{



			Match match = Match(anchorList[i], anchorList[teams.size() - 1 - i]);
			matches.push_back(match);

			if (teams.size() % 2 != 0 && i == roundsToPlay) // last team gets a free pass
			{
				matches.pop_back(); // remove last element which is normally the same odd team playing itself
				Team ghostTeam = Team("Ghost", "GHO", 99);
				match = Match(anchorList[i], ghostTeam);
				matches.push_back(match);
			}

		}
		

		// rotate every element apart from [0] ("the anchor")
		std::rotate(anchorList.begin() + 1, anchorList.end() - 1, anchorList.end()); 

	}

	mirrorSchedule();


}


void League::printLeague()
{

	int increment = matchCount / matchdays;

	std::cout << std::to_string(matchCount) << std::endl << std::to_string(matchdays) << std::endl << std::to_string(increment) << std::endl;
	for (int i = 0; i < matches.size(); i++) {


		// TODO: ADD WINS AND LOSSES FOR EACH TEAM (ESPECIALLY AUTO WINS FOR GHOST TEAMS) SO I DONT HAVE TO DO THIS BULLSHIT IF STATEMENT
		if (matches[i].returnHome().name == "Ghost" || matches[i].returnAway().name == "Ghost")
		{
			
		}
		else
		{
			std::cout << matches[i].returnHome().name << " VS " << matches[i].returnAway().name << std::endl;
		}

		// on every new matchday format accordingly
		if (i % increment == 0 && i != 0)
		{
			std::cout << "----------------" << std::endl;
		}
	}
}
