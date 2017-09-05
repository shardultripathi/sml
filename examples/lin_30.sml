uint32_t a[30];
uint32_t b[30];
uint32_t j;
uint32_t k;
j = 0;

for uint32_t i = [0:30] {
        a[i] = input1(50);
}

for uint32_t i = [0:30] {
    b[i] = input2(100);
}


for uint32_t i = [0:30] {
  j = j + (a[i] * b[i]);
}
k = (j > 100) ? 1 : 0;
output(k);
