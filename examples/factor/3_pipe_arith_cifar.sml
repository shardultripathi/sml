uint32_t outmp[16384][24];
uint32_t boolarr[200000];
uint32_t temp[10];
uint32_t dots[15444];
public uint32_t boolidx;
uint32_t Routmp[16384][24];
uint32_t IRoutmp[16384][24];

uint32_t b;
uint32_t b1;
boolidx = 0;
public uint32_t t;
uint32_t cas;

for uint32_t i = [0:200000] {
  boolarr[i] = input1(1);
}

for uint32_t i = [0:16384] {
  for uint32_t j = [0:24] {
    Routmp[i][j] = input1(IRoutmp[i][j]);
  }
}

for uint32_t i = [0:16384] {
  for uint32_t j = [0:24] {
    outmp[i][j] = outmp[i][j] - Routmp[i][j];
  }
}

for uint32_t i = [0:8192] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      cas = outmp[2*i][j];
      outmp[2*i][j] = (b * outmp[2*i][j]) + (b1 * outmp[2*i+1][j]); 
      outmp[2*i+1][j] = (b1 * cas) + (b * outmp[2*i+1][j]);
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      cas = outmp[4*i][j];
      outmp[4*i][j] = (b * outmp[4*i][j]) + (b1 * outmp[4*i+2][j]); 
      outmp[4*i+2][j] = (b1 *cas) + (b * outmp[4*i+2][j]);
    }  
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24] {
      cas = outmp[4*i+1][j];
      outmp[4*i+1][j] = (b * outmp[4*i+1][j]) + (b1 * outmp[4*i+3][j]); 
      outmp[4*i+3][j] = (b1 * cas) + (b * outmp[4*i+3][j]);      
    }  
}

for uint32_t i = [0:4096] {
    b = boolarr[boolidx];
    b1 = 1 - b;
    boolidx = boolidx + 1;
    for uint32_t j = [0:24]  {
      cas = outmp[4*i+2][j];
      outmp[4*i+2][j] = (b1 * outmp[4*i+1][j]) + (b * outmp[4*i+2][j]);
      outmp[4*i+1][j] = (b * outmp[4*i+1][j]) + (b1 * cas); 
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:2] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[8*i+2*k][j];
        outmp[8*i+2*k][j] = (b1 * outmp[8*i+2*k][j]) + (b * outmp[8*i+4+2*k][j]);
        outmp[8*i+4+2*k][j] = (b * cas) + (b1 * outmp[8*i+4+2*k][j]); 
      }
    }
    for uint32_t k = [0:2]  {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[8*i+2*k+1][j];
        outmp[8*i+2*k+1][j] = (b1 * outmp[8*i+2*k+1][j]) + (b * outmp[8*i+4+2*k+1][j]);
        outmp[8*i+4+2*k+1][j] = (b * cas) + (b1 * outmp[8*i+4+2*k+1][j]); 
      }
    }  
}

for uint32_t i = [0:2048] {
    for uint32_t k = [0:3] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[8*i+2+2*k][j];
        outmp[8*i+2+2*k][j] = (b1 * outmp[8*i+1+2*k][j]) + (b * outmp[8*i+2+2*k][j]);
        outmp[8*i+1+2*k][j] = (b * outmp[8*i+1+2*k][j]) + (b1 * cas); 
      }  
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[16*i+2*k][j];
        outmp[16*i+2*k][j] = (b1 * outmp[16*i+2*k][j]) + (b * outmp[16*i+2*k+8][j]);
        outmp[16*i+2*k+8][j] = (b * cas) + (b1 * outmp[16*i+2*k+8][j]); 
      }
    }
    for uint32_t k = [0:4] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[16*i+2*k+1][j];
        outmp[16*i+2*k+1][j] = (b1 * outmp[16*i+2*k+1][j]) + (b * outmp[16*i+2*k+8+1][j]);
        outmp[16*i+2*k+8+1][j] = (b * cas) + (b1 * outmp[16*i+2*k+8+1][j]); 
      }
    }
}

for uint32_t i = [0:1024] {
    for uint32_t k = [0:7] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas =  outmp[16*i+2*k+1][j];
        outmp[16*i+2*k+1][j] = (b * outmp[16*i+2*k+1][j]) + (b1 * outmp[16*i+2*k+2][j]); 
        outmp[16*i+2*k+2][j] = (b1 * cas) + (b * outmp[16*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[32*i+2*k][j];
        outmp[32*i+2*k][j] = (b1 * outmp[32*i+2*k][j]) + (b * outmp[32*i+2*k+16][j]);
        outmp[32*i+2*k+16][j] = (b * cas) + (b1 * outmp[32*i+2*k+16][j]); 
      }
    }
    for uint32_t k = [0:8] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[32*i+2*k+1][j];
        outmp[32*i+2*k+1][j] = (b1 * outmp[32*i+2*k+1][j]) + (b * outmp[32*i+2*k+16+1][j]);
        outmp[32*i+2*k+16+1][j] = (b * cas) + (b1 * outmp[32*i+2*k+16+1][j]); 
      }
    }
}

