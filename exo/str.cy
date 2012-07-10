void print_int(int a)
{
    asm iloadfp;
    asm 4;
    asm callbuiltin;
    asm .b 1;
    asm pop;
    return;
}
"hello world";
"oui";
print_int(1+1);