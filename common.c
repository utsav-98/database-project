#include "common.h"

inputBuffer *init_inputBuffer() {
  inputBuffer *inputField = malloc(sizeof(inputBuffer));
  if (!inputField) {
    setError("Memory Allocation failed");
  }
  inputField->input = NULL;
  inputField->input_length = 0;
  return inputField;
}

void AllocateInputBuffer(inputBuffer *new_input_field, size_t Currentlength) {
  new_input_field->buffer_length = Currentlength;
  new_input_field->input = malloc(new_input_field->buffer_length);
  if (!new_input_field->input) {
    setError("Memory allcation For Input Bufer  failed");
  }
}

void setError(char *errorText) {
  printf("%s", errorText);
  exit(EXIT_FAILURE);
}
