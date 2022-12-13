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

void feed_schema(Error *error, char *line) {
  LineStruct ls = get_line_struct(line);

  if (ls.value) {
    for (int i = 0; i < PACKAGE_SCHEMA_SIZE; i++) {
      if (strcmp(ls.key, PSCH[i].name) == 0) {
        validate(error, &PSCH[i], ls.value);

        if (error->message == NULL) {
          PSCH[i].setter(&PSCH[i].value, ls.value);
        }

        break;
      }
    }
  }
}

void validate(Error *error, SchemaItem *pschi, char *value) {
  pschi->vfn(error, value);
}

Error parse(SchemaItem *psch, char *content) {
  PSCH = psch;
  Error pe = { NULL, 0 };
  struct Chain *content_chain_head = create_content_chain(content);

  if (content_chain_head != NULL) {
    bool first_iterate = true;
    char *line;

    do {
      line = get_line(content_chain_head);

      if (line != NULL) {
        feed_schema(&pe, line);

        if (pe.message != NULL) {
          break;
        }
      }

      if (first_iterate) {
        content_chain_head = NULL;
        first_iterate = false;
      }
    } while (line != NULL);
  }

  return pe;
}
