#include "IStreamGenerator.h"

int IStreamGenerator::generate() {
	int value = 0;
	this->in >> value;
	return value;
}