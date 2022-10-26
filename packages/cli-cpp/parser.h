#include <stdio.h>

typedef version_s char *;

struct PackageAuthorSchema {
  char *name;
  char *email;
  char *url;
}

struct PackageDependencySchema {
  char *name;
  version_s version;
}

struct PackageSchema {
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
  version_s version;
  /*
    TODO: Use dynamic sized dependencies array:
          struct PackageDependencySchema dependencies[];
  */
  struct PackageDependencySchema dependencies;
  struct PackageDependencySchema dev_dependencies;
  struct PackageAuthorSchema author;
};
