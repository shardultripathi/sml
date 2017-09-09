uint32_t T[5][9][3];
uint32_t P[5];
uint32_t x[9];
uint32_t s;
uint32_t t;
uint32_t k;
uint32_t A[5];
uint32_t max;
uint32_t out;

for uint32_t i = [0:5] {
  P[i] = input1(25);
  for uint32_t j = [0:9] {
    T[i][j][0] = input1(30);
    T[i][j][1] = input1(31);
    T[i][j][2] = input1(32);
  }
}

for uint32_t i = [0:9] {
  x[i] = input2(40);
}

for uint32_t i = [0:5] {
  s = P[i];
  for uint32_t j = [0:9] {
    t = (1 > x[j]) ? T[i][j][0] : ((2 > x[j]) ? T[i][j][1] : T[i][j][2]);
    s = s + t; 
  }
  A[i] = s;
}

k = 0;
out = 0;
max = A[0];
for uint32_t i = [0:5] {
  out = (A[i] > max) ? k : out;
  k = k + 1; 
}
output(out);
