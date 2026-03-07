#include "common.h"
#include <stdio.h>
#include <stdlib.h>

// Input Field initialization

void setError(char *errorText) {
  printf("%s", errorText);
  exit(EXIT_FAILURE);
}

inputBuffer *init_inputBuffer() {
  inputBuffer *inputField = malloc(sizeof(inputBuffer));
  if (!inputField) {
    setError("Memory Allocation failed");
  }
  inputField->input = NULL;
  inputField->input_length = 0;
  return inputField;
}

void AllocateInputBuffer(inputBuffer *new_input_field, size_t n) {
  new_input_field->buffer_length = n;
  new_input_field->input = malloc(new_input_field->buffer_length);
  if (!new_input_field->input) {
    setError("Memory allcation For Input Bufer  failed");
  }
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
// Function to check if the Command is Exit command or not

int isMetaCommand(inputBuffer *new_input_buffer) {
  if (strncmp(".", new_input_buffer->input, 1) == 0) {
    return 1;
  } else {
    return 0;
  }
}
int isExit(inputBuffer *new_input_buffer) {
  if (strcmp(".exit", new_input_buffer->input) == 0) {
    free(new_input_buffer->input); // freeing the make input_text
    free(new_input_buffer);        // freeing the input field
    return 1;
  } else {
    return 0;
  }
}

int main() {
  inputBuffer *new_input_buffer = init_inputBuffer();
  while (true) {
    printf("db> ");
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
