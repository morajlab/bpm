#include <string.h>
#include "schema.h"
#include "libmjl-cpp/src/create_chain/create_chain.h"
#include "libmjl-cpp/src/get_file_content/get_file_content.h"

#define KEY_VALUE_TOKEN "="

static struct Chain *lines_chain_head = NULL;
static SchemaItem *PSCH = NULL;

typedef struct {
  char *key;
  char *value;
} LineStruct;

LineStruct get_line_struct(char *);
Error parse(SchemaItem *,char *);
char *get_line(struct Chain *);
struct Chain *create_content_chain(char *);
void feed_schema(Error *, char *);
void validate(Error *, SchemaItem *, char *);
