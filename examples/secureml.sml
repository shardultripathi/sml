uint32_t x[784];
uint32_t w1[128][784];
uint32_t f1out[128];
uint32_t r1out[128];
uint32_t f2out[128];
uint32_t w2[128][128];
uint32_t r2out[128];
uint32_t w3[10][128];
uint32_t f3out[10];


for uint32_t i = [0:784] {
        x[i] = input1(450);
}
for uint32_t i = [0:128] {
    for uint32_t j = [0:784] {
            w1[i][j] = input2(500);
    }
}
for uint32_t i = [0:128] {
    for uint32_t j = [0:128] {
            w2[i][j] = input2(500);
    }
}
for uint32_t i = [0:10] {
    for uint32_t j = [0:128] {
            w3[i][j] = input2(500);
    }
}

for uint32_t i = [0:128] {
    f1out[i] = 0;
    for uint32_t j = [0:784] {
	f1out[i] = f1out[i] + w1[i][j]*x[j];
    }
}

for uint32_t i = [0:128] {
    r1out[i] = f1out[i] * f1out[i]; 
}

for uint32_t i = [0:128] {
    f2out[i]= 0;
    for uint32_t j = [0:128] {
		f2out[i] = f2out[i] + w2[i][j]*r1out[j];
    }
}


for uint32_t i = [0:128] {
    r2out[i] = f2out[i] * f2out[i]; 
}


for uint32_t i = [0:10] {
    f3out[i]= 0;
    for uint32_t j = [0:128] {
		f3out[i] = f3out[i] + w3[i][j]*r2out[j];
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
  max = (f3out[i] > max) ? f3out[i] : max;
  maxidx = (f3out[i] > max) ? myj : maxidx;
  myj = myj + 1;
}

out = maxidx;
output(out);



