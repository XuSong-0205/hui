#pragma once
#ifndef REPL_H
#define REPL_H

namespace hui {

class Repl
{
public:
	void start();
	void exec(const char* file_name);
};

}	// namespace hui

#endif // !REPL_H
