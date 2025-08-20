# :fire: The C 100 Challenge
A curated set of progressively challenging C exercises focused on security, systems programming, and embedded development. From low-level memory safety to real-time device drivers, each task is designed to build practical skills for real-world applications.

Feel free to pull-request any changes, from codes to this `README`! And if you find these challenges useful please share it with your friends and star! :star:

## Level 1 – Pro Warm-up (20 exercises)
1. [**Minimal Hex Dumper**](./challenges/01_pro_warm_up/01_minimal_hex_dumper/src/main.c): Print a file in hex, with offset addresses and ASCII alongside.  
2. [**Command-line Parser**](./challenges/01_pro_warm_up/02_command_line_parser/src/main.c): Read arguments with `getopt` (or manually), handling short/long switches.  
3. [**Safe Reader**](./challenges/01_pro_warm_up/03_safe_reader/src/main.c): Replace `gets`/`scanf("%s")` with a looped `read` that enforces buffer limits.  
4. [**Accurate Timer**](./challenges/01_pro_warm_up/04_accurate_timer/src/main.c): Measure the runtime of a function using `clock_gettime` (ns precision).  
5. **Single-file CRC32**: Compute CRC32 for an input file and check against a reference value.  
6. [**Lightweight INI Parser**](./challenges/01_pro_warm_up/06_ini_parser/src/main.c): Convert a `.ini` file into a key=value map.  
7. **Rotating Log**: A log file that rotates after reaching X KB (rename + new file).  
8. **Rate Limiter**: Sliding window to limit requests on stdin.  
9. **Safe Tempfiles**: Create temporary files with `mkstemp` and clean them up via signals.  
10. **Bitfield Practice**: 32-bit register struct with bitfields; set/clear/test bits.  
11. **Endian Swap**: Implement `bswap16/32/64` and detect system endianness.  
12. **ASCII Armor**: Base64 encode/decode binary input (streaming).  
13. **Normalize Path**: Remove `.`/`..` and multiple slashes without calling `realpath`.  
14. **Memory Zeroize**: A function that won’t be optimized away by the compiler (`volatile` / `memset_s` fallback).  
15. **Small Arena Allocator**: Linear arena with a global reset.  
16. **Bounded Str API**: Implement safe versions of `strlcpy/strlcat`.  
17. **FNV-1a Hash**: 32/64-bit hash for strings; implement a small hash table.  
18. **Mini-printf**: Implement limited `%s %d %x` without heavy dependencies.  
19. **Signal-safe Logger**: Print critical messages only using signal-safe syscalls.  
20. **Userland Watchdog**: Kill and restart a child process if it hangs.

## Level 2 – Strong Systems Foundations (20 exercises)
21. **Cat with `mmap`**: Copy large files using `mmap` (zero-copy).  
22. **Safe Dir Walker**: Traverse directories with `fdopendir` and prevent TOCTOU attacks.  
23. **Atomic File Copy**: Write to a temp file, `fsync`, then `rename` atomically.  
24. **Limited Shell**: Safely execute a few whitelisted commands using `posix_spawn`.  
25. **Resource Limits**: Sandbox a process with `setrlimit` (CPU/mem/FD limits).  
26. **Syslog Client**: Send logs to syslog with a local file fallback.  
27. **Lock File**: Process-level lock using `flock` + stale lock detection.  
28. **Epoll Echo**: Echo server with `epoll`/non-blocking I/O and fixed buffers.  
29. **Timeout Read/Write**: I/O with `poll` and connection drop handling.  
30. **Unix Domain Socket**: Local messaging with sender UID validation.  
31. **Pipe Chain**: Implement `cmd1 | cmd2 | cmd3` with `pipe`/`dup2`.  
32. **Signal Supervisor**: Handle SIGINT/SIGTERM with clean shutdown.  
33. **Config Hot-Reload**: Receive SIGHUP and reload config without downtime.  
34. **Replay-safe Journal**: Journal file with checksum for crash recovery.  
35. **RLE Compression**: Simple run-length encoding for data streams.  
36. **TTY Raw Mode**: Read keys without echo, implement a mini-REPL.  
37. **Secure Random**: Seed from `/dev/urandom` with health checks.  
38. **Timer Callback**: Implement a timer wheel for event expiry.  
39. **Atomic Config Loader**: Double-buffered config struct with simple RCU.  
40. **Benchmark Framework**: Lightweight micro-benchmarking module.

