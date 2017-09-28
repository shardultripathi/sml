uint32_t c2out[64][1024];
uint32_t r2out[64][1024];
uint32_t p1out[64][256];
uint32_t c3in[576][256];
uint32_t t2[66][258];
uint32_t w3[64][576];
uint32_t c3out[64][256];
uint32_t r3out[64][256];
uint32_t c4in[576][256];
uint32_t t3[66][258];

uint32_t Rc2out[64][1024];
uint32_t IRc2out[64][1024];
uint32_t Rc4in[576][256];
uint32_t IRc4in[576][256];


for uint32_t i = [0:64] {
    for uint32_t j = [0:1024] {
        Rc2out[i][j] = input1(IRc2out[i][j]);
    }
}

for uint32_t i = [0:576] {
    for uint32_t j = [0:256] {
        Rc4in[i][j] = input1(IRc4in[i][j]);
    }
}


for uint32_t i = [0:64] {
    for uint32_t j = [0:576] {
            w3[i][j] = input2(500);
    }
}

uint32_t tmp;

for uint32_t i = [0:64] {
    for uint32_t j = [0:1024] {
	tmp = c2out[i][j] - Rc2out[i][j];
	r2out[i][j] = (tmp > 1) ? tmp : 0;
    }
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:256] {
    p1out[i][j] = 0;
      for uint32_t k = [0:2] {
        for uint32_t l = [0:2] {
          p1out[i][j] = r2out[i][4*j + 2*k + l] + p1out[i][j]; 
        }
      }
  }
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:256] {
    t2[i+1][j+1] = p1out[i][j];
  }
}

for uint32_t i = [0:66] {
  t2[i][0] = 0;
  t2[i][257] = 0;
}

for uint32_t i = [1:257] {
  t2[0][i] = 0;
  t2[65][i] = 0;
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:256] {
    for uint32_t l = [0:3] {
      for uint32_t m = [0:3] {
	c3in[i*9 + 3*l + m][j] = t2[i+l][j+m];
      }
    } 
  }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:256] {
	c3out[i][j] = 0;
        for uint32_t k = [0:576] {
		c3out[i][j] = c3out[i][j] + w3[i][k]*c3in[k][j];
	}
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:256] {
	r3out[i][j] = (c3out[i][j] > 1 ) ? c3out[i][j] : 0;
    }
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:256] {
    t3[i+1][j+1] = r3out[i][j];
  }
}

for uint32_t i = [0:66] {
  t3[i][0] = 0;
  t3[i][257] = 0;
}

for uint32_t i = [1:257] {
  t3[0][i] = 0;
  t3[65][i] = 0;
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:256] {
    for uint32_t l = [0:3] {
      for uint32_t m = [0:3] {
	c4in[i*9 + 3*l + m][j] = t3[i+l][j+m] + Rc4in[i*9 + 3*l + m][j];
      }
    } 
  }
}

output(1);
