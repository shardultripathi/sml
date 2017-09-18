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

TZX = 0;
uint32_t T3[7];
for uint32_t i = [0:7] {
  T3[i] = input2(150); 
}
uint32_t T4[7];
for uint32_t i = [0:7] {
  T4[i] = input2(150); 
}
uint32_t T5[7];
for uint32_t i = [0:7] {
  T5[i] = input2(150); 
}
uint32_t T6[7];
for uint32_t i = [0:7] {
  T6[i] = input2(150); 
}

for uint32_t i = [0:7] {
  tmp = ((curr > 4) ? (curr > 5 ? T6[i] : T5[i]) : ((curr > 3) ? T4[i] : T3[i]));
  TZX = TZX + tmp*ZX[i];
}

curr = (TZX>100) ? 2*curr+1 : 2*curr+2;

uint32_t V7[7];
for uint32_t i = [0:7] {
  V7[i] = input2(150); 
}

uint32_t V8[7];
for uint32_t i = [0:7] {
  V8[i] = input2(150); 
}


uint32_t V9[7];
for uint32_t i = [0:7] {
  V9[i] = input2(150); 
}

uint32_t V10[7];
for uint32_t i = [0:7] {
  V10[i] = input2(150); 
}

uint32_t V11[7];
for uint32_t i = [0:7] {
  V11[i] = input2(150); 
}

uint32_t V12[7];
for uint32_t i = [0:7] {
  V12[i] = input2(150); 
}


uint32_t V13[7];
for uint32_t i = [0:7] {
  V13[i] = input2(150); 
}

uint32_t V14[7];
for uint32_t i = [0:7] {
  V14[i] = input2(150); 
}

VZX = 0;

for uint32_t i = [0:7] {
  tmp = ((curr > 10) ? (curr > 12 ? ((curr > 13) ? V14[i] : V13[i]) : ((curr > 11) ? V12[i] : V11[i])) : ((curr > 8) ? ((curr > 9) ? V10[i] : V9[i]) : ((curr > 7) ? V8[i] : V7[i])));
  VZX = VZX + (tmp*ZX[i]);
}
VZX = (VZX > 100) ? 100 : ((VZX > 10) ? VZX : 10);

uint32_t W7[7];
for uint32_t i = [0:7] {
  W7[i] = input2(150); 
}

uint32_t W8[7];
for uint32_t i = [0:7] {
  W8[i] = input2(150); 
}


uint32_t W9[7];
for uint32_t i = [0:7] {
  W9[i] = input2(150); 
}

uint32_t W10[7];
for uint32_t i = [0:7] {
  W10[i] = input2(150); 
}

uint32_t W11[7];
for uint32_t i = [0:7] {
  W11[i] = input2(150); 
}

uint32_t W12[7];
for uint32_t i = [0:7] {
  W12[i] = input2(150); 
}


uint32_t W13[7];
for uint32_t i = [0:7] {
  W13[i] = input2(150); 
}

uint32_t W14[7];
for uint32_t i = [0:7] {
  W14[i] = input2(150); 
}

WZX = 0;

for uint32_t i = [0:7] {
  tmp = ((curr > 10) ? (curr > 12 ? ((curr > 13) ? W14[i] : W13[i]) : ((curr > 11) ? W12[i] : V11[i])) : ((curr > 8) ? ((curr > 9) ? W10[i] : W9[i]) : ((curr > 7) ? W8[i] : W7[i])));
  WZX = WZX + (tmp*ZX[i]);
}

Score = Score + VZX * WZX;


uint32_t out;
out = (Score > 100) ? 1 : 0;

output(out);


