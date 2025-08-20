// Very lightweight :)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_SIZE 100
#define BUFFER_SIZE 1000

int main(int argc, char *argv[]) {
  char config[CONFIG_SIZE][BUFFER_SIZE];

  // The usage will be like this: ./a.out test.ini
  char *init_file = argv[1];

  char buffer[BUFFER_SIZE];
  FILE *fp = fopen(init_file, "r");

  size_t config_index = 0;
  // This method read the line and copy it to the buffer
  while (fgets(buffer, sizeof(buffer), fp)) {
    if (buffer[0] == ';' || buffer[0] == '#') // Prevent to read comments
      continue;

    // Check if it is a "section"
    if (buffer[0] == '[') {
      size_t index = 1;
      while (buffer[index] != ']') {
        config[config_index][index - 1] = buffer[index];
        index++;
      }

      config[config_index][index - 1] = ':';
      config[config_index][index] = '\0';
    } else {
      strcpy(config[config_index], buffer);
    }

    config_index++;
  }

  for (int i = 0; i < config_index; i++) {
    printf("%s", config[i]);
  }

  fclose(fp);
  return 0;
}