#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#include "variable.h"
#include "helper.h"

void emptyBuffer() {

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    
}

int isIdDuplicated(int input) {

  int flag = 0, i = 0;
  while (i < size) {
    if(input == id[i]) {
      flag = 1;
      break;
    } else {
      i++;
    }
  }
  return flag;

}

int validateIdInput(int input, int scf_rtn, char end_term) {

  if (scf_rtn != 2 || end_term != '\n') {
    red();
    printf("Invalid input. (Not a number)\n");
    reset();
    emptyBuffer();
    return 0;
  } else if (input < 1) {
    red();
    printf("Invalid input. (Out of range)\n");
    reset();
    return 0;
  } else {
    return 1;
  }
  return -1;

}


int validateGradeInput(float input, int scf_rtn, char end_term) {

  if (scf_rtn != 2 || end_term != '\n') {
    red();
    printf("Not a valid grade (Number only)\n");
    reset();
    emptyBuffer();
    return 0;
  } else if (input < 0.0 || input > 10.0) {
    red();
    printf("Not a valid grade (Out of range)\n");
    reset();
    return 0;
  } else {
    return 1;
  }
  return -1;

}

int validateName(const char *input, int scf_rtn) {

  int value = 1;
  if (scf_rtn != 0) {
    regex_t regex;
    const char* pattern = "^[[:alpha:]]\\{1,\\} [[:alpha:]]\\{1,\\}$";
    value = regcomp(&regex, pattern, 0);
    value = regexec(&regex, input, 0, NULL, 0);
    regfree(&regex);
    if (value == 1) {
      red();
      printf("Invalid name, try again (Correct format is: FirstName LastName)");
      reset();
    }
  } else {
    red();
    printf("Invalid name, try again (Correct format is: FirstName LastName)");
    reset();
    emptyBuffer();
  }
  return value;
}

int isInteger(const char *input) {

  int value;
  regex_t regex;
  const char* pattern = "^[[:digit:]]*$";
  value = regcomp(&regex, pattern, 0);
  value = regexec(&regex, input, 0, NULL, 0);
  regfree(&regex);
  return value;
    
}

void red() {
  printf("\033[0;31m");
}

void green() {
  printf("\033[0;32m");
}

void cyan() {
  printf("\033[0;36m");
}

void purple() {
  printf("\033[0;35m");
}

void yellow() {
  printf("\033[0;33m");
}

void reset() {
  printf("\033[0m");
}