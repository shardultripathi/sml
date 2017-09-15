uint32_t testX[400];
for uint32_t i = [0:400] {
  testX[i] = input1(50);
}
uint32_t Z[5][400];
for uint32_t i = [0:5] {
  for uint32_t j = [0:400] {
    Z[i][j] = input2(1000);
  }
}

uint32_t ZX[5];
for uint32_t i = [0:5] {
  ZX[i] = 0;
  for uint32_t j = [0:400] {
      ZX[i] = ZX[i] + testX[i]*Z[i][j]; 
  }  
}
uint32_t Score;
Score = 0;
uint32_t curr;
curr = 0;
uint32_t VZX;
VZX = 0;
uint32_t V[5];
for uint32_t i = [0:5] {
  V[i] = input2(150); 
}
for uint32_t i = [0:5] {
  VZX = VZX + V[i]*ZX[i];
}
VZX = (VZX > 100) ? 100 : ((VZX > 10) ? VZX : 10);
uint32_t WZX;
WZX = 0;
uint32_t W[5];
for uint32_t i = [0:5] {
  W[i] = input2(150); 
}
for uint32_t i = [0:5] {
  WZX = WZX + W[i]*ZX[i];
}
Score = Score + VZX * WZX;
uint32_t TZX;
TZX = 0;
uint32_t T[5];
for uint32_t i = [0:5] {
  T[i] = input2(150); 
}
for uint32_t i = [0:5] {
  TZX = TZX + T[i]*ZX[i];
}
curr = (TZX>100) ? 2*curr+1 : 2*curr+2;

uint32_t V1[5];
for uint32_t i = [0:5] {
  V1[i] = input2(150); 
}

uint32_t V2[5];
for uint32_t i = [0:5] {
  V2[i] = input2(150); 
}
VZX = 0;
uint32_t tmp;
for uint32_t i = [0:5] {
  tmp = ((curr > 1) ? V2[i] : V1[i]);
  VZX = VZX + (tmp*ZX[i]);
}
VZX = (VZX > 100) ? 100 : ((VZX > 10) ? VZX : 10);
WZX = 0;
uint32_t W1[5];
for uint32_t i = [0:5] {
  W1[i] = input2(150); 
}
uint32_t W2[5];
for uint32_t i = [0:5] {
  W2[i] = input2(150); 
}

for uint32_t i = [0:5] {
  tmp = (curr > 1) ? W2[i] : W1[i];
  WZX = WZX + (tmp*ZX[i]);
}
Score = Score + VZX * WZX;

uint32_t out;
out = (Score > 100) ? 1 : 0;

output(out);


