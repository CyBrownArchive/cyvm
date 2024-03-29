char* opcode_2_str(int opcode)
{
    switch(opcode)
    {
        case OP_NOP: return "OP_NOP"; break;
        case OP_WIDE: return "OP_WIDE"; break;
        case OP_POP: return "OP_POP"; break;
        case OP_POP2: return "OP_POP2"; break;
        case OP_SWAP: return "OP_SWAP"; break;
        case OP_SWAP2: return "OP_SWAP2"; break;
        case OP_DUP: return "OP_DUP"; break;
        case OP_DUP2: return "OP_DUP2"; break;
        case OP_JP: return "OP_JP"; break;
        case OP_JPZ: return "OP_JPZ"; break;
        case OP_JPNZ: return "OP_JPNZ"; break;
        case OP_JPNEG: return "OP_JPNEG"; break;
        case OP_JPPOS: return "OP_JPPOS"; break;
        case OP_JPZNEG: return "OP_JPZNEG"; break;
        case OP_JPZPOS: return "OP_JPZPOS"; break;
        case OP_PREPCALL: return "OP_PREPCALL"; break;
        case OP_CALL: return "OP_CALL"; break;
        case OP_PUSHFP: return "OP_PUSHFP"; break;
        case OP_RET: return "OP_RET"; break;
        case OP_RET_1: return "OP_RET_1"; break;
        case OP_RET_2: return "OP_RET_2"; break;
        case OP_CALLBUILTIN: return "OP_CALLBUILTIN"; break;
        case OP_IADD: return "OP_IADD"; break;
        case OP_ISUB: return "OP_ISUB"; break;
        case OP_IMUL: return "OP_IMUL"; break;
        case OP_IDIV: return "OP_IDIV"; break;
        case OP_IMOD: return "OP_IMOD"; break;
        case OP_IAND: return "OP_IAND"; break;
        case OP_IOR: return "OP_IOR"; break;
        case OP_IXOR: return "OP_IXOR"; break;
        case OP_ISHL: return "OP_ISHL"; break;
        case OP_ISHR: return "OP_ISHR"; break;
        case OP_INEG: return "OP_INEG"; break;
        case OP_INOT: return "OP_INOT"; break;
        case OP_IPUSH: return "OP_IPUSH"; break;
        case OP_IPUSH0: return "OP_IPUSH0"; break;
        case OP_I2BOOL: return "OP_I2BOOL"; break;
        case OP_LADD: return "OP_LADD"; break;
        case OP_LSUB: return "OP_LSUB"; break;
        case OP_LMUL: return "OP_LMUL"; break;
        case OP_LDIV: return "OP_LDIV"; break;
        case OP_LMOD: return "OP_LMOD"; break;
        case OP_LAND: return "OP_LAND"; break;
        case OP_LOR: return "OP_LOR"; break;
        case OP_LXOR: return "OP_LXOR"; break;
        case OP_LSHL: return "OP_LSHL"; break;
        case OP_LSHR: return "OP_LSHR"; break;
        case OP_LLAND: return "OP_LLAND"; break;
        case OP_LLOR: return "OP_LLOR"; break;
        case OP_LNEG: return "OP_LNEG"; break;
        case OP_LNOT: return "OP_LNOT"; break;
        case OP_LPUSH: return "OP_LPUSH"; break;
        case OP_LPUSH0: return "OP_LPUSH0"; break;
        case OP_FADD: return "OP_FADD"; break;
        case OP_FSUB: return "OP_FSUB"; break;
        case OP_FMUL: return "OP_FMUL"; break;
        case OP_FDIV: return "OP_FDIV"; break;
        case OP_FNEG: return "OP_FNEG"; break;
        case OP_FPUSH: return "OP_FPUSH"; break;
        case OP_FPUSH0: return "OP_FPUSH0"; break;
        case OP_DADD: return "OP_DADD"; break;
        case OP_DSUB: return "OP_DSUB"; break;
        case OP_DMUL: return "OP_DMUL"; break;
        case OP_DDIV: return "OP_DDIV"; break;
        case OP_DNEG: return "OP_DNEG"; break;
        case OP_DPUSH: return "OP_DPUSH"; break;
        case OP_DPUSH0: return "OP_DPUSH0"; break;
        case OP_ISTORE: return "OP_ISTORE"; break;
        case OP_LSTORE: return "OP_LSTORE"; break;
        case OP_ISTOREFP: return "OP_ISTOREFP"; break;
        case OP_LSTOREFP: return "OP_LSTOREFP"; break;
        case OP_ILOAD: return "OP_ILOAD"; break;
        case OP_LLOAD: return "OP_LLOAD"; break;
        case OP_ILOADFP: return "OP_ILOADFP"; break;
        case OP_LLOADFP: return "OP_LLOADFP"; break;
        case OP_GETF: return "OP_GETF"; break;
        case OP_PUTF: return "OP_PUTF"; break;
        case OP_GETSF: return "OP_GETSF"; break;
        case OP_PUTSF: return "OP_PUTSF"; break;
        case OP_IS: return "OP_IS"; break;
        case OP_OPUSH: return "OP_OPUSH"; break;
        case OP_OPUSH0: return "OP_OPUSH0"; break;
        case OP_I2L: return "OP_I2L"; break;
        case OP_I2F: return "OP_I2F"; break;
        case OP_I2D: return "OP_I2D"; break;
        case OP_L2I: return "OP_L2I"; break;
        case OP_L2F: return "OP_L2F"; break;
        case OP_L2D: return "OP_L2D"; break;
        case OP_F2I: return "OP_F2I"; break;
        case OP_F2L: return "OP_F2L"; break;
        case OP_F2D: return "OP_F2D"; break;
        case OP_D2I: return "OP_D2I"; break;
        case OP_D2L: return "OP_D2L"; break;
        case OP_D2F: return "OP_D2F"; break;
        case OP_I2B: return "OP_I2B"; break;
        case OP_I2S: return "OP_I2S"; break;
        case OP_BIPUSH: return "OP_BIPUSH"; break;
        case OP_SIPUSH: return "OP_SIPUSH"; break;
        case OP_IISNEG: return "OP_IISNEG"; break;
        case OP_IISPOS: return "OP_IISPOS"; break;
        case OP_IISZNEG: return "OP_IISZNEG"; break;
        case OP_IISZPOS: return "OP_IISZPOS"; break;
        case OP_LISNEG: return "OP_LISNEG"; break;
        case OP_LISPOS: return "OP_LISPOS"; break;
        case OP_LISZNEG: return "OP_LISZNEG"; break;
        case OP_LISZPOS: return "OP_LISZPOS"; break;
        case OP_FISNEG: return "OP_FISNEG"; break;
        case OP_FISPOS: return "OP_FISPOS"; break;
        case OP_FISZNEG: return "OP_FISZNEG"; break;
        case OP_FISZPOS: return "OP_FISZPOS"; break;
        case OP_DISNEG: return "OP_DISNEG"; break;
        case OP_DISPOS: return "OP_DISPOS"; break;
        case OP_DISZNEG: return "OP_DISZNEG"; break;
        case OP_DISZPOS: return "OP_DISZPOS"; break;
        default: return "UNKNOWN"; break;
    }
}
