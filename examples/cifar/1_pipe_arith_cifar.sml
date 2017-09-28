uint32_t x[27][1024];
uint32_t w1[64][27];
uint32_t c1out[64][1024];
uint32_t r1out[64][1024];
uint32_t t1[66][1026];
uint32_t c2in[576][1024];
uint32_t Rc2in[576][1024];
uint32_t IRc2in[576][1024];

for uint32_t i = [0:27] {
    for uint32_t j = [0:1024] {
        x[i][j] = input1(450);
    }
}

for uint32_t i = [0:576] {
    for uint32_t j = [0:1024] {
        Rc2in[i][j] = input1(IRc2in[i][j]);
    }
}


for uint32_t i = [0:64] {
    for uint32_t j = [0:27] {
            w1[i][j] = input2(500);
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
	r1out[i][j] = (c1out[i][j] > 1) ? c1out[i][j] : 0;
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
	c2in[i*9 + 3*l + m][j] = t1[i+l][j+m] + Rc2in[i*9 + 3*l + m][j];
      }
    } 
  }
}


output(1);
