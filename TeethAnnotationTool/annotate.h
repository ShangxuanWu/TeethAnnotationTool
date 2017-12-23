#pragma once
#include <string>
#include "../Utils/config.h"

class Annotate {
public:
	Annotate();
	Annotate(std::string part, std::string direction);
private:
	std::string _part;
	std::string _direction;
};