# Assignment Overview
Designed a Direct Mapped Cache of different stages:\ 
(a) Cache size: 64kilobytes, Block size: 4 bytes.\
(b) Increased the cache size to 512kB, Block size: 4 bytes. Noted the change in hit/miss rates \
(c) Keeping the cache size at 64kB, varied the block size from 1 byte, 4 bytes,8 bytes, 16 bytes, 32 bytes (the number of cache lines will reduce, if we increase the block size keeping the cache size same).\
(Assumed a 32 bit address) 
# Input Files:
5 Trace Files.
### About Trace Files
The trace file will specify all the  memory accesses/addresses that occur in a certain program. Each line in the trace file will specify a new memory reference and has the following fields:
* Access Type: A single character indicating whether the access is a load ('l') or a store ('s'). We can ignore this field
* Address: A 32-bit integer (in unsigned hexadecimal format) specifying the memory address that is being accessed. This is the only field we need.
* Instructions since last memory access: Indicates the number of instructions of any type that executed between since the last memory access (i.e. the one on the previous line in the trace). For example, if the 5th and 10th instructions in the program's execution are loads, and there are no memory operations between them, then the trace line for with the second load has "4" for this field. We can ignore this field
# Output of the code:
* Hit rates or miss rates for all the 5 traces for the 3 different experiments.
