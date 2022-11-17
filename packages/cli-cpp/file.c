#include "file.h"

char *get_file_content(char *path) {
  char *buffer = NULL;
  long length;

  FILE *file = fopen(path, "rb");

  if (file) {
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = malloc(length);

    if (buffer) {
      fread(buffer, 1, length, file);
    }

    fclose(file);
  }

  return buffer;
}
