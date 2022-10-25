#include "cli.h"

int install() {
  printf("install() method\n");

  return 0;
}

int defaultCommand() {
  printf("%s\n", ">> WARNING:: This is default command.");

  return 0;
}

cmdcallbackfunc getCommandFunction(char *command) {
  struct MainCommands commands_list[COMMANDS_LIST_SIZE] = COMMANDS_LIST;
  cmdcallbackfunc cmd_func = &defaultCommand;

  for (int i = 0; i < COMMANDS_LIST_SIZE; i++) {
    if (strcmp(commands_list[i].command, command) == 0) {
      cmd_func = commands_list[i].callback_func;
    }
  }

  return cmd_func;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("%s\n", ">> ERROR:: arguments count is invalid.");

    return 1;
  }

  cmdcallbackfunc cmd_func = getCommandFunction(argv[1]);

  return (*cmd_func)();
}
