#include "BoardView.h"
#include "ColorView.h"
#include "Combination.h"
#include "Result.h"
#include "State.h"
#include <iostream>
using namespace std;


BoardView::BoardView() {
}


BoardView::~BoardView() {
}

void BoardView::interact(IController* controller) {
  bool victory = false;
  cout << "ROUND\t|\tCOMBINATION\t|\tRESULT" << endl;
  int i = 0;
  for (i; i < controller->getRounds().size(); i++) {
    cout << i + 1 << "\t|\t";
    pair<Combination*, Result*> round = controller->getRounds().at(i);
    printRound(round.first);
    cout << "\t|\t";
    printRound(round.second);
    cout << endl;
  }

  switch (controller->getState()) {
    case StateValue::WON:
      printVictory();
      break;
    case StateValue::DEFEAT:
      printLoose();
      break;
    case StateValue::IN_GAME:
      cheerPlayer();
      break;
  }
}

void BoardView::printRound(Combination* combination) {
  for (const auto& color : combination->getCombination()) {
    ColorView* colorView = new ColorView(color);
    colorView->interact();
    cout << " ";
    delete colorView;
  }
}

void BoardView::printVictory() {
  cout << "¡VICTORIA!" << endl;
  cout << "¡FELICIDADES!" << endl;
}

void BoardView::printLoose() {
  cout << "Sorry, you loose, PLAY try it again!" << endl;
}

void BoardView::cheerPlayer() {
  cout << "Your Combination is not correct. TRY it again!" << endl;
}