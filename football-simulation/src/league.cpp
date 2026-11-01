#include "../include/league.h"

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
	for (int i = 0; i <= 5; i++)
	{
		Team mockTeam = Team("Team " + std::to_string(i), "TM" + std::to_string(i), getRandomNumber(0, 99));
		teams.push_back(mockTeam);
	}
}

void League::printLeague()
{
	for (int i = 0; i <= 2; i++)
	{
		std::cout << teams[i].name << ", " <<  teams[i].abbr << ", " << teams[i].ovr << std::endl;
	}
}