#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opcodes.h"
#include "opcode_2_str.h"

int mode_verbose;

#define BYTE_STACK(NUM)   (*((char*)sp+(NUM)))
#define SHORT_STACK(NUM)  (*((short*)sp+(NUM)))
#define INT_STACK(NUM)    (*((int*)sp+(NUM)))
#define LONG_STACK(NUM)   (*((long*)sp+(NUM)))
#define FLOAT_STACK(NUM)  (*((float*)sp+(NUM)))
#define DOUBLE_STACK(NUM) (*((double*)sp+(NUM)))

#define BYTE_BYTECODE(NUM)    (*(char*)(bytecode + pc + (NUM)))
#define BYTE_UBYTECODE(NUM)   (*(unsigned char*)(bytecode + pc + (NUM)))
#define SHORT_BYTECODE(NUM)   (*(short*)(bytecode + pc + (NUM)))
#define INT_BYTECODE(NUM)     (*(int*)(bytecode + pc + (NUM)))
#define LONG_BYTECODE(NUM)    (*(long*)(bytecode + pc + (NUM)))
#define FLOAT_BYTECODE(NUM)   (*(float*)(bytecode + pc + (NUM)))
#define DOUBLE_BYTECODE(NUM)  (*(double*)(bytecode + pc + (NUM)))

// memory
char* stack;
char* memory;

// registers
int ia;     // 32 bit Accumulator
long la;    // 64 bit Accumulator
float fa;
double da;
int fp;     // Frame pointer, offset since stack
char* sp;     // Stack pointer
int pc;     // PC, offset since bytecode

int bytecode_load(const char* path, char** out)
{
    int a = 0;
    FILE* fin = fopen(path, "rb");
    if (fin == NULL)
    {
        return 0;
    }
    char* bytecode = malloc(10240);
    *out = bytecode;
    while (1)
    {
        bytecode[a] = fgetc(fin);
        if (feof(fin))
        {
            break;
        }
        a++;
    }
    return a;
}

#define BUILTIN_PRINT_INT  1
#define BUILTIN_PRINT_CHAR 2

int call_builtin(int num)
{
    switch (num)
    {
        case BUILTIN_PRINT_INT:
            printf("%d", INT_STACK(-1));
            break;
        case BUILTIN_PRINT_CHAR:
            printf("%c", INT_STACK(-1));
            break;
    }
}

int tmp_fp[10];
int *cur_tmp_fp = tmp_fp;

void push_tmp_fp(int t)
{
    // TODO Exception
    *cur_tmp_fp = t;
    cur_tmp_fp++;
}

int pop_tmp_fp()
{
    // TODO exception if < 0
    cur_tmp_fp--;
    return *cur_tmp_fp;
}

