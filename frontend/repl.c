#include "frontend.h"

void printPrompt() {
  //
  printf("db> ");
}

// Function to read Input from User

void read_input(inputBuffer *new_input_buffer) {
  if (new_input_buffer->input == NULL) { // if the input text is empty
    AllocateInputBuffer(new_input_buffer, 100);
  }

  size_t bytes_count = getline(&new_input_buffer->input,
                               &(new_input_buffer->buffer_length), stdin);
  if (bytes_count <= 0) {
    setError("Error while reading Input \n");
  } else {
    new_input_buffer->input_length = bytes_count - 1;
    new_input_buffer->input[bytes_count - 1] = 0;
  }
}
