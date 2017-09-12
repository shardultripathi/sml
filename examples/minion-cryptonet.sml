uint32_t x[25][169];
uint32_t w1[5][25];
uint32_t t1[5][169];
uint32_t t2[845];
uint32_t t3[845];
uint32_t w2[100][845];
uint32_t t4[100];
uint32_t t5[100];
uint32_t w3[10][100];
uint32_t t6[10];
for uint32_t i = [0:25] {
    for uint32_t j = [0:169] {
        x[i][j] = input1(450);
    }
}
for uint32_t i = [0:5] {
    for uint32_t j = [0:25] {
            w1[i][j] = input2(500);
    }
}
for uint32_t i = [0:100] {
    for uint32_t j = [0:845] {
            w2[i][j] = input2(500);
    }
}
for uint32_t i = [0:10] {
    for uint32_t j = [0:100] {
            w3[i][j] = input2(500);
    }
}

for uint32_t i = [0:5] {
    for uint32_t j = [0:169] {
	t1[i][j] = 0;
        for uint32_t k = [0:25] {
		t1[i][j] = t1[i][j] + w1[i][k]*x[k][j];
	}
    }
}

for uint32_t i = [0:5] {
    for uint32_t j = [0:169] {
	t2[169*i + j] = t1[i][j];
    }
}

for uint32_t i = [0:845] {
	t3[i] = t2[i] * t2[i];
}


for uint32_t i = [0:100] {
    t4[i]= 0;
    for uint32_t j = [0:845] {
		t4[i] = t4[i] + w2[i][j]*t3[j];
    }
}

for uint32_t i = [0:100] {
	t5[i] = t4[i] * t4[i];
}


for uint32_t i = [0:10] {
    t6[i]= 0;
    for uint32_t j = [0:100] {
		t6[i] = t6[i] + w3[i][j]*t5[j];
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
  max = (t6[i] > max) ? t6[i] : max;
  maxidx = (t6[i] > max) ? myj : maxidx;
  myj = myj + 1;
}

out = max;
output(out);

