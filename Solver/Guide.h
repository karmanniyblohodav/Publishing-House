#pragma once

#include "..\Project2\Publication.h"

class Guide : public Publication {
public:
	Guide(const std::string& title, int year);
	void displayInfo() const override;
};

