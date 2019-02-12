#pragma once
#include <string>

class Command {
public:
  Command() : title_() {};
	Command(std::string title) :
		title_(title)
	{}

	inline const std::string getTitle() { return title_; }
  virtual void execute() = 0;

private:
	const std::string title_;
};