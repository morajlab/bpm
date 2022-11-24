#include <stddef.h>
#include <stdbool.h>

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
#define S_LICENSE_I { \
                     "LICENSE", \
                     NULL, \
                     &license_setter, \
                     &license_vfn \
                    }
#define S_REPOSITORY_I { \
                        "REPOSITORY", \
                        NULL, \
                        &repository_setter, \
                        &repository_vfn \
                       }
#define S_SOURCE_I { \
                    "SOURCE", \
                    NULL, \
                    &source_setter, \
                    &source_vfn \
                   }
#define S_BIN_I { \
                 "BIN", \
                 NULL, \
                 &bin_setter, \
                 &bin_vfn \
                }
#define S_VERSION_I { \
                     "VERSION", \
                     NULL, \
                     &version_setter, \
                     &version_vfn \
                    }
#define S_KEYWORDS_I { \
                      "KEYWORDS", \
                      NULL, \
                      &keywords_setter, \
                      &keywords_vfn \
                     }
#define S_DEPENDENCIES_I { \
                          "DEPENDENCIES", \
                          NULL, \
                          &dependencies_setter, \
                          &dependencies_vfn \
                         }
#define S_DEVDEPENDENCIES_I { \
                             "DEV_DEPENDENCIES", \
                             NULL, \
                             &devdependencies_setter, \
                             &devdependencies_vfn \
                            }
#define S_AUTHOR_I { \
                    "AUTHOR", \
                    NULL, \
                    &author_setter, \
                    &author_vfn \
                   }

#define PACKAGE_SCHEMA { \
                        S_NAME_I, \
                        S_DESCRIPTION_I, \
                        S_LICENSE_I, \
                        S_REPOSITORY_I, \
                        S_SOURCE_I, \
                        S_BIN_I, \
                        S_VERSION_I, \
                        S_KEYWORDS_I, \
                        S_DEPENDENCIES_I, \
                        S_DEVDEPENDENCIES_I, \
                        S_AUTHOR_I \
                       }
#define PACKAGE_SCHEMA_SIZE 11

typedef struct {
  char *message;
  int id;
} Error;

typedef void(*validator_fn)(Error *, void *);
typedef void(*setter_fn)(void *, char *);

typedef struct {
  char *name;
  void *value;
  setter_fn setter;
  validator_fn vfn;
} SchemaItem;

// Verifier functions
void name_vfn(Error *, void *);
void description_vfn(Error *, void *);
void license_vfn(Error *, void *);
void repository_vfn(Error *, void *);
void source_vfn(Error *, void *);
void bin_vfn(Error *, void *);
void version_vfn(Error *, void *);
void keywords_vfn(Error *, void *);
void dependencies_vfn(Error *, void *);
void devdependencies_vfn(Error *, void *);
void author_vfn(Error *, void *);

// Setter functions
void name_setter(void *, char *);
void description_setter(void *, char *);
void license_setter(void *, char *);
void repository_setter(void *, char *);
void source_setter(void *, char *);
void bin_setter(void *, char *);
void version_setter(void *, char *);
void keywords_setter(void *, char *);
void dependencies_setter(void *, char *);
void devdependencies_setter(void *, char *);
void author_setter(void *, char *);
