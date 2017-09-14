uint32_t x[25][576];
uint32_t w1[16][25];
uint32_t c1out[16][576];
uint32_t r1out[16][576];
uint32_t pool1out[16][12][12];
uint32_t c2in[400][64];
uint32_t w2[16][400];
uint32_t c2out[16][64];
uint32_t r2out[16][64];
uint32_t pool2out[16][4][4];
uint32_t reshape[256];
uint32_t w3[100][256];
uint32_t f1out[100];
uint32_t r3out[100];
uint32_t w4[10][100];
uint32_t f2out[10];


for uint32_t i = [0:25] {
    for uint32_t j = [0:576] {
        x[i][j] = input1(450);
    }
}
for uint32_t i = [0:16] {
    for uint32_t j = [0:25] {
            w1[i][j] = input2(500);
    }
}
for uint32_t i = [0:16] {
    for uint32_t j = [0:400] {
            w2[i][j] = input2(500);
    }
}
for uint32_t i = [0:100] {
    for uint32_t j = [0:256] {
            w3[i][j] = input2(500);
    }
}
for uint32_t i = [0:10] {
    for uint32_t j = [0:100] {
            w4[i][j] = input2(500);
    }
}
for uint32_t i = [0:16] {
    for uint32_t j = [0:576] {
	c1out[i][j] = 0;
        for uint32_t k = [0:25] {
		c1out[i][j] = c1out[i][j] + w1[i][k]*x[k][j];
	}
    }
}

for uint32_t i = [0:16] {
    for uint32_t j = [0:576] {
	r1out[i][j] = (c1out[i][j] > 100) ? c1out[i][j] : 0;
    }
}

for uint32_t i = [0:16] {
    for uint32_t j = [0:12] {
	for uint32_t k = [0:12] {
	    pool1out[i][j][k] = 0;
	    for uint32_t l = [0:4] {
	        pool1out[i][j][k] = (r1out[i][48*j + 4*k + l] > pool1out[i][j][k]) ? r1out[i][48*j + 4*k + l] : pool1out[i][j][k]; 	

	    }
	}
    }
}


for uint32_t i = [0:8] {
  for uint32_t j = [0:8] {
    for uint32_t k = [0:16] {
       for uint32_t l = [0:5] {
         for uint32_t m = [0:5] {
	   c2in[25*k+5*l+m][8*i + j] = pool1out[k][i+l][j+m];
	 }
       }
    }
  }
}


for uint32_t i = [0:16] {
    for uint32_t j = [0:64] {
	c2out[i][j] = 0;
        for uint32_t k = [0:400] {
		c2out[i][j] = c2out[i][j] + w2[i][k]*c2in[k][j];
	}
    }
}

for uint32_t i = [0:16] {
    for uint32_t j = [0:64] {
	r2out[i][j] = (c2out[i][j] > 100) ? c2out[i][j] : 0;
    }
}

for uint32_t i = [0:16] {
  for uint32_t j = [0:4] {
    for uint32_t k = [0:4] {
      pool2out[i][j][k] = 0;
      for uint32_t l = [0:4] {
        pool2out[i][j][k] = (r2out[i][16*j + 4*k + l] > pool2out[i][j][k]) ? r2out[i][16*j + 4*k + l] : pool2out[i][j][k]; 
      }
    }
  }
}

for uint32_t i = [0:16] {
  for uint32_t j = [0:4] {
    for uint32_t k = [0:4] {
      reshape[16*i + 4*j + k] = pool2out[i][j][k];
    }
  }
}


for uint32_t i = [0:100] {
    f1out[i] = 0;
    for uint32_t j = [0:256] {
	f1out[i] = f1out[i] + w3[i][j]*reshape[j];
    }
}

for uint32_t i = [0:100] {
    r3out[i] = (f1out[i] > 100) ? f1out[i] : 0; 
}

for uint32_t i = [0:10] {
    f2out[i]= 0;
    for uint32_t j = [0:100] {
		f2out[i] = f2out[i] + w4[i][j]*r3out[j];
    }
}

uint32_t max;
uint32_t out;
uint32_t maxidx;
uint32_t myj;


max = 0;
maxidx = 0;
myj = 0;
for uint32_t i = [0:10] {
  max = (f2out[i] > max) ? f2out[i] : max;
  maxidx = (f2out[i] > max) ? myj : maxidx;
  myj = myj + 1;
}

out = maxidx;
output(out);



