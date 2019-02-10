#pragma once
#include <string>
class Command {
public:
	Command(std::string title) :
		title_(title)
	{}

	virtual void execute() = 0;
	inline const std::string getTitle() { return title_; }

protected:
	const std::string title_;
};