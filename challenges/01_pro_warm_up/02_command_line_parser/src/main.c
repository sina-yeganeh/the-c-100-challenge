// Minicat - A mini version of `cat` tool
// It's just for practising not developing
// a better version of cat :/

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10000
// Is this format standard for writing help messages?
#define HELP_MESSAGE \
"Minicat - a mini version of \"cat\".\n" \
"USAGE:\n" \
"  --help: print this message.\n" \
"  -i, --input=<file_name>: Select the file for concatenate.\n" \
"  -t, --top: print first 10 line.\n" \
"  -l, --line: add number line.\n"

void print_help() {
  printf(HELP_MESSAGE);
}

// Instead of this shit, you can use `isprint`
// in the `ctype` libaray.
bool is_printable(char c) {
  if (c < 26 || c > 126) {
    return false;
  }

  return true;
}

bool read_file(char path[], bool is_top, bool lined) {
  FILE *fp = fopen(path, "r");
  if (!fp) {
    printf("Could not open file.");
    return false;
  }

  size_t counter = 0;
  size_t bytes;
  unsigned char buffer[16];
  // Exactly like the past challenge
  while ((bytes = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
    if (is_top) {
      counter++;
      if (counter > 10) {
        break;
      }
    }
    for (size_t line = 0; line < bytes; line++) {
      if (lined) {
        printf("%02zu %c", line + 1, buffer[line]);
      } else {
        printf("%c", buffer[line]);
      }
    }
  }

  fclose(fp);
  return true;
}

int main(int argc, char *argv[]) {
  char file_name[MAX];
  bool is_top = false;
  bool lined = false;

  int opt;
  int option_index = 0;

  // It is obvious what are the arguments are, right?
  struct option long_options[] = {
    {"help", no_argument, 0, 'h'},
    {"input", required_argument, 0, 'i'},
    {"top", no_argument, 0, 't'},
    {"line", no_argument, 0, 'l'},
  };

  while ((opt = getopt_long(argc, argv, "i:ht", long_options, &option_index)) != -1) {
     switch(opt) {
      case 'h':
        print_help();
        return 0;
        break;
      case 'i':
        strcpy(file_name, optarg);
        break;
      case 't':
        is_top = true;
        break;
      case 'l':
        lined = true;
        break;
     }
  }

  read_file(file_name, is_top, lined); 
  
  return 0;
}