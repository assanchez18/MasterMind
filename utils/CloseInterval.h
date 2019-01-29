#pragma once
namespace utils {
class CloseInterval
{
public:
  CloseInterval(int min, int max);
  ~CloseInterval();

  int getMin();
  int getMax();
  bool contains(int value);

private:
  int min;
  int max;
};

}