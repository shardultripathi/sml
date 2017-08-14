uint32_t maxind;
uint32_t N;
uint32_t cnt;
uint32_t ii;
uint32_t jj;
uint32_t kk;
uint32_t ll;
uint32_t jjover;
uint32_t kkover;
uint32_t llover;
uint32_t mtmp;
uint32_t htmp;
uint32_t wtmp;
uint32_t maxval;
uint32_t tmp;
uint32_t tmp0;
uint32_t tmp1;
uint32_t Wc1[5][5][1][32];
uint32_t Wc2[5][5][32][64];
uint32_t Wf1[1][1][3136][1024];
uint32_t Wf2[1][1][1024][10];
uint32_t bc1[1][1][1][32];
uint32_t bc2[1][1][1][64];
uint32_t bf1[1][1][1][1024];
uint32_t bf2[1][1][1][10];
uint32_t x[1][1][1][784];
uint32_t ximg[1][28][28][1];
uint32_t hc11[1][28][28][32];
uint32_t hc12[1][28][28][32];
uint32_t hc13[1][28][28][32];
uint32_t hp1[1][14][14][32];
uint32_t hc21[1][14][14][64];
uint32_t hc22[1][14][14][64];
uint32_t hc23[1][14][14][64];
uint32_t hp2[1][7][7][64];
uint32_t ht2[1][1][1][3136];
uint32_t hf11[1][1][1][1024];
uint32_t hf12[1][1][1][1024];
uint32_t hf13[1][1][1][1024];
uint32_t hf21[1][1][1][10];
uint32_t hf22[1][1][1][10];

