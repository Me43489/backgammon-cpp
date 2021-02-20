#pragma once
/*****************************
			Instance of board class
******************************/
#include <cstdint>
#include <stack>
#include "space.hpp"

class Board {
private:
	static const uint32_t  SIZE = 144;

public:
	Space data[SIZE];
	std::stack<Space> waitQueue;

	void clear();
	void set();
	void update();
};