## Level 3 – Applied Security (20 exercises)
41. **Safe Unpacker**: Unzip a simple zip file with size/count/path traversal limits.  
42. **chroot Sandbox**: Run a tool inside a chroot and drop privileges.  
43. **Stack Canary Demo**: Implement and check a software canary around buffers.  
44. **Seeded Fuzzer**: Dumb fuzzer for a simple line parser, with corpus and crash saving.  
45. **TLS Fingerprint (JA3-lite)**: Extract TLS client features from pcap (header parse only).  
46. **ELF Header Reader**: Display `e_type/e_machine/entry` and section info.  
47. **Symbol Resolver**: Read ELF symbol table and search for functions.  
48. **Procfs Inspector**: Get a process’s memory map from `/proc/<pid>/maps`.  
49. **LD_PRELOAD Hook**: Educational hook counting calls to `open`.  
50. **Syscall Filter (seccomp-bpf)**: Block unneeded syscalls for a simple tool.  
51. **Address Sanitizer-lite**: Maintain guard zones for malloc/free in custom allocator.  
52. **Minimal Race Detector**: Force locking and detect simple concurrency races.  
53. **Password KDF**: PBKDF2 or scrypt wrapper around a standard library.  
54. **HMAC-SHA256 Wrapper**: API with key in locked memory (`mlock`).  
55. **Replay Protection**: Persistent nonce counter with checksum.  
56. **Simple Taint Tracking**: Flag “untrusted” data throughout a pipeline.  
57. **JWT Verifier (HS256)**: Verify signature and exp/nbf only, no risky decoding.  
58. **Zip Bomb Guard**: Limit compression ratio and abort if exceeded.  
59. **Format-String Guard**: Safe wrapper for printing unknown strings.  
60. **Secure Wipe File**: Multi-pass overwrite + `fsync` + rename + unlink.

## Level 4 – Advanced Systems Programming (20 exercises)
61. **Thread Pool**: Job queue with N workers, clean shutdown.  
62. **Lock-free Ring Buffer**: Single-producer/single-consumer with `atomic`.  
63. **Shared Memory IPC**: Message queue with `shm_open` + `pthread_cond` in shared memory.  
64. **kqueue/epoll Abstraction**: Cross-platform event layer (Linux/BSD).  
65. **Zero-Copy Sendfile**: Static web server using `sendfile` and ETag.  
66. **Syslog Server**: UDP syslog receiver writing to disk in batches.  
67. **Netlink Listener**: Monitor network events (link up/down).  
68. **Small DNS Resolver**: A/AAAA queries over UDP, with timeout/backoff.  
69. **HTTP/1.1 Parser**: State machine resilient to packet splitting/merging.  
70. **Token Bucket Rate Limiter**: General-purpose limiter for sockets.  
71. **Process Supervisor**: Restart on crash with exponential backoff and max tries.  
72. **cgroup v2 Sandbox**: Limit CPU/mem/IO for a child process.  
73. **Perf Counter Hook**: Measure cache misses with `perf_event_open`.  
74. **NUMA-aware Alloc**: Bind threads and allocate memory on a specific node.  
75. **File Integrity (FS-verity-lite)**: Merkle tree for large files.  
76. **Crash Dump Writer**: Catch signals and write a mini dump of registers.  
77. **Pluggable Modules**: Dynamically load `.so` files with a fixed interface.  
78. **Trie/IP CIDR Match**: CIDR routing/firewall with longest-prefix matching.  
79. **Bloom Filter**: Memory-efficient filter with false positive evaluation.  
80. **PCAP Writer**: Save raw packets in pcap format.

## Level 5 – Embedded/RTOS/Device (20 exercises)
81. **ISR-safe Ring Buffer**: Circular buffer for UART RX in ISR + consumption in main loop.  
82. **Button Debounce**: Anti-bounce logic for buttons using timer/state machine.  
83. **GPIO Driver**: Implement `gpio_set/clear/toggle` with memory-mapped registers.  
84. **PWM LED Control**: Soft fading with hardware timer.  
85. **I²C Master**: Read temperature from a sensor (e.g., LM75) using a state machine.  
86. **SPI Flash Reader**: Read JEDEC ID and blocks with checksum.  
87. **Minimal UART Bootloader**: Receive frames, verify length+CRC, write to flash (simulated).  
88. **RTOS Tasks**: Two tasks with a message queue; priority and starvation tests.  
89. **Fixed-point Math**: Moving average filter on ADC values with Q15.  
90. **Hardware Watchdog**: Feed WDT and test reset.  
91. **Low-power Mode**: Deep sleep and wake-up on timer interrupt.  
92. **Motor State Machine**: Four states with safe error transitions.  
93. **CRC peripheral vs software**: Compare performance on board.  
94. **Boot-time Self-test**: Test RAM/Flash/Clock and report errors via LED code.  
95. **Circular DMA**: Continuous ADC sampling with circular DMA and half/full interrupts.  
96. **Cooperative Scheduler**: Task scheduler without interrupts, round-robin.  
97. **Flash Wear Leveling**: Key=value store layer with wear leveling.  
98. **Very Simple Filesystem**: Log-structured FS on simulated flash.  
99. **Embedded Cryptobox**: AES-GCM using a lightweight library, key in locked memory, correct nonce.  
100. **Over-the-Air Update Simulation**: Receive packages, verify signature, switch boot slot.
