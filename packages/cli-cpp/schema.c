#include "schema.h"
#include <string.h>

void name_vfn(Error *error, void *value) {}
void license_vfn(Error *error, void *value) {}
void repository_vfn(Error *error, void *value) {}
void source_vfn(Error *error, void *value) {}
void bin_vfn(Error *error, void *value) {}
void version_vfn(Error *error, void *value) {}
void keywords_vfn(Error *error, void *value) {}
void dependencies_vfn(Error *error, void *value) {}
void devdependencies_vfn(Error *error, void *value) {}
void author_vfn(Error *error, void *value) {}
void description_vfn(Error *error, void *value) {}

void name_setter(void *value, char *new_value) {
  strcpy(value, &new_value);
}
void description_setter(void *value, char *new_value) {
  strcpy(value, &new_value);
}
void license_setter(void *value, char *new_value) {}
void repository_setter(void *value, char *new_value) {}
void source_setter(void *value, char *new_value) {}
void bin_setter(void *value, char *new_value) {}
void version_setter(void *value, char *new_value) {}
void keywords_setter(void *value, char *new_value) {}
void dependencies_setter(void *value, char *new_value) {}
void devdependencies_setter(void *value, char *new_value) {}
void author_setter(void *value, char *new_value) {}
