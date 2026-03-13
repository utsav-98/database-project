#include "frontend.h"
#include <string.h>

// Function to read Input from User

void read_input(inputBuffer *new_input_buffer) {
  if (new_input_buffer->input == NULL) { // if the input text is empty
    AllocateInputBuffer(new_input_buffer, 100); //create new space for input field to store
  }

  //Read entire line from keyboard and return the count
  size_t bytes_count = getline(&new_input_buffer->input,
                               &(new_input_buffer->buffer_length), stdin);
  if (bytes_count <= 0) {
    setError("Error while reading Input \n");
  } else {
    //It Remove \n from the end of input like insert\n 
    new_input_buffer->input_length = bytes_count - 1;
    new_input_buffer->input[bytes_count - 1] = 0; 
  }
}

PrepareResult prepare_statement(inputBuffer *input_field, Statement *statement) {

  //compare insert word from 0 to 6 index 
  if (strncmp(input_field->input, "insert", 6) == 0) {
    //it Check at the last of word 'insert' if there is nothing then it will run
    if (input_field->input[6] == ' ' || '\0') {
      statement->type = STATEMENT_INSERT;
      return PREPARE_SUCCESS;
    }
  }
  
  if (strcmp(input_field->input, "select") == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}
