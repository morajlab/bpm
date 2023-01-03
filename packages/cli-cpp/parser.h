#include <string.h>
#include "schema.h"
#include "promise.h"
#include "libmjl-cpp/src/create_chain/create_chain.h"

#define KEY_VALUE_TOKEN "="

static struct Chain *lines_chain_head = NULL;
static SchemaItem *PSCH = NULL;

typedef struct {
  char *key;
  char *value;
} LineStruct;

LineStruct get_line_struct(char *);
Promise parse(SchemaItem *,char *);
char *get_line(struct Chain *);
struct Chain *create_content_chain(char *);
void feed_schema(Promise *, char *);
void validate(Promise *, SchemaItem *, char *);
