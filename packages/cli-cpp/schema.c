#include "schema.h"
#include <string.h>

// Verifier functions
void name_vfn(Promise *prm, void *value) {}
void license_vfn(Promise *prm, void *value) {}
void repository_vfn(Promise *prm, void *value) {}
void source_vfn(Promise *prm, void *value) {}
void bin_vfn(Promise *prm, void *value) {}
void version_vfn(Promise *prm, void *value) {}
void keywords_vfn(Promise *prm, void *value) {}
void dependencies_vfn(Promise *prm, void *value) {}
void devdependencies_vfn(Promise *prm, void *value) {}
void author_vfn(Promise *prm, void *value) {}
void description_vfn(Promise *prm, void *value) {}

// Setter functions
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
