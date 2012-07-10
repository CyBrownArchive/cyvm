void print_char(int a)
{
    asm iloadfp;
    asm 4;
    asm callbuiltin;
    asm .b 2;
    asm pop;
    return;
}

// Show hello world
print_char(72);
print_char(69);
print_char(76);
print_char(76);
print_char(79);
print_char(32);
print_char(87);
print_char(79);
print_char(82);
print_char(76);
print_char(68);
print_char(10);
