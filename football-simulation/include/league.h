#include <iostream>
#include "../include/team.h"
#include <vector>
#include <random>
#include <initializer_list>
#include "../include/match.h"


class League
{

private:
	std::string name = "Unnamed League";
	int teamLimit = 20;

	std::vector<Team> teams;

	std::vector<Match> matches;

	int matchdays;

	int matchCount;

public:

	League() = default;

	League(std::string name, int teamLimit);

	void addTeam(std::initializer_list<Team> teams);

	void createMockLeague();

	void mirrorSchedule();

	void generateSchedule();

	void printLeague();




	// helper functions

	void setName(const std::string newName) { name = newName; }
	std::string getName() const { return name; }

	void setLimit(const int newLimit) { teamLimit = newLimit; }
	int getLimit() const { return teamLimit; }


	int getRandomNumber(int min, int max);
	int getMatchDays() const { return matchdays; }


};