// load
for uint32_t i = [0:5] {
  for uint32_t j = [0:5] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:32] {
        Wc1[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:5] {
  for uint32_t j = [0:5] {
    for uint32_t k = [0:32] {
      for uint32_t l = [0:64] {
        Wc2[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:3136] {
      for uint32_t l = [0:1024] {
        Wf1[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1024] {
      for uint32_t l = [0:10] {
        Wf2[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:32] {
        bc1[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:64] {
        bc2[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:1024] {
        bf1[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:10] {
        bf2[i][j][k][l] = input2(1);
      }
    }
  }
}

// load
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:784] {
        x[i][j][k][l] = input1(1);
      }
    }
  }
}

// reshape
ii = 0;
jj = 0;
kk = 0;
ll = 0;
for uint32_t i = [0:1] {
  for uint32_t j = [0:28] {
    for uint32_t k = [0:28] {
      for uint32_t l = [0:1] {
        ximg[i ][j ][k ][l ] = x[ii][jj][kk][ll];
        ll = ll+1;
        llover = (ll == 784) ? 1 : 0;
        ll =  (llover == 1) ? 0    : ll;
        kk =  (llover == 1) ? kk+1 : kk;
        kkover = (kk == 1) ? 1 : 0;
        kk =  (kkover == 1) ? 0    : kk;
        jj =  (kkover == 1) ? jj+1 : jj;
        jjover = (jj == 1) ? 1 : 0;
        jj =  (jjover == 1) ? 0    : jj;
        ii =  (jjover == 1) ? ii+1 : ii;
      }
    }
  }
}

// conv
uint32_t ximgBuf[1][32][32][1];
uint32_t hc11Buf[1][28][28][32][25];
for uint32_t i = [0:1] {
  for uint32_t j = [0:28] {
    for uint32_t k = [0:28] {
      for uint32_t l = [0:1] {
        ximg[i][j][k][l] = (ximg[i][j][k][l]<2147483648) ? (ximg[i][j][k][l] >> 15) : (((ximg[i][j][k][l] ^ 4294967295) >> 15) ^ 4294967295);
      }
    }
  }
}
for uint32_t i = [0:5] {
  for uint32_t j = [0:5] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:32] {
        Wc1[i][j][k][l] = (Wc1[i][j][k][l]<2147483648) ? (Wc1[i][j][k][l] >> 15) : (((Wc1[i][j][k][l] ^ 4294967295) >> 15) ^ 4294967295);
      }
    }
  }
}
for uint32_t n = [0:1] {
  htmp = 0;
  for uint32_t h = [0:32] {
    wtmp = 0;
    for uint32_t w = [0:32] {
      for uint32_t ci = [0:1] {
        ximgBuf[n][h][w][ci] = (htmp-2<28 && wtmp-2<28) ? ximg[n][h-2][w-2][ci] : 0;
      }
      wtmp = wtmp+1;
    }
    htmp = htmp+1;
  }
}
for uint32_t n = [0:1] {
  for uint32_t h = [0:28] {
    for uint32_t w = [0:28] {
      for uint32_t co = [0:32] {
        cnt = 0;
        for uint32_t hf = [0:5] {
          for uint32_t wf = [0:5] {
            for uint32_t ci = [0:1] {
              hc11Buf[n][h][w][co][cnt] = ximgBuf[n][h+hf][w+wf][ci] * Wc1[hf][wf][ci][co];
              cnt = cnt+1;
            }
          }
        }
      }
    }
  }
}
for uint32_t n = [0:1] {
  for uint32_t h = [0:28] {
    for uint32_t w = [0:28] {
      for uint32_t co = [0:32] {
        N = 25;
        for uint32_t a = [0:5] {
          mtmp = 0;
          for uint32_t m = [0:25] {
            hc11Buf[n][h][w][co][mtmp] = (mtmp<(N>>1)) ? (((hc11Buf[n][h][w][co][2*mtmp]) + (hc11Buf[n][h][w][co][2*mtmp+1]))<2147483648) ? (((hc11Buf[n][h][w][co][2*mtmp]) + (hc11Buf[n][h][w][co][2*mtmp+1])) >> 1) : (((((hc11Buf[n][h][w][co][2*mtmp]) + (hc11Buf[n][h][w][co][2*mtmp+1])) ^ 4294967295) >> 1) ^ 4294967295) : hc11Buf[n][h][w][co][mtmp];
            mtmp = mtmp+1;
          }
	  // (N%2==1)
          hc11Buf[n][h][w][co][N>>1] = (N&1==1) ? (hc11Buf[n][h][w][co][N-1]<2147483648) ? (hc11Buf[n][h][w][co][N-1] >> 1) : (((hc11Buf[n][h][w][co][N-1] ^ 4294967295) >> 1) ^ 4294967295) : 0;
          N = (N+1)>>1;
        }
        hc11[n][h][w][co] = hc11Buf[n][h][w][co][0];
      }
    }
  }
}

// add
for uint32_t i = [0:1] {
  for uint32_t j = [0:28] {
    for uint32_t k = [0:28] {
      for uint32_t l = [0:32] {
        tmp0 = hc11[i][j][k][l];
        tmp1 = (bc1[0][0][0][l]<2147483648) ? (bc1[0][0][0][l] >> 7) : (((bc1[0][0][0][l] ^ 4294967295) >> 7) ^ 4294967295);
        hc12[i][j][k][l] = tmp0+tmp1;
        hc12[i][j][k][l] = hc12[i][j][k][l];
      }
    }
  }
}

// relu
for uint32_t i = [0:1] {
  for uint32_t j = [0:28] {
    for uint32_t k = [0:28] {
      for uint32_t l = [0:32] {
        hc13[i][j][k][l] = (hc12[i][j][k][l] < 2147483648) ? hc12[i][j][k][l] : 0;
      }
    }
  }
}

// maxpool
for uint32_t i = [0:1] {
  for uint32_t j = [0:14] {
    for uint32_t k = [0:14] {
      for uint32_t l = [0:32] {
        tmp0 = (hc13[i][2*j  ][2*k  ][l]<2147483648) ? (hc13[i][2*j  ][2*k+1][l]<2147483648) ? (hc13[i][2*j  ][2*k  ][l]>hc13[i][2*j  ][2*k+1][l])?hc13[i][2*j  ][2*k  ][l]:hc13[i][2*j  ][2*k+1][l] : hc13[i][2*j  ][2*k  ][l] : (hc13[i][2*j  ][2*k+1][l]<2147483648) ? hc13[i][2*j  ][2*k+1][l] : (hc13[i][2*j  ][2*k  ][l]>hc13[i][2*j  ][2*k+1][l])?hc13[i][2*j  ][2*k+1][l]:hc13[i][2*j  ][2*k  ][l];
        tmp1 = (hc13[i][2*j+1][2*k  ][l]<2147483648) ? (hc13[i][2*j+1][2*k+1][l]<2147483648) ? (hc13[i][2*j+1][2*k  ][l]>hc13[i][2*j+1][2*k+1][l])?hc13[i][2*j+1][2*k  ][l]:hc13[i][2*j+1][2*k+1][l] : hc13[i][2*j+1][2*k  ][l] : (hc13[i][2*j+1][2*k+1][l]<2147483648) ? hc13[i][2*j+1][2*k+1][l] : (hc13[i][2*j+1][2*k  ][l]>hc13[i][2*j+1][2*k+1][l])?hc13[i][2*j+1][2*k+1][l]:hc13[i][2*j+1][2*k  ][l];
        hp1[i][  j  ][  k  ][l] = (tmp0<2147483648) ? (tmp1<2147483648) ? (tmp0>tmp1)?tmp0:tmp1 : tmp0 : (tmp1<2147483648) ? tmp1 : (tmp0>tmp1)?tmp1:tmp0;
      }
    }
  }
}

// conv
uint32_t hp1Buf[1][18][18][32];
uint32_t hc21Buf[1][14][14][64][800];
for uint32_t i = [0:1] {
  for uint32_t j = [0:14] {
    for uint32_t k = [0:14] {
      for uint32_t l = [0:32] {
        hp1[i][j][k][l] = (hp1[i][j][k][l]<2147483648) ? (hp1[i][j][k][l] >> 15) : (((hp1[i][j][k][l] ^ 4294967295) >> 15) ^ 4294967295);
      }
    }
  }
}
for uint32_t i = [0:5] {
  for uint32_t j = [0:5] {
    for uint32_t k = [0:32] {
      for uint32_t l = [0:64] {
        Wc2[i][j][k][l] = (Wc2[i][j][k][l]<2147483648) ? (Wc2[i][j][k][l] >> 15) : (((Wc2[i][j][k][l] ^ 4294967295) >> 15) ^ 4294967295);
      }
    }
  }
}
for uint32_t n = [0:1] {
  htmp = 0;
  for uint32_t h = [0:18] {
    wtmp = 0;
    for uint32_t w = [0:18] {
      for uint32_t ci = [0:32] {
        hp1Buf[n][h][w][ci] = (htmp-2<14 && wtmp-2<14) ? hp1[n][h-2][w-2][ci] : 0;
      }
      wtmp = wtmp+1;
    }
    htmp = htmp+1;
  }
}
for uint32_t n = [0:1] {
  for uint32_t h = [0:14] {
    for uint32_t w = [0:14] {
      for uint32_t co = [0:64] {
        cnt = 0;
        for uint32_t hf = [0:5] {
          for uint32_t wf = [0:5] {
            for uint32_t ci = [0:32] {
              hc21Buf[n][h][w][co][cnt] = hp1Buf[n][h+hf][w+wf][ci] * Wc2[hf][wf][ci][co];
              cnt = cnt+1;
            }
          }
        }
      }
    }
  }
}
for uint32_t n = [0:1] {
  for uint32_t h = [0:14] {
    for uint32_t w = [0:14] {
      for uint32_t co = [0:64] {
        N = 800;
        for uint32_t a = [0:2] {
          mtmp = 0;
          for uint32_t m = [0:800] {
            hc21Buf[n][h][w][co][mtmp] = (mtmp<(N>>1)) ? (((hc21Buf[n][h][w][co][2*mtmp]) + (hc21Buf[n][h][w][co][2*mtmp+1]))<2147483648) ? (((hc21Buf[n][h][w][co][2*mtmp]) + (hc21Buf[n][h][w][co][2*mtmp+1])) >> 1) : (((((hc21Buf[n][h][w][co][2*mtmp]) + (hc21Buf[n][h][w][co][2*mtmp+1])) ^ 4294967295) >> 1) ^ 4294967295) : hc21Buf[n][h][w][co][mtmp];
            mtmp = mtmp+1;
          }
	  // (N%2==1)
          hc21Buf[n][h][w][co][N>>1] = (N&1==1) ? (hc21Buf[n][h][w][co][N-1]<2147483648) ? (hc21Buf[n][h][w][co][N-1] >> 1) : (((hc21Buf[n][h][w][co][N-1] ^ 4294967295) >> 1) ^ 4294967295) : 0;
          N = (N+1)>>1;
        }
        for uint32_t a = [0:8] {
          mtmp = 0;
          for uint32_t m = [0:800] {
            hc21Buf[n][h][w][co][mtmp] = (mtmp<(N>>1)) ? ((hc21Buf[n][h][w][co][2*mtmp]) + (hc21Buf[n][h][w][co][2*mtmp+1])) : hc21Buf[n][h][w][co][mtmp];
            mtmp = mtmp+1;
          }
	  // (N%2==1)
          hc21Buf[n][h][w][co][N>>1] = (N&1==1) ? hc21Buf[n][h][w][co][N-1] : 0;
          N = (N+1)>>1;
        }
        hc21[n][h][w][co] = hc21Buf[n][h][w][co][0];
      }
    }
  }
}

// add
for uint32_t i = [0:1] {
  for uint32_t j = [0:14] {
    for uint32_t k = [0:14] {
      for uint32_t l = [0:64] {
        tmp0 = hc21[i][j][k][l];
        tmp1 = (bc2[0][0][0][l]<2147483648) ? (bc2[0][0][0][l] >> 8) : (((bc2[0][0][0][l] ^ 4294967295) >> 8) ^ 4294967295);
        hc22[i][j][k][l] = tmp0+tmp1;
        hc22[i][j][k][l] = hc22[i][j][k][l];
      }
    }
  }
}

// relu
for uint32_t i = [0:1] {
  for uint32_t j = [0:14] {
    for uint32_t k = [0:14] {
      for uint32_t l = [0:64] {
        hc23[i][j][k][l] = (hc22[i][j][k][l] < 2147483648) ? hc22[i][j][k][l] : 0;
      }
    }
  }
}

// maxpool
for uint32_t i = [0:1] {
  for uint32_t j = [0:7] {
    for uint32_t k = [0:7] {
      for uint32_t l = [0:64] {
        tmp0 = (hc23[i][2*j  ][2*k  ][l]<2147483648) ? (hc23[i][2*j  ][2*k+1][l]<2147483648) ? (hc23[i][2*j  ][2*k  ][l]>hc23[i][2*j  ][2*k+1][l])?hc23[i][2*j  ][2*k  ][l]:hc23[i][2*j  ][2*k+1][l] : hc23[i][2*j  ][2*k  ][l] : (hc23[i][2*j  ][2*k+1][l]<2147483648) ? hc23[i][2*j  ][2*k+1][l] : (hc23[i][2*j  ][2*k  ][l]>hc23[i][2*j  ][2*k+1][l])?hc23[i][2*j  ][2*k+1][l]:hc23[i][2*j  ][2*k  ][l];
        tmp1 = (hc23[i][2*j+1][2*k  ][l]<2147483648) ? (hc23[i][2*j+1][2*k+1][l]<2147483648) ? (hc23[i][2*j+1][2*k  ][l]>hc23[i][2*j+1][2*k+1][l])?hc23[i][2*j+1][2*k  ][l]:hc23[i][2*j+1][2*k+1][l] : hc23[i][2*j+1][2*k  ][l] : (hc23[i][2*j+1][2*k+1][l]<2147483648) ? hc23[i][2*j+1][2*k+1][l] : (hc23[i][2*j+1][2*k  ][l]>hc23[i][2*j+1][2*k+1][l])?hc23[i][2*j+1][2*k+1][l]:hc23[i][2*j+1][2*k  ][l];
        hp2[i][  j  ][  k  ][l] = (tmp0<2147483648) ? (tmp1<2147483648) ? (tmp0>tmp1)?tmp0:tmp1 : tmp0 : (tmp1<2147483648) ? tmp1 : (tmp0>tmp1)?tmp1:tmp0;
      }
    }
  }
}

// reshape
ii = 0;
jj = 0;
kk = 0;
ll = 0;
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:3136] {
        ht2[i ][j ][k ][l ] = hp2[ii][jj][kk][ll];
        ll = ll+1;
        llover = (ll == 64) ? 1 : 0;
        ll =  (llover == 1) ? 0    : ll;
        kk =  (llover == 1) ? kk+1 : kk;
        kkover = (kk == 7) ? 1 : 0;
        kk =  (kkover == 1) ? 0    : kk;
        jj =  (kkover == 1) ? jj+1 : jj;
        jjover = (jj == 7) ? 1 : 0;
        jj =  (jjover == 1) ? 0    : jj;
        ii =  (jjover == 1) ? ii+1 : ii;
      }
    }
  }
}