for uint32_t i = [0:512] {
    for uint32_t k = [0:15] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[32*i+2*k+1][j];
        outmp[32*i+2*k+1][j] = (b * outmp[32*i+2*k+1][j]) + (b1 * outmp[32*i+2*k+2][j]); 
        outmp[32*i+2*k+2][j] = (b1 * cas) + (b * outmp[32*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[64*i+2*k][j];
        outmp[64*i+2*k][j] = (b1 * outmp[64*i+2*k][j]) + (b * outmp[64*i+2*k+32][j]);
        outmp[64*i+2*k+32][j] = (b * cas) + (b1 * outmp[64*i+2*k+32][j]); 
      }
    }
    for uint32_t k = [0:16] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[64*i+2*k+1][j];
        outmp[64*i+2*k+1][j] = (b1 * outmp[64*i+2*k+1][j]) + (b * outmp[64*i+2*k+32+1][j]);
        outmp[64*i+2*k+32+1][j] = (b * cas) + (b1 * outmp[64*i+2*k+32+1][j]); 
      }
    }
}

for uint32_t i = [0:256] {
    for uint32_t k = [0:31] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[64*i+2*k+1][j];
        outmp[64*i+2*k+1][j] = (b * outmp[64*i+2*k+1][j]) + (b1 * outmp[64*i+2*k+2][j]); 
        outmp[64*i+2*k+2][j] = (b1 * cas) + (b * outmp[64*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[128*i+2*k][j];
        outmp[128*i+2*k][j] = (b1 * outmp[128*i+2*k][j]) + (b * outmp[128*i+2*k+64][j]);
        outmp[128*i+2*k+64][j] = (b * cas) + (b1 * outmp[128*i+2*k+64][j]); 
      }
    }
    for uint32_t k = [0:32] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[128*i+2*k+1][j];
        outmp[128*i+2*k+1][j] = (b1 * outmp[128*i+2*k+1][j]) + (b * outmp[128*i+2*k+64+1][j]);
        outmp[128*i+2*k+64+1][j] = (b * cas) + (b1 * outmp[128*i+2*k+64+1][j]); 
      }
    }
}

for uint32_t i = [0:128] {
    for uint32_t k = [0:63] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[128*i+2*k+1][j];
        outmp[128*i+2*k+1][j] = (b * outmp[128*i+2*k+1][j]) + (b1 * outmp[128*i+2*k+2][j]); 
        outmp[128*i+2*k+2][j] = (b1 *cas) + (b * outmp[128*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas =  outmp[256*i+2*k][j];
        outmp[256*i+2*k][j] = (b1 * outmp[256*i+2*k][j]) + (b * outmp[256*i+2*k+128][j]);
        outmp[256*i+2*k+128][j] = (b *cas) + (b1 * outmp[256*i+2*k+128][j]); 
      }
    }
    for uint32_t k = [0:64] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[256*i+2*k+1][j];
        outmp[256*i+2*k+1][j] = (b1 * outmp[256*i+2*k+1][j]) + (b * outmp[256*i+2*k+128+1][j]);
        outmp[256*i+2*k+128+1][j] = (b * cas) + (b1 * outmp[256*i+2*k+128+1][j]); 
      }
    }
}

for uint32_t i = [0:64] {
    for uint32_t k = [0:127] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[256*i+2*k+1][j];
        outmp[256*i+2*k+1][j] = (b * outmp[256*i+2*k+1][j]) + (b1 * outmp[256*i+2*k+2][j]); 
        outmp[256*i+2*k+2][j] = (b1 * cas) + (b * outmp[256*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:32] {
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[512*i+2*k][j];
        outmp[512*i+2*k][j] = (b1 * outmp[512*i+2*k][j]) + (b * outmp[512*i+2*k+256][j]);
        outmp[512*i+2*k+256][j] = (b * cas) + (b1 * outmp[512*i+2*k+256][j]); 
      }
    }
    for uint32_t k = [0:128] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[512*i+2*k+1][j];
        outmp[512*i+2*k+1][j] = (b1 * outmp[512*i+2*k+1][j]) + (b * outmp[512*i+2*k+256+1][j]);
        outmp[512*i+2*k+256+1][j] = (b * cas) + (b1 * outmp[512*i+2*k+256+1][j]); 
      }
    }
}

