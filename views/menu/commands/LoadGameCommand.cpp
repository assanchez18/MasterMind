#include "LoadGameCommand.h"
#include "Config.h"
#include "CloseInterval.h"
#include "BoardView.h"
#include <dirent.h>
#include <vector>
#include <iostream>

LoadGameCommand::LoadGameCommand(std::string title, OutGameController* controller)
  : OutGameCommand(title, controller) {
}

LoadGameCommand::~LoadGameCommand() {
}

void LoadGameCommand::execute() {
  std::string gameName = selectFileToLoad();
  if (gameName.compare(".") != 0) {
    controller_->loadGame(gameName);
    BoardView* boardView = new BoardView();
    boardView->interact(controller_->getBoardController());
    delete boardView;
  }
}

std::string LoadGameCommand::selectFileToLoad() {
  //TO-DO: REFACTOR THIS TO AVOID DUPLICATED CODE LoadGameCommand and SaveGameCommand
  DIR *dir;
  struct dirent *ent;
  string savedPath = Config::getInstance()->getSaveGamePath();
  char *path[sizeof(savedPath)];
  for (int i = 0; i < sizeof(savedPath); i++) {
    path[i] = &savedPath.at(i);
  }
  if ((dir = opendir(*path)) != NULL) {
    /* print all the files and directories within directory */
    int i = 0;
    std::vector<std::string> filesInPath;
    while ((ent = readdir(dir)) != NULL) {
      if (ent->d_name[0] != '.') {
        printf("%u %s\n", i + 1, ent->d_name);
        filesInPath.emplace_back(ent->d_name);
        i++;
      }
    }
    closedir(dir);
    return filesInPath.at(askForOption(i));
  }
  else {
    /* could not open directory */
    perror("Unable to load games. Directory not found");
    return ".";
  }
}

int LoadGameCommand::askForOption(int maxOption) {
  int option = -1;
  do {
    printf("%s", "Which game do you want to open? ");
    cin >> option;
  }while (!CloseInterval::CloseInterval(0, maxOption).contains(option)); 
  
  return option-1;
}
