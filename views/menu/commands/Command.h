#pragma once
#include <string>

class Command {
public:
  Command(std::string title) :
    title_(title) {
  }

  inline const std::string getTitle() { return title_; }
  virtual void execute() = 0;
  virtual bool isActive() = 0;

private:
  const std::string title_;
};