// mul
uint32_t hf11Buf[1][1][1][1024][3136];
for uint32_t k = [0:1] {
  for uint32_t l = [0:3136] {
    ht2[0][0][k][l] = (ht2[0][0][k][l]<2147483648) ? (ht2[0][0][k][l] >> 15) : (((ht2[0][0][k][l] ^ 4294967295) >> 15) ^ 4294967295);
  }
}
for uint32_t k = [0:3136] {
  for uint32_t l = [0:1024] {
    Wf1[0][0][k][l] = (Wf1[0][0][k][l]<2147483648) ? (Wf1[0][0][k][l] >> 15) : (((Wf1[0][0][k][l] ^ 4294967295) >> 15) ^ 4294967295);
  }
}
for uint32_t k = [0:1] {
  for uint32_t l = [0:1024] {
    for uint32_t m = [0:3136] {
      hf11Buf[0][0][k][l][m] = ht2[0][0][k][m] * Wf1[0][0][m][l];
    }
  }
}
for uint32_t k = [0:1] {
  for uint32_t l = [0:1024] {
    N = 3136;
    for uint32_t a = [0:1] {
      mtmp = 0;
      for uint32_t m = [0:3136] {
        hf11Buf[0][0][k][l][mtmp] = (mtmp<(N>>1)) ? (((hf11Buf[0][0][k][l][2*mtmp]) + (hf11Buf[0][0][k][l][2*mtmp+1]))<2147483648) ? (((hf11Buf[0][0][k][l][2*mtmp]) + (hf11Buf[0][0][k][l][2*mtmp+1])) >> 1) : (((((hf11Buf[0][0][k][l][2*mtmp]) + (hf11Buf[0][0][k][l][2*mtmp+1])) ^ 4294967295) >> 1) ^ 4294967295) : hf11Buf[0][0][k][l][mtmp];
        mtmp = mtmp+1;
      }
      // (N%2==1)
      hf11Buf[0][0][k][l][N>>1] = (N&1==1) ? (hf11Buf[0][0][k][l][N-1]<2147483648) ? (hf11Buf[0][0][k][l][N-1] >> 1) : (((hf11Buf[0][0][k][l][N-1] ^ 4294967295) >> 1) ^ 4294967295) : 0;
      N = (N+1)>>1;
    }
    for uint32_t a = [0:11] {
      mtmp = 0;
      for uint32_t m = [0:3136] {
        hf11Buf[0][0][k][l][mtmp] = (mtmp<(N>>1)) ? ((hf11Buf[0][0][k][l][2*mtmp]) + (hf11Buf[0][0][k][l][2*mtmp+1])) : hf11Buf[0][0][k][l][mtmp];
        mtmp = mtmp+1;
      }
      // (N%2==1)
      hf11Buf[0][0][k][l][N>>1] = (N&1==1) ? hf11Buf[0][0][k][l][N-1] : 0;
      N = (N+1)>>1;
    }
    hf11[0][0][k][l] = hf11Buf[0][0][k][l][0];
  }
}

