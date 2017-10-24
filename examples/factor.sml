uint32_t S1[16384][24];
uint32_t S2[16384][24];
uint32_t S[16384][24];
uint32_t outmat[16384][24];
uint32_t boolarr[1000000];
uint32_t temp[10];
uint32_t dots[15444];

public uint32_t boolidx;
uint32_t b;
uint32_t b1;
boolidx = 0;

for uint32_t i = [0:16384] {
  for uint32_t j = [0:24] {
    S1[i][j] = input1(50);
  }
}

for uint32_t i = [0:1000000] {
  boolarr[i] = input1(1);
}

for uint32_t i = [0:16384] {
  for uint32_t j = [0:24] {
    S2[i][j] = input2(60);
  }
}

for uint32_t i = [0:16384] {
  for uint32_t j = [0:24] {
    S[i][j] = S1[i][j] + S2[i][j];
  }
}




for uint32_t i = [0:8192] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[2*i][j] = (b * S[2*i][j]) + (b1 * S[2*i+1][j]); 
      outmat[2*i+1][j] = (b1 * S[2*i][j]) + (b * S[2*i+1][j]);
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[4*i][j] = (b * outmat[4*i][j]) + (b1 * outmat[4*i+2][j]); 
      outmat[4*i+2][j] = (b1 * outmat[4*i][j]) + (b * outmat[4*i+2][j]);
    }  
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[4*i+1][j] = (b * outmat[4*i+1][j]) + (b1 * outmat[4*i+3][j]); 
      outmat[4*i+3][j] = (b1 * outmat[4*i+1][j]) + (b * outmat[4*i+3][j]);      
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24]  {
      outmat[4*i+2][j] = (b1 * outmat[4*i+1][j]) + (b * outmat[4*i+2][j]);
      outmat[4*i+1][j] = (b * outmat[4*i+1][j]) + (b1 * outmat[4*i+2][j]); 
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:2] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2*k][j] = (b1 * outmat[8*i+2*k][j]) + (b * outmat[8*i+4+2*k][j]);
        outmat[8*i+4+2*k][j] = (b * outmat[8*i+2*k][j]) + (b1 * outmat[8*i+4+2*k][j]); 
      }
    }
    for uint32_t k = [0:2]  {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2*k+1][j] = (b1 * outmat[8*i+2*k+1][j]) + (b * outmat[8*i+4+2*k+1][j]);
        outmat[8*i+4+2*k+1][j] = (b * outmat[8*i+2*k+1][j]) + (b1 * outmat[8*i+4+2*k+1][j]); 
      }
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:3] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2+2*k][j] = (b1 * outmat[8*i+1+2*k][j]) + (b * outmat[8*i+2+2*k][j]);
        outmat[8*i+1+2*k][j] = (b * outmat[8*i+1+2*k][j]) + (b1 * outmat[8*i+2+2*k][j]); 
      }  
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[16*i+2*k][j] = (b1 * outmat[16*i+2*k][j]) + (b * outmat[16*i+2*k+8][j]);
        outmat[16*i+2*k+8][j] = (b * outmat[16*i+2*k][j]) + (b1 * outmat[16*i+2*k+8][j]); 
      }
    }
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[16*i+2*k+1][j] = (b1 * outmat[16*i+2*k+1][j]) + (b * outmat[16*i+2*k+8+1][j]);
        outmat[16*i+2*k+8+1][j] = (b * outmat[16*i+2*k+1][j]) + (b1 * outmat[16*i+2*k+8+1][j]); 
      }
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:7] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[16*i+2*k+1][j] = (b * outmat[16*i+2*k+1][j]) + (b1 * outmat[16*i+2*k+2][j]); 
        outmat[16*i+2*k+2][j] = (b1 * outmat[16*i+2*k+1][j]) + (b * outmat[16*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[32*i+2*k][j] = (b1 * outmat[32*i+2*k][j]) + (b * outmat[32*i+2*k+16][j]);
        outmat[32*i+2*k+16][j] = (b * outmat[32*i+2*k][j]) + (b1 * outmat[32*i+2*k+16][j]); 
      }
    }
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[32*i+2*k+1][j] = (b1 * outmat[32*i+2*k+1][j]) + (b * outmat[32*i+2*k+16+1][j]);
        outmat[32*i+2*k+16+1][j] = (b * outmat[32*i+2*k+1][j]) + (b1 * outmat[32*i+2*k+16+1][j]); 
      }
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:15] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[32*i+2*k+1][j] = (b * outmat[32*i+2*k+1][j]) + (b1 * outmat[32*i+2*k+2][j]); 
        outmat[32*i+2*k+2][j] = (b1 * outmat[32*i+2*k+1][j]) + (b * outmat[32*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[64*i+2*k][j] = (b1 * outmat[64*i+2*k][j]) + (b * outmat[64*i+2*k+32][j]);
        outmat[64*i+2*k+32][j] = (b * outmat[64*i+2*k][j]) + (b1 * outmat[64*i+2*k+32][j]); 
      }
    }
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[64*i+2*k+1][j] = (b1 * outmat[64*i+2*k+1][j]) + (b * outmat[64*i+2*k+32+1][j]);
        outmat[64*i+2*k+32+1][j] = (b * outmat[64*i+2*k+1][j]) + (b1 * outmat[64*i+2*k+32+1][j]); 
      }
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:31] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[64*i+2*k+1][j] = (b * outmat[64*i+2*k+1][j]) + (b1 * outmat[64*i+2*k+2][j]); 
        outmat[64*i+2*k+2][j] = (b1 * outmat[64*i+2*k+1][j]) + (b * outmat[64*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[128*i+2*k][j] = (b1 * outmat[128*i+2*k][j]) + (b * outmat[128*i+2*k+64][j]);
        outmat[128*i+2*k+64][j] = (b * outmat[128*i+2*k][j]) + (b1 * outmat[128*i+2*k+64][j]); 
      }
    }
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[128*i+2*k+1][j] = (b1 * outmat[128*i+2*k+1][j]) + (b * outmat[128*i+2*k+64+1][j]);
        outmat[128*i+2*k+64+1][j] = (b * outmat[128*i+2*k+1][j]) + (b1 * outmat[128*i+2*k+64+1][j]); 
      }
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:63] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[128*i+2*k+1][j] = (b * outmat[128*i+2*k+1][j]) + (b1 * outmat[128*i+2*k+2][j]); 
        outmat[128*i+2*k+2][j] = (b1 * outmat[128*i+2*k+1][j]) + (b * outmat[128*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[256*i+2*k][j] = (b1 * outmat[256*i+2*k][j]) + (b * outmat[256*i+2*k+128][j]);
        outmat[256*i+2*k+128][j] = (b * outmat[256*i+2*k][j]) + (b1 * outmat[256*i+2*k+128][j]); 
      }
    }
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[256*i+2*k+1][j] = (b1 * outmat[256*i+2*k+1][j]) + (b * outmat[256*i+2*k+128+1][j]);
        outmat[256*i+2*k+128+1][j] = (b * outmat[256*i+2*k+1][j]) + (b1 * outmat[256*i+2*k+128+1][j]); 
      }
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:127] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[256*i+2*k+1][j] = (b * outmat[256*i+2*k+1][j]) + (b1 * outmat[256*i+2*k+2][j]); 
        outmat[256*i+2*k+2][j] = (b1 * outmat[256*i+2*k+1][j]) + (b * outmat[256*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:32] {
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[512*i+2*k][j] = (b1 * outmat[512*i+2*k][j]) + (b * outmat[512*i+2*k+256][j]);
        outmat[512*i+2*k+256][j] = (b * outmat[512*i+2*k][j]) + (b1 * outmat[512*i+2*k+256][j]); 
      }
    }
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[512*i+2*k+1][j] = (b1 * outmat[512*i+2*k+1][j]) + (b * outmat[512*i+2*k+256+1][j]);
        outmat[512*i+2*k+256+1][j] = (b * outmat[512*i+2*k+1][j]) + (b1 * outmat[512*i+2*k+256+1][j]); 
      }
    }
}

