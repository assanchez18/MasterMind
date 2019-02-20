#include "SaveGameCommand.h"
#include "SaveGameView.h"
#include <dirent.h>
#include "Config.h"

SaveGameCommand::SaveGameCommand(std::string title, InGameController* controller)
  : InGameCommand(title, controller) {
}

SaveGameCommand::~SaveGameCommand() {
}

void SaveGameCommand::execute() {
  SaveGameView* view = new SaveGameView();
  std::string gameName = view->requestGameName();
 /*
  TO-DO: USE DIRENT.h algorithm 
  
  */
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir("c:\\src\\")) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir(dir)) != NULL) {
      printf("%s\n", ent->d_name);
    }
    closedir(dir);
  }
  else {
    /* could not open directory */
    perror("");
    return EXIT_FAILURE;
  }

  //ask if want to overwrite the game (if exists)
  controller_->saveGame(gameName);
}


