#include "parser.h"

prepare_chain(char *);

char *get_line(struct Chain *chain_head) {
  char *line = NULL;

  if (chain_head != NULL) {
    lines_chain_head = chain_head;
  }

  if (lines_chain_head != NULL) {
    line = lines_chain_head->value;
    lines_chain_head = lines_chain_head->next;
  }

  return line;
}

struct Chain *create_content_chain(char *content) {
  struct Chain *head = NULL;

  if (content) {
    bool first_iterate = true;
    char *line;

    do {
      line = strtok(content, "\n");

      if (line) {
        head = insert_chain(line);
      }

      if (first_iterate) {
        content = NULL;
        first_iterate = false;
      }
    } while (line);
  }

  return head;
}

LineStruct get_line_struct(char *line) {
  LineStruct line_struct;

  char *key = strtok(line, KEY_VALUE_TOKEN);
  char *value = strtok(NULL, KEY_VALUE_TOKEN);;

  line_struct.key = key ? key : "";
  line_struct.value = value ? value : "";

  return line_struct;
}

PackageSchema parse(char *path) {
  PackageSchema psch;
  char *content = get_file_content(path);
  struct Chain *content_chain_head = create_content_chain(content);

  if (content_chain_head != NULL) {
    bool first_iterate = true;
    char *line;
    LineStruct line_struct;

    do {
      line = get_line(content_chain_head);
      // line_struct = get_line_struct(line);

      if (line != NULL) {
        puts(line);
      }
      // printf("%s -> %s\n", line_struct.key, line_struct.value);

      if (first_iterate) {
        content_chain_head = NULL;
        first_iterate = false;
      }
    } while (line != NULL);

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