for uint32_t i = [0:32] {
    for uint32_t k = [0:255] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[512*i+2*k+1][j] = (b * outmat[512*i+2*k+1][j]) + (b1 * outmat[512*i+2*k+2][j]); 
        outmat[512*i+2*k+2][j] = (b1 * outmat[512*i+2*k+1][j]) + (b * outmat[512*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[1024*i+2*k][j] = (b1 * outmat[1024*i+2*k][j]) + (b * outmat[1024*i+2*k+512][j]);
        outmat[1024*i+2*k+512][j] = (b * outmat[1024*i+2*k][j]) + (b1 * outmat[1024*i+2*k+512][j]); 
      }
    }
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[1024*i+2*k+1][j] = (b1 * outmat[1024*i+2*k+1][j]) + (b * outmat[1024*i+2*k+512+1][j]);
        outmat[1024*i+2*k+512+1][j] = (b * outmat[1024*i+2*k+1][j]) + (b1 * outmat[1024*i+2*k+512+1][j]); 
      }
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:511] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[1024*i+2*k+1][j] = (b * outmat[1024*i+2*k+1][j]) + (b1 * outmat[1024*i+2*k+2][j]); 
        outmat[1024*i+2*k+2][j] = (b1 * outmat[1024*i+2*k+1][j]) + (b * outmat[1024*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[2048*i+2*k][j] = (b1 * outmat[2048*i+2*k][j]) + (b * outmat[2048*i+2*k+1024][j]);
        outmat[2048*i+2*k+1024][j] = (b * outmat[2048*i+2*k][j]) + (b1 * outmat[2048*i+2*k+1024][j]); 
      }
    }
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[2048*i+2*k+1][j] = (b1 * outmat[2048*i+2*k+1][j]) + (b * outmat[2048*i+2*k+1024+1][j]);
        outmat[2048*i+2*k+1024+1][j] = (b * outmat[2048*i+2*k+1][j]) + (b1 * outmat[2048*i+2*k+1024+1][j]); 
      }
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:1023] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[2048*i+2*k+1][j] = (b * outmat[2048*i+2*k+1][j]) + (b1 * outmat[2048*i+2*k+2][j]); 
        outmat[2048*i+2*k+2][j] = (b1 * outmat[2048*i+2*k+1][j]) + (b * outmat[2048*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k][j] = (b1 * outmat[4096*i+2*k][j]) + (b * outmat[4096*i+2*k+2048][j]);
        outmat[4096*i+2*k+2048][j] = (b * outmat[4096*i+2*k][j]) + (b1 * outmat[4096*i+2*k+2048][j]); 
      }
    }
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k+1][j] = (b1 * outmat[4096*i+2*k+1][j]) + (b * outmat[4096*i+2*k+2048+1][j]);
        outmat[4096*i+2*k+2048+1][j] = (b * outmat[4096*i+2*k+1][j]) + (b1 * outmat[4096*i+2*k+2048+1][j]); 
      }
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:2047] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k+1][j] = (b * outmat[4096*i+2*k+1][j]) + (b1 * outmat[4096*i+2*k+2][j]); 
        outmat[4096*i+2*k+2][j] = (b1 * outmat[4096*i+2*k+1][j]) + (b * outmat[4096*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:2] {
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k][j] = (b1 * outmat[8192*i+2*k][j]) + (b * outmat[8192*i+2*k+4096][j]);
        outmat[8192*i+2*k+4096][j] = (b * outmat[8192*i+2*k][j]) + (b1 * outmat[8192*i+2*k+4096][j]); 
      }
    }
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k+1][j] = (b1 * outmat[8192*i+2*k+1][j]) + (b * outmat[8192*i+2*k+4096+1][j]);
        outmat[8192*i+2*k+4096+1][j] = (b * outmat[8192*i+2*k+1][j]) + (b1 * outmat[8192*i+2*k+4096+1][j]); 
      }
    }
}