for uint32_t i = [0:32] {
    for uint32_t k = [0:255] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[512*i+2*k+1][j];
        outmp[512*i+2*k+1][j] = (b * outmp[512*i+2*k+1][j]) + (b1 * outmp[512*i+2*k+2][j]); 
        outmp[512*i+2*k+2][j] = (b1 * cas) + (b * outmp[512*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[1024*i+2*k][j];
        outmp[1024*i+2*k][j] = (b1 * outmp[1024*i+2*k][j]) + (b * outmp[1024*i+2*k+512][j]);
        outmp[1024*i+2*k+512][j] = (b * cas) + (b1 * outmp[1024*i+2*k+512][j]); 
      }
    }
    for uint32_t k = [0:256] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[1024*i+2*k+1][j];
        outmp[1024*i+2*k+1][j] = (b1 * outmp[1024*i+2*k+1][j]) + (b * outmp[1024*i+2*k+512+1][j]);
        outmp[1024*i+2*k+512+1][j] = (b * cas) + (b1 * outmp[1024*i+2*k+512+1][j]); 
      }
    }
}

for uint32_t i = [0:16] {
    for uint32_t k = [0:511] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[1024*i+2*k+1][j];
        outmp[1024*i+2*k+1][j] = (b * outmp[1024*i+2*k+1][j]) + (b1 * outmp[1024*i+2*k+2][j]); 
        outmp[1024*i+2*k+2][j] = (b1 * cas) + (b * outmp[1024*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas =  outmp[2048*i+2*k][j];
        outmp[2048*i+2*k][j] = (b1 * outmp[2048*i+2*k][j]) + (b * outmp[2048*i+2*k+1024][j]);
        outmp[2048*i+2*k+1024][j] = (b * cas) + (b1 * outmp[2048*i+2*k+1024][j]); 
      }
    }
    for uint32_t k = [0:512] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24]  {
        cas = outmp[2048*i+2*k+1][j];
        outmp[2048*i+2*k+1][j] = (b1 * outmp[2048*i+2*k+1][j]) + (b * outmp[2048*i+2*k+1024+1][j]);
        outmp[2048*i+2*k+1024+1][j] = (b * cas) + (b1 * outmp[2048*i+2*k+1024+1][j]); 
      }
    }
}

for uint32_t i = [0:8] {
    for uint32_t k = [0:1023] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[2048*i+2*k+1][j];
        outmp[2048*i+2*k+1][j] = (b * outmp[2048*i+2*k+1][j]) + (b1 * outmp[2048*i+2*k+2][j]); 
        outmp[2048*i+2*k+2][j] = (b1 * cas) + (b * outmp[2048*i+2*k+2][j]);
      }  
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[4096*i+2*k][j];
        outmp[4096*i+2*k][j] = (b1 * outmp[4096*i+2*k][j]) + (b * outmp[4096*i+2*k+2048][j]);
        outmp[4096*i+2*k+2048][j] = (b * cas) + (b1 * outmp[4096*i+2*k+2048][j]); 
      }
    }
    for uint32_t k = [0:1024] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[4096*i+2*k+1][j];
        outmp[4096*i+2*k+1][j] = (b1 * outmp[4096*i+2*k+1][j]) + (b * outmp[4096*i+2*k+2048+1][j]);
        outmp[4096*i+2*k+2048+1][j] = (b * cas) + (b1 * outmp[4096*i+2*k+2048+1][j]); 
      }
    }
}

for uint32_t i = [0:4] {
    for uint32_t k = [0:2047] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[4096*i+2*k+1][j];
        outmp[4096*i+2*k+1][j] = (b * outmp[4096*i+2*k+1][j]) + (b1 * outmp[4096*i+2*k+2][j]); 
        outmp[4096*i+2*k+2][j] = (b1 * cas) + (b * outmp[4096*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [0:2] {
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[8192*i+2*k][j];
        outmp[8192*i+2*k][j] = (b1 * outmp[8192*i+2*k][j]) + (b * outmp[8192*i+2*k+4096][j]);
        outmp[8192*i+2*k+4096][j] = (b * cas) + (b1 * outmp[8192*i+2*k+4096][j]); 
      }
    }
    for uint32_t k = [0:2048] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[8192*i+2*k+1][j];
        outmp[8192*i+2*k+1][j] = (b1 * outmp[8192*i+2*k+1][j]) + (b * outmp[8192*i+2*k+4096+1][j]);
        outmp[8192*i+2*k+4096+1][j] = (b * cas) + (b1 * outmp[8192*i+2*k+4096+1][j]); 
      }
    }
}

for uint32_t i = [0:2] {
    for uint32_t k = [0:4095] {
      b = boolarr[boolidx];
      b1 = 1 - b;
      boolidx = boolidx + 1;
      for uint32_t j = [0:24] {
        cas = outmp[8192*i+2*k+1][j];
        outmp[8192*i+2*k+1][j] = (b * outmp[8192*i+2*k+1][j]) + (b1 * outmp[8192*i+2*k+2][j]); 
        outmp[8192*i+2*k+2][j] = (b1 * cas) + (b * outmp[8192*i+2*k+2][j]);
      }  
    }
}


for uint32_t i = [41:16384] {
  t = 16384 - i;
  for uint32_t j = [4:14] {
    outmp[t][j] = outmp[t][j] + (outmp[t+1][2]*outmp[t+1][j]) + ((1-outmp[t+1][2])*outmp[t][j]);
  }  
}

output(1);


