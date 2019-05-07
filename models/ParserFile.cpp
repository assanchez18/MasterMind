#include "ParserFile.h"



ParserFile::ParserFile(Session* session) :
	session_(session) {
}


ParserFile::~ParserFile() {
}

void ParserFile::secretCombination(std::string secret) {
	session_->setSecretCombination(secret);
}

void ParserFile::playedRounds(std::string & value) {
	session_->setPlayedRounds(std::stoi(value));
}

void ParserFile::toRound(std::string combWithResult) {
	std::string splitter = "*";
	size_t pos = combWithResult.find(splitter);
	std::string aux = combWithResult.substr(0, pos);
	Combination *comb = new Combination(aux);
	aux = combWithResult.substr(pos + 1, combWithResult.size());
	Result *result = new Result(aux);
	std::pair<Combination*, Result*> round(comb, result);
	session_->setRound(round);
}

