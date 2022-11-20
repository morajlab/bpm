#include <string.h>
#include <stdbool.h>
#include "libmjl-cpp/src/create_chain/create_chain.h"
#include "libmjl-cpp/src/get_file_content/get_file_content.h"

#define KEY_VALUE_TOKEN "="

struct Chain *lines_chain_head = NULL;

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
PackageSchema parse(char *);
char *get_line(struct Chain *);
struct Chain *create_content_chain(char *);
