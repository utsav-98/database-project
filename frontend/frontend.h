#ifndef FRONTEND_H
#define FRONTEND_H

#include "../common.h"

//Result for the Compiler 
typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

// Types of statements our VM understands
typedef enum {
  STATEMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

//ByteCode Statement for VM
typedef struct {
    StatementType type;
}Statement;

#define true 1
#define false 0

void read_input(inputBuffer *new_input_field); /* Function to Read Input*/

PrepareResult prepare_statement(inputBuffer *input_field, Statement* statement);

#endif // !FRONTEND_H
