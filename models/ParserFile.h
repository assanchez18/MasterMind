#pragma once
#include <string>
#include "Session.h"

class ParserFile{
public:
	ParserFile(Session* session);
	~ParserFile();

	void secretCombination(std::string secret);
	void playedRounds(std::string& value);
	void toRound(std::string combWithResult);
private:
	Session* session_;
};

