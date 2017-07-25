uint32_t a[100];
uint32_t b[100];
uint32_t c[100];
uint32_t d[100];

for uint32_t i = [0:100] {
    a[i] = input1(50);
    b[i] = input2(60);
}

for uint32_t i = [0:100] {
    c[i] = a[i] & b[i];
}

for uint32_t i = [0:100] {
    a[i] = a[i] & b[i];
}

for uint32_t i = [0:100] {
    d[i] = a[i] + b[i];
}

output(1);