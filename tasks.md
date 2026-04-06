/*
 * ==============================================================================
 * VISUAL MEMORY LAYOUT DIAGRAM (Linux 32-bit Process)
 * ==============================================================================
 *
 * HIGH ADDRESSES (0xFFFFFFFF)
 * -------------------------------------------------------------------------
 * |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 * |||                  OS KERNEL SPACE (RESERVED)                     |||
 * |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
 * -------------------------------------------------------------------------
 *
 * =========================================================================
 * |||                       THE STACK (MHSNIT)                          |||
 * |||                                                                   |||
 * |||  - Grows DOWNWARDS towards lower addresses                        |||
 * |||  - Stores function arguments, return addresses, local variables.  |||
 * |||                                                                   |||
 * |||   [ main() frame ]                                                |||
 * |||     -> argc, argv, &argv                                          |||
 * |||                                                                   |||
 * |||   [ secondary() frame ]                                           |||
 * |||     -> addr2, addr3 (locals)                                      |||
 * |||     -> iarray[3], darray[3], etc. (local arrays)                  |||
 * |||     -> yos, addr4 (local pointers to other regions)               |||
 * |||                                                                   |||
 * |||   [ point_at() frame ] <--- CURRENT ACTIVE FRAME                  |||
 * |||     -> void *p (argument/parameter)                               |||
 * |||     -> long local (local variable)                                |||
 * |||     -> long dist1, dist2, dist3 (local calculation results)       |||
 * |||                                                                   |||
 * =========================================================================
 * |||                                                     |||
 * |||  [\]  Stack grows DOWN   <---[ dist2 ]--->   [\]    |||
 * V                                                       V
 *
 * . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 * .            UNALLOCATED / FREE MEMORY GAP              .
 * .      (Huge distance between Stack and other segments)     .
 * .            [ This gap is reflected in dist1 & dist3 ]     .
 * . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 *
 * ^                                                       ^
 * |||  [/]   Heap grows UP                                [/]  |||
 * |||                                                     |||
 * =========================================================================
 * |||                        THE HEAP (HIP)                             |||
 * |||                                                                   |||
 * |||  - Grows UPWARDS towards higher addresses                         |||
 * |||  - Stores dynamically allocated memory (via malloc/calloc)        |||
 * |||                                                                   |||
 * |||     -> Memory pointed to by secondary's addr4: malloc(50)         |||
 * |||                                                                   |||
 * =========================================================================
 *
 * -------------------------------------------------------------------------
 * |||                BSS SEGMENT (Uninitialized Global Data)            |||
 * |||  - Initialized to zero by OS.                                     |||
 * |||     -> addr5, addr6 (int addr5; int addr6;)                       |||
 * -------------------------------------------------------------------------
 *
 * -------------------------------------------------------------------------
 * |||                 DATA SEGMENT (Initialized Global Data)           |||
 * |||  - Stores global/static variables with specific values.          |||
 * |||     -> char g = 'g';                                              |||
 * -------------------------------------------------------------------------
 *
 * -------------------------------------------------------------------------
 * |||                 TEXT / CODE SEGMENT (Read-Only)                  |||
 * |||  - Stores machine instructions of functions.                      |||
 * |||     -> main(), secondary(), point_at(), foo()                    |||
 * |||     -> Also stores string literals (e.g., "ree")                 |||
 * -------------------------------------------------------------------------
 *
 * LOW ADDRESSES (0x00000000)
 * ==============================================================================
 */