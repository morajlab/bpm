#include "promise.h"

// TODO: Promise should push and pop content in a stack

Promise promise(void* content, enum PromiseType type) {
  *promise_content = *content;
  Promise prm = { promise_content, type };

  return prm;
}
