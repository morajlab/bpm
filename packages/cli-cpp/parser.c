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

void feed_schema(PackageSchema *psch, char *line) {
  LineStruct ls = get_line_struct(line);

  if (ls.value) {
    if (strcmp(ls.key, "NAME") == 0) {
      psch->name = ls.value;
    }

    if (strcmp(ls.key, "LICENSE") == 0) {
      psch->license = ls.value;
    }

    if (strcmp(ls.key, "DESCRIPTION") == 0) {
      psch->description = ls.value;
    }

    if (strcmp(ls.key, "REPOSITORY") == 0) {
      psch->repository = ls.value;
    }

    if (strcmp(ls.key, "SOURCE") == 0) {
      psch->source = ls.value;
    }

    if (strcmp(ls.key, "BIN") == 0) {
      psch->bin = ls.value;
    }

    if (strcmp(ls.key, "KEYWORDS") == 0) {
      // TODO
    }

    if (strcmp(ls.key, "VERSION") == 0) {
      psch->version = ls.value;
    }

    if (strcmp(ls.key, "DEPENDENCIES") == 0) {
      // TODO
    }

    if (strcmp(ls.key, "DEV_DEPENDENCIES") == 0) {
      // TODO
    }

    if (strcmp(ls.key, "AUTHOR") == 0) {
      // TODO
    }
  }
}

PackageSchema parse(char *path) {
  PackageSchema psch;
  char *content = get_file_content(path);
  struct Chain *content_chain_head = create_content_chain(content);

  if (content_chain_head != NULL) {
    bool first_iterate = true;
    char *line;

    do {
      line = get_line(content_chain_head);

      if (line != NULL) {
        feed_schema(&psch, line);
      }

      if (first_iterate) {
        content_chain_head = NULL;
        first_iterate = false;
      }
    } while (line != NULL);
  }

  return psch;
}
