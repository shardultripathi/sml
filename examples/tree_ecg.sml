uint32_t W[6];
uint32_t x[6];
uint32_t B[6];
uint32_t out;

for uint32_t i = [0:6] {
  W[i] = input1(25);
}

for uint32_t i = [0:6] {
  x[i] = input2(40);
}

for uint32_t i = [0:6] {
  B[i] = W[i] > x[i] ? 0 : 1;
}

out = ((1-B[0]) * (B[1] + (1 - B[1])*(B[3] + ((1 -  B[3]) * B[5])))) + (B[0] * (B[2] + ((1 - B[2]) * B[4])));

output(out);
