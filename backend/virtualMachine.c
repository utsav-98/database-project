#include "backend.h"

// Meta Command Handler
int isMetaCommand(inputBuffer *new_input_buffer) {
  if (strncmp(".", new_input_buffer->input, 1) == 0) {
    return 1;
  } else {
    return 0;
  }
}
// Exit command handler
int isExit(inputBuffer *new_input_buffer) {
  if (strcmp(".exit", new_input_buffer->input) == 0) {
    free(new_input_buffer->input); // freeing the make input_text
    free(new_input_buffer);        // freeing the input field
    return 1;
  } else {
    return 0;
  }
}
