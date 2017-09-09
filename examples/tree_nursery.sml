uint32_t W[4];
uint32_t x[4];
uint32_t B[4];
uint32_t out;

for uint32_t i = [0:4] {
  W[i] = input1(25);
}

for uint32_t i = [0:4] {
  x[i] = input2(40);
}

for uint32_t i = [0:4] {
  B[i] = W[i] > x[i] ? 0 : 1;
}

out = (B[0] * B[1]) * (B[2] * B[3]);

output(out);
