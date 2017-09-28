uint32_t c4in[576][256];
uint32_t w4[64][576];
uint32_t c4out[64][256];
uint32_t r4out[64][256]; 
uint32_t p2out[64][64];
uint32_t c5in[576][64];
uint32_t t4[66][66];
uint32_t w5[64][576];
uint32_t c5out[64][64];
uint32_t r5out[64][64];
uint32_t w6[64][64];
uint32_t c6out[64][64];
uint32_t r6out[64][64];
uint32_t w7[16][64];
uint32_t c7out[16][64];
uint32_t r7out[16][64];
uint32_t reshape[1024];
uint32_t w8[10][1024];
uint32_t f1out[10];

uint32_t Rc4in[576][256];
uint32_t IRc4in[576][256];

for uint32_t i = [0:576] {
    for uint32_t j = [0:256] {
        Rc4in[i][j] = input1(IRc4in[i][j]);
    }
}



for uint32_t i = [0:64] {
    for uint32_t j = [0:576] {
            w4[i][j] = input2(500);
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:576] {
            w5[i][j] = input2(500);
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:64] {
            w6[i][j] = input2(500);
    }
}

for uint32_t i = [0:16] {
    for uint32_t j = [0:64] {
            w7[i][j] = input2(500);
    }
}

for uint32_t i = [0:10] {
    for uint32_t j = [0:1024] {
            w8[i][j] = input2(500);
    }
}


for uint32_t i = [0:64] {
    for uint32_t j = [0:256] {
	c4out[i][j] = 0;
        for uint32_t k = [0:576] {
		c4out[i][j] = c4out[i][j] + w4[i][k]*(c4in[k][j] - Rc4in[k][j]);
	}
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:256] {
	r4out[i][j] = (c4out[i][j] > 1) ?  c4out[i][j] : 0;
    }
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:64] {
    p2out[i][j] = 0;
      for uint32_t k = [0:2] {
        for uint32_t l = [0:2] {
          p2out[i][j] = r4out[i][4*j + 2*k + l] + p2out[i][j]; 
        }
      }
  }
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:64] {
    t4[i+1][j+1] = p2out[i][j];
  }
}

for uint32_t i = [0:66] {
  t4[i][0] = 0;
  t4[i][65] = 0;
}

for uint32_t i = [1:65] {
  t4[0][i] = 0;
  t4[65][i] = 0;
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:64] {
    for uint32_t l = [0:3] {
      for uint32_t m = [0:3] {
	c5in[i*9 + 3*l + m][j] = t4[i+l][j+m];
      }
    } 
  }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:64] {
	c5out[i][j] = 0;
        for uint32_t k = [0:576] {
		c5out[i][j] = c5out[i][j] + w5[i][k]*c5in[k][j];
	}
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:64] {
	r5out[i][j] = (c5out[i][j] > 1) ? c5out[i][j] : 0;
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:64] {
	c6out[i][j] = 0;
        for uint32_t k = [0:64] {
		c6out[i][j] = c6out[i][j] + w6[i][k]*r5out[k][j];
	}
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:64] {
	r6out[i][j] = (c6out[i][j] > 1) ? c6out[i][j] : 0;
    }
}

for uint32_t i = [0:16] {
    for uint32_t j = [0:64] {
	c7out[i][j] = 0;
        for uint32_t k = [0:64] {
		c7out[i][j] = c7out[i][j] + w7[i][k]*r6out[k][j];
	}
    }
}

for uint32_t i = [0:16] {
    for uint32_t j = [0:64] {
	r7out[i][j] = (c7out[i][j] > 1) ? c7out[i][j] : 0;
    }
}

for uint32_t i = [0:16] {
  for uint32_t j = [0:64] {
      reshape[64*i + j] = r7out[i][j];
  }
}

for uint32_t i = [0:10] {
    f1out[i]= 0;
    for uint32_t j = [0:1024] {
		f1out[i] = f1out[i] + w8[i][j]*reshape[j];
    }
}

output(1);
