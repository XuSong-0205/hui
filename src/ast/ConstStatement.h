#pragma once
#ifndef CONSTSTATEMENT_H
#define CONSTSTATEMENT_H

#include "VarStatement.h"

namespace hui {

class ConstStatement : public VarStatement
{
public:
	using VarStatement::VarStatement;
};

}	// namespace hui

#endif // !CONSTSTATEMENT_H
