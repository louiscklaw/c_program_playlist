int a[10];
int* p = a;

assert(sizeof(a) / sizeof(a[0]) == 10);
assert(sizeof(p) == sizeof(int*));
assert(sizeof(*p) == sizeof(int));
