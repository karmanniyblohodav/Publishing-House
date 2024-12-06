#pragma once

#include "..\Project2\Publication.h"

class Journal : public Publication {
public:
	Journal(const std::string& title, int year);
	void displayInfo() const override;
};

