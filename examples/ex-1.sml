// logistic regression

uint32_t WW[784][10];
uint32_t bb[10];
uint32_t xx[1][784];
uint32_t tmp0[1][10];
uint32_t tmp1[1][784];
uint32_t tmp2[784][10];
uint32_t tmp3[1][10][784];
uint32_t tmp4;
uint32_t tmp5;
uint32_t tmp6[1][10];
uint32_t tmp7;
uint32_t tmp8;
uint32_t tmp9;
uint32_t tmp10;
uint32_t tmp11;
uint32_t tmp12;
for uint32_t i9 = [0:784] {
  for uint32_t i10 = [0:10] {
    WW[i9][i10] = input2(456);
  }
}
for uint32_t i11 = [0:10] {
  bb[i11] = input2(456);
}
for uint32_t i12 = [0:1] {
  for uint32_t i13 = [0:784] {
    xx[i12][i13] = input1(123);
  }
}
for uint32_t i0 = [0:1] {
  for uint32_t i1 = [0:784] {
    tmp1[i0][i1] = ((xx[i0][i1]<2147483648) ? (xx[i0][i1]>>15) : (((xx[i0][i1]^4294967295)>>15)^4294967295));
  }
}
for uint32_t i1 = [0:784] {
  for uint32_t i2 = [0:10] {
    tmp2[i1][i2] = ((WW[i1][i2]<2147483648) ? (WW[i1][i2]>>15) : (((WW[i1][i2]^4294967295)>>15)^4294967295));
  }
}
for uint32_t i0 = [0:1] {
  for uint32_t i2 = [0:10] {
    for uint32_t i1 = [0:784] {
      tmp3[i0][i2][i1] = (tmp1[i0][i1]*tmp2[i1][i2]);
    }
  }
}
for uint32_t i0 = [0:1] {
  for uint32_t i2 = [0:10] {
    tmp4 = 784;
    for uint32_t i3 = [0:5] {
      tmp5 = 0;
      for uint32_t i4 = [0:393] {
        tmp3[i0][i2][i4] = ((tmp5<(tmp4>>1)) ? (((tmp3[i0][i2][(2*i4)]+tmp3[i0][i2][((2*i4)+1)])<2147483648) ? ((tmp3[i0][i2][(2*i4)]+tmp3[i0][i2][((2*i4)+1)])>>1) : ((((tmp3[i0][i2][(2*i4)]+tmp3[i0][i2][((2*i4)+1)])^4294967295)>>1)^4294967295)) : (((tmp5==(tmp4>>1))&&((tmp4&1)==1)) ? ((tmp3[i0][i2][(2*i4)]<2147483648) ? (tmp3[i0][i2][(2*i4)]>>1) : (((tmp3[i0][i2][(2*i4)]^4294967295)>>1)^4294967295)) : 0));
        tmp5 = (tmp5+1);
      }
      tmp4 = ((tmp4+1)>>1);
    }
    for uint32_t i3 = [0:5] {
      tmp5 = 0;
      for uint32_t i4 = [0:393] {
        tmp3[i0][i2][i4] = ((tmp5<(tmp4>>1)) ? (tmp3[i0][i2][(2*i4)]+tmp3[i0][i2][((2*i4)+1)]) : (((tmp5==(tmp4>>1))&&((tmp4&1)==1)) ? tmp3[i0][i2][(2*i4)] : 0));
        tmp5 = (tmp5+1);
      }
      tmp4 = ((tmp4+1)>>1);
    }
    tmp0[i0][i2] = tmp3[i0][i2][0];
  }
}
for uint32_t i5 = [0:1] {
  for uint32_t i6 = [0:10] {
    tmp7 = tmp0[i5][i6];
    tmp8 = ((bb[i6]<2147483648) ? (bb[i6]>>6) : (((bb[i6]^4294967295)>>6)^4294967295));
    tmp6[i5][i6] = (tmp7+tmp8);
    tmp6[i5][i6] = tmp6[i5][i6];
  }
}
tmp9 = 0;
tmp10 = 0;
tmp11 = tmp6[0][0];
for uint32_t i7 = [0:1] {
  for uint32_t i8 = [0:10] {
    tmp12 = ((tmp11<2147483648) ? ((tmp6[i7][i8]<2147483648) ? ((tmp11>tmp6[i7][i8]) ? tmp11 : tmp6[i7][i8]) : tmp11) : ((tmp6[i7][i8]<2147483648) ? tmp6[i7][i8] : ((tmp11>tmp6[i7][i8]) ? tmp11 : tmp6[i7][i8])));
    tmp10 = ((tmp11==tmp12) ? tmp10 : tmp9);
    tmp11 = tmp12;
    tmp9 = (tmp9+1);
  }
}
output(tmp10);
