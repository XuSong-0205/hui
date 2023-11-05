#pragma once
#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Node.h"
#include "Environment.h"
#include "Object.h"

#include <memory>


namespace hui {

class Evaluator
{
private:

public:
	std::shared_ptr<Object> eval(Node* node, Environment* env);


};

}	// namespace hui

#endif // !EVALUATOR_H
