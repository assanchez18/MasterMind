#include "SaveGameCommand.h"
#include "SaveGameView.h"
#include "BoardView.h"
#include <dirent.h>
#include "Config.h"

#include <iostream>
using namespace std;

SaveGameCommand::SaveGameCommand(std::string title, InGameController* controller)
  : InGameCommand(title, controller) {
}

SaveGameCommand::~SaveGameCommand() {
}

void SaveGameCommand::execute() {
  SaveGameView* view = new SaveGameView();
  std::string gameName = view->requestGameName();
  int result = checkIfFileExists(gameName);
  if (result != ERROR_NOACCESS) {
    if (result != 0 || view->askIfOverride()) {
      string pathForGame = Config::getInstance()->getSaveGamePath() + gameName + ".txt";
      controller_->saveGame(pathForGame);
      printf("Game saved correctly.\n");
    }
    else {
      printf("Game was not saved.\n");
    }
	BoardView* boardView = new BoardView();
	boardView->interact(controller_);
  }
  delete view;
}

int SaveGameCommand::checkIfFileExists(const std::string &gameName) {
  DIR *dir;
  struct dirent *ent;
  int fileExists = -1;
  Config* conf = Config::getInstance();
  string name = gameName + ".txt";
  string savedPath = conf->getSaveGamePath();
  char *path[sizeof(savedPath)];
  for (int i = 0; i < sizeof(savedPath); i++) {
    path[i] = &savedPath.at(i);
  }
  if ((dir = opendir(*path)) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir(dir)) != NULL) {
      if (ent->d_name == name) {
        fileExists = 0;
        break;
      }
    }
    closedir(dir);
    //delete []path;
    return fileExists;
  }
  else {
    char errorMessage[100];
    printf(errorMessage, sizeof errorMessage, "Unable to open destination path where to save the game: %s", savedPath);
    perror(errorMessage);
    return ERROR_NOACCESS;
  }

}

bool SaveGameCommand::isActive()
{
	return true;
}
