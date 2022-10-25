#include <stdio.h>
#include <string.h>

int install();
int defaultCommand();

#define COMMANDS_LIST_SIZE 1
#define COMMANDS_LIST { \
                        { \
                          "install", \
                          &install \
                        } \
                      }


typedef int(*cmdcallbackfunc)();

struct MainCommands {
  char *command;
  cmdcallbackfunc callback_func;
};

cmdcallbackfunc getCommandFunction(char *);
