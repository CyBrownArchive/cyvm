// MISC
#define OP_NOP 0x00
#define OP_WIDE 0x01


// STACK
#define OP_POP 0x10
#define OP_POP2 0x11
#define OP_SWAP 0x12
#define OP_SWAP2 0x13
#define OP_DUP 0x14
#define OP_DUP2 0x15


// JUMPS
#define OP_JP 0x40
#define OP_JPZ 0x41
#define OP_JPNZ 0x42
#define OP_JPNEG 0x43
#define OP_JPPOS 0x44
#define OP_JPZNEG 0x45
#define OP_JPZPOS 0x46


// CALLS
#define OP_PREPCALL 0x47
#define OP_CALL 0x48
#define OP_PUSHFP 0x49
#define OP_RET 0x4A
#define OP_RET_1 0x4B
#define OP_RET_2 0x4C
#define OP_CALLBUILTIN 0x4D


// OP INT
#define OP_IADD 0x80
#define OP_ISUB 0x81
#define OP_IMUL 0x82
#define OP_IDIV 0x83
#define OP_IMOD 0x84
// OP INT LOG/BIN
#define OP_IAND 0x88
#define OP_IOR 0x89
#define OP_IXOR 0x8A
#define OP_ISHL 0x8B
#define OP_ISHR 0x8C
// OP INT UNARY
#define OP_INEG 0x85
#define OP_INOT 0x8D
// OP INT STACK
#define OP_IPUSH 0x86
#define OP_IPUSH0 0x87
#define OP_I2BOOL 0x8E


// OP LONG
#define OP_LADD 0x90
#define OP_LSUB 0x91
#define OP_LMUL 0x92
#define OP_LDIV 0x93
#define OP_LMOD 0x94
// OP LONG LOG/BIN
#define OP_LAND 0x98
#define OP_LOR 0x99
#define OP_LXOR 0x9A
#define OP_LSHL 0x9B
#define OP_LSHR 0x9C
#define OP_LLAND 0x9E
#define OP_LLOR 0x9F
// OP LONG UNARY
#define OP_LNEG 0x95
#define OP_LNOT 0x9D
// OP LONG STACK
#define OP_LPUSH 0x96
#define OP_LPUSH0 0x97


// OP FLOAT
#define OP_FADD 0xA0
#define OP_FSUB 0xA1
#define OP_FMUL 0xA2
#define OP_FDIV 0xA3
// OP FLOAT UNARY
#define OP_FNEG 0xA5
// OP FLOAT STACK
#define OP_FPUSH 0xA6
#define OP_FPUSH0 0xA7


// OP DOUBLE
#define OP_DADD 0xB0
#define OP_DSUB 0xB1
#define OP_DMUL 0xB2
#define OP_DDIV 0xB3
// OP DOUBLE UNARY
#define OP_DNEG 0xB5
// OP DOUBLE STACK
#define OP_DPUSH 0xB6
#define OP_DPUSH0 0xB7


// VARS
#define OP_ISTORE 0xA8
#define OP_LSTORE 0xA9
#define OP_ISTOREFP 0xAA
#define OP_LSTOREFP 0xAB

// VARS
#define OP_ILOAD 0xB8
#define OP_LLOAD 0xB9
#define OP_ILOADFP 0xBA
#define OP_LLOADFP 0xBB


// OBJECTS
#define OP_GETF 0xC0
#define OP_PUTF 0xC1
#define OP_GETSF 0xC2
#define OP_PUTSF 0xC3
#define OP_IS 0xC4
#define OP_OPUSH 0xC6
#define OP_OPUSH0 0xC7


// TYPE CONVERSION
#define OP_I2L 0xD0
#define OP_I2F 0xD1
#define OP_I2D 0xD2
#define OP_L2I 0xD3
#define OP_L2F 0xD4
#define OP_L2D 0xD5
#define OP_F2I 0xD6
#define OP_F2L 0xD7
#define OP_F2D 0xD8
#define OP_D2I 0xD9
#define OP_D2L 0xDA
#define OP_D2F 0xDB
#define OP_I2B 0xDC
#define OP_I2S 0xDD
#define OP_BIPUSH 0xDE
#define OP_SIPUSH 0xDF


// CONV TO OP_I2BOOL
#define OP_IISNEG 0xF0
#define OP_IISPOS 0xF1
#define OP_IISZNEG 0xF2
#define OP_IISZPOS 0xF3
#define OP_LISNEG 0xF4
#define OP_LISPOS 0xF5
#define OP_LISZNEG 0xF6
#define OP_LISZPOS 0xF7
#define OP_FISNEG 0xF8
#define OP_FISPOS 0xF9
#define OP_FISZNEG 0xFA
#define OP_FISZPOS 0xFB
#define OP_DISNEG 0xFC
#define OP_DISPOS 0xFD
#define OP_DISZNEG 0xFE
#define OP_DISZPOS 0xFF
