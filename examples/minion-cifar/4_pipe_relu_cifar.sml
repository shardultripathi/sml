uint32_t c2in[576][1024];
uint32_t w2[64][576];
uint32_t c2out[64][1024];
uint32_t Rc2in[576][1024];
uint32_t IRc2in[576][1024];
uint32_t Rc2outIS32IE48[64][1024];
uint32_t IRc2outIS32IE48[64][1024];

for uint32_t i = [0:576] {
    for uint32_t j = [0:1024] {
        Rc2in[i][j] = input1(IRc2in[i][j]);
    }
}

for uint32_t i = [32:48] {
    for uint32_t j = [0:1024] {
        Rc2outIS32IE48[i][j] = input1(IRc2outIS32IE48[i][j]);
    }
}

for uint32_t i = [32:48] {
    for uint32_t j = [0:576] {
            w2[i][j] = input2(500);
    }
}


for uint32_t i = [32:48] {
    for uint32_t j = [0:1024] {
	c2out[i][j] = 0;
        for uint32_t k = [0:576] {
		c2out[i][j] = c2out[i][j] + w2[i][k]*(c2in[k][j]-Rc2in[k][j]);
	}
        c2out[i][j] = c2out[i][j] + Rc2outIS32IE48[i][j];
    }
}

output(1);
