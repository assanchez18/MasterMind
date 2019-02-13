#include "RoundView.h"
#include <iostream>
#include "CombinationColor.h"
#include "Combination.h"
using namespace std;

RoundView::RoundView() {
}


RoundView::~RoundView() {
}

Combination* RoundView::requestCombination() {
  Combination* playerCombination = new Combination();
  for (int i = 0; i < playerCombination->getSizeOfCombination(); i++) {
    char input;
    CombinationColor* color;
    do {
      cout << "Introduce the color for position " << i + 1 << " (R, B, W, G, Y, O):";
      cin >> input;
      color = new CombinationColor(input);
    } while (!color->isValid());
    playerCombination->pushColorToCombination(move(color));
  }
  return move(playerCombination);
}
