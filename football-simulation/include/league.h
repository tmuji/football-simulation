#include <iostream>
#include "../include/team.h"
#include <vector>
#include <random>

class League
{

private:
	std::string name = "Unnamed League";
	int teamLimit = 20;

	std::vector<Team> teams;

public:

	League() = default;

	League(std::string name, int teamLimit);

	void createMockLeague();


	// helper functions
	void setName(const std::string newName) { name = newName; }
	std::string getName() const { return name; }

	void setLimit(const int newLimit) { teamLimit = newLimit; }
	int getLimit() const { return teamLimit; }

	void printLeague();


	int getRandomNumber(int min, int max);


};