// add
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:1024] {
        tmp0 = hf11[i][j][k][l];
        tmp1 = (bf1[0][0][0][l]<2147483648) ? (bf1[0][0][0][l] >> 8) : (((bf1[0][0][0][l] ^ 4294967295) >> 8) ^ 4294967295);
        hf12[i][j][k][l] = tmp0+tmp1;
        hf12[i][j][k][l] = hf12[i][j][k][l];
      }
    }
  }
}

// relu
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:1024] {
        hf13[i][j][k][l] = (hf12[i][j][k][l] < 2147483648) ? hf12[i][j][k][l] : 0;
      }
    }
  }
}

// mul
uint32_t hf21Buf[1][1][1][10][1024];
for uint32_t k = [0:1] {
  for uint32_t l = [0:1024] {
    hf13[0][0][k][l] = (hf13[0][0][k][l]<2147483648) ? (hf13[0][0][k][l] >> 15) : (((hf13[0][0][k][l] ^ 4294967295) >> 15) ^ 4294967295);
  }
}
for uint32_t k = [0:1024] {
  for uint32_t l = [0:10] {
    Wf2[0][0][k][l] = (Wf2[0][0][k][l]<2147483648) ? (Wf2[0][0][k][l] >> 15) : (((Wf2[0][0][k][l] ^ 4294967295) >> 15) ^ 4294967295);
  }
}
for uint32_t k = [0:1] {
  for uint32_t l = [0:10] {
    for uint32_t m = [0:1024] {
      hf21Buf[0][0][k][l][m] = hf13[0][0][k][m] * Wf2[0][0][m][l];
    }
  }
}
for uint32_t k = [0:1] {
  for uint32_t l = [0:10] {
    N = 1024;
    for uint32_t a = [0:1] {
      mtmp = 0;
      for uint32_t m = [0:1024] {
        hf21Buf[0][0][k][l][mtmp] = (mtmp<(N>>1)) ? (((hf21Buf[0][0][k][l][2*mtmp]) + (hf21Buf[0][0][k][l][2*mtmp+1]))<2147483648) ? (((hf21Buf[0][0][k][l][2*mtmp]) + (hf21Buf[0][0][k][l][2*mtmp+1])) >> 1) : (((((hf21Buf[0][0][k][l][2*mtmp]) + (hf21Buf[0][0][k][l][2*mtmp+1])) ^ 4294967295) >> 1) ^ 4294967295) : hf21Buf[0][0][k][l][mtmp];
        mtmp = mtmp+1;
      }
      // (N%2==1)
      hf21Buf[0][0][k][l][N>>1] = (N&1==1) ? (hf21Buf[0][0][k][l][N-1]<2147483648) ? (hf21Buf[0][0][k][l][N-1] >> 1) : (((hf21Buf[0][0][k][l][N-1] ^ 4294967295) >> 1) ^ 4294967295) : 0;
      N = (N+1)>>1;
    }
    for uint32_t a = [0:9] {
      mtmp = 0;
      for uint32_t m = [0:1024] {
        hf21Buf[0][0][k][l][mtmp] = (mtmp<(N>>1)) ? ((hf21Buf[0][0][k][l][2*mtmp]) + (hf21Buf[0][0][k][l][2*mtmp+1])) : hf21Buf[0][0][k][l][mtmp];
        mtmp = mtmp+1;
      }
      // (N%2==1)
      hf21Buf[0][0][k][l][N>>1] = (N&1==1) ? hf21Buf[0][0][k][l][N-1] : 0;
      N = (N+1)>>1;
    }
    hf21[0][0][k][l] = hf21Buf[0][0][k][l][0];
  }
}

// add
for uint32_t i = [0:1] {
  for uint32_t j = [0:1] {
    for uint32_t k = [0:1] {
      for uint32_t l = [0:10] {
        tmp0 = hf21[i][j][k][l];
        tmp1 = (bf2[0][0][0][l]<2147483648) ? (bf2[0][0][0][l] >> 7) : (((bf2[0][0][0][l] ^ 4294967295) >> 7) ^ 4294967295);
        hf22[i][j][k][l] = tmp0+tmp1;
        hf22[i][j][k][l] = hf22[i][j][k][l];
      }
    }
  }
}

// argmax
maxind = 0;
maxval = hf22[0][0][0][0];
cnt = 0;
for uint32_t l = [0:10] {
  tmp = ((maxval<2147483648) ? (hf22[0][0][0][l]<2147483648) ? (maxval>hf22[0][0][0][l])?maxval:hf22[0][0][0][l] : maxval : (hf22[0][0][0][l]<2147483648) ? hf22[0][0][0][l] : ((maxval>hf22[0][0][0][l])?hf22[0][0][0][l]:maxval));
  maxind = (tmp == maxval) ? maxind : cnt;
  maxval = tmp;
  cnt = cnt+1;
}
output(maxind);
