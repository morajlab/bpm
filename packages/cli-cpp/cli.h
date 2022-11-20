#include <stdio.h>
#include <string.h>

enum ScopeType {
  GLOBAL,
  LOCAL
};

/*
  TODO: Get '$HOME' linux environment variable and use following line:
        #define GLOBAL_BASH_MODULES_PATH $HOME/.bash_modules
*/
#define GLOBAL_BASH_MODULES_PATH "~/.bash_modules"
#define LOCAL_BASH_MODULES_PATH "to/path/example"
#define MODULES_BIN_PATH(x) (x == GLOBAL ? GLOBAL_BASH_MODULES_PATH : LOCAL_BASH_MODULES_PATH)

int install(int, char **);
int defaultCommand(int, char **);

#define COMMANDS_LIST_SIZE 1
#define COMMANDS_LIST { \
                        { \
                          "install", \
                          &install \
                        } \
                      }


typedef int(*cmdcallbackfunc)(int, char **);

struct MainCommands {
  char *command;
  cmdcallbackfunc callback_func;
};

cmdcallbackfunc getCommandFunction(char *);
