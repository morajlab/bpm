#include "parser.h"

LineStruct get_line_struct(char *line) {
  LineStruct line_struct;

  char *key = strtok(line, KEY_VALUE_TOKEN);
  char *value = strtok(NULL, KEY_VALUE_TOKEN);;

  line_struct.key = key ? key : "";
  line_struct.value = value ? value : "";

  return line_struct;
}

char *get_line(char *string) {
  return strtok(string, "\n");
}

PackageSchema parse(char *path) {
  PackageSchema psch;
  char *content = get_file_content(path);

  if (content) {
    bool first_iterate = true;
    struct Lines lines;
    LineStruct line_struct;

    do {
      line = get_line(content);
      // line_struct = get_line_struct(line);

      if (line) {
        puts(line);
      }
      // printf("%s -> %s\n", line_struct.key, line_struct.value);

      if (first_iterate) {
        content = NULL;
        first_iterate = false;
      }
    } while (line);

    // psch.name = line_struct.value;
  }

  return psch;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    PackageSchema psch = parse(argv[1]);

    // puts(psch.name);
  }

  return 0;
}
