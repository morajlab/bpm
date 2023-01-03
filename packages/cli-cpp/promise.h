static void* promise_content = NULL;

enum PromiseType {
  SUCCESS,
  ERROR
}

typedef struct {
  void* content;
  enum PromiseType type;
} Promise;
