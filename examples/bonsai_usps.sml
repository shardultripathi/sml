uint32_t testX[256];
for uint32_t i = [0:256] {
  testX[i] = input1(50);
}
uint32_t Z[7][256];
for uint32_t i = [0:7] {
  for uint32_t j = [0:256] {
    Z[i][j] = input2(1000);
  }
}

uint32_t ZX[7];
for uint32_t i = [0:7] {
  ZX[i] = 0;
  for uint32_t j = [0:256] {
      ZX[i] = ZX[i] + testX[i]*Z[i][j]; 
  }  
}
uint32_t Score;
Score = 0;
uint32_t curr;
curr = 0;
uint32_t VZX;
VZX = 0;
uint32_t V[7];
for uint32_t i = [0:7] {
  V[i] = input2(150); 
}
for uint32_t i = [0:7] {
  VZX = VZX + V[i]*ZX[i];
}
VZX = (VZX > 100) ? 100 : ((VZX > 10) ? VZX : 10);
uint32_t WZX;
WZX = 0;
uint32_t W[7];
for uint32_t i = [0:7] {
  W[i] = input2(150); 
}
for uint32_t i = [0:7] {
  WZX = WZX + W[i]*ZX[i];
}
Score = Score + VZX * WZX;
uint32_t TZX;
TZX = 0;
uint32_t T[7];
for uint32_t i = [0:7] {
  T[i] = input2(150); 
}
for uint32_t i = [0:7] {
  TZX = TZX + T[i]*ZX[i];
}
curr = (TZX>100) ? 2*curr+1 : 2*curr+2;

uint32_t V1[7];
for uint32_t i = [0:7] {
  V1[i] = input2(150); 
}

uint32_t V2[7];
for uint32_t i = [0:7] {
  V2[i] = input2(150); 
}
VZX = 0;
uint32_t tmp;
for uint32_t i = [0:7] {
  tmp = ((curr > 1) ? V2[i] : V1[i]);
  VZX = VZX + (tmp*ZX[i]);
}
VZX = (VZX > 100) ? 100 : ((VZX > 10) ? VZX : 10);
WZX = 0;
uint32_t W1[7];
for uint32_t i = [0:7] {
  W1[i] = input2(150); 
}
uint32_t W2[7];
for uint32_t i = [0:7] {
  W2[i] = input2(150); 
}

for uint32_t i = [0:7] {
  tmp = (curr > 1) ? W2[i] : W1[i];
  WZX = WZX + (tmp*ZX[i]);
}
Score = Score + VZX * WZX;

TZX = 0;
uint32_t T1[7];
for uint32_t i = [0:7] {
  T1[i] = input2(150); 
}
uint32_t T2[7];
for uint32_t i = [0:7] {
  T2[i] = input2(150); 
}

for uint32_t i = [0:7] {
  tmp = (curr > 1) ? T2[i] : T1[i];
  TZX = TZX + tmp*ZX[i];
}
curr = (TZX>100) ? 2*curr+1 : 2*curr+2;

uint32_t V3[7];
for uint32_t i = [0:7] {
  V3[i] = input2(150); 
}

uint32_t V4[7];
for uint32_t i = [0:7] {
  V4[i] = input2(150); 
}


uint32_t V5[7];
for uint32_t i = [0:7] {
  V5[i] = input2(150); 
}

uint32_t V6[7];
for uint32_t i = [0:7] {
  V6[i] = input2(150); 
}
VZX = 0;

for uint32_t i = [0:7] {
  tmp = ((curr > 4) ? (curr > 5 ? V6[i] : V5[i]) : ((curr > 3) ? V4[i] : V3[i]));
  VZX = VZX + (tmp*ZX[i]);
}
VZX = (VZX > 100) ? 100 : ((VZX > 10) ? VZX : 10);
WZX = 0;
uint32_t W3[7];
for uint32_t i = [0:7] {
  W3[i] = input2(150); 
}
uint32_t W4[7];
for uint32_t i = [0:7] {
  W4[i] = input2(150); 
}
uint32_t W5[7];
for uint32_t i = [0:7] {
  W5[i] = input2(150); 
}
uint32_t W6[7];
for uint32_t i = [0:7] {
  W6[i] = input2(150); 
}

for uint32_t i = [0:7] {
  tmp = ((curr > 4) ? (curr > 5 ? W6[i] : W5[i]) : ((curr > 3) ? W4[i] : W3[i]));
  WZX = WZX + (tmp*ZX[i]);
}
Score = Score + VZX * WZX;

uint32_t out;
out = (Score > 100) ? 1 : 0;

output(out);