for uint32_t i = [0:2] {
    for uint32_t k = [0:4095] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k+1][j] = (b * outmat[8192*i+2*k+1][j]) + (b1 * outmat[8192*i+2*k+2][j]); 
        outmat[8192*i+2*k+2][j] = (b1 * outmat[8192*i+2*k+1][j]) + (b * outmat[8192*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [1:16344] {
  for uint32_t j = [4:14] {
    outmat[i][j] = outmat[i][2]*outmat[i-1][j] + ((1-outmat[i][2]) *outmat[i][j]); 
  }
}


for uint32_t i = [0:8192] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[2*i][j] = (b * outmat[2*i][j]) + (b1 * outmat[2*i+1][j]); 
      outmat[2*i+1][j] = (b1 * outmat[2*i][j]) + (b * outmat[2*i+1][j]);
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[4*i][j] = (b * outmat[4*i][j]) + (b1 * outmat[4*i+2][j]); 
      outmat[4*i+2][j] = (b1 * outmat[4*i][j]) + (b * outmat[4*i+2][j]);
    }  
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[4*i+1][j] = (b * outmat[4*i+1][j]) + (b1 * outmat[4*i+3][j]); 
      outmat[4*i+3][j] = (b1 * outmat[4*i+1][j]) + (b * outmat[4*i+3][j]);      
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24]  {
      outmat[4*i+2][j] = (b1 * outmat[4*i+1][j]) + (b * outmat[4*i+2][j]);
      outmat[4*i+1][j] = (b * outmat[4*i+1][j]) + (b1 * outmat[4*i+2][j]); 
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:2] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2*k][j] = (b1 * outmat[8*i+2*k][j]) + (b * outmat[8*i+4+2*k][j]);
        outmat[8*i+4+2*k][j] = (b * outmat[8*i+2*k][j]) + (b1 * outmat[8*i+4+2*k][j]); 
      }
    }
    for uint32_t k = [0:2]  {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2*k+1][j] = (b1 * outmat[8*i+2*k+1][j]) + (b * outmat[8*i+4+2*k+1][j]);
        outmat[8*i+4+2*k+1][j] = (b * outmat[8*i+2*k+1][j]) + (b1 * outmat[8*i+4+2*k+1][j]); 
      }
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:3] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2+2*k][j] = (b1 * outmat[8*i+1+2*k][j]) + (b * outmat[8*i+2+2*k][j]);
        outmat[8*i+1+2*k][j] = (b * outmat[8*i+1+2*k][j]) + (b1 * outmat[8*i+2+2*k][j]); 
      }  
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[16*i+2*k][j] = (b1 * outmat[16*i+2*k][j]) + (b * outmat[16*i+2*k+8][j]);
        outmat[16*i+2*k+8][j] = (b * outmat[16*i+2*k][j]) + (b1 * outmat[16*i+2*k+8][j]); 
      }
    }
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[16*i+2*k+1][j] = (b1 * outmat[16*i+2*k+1][j]) + (b * outmat[16*i+2*k+8+1][j]);
        outmat[16*i+2*k+8+1][j] = (b * outmat[16*i+2*k+1][j]) + (b1 * outmat[16*i+2*k+8+1][j]); 
      }
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:7] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[16*i+2*k+1][j] = (b * outmat[16*i+2*k+1][j]) + (b1 * outmat[16*i+2*k+2][j]); 
        outmat[16*i+2*k+2][j] = (b1 * outmat[16*i+2*k+1][j]) + (b * outmat[16*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[32*i+2*k][j] = (b1 * outmat[32*i+2*k][j]) + (b * outmat[32*i+2*k+16][j]);
        outmat[32*i+2*k+16][j] = (b * outmat[32*i+2*k][j]) + (b1 * outmat[32*i+2*k+16][j]); 
      }
    }
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[32*i+2*k+1][j] = (b1 * outmat[32*i+2*k+1][j]) + (b * outmat[32*i+2*k+16+1][j]);
        outmat[32*i+2*k+16+1][j] = (b * outmat[32*i+2*k+1][j]) + (b1 * outmat[32*i+2*k+16+1][j]); 
      }
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:15] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[32*i+2*k+1][j] = (b * outmat[32*i+2*k+1][j]) + (b1 * outmat[32*i+2*k+2][j]); 
        outmat[32*i+2*k+2][j] = (b1 * outmat[32*i+2*k+1][j]) + (b * outmat[32*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[64*i+2*k][j] = (b1 * outmat[64*i+2*k][j]) + (b * outmat[64*i+2*k+32][j]);
        outmat[64*i+2*k+32][j] = (b * outmat[64*i+2*k][j]) + (b1 * outmat[64*i+2*k+32][j]); 
      }
    }
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[64*i+2*k+1][j] = (b1 * outmat[64*i+2*k+1][j]) + (b * outmat[64*i+2*k+32+1][j]);
        outmat[64*i+2*k+32+1][j] = (b * outmat[64*i+2*k+1][j]) + (b1 * outmat[64*i+2*k+32+1][j]); 
      }
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:31] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[64*i+2*k+1][j] = (b * outmat[64*i+2*k+1][j]) + (b1 * outmat[64*i+2*k+2][j]); 
        outmat[64*i+2*k+2][j] = (b1 * outmat[64*i+2*k+1][j]) + (b * outmat[64*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[128*i+2*k][j] = (b1 * outmat[128*i+2*k][j]) + (b * outmat[128*i+2*k+64][j]);
        outmat[128*i+2*k+64][j] = (b * outmat[128*i+2*k][j]) + (b1 * outmat[128*i+2*k+64][j]); 
      }
    }
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[128*i+2*k+1][j] = (b1 * outmat[128*i+2*k+1][j]) + (b * outmat[128*i+2*k+64+1][j]);
        outmat[128*i+2*k+64+1][j] = (b * outmat[128*i+2*k+1][j]) + (b1 * outmat[128*i+2*k+64+1][j]); 
      }
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:63] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[128*i+2*k+1][j] = (b * outmat[128*i+2*k+1][j]) + (b1 * outmat[128*i+2*k+2][j]); 
        outmat[128*i+2*k+2][j] = (b1 * outmat[128*i+2*k+1][j]) + (b * outmat[128*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[256*i+2*k][j] = (b1 * outmat[256*i+2*k][j]) + (b * outmat[256*i+2*k+128][j]);
        outmat[256*i+2*k+128][j] = (b * outmat[256*i+2*k][j]) + (b1 * outmat[256*i+2*k+128][j]); 
      }
    }
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[256*i+2*k+1][j] = (b1 * outmat[256*i+2*k+1][j]) + (b * outmat[256*i+2*k+128+1][j]);
        outmat[256*i+2*k+128+1][j] = (b * outmat[256*i+2*k+1][j]) + (b1 * outmat[256*i+2*k+128+1][j]); 
      }
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:127] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[256*i+2*k+1][j] = (b * outmat[256*i+2*k+1][j]) + (b1 * outmat[256*i+2*k+2][j]); 
        outmat[256*i+2*k+2][j] = (b1 * outmat[256*i+2*k+1][j]) + (b * outmat[256*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:32] {
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[512*i+2*k][j] = (b1 * outmat[512*i+2*k][j]) + (b * outmat[512*i+2*k+256][j]);
        outmat[512*i+2*k+256][j] = (b * outmat[512*i+2*k][j]) + (b1 * outmat[512*i+2*k+256][j]); 
      }
    }
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[512*i+2*k+1][j] = (b1 * outmat[512*i+2*k+1][j]) + (b * outmat[512*i+2*k+256+1][j]);
        outmat[512*i+2*k+256+1][j] = (b * outmat[512*i+2*k+1][j]) + (b1 * outmat[512*i+2*k+256+1][j]); 
      }
    }
}

