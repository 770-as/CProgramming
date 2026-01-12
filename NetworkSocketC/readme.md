memcp knows how many bytes to check before it starts. It compares memory a to memory b. Modern c compilers translate memcmp into avx-512 or sse
instead of compagin 1 byte at a time, they compare 64 bytes in a single clock cycle. The cpu knows when the loop will end. 
Since strstr is slow, HFT traders use these tricks. Dont scan the whole buffer but just what you need. If you are looking for the soh, memchr is 
faster than strstr because it looks for a single character. Use a direct memory pointer access. memcmp loads a massive chunk of your fix buffer
into a register and compares it against another register in one single cpu cycle. The zero terminator forces the cpu to make a decision at every 
single byte it processes. memcmp uses vectorization and compares 32 bytes to 32 bytes in one go. It compares block per block with vectorization
and uses its ALU at 100% because it don't have to check for zero. atof() is a latency killer, it is a generic slow function that handles scientific
notation null terminators and locale settings. 
