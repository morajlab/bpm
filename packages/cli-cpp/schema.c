#include "schema.h"

bool name_vfn(void *value) {
  return true;
}
void name_setter(void *value, char *new_value) {
  strcpy(value, &new_value);
}

bool description_vfn(void *value) {
  return true;
}
void description_setter(void *value, char *new_value) {
  strcpy(value, &new_value);
}
