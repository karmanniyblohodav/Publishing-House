#pragma once
class Generator
{
public:
	virtual ~Generator() = 0 {};

	virtual int generate() const = 0;
};

