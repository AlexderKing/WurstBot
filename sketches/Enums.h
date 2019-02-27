#pragma once

#ifndef __ENUMS_H
#define __ENUMS_H

#include <stdint.h>

class Status final
{
public: 
	const static uint8_t Enabled = 0;
	const static uint8_t Disabled = 1;
};

class Direction final
{
public:
	const static uint8_t Right = 0;
	const static uint8_t Left = 1;
};

class MovingDirection final
{
public:
	const static uint8_t North = 0;
	const static uint8_t East  = 1;
	const static uint8_t South = 2;
	const static uint8_t West  = 3;
};

#endif
