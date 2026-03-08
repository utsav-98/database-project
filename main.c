#include "backend/backend.h"
#include "common.h"
#include "frontend/frontend.h"

int main() {
  inputBuffer *new_input_buffer = init_inputBuffer();
  while (true) {
    printPrompt();
    read_input(new_input_buffer);

    if (isMetaCommand(new_input_buffer)) {
      if (isExit(new_input_buffer)) {
        exit(EXIT_SUCCESS);
      } else {
        printf("unrecognized command '%s'.\n", new_input_buffer->input);
      }
    } else {
      printf("unrecognized command '%s'.\n", new_input_buffer->input);
    }
  }

  return 0;
}
