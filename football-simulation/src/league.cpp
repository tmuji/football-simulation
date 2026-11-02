#include "../include/league.h"
#include "../include/match.h"

League::League(std::string name, int teamLimit) : name(name), teamLimit(teamLimit)
{

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

void League::generateSchedule()
{

	// TODO: HANDLE ODD NUMBER OF TEAMS


	std::vector<Team> anchorList = teams; // put teams into temp vector to allow shifting

	std::vector<Match> matches; 

	int matchCount = teams.size() * (teams.size() - 1) / 2; // standard *single* round robin formula

	int roundsToPlay = teams.size() / 2; 

	for (int round = 0; round < matchCount; round+=roundsToPlay) // increment for each matchday ( for 45 games, each increment is 5 which makes 9 matchdays )
	{
		std::cout << "Matchday: " + std::to_string((round / roundsToPlay) + 1) << std::endl; // TODO: ADD PROPER MATCHDAY VARIABLE (it currently does bogus math)


		for (int i = 0; i < teams.size() / 2; i++)
		{
			Match match = Match(anchorList[i], anchorList[teams.size() - 1 - i]);
			matches.push_back(match);

			std::cout << match.returnHome().name << " VS " << match.returnAway().name << std::endl;
		}

		std::cout << "-------------" << std::endl;

		// rotate every element apart from [0] ("the anchor")
		std::rotate(anchorList.begin() + 1, anchorList.end() - 1, anchorList.end()); 

	}

}

void League::printLeague()
{
	for (int i = 0; i < teamLimit; i++)
	{
		std::cout << teams[i].name << ", " <<  teams[i].abbr << ", " << teams[i].ovr << std::endl;
	}
}