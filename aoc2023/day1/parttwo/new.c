#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
  char *word;
  int number;
} WordNumberPair;

int main() {
  FILE *input_file, *output_file;
  char buffer[MAX_BUFFER_SIZE];
  char *words[MAX_WORDS];
  int numbers[MAX_WORDS];
  int num_words = 0;

  // Open the input file
  input_file = fopen("demo.txt", "r");
  if (input_file == NULL) {
    printf("Error opening input file: %s\n", strerror(errno));
    return 1;
  }

  // Read the input file contents
  while (fgets(buffer, MAX_BUFFER_SIZE, input_file) != NULL) {
    char *word = strtok(buffer, " \t\n");
    while (word != NULL) {
      if (num_words < MAX_WORDS) {
        words[num_words] = strdup(word);
        numbers[num_words] = num_words + 1;
        num_words++;
      }
      word = strtok(NULL, " \t\n");
    }
  }

  // Close the input file
  fclose(input_file);

  // Open the output file
  output_file = fopen("output.txt", "w");
  if (output_file == NULL) {
    printf("Error opening output file: %s\n", strerror(errno));
    return 1;
  }

  // Replace words with corresponding numbers
  fseek(input_file, 0, SEEK_SET);
  while (fgets(buffer, MAX_BUFFER_SIZE, input_file) != NULL) {
    for (int i = 0; i < num_words; i++) {
      char *search_string = malloc(strlen(words[i]) + 2);
      sprintf(search_string, " %s ", words[i]);
      char *replace_string = malloc(strlen(words[i]) + 2);
      sprintf(replace_string, " %d ", numbers[i]);

      char *ptr = strstr(buffer, search_string);
      while (ptr != NULL) {
        memmove(ptr + strlen(replace_string), ptr + strlen(search_string), strlen(ptr + strlen(search_string)));
        memcpy(ptr, replace_string, strlen(replace_string));
        ptr = strstr(ptr + strlen(replace_string), search_string);
      }

      free(search_string);
      free(replace_string);
    }

    fputs(buffer, output_file);
  }

  // Close the output file
  fclose(output_file);

  // Free memory
  for (int i = 0; i < num_words; i++) {
    free(words[i]);
  }

  return 0;
}
