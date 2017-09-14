uint32_t x[33][33];
uint32_t wconv1[32][5][5];
uint32_t bconv1[32];
uint32_t hconv1[32][28][28];
for uint32_t i = [0:33] {
    for uint32_t j = [0:33] {
        x[i][j] = input1(450);
    }
}
for uint32_t i = [0:32] {
    for uint32_t j = [0:5] {
        for uint32_t k = [0:5] {
            wconv1[i][j][k] = input2(500);
        }
    }
}
for uint32_t i = [0:32] {
    bconv1[i] = input2(66882);
}

for uint32_t i = [0:32] {
    for uint32_t j = [0:28] {
        for uint32_t k = [0:28] {
            hconv1[i][j][k] = bconv1[i];
            for uint32_t l = [0:5] {
                for uint32_t m = [0:5] {
                    hconv1[i][j][k] = hconv1[i][j][k] + wconv1[i][l][m]*x[j+l][k+m];
                }
            }
        }
    }
}

for uint32_t i = [0:32] {
    for uint32_t j = [0:28] {
        for uint32_t k = [0:28] {
            hconv1[i][j][k] = (hconv1[i][j][k] > 2147483648) ? 0 : (hconv1[i][j][k] >> 8);
        }
    }
}

uint32_t hpool1[32][19][19];
for uint32_t i = [0:32] {
    for uint32_t j = [0:28:2] {
        for uint32_t k = [0:28:2] {
            hpool1[i][j/2][k/2] = 0;
            hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2] > hconv1[i][j][k]) ? hpool1[i][j/2][k/2] : hconv1[i][j][k];
            hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2] > hconv1[i][j+1][k]) ? hpool1[i][j/2][k/2] : hconv1[i][j+1][k];
            hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2] > hconv1[i][j][k+1]) ? hpool1[i][j/2][k/2] : hconv1[i][j][k+1];
            hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2] > hconv1[i][j+1][k+1]) ? hpool1[i][j/2][k/2] : hconv1[i][j+1][k+1];
        }
    }
    for uint32_t j = [14:19] {
        for uint32_t k = [0:19] {
            hpool1[i][j][k] = 0;
        }
    }
    for uint32_t j = [0:19] {
        for uint32_t k = [14:19] {
            hpool1[i][j][k] = 0;
        }
    }
}

uint32_t wconv2[64][5][5];
uint32_t bconv2[64];
uint32_t hconv2[64][14][14];
for uint32_t i = [0:64] {
    for uint32_t j = [0:5] {
        for uint32_t k = [0:5] {
            wconv2[i][j][k] = input2(500);
        }
    }
}
for uint32_t i = [0:64] {
    bconv2[i] = input2(66882);
}

for uint32_t i = [0:32] {
    for uint32_t j = [0:14] {
        for uint32_t k = [0:14] {
            hconv2[2*i][j][k] = 0;
            hconv2[2*i+1][j][k] = 0;
            for uint32_t l = [0:5] {
                for uint32_t m = [0:5] {
                    hconv2[2*i][j][k] = hconv2[2*i][j][k] + wconv2[2*i][l][m]*hpool1[i][j+l][k+m];
                    hconv2[2*i+1][j][k] = hconv2[2*i+1][j][k] + wconv2[2*i+1][l][m]*hpool1[i][j+l][k+m];
                }
            }
            hconv2[2*i][j][k] = hconv2[2*i][j][k] + bconv2[2*i];
            hconv2[2*i+1][j][k] = hconv2[2*i+1][j][k] + bconv2[2*i+1];
        }
    }
}
for uint32_t i = [0:64] {
    for uint32_t j = [0:14] {
        for uint32_t k = [0:14] {
            hconv2[i][j][k] = (hconv2[i][j][k] > 2147483648) ? 0 : (hconv2[i][j][k] >> 8);
        }
    }
}
uint32_t hpool2[64][7][7];
for uint32_t i = [0:64] {
    for uint32_t j = [0:14:2] {
        for uint32_t k = [0:14:2] {
            hpool2[i][j/2][k/2] = 0;
            hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2] > hconv2[i][j][k]) ? hpool2[i][j/2][k/2] : hconv2[i][j][k];
            hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2] > hconv2[i][j+1][k]) ? hpool2[i][j/2][k/2] : hconv2[i][j+1][k];
            hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2] > hconv2[i][j][k+1]) ? hpool2[i][j/2][k/2] : hconv2[i][j][k+1];
            hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2] > hconv2[i][j+1][k+1]) ? hpool2[i][j/2][k/2] : hconv2[i][j+1][k+1];
        }
    }
}
uint32_t hpool2flat[3136];
for uint32_t i = [0:64] {
    for uint32_t j = [0:7] {
        for uint32_t k = [0:7] {
            hpool2flat[49*i + 7*j + k] = hpool2[i][j][k];
        }
    }
}

uint32_t wfc1[1024][3136];
uint32_t bfc1[1024];
for uint32_t i = [0:1024] {
    for uint32_t j = [0:3136] {
        wfc1[i][j] = input2(460);
    }
}
for uint32_t i = [0:1024] {
    bfc1[i] = input2(66892);
}

uint32_t hfc1[1024];
for uint32_t i = [0:1024] {
    hfc1[i] = 0;
    for uint32_t j = [0:3136] {
        hfc1[i] = hfc1[i] + wfc1[i][j]*hpool2flat[j];
    }
    hfc1[i] = hfc1[i] + bfc1[i];
}

for uint32_t i = [0:1024] {
    hfc1[i] = (hfc1[i] > 2147483648) ? 0 : (hfc1[i] );
}

uint32_t wfc2[10][1024];
uint32_t bfc2[10];
for uint32_t i = [0:10] {
    for uint32_t j = [0:1024] {
        wfc2[i][j] = input2(460);
    }
}
for uint32_t i = [0:10] {
    bfc2[i] = input2(66892);
}

uint32_t yconv[10];
for uint32_t i = [0:10] {
    yconv[i] = 0;
    for uint32_t j = [0:1024] {
        yconv[i] = yconv[i] + wfc2[i][j]*hfc1[j];
    }
    yconv[i] = yconv[i] + bfc2[i];
}
uint32_t max;
max = 0;
for uint32_t i = [0:10] {
    max = (yconv[i] > max) ? yconv[i] : max;
}

output(47>>2);