int bytecode_run(char* bytecode, int max_size)
{
    stack = malloc(2048);
    memory = malloc(1024);
    ia = 0;
    la = 0;
    sp = stack;
    fp = 0;
    pc = 0;

    while (pc < max_size)
    {
        if (mode_verbose)
        {
            printf("[%04X: %02X %14s %2d]\n", pc, BYTE_UBYTECODE(0), opcode_2_str(BYTE_UBYTECODE(0)), INT_STACK(-1));
        }
        switch (BYTE_UBYTECODE(0))
        {
            // MISC
            case OP_NOP:

                break;
            case OP_WIDE:

                break;
            // STACK
            case OP_POP:
                sp -= 4;
                break;
            case OP_POP2:
                sp -= 8;
                break;
            case OP_SWAP:
                ia = INT_STACK(-1);
                INT_STACK(-1) = INT_STACK(-2);
                INT_STACK(-2) = ia;
                break;
            case OP_SWAP2:
                la = LONG_STACK(-1);
                LONG_STACK(-1) = LONG_STACK(-2);
                LONG_STACK(-2) = la;
                break;
            case OP_DUP:
                INT_STACK(0) = INT_STACK(-1);
                sp += 4;
                break;
            case OP_DUP2:
                LONG_STACK(0) = LONG_STACK(-1);
                sp += 8;
                break;

            // JUMPS
            case OP_JP:
                pc = INT_BYTECODE(1);
                continue;
            case OP_JPZ:
                sp -= 4;
                if (!INT_STACK(0))
                {
                    pc = INT_BYTECODE(1);
                    continue;
                }
                else
                {
                    pc += 4;
                }
                break;
            case OP_JPNZ:
                sp -= 4;
                if (INT_STACK(0))
                {
                    pc = INT_BYTECODE(1);
                    continue;
                }
                else
                {
                    pc += 4;
                }
                break;
            case OP_JPNEG:
                sp -= 4;
                if (INT_STACK(0) < 0)
                {
                    pc = INT_BYTECODE(1);
                    continue;
                }
                else
                {
                    pc += 4;
                }
                break;
            case OP_JPPOS:
                sp -= 4;
                if (INT_STACK(0) > 0)
                {
                    pc = INT_BYTECODE(1);
                    continue;
                }
                else
                {
                    pc += 4;
                }
                break;
            case OP_JPZNEG:
                sp -= 4;
                if (INT_STACK(0) <= 0)
                {
                    pc = INT_BYTECODE(1);
                    continue;
                }
                else
                {
                    pc += 4;
                }
                break;
            case OP_JPZPOS:
                sp -= 4;
                if (INT_STACK(0) >= 0)
                {
                    pc = INT_BYTECODE(1);
                    continue;
                }
                else
                {
                    pc += 4;
                }
                break;


            // CALLS
            case OP_PREPCALL:
                INT_STACK(0) = fp;
                push_tmp_fp(sp-stack);
                sp += 4;
                break;
            case OP_CALL:
                //INT_STACK(0) = pc;
                INT_STACK(0) = pc+4;
                sp += 4;
                pc = INT_BYTECODE(1);
                fp = pop_tmp_fp();
                continue;
                break;
            case OP_PUSHFP:
                INT_STACK(0) = fp;
                sp += 4;
                break;
            case OP_RET:
                pc = INT_STACK(-1);
                sp = stack + fp;
                fp = *(int*)(stack+fp+0);
                break;
            case OP_RET_1:
                ia = INT_STACK(-1);
                pc = INT_STACK(-2);
                sp = stack+fp;
                fp = *(int*)(stack+fp);
                INT_STACK(0) = ia;
                sp += 4;
                break;
            case OP_RET_2:
                la = LONG_STACK(-1);
                pc = INT_STACK(-3);
                sp = stack+fp;
                fp = *(int*)(stack+fp);
                LONG_STACK(0) = ia;
                sp += 8;
                break;
            case OP_CALLBUILTIN:
                call_builtin(BYTE_BYTECODE(1));
                pc += 1;
                break;


            // OP INT
            case OP_IADD:
                sp -= 4;
                INT_STACK(-1) += INT_STACK(0);
                break;
            case OP_ISUB:
                sp -= 4;
                INT_STACK(-1) -= INT_STACK(0);
                break;
            case OP_IMUL:
                sp -= 4;
                INT_STACK(-1) *= INT_STACK(0);
                break;
            case OP_IDIV:
                sp -= 4;
                INT_STACK(-1) /= INT_STACK(0);
                break;
            case OP_IMOD:
                sp -= 4;
                INT_STACK(-1) %= INT_STACK(0);
                break;
            // OP INT BITWISE
            case OP_IAND:
                sp -= 4;
                INT_STACK(-1) &= INT_STACK(0);
                break;
            case OP_IOR:
                sp -= 4;
                INT_STACK(-1) |= INT_STACK(0);
                break;
            case OP_IXOR:
                sp -= 4;
                INT_STACK(-1) ^= INT_STACK(0);
                break;
            case OP_ISHL:
                sp -= 4;
                INT_STACK(-1) = INT_STACK(-1) << INT_STACK(0);
                break;
            case OP_ISHR:
                sp -= 4;
                INT_STACK(-1) = INT_STACK(-1) >> INT_STACK(0);
                break;
            // OP INT UNARY
            case OP_INEG:
                INT_STACK(-1) = -INT_STACK(-1);
                break;
            case OP_INOT:
                INT_STACK(-1) = ~INT_STACK(-1);
                break;
            // OP INT STACK
            case OP_IPUSH:
                INT_STACK(0) = INT_BYTECODE(1);
                pc += 4;
                sp += 4;
                break;
            case OP_IPUSH0:
                INT_STACK(0) = 0;
                sp += 4;
                break;
            case OP_I2BOOL:
                INT_STACK(-1) = INT_STACK(-1) != 0 ? 1 : 0;
                break;


            // OP LONG
            case OP_LADD:
                sp -= 8;
                LONG_STACK(-1) += LONG_STACK(0);
                break;
            case OP_LSUB:
                sp -= 8;
                LONG_STACK(-1) -= LONG_STACK(0);
                break;
            case OP_LMUL:
                sp -= 8;
                LONG_STACK(-1) *= LONG_STACK(0);
                break;
            case OP_LDIV:
                sp -= 8;
                LONG_STACK(-1) %= LONG_STACK(0);
                break;
            case OP_LMOD:
                sp -= 8;
                LONG_STACK(-1) %= LONG_STACK(0);
                break;
            // OP LONG LOG/BIN
            case OP_LAND:
                sp -= 8;
                LONG_STACK(-1) %= LONG_STACK(0);
                break;
            case OP_LOR:
                sp -= 8;
                LONG_STACK(-1) |= LONG_STACK(0);
                break;
            case OP_LXOR:
                sp -= 8;
                LONG_STACK(-1) ^= LONG_STACK(0);
                break;
            case OP_LSHL:
                sp -= 8;
                LONG_STACK(-1) <<= LONG_STACK(0);
                break;
            case OP_LSHR:
                sp -= 8;
                LONG_STACK(-1) >>= LONG_STACK(0);
                break;
            // OP LONG UNARY
            case OP_LNEG:
                LONG_STACK(-1) = -LONG_STACK(-1);
                break;
            case OP_LNOT:
                LONG_STACK(-1) = ~LONG_STACK(-1);
                break;
            // OP LONG STACK
            case OP_LPUSH:
                LONG_STACK(0) = LONG_BYTECODE(1);
                pc += 8;
                sp += 8;
                break;
            case OP_LPUSH0:
                LONG_STACK(0) = 0;
                sp += 8;
                break;


            // OP FLOAT
            case OP_FADD:
                sp -= 4;
                FLOAT_STACK(-1) += FLOAT_STACK(0);
                break;
            case OP_FSUB:
                sp -= 4;
                FLOAT_STACK(-1) -= FLOAT_STACK(0);
                break;
            case OP_FMUL:
                sp -= 4;
                FLOAT_STACK(-1) *= FLOAT_STACK(0);
                break;
            case OP_FDIV:
                sp -= 4;
                FLOAT_STACK(-1) /= FLOAT_STACK(0);
                break;
            // OP FLOAT UNARY
            case OP_FNEG:
                FLOAT_STACK(-1) = -FLOAT_STACK(-1);
                break;
            // OP FLOAT STACK
            case OP_FPUSH:
                FLOAT_STACK(0) = FLOAT_BYTECODE(1);
                pc += 4;
                sp += 4;
                break;
            case OP_FPUSH0:
                FLOAT_STACK(0) = 0.0;
                sp += 4;
                break;


            // OP DOUBLE
            case OP_DADD:
                sp -= 8;
                DOUBLE_STACK(-1) += DOUBLE_STACK(0);
                break;
            case OP_DSUB:
                sp -= 8;
                DOUBLE_STACK(-1) -= DOUBLE_STACK(0);
                break;
            case OP_DMUL:
                sp -= 8;
                DOUBLE_STACK(-1) *= DOUBLE_STACK(0);
                break;
            case OP_DDIV:
                sp -= 8;
                DOUBLE_STACK(-1) /= DOUBLE_STACK(0);
                break;
            // OP DOUBLE UNARY
            case OP_DNEG:
                DOUBLE_STACK(-1) = -DOUBLE_STACK(-1);
                break;
            // OP DOUBLE STACK
            case OP_DPUSH:
                DOUBLE_STACK(0) = DOUBLE_BYTECODE(1);
                pc += 8;
                sp += 8;
                break;
            case OP_DPUSH0:
                DOUBLE_STACK(0) = 0.0d;
                sp += 8;
                break;


            // VARS
            case OP_ISTORE:
                *(int*)(memory+(INT_BYTECODE(1))) = INT_STACK(-1);
                sp -= 4;
                pc += 4;
                break;
            case OP_LSTORE:
                *(long*)(memory+(INT_BYTECODE(1))) = LONG_STACK(-1);
                sp -= 8;
                pc += 4;
                break;
            case OP_ISTOREFP:
                *(int*)(stack+fp+(INT_BYTECODE(1))) = INT_STACK(-1);
                pc += 4;
                break;
            case OP_LSTOREFP:
                *(long*)(stack+fp+(INT_BYTECODE(1))) = LONG_STACK(-1);
                pc += 4;
                break;

            // VARS
            case OP_ILOAD:
                INT_STACK(0) = *(int*)(memory+(INT_BYTECODE(1)));
                sp += 4;
                pc += 4;
                break;
            case OP_LLOAD:
                LONG_STACK(0) = *(long*)(memory+(INT_BYTECODE(1)));
                sp += 8;
                pc += 4;
                break;
            case OP_ILOADFP:
                INT_STACK(0) = *(int*)(stack+fp+(INT_BYTECODE(1)));
                sp += 4;
                pc += 4;
                break;
            case OP_LLOADFP:
                LONG_STACK(0) = *(long*)(stack+fp+(INT_BYTECODE(1)));
                sp += 8;
                pc += 4;
                break;


            // OBJECTS
            case OP_GETF:

                break;
            case OP_PUTF:

                break;
            case OP_GETSF:

                break;
            case OP_PUTSF:

                break;
            case OP_IS:

                break;
            case OP_OPUSH:

                break;
            case OP_OPUSH0:

                break;


            // TYPE CONVERSION
            case OP_I2L:
                ia = INT_STACK(-1);
                sp -= 4;
                LONG_STACK(0) = (long)ia;
                sp += 8;
                break;
            case OP_I2F:
                ia = INT_STACK(-1);
                sp -= 4;
                FLOAT_STACK(0) = (float)ia;
                sp += 4;
                break;
            case OP_I2D:
                ia = INT_STACK(-1);
                sp -= 4;
                DOUBLE_STACK(0) = (double)ia;
                sp += 8;
                break;
            case OP_L2I:
                la = LONG_STACK(-1);
                sp -= 8;
                INT_STACK(0) = (int)la;
                sp += 4;
                break;
            case OP_L2F:
                la = LONG_STACK(-1);
                sp -= 8;
                FLOAT_STACK(0) = (float)la;
                sp += 4;
                break;
            case OP_L2D:
                la = LONG_STACK(-1);
                sp -= 8;
                DOUBLE_STACK(0) = (double)la;
                sp += 8;
                break;
            case OP_F2I:
                fa = FLOAT_STACK(-1);
                sp -= 4;
                INT_STACK(0) = (int)fa;
                sp += 4;
                break;
            case OP_F2L:
                fa = FLOAT_STACK(-1);
                sp -= 4;
                LONG_STACK(0) = (long)fa;
                sp += 8;
                break;
            case OP_F2D:
                fa = FLOAT_STACK(-1);
                sp -= 4;
                DOUBLE_STACK(0) = (double)fa;
                sp += 8;
                break;
            case OP_D2I:
                da = DOUBLE_STACK(-1);
                sp -= 8;
                INT_STACK(0) = (int)da;
                sp += 4;
                break;
            case OP_D2L:
                da = DOUBLE_STACK(-1);
                sp -= 8;
                LONG_STACK(0) = (long)da;
                sp += 8;
                break;
            case OP_D2F:
                da = DOUBLE_STACK(-1);
                sp -= 8;
                FLOAT_STACK(0) = (float)da;
                sp += 4;
                break;
            case OP_I2B:
                ia = INT_STACK(-1);
                sp -= 4;
                INT_STACK(0) = ia & 0xFFFF;
                sp += 4;
                break;
            case OP_I2S:
                ia = INT_STACK(-1);
                sp -= 4;
                LONG_STACK(0) = ia & 0xFF;
                sp += 4;
                break;
            case OP_BIPUSH:

                break;
            case OP_SIPUSH:

                break;


            // CONV TO OP_I2BOOL
            // TODO Make all types opcodes
            case OP_IISNEG:
                INT_STACK(-1) = (INT_STACK(-1) < 0) ? 1 : 0;
                break;
            case OP_IISPOS:
                INT_STACK(-1) = (INT_STACK(-1) > 0) ? 1 : 0;
                break;
            case OP_IISZNEG:
                INT_STACK(-1) = (INT_STACK(-1) <= 0) ? 1 : 0;
                break;
            case OP_IISZPOS:
                INT_STACK(-1) = (INT_STACK(-1) >= 0) ? 1 : 0;
                break;

            case OP_LISNEG:
                INT_STACK(-1) = (LONG_STACK(-1) < 0) ? 1 : 0;
                break;
            case OP_LISPOS:
                INT_STACK(-1) = (LONG_STACK(-1) > 0) ? 1 : 0;
                break;
            case OP_LISZNEG:
                INT_STACK(-1) = (LONG_STACK(-1) <= 0) ? 1 : 0;
                break;
            case OP_LISZPOS:
                INT_STACK(-1) = (LONG_STACK(-1) >= 0) ? 1 : 0;
                break;

            case OP_FISNEG:
                INT_STACK(-1) = (FLOAT_STACK(-1) < 0) ? 1 : 0;
                break;
            case OP_FISPOS:
                INT_STACK(-1) = (FLOAT_STACK(-1) > 0) ? 1 : 0;
                break;
            case OP_FISZNEG:
                INT_STACK(-1) = (FLOAT_STACK(-1) <= 0) ? 1 : 0;
                break;
            case OP_FISZPOS:
                INT_STACK(-1) = (FLOAT_STACK(-1) >= 0) ? 1 : 0;
                break;

            case OP_DISNEG:
                INT_STACK(-1) = (DOUBLE_STACK(-1) < 0) ? 1 : 0;
                break;
            case OP_DISPOS:
                INT_STACK(-1) = (DOUBLE_STACK(-1) > 0) ? 1 : 0;
                break;
            case OP_DISZNEG:
                INT_STACK(-1) = (DOUBLE_STACK(-1) <= 0) ? 1 : 0;
                break;
            case OP_DISZPOS:
                INT_STACK(-1) = (DOUBLE_STACK(-1) >= 0) ? 1 : 0;
                break;
        }
        pc++;
    }
    if (mode_verbose)
    {
        printf("Finished, top of stack: %d\n", INT_STACK(-1));
    }
}

void notice()
{
    printf("USAGE:\n");
    printf("cyvm file_to_execute\n\n");
}

int main(int argc, char* argv[])
{
    char* bytecode;
    mode_verbose = 0;
    if (argc <= 1)
    {
        notice();
    }
    else
    {
        int bytecode_size = bytecode_load(argv[1], &bytecode);
        //int bytecode_size = bytecode_load("test.bin", &bytecode);
        if (bytecode_size != 0)
        {
            bytecode_run(bytecode, bytecode_size);
        }
        else
        {
            printf("File not readable or empty.\n");
        }
    }
    return 0;
}