for uint32_t i = [0:32] {
    for uint32_t k = [0:255] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[512*i+2*k+1][j] = (b * outmat[512*i+2*k+1][j]) + (b1 * outmat[512*i+2*k+2][j]); 
        outmat[512*i+2*k+2][j] = (b1 * outmat[512*i+2*k+1][j]) + (b * outmat[512*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[1024*i+2*k][j] = (b1 * outmat[1024*i+2*k][j]) + (b * outmat[1024*i+2*k+512][j]);
        outmat[1024*i+2*k+512][j] = (b * outmat[1024*i+2*k][j]) + (b1 * outmat[1024*i+2*k+512][j]); 
      }
    }
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[1024*i+2*k+1][j] = (b1 * outmat[1024*i+2*k+1][j]) + (b * outmat[1024*i+2*k+512+1][j]);
        outmat[1024*i+2*k+512+1][j] = (b * outmat[1024*i+2*k+1][j]) + (b1 * outmat[1024*i+2*k+512+1][j]); 
      }
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:511] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[1024*i+2*k+1][j] = (b * outmat[1024*i+2*k+1][j]) + (b1 * outmat[1024*i+2*k+2][j]); 
        outmat[1024*i+2*k+2][j] = (b1 * outmat[1024*i+2*k+1][j]) + (b * outmat[1024*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[2048*i+2*k][j] = (b1 * outmat[2048*i+2*k][j]) + (b * outmat[2048*i+2*k+1024][j]);
        outmat[2048*i+2*k+1024][j] = (b * outmat[2048*i+2*k][j]) + (b1 * outmat[2048*i+2*k+1024][j]); 
      }
    }
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[2048*i+2*k+1][j] = (b1 * outmat[2048*i+2*k+1][j]) + (b * outmat[2048*i+2*k+1024+1][j]);
        outmat[2048*i+2*k+1024+1][j] = (b * outmat[2048*i+2*k+1][j]) + (b1 * outmat[2048*i+2*k+1024+1][j]); 
      }
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:1023] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[2048*i+2*k+1][j] = (b * outmat[2048*i+2*k+1][j]) + (b1 * outmat[2048*i+2*k+2][j]); 
        outmat[2048*i+2*k+2][j] = (b1 * outmat[2048*i+2*k+1][j]) + (b * outmat[2048*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k][j] = (b1 * outmat[4096*i+2*k][j]) + (b * outmat[4096*i+2*k+2048][j]);
        outmat[4096*i+2*k+2048][j] = (b * outmat[4096*i+2*k][j]) + (b1 * outmat[4096*i+2*k+2048][j]); 
      }
    }
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k+1][j] = (b1 * outmat[4096*i+2*k+1][j]) + (b * outmat[4096*i+2*k+2048+1][j]);
        outmat[4096*i+2*k+2048+1][j] = (b * outmat[4096*i+2*k+1][j]) + (b1 * outmat[4096*i+2*k+2048+1][j]); 
      }
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:2047] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k+1][j] = (b * outmat[4096*i+2*k+1][j]) + (b1 * outmat[4096*i+2*k+2][j]); 
        outmat[4096*i+2*k+2][j] = (b1 * outmat[4096*i+2*k+1][j]) + (b * outmat[4096*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:2] {
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k][j] = (b1 * outmat[8192*i+2*k][j]) + (b * outmat[8192*i+2*k+4096][j]);
        outmat[8192*i+2*k+4096][j] = (b * outmat[8192*i+2*k][j]) + (b1 * outmat[8192*i+2*k+4096][j]); 
      }
    }
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k+1][j] = (b1 * outmat[8192*i+2*k+1][j]) + (b * outmat[8192*i+2*k+4096+1][j]);
        outmat[8192*i+2*k+4096+1][j] = (b * outmat[8192*i+2*k+1][j]) + (b1 * outmat[8192*i+2*k+4096+1][j]); 
      }
    }
}

