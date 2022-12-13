#include "cli.h"

int install(int argc, char **argv) {
  bool global = false;

  /* TODO: process arguments */
  for (int i = 2; i < argc; i++) {
    if (strcmp(argv[i], "--global") == 0) {
      global = true;
    }
  }

  char *package = request(argv[2]);
  /* TODO: process arguments */

  if (package == NULL) {
    printf(">> ERROR:: package '%s' not found !", argv[2]);

    return 1;
  }

  SchemaItem psch[] = PACKAGE_SCHEMA;

  Error er = parse(psch, package);

  if (er.message != NULL) {
    printf("message: %s\nid: %i\n", er.message, er.id);

    return 1;
  }

  for (int i = 0; i < PACKAGE_SCHEMA_SIZE; i++) {
    printf("name: %s\nvalue: %s\n-----------\n", psch[i].name, psch[i].value);
  }

  return 0;
}

int defaultCommand(int argc, char **argv) {
  printf("%s\n", ">> WARNING:: This is default command.");

  return 0;
}

cmdcallbackfunc get_cmd_fn(char *command) {
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

  cmdcallbackfunc cmd_func = get_cmd_fn(argv[1]);

  return (*cmd_func)(argc, argv);
}
