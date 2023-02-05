#pragma once

#include <string>

class Component
{
protected:
	std::string typeName;

	Component(std::string typeName)
		: typeName(typeName) {}
};