for uint32_t i = [0:2] {
    for uint32_t k = [0:4095] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k+1][j] = (b * outmat[8192*i+2*k+1][j]) + (b1 * outmat[8192*i+2*k+2][j]); 
        outmat[8192*i+2*k+2][j] = (b1 * outmat[8192*i+2*k+1][j]) + (b * outmat[8192*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [1:15444] {
  for uint32_t j = [14:24] {
    outmat[i][j] = outmat[i][2]*outmat[i-1][j] + ((1-outmat[i][2]) *outmat[i][j]); 
  }
}

for uint32_t i = [0:15444] {
  dots[i] = 0;
  for uint32_t j = [4:14] {
    dots[i] = dots[i] + (outmat[i][j] * outmat[i][j+10]);
  }
  dots[i] = outmat[i][3] - dots[i];
}  

for uint32_t i = [0:15444] {
  for uint32_t j = [14:24] {
    temp[j-14] = outmat[i][j];
    outmat[i][j] = outmat[i][2] * dots[i] * outmat[i][j-10] + ((1-outmat[i][2]) *outmat[i][j]);
  }
  for uint32_t j = [4:14] {
    outmat[i][j] = outmat[i][2] * dots[i] * temp[j-4] + ((1-outmat[i][2]) *outmat[i][j]);
  }
}
public uint32_t t;
for uint32_t i = [941:16384] {
  t = 16384 - i;
  for uint32_t j = [14:24] {
    outmat[t][j] = outmat[t][j] + (outmat[t+1][2]*outmat[t+1][j]) + ((1-outmat[t+1][2])*outmat[t][j]);
  }  
}

for uint32_t i = [0:8192] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[2*i][j] = (b * outmat[2*i][j]) + (b1 * outmat[2*i+1][j]); 
      outmat[2*i+1][j] = (b1 * outmat[2*i][j]) + (b * outmat[2*i+1][j]);
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[4*i][j] = (b * outmat[4*i][j]) + (b1 * outmat[4*i+2][j]); 
      outmat[4*i+2][j] = (b1 * outmat[4*i][j]) + (b * outmat[4*i+2][j]);
    }  
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      outmat[4*i+1][j] = (b * outmat[4*i+1][j]) + (b1 * outmat[4*i+3][j]); 
      outmat[4*i+3][j] = (b1 * outmat[4*i+1][j]) + (b * outmat[4*i+3][j]);      
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24]  {
      outmat[4*i+2][j] = (b1 * outmat[4*i+1][j]) + (b * outmat[4*i+2][j]);
      outmat[4*i+1][j] = (b * outmat[4*i+1][j]) + (b1 * outmat[4*i+2][j]); 
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:2] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2*k][j] = (b1 * outmat[8*i+2*k][j]) + (b * outmat[8*i+4+2*k][j]);
        outmat[8*i+4+2*k][j] = (b * outmat[8*i+2*k][j]) + (b1 * outmat[8*i+4+2*k][j]); 
      }
    }
    for uint32_t k = [0:2]  {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2*k+1][j] = (b1 * outmat[8*i+2*k+1][j]) + (b * outmat[8*i+4+2*k+1][j]);
        outmat[8*i+4+2*k+1][j] = (b * outmat[8*i+2*k+1][j]) + (b1 * outmat[8*i+4+2*k+1][j]); 
      }
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:3] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8*i+2+2*k][j] = (b1 * outmat[8*i+1+2*k][j]) + (b * outmat[8*i+2+2*k][j]);
        outmat[8*i+1+2*k][j] = (b * outmat[8*i+1+2*k][j]) + (b1 * outmat[8*i+2+2*k][j]); 
      }  
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[16*i+2*k][j] = (b1 * outmat[16*i+2*k][j]) + (b * outmat[16*i+2*k+8][j]);
        outmat[16*i+2*k+8][j] = (b * outmat[16*i+2*k][j]) + (b1 * outmat[16*i+2*k+8][j]); 
      }
    }
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[16*i+2*k+1][j] = (b1 * outmat[16*i+2*k+1][j]) + (b * outmat[16*i+2*k+8+1][j]);
        outmat[16*i+2*k+8+1][j] = (b * outmat[16*i+2*k+1][j]) + (b1 * outmat[16*i+2*k+8+1][j]); 
      }
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:7] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[16*i+2*k+1][j] = (b * outmat[16*i+2*k+1][j]) + (b1 * outmat[16*i+2*k+2][j]); 
        outmat[16*i+2*k+2][j] = (b1 * outmat[16*i+2*k+1][j]) + (b * outmat[16*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[32*i+2*k][j] = (b1 * outmat[32*i+2*k][j]) + (b * outmat[32*i+2*k+16][j]);
        outmat[32*i+2*k+16][j] = (b * outmat[32*i+2*k][j]) + (b1 * outmat[32*i+2*k+16][j]); 
      }
    }
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[32*i+2*k+1][j] = (b1 * outmat[32*i+2*k+1][j]) + (b * outmat[32*i+2*k+16+1][j]);
        outmat[32*i+2*k+16+1][j] = (b * outmat[32*i+2*k+1][j]) + (b1 * outmat[32*i+2*k+16+1][j]); 
      }
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:15] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[32*i+2*k+1][j] = (b * outmat[32*i+2*k+1][j]) + (b1 * outmat[32*i+2*k+2][j]); 
        outmat[32*i+2*k+2][j] = (b1 * outmat[32*i+2*k+1][j]) + (b * outmat[32*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[64*i+2*k][j] = (b1 * outmat[64*i+2*k][j]) + (b * outmat[64*i+2*k+32][j]);
        outmat[64*i+2*k+32][j] = (b * outmat[64*i+2*k][j]) + (b1 * outmat[64*i+2*k+32][j]); 
      }
    }
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[64*i+2*k+1][j] = (b1 * outmat[64*i+2*k+1][j]) + (b * outmat[64*i+2*k+32+1][j]);
        outmat[64*i+2*k+32+1][j] = (b * outmat[64*i+2*k+1][j]) + (b1 * outmat[64*i+2*k+32+1][j]); 
      }
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:31] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[64*i+2*k+1][j] = (b * outmat[64*i+2*k+1][j]) + (b1 * outmat[64*i+2*k+2][j]); 
        outmat[64*i+2*k+2][j] = (b1 * outmat[64*i+2*k+1][j]) + (b * outmat[64*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[128*i+2*k][j] = (b1 * outmat[128*i+2*k][j]) + (b * outmat[128*i+2*k+64][j]);
        outmat[128*i+2*k+64][j] = (b * outmat[128*i+2*k][j]) + (b1 * outmat[128*i+2*k+64][j]); 
      }
    }
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[128*i+2*k+1][j] = (b1 * outmat[128*i+2*k+1][j]) + (b * outmat[128*i+2*k+64+1][j]);
        outmat[128*i+2*k+64+1][j] = (b * outmat[128*i+2*k+1][j]) + (b1 * outmat[128*i+2*k+64+1][j]); 
      }
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:63] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[128*i+2*k+1][j] = (b * outmat[128*i+2*k+1][j]) + (b1 * outmat[128*i+2*k+2][j]); 
        outmat[128*i+2*k+2][j] = (b1 * outmat[128*i+2*k+1][j]) + (b * outmat[128*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[256*i+2*k][j] = (b1 * outmat[256*i+2*k][j]) + (b * outmat[256*i+2*k+128][j]);
        outmat[256*i+2*k+128][j] = (b * outmat[256*i+2*k][j]) + (b1 * outmat[256*i+2*k+128][j]); 
      }
    }
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[256*i+2*k+1][j] = (b1 * outmat[256*i+2*k+1][j]) + (b * outmat[256*i+2*k+128+1][j]);
        outmat[256*i+2*k+128+1][j] = (b * outmat[256*i+2*k+1][j]) + (b1 * outmat[256*i+2*k+128+1][j]); 
      }
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:127] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[256*i+2*k+1][j] = (b * outmat[256*i+2*k+1][j]) + (b1 * outmat[256*i+2*k+2][j]); 
        outmat[256*i+2*k+2][j] = (b1 * outmat[256*i+2*k+1][j]) + (b * outmat[256*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:32] {
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[512*i+2*k][j] = (b1 * outmat[512*i+2*k][j]) + (b * outmat[512*i+2*k+256][j]);
        outmat[512*i+2*k+256][j] = (b * outmat[512*i+2*k][j]) + (b1 * outmat[512*i+2*k+256][j]); 
      }
    }
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[512*i+2*k+1][j] = (b1 * outmat[512*i+2*k+1][j]) + (b * outmat[512*i+2*k+256+1][j]);
        outmat[512*i+2*k+256+1][j] = (b * outmat[512*i+2*k+1][j]) + (b1 * outmat[512*i+2*k+256+1][j]); 
      }
    }
}

