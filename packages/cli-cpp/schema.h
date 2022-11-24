#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define S_NAME_I { \
                  "NAME", \
                  NULL, \
                  &name_setter, \
                  &name_vfn \
                 }
#define S_DESCRIPTION_I { \
                         "DESCRIPTION", \
                         NULL, \
                         &description_setter, \
                         &description_vfn \
                        }

#define PACKAGE_SCHEMA { \
                        S_NAME_I, \
                        S_DESCRIPTION_I \
                       }
#define PACKAGE_SCHEMA_SIZE 2

typedef bool(*validator_fn)(void *);
typedef void(*setter_fn)(void *, char *);

typedef struct {
  char *name;
  void *value;
  setter_fn setter;
  validator_fn vfn;
} SchemaItem;

// Verifier functions
bool name_vfn(void *);
bool description_vfn(void *);

// Setter functions
void name_setter(void *, char *);
void description_setter(void *, char *);
