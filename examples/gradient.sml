uint32_t S1S5[10][100];
uint32_t S1S6[10][100];
uint32_t S2S5[10][100];
uint32_t S2S6[10][100];
uint32_t S5[10][100];
uint32_t S5P[10][100];
uint32_t S6[10][100];
uint32_t S6P[10][100];
uint32_t S1R[100];
uint32_t S2R[100];
uint32_t R[100];
uint32_t IP[100];

for uint32_t i = [0:10]{
  for uint32_t j = [0:100] {
    S1S5[i][j] = input1(50);
  }
}

for uint32_t i = [0:10]{
  for uint32_t j = [0:100] {
    S1S6[i][j] = input1(55);
  }
}

for uint32_t i = [0:10]{
  for uint32_t j = [0:100] {
    S2S5[i][j] = input2(60);
  }
}

for uint32_t i = [0:10]{
  for uint32_t j = [0:100] {
    S2S6[i][j] = input2(65);
  }
}

  for uint32_t j = [0:100] {
    S1R[j] = input1(70);
  }

  for uint32_t j = [0:100] {
    S2R[j] = input2(70);
  }


  for uint32_t j = [0:100] {
    R[j] = S1R[j]+S2R[j];
  }

for uint32_t i = [0:10]{
  for uint32_t j = [0:100] {
    S5[i][j] = S1S5[i][j]+S2S5[i][j];
  }
}

for uint32_t i = [0:10]{
  for uint32_t j = [0:100] {
    S6[i][j] = S1S6[i][j]+S2S6[i][j];
  }
}

for uint32_t i = [0:100]{
  IP[i] = 0;
  for uint32_t j = [0:10] {
    IP[i] = IP[i] + (S5[j][i] * S6[j][i]);
  }
  IP[i] = R[i] - IP[i];
}

for uint32_t i = [0:100] {
  for uint32_t j = [0:10] {
    S5P[j][i] = S6[j][i] * IP[i];
  }
}


for uint32_t i = [0:100] {
  for uint32_t j = [0:10] {
    S6P[j][i] = S5[j][i] * IP[i];
  }
}

output(1);