for uint32_t i = [0:32] {
    for uint32_t k = [0:255] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[512*i+2*k+1][j] = (b * outmat[512*i+2*k+1][j]) + (b1 * outmat[512*i+2*k+2][j]); 
        outmat[512*i+2*k+2][j] = (b1 * outmat[512*i+2*k+1][j]) + (b * outmat[512*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[1024*i+2*k][j] = (b1 * outmat[1024*i+2*k][j]) + (b * outmat[1024*i+2*k+512][j]);
        outmat[1024*i+2*k+512][j] = (b * outmat[1024*i+2*k][j]) + (b1 * outmat[1024*i+2*k+512][j]); 
      }
    }
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[1024*i+2*k+1][j] = (b1 * outmat[1024*i+2*k+1][j]) + (b * outmat[1024*i+2*k+512+1][j]);
        outmat[1024*i+2*k+512+1][j] = (b * outmat[1024*i+2*k+1][j]) + (b1 * outmat[1024*i+2*k+512+1][j]); 
      }
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:511] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[1024*i+2*k+1][j] = (b * outmat[1024*i+2*k+1][j]) + (b1 * outmat[1024*i+2*k+2][j]); 
        outmat[1024*i+2*k+2][j] = (b1 * outmat[1024*i+2*k+1][j]) + (b * outmat[1024*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[2048*i+2*k][j] = (b1 * outmat[2048*i+2*k][j]) + (b * outmat[2048*i+2*k+1024][j]);
        outmat[2048*i+2*k+1024][j] = (b * outmat[2048*i+2*k][j]) + (b1 * outmat[2048*i+2*k+1024][j]); 
      }
    }
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        outmat[2048*i+2*k+1][j] = (b1 * outmat[2048*i+2*k+1][j]) + (b * outmat[2048*i+2*k+1024+1][j]);
        outmat[2048*i+2*k+1024+1][j] = (b * outmat[2048*i+2*k+1][j]) + (b1 * outmat[2048*i+2*k+1024+1][j]); 
      }
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:1023] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[2048*i+2*k+1][j] = (b * outmat[2048*i+2*k+1][j]) + (b1 * outmat[2048*i+2*k+2][j]); 
        outmat[2048*i+2*k+2][j] = (b1 * outmat[2048*i+2*k+1][j]) + (b * outmat[2048*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k][j] = (b1 * outmat[4096*i+2*k][j]) + (b * outmat[4096*i+2*k+2048][j]);
        outmat[4096*i+2*k+2048][j] = (b * outmat[4096*i+2*k][j]) + (b1 * outmat[4096*i+2*k+2048][j]); 
      }
    }
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k+1][j] = (b1 * outmat[4096*i+2*k+1][j]) + (b * outmat[4096*i+2*k+2048+1][j]);
        outmat[4096*i+2*k+2048+1][j] = (b * outmat[4096*i+2*k+1][j]) + (b1 * outmat[4096*i+2*k+2048+1][j]); 
      }
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:2047] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[4096*i+2*k+1][j] = (b * outmat[4096*i+2*k+1][j]) + (b1 * outmat[4096*i+2*k+2][j]); 
        outmat[4096*i+2*k+2][j] = (b1 * outmat[4096*i+2*k+1][j]) + (b * outmat[4096*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:2] {
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k][j] = (b1 * outmat[8192*i+2*k][j]) + (b * outmat[8192*i+2*k+4096][j]);
        outmat[8192*i+2*k+4096][j] = (b * outmat[8192*i+2*k][j]) + (b1 * outmat[8192*i+2*k+4096][j]); 
      }
    }
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k+1][j] = (b1 * outmat[8192*i+2*k+1][j]) + (b * outmat[8192*i+2*k+4096+1][j]);
        outmat[8192*i+2*k+4096+1][j] = (b * outmat[8192*i+2*k+1][j]) + (b1 * outmat[8192*i+2*k+4096+1][j]); 
      }
    }
}

for uint32_t i = [0:2] {
    for uint32_t k = [0:4095] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        outmat[8192*i+2*k+1][j] = (b * outmat[8192*i+2*k+1][j]) + (b1 * outmat[8192*i+2*k+2][j]); 
        outmat[8192*i+2*k+2][j] = (b1 * outmat[8192*i+2*k+1][j]) + (b * outmat[8192*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [41:16384] {
  t = 16384 - i;
  for uint32_t j = [4:14] {
    outmat[t][j] = outmat[t][j] + (outmat[t+1][2]*outmat[t+1][j]) + ((1-outmat[t+1][2])*outmat[t][j]);
  }  
}

output(1);


