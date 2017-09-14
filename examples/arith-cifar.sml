uint32_t x[27][1024];
uint32_t w1[64][27];
uint32_t c1out[64][1024];
uint32_t r1out[64][1024];
uint32_t t1[66][1026];
uint32_t c2in[576][1024];
uint32_t w2[64][576];
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

for uint32_t i = [0:27] {
    for uint32_t j = [0:1024] {
        x[i][j] = input1(450);
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:27] {
            w1[i][j] = input2(500);
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:576] {
            w2[i][j] = input2(500);
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:576] {
            w3[i][j] = input2(500);
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
    for uint32_t j = [0:1024] {
	c1out[i][j] = 0;
        for uint32_t k = [0:27] {
		c1out[i][j] = c1out[i][j] + w1[i][k]*x[k][j];
	}
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:1024] {
	r1out[i][j] = c1out[i][j] * c1out[i][j];
    }
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:1024] {
    t1[i+1][j+1] = r1out[i][j];
  }
}

for uint32_t i = [0:66] {
  t1[i][0] = 0;
  t1[i][1025] = 0;
}

for uint32_t i = [1:1025] {
  t1[0][i] = 0;
  t1[65][i] = 0;
}

for uint32_t i = [0:64] {
  for uint32_t j = [0:1024] {
    for uint32_t l = [0:3] {
      for uint32_t m = [0:3] {
	c2in[i*9 + 3*l + m][j] = t1[i+l][j+m];
      }
    } 
  }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:1024] {
	c2out[i][j] = 0;
        for uint32_t k = [0:576] {
		c2out[i][j] = c2out[i][j] + w2[i][k]*c2in[k][j];
	}
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:1024] {
	r2out[i][j] = c2out[i][j] * c2out[i][j];
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
	r3out[i][j] = c3out[i][j] * c3out[i][j];
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
	c4in[i*9 + 3*l + m][j] = t3[i+l][j+m];
      }
    } 
  }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:256] {
	c4out[i][j] = 0;
        for uint32_t k = [0:576] {
		c4out[i][j] = c4out[i][j] + w4[i][k]*c4in[k][j];
	}
    }
}

for uint32_t i = [0:64] {
    for uint32_t j = [0:256] {
	r4out[i][j] = c4out[i][j] * c4out[i][j];
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
	r5out[i][j] = c5out[i][j] * c5out[i][j];
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
	r6out[i][j] = c6out[i][j] * c6out[i][j];
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
	r7out[i][j] = c7out[i][j] * c7out[i][j];
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
