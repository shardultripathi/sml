uint32_t a[47];
uint32_t b[47];
uint32_t j;
uint32_t k;

j = input1(25);

for uint32_t i = [0:47] {
        a[i] = input1(50);
}

for uint32_t i = [0:47] {
    b[i] = input2(100);
}


for uint32_t i = [0:47] {
  j = j + (a[i] * b[i]);
}
k = (j > 100) ? 1 : 0;
output(k);
