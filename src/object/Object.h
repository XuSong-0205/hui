#pragma once
#ifndef OBJECT_H
#define OBJECT_H

#include "Constant.h"

namespace hui {

class Object
{
public:
	virtual ~Object() = default;
	virtual OBJECT_TYPE type() { return OBJECT_TYPE::NULL_OBJ; }
	virtual std::string inspect() { return ""; }
	static const char* object_type_value(OBJECT_TYPE type)
	{
		return OBJECT_TYPE_VALUE[static_cast<int>(type)];
	}
};

}	// namespace hui

#endif // !OBJECT_H
