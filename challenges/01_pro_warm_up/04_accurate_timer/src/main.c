// Easy one btw :/

#define _POSIX_C_SOURCE 199309L // Read about this line plz

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // timespec
  //  time_t tv_sec; -> seconds
  //  long   tv_nsec; -> nanoseconds (0 to 999999999)
  struct timespec start_mono, end_mono, start_cpu, end_cpu;
  // int clock_gettime(clockid_t __clock_id, struct timespec *__tp)
  // return 1 if successful
  // clock_id:
  //  CLOCK_REALTIME: system's real world wall clock
  //  CLOCK_MONOTONIC: increasment timer -> not effected by system clock changes
  //                   so good for time misurements
  //  CLOCK_PROCESS_CPUTIME_ID, CLOCK_THREAD_CPUTIME_ID: read about them by yourself
  if (
    clock_gettime(CLOCK_MONOTONIC, &start_mono) != 0 ||
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_cpu) != 0
  ) {
    perror("Could not query the time.");
    return 1;
  }

  for (unsigned long long int i = 0; i < 10000000000; i++);

  if (
    clock_gettime(CLOCK_MONOTONIC, &end_mono) != 0 ||
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_cpu)
  ) {
    perror("Could not query the time.");
    return 1;
  }

  double elapsed_mono = (end_mono.tv_sec - start_mono.tv_sec) +
    (end_mono.tv_nsec - start_mono.tv_nsec) / 1e9; // Because we get an int between 0 to 999999999 (ns)
  double elapsed_cpu = (end_cpu.tv_sec - start_cpu.tv_sec) +
    (end_cpu.tv_nsec - start_cpu.tv_nsec) / 1e9;

  printf("Monotonic time elapsed: %.9f\n", elapsed_mono);
  printf("CPU time elapsed: %.9f\n", elapsed_cpu);

  printf("Different between Monotonic and CPU measurement: %.9f\n", fabs(elapsed_mono - elapsed_cpu));

  return 0;
}