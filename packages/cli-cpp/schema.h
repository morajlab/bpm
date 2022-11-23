#include <stdio.h>
#include <stdbool.h>

typedef bool(*validator_fn)(void *);

typedef struct {
  char *name;
  validator_fn vfn;
} SchemaItem;
