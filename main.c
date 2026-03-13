#include "backend/backend.h"
#include "common.h"
#include "frontend/frontend.h"


int main() {
  inputBuffer *new_input_buffer = init_inputBuffer();
  
  while (true) {
    printf("db >");
    read_input(new_input_buffer); //Read Input from User

    Statement statement; //Create new Statement struct;
    
    if (isMetaCommand(new_input_buffer)) {
      if (isExit(new_input_buffer)) {
        exit(EXIT_SUCCESS);
      } else {
        printf("unrecognized meta command '%s'.\n", new_input_buffer->input);
      }
    } else {
      //If Input has insert/Select keyword then pass
      //or print "unrecognized keyword"
      switch(prepare_statement(new_input_buffer, &statement )){
        case (PREPARE_SUCCESS): break;
        case (PREPARE_UNRECOGNIZED_STATEMENT): printf("Unrecongnized keyword at start of %s .\n", new_input_buffer->input);
        continue;
      }
    }

    RunStatement(&statement);
  }

  return 0;
}
