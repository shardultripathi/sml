uint32_t T[24][70][5];
uint32_t P[24];
uint32_t x[70];
uint32_t s;
uint32_t t;
uint32_t k;
uint32_t A[24];
uint32_t max;
uint32_t out;

for uint32_t i = [0:24] {
  P[i] = input1(25);
  for uint32_t j = [0:70] {
    T[i][j][0] = input1(30);
    T[i][j][1] = input1(31);
    T[i][j][2] = input1(32);
    T[i][j][3] = input1(33);
    T[i][j][4] = input1(34);
  }
}

for uint32_t i = [0:70] {
  x[i] = input2(40);
}

for uint32_t i = [0:24] {
  s = P[i];
  for uint32_t j = [0:70] {
    t = (2 > x[j]) ? ((x[j] > 0) ? T[i][j][1] : T[i][j][0]) : ((4 > x[j]) ? ((x[j] > 2) ? T[i][j][3] : T[i][j][2]) : T[i][j][4]);
    s = s + t; 
  }
  A[i] = s;
}

k = 0;
out = 0;
max = A[0];
for uint32_t i = [0:24] {
  out = (A[i] > max) ? k : out;
  k = k + 1; 
}
output(out);
