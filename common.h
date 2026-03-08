#ifndef COMMON_H
#define COMMON_H

/* DEFINES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// input Field Struct
typedef struct {
  char *input;
  size_t buffer_length;
  ssize_t input_length;
} inputBuffer;

void AllocateInputBuffer(inputBuffer *new_input_field,
                         size_t n); /* Allocates Input Buffer*/

void setError(char *errorText); /* Prints Error and Exit*/

inputBuffer *init_inputBuffer();

#endif // !COMMON_H
