#pragma once
#include <iostream>
#include <string>


class Team
{
public:

	std::string name = "Unnamed Team", abbr = "Unnamed Abbreviation";
	int ovr{};


	Team() = default;

	Team(std::string name, std::string abbr, int ovr);

};