#include <stdio.h>

// You will need stdlib for file i/o and size_t
#include <stdlib.h>

int main() {
  FILE *fp = fopen("test", "r");
  if (!fp) {
    printf("Could not open file.");
    return 1;
  }

  // Print x offsets
  printf("         ");
  for (int i = 1; i < 17; i++) {
    printf("%02d ", i); 
  }
  puts("");

  // You must ask yourself, why unsigned?
  unsigned char buffer[16];
  // One question, what is the different between
  // size_t and int variables? and where is suitable 
  // to use size_t?
  size_t bytes; 
  size_t offset = 0;
  // size_t fread(void *__restrict__ __ptr, size_t __size, size_t __n, FILE *__restrict__ __stream)
  // a buffer to write bytes to it | the size of element to read | the number of element to read | opend file 
  while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
    // Use %zu to print size_t variables
    printf("%08zu ", offset);
    for (size_t i = 0; i < bytes; i++) {
      printf("%02x ", buffer[i]);
    }

    // Feel the gap
    for (size_t i = 0; i < 16 - bytes; i++) {
      printf("%02x ", 0);
    }

    printf(" ");
    for (size_t i = 0; i < bytes; i++) {
      switch (buffer[i]) {
      // You can add more special characters.
      case '\n':
        printf("\\n");
        break;
      case '\t':
        printf("\\t");
        break;
      
      default:
        if (buffer[i] < 32 || buffer[i] > 126) {
          printf(".");
        } else {
          printf("%c", buffer[i]);
        }
      }
    }

    offset += bytes;
    puts("");
  }

  fclose(fp);
  return 0;
}