#pragma once

#include "Generator.h"
#include <iostream>

class IStreamGenerator : public Generator
{
private:
	std::istream& in;
public:
	IStreamGenerator(std::istream& in = std::cin);

	int generate();
};

