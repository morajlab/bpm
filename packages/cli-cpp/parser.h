#include "file.h"
#include <string.h>
#include <stdbool.h>

#define KEY_VALUE_TOKEN "="

struct Lines {
  char *value;
  struct Lines *next;
}

typedef struct {
  char *key;
  char *value;
} LineStruct;

typedef struct {
  char *name;
  char *email;
  char *url;
} PackageAuthorSchema;

typedef struct {
  char *name;
  char *version;
} PackageDependencySchema;

typedef struct {
  char *name;
  char *license;
  char *description;
  char *repository;
  /*
    TODO: Use dynamic sized sources array:
          char *source[];
  */
  char *source;
  char *bin;
  /*
    TODO: Use dynamic sized keys array:
          char *key[];
  */
  char *key[20];
  char *version;
  /*
    TODO: Use dynamic sized dependencies array:
          struct PackageDependencySchema dependencies[];
  */
  PackageDependencySchema dependencies;
  PackageDependencySchema dev_dependencies;
  PackageAuthorSchema author;
} PackageSchema;

LineStruct get_line_struct(char *);
char *get_line(char *);
PackageSchema parse(char *);
