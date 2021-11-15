#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
char ** parse_args( char * line );
int main() {
  char * command = "ls -l";
  char hold[strlen(command)];
  strcpy(hold, command);
  char ** args = parse_args( hold); // bug fix, strsep coulnt edit a string litteral
  execvp(args[0], args);
 }

char ** parse_args( char * line ){
  // printf("%s\n", line);

  char ** arg_array = calloc(5, sizeof(char **));
  // printf("%s\n", line);

  int index = 0;
  char ** holdline = &line;
  // printf("%s\n", line);

  char * temp;
  temp = strsep( &line, " ");
  // printf("hi%s\n", line);

  while (temp){
    // printf("test\n");
    if (errno != 0) {
      printf("Error: %s\n", strerror(errno));
      exit(-1);
    }
    arg_array[index] = temp;
    temp = strsep( holdline, " ");
    index ++;
  }
  return arg_array;
}
