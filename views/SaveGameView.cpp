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

bool SaveGameView::askIfOverride() {
  printf("File already exists, do you want to replace it?\n");
  printOptions();
  char value[10];
  while (true) {
    cin >> value;
    if (!strcmp(value, "yes")) {
      return true;
    }
    else if (!strcmp(value, "no")) {
      return false;
    }
    printf("Invalid option, please choose between:\n");
    printOptions();
  }
}

void SaveGameView::printOptions() {
  printf("- yes\n");
  printf("- no\n");
}