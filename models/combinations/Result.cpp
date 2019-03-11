#include <iostream>
#include <assert.h>
#include "Result.h"
#include "CloseInterval.h"

using namespace std;


//TO-DO: BUILDER FOR RESULT?
Result::Result(SecretCombination* secret, Combination* playerCombination) {
  assert(secret != nullptr);
  assert(playerCombination != nullptr);
  createResult(secret, playerCombination);
  if (combination.size() < SIZE_OF_COMBINATION) {
    fillResult();
  }

}

Result::Result(std::string result) {
  for (char a : result) {
    ResultColor* color = new ResultColor(a);
    pushColorToCombination(std::move(color));
  }
}

Result::~Result() {
}


void Result::createResult(SecretCombination * secret, Combination* playerCombination) {
  assert(secret != nullptr);
  assert(playerCombination != nullptr);

  map<char, vector<int>> possiblePositions = {};
  map<char, vector<int>> secretPositions = {};
  loadSetOfPosition(possiblePositions, playerCombination->getCombination());
  loadSetOfPosition(secretPositions, secret->getCombination());

  map<char, vector<int>>::iterator itPossible;
  for (itPossible = possiblePositions.begin(); itPossible != possiblePositions.end(); itPossible++) {
    if (containsColor(secretPositions, itPossible->first)) {
      compareVectors(secretPositions.at(itPossible->first), itPossible->second);
    }
  }
}

void Result::fillResult() {

  for (int i = combination.size(); i < SIZE_OF_COMBINATION; i++) {
    pushColorToCombination(std::move(new ResultColor(ResultColor::NO_COLOR)));
  }
}

bool Result::isSolution() {
  Color c = Color::Color(Color::BLACK);
  for (unsigned i = 0; i < combination.size(); i++) {
    if (!combination.at(i)->isEqual(&c)) {
      return false;
    }
  }
  return true;
}

void Result::pushIntoMap(map<char, vector<int>>& map, char color, int position) {
  assert(&color != nullptr);
  assert(&position != nullptr);
  assert(CloseInterval::CloseInterval(0, SIZE_OF_COMBINATION).contains(position));

  if (!containsColor(map, color)) {
    vector<int> tmp;
    tmp.emplace_back(position);
    map.insert_or_assign(color, tmp);
  }
  else {
    map.at(color).emplace_back(position);
  }
}

void Result::loadSetOfPosition(map<char, vector<int>>& map, vector<Color*>& combination) {
  assert(&combination != nullptr);

  for (unsigned int i = 0; i < combination.size(); i++) {
    pushIntoMap(map, combination.at(i)->getColor(), i);
  }
}

bool Result::containsPosition(vector<int> &positions, int position) {
  assert(&positions != nullptr);
  assert(&position != nullptr);
  assert(CloseInterval::CloseInterval(0, SIZE_OF_COMBINATION).contains(position));

  for (unsigned int i = 0; i < positions.size(); i++) {
    if (positions.at(i) == position) {
      positions.at(i) = -1;
      return true;
    }
  }
  return false;
}

bool Result::containsColor(map<char, vector<int>> map, char color) {
  assert(&map != nullptr);
  assert(&color != nullptr);

  return (map.count(color) == 1);
}

void Result::compareVectors(vector<int> secret, vector<int> possible) {
  assert(&possible != nullptr);

  int itemsAdded = 0;
  for (unsigned int i = 0; i < possible.size(); i++) {
    if (containsPosition(secret, possible.at(i))) {
      pushColorToCombination(std::move(new ResultColor(ResultColor::BLACK)));
      itemsAdded++;
    }
  }
  if (possible.size() >= secret.size()) {
    unsigned int absoluteDifference = secret.size() - itemsAdded;
    for (unsigned int i = 0; i < absoluteDifference; i++) {
      pushColorToCombination(std::move(new ResultColor(ResultColor::WHITE)));
    }
  }
}
