#include "SaveGameView.h"
#include <iostream>
using namespace std;


SaveGameView::SaveGameView() {
}


SaveGameView::~SaveGameView() {
}

string SaveGameView::requestGameName() {
  
  string gameName = "";
  do {
    cout << "Introduce the name of the game to save: ";
    cin >> gameName;
    cout << endl;
  } while (gameName.empty());
  return gameName;
}
