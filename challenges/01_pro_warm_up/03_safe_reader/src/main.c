#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// This function is only for strings
char *safer_scanf(char *str, int str_size, bool *completed) {
  // Different between size_t and ssize_t is
  // that the ssize_t is signed size_t
  ssize_t n;
  size_t index = 0;
  char buffer[1];
  // Loop condition simply handle overflow vlun
  // minus 1 is for `\0`
  while (index < str_size - 1) { 
    // ssize_t read(int __fd, void *__buf, size_t __nbytes)
    // __fd: 1, 2, -1 -> stdin, stdout, stderr
    // __buf: the buffer to copy data on int
    // __nbytes: how many byte to read
    n = read(0, buffer, 1);
    // If `read` get any error return -1
    if (n == -1) {
      puts("Error occurred when reading stdin");
      break;
    }

    // Check if user finished his input
    if (buffer[0] == '\n') {
      *completed = true;
      break;
    }

    str[index] = buffer[0];
    index++;
  }

  str[index] = '\0';
  return str;
}

int main() {
  int str_size = 10;
  char str[str_size];
  bool completed = false;

  safer_scanf(str, str_size, &completed);
  if (!completed) {
    puts("Could not read all the string from stdin.");
  }

  printf("%s\n", str);
  
  return 0;
}