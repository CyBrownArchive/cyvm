void print_char(int a)
{
    asm iloadfp;
    asm 4;
    asm callbuiltin;
    asm .b 2;
    asm pop;
    return;
}

void print_int(int a)
{
    asm iloadfp;
    asm 4;
    asm callbuiltin;
    asm .b 1;
    asm pop;
    return;
}

int fadd(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int fact(int n)
{
    return n <= 1 ? 1 : n * fact(n-1);
}

int return_1(void)
{
    return 1;
}

// Show factorial
int b;
int c;
c = return_1()*(return_1()+return_1());
print_int(1);
print_char(10);
print_int(c);
print_char(10);
b = fact(fact(fadd(return_1(),c)));
print_int(b);
print_char(10);

// Show integer 42
print_int(42);
print_char(10);
