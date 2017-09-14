uint32_t T[5][9][3];
uint32_t P[5];
uint32_t x[9];
uint32_t s;
uint32_t t;
uint32_t k;
uint32_t A[5];

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

uint32_t max;
uint32_t out;
uint32_t maxidx;
uint32_t myj;


max = 0;
maxidx = 0;
myj = 0;
for uint32_t i = [0:10] {
  max = (A[i] > max) ? A[i] : max;
  maxidx = (A[i] > max) ? myj : maxidx;
  myj = myj + 1;
}

out = maxidx;
output(out);
