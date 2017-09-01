ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto WWc1 = make_vector<uint32_t>(5, 5, 1, 32);
auto s_a_WWc1 = make_vector<share*>(5, 5, 1, 32);
auto WWc2 = make_vector<uint32_t>(5, 5, 32, 64);
auto s_a_WWc2 = make_vector<share*>(5, 5, 32, 64);
auto WWf1 = make_vector<uint32_t>(3136, 1024);
auto s_a_WWf1 = make_vector<share*>(3136, 1024);
auto WWf2 = make_vector<uint32_t>(1024, 10);
auto s_a_WWf2 = make_vector<share*>(1024, 10);
auto bbc1 = make_vector<uint32_t>(32);
auto s_a_bbc1 = make_vector<share*>(32);
auto bbc2 = make_vector<uint32_t>(64);
auto s_a_bbc2 = make_vector<share*>(64);
auto bbf1 = make_vector<uint32_t>(1024);
auto s_a_bbf1 = make_vector<share*>(1024);
auto bbf2 = make_vector<uint32_t>(10);
auto s_a_bbf2 = make_vector<share*>(10);
auto xx = make_vector<uint32_t>(784);
auto s_a_xx = make_vector<share*>(784);
auto tmp0 = make_vector<uint32_t>(1, 28, 28, 1);
auto s_a_tmp0 = make_vector<share*>(1, 28, 28, 1);
auto tmp1 = make_vector<uint32_t>(1, 28, 28, 32);
auto s_a_tmp1 = make_vector<share*>(1, 28, 28, 32);
auto tmp2 = make_vector<uint32_t>(1, 28, 28, 1);
auto s_a_tmp2 = make_vector<share*>(1, 28, 28, 1);
auto tmp3 = make_vector<uint32_t>(1, 32, 32, 1);
auto s_a_tmp3 = make_vector<share*>(1, 32, 32, 1);
auto tmp4 = make_vector<uint32_t>(5, 5, 1, 32);
auto s_a_tmp4 = make_vector<share*>(5, 5, 1, 32);
auto tmp5 = make_vector<uint32_t>(1, 28, 28, 1, 25);
auto s_a_tmp5 = make_vector<share*>(1, 28, 28, 1, 25);
uint32_t tmp6;
share *s_a_tmp6;
uint32_t tmp7;
share *s_a_tmp7;
uint32_t tmp8;
share *s_a_tmp8;
uint32_t tmp9;
share *s_a_tmp9;
uint32_t tmp10;
share *s_a_tmp10;
auto tmp11 = make_vector<uint32_t>(1, 28, 28, 32);
auto s_a_tmp11 = make_vector<share*>(1, 28, 28, 32);
uint32_t tmp12;
share *s_a_tmp12;
uint32_t tmp13;
share *s_a_tmp13;
auto tmp14 = make_vector<uint32_t>(1, 28, 28, 32);
auto s_a_tmp14 = make_vector<share*>(1, 28, 28, 32);
auto tmp15 = make_vector<uint32_t>(1, 14, 14, 32);
auto s_a_tmp15 = make_vector<share*>(1, 14, 14, 32);
uint32_t tmp16;
share *s_a_tmp16;
auto tmp17 = make_vector<uint32_t>(1, 14, 14, 64);
auto s_a_tmp17 = make_vector<share*>(1, 14, 14, 64);
auto tmp18 = make_vector<uint32_t>(1, 14, 14, 32);
auto s_a_tmp18 = make_vector<share*>(1, 14, 14, 32);
auto tmp19 = make_vector<uint32_t>(1, 18, 18, 32);
auto s_a_tmp19 = make_vector<share*>(1, 18, 18, 32);
auto tmp20 = make_vector<uint32_t>(5, 5, 32, 64);
auto s_a_tmp20 = make_vector<share*>(5, 5, 32, 64);
auto tmp21 = make_vector<uint32_t>(1, 14, 14, 32, 25);
auto s_a_tmp21 = make_vector<share*>(1, 14, 14, 32, 25);
uint32_t tmp22;
share *s_a_tmp22;
uint32_t tmp23;
share *s_a_tmp23;
uint32_t tmp24;
share *s_a_tmp24;
uint32_t tmp25;
share *s_a_tmp25;
uint32_t tmp26;
share *s_a_tmp26;
auto tmp27 = make_vector<uint32_t>(1, 14, 14, 64);
auto s_a_tmp27 = make_vector<share*>(1, 14, 14, 64);
uint32_t tmp28;
share *s_a_tmp28;
uint32_t tmp29;
share *s_a_tmp29;
auto tmp30 = make_vector<uint32_t>(1, 14, 14, 64);
auto s_a_tmp30 = make_vector<share*>(1, 14, 14, 64);
auto tmp31 = make_vector<uint32_t>(1, 7, 7, 64);
auto s_a_tmp31 = make_vector<share*>(1, 7, 7, 64);
uint32_t tmp32;
share *s_a_tmp32;
auto tmp33 = make_vector<uint32_t>(1, 3136);
auto s_a_tmp33 = make_vector<share*>(1, 3136);
auto tmp34 = make_vector<uint32_t>(1, 1024);
auto s_a_tmp34 = make_vector<share*>(1, 1024);
auto tmp35 = make_vector<uint32_t>(1, 3136);
auto s_a_tmp35 = make_vector<share*>(1, 3136);
auto tmp36 = make_vector<uint32_t>(3136, 1024);
auto s_a_tmp36 = make_vector<share*>(3136, 1024);
auto tmp37 = make_vector<uint32_t>(1, 1024, 3136);
auto s_a_tmp37 = make_vector<share*>(1, 1024, 3136);
uint32_t tmp38;
share *s_a_tmp38;
uint32_t tmp39;
share *s_a_tmp39;
auto tmp40 = make_vector<uint32_t>(1, 1024);
auto s_a_tmp40 = make_vector<share*>(1, 1024);
uint32_t tmp41;
share *s_a_tmp41;
uint32_t tmp42;
share *s_a_tmp42;
auto tmp43 = make_vector<uint32_t>(1, 1024);
auto s_a_tmp43 = make_vector<share*>(1, 1024);
auto tmp44 = make_vector<uint32_t>(1, 10);
auto s_a_tmp44 = make_vector<share*>(1, 10);
auto tmp45 = make_vector<uint32_t>(1, 1024);
auto s_a_tmp45 = make_vector<share*>(1, 1024);
auto tmp46 = make_vector<uint32_t>(1024, 10);
auto s_a_tmp46 = make_vector<share*>(1024, 10);
auto tmp47 = make_vector<uint32_t>(1, 10, 1024);
auto s_a_tmp47 = make_vector<share*>(1, 10, 1024);
uint32_t tmp48;
share *s_a_tmp48;
uint32_t tmp49;
share *s_a_tmp49;
auto tmp50 = make_vector<uint32_t>(1, 10);
auto s_a_tmp50 = make_vector<share*>(1, 10);
uint32_t tmp51;
share *s_a_tmp51;
uint32_t tmp52;
share *s_a_tmp52;
uint32_t tmp53;
share *s_a_tmp53;
uint32_t tmp54;
share *s_a_tmp54;
uint32_t tmp55;
share *s_a_tmp55;
uint32_t tmp56;
share *s_a_tmp56;
for (uint32_t i72 = 0; i72 < 5; i72++)
{
    for (uint32_t i73 = 0; i73 < 5; i73++)
    {
        for (uint32_t i74 = 0; i74 < 1; i74++)
        {
            for (uint32_t i75 = 0; i75 < 32; i75++)
            {
                if (role == CLIENT) {
                    WWc1[i72][i73][i74][i75] = 456 ;
                    s_a_WWc1[i72][i73][i74][i75] = acirc->PutINGate( WWc1[i72][i73][i74][i75] ,bitlen,CLIENT);
                } else {
                    s_a_WWc1[i72][i73][i74][i75] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i76 = 0; i76 < 5; i76++)
{
    for (uint32_t i77 = 0; i77 < 5; i77++)
    {
        for (uint32_t i78 = 0; i78 < 32; i78++)
        {
            for (uint32_t i79 = 0; i79 < 64; i79++)
            {
                if (role == CLIENT) {
                    WWc2[i76][i77][i78][i79] = 456 ;
                    s_a_WWc2[i76][i77][i78][i79] = acirc->PutINGate( WWc2[i76][i77][i78][i79] ,bitlen,CLIENT);
                } else {
                    s_a_WWc2[i76][i77][i78][i79] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i80 = 0; i80 < 3136; i80++)
{
    for (uint32_t i81 = 0; i81 < 1024; i81++)
    {
        if (role == CLIENT) {
            WWf1[i80][i81] = 456 ;
            s_a_WWf1[i80][i81] = acirc->PutINGate( WWf1[i80][i81] ,bitlen,CLIENT);
        } else {
            s_a_WWf1[i80][i81] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i82 = 0; i82 < 1024; i82++)
{
    for (uint32_t i83 = 0; i83 < 10; i83++)
    {
        if (role == CLIENT) {
            WWf2[i82][i83] = 456 ;
            s_a_WWf2[i82][i83] = acirc->PutINGate( WWf2[i82][i83] ,bitlen,CLIENT);
        } else {
            s_a_WWf2[i82][i83] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i84 = 0; i84 < 32; i84++)
{
    if (role == CLIENT) {
        bbc1[i84] = 456 ;
        s_a_bbc1[i84] = acirc->PutINGate( bbc1[i84] ,bitlen,CLIENT);
    } else {
        s_a_bbc1[i84] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i85 = 0; i85 < 64; i85++)
{
    if (role == CLIENT) {
        bbc2[i85] = 456 ;
        s_a_bbc2[i85] = acirc->PutINGate( bbc2[i85] ,bitlen,CLIENT);
    } else {
        s_a_bbc2[i85] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i86 = 0; i86 < 1024; i86++)
{
    if (role == CLIENT) {
        bbf1[i86] = 456 ;
        s_a_bbf1[i86] = acirc->PutINGate( bbf1[i86] ,bitlen,CLIENT);
    } else {
        s_a_bbf1[i86] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i87 = 0; i87 < 10; i87++)
{
    if (role == CLIENT) {
        bbf2[i87] = 456 ;
        s_a_bbf2[i87] = acirc->PutINGate( bbf2[i87] ,bitlen,CLIENT);
    } else {
        s_a_bbf2[i87] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i88 = 0; i88 < 784; i88++)
{
    if (role == SERVER) {
        xx[i88] = 123 ;
        s_a_xx[i88] = acirc->PutINGate( xx[i88] ,bitlen,SERVER);
    } else {
        s_a_xx[i88] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i0 = 0; i0 < 1; i0++)
{
    for (uint32_t i1 = 0; i1 < 28; i1++)
    {
        for (uint32_t i2 = 0; i2 < 28; i2++)
        {
            for (uint32_t i3 = 0; i3 < 1; i3++)
            {
                s_a_tmp0[i0][i1][i2][i3] = create_new_share(s_a_xx[(i3+((i2*1)+((i1*28)+(i0*784))))]->get_wires(), acirc );
            }
        }
    }
}
auto s_y_tmp0 = make_vector<share*>(1, 28, 28, 1);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 28 ; _i4++) {
for (int _i7 = 0; _i7 < 28 ; _i7++) {
for (int _i10 = 0; _i10 < 1 ; _i10++) {
s_y_tmp0[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_tmp0[_i1][_i4][_i7][_i10] );
}
}
}
}
auto s_y_tmp2 = make_vector<share*>(1, 28, 28, 1);
for (uint32_t i4 = 0; i4 < 1; i4++)
{
    for (uint32_t i5 = 0; i5 < 28; i5++)
    {
        for (uint32_t i6 = 0; i6 < 28; i6++)
        {
            for (uint32_t i7 = 0; i7 < 1; i7++)
            {
                uint32_t _tmp_1 = 2147483648 ;
                share * s_y__tmp_1 = ycirc->PutCONSGate( _tmp_1 ,bitlen);
                share * s_y_tmp_0 = ycirc->PutGTGate( s_y__tmp_1 , s_y_tmp0[i4][i5][i6][i7] );
                vector<uint32_t> _vec3 = s_y_tmp0[i4][i5][i6][i7]->get_wires();
                _vec3.erase( _vec3.begin(), _vec3.begin() + 15 );
                share *s_y_tmp_2 = create_new_share( _vec3 , ycirc );
                uint32_t _tmp_7 = 4294967295 ;
                share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
                share * s_y_tmp_6 = ycirc->PutXORGate( s_y_tmp0[i4][i5][i6][i7] , s_y__tmp_7 );
                vector<uint32_t> _vec8 = s_y_tmp_6->get_wires();
                _vec8.erase( _vec8.begin(), _vec8.begin() + 15 );
                share *s_y_tmp_5 = create_new_share( _vec8 , ycirc );
                uint32_t _tmp_9 = 4294967295 ;
                share * s_y__tmp_9 = ycirc->PutCONSGate( _tmp_9 ,bitlen);
                share * s_y_tmp_4 = ycirc->PutXORGate( s_y_tmp_5 , s_y__tmp_9 );
                s_y_tmp2[i4][i5][i6][i7] = ycirc->PutMUXGate( s_y_tmp_2 , s_y_tmp_4 , s_y_tmp_0 );
            }
        }
    }
}
auto s_y_WWc1 = make_vector<share*>(5, 5, 1, 32);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
s_y_WWc1[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_WWc1[_i1][_i4][_i7][_i10] );
}
}
}
}
auto s_y_tmp4 = make_vector<share*>(5, 5, 1, 32);
for (uint32_t i8 = 0; i8 < 5; i8++)
{
    for (uint32_t i9 = 0; i9 < 5; i9++)
    {
        for (uint32_t i7 = 0; i7 < 1; i7++)
        {
            for (uint32_t i10 = 0; i10 < 32; i10++)
            {
                uint32_t _tmp_11 = 2147483648 ;
                share * s_y__tmp_11 = ycirc->PutCONSGate( _tmp_11 ,bitlen);
                share * s_y_tmp_10 = ycirc->PutGTGate( s_y__tmp_11 , s_y_WWc1[i8][i9][i7][i10] );
                vector<uint32_t> _vec13 = s_y_WWc1[i8][i9][i7][i10]->get_wires();
                _vec13.erase( _vec13.begin(), _vec13.begin() + 15 );
                share *s_y_tmp_12 = create_new_share( _vec13 , ycirc );
                uint32_t _tmp_17 = 4294967295 ;
                share * s_y__tmp_17 = ycirc->PutCONSGate( _tmp_17 ,bitlen);
                share * s_y_tmp_16 = ycirc->PutXORGate( s_y_WWc1[i8][i9][i7][i10] , s_y__tmp_17 );
                vector<uint32_t> _vec18 = s_y_tmp_16->get_wires();
                _vec18.erase( _vec18.begin(), _vec18.begin() + 15 );
                share *s_y_tmp_15 = create_new_share( _vec18 , ycirc );
                uint32_t _tmp_19 = 4294967295 ;
                share * s_y__tmp_19 = ycirc->PutCONSGate( _tmp_19 ,bitlen);
                share * s_y_tmp_14 = ycirc->PutXORGate( s_y_tmp_15 , s_y__tmp_19 );
                s_y_tmp4[i8][i9][i7][i10] = ycirc->PutMUXGate( s_y_tmp_12 , s_y_tmp_14 , s_y_tmp_10 );
            }
        }
    }
}
share * s_y_tmp6 ;
share * s_y_tmp7 ;
auto s_y_tmp3 = make_vector<share*>(1, 32, 32, 1);
for (uint32_t i4 = 0; i4 < 1; i4++)
{
    tmp6 = 0 ;
    s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
    for (uint32_t i5 = 0; i5 < 28; i5++)
    {
        tmp7 = 0 ;
        s_y_tmp7 = ycirc->PutCONSGate( tmp7 ,bitlen);
        for (uint32_t i6 = 0; i6 < 28; i6++)
        {
            for (uint32_t i7 = 0; i7 < 1; i7++)
            {
                uint32_t _tmp_23 = 2 ;
                share * s_y__tmp_23 = ycirc->PutCONSGate( _tmp_23 ,bitlen);
                share * s_y_tmp_22 = ycirc->PutSUBGate( s_y_tmp6 , s_y__tmp_23 );
                uint32_t _tmp_24 = 28 ;
                share * s_y__tmp_24 = ycirc->PutCONSGate( _tmp_24 ,bitlen);
                share * s_y_tmp_21 = ycirc->PutGTGate( s_y__tmp_24 , s_y_tmp_22 );
                uint32_t _tmp_27 = 2 ;
                share * s_y__tmp_27 = ycirc->PutCONSGate( _tmp_27 ,bitlen);
                share * s_y_tmp_26 = ycirc->PutSUBGate( s_y_tmp7 , s_y__tmp_27 );
                uint32_t _tmp_28 = 28 ;
                share * s_y__tmp_28 = ycirc->PutCONSGate( _tmp_28 ,bitlen);
                share * s_y_tmp_25 = ycirc->PutGTGate( s_y__tmp_28 , s_y_tmp_26 );
                share * s_y_tmp_20 = ycirc->PutANDGate( s_y_tmp_21 , s_y_tmp_25 );
                uint32_t _tmp_29 = 0 ;
                share * s_y__tmp_29 = ycirc->PutCONSGate( _tmp_29 ,bitlen);
                s_y_tmp3[i4][i5][i6][i7] = ycirc->PutMUXGate( s_y_tmp2[i4][(i5-2)][(i6-2)][i7] , s_y__tmp_29 , s_y_tmp_20 );
            }
            uint32_t _tmp_30 = 1 ;
            share * s_y__tmp_30 = ycirc->PutCONSGate( _tmp_30 ,bitlen);
            s_y_tmp7 = ycirc->PutADDGate( s_y_tmp7 , s_y__tmp_30 );
        }
        uint32_t _tmp_31 = 1 ;
        share * s_y__tmp_31 = ycirc->PutCONSGate( _tmp_31 ,bitlen);
        s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_31 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 32 ; _i4++) {
for (int _i7 = 0; _i7 < 32 ; _i7++) {
for (int _i10 = 0; _i10 < 1 ; _i10++) {
s_a_tmp3[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
s_a_tmp4[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_tmp4[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (uint32_t i4 = 0; i4 < 1; i4++)
{
    for (uint32_t i5 = 0; i5 < 28; i5++)
    {
        for (uint32_t i6 = 0; i6 < 28; i6++)
        {
            for (uint32_t i10 = 0; i10 < 32; i10++)
            {
                tmp8 = 0 ;
                s_a_tmp8 = acirc->PutCONSGate( tmp8 ,bitlen);
                for (uint32_t i8 = 0; i8 < 5; i8++)
                {
                    for (uint32_t i9 = 0; i9 < 5; i9++)
                    {
                        for (uint32_t i7 = 0; i7 < 1; i7++)
                        {
                            s_a_tmp5[i4][i5][i6][i10][tmp8] = acirc->PutMULGate( s_a_tmp3[i4][(i5+i8)][(i6+i9)][i7] , s_a_tmp4[i8][i9][i7][i10] );
                            uint32_t _tmp_32 = 1 ;
                            share * s_a__tmp_32 = acirc->PutCONSGate( _tmp_32 ,bitlen);
                            s_a_tmp8 = acirc->PutADDGate( s_a_tmp8 , s_a__tmp_32 );
                        }
                    }
                }
            }
        }
    }
}
share * s_y_tmp9 ;
share * s_y_tmp10 ;
auto s_y_tmp5 = make_vector<share*>(1, 28, 28, 1, 25);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 28 ; _i4++) {
for (int _i7 = 0; _i7 < 28 ; _i7++) {
for (int _i10 = 0; _i10 < 1 ; _i10++) {
for (int _i13 = 0; _i13 < 25 ; _i13++) {
s_y_tmp5[_i1][_i4][_i7][_i10][_i13] = ycirc->PutA2YGate( s_a_tmp5[_i1][_i4][_i7][_i10][_i13] );
}
}
}
}
}
auto s_y_tmp1 = make_vector<share*>(1, 28, 28, 32);
for (uint32_t i4 = 0; i4 < 1; i4++)
{
    for (uint32_t i5 = 0; i5 < 28; i5++)
    {
        for (uint32_t i6 = 0; i6 < 28; i6++)
        {
            for (uint32_t i10 = 0; i10 < 32; i10++)
            {
                tmp9 = 25 ;
                s_y_tmp9 = ycirc->PutCONSGate( tmp9 ,bitlen);
                for (uint32_t i11 = 0; i11 < 5; i11++)
                {
                    tmp10 = 0 ;
                    s_y_tmp10 = ycirc->PutCONSGate( tmp10 ,bitlen);
                    for (uint32_t i12 = 0; i12 < 13; i12++)
                    {
                        vector<uint32_t> _vec35 = s_y_tmp9->get_wires();
                        _vec35.erase( _vec35.begin(), _vec35.begin() + 1 );
                        share *s_y_tmp_34 = create_new_share( _vec35 , ycirc );
                        share * s_y_tmp_33 = ycirc->PutGTGate( s_y_tmp_34 , s_y_tmp10 );
                        share * s_y_tmp_38 = ycirc->PutADDGate( s_y_tmp5[i4][i5][i6][i10][(2*i12)] , s_y_tmp5[i4][i5][i6][i10][((2*i12)+1)] );
                        uint32_t _tmp_39 = 2147483648 ;
                        share * s_y__tmp_39 = ycirc->PutCONSGate( _tmp_39 ,bitlen);
                        share * s_y_tmp_37 = ycirc->PutGTGate( s_y__tmp_39 , s_y_tmp_38 );
                        share * s_y_tmp_41 = ycirc->PutADDGate( s_y_tmp5[i4][i5][i6][i10][(2*i12)] , s_y_tmp5[i4][i5][i6][i10][((2*i12)+1)] );
                        vector<uint32_t> _vec42 = s_y_tmp_41->get_wires();
                        _vec42.erase( _vec42.begin(), _vec42.begin() + 1 );
                        share *s_y_tmp_40 = create_new_share( _vec42 , ycirc );
                        share * s_y_tmp_46 = ycirc->PutADDGate( s_y_tmp5[i4][i5][i6][i10][(2*i12)] , s_y_tmp5[i4][i5][i6][i10][((2*i12)+1)] );
                        uint32_t _tmp_47 = 4294967295 ;
                        share * s_y__tmp_47 = ycirc->PutCONSGate( _tmp_47 ,bitlen);
                        share * s_y_tmp_45 = ycirc->PutXORGate( s_y_tmp_46 , s_y__tmp_47 );
                        vector<uint32_t> _vec48 = s_y_tmp_45->get_wires();
                        _vec48.erase( _vec48.begin(), _vec48.begin() + 1 );
                        share *s_y_tmp_44 = create_new_share( _vec48 , ycirc );
                        uint32_t _tmp_49 = 4294967295 ;
                        share * s_y__tmp_49 = ycirc->PutCONSGate( _tmp_49 ,bitlen);
                        share * s_y_tmp_43 = ycirc->PutXORGate( s_y_tmp_44 , s_y__tmp_49 );
                        share * s_y_tmp_36 = ycirc->PutMUXGate( s_y_tmp_40 , s_y_tmp_43 , s_y_tmp_37 );
                        vector<uint32_t> _vec54 = s_y_tmp9->get_wires();
                        _vec54.erase( _vec54.begin(), _vec54.begin() + 1 );
                        share *s_y_tmp_53 = create_new_share( _vec54 , ycirc );
                        share * s_y_tmp_52 = ycirc->PutEQGate( s_y_tmp10 , s_y_tmp_53 );
                        uint32_t _tmp_57 = 1 ;
                        share * s_y__tmp_57 = ycirc->PutCONSGate( _tmp_57 ,bitlen);
                        share * s_y_tmp_56 = ycirc->PutANDGate( s_y_tmp9 , s_y__tmp_57 );
                        uint32_t _tmp_58 = 1 ;
                        share * s_y__tmp_58 = ycirc->PutCONSGate( _tmp_58 ,bitlen);
                        share * s_y_tmp_55 = ycirc->PutEQGate( s_y_tmp_56 , s_y__tmp_58 );
                        share * s_y_tmp_51 = ycirc->PutANDGate( s_y_tmp_52 , s_y_tmp_55 );
                        uint32_t _tmp_61 = 2147483648 ;
                        share * s_y__tmp_61 = ycirc->PutCONSGate( _tmp_61 ,bitlen);
                        share * s_y_tmp_60 = ycirc->PutGTGate( s_y__tmp_61 , s_y_tmp5[i4][i5][i6][i10][(2*i12)] );
                        vector<uint32_t> _vec63 = s_y_tmp5[i4][i5][i6][i10][(2*i12)]->get_wires();
                        _vec63.erase( _vec63.begin(), _vec63.begin() + 1 );
                        share *s_y_tmp_62 = create_new_share( _vec63 , ycirc );
                        uint32_t _tmp_67 = 4294967295 ;
                        share * s_y__tmp_67 = ycirc->PutCONSGate( _tmp_67 ,bitlen);
                        share * s_y_tmp_66 = ycirc->PutXORGate( s_y_tmp5[i4][i5][i6][i10][(2*i12)] , s_y__tmp_67 );
                        vector<uint32_t> _vec68 = s_y_tmp_66->get_wires();
                        _vec68.erase( _vec68.begin(), _vec68.begin() + 1 );
                        share *s_y_tmp_65 = create_new_share( _vec68 , ycirc );
                        uint32_t _tmp_69 = 4294967295 ;
                        share * s_y__tmp_69 = ycirc->PutCONSGate( _tmp_69 ,bitlen);
                        share * s_y_tmp_64 = ycirc->PutXORGate( s_y_tmp_65 , s_y__tmp_69 );
                        share * s_y_tmp_59 = ycirc->PutMUXGate( s_y_tmp_62 , s_y_tmp_64 , s_y_tmp_60 );
                        uint32_t _tmp_70 = 0 ;
                        share * s_y__tmp_70 = ycirc->PutCONSGate( _tmp_70 ,bitlen);
                        share * s_y_tmp_50 = ycirc->PutMUXGate( s_y_tmp_59 , s_y__tmp_70 , s_y_tmp_51 );
                        s_y_tmp5[i4][i5][i6][i10][i12] = ycirc->PutMUXGate( s_y_tmp_36 , s_y_tmp_50 , s_y_tmp_33 );
                        uint32_t _tmp_71 = 1 ;
                        share * s_y__tmp_71 = ycirc->PutCONSGate( _tmp_71 ,bitlen);
                        s_y_tmp10 = ycirc->PutADDGate( s_y_tmp10 , s_y__tmp_71 );
                    }
                    uint32_t _tmp_73 = 1 ;
                    share * s_y__tmp_73 = ycirc->PutCONSGate( _tmp_73 ,bitlen);
                    share * s_y_tmp_72 = ycirc->PutADDGate( s_y_tmp9 , s_y__tmp_73 );
                    vector<uint32_t> _vec74 = s_y_tmp_72->get_wires();
                    _vec74.erase( _vec74.begin(), _vec74.begin() + 1 );
                    s_y_tmp9 = create_new_share( _vec74 , ycirc );
                }
                for (uint32_t i11 = 0; i11 < 0; i11++)
                {
                    tmp10 = 0 ;
                    s_y_tmp10 = ycirc->PutCONSGate( tmp10 ,bitlen);
                    for (uint32_t i12 = 0; i12 < 13; i12++)
                    {
                        vector<uint32_t> _vec77 = s_y_tmp9->get_wires();
                        _vec77.erase( _vec77.begin(), _vec77.begin() + 1 );
                        share *s_y_tmp_76 = create_new_share( _vec77 , ycirc );
                        share * s_y_tmp_75 = ycirc->PutGTGate( s_y_tmp_76 , s_y_tmp10 );
                        share * s_y_tmp_78 = ycirc->PutADDGate( s_y_tmp5[i4][i5][i6][i10][(2*i12)] , s_y_tmp5[i4][i5][i6][i10][((2*i12)+1)] );
                        vector<uint32_t> _vec83 = s_y_tmp9->get_wires();
                        _vec83.erase( _vec83.begin(), _vec83.begin() + 1 );
                        share *s_y_tmp_82 = create_new_share( _vec83 , ycirc );
                        share * s_y_tmp_81 = ycirc->PutEQGate( s_y_tmp10 , s_y_tmp_82 );
                        uint32_t _tmp_86 = 1 ;
                        share * s_y__tmp_86 = ycirc->PutCONSGate( _tmp_86 ,bitlen);
                        share * s_y_tmp_85 = ycirc->PutANDGate( s_y_tmp9 , s_y__tmp_86 );
                        uint32_t _tmp_87 = 1 ;
                        share * s_y__tmp_87 = ycirc->PutCONSGate( _tmp_87 ,bitlen);
                        share * s_y_tmp_84 = ycirc->PutEQGate( s_y_tmp_85 , s_y__tmp_87 );
                        share * s_y_tmp_80 = ycirc->PutANDGate( s_y_tmp_81 , s_y_tmp_84 );
                        uint32_t _tmp_88 = 0 ;
                        share * s_y__tmp_88 = ycirc->PutCONSGate( _tmp_88 ,bitlen);
                        share * s_y_tmp_79 = ycirc->PutMUXGate( s_y_tmp5[i4][i5][i6][i10][(2*i12)] , s_y__tmp_88 , s_y_tmp_80 );
                        s_y_tmp5[i4][i5][i6][i10][i12] = ycirc->PutMUXGate( s_y_tmp_78 , s_y_tmp_79 , s_y_tmp_75 );
                        uint32_t _tmp_89 = 1 ;
                        share * s_y__tmp_89 = ycirc->PutCONSGate( _tmp_89 ,bitlen);
                        s_y_tmp10 = ycirc->PutADDGate( s_y_tmp10 , s_y__tmp_89 );
                    }
                    uint32_t _tmp_91 = 1 ;
                    share * s_y__tmp_91 = ycirc->PutCONSGate( _tmp_91 ,bitlen);
                    share * s_y_tmp_90 = ycirc->PutADDGate( s_y_tmp9 , s_y__tmp_91 );
                    vector<uint32_t> _vec92 = s_y_tmp_90->get_wires();
                    _vec92.erase( _vec92.begin(), _vec92.begin() + 1 );
                    s_y_tmp9 = create_new_share( _vec92 , ycirc );
                }
                s_y_tmp1[i4][i5][i6][i10] = create_new_share(s_y_tmp5[i4][i5][i6][i10][0]->get_wires(), ycirc );
            }
        }
    }
}
share * s_y_tmp12 ;
auto s_y_bbc1 = make_vector<share*>(32);
for (int _i1 = 0; _i1 < 32 ; _i1++) {
s_y_bbc1[_i1] = ycirc->PutA2YGate( s_a_bbc1[_i1] );
}
share * s_y_tmp13 ;
auto s_y_tmp11 = make_vector<share*>(1, 28, 28, 32);
for (uint32_t i13 = 0; i13 < 1; i13++)
{
    for (uint32_t i14 = 0; i14 < 28; i14++)
    {
        for (uint32_t i15 = 0; i15 < 28; i15++)
        {
            for (uint32_t i16 = 0; i16 < 32; i16++)
            {
                s_y_tmp12 = create_new_share(s_y_tmp1[i13][i14][i15][i16]->get_wires(), ycirc );
                uint32_t _tmp_94 = 2147483648 ;
                share * s_y__tmp_94 = ycirc->PutCONSGate( _tmp_94 ,bitlen);
                share * s_y_tmp_93 = ycirc->PutGTGate( s_y__tmp_94 , s_y_bbc1[i16] );
                vector<uint32_t> _vec96 = s_y_bbc1[i16]->get_wires();
                _vec96.erase( _vec96.begin(), _vec96.begin() + 8 );
                share *s_y_tmp_95 = create_new_share( _vec96 , ycirc );
                uint32_t _tmp_100 = 4294967295 ;
                share * s_y__tmp_100 = ycirc->PutCONSGate( _tmp_100 ,bitlen);
                share * s_y_tmp_99 = ycirc->PutXORGate( s_y_bbc1[i16] , s_y__tmp_100 );
                vector<uint32_t> _vec101 = s_y_tmp_99->get_wires();
                _vec101.erase( _vec101.begin(), _vec101.begin() + 8 );
                share *s_y_tmp_98 = create_new_share( _vec101 , ycirc );
                uint32_t _tmp_102 = 4294967295 ;
                share * s_y__tmp_102 = ycirc->PutCONSGate( _tmp_102 ,bitlen);
                share * s_y_tmp_97 = ycirc->PutXORGate( s_y_tmp_98 , s_y__tmp_102 );
                s_y_tmp13 = ycirc->PutMUXGate( s_y_tmp_95 , s_y_tmp_97 , s_y_tmp_93 );
                s_y_tmp11[i13][i14][i15][i16] = ycirc->PutADDGate( s_y_tmp12 , s_y_tmp13 );
                s_y_tmp11[i13][i14][i15][i16] = create_new_share(s_y_tmp11[i13][i14][i15][i16]->get_wires(), ycirc );
            }
        }
    }
}
auto s_y_tmp14 = make_vector<share*>(1, 28, 28, 32);
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 28; i18++)
    {
        for (uint32_t i19 = 0; i19 < 28; i19++)
        {
            for (uint32_t i20 = 0; i20 < 32; i20++)
            {
                uint32_t _tmp_104 = 2147483648 ;
                share * s_y__tmp_104 = ycirc->PutCONSGate( _tmp_104 ,bitlen);
                share * s_y_tmp_103 = ycirc->PutGTGate( s_y__tmp_104 , s_y_tmp11[i17][i18][i19][i20] );
                uint32_t _tmp_105 = 0 ;
                share * s_y__tmp_105 = ycirc->PutCONSGate( _tmp_105 ,bitlen);
                s_y_tmp14[i17][i18][i19][i20] = ycirc->PutMUXGate( s_y_tmp11[i17][i18][i19][i20] , s_y__tmp_105 , s_y_tmp_103 );
            }
        }
    }
}
share * s_y_tmp16 ;
auto s_y_tmp15 = make_vector<share*>(1, 14, 14, 32);
for (uint32_t i21 = 0; i21 < 1; i21++)
{
    for (uint32_t i22 = 0; i22 < 14; i22++)
    {
        for (uint32_t i23 = 0; i23 < 14; i23++)
        {
            for (uint32_t i24 = 0; i24 < 32; i24++)
            {
                s_y_tmp16 = create_new_share(s_y_tmp14[i21][((2*i22)+0)][((2*i23)+0)][i24]->get_wires(), ycirc );
                for (uint32_t i25 = 0; i25 < 2; i25++)
                {
                    for (uint32_t i26 = 0; i26 < 2; i26++)
                    {
                        share * s_y_tmp_106 = ycirc->PutGTGate( s_y_tmp16 , s_y_tmp14[i21][((2*i22)+i25)][((2*i23)+i26)][i24] );
                        s_y_tmp16 = ycirc->PutMUXGate( s_y_tmp16 , s_y_tmp14[i21][((2*i22)+i25)][((2*i23)+i26)][i24] , s_y_tmp_106 );
                    }
                }
                s_y_tmp15[i21][i22][i23][i24] = create_new_share(s_y_tmp16->get_wires(), ycirc );
            }
        }
    }
}
auto s_y_tmp18 = make_vector<share*>(1, 14, 14, 32);
for (uint32_t i27 = 0; i27 < 1; i27++)
{
    for (uint32_t i28 = 0; i28 < 14; i28++)
    {
        for (uint32_t i29 = 0; i29 < 14; i29++)
        {
            for (uint32_t i30 = 0; i30 < 32; i30++)
            {
                uint32_t _tmp_108 = 2147483648 ;
                share * s_y__tmp_108 = ycirc->PutCONSGate( _tmp_108 ,bitlen);
                share * s_y_tmp_107 = ycirc->PutGTGate( s_y__tmp_108 , s_y_tmp15[i27][i28][i29][i30] );
                vector<uint32_t> _vec110 = s_y_tmp15[i27][i28][i29][i30]->get_wires();
                _vec110.erase( _vec110.begin(), _vec110.begin() + 15 );
                share *s_y_tmp_109 = create_new_share( _vec110 , ycirc );
                uint32_t _tmp_114 = 4294967295 ;
                share * s_y__tmp_114 = ycirc->PutCONSGate( _tmp_114 ,bitlen);
                share * s_y_tmp_113 = ycirc->PutXORGate( s_y_tmp15[i27][i28][i29][i30] , s_y__tmp_114 );
                vector<uint32_t> _vec115 = s_y_tmp_113->get_wires();
                _vec115.erase( _vec115.begin(), _vec115.begin() + 15 );
                share *s_y_tmp_112 = create_new_share( _vec115 , ycirc );
                uint32_t _tmp_116 = 4294967295 ;
                share * s_y__tmp_116 = ycirc->PutCONSGate( _tmp_116 ,bitlen);
                share * s_y_tmp_111 = ycirc->PutXORGate( s_y_tmp_112 , s_y__tmp_116 );
                s_y_tmp18[i27][i28][i29][i30] = ycirc->PutMUXGate( s_y_tmp_109 , s_y_tmp_111 , s_y_tmp_107 );
            }
        }
    }
}
auto s_y_WWc2 = make_vector<share*>(5, 5, 32, 64);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 32 ; _i7++) {
for (int _i10 = 0; _i10 < 64 ; _i10++) {
s_y_WWc2[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_WWc2[_i1][_i4][_i7][_i10] );
}
}
}
}
auto s_y_tmp20 = make_vector<share*>(5, 5, 32, 64);
for (uint32_t i31 = 0; i31 < 5; i31++)
{
    for (uint32_t i32 = 0; i32 < 5; i32++)
    {
        for (uint32_t i30 = 0; i30 < 32; i30++)
        {
            for (uint32_t i33 = 0; i33 < 64; i33++)
            {
                uint32_t _tmp_118 = 2147483648 ;
                share * s_y__tmp_118 = ycirc->PutCONSGate( _tmp_118 ,bitlen);
                share * s_y_tmp_117 = ycirc->PutGTGate( s_y__tmp_118 , s_y_WWc2[i31][i32][i30][i33] );
                vector<uint32_t> _vec120 = s_y_WWc2[i31][i32][i30][i33]->get_wires();
                _vec120.erase( _vec120.begin(), _vec120.begin() + 15 );
                share *s_y_tmp_119 = create_new_share( _vec120 , ycirc );
                uint32_t _tmp_124 = 4294967295 ;
                share * s_y__tmp_124 = ycirc->PutCONSGate( _tmp_124 ,bitlen);
                share * s_y_tmp_123 = ycirc->PutXORGate( s_y_WWc2[i31][i32][i30][i33] , s_y__tmp_124 );
                vector<uint32_t> _vec125 = s_y_tmp_123->get_wires();
                _vec125.erase( _vec125.begin(), _vec125.begin() + 15 );
                share *s_y_tmp_122 = create_new_share( _vec125 , ycirc );
                uint32_t _tmp_126 = 4294967295 ;
                share * s_y__tmp_126 = ycirc->PutCONSGate( _tmp_126 ,bitlen);
                share * s_y_tmp_121 = ycirc->PutXORGate( s_y_tmp_122 , s_y__tmp_126 );
                s_y_tmp20[i31][i32][i30][i33] = ycirc->PutMUXGate( s_y_tmp_119 , s_y_tmp_121 , s_y_tmp_117 );
            }
        }
    }
}
share * s_y_tmp22 ;
share * s_y_tmp23 ;
auto s_y_tmp19 = make_vector<share*>(1, 18, 18, 32);
for (uint32_t i27 = 0; i27 < 1; i27++)
{
    tmp22 = 0 ;
    s_y_tmp22 = ycirc->PutCONSGate( tmp22 ,bitlen);
    for (uint32_t i28 = 0; i28 < 14; i28++)
    {
        tmp23 = 0 ;
        s_y_tmp23 = ycirc->PutCONSGate( tmp23 ,bitlen);
        for (uint32_t i29 = 0; i29 < 14; i29++)
        {
            for (uint32_t i30 = 0; i30 < 32; i30++)
            {
                uint32_t _tmp_130 = 2 ;
                share * s_y__tmp_130 = ycirc->PutCONSGate( _tmp_130 ,bitlen);
                share * s_y_tmp_129 = ycirc->PutSUBGate( s_y_tmp22 , s_y__tmp_130 );
                uint32_t _tmp_131 = 14 ;
                share * s_y__tmp_131 = ycirc->PutCONSGate( _tmp_131 ,bitlen);
                share * s_y_tmp_128 = ycirc->PutGTGate( s_y__tmp_131 , s_y_tmp_129 );
                uint32_t _tmp_134 = 2 ;
                share * s_y__tmp_134 = ycirc->PutCONSGate( _tmp_134 ,bitlen);
                share * s_y_tmp_133 = ycirc->PutSUBGate( s_y_tmp23 , s_y__tmp_134 );
                uint32_t _tmp_135 = 14 ;
                share * s_y__tmp_135 = ycirc->PutCONSGate( _tmp_135 ,bitlen);
                share * s_y_tmp_132 = ycirc->PutGTGate( s_y__tmp_135 , s_y_tmp_133 );
                share * s_y_tmp_127 = ycirc->PutANDGate( s_y_tmp_128 , s_y_tmp_132 );
                uint32_t _tmp_136 = 0 ;
                share * s_y__tmp_136 = ycirc->PutCONSGate( _tmp_136 ,bitlen);
                s_y_tmp19[i27][i28][i29][i30] = ycirc->PutMUXGate( s_y_tmp18[i27][(i28-2)][(i29-2)][i30] , s_y__tmp_136 , s_y_tmp_127 );
            }
            uint32_t _tmp_137 = 1 ;
            share * s_y__tmp_137 = ycirc->PutCONSGate( _tmp_137 ,bitlen);
            s_y_tmp23 = ycirc->PutADDGate( s_y_tmp23 , s_y__tmp_137 );
        }
        uint32_t _tmp_138 = 1 ;
        share * s_y__tmp_138 = ycirc->PutCONSGate( _tmp_138 ,bitlen);
        s_y_tmp22 = ycirc->PutADDGate( s_y_tmp22 , s_y__tmp_138 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 18 ; _i4++) {
for (int _i7 = 0; _i7 < 18 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
s_a_tmp19[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_tmp19[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 32 ; _i7++) {
for (int _i10 = 0; _i10 < 64 ; _i10++) {
s_a_tmp20[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (uint32_t i27 = 0; i27 < 1; i27++)
{
    for (uint32_t i28 = 0; i28 < 14; i28++)
    {
        for (uint32_t i29 = 0; i29 < 14; i29++)
        {
            for (uint32_t i33 = 0; i33 < 64; i33++)
            {
                tmp24 = 0 ;
                s_a_tmp24 = acirc->PutCONSGate( tmp24 ,bitlen);
                for (uint32_t i31 = 0; i31 < 5; i31++)
                {
                    for (uint32_t i32 = 0; i32 < 5; i32++)
                    {
                        for (uint32_t i30 = 0; i30 < 32; i30++)
                        {
                            s_a_tmp21[i27][i28][i29][i33][tmp24] = acirc->PutMULGate( s_a_tmp19[i27][(i28+i31)][(i29+i32)][i30] , s_a_tmp20[i31][i32][i30][i33] );
                            uint32_t _tmp_139 = 1 ;
                            share * s_a__tmp_139 = acirc->PutCONSGate( _tmp_139 ,bitlen);
                            s_a_tmp24 = acirc->PutADDGate( s_a_tmp24 , s_a__tmp_139 );
                        }
                    }
                }
            }
        }
    }
}
share * s_y_tmp25 ;
share * s_y_tmp26 ;
auto s_y_tmp21 = make_vector<share*>(1, 14, 14, 32, 25);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 14 ; _i4++) {
for (int _i7 = 0; _i7 < 14 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
for (int _i13 = 0; _i13 < 25 ; _i13++) {
s_y_tmp21[_i1][_i4][_i7][_i10][_i13] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4][_i7][_i10][_i13] );
}
}
}
}
}
auto s_y_tmp17 = make_vector<share*>(1, 14, 14, 64);
for (uint32_t i27 = 0; i27 < 1; i27++)
{
    for (uint32_t i28 = 0; i28 < 14; i28++)
    {
        for (uint32_t i29 = 0; i29 < 14; i29++)
        {
            for (uint32_t i33 = 0; i33 < 64; i33++)
            {
                tmp25 = 25 ;
                s_y_tmp25 = ycirc->PutCONSGate( tmp25 ,bitlen);
                for (uint32_t i34 = 0; i34 < 1; i34++)
                {
                    tmp26 = 0 ;
                    s_y_tmp26 = ycirc->PutCONSGate( tmp26 ,bitlen);
                    for (uint32_t i35 = 0; i35 < 13; i35++)
                    {
                        vector<uint32_t> _vec142 = s_y_tmp25->get_wires();
                        _vec142.erase( _vec142.begin(), _vec142.begin() + 1 );
                        share *s_y_tmp_141 = create_new_share( _vec142 , ycirc );
                        share * s_y_tmp_140 = ycirc->PutGTGate( s_y_tmp_141 , s_y_tmp26 );
                        share * s_y_tmp_145 = ycirc->PutADDGate( s_y_tmp21[i27][i28][i29][i33][(2*i35)] , s_y_tmp21[i27][i28][i29][i33][((2*i35)+1)] );
                        uint32_t _tmp_146 = 2147483648 ;
                        share * s_y__tmp_146 = ycirc->PutCONSGate( _tmp_146 ,bitlen);
                        share * s_y_tmp_144 = ycirc->PutGTGate( s_y__tmp_146 , s_y_tmp_145 );
                        share * s_y_tmp_148 = ycirc->PutADDGate( s_y_tmp21[i27][i28][i29][i33][(2*i35)] , s_y_tmp21[i27][i28][i29][i33][((2*i35)+1)] );
                        vector<uint32_t> _vec149 = s_y_tmp_148->get_wires();
                        _vec149.erase( _vec149.begin(), _vec149.begin() + 1 );
                        share *s_y_tmp_147 = create_new_share( _vec149 , ycirc );
                        share * s_y_tmp_153 = ycirc->PutADDGate( s_y_tmp21[i27][i28][i29][i33][(2*i35)] , s_y_tmp21[i27][i28][i29][i33][((2*i35)+1)] );
                        uint32_t _tmp_154 = 4294967295 ;
                        share * s_y__tmp_154 = ycirc->PutCONSGate( _tmp_154 ,bitlen);
                        share * s_y_tmp_152 = ycirc->PutXORGate( s_y_tmp_153 , s_y__tmp_154 );
                        vector<uint32_t> _vec155 = s_y_tmp_152->get_wires();
                        _vec155.erase( _vec155.begin(), _vec155.begin() + 1 );
                        share *s_y_tmp_151 = create_new_share( _vec155 , ycirc );
                        uint32_t _tmp_156 = 4294967295 ;
                        share * s_y__tmp_156 = ycirc->PutCONSGate( _tmp_156 ,bitlen);
                        share * s_y_tmp_150 = ycirc->PutXORGate( s_y_tmp_151 , s_y__tmp_156 );
                        share * s_y_tmp_143 = ycirc->PutMUXGate( s_y_tmp_147 , s_y_tmp_150 , s_y_tmp_144 );
                        vector<uint32_t> _vec161 = s_y_tmp25->get_wires();
                        _vec161.erase( _vec161.begin(), _vec161.begin() + 1 );
                        share *s_y_tmp_160 = create_new_share( _vec161 , ycirc );
                        share * s_y_tmp_159 = ycirc->PutEQGate( s_y_tmp26 , s_y_tmp_160 );
                        uint32_t _tmp_164 = 1 ;
                        share * s_y__tmp_164 = ycirc->PutCONSGate( _tmp_164 ,bitlen);
                        share * s_y_tmp_163 = ycirc->PutANDGate( s_y_tmp25 , s_y__tmp_164 );
                        uint32_t _tmp_165 = 1 ;
                        share * s_y__tmp_165 = ycirc->PutCONSGate( _tmp_165 ,bitlen);
                        share * s_y_tmp_162 = ycirc->PutEQGate( s_y_tmp_163 , s_y__tmp_165 );
                        share * s_y_tmp_158 = ycirc->PutANDGate( s_y_tmp_159 , s_y_tmp_162 );
                        uint32_t _tmp_168 = 2147483648 ;
                        share * s_y__tmp_168 = ycirc->PutCONSGate( _tmp_168 ,bitlen);
                        share * s_y_tmp_167 = ycirc->PutGTGate( s_y__tmp_168 , s_y_tmp21[i27][i28][i29][i33][(2*i35)] );
                        vector<uint32_t> _vec170 = s_y_tmp21[i27][i28][i29][i33][(2*i35)]->get_wires();
                        _vec170.erase( _vec170.begin(), _vec170.begin() + 1 );
                        share *s_y_tmp_169 = create_new_share( _vec170 , ycirc );
                        uint32_t _tmp_174 = 4294967295 ;
                        share * s_y__tmp_174 = ycirc->PutCONSGate( _tmp_174 ,bitlen);
                        share * s_y_tmp_173 = ycirc->PutXORGate( s_y_tmp21[i27][i28][i29][i33][(2*i35)] , s_y__tmp_174 );
                        vector<uint32_t> _vec175 = s_y_tmp_173->get_wires();
                        _vec175.erase( _vec175.begin(), _vec175.begin() + 1 );
                        share *s_y_tmp_172 = create_new_share( _vec175 , ycirc );
                        uint32_t _tmp_176 = 4294967295 ;
                        share * s_y__tmp_176 = ycirc->PutCONSGate( _tmp_176 ,bitlen);
                        share * s_y_tmp_171 = ycirc->PutXORGate( s_y_tmp_172 , s_y__tmp_176 );
                        share * s_y_tmp_166 = ycirc->PutMUXGate( s_y_tmp_169 , s_y_tmp_171 , s_y_tmp_167 );
                        uint32_t _tmp_177 = 0 ;
                        share * s_y__tmp_177 = ycirc->PutCONSGate( _tmp_177 ,bitlen);
                        share * s_y_tmp_157 = ycirc->PutMUXGate( s_y_tmp_166 , s_y__tmp_177 , s_y_tmp_158 );
                        s_y_tmp21[i27][i28][i29][i33][i35] = ycirc->PutMUXGate( s_y_tmp_143 , s_y_tmp_157 , s_y_tmp_140 );
                        uint32_t _tmp_178 = 1 ;
                        share * s_y__tmp_178 = ycirc->PutCONSGate( _tmp_178 ,bitlen);
                        s_y_tmp26 = ycirc->PutADDGate( s_y_tmp26 , s_y__tmp_178 );
                    }
                    uint32_t _tmp_180 = 1 ;
                    share * s_y__tmp_180 = ycirc->PutCONSGate( _tmp_180 ,bitlen);
                    share * s_y_tmp_179 = ycirc->PutADDGate( s_y_tmp25 , s_y__tmp_180 );
                    vector<uint32_t> _vec181 = s_y_tmp_179->get_wires();
                    _vec181.erase( _vec181.begin(), _vec181.begin() + 1 );
                    s_y_tmp25 = create_new_share( _vec181 , ycirc );
                }
                for (uint32_t i34 = 0; i34 < 9; i34++)
                {
                    tmp26 = 0 ;
                    s_y_tmp26 = ycirc->PutCONSGate( tmp26 ,bitlen);
                    for (uint32_t i35 = 0; i35 < 13; i35++)
                    {
                        vector<uint32_t> _vec184 = s_y_tmp25->get_wires();
                        _vec184.erase( _vec184.begin(), _vec184.begin() + 1 );
                        share *s_y_tmp_183 = create_new_share( _vec184 , ycirc );
                        share * s_y_tmp_182 = ycirc->PutGTGate( s_y_tmp_183 , s_y_tmp26 );
                        share * s_y_tmp_185 = ycirc->PutADDGate( s_y_tmp21[i27][i28][i29][i33][(2*i35)] , s_y_tmp21[i27][i28][i29][i33][((2*i35)+1)] );
                        vector<uint32_t> _vec190 = s_y_tmp25->get_wires();
                        _vec190.erase( _vec190.begin(), _vec190.begin() + 1 );
                        share *s_y_tmp_189 = create_new_share( _vec190 , ycirc );
                        share * s_y_tmp_188 = ycirc->PutEQGate( s_y_tmp26 , s_y_tmp_189 );
                        uint32_t _tmp_193 = 1 ;
                        share * s_y__tmp_193 = ycirc->PutCONSGate( _tmp_193 ,bitlen);
                        share * s_y_tmp_192 = ycirc->PutANDGate( s_y_tmp25 , s_y__tmp_193 );
                        uint32_t _tmp_194 = 1 ;
                        share * s_y__tmp_194 = ycirc->PutCONSGate( _tmp_194 ,bitlen);
                        share * s_y_tmp_191 = ycirc->PutEQGate( s_y_tmp_192 , s_y__tmp_194 );
                        share * s_y_tmp_187 = ycirc->PutANDGate( s_y_tmp_188 , s_y_tmp_191 );
                        uint32_t _tmp_195 = 0 ;
                        share * s_y__tmp_195 = ycirc->PutCONSGate( _tmp_195 ,bitlen);
                        share * s_y_tmp_186 = ycirc->PutMUXGate( s_y_tmp21[i27][i28][i29][i33][(2*i35)] , s_y__tmp_195 , s_y_tmp_187 );
                        s_y_tmp21[i27][i28][i29][i33][i35] = ycirc->PutMUXGate( s_y_tmp_185 , s_y_tmp_186 , s_y_tmp_182 );
                        uint32_t _tmp_196 = 1 ;
                        share * s_y__tmp_196 = ycirc->PutCONSGate( _tmp_196 ,bitlen);
                        s_y_tmp26 = ycirc->PutADDGate( s_y_tmp26 , s_y__tmp_196 );
                    }
                    uint32_t _tmp_198 = 1 ;
                    share * s_y__tmp_198 = ycirc->PutCONSGate( _tmp_198 ,bitlen);
                    share * s_y_tmp_197 = ycirc->PutADDGate( s_y_tmp25 , s_y__tmp_198 );
                    vector<uint32_t> _vec199 = s_y_tmp_197->get_wires();
                    _vec199.erase( _vec199.begin(), _vec199.begin() + 1 );
                    s_y_tmp25 = create_new_share( _vec199 , ycirc );
                }
                s_y_tmp17[i27][i28][i29][i33] = create_new_share(s_y_tmp21[i27][i28][i29][i33][0]->get_wires(), ycirc );
            }
        }
    }
}
share * s_y_tmp28 ;
auto s_y_bbc2 = make_vector<share*>(64);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
s_y_bbc2[_i1] = ycirc->PutA2YGate( s_a_bbc2[_i1] );
}
share * s_y_tmp29 ;
auto s_y_tmp27 = make_vector<share*>(1, 14, 14, 64);
for (uint32_t i36 = 0; i36 < 1; i36++)
{
    for (uint32_t i37 = 0; i37 < 14; i37++)
    {
        for (uint32_t i38 = 0; i38 < 14; i38++)
        {
            for (uint32_t i39 = 0; i39 < 64; i39++)
            {
                s_y_tmp28 = create_new_share(s_y_tmp17[i36][i37][i38][i39]->get_wires(), ycirc );
                uint32_t _tmp_201 = 2147483648 ;
                share * s_y__tmp_201 = ycirc->PutCONSGate( _tmp_201 ,bitlen);
                share * s_y_tmp_200 = ycirc->PutGTGate( s_y__tmp_201 , s_y_bbc2[i39] );
                vector<uint32_t> _vec203 = s_y_bbc2[i39]->get_wires();
                _vec203.erase( _vec203.begin(), _vec203.begin() + 8 );
                share *s_y_tmp_202 = create_new_share( _vec203 , ycirc );
                uint32_t _tmp_207 = 4294967295 ;
                share * s_y__tmp_207 = ycirc->PutCONSGate( _tmp_207 ,bitlen);
                share * s_y_tmp_206 = ycirc->PutXORGate( s_y_bbc2[i39] , s_y__tmp_207 );
                vector<uint32_t> _vec208 = s_y_tmp_206->get_wires();
                _vec208.erase( _vec208.begin(), _vec208.begin() + 8 );
                share *s_y_tmp_205 = create_new_share( _vec208 , ycirc );
                uint32_t _tmp_209 = 4294967295 ;
                share * s_y__tmp_209 = ycirc->PutCONSGate( _tmp_209 ,bitlen);
                share * s_y_tmp_204 = ycirc->PutXORGate( s_y_tmp_205 , s_y__tmp_209 );
                s_y_tmp29 = ycirc->PutMUXGate( s_y_tmp_202 , s_y_tmp_204 , s_y_tmp_200 );
                s_y_tmp27[i36][i37][i38][i39] = ycirc->PutADDGate( s_y_tmp28 , s_y_tmp29 );
                s_y_tmp27[i36][i37][i38][i39] = create_new_share(s_y_tmp27[i36][i37][i38][i39]->get_wires(), ycirc );
            }
        }
    }
}
auto s_y_tmp30 = make_vector<share*>(1, 14, 14, 64);
for (uint32_t i40 = 0; i40 < 1; i40++)
{
    for (uint32_t i41 = 0; i41 < 14; i41++)
    {
        for (uint32_t i42 = 0; i42 < 14; i42++)
        {
            for (uint32_t i43 = 0; i43 < 64; i43++)
            {
                uint32_t _tmp_211 = 2147483648 ;
                share * s_y__tmp_211 = ycirc->PutCONSGate( _tmp_211 ,bitlen);
                share * s_y_tmp_210 = ycirc->PutGTGate( s_y__tmp_211 , s_y_tmp27[i40][i41][i42][i43] );
                uint32_t _tmp_212 = 0 ;
                share * s_y__tmp_212 = ycirc->PutCONSGate( _tmp_212 ,bitlen);
                s_y_tmp30[i40][i41][i42][i43] = ycirc->PutMUXGate( s_y_tmp27[i40][i41][i42][i43] , s_y__tmp_212 , s_y_tmp_210 );
            }
        }
    }
}
share * s_y_tmp32 ;
auto s_y_tmp31 = make_vector<share*>(1, 7, 7, 64);
for (uint32_t i44 = 0; i44 < 1; i44++)
{
    for (uint32_t i45 = 0; i45 < 7; i45++)
    {
        for (uint32_t i46 = 0; i46 < 7; i46++)
        {
            for (uint32_t i47 = 0; i47 < 64; i47++)
            {
                s_y_tmp32 = create_new_share(s_y_tmp30[i44][((2*i45)+0)][((2*i46)+0)][i47]->get_wires(), ycirc );
                for (uint32_t i48 = 0; i48 < 2; i48++)
                {
                    for (uint32_t i49 = 0; i49 < 2; i49++)
                    {
                        share * s_y_tmp_213 = ycirc->PutGTGate( s_y_tmp32 , s_y_tmp30[i44][((2*i45)+i48)][((2*i46)+i49)][i47] );
                        s_y_tmp32 = ycirc->PutMUXGate( s_y_tmp32 , s_y_tmp30[i44][((2*i45)+i48)][((2*i46)+i49)][i47] , s_y_tmp_213 );
                    }
                }
                s_y_tmp31[i44][i45][i46][i47] = create_new_share(s_y_tmp32->get_wires(), ycirc );
            }
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
for (int _i10 = 0; _i10 < 64 ; _i10++) {
s_a_tmp31[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_tmp31[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (uint32_t i50 = 0; i50 < 1; i50++)
{
    for (uint32_t i51 = 0; i51 < 7; i51++)
    {
        for (uint32_t i52 = 0; i52 < 7; i52++)
        {
            for (uint32_t i53 = 0; i53 < 64; i53++)
            {
                s_a_tmp33[0][(i53+((i52*64)+((i51*448)+(i50*3136))))] = create_new_share(s_a_tmp31[i50][i51][i52][i53]->get_wires(), acirc );
            }
        }
    }
}
auto s_y_tmp33 = make_vector<share*>(1, 3136);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 3136 ; _i4++) {
s_y_tmp33[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp33[_i1][_i4] );
}
}
auto s_y_tmp35 = make_vector<share*>(1, 3136);
for (uint32_t i54 = 0; i54 < 1; i54++)
{
    for (uint32_t i55 = 0; i55 < 3136; i55++)
    {
        uint32_t _tmp_215 = 2147483648 ;
        share * s_y__tmp_215 = ycirc->PutCONSGate( _tmp_215 ,bitlen);
        share * s_y_tmp_214 = ycirc->PutGTGate( s_y__tmp_215 , s_y_tmp33[i54][i55] );
        vector<uint32_t> _vec217 = s_y_tmp33[i54][i55]->get_wires();
        _vec217.erase( _vec217.begin(), _vec217.begin() + 15 );
        share *s_y_tmp_216 = create_new_share( _vec217 , ycirc );
        uint32_t _tmp_221 = 4294967295 ;
        share * s_y__tmp_221 = ycirc->PutCONSGate( _tmp_221 ,bitlen);
        share * s_y_tmp_220 = ycirc->PutXORGate( s_y_tmp33[i54][i55] , s_y__tmp_221 );
        vector<uint32_t> _vec222 = s_y_tmp_220->get_wires();
        _vec222.erase( _vec222.begin(), _vec222.begin() + 15 );
        share *s_y_tmp_219 = create_new_share( _vec222 , ycirc );
        uint32_t _tmp_223 = 4294967295 ;
        share * s_y__tmp_223 = ycirc->PutCONSGate( _tmp_223 ,bitlen);
        share * s_y_tmp_218 = ycirc->PutXORGate( s_y_tmp_219 , s_y__tmp_223 );
        s_y_tmp35[i54][i55] = ycirc->PutMUXGate( s_y_tmp_216 , s_y_tmp_218 , s_y_tmp_214 );
    }
}
auto s_y_WWf1 = make_vector<share*>(3136, 1024);
for (int _i1 = 0; _i1 < 3136 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_y_WWf1[_i1][_i4] = ycirc->PutA2YGate( s_a_WWf1[_i1][_i4] );
}
}
auto s_y_tmp36 = make_vector<share*>(3136, 1024);
for (uint32_t i55 = 0; i55 < 3136; i55++)
{
    for (uint32_t i56 = 0; i56 < 1024; i56++)
    {
        uint32_t _tmp_225 = 2147483648 ;
        share * s_y__tmp_225 = ycirc->PutCONSGate( _tmp_225 ,bitlen);
        share * s_y_tmp_224 = ycirc->PutGTGate( s_y__tmp_225 , s_y_WWf1[i55][i56] );
        vector<uint32_t> _vec227 = s_y_WWf1[i55][i56]->get_wires();
        _vec227.erase( _vec227.begin(), _vec227.begin() + 15 );
        share *s_y_tmp_226 = create_new_share( _vec227 , ycirc );
        uint32_t _tmp_231 = 4294967295 ;
        share * s_y__tmp_231 = ycirc->PutCONSGate( _tmp_231 ,bitlen);
        share * s_y_tmp_230 = ycirc->PutXORGate( s_y_WWf1[i55][i56] , s_y__tmp_231 );
        vector<uint32_t> _vec232 = s_y_tmp_230->get_wires();
        _vec232.erase( _vec232.begin(), _vec232.begin() + 15 );
        share *s_y_tmp_229 = create_new_share( _vec232 , ycirc );
        uint32_t _tmp_233 = 4294967295 ;
        share * s_y__tmp_233 = ycirc->PutCONSGate( _tmp_233 ,bitlen);
        share * s_y_tmp_228 = ycirc->PutXORGate( s_y_tmp_229 , s_y__tmp_233 );
        s_y_tmp36[i55][i56] = ycirc->PutMUXGate( s_y_tmp_226 , s_y_tmp_228 , s_y_tmp_224 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 3136 ; _i4++) {
s_a_tmp35[_i1][_i4] = acirc->PutY2AGate( s_y_tmp35[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 3136 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_a_tmp36[_i1][_i4] = acirc->PutY2AGate( s_y_tmp36[_i1][_i4] ,bcirc);
}
}
for (uint32_t i54 = 0; i54 < 1; i54++)
{
    for (uint32_t i56 = 0; i56 < 1024; i56++)
    {
        for (uint32_t i55 = 0; i55 < 3136; i55++)
        {
            s_a_tmp37[i54][i56][i55] = acirc->PutMULGate( s_a_tmp35[i54][i55] , s_a_tmp36[i55][i56] );
        }
    }
}
share * s_y_tmp38 ;
share * s_y_tmp39 ;
auto s_y_tmp37 = make_vector<share*>(1, 1024, 3136);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
for (int _i7 = 0; _i7 < 3136 ; _i7++) {
s_y_tmp37[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp37[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp34 = make_vector<share*>(1, 1024);
for (uint32_t i54 = 0; i54 < 1; i54++)
{
    for (uint32_t i56 = 0; i56 < 1024; i56++)
    {
        tmp38 = 3136 ;
        s_y_tmp38 = ycirc->PutCONSGate( tmp38 ,bitlen);
        for (uint32_t i57 = 0; i57 < 1; i57++)
        {
            tmp39 = 0 ;
            s_y_tmp39 = ycirc->PutCONSGate( tmp39 ,bitlen);
            for (uint32_t i58 = 0; i58 < 1569; i58++)
            {
                vector<uint32_t> _vec236 = s_y_tmp38->get_wires();
                _vec236.erase( _vec236.begin(), _vec236.begin() + 1 );
                share *s_y_tmp_235 = create_new_share( _vec236 , ycirc );
                share * s_y_tmp_234 = ycirc->PutGTGate( s_y_tmp_235 , s_y_tmp39 );
                share * s_y_tmp_239 = ycirc->PutADDGate( s_y_tmp37[i54][i56][(2*i58)] , s_y_tmp37[i54][i56][((2*i58)+1)] );
                uint32_t _tmp_240 = 2147483648 ;
                share * s_y__tmp_240 = ycirc->PutCONSGate( _tmp_240 ,bitlen);
                share * s_y_tmp_238 = ycirc->PutGTGate( s_y__tmp_240 , s_y_tmp_239 );
                share * s_y_tmp_242 = ycirc->PutADDGate( s_y_tmp37[i54][i56][(2*i58)] , s_y_tmp37[i54][i56][((2*i58)+1)] );
                vector<uint32_t> _vec243 = s_y_tmp_242->get_wires();
                _vec243.erase( _vec243.begin(), _vec243.begin() + 1 );
                share *s_y_tmp_241 = create_new_share( _vec243 , ycirc );
                share * s_y_tmp_247 = ycirc->PutADDGate( s_y_tmp37[i54][i56][(2*i58)] , s_y_tmp37[i54][i56][((2*i58)+1)] );
                uint32_t _tmp_248 = 4294967295 ;
                share * s_y__tmp_248 = ycirc->PutCONSGate( _tmp_248 ,bitlen);
                share * s_y_tmp_246 = ycirc->PutXORGate( s_y_tmp_247 , s_y__tmp_248 );
                vector<uint32_t> _vec249 = s_y_tmp_246->get_wires();
                _vec249.erase( _vec249.begin(), _vec249.begin() + 1 );
                share *s_y_tmp_245 = create_new_share( _vec249 , ycirc );
                uint32_t _tmp_250 = 4294967295 ;
                share * s_y__tmp_250 = ycirc->PutCONSGate( _tmp_250 ,bitlen);
                share * s_y_tmp_244 = ycirc->PutXORGate( s_y_tmp_245 , s_y__tmp_250 );
                share * s_y_tmp_237 = ycirc->PutMUXGate( s_y_tmp_241 , s_y_tmp_244 , s_y_tmp_238 );
                vector<uint32_t> _vec255 = s_y_tmp38->get_wires();
                _vec255.erase( _vec255.begin(), _vec255.begin() + 1 );
                share *s_y_tmp_254 = create_new_share( _vec255 , ycirc );
                share * s_y_tmp_253 = ycirc->PutEQGate( s_y_tmp39 , s_y_tmp_254 );
                uint32_t _tmp_258 = 1 ;
                share * s_y__tmp_258 = ycirc->PutCONSGate( _tmp_258 ,bitlen);
                share * s_y_tmp_257 = ycirc->PutANDGate( s_y_tmp38 , s_y__tmp_258 );
                uint32_t _tmp_259 = 1 ;
                share * s_y__tmp_259 = ycirc->PutCONSGate( _tmp_259 ,bitlen);
                share * s_y_tmp_256 = ycirc->PutEQGate( s_y_tmp_257 , s_y__tmp_259 );
                share * s_y_tmp_252 = ycirc->PutANDGate( s_y_tmp_253 , s_y_tmp_256 );
                uint32_t _tmp_262 = 2147483648 ;
                share * s_y__tmp_262 = ycirc->PutCONSGate( _tmp_262 ,bitlen);
                share * s_y_tmp_261 = ycirc->PutGTGate( s_y__tmp_262 , s_y_tmp37[i54][i56][(2*i58)] );
                vector<uint32_t> _vec264 = s_y_tmp37[i54][i56][(2*i58)]->get_wires();
                _vec264.erase( _vec264.begin(), _vec264.begin() + 1 );
                share *s_y_tmp_263 = create_new_share( _vec264 , ycirc );
                uint32_t _tmp_268 = 4294967295 ;
                share * s_y__tmp_268 = ycirc->PutCONSGate( _tmp_268 ,bitlen);
                share * s_y_tmp_267 = ycirc->PutXORGate( s_y_tmp37[i54][i56][(2*i58)] , s_y__tmp_268 );
                vector<uint32_t> _vec269 = s_y_tmp_267->get_wires();
                _vec269.erase( _vec269.begin(), _vec269.begin() + 1 );
                share *s_y_tmp_266 = create_new_share( _vec269 , ycirc );
                uint32_t _tmp_270 = 4294967295 ;
                share * s_y__tmp_270 = ycirc->PutCONSGate( _tmp_270 ,bitlen);
                share * s_y_tmp_265 = ycirc->PutXORGate( s_y_tmp_266 , s_y__tmp_270 );
                share * s_y_tmp_260 = ycirc->PutMUXGate( s_y_tmp_263 , s_y_tmp_265 , s_y_tmp_261 );
                uint32_t _tmp_271 = 0 ;
                share * s_y__tmp_271 = ycirc->PutCONSGate( _tmp_271 ,bitlen);
                share * s_y_tmp_251 = ycirc->PutMUXGate( s_y_tmp_260 , s_y__tmp_271 , s_y_tmp_252 );
                s_y_tmp37[i54][i56][i58] = ycirc->PutMUXGate( s_y_tmp_237 , s_y_tmp_251 , s_y_tmp_234 );
                uint32_t _tmp_272 = 1 ;
                share * s_y__tmp_272 = ycirc->PutCONSGate( _tmp_272 ,bitlen);
                s_y_tmp39 = ycirc->PutADDGate( s_y_tmp39 , s_y__tmp_272 );
            }
            uint32_t _tmp_274 = 1 ;
            share * s_y__tmp_274 = ycirc->PutCONSGate( _tmp_274 ,bitlen);
            share * s_y_tmp_273 = ycirc->PutADDGate( s_y_tmp38 , s_y__tmp_274 );
            vector<uint32_t> _vec275 = s_y_tmp_273->get_wires();
            _vec275.erase( _vec275.begin(), _vec275.begin() + 1 );
            s_y_tmp38 = create_new_share( _vec275 , ycirc );
        }
        for (uint32_t i57 = 0; i57 < 11; i57++)
        {
            tmp39 = 0 ;
            s_y_tmp39 = ycirc->PutCONSGate( tmp39 ,bitlen);
            for (uint32_t i58 = 0; i58 < 1569; i58++)
            {
                vector<uint32_t> _vec278 = s_y_tmp38->get_wires();
                _vec278.erase( _vec278.begin(), _vec278.begin() + 1 );
                share *s_y_tmp_277 = create_new_share( _vec278 , ycirc );
                share * s_y_tmp_276 = ycirc->PutGTGate( s_y_tmp_277 , s_y_tmp39 );
                share * s_y_tmp_279 = ycirc->PutADDGate( s_y_tmp37[i54][i56][(2*i58)] , s_y_tmp37[i54][i56][((2*i58)+1)] );
                vector<uint32_t> _vec284 = s_y_tmp38->get_wires();
                _vec284.erase( _vec284.begin(), _vec284.begin() + 1 );
                share *s_y_tmp_283 = create_new_share( _vec284 , ycirc );
                share * s_y_tmp_282 = ycirc->PutEQGate( s_y_tmp39 , s_y_tmp_283 );
                uint32_t _tmp_287 = 1 ;
                share * s_y__tmp_287 = ycirc->PutCONSGate( _tmp_287 ,bitlen);
                share * s_y_tmp_286 = ycirc->PutANDGate( s_y_tmp38 , s_y__tmp_287 );
                uint32_t _tmp_288 = 1 ;
                share * s_y__tmp_288 = ycirc->PutCONSGate( _tmp_288 ,bitlen);
                share * s_y_tmp_285 = ycirc->PutEQGate( s_y_tmp_286 , s_y__tmp_288 );
                share * s_y_tmp_281 = ycirc->PutANDGate( s_y_tmp_282 , s_y_tmp_285 );
                uint32_t _tmp_289 = 0 ;
                share * s_y__tmp_289 = ycirc->PutCONSGate( _tmp_289 ,bitlen);
                share * s_y_tmp_280 = ycirc->PutMUXGate( s_y_tmp37[i54][i56][(2*i58)] , s_y__tmp_289 , s_y_tmp_281 );
                s_y_tmp37[i54][i56][i58] = ycirc->PutMUXGate( s_y_tmp_279 , s_y_tmp_280 , s_y_tmp_276 );
                uint32_t _tmp_290 = 1 ;
                share * s_y__tmp_290 = ycirc->PutCONSGate( _tmp_290 ,bitlen);
                s_y_tmp39 = ycirc->PutADDGate( s_y_tmp39 , s_y__tmp_290 );
            }
            uint32_t _tmp_292 = 1 ;
            share * s_y__tmp_292 = ycirc->PutCONSGate( _tmp_292 ,bitlen);
            share * s_y_tmp_291 = ycirc->PutADDGate( s_y_tmp38 , s_y__tmp_292 );
            vector<uint32_t> _vec293 = s_y_tmp_291->get_wires();
            _vec293.erase( _vec293.begin(), _vec293.begin() + 1 );
            s_y_tmp38 = create_new_share( _vec293 , ycirc );
        }
        s_y_tmp34[i54][i56] = create_new_share(s_y_tmp37[i54][i56][0]->get_wires(), ycirc );
    }
}
share * s_y_tmp41 ;
auto s_y_bbf1 = make_vector<share*>(1024);
for (int _i1 = 0; _i1 < 1024 ; _i1++) {
s_y_bbf1[_i1] = ycirc->PutA2YGate( s_a_bbf1[_i1] );
}
share * s_y_tmp42 ;
auto s_y_tmp40 = make_vector<share*>(1, 1024);
for (uint32_t i59 = 0; i59 < 1; i59++)
{
    for (uint32_t i60 = 0; i60 < 1024; i60++)
    {
        s_y_tmp41 = create_new_share(s_y_tmp34[i59][i60]->get_wires(), ycirc );
        uint32_t _tmp_295 = 2147483648 ;
        share * s_y__tmp_295 = ycirc->PutCONSGate( _tmp_295 ,bitlen);
        share * s_y_tmp_294 = ycirc->PutGTGate( s_y__tmp_295 , s_y_bbf1[i60] );
        vector<uint32_t> _vec297 = s_y_bbf1[i60]->get_wires();
        _vec297.erase( _vec297.begin(), _vec297.begin() + 8 );
        share *s_y_tmp_296 = create_new_share( _vec297 , ycirc );
        uint32_t _tmp_301 = 4294967295 ;
        share * s_y__tmp_301 = ycirc->PutCONSGate( _tmp_301 ,bitlen);
        share * s_y_tmp_300 = ycirc->PutXORGate( s_y_bbf1[i60] , s_y__tmp_301 );
        vector<uint32_t> _vec302 = s_y_tmp_300->get_wires();
        _vec302.erase( _vec302.begin(), _vec302.begin() + 8 );
        share *s_y_tmp_299 = create_new_share( _vec302 , ycirc );
        uint32_t _tmp_303 = 4294967295 ;
        share * s_y__tmp_303 = ycirc->PutCONSGate( _tmp_303 ,bitlen);
        share * s_y_tmp_298 = ycirc->PutXORGate( s_y_tmp_299 , s_y__tmp_303 );
        s_y_tmp42 = ycirc->PutMUXGate( s_y_tmp_296 , s_y_tmp_298 , s_y_tmp_294 );
        s_y_tmp40[i59][i60] = ycirc->PutADDGate( s_y_tmp41 , s_y_tmp42 );
        s_y_tmp40[i59][i60] = create_new_share(s_y_tmp40[i59][i60]->get_wires(), ycirc );
    }
}
auto s_y_tmp43 = make_vector<share*>(1, 1024);
for (uint32_t i61 = 0; i61 < 1; i61++)
{
    for (uint32_t i62 = 0; i62 < 1024; i62++)
    {
        uint32_t _tmp_305 = 2147483648 ;
        share * s_y__tmp_305 = ycirc->PutCONSGate( _tmp_305 ,bitlen);
        share * s_y_tmp_304 = ycirc->PutGTGate( s_y__tmp_305 , s_y_tmp40[i61][i62] );
        uint32_t _tmp_306 = 0 ;
        share * s_y__tmp_306 = ycirc->PutCONSGate( _tmp_306 ,bitlen);
        s_y_tmp43[i61][i62] = ycirc->PutMUXGate( s_y_tmp40[i61][i62] , s_y__tmp_306 , s_y_tmp_304 );
    }
}
auto s_y_tmp45 = make_vector<share*>(1, 1024);
for (uint32_t i63 = 0; i63 < 1; i63++)
{
    for (uint32_t i64 = 0; i64 < 1024; i64++)
    {
        uint32_t _tmp_308 = 2147483648 ;
        share * s_y__tmp_308 = ycirc->PutCONSGate( _tmp_308 ,bitlen);
        share * s_y_tmp_307 = ycirc->PutGTGate( s_y__tmp_308 , s_y_tmp43[i63][i64] );
        vector<uint32_t> _vec310 = s_y_tmp43[i63][i64]->get_wires();
        _vec310.erase( _vec310.begin(), _vec310.begin() + 15 );
        share *s_y_tmp_309 = create_new_share( _vec310 , ycirc );
        uint32_t _tmp_314 = 4294967295 ;
        share * s_y__tmp_314 = ycirc->PutCONSGate( _tmp_314 ,bitlen);
        share * s_y_tmp_313 = ycirc->PutXORGate( s_y_tmp43[i63][i64] , s_y__tmp_314 );
        vector<uint32_t> _vec315 = s_y_tmp_313->get_wires();
        _vec315.erase( _vec315.begin(), _vec315.begin() + 15 );
        share *s_y_tmp_312 = create_new_share( _vec315 , ycirc );
        uint32_t _tmp_316 = 4294967295 ;
        share * s_y__tmp_316 = ycirc->PutCONSGate( _tmp_316 ,bitlen);
        share * s_y_tmp_311 = ycirc->PutXORGate( s_y_tmp_312 , s_y__tmp_316 );
        s_y_tmp45[i63][i64] = ycirc->PutMUXGate( s_y_tmp_309 , s_y_tmp_311 , s_y_tmp_307 );
    }
}
auto s_y_WWf2 = make_vector<share*>(1024, 10);
for (int _i1 = 0; _i1 < 1024 ; _i1++) {
for (int _i4 = 0; _i4 < 10 ; _i4++) {
s_y_WWf2[_i1][_i4] = ycirc->PutA2YGate( s_a_WWf2[_i1][_i4] );
}
}
auto s_y_tmp46 = make_vector<share*>(1024, 10);
for (uint32_t i64 = 0; i64 < 1024; i64++)
{
    for (uint32_t i65 = 0; i65 < 10; i65++)
    {
        uint32_t _tmp_318 = 2147483648 ;
        share * s_y__tmp_318 = ycirc->PutCONSGate( _tmp_318 ,bitlen);
        share * s_y_tmp_317 = ycirc->PutGTGate( s_y__tmp_318 , s_y_WWf2[i64][i65] );
        vector<uint32_t> _vec320 = s_y_WWf2[i64][i65]->get_wires();
        _vec320.erase( _vec320.begin(), _vec320.begin() + 15 );
        share *s_y_tmp_319 = create_new_share( _vec320 , ycirc );
        uint32_t _tmp_324 = 4294967295 ;
        share * s_y__tmp_324 = ycirc->PutCONSGate( _tmp_324 ,bitlen);
        share * s_y_tmp_323 = ycirc->PutXORGate( s_y_WWf2[i64][i65] , s_y__tmp_324 );
        vector<uint32_t> _vec325 = s_y_tmp_323->get_wires();
        _vec325.erase( _vec325.begin(), _vec325.begin() + 15 );
        share *s_y_tmp_322 = create_new_share( _vec325 , ycirc );
        uint32_t _tmp_326 = 4294967295 ;
        share * s_y__tmp_326 = ycirc->PutCONSGate( _tmp_326 ,bitlen);
        share * s_y_tmp_321 = ycirc->PutXORGate( s_y_tmp_322 , s_y__tmp_326 );
        s_y_tmp46[i64][i65] = ycirc->PutMUXGate( s_y_tmp_319 , s_y_tmp_321 , s_y_tmp_317 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_a_tmp45[_i1][_i4] = acirc->PutY2AGate( s_y_tmp45[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1024 ; _i1++) {
for (int _i4 = 0; _i4 < 10 ; _i4++) {
s_a_tmp46[_i1][_i4] = acirc->PutY2AGate( s_y_tmp46[_i1][_i4] ,bcirc);
}
}
for (uint32_t i63 = 0; i63 < 1; i63++)
{
    for (uint32_t i65 = 0; i65 < 10; i65++)
    {
        for (uint32_t i64 = 0; i64 < 1024; i64++)
        {
            s_a_tmp47[i63][i65][i64] = acirc->PutMULGate( s_a_tmp45[i63][i64] , s_a_tmp46[i64][i65] );
        }
    }
}
share * s_y_tmp48 ;
share * s_y_tmp49 ;
auto s_y_tmp47 = make_vector<share*>(1, 10, 1024);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 10 ; _i4++) {
for (int _i7 = 0; _i7 < 1024 ; _i7++) {
s_y_tmp47[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp47[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp44 = make_vector<share*>(1, 10);
for (uint32_t i63 = 0; i63 < 1; i63++)
{
    for (uint32_t i65 = 0; i65 < 10; i65++)
    {
        tmp48 = 1024 ;
        s_y_tmp48 = ycirc->PutCONSGate( tmp48 ,bitlen);
        for (uint32_t i66 = 0; i66 < 1; i66++)
        {
            tmp49 = 0 ;
            s_y_tmp49 = ycirc->PutCONSGate( tmp49 ,bitlen);
            for (uint32_t i67 = 0; i67 < 513; i67++)
            {
                vector<uint32_t> _vec329 = s_y_tmp48->get_wires();
                _vec329.erase( _vec329.begin(), _vec329.begin() + 1 );
                share *s_y_tmp_328 = create_new_share( _vec329 , ycirc );
                share * s_y_tmp_327 = ycirc->PutGTGate( s_y_tmp_328 , s_y_tmp49 );
                share * s_y_tmp_332 = ycirc->PutADDGate( s_y_tmp47[i63][i65][(2*i67)] , s_y_tmp47[i63][i65][((2*i67)+1)] );
                uint32_t _tmp_333 = 2147483648 ;
                share * s_y__tmp_333 = ycirc->PutCONSGate( _tmp_333 ,bitlen);
                share * s_y_tmp_331 = ycirc->PutGTGate( s_y__tmp_333 , s_y_tmp_332 );
                share * s_y_tmp_335 = ycirc->PutADDGate( s_y_tmp47[i63][i65][(2*i67)] , s_y_tmp47[i63][i65][((2*i67)+1)] );
                vector<uint32_t> _vec336 = s_y_tmp_335->get_wires();
                _vec336.erase( _vec336.begin(), _vec336.begin() + 1 );
                share *s_y_tmp_334 = create_new_share( _vec336 , ycirc );
                share * s_y_tmp_340 = ycirc->PutADDGate( s_y_tmp47[i63][i65][(2*i67)] , s_y_tmp47[i63][i65][((2*i67)+1)] );
                uint32_t _tmp_341 = 4294967295 ;
                share * s_y__tmp_341 = ycirc->PutCONSGate( _tmp_341 ,bitlen);
                share * s_y_tmp_339 = ycirc->PutXORGate( s_y_tmp_340 , s_y__tmp_341 );
                vector<uint32_t> _vec342 = s_y_tmp_339->get_wires();
                _vec342.erase( _vec342.begin(), _vec342.begin() + 1 );
                share *s_y_tmp_338 = create_new_share( _vec342 , ycirc );
                uint32_t _tmp_343 = 4294967295 ;
                share * s_y__tmp_343 = ycirc->PutCONSGate( _tmp_343 ,bitlen);
                share * s_y_tmp_337 = ycirc->PutXORGate( s_y_tmp_338 , s_y__tmp_343 );
                share * s_y_tmp_330 = ycirc->PutMUXGate( s_y_tmp_334 , s_y_tmp_337 , s_y_tmp_331 );
                vector<uint32_t> _vec348 = s_y_tmp48->get_wires();
                _vec348.erase( _vec348.begin(), _vec348.begin() + 1 );
                share *s_y_tmp_347 = create_new_share( _vec348 , ycirc );
                share * s_y_tmp_346 = ycirc->PutEQGate( s_y_tmp49 , s_y_tmp_347 );
                uint32_t _tmp_351 = 1 ;
                share * s_y__tmp_351 = ycirc->PutCONSGate( _tmp_351 ,bitlen);
                share * s_y_tmp_350 = ycirc->PutANDGate( s_y_tmp48 , s_y__tmp_351 );
                uint32_t _tmp_352 = 1 ;
                share * s_y__tmp_352 = ycirc->PutCONSGate( _tmp_352 ,bitlen);
                share * s_y_tmp_349 = ycirc->PutEQGate( s_y_tmp_350 , s_y__tmp_352 );
                share * s_y_tmp_345 = ycirc->PutANDGate( s_y_tmp_346 , s_y_tmp_349 );
                uint32_t _tmp_355 = 2147483648 ;
                share * s_y__tmp_355 = ycirc->PutCONSGate( _tmp_355 ,bitlen);
                share * s_y_tmp_354 = ycirc->PutGTGate( s_y__tmp_355 , s_y_tmp47[i63][i65][(2*i67)] );
                vector<uint32_t> _vec357 = s_y_tmp47[i63][i65][(2*i67)]->get_wires();
                _vec357.erase( _vec357.begin(), _vec357.begin() + 1 );
                share *s_y_tmp_356 = create_new_share( _vec357 , ycirc );
                uint32_t _tmp_361 = 4294967295 ;
                share * s_y__tmp_361 = ycirc->PutCONSGate( _tmp_361 ,bitlen);
                share * s_y_tmp_360 = ycirc->PutXORGate( s_y_tmp47[i63][i65][(2*i67)] , s_y__tmp_361 );
                vector<uint32_t> _vec362 = s_y_tmp_360->get_wires();
                _vec362.erase( _vec362.begin(), _vec362.begin() + 1 );
                share *s_y_tmp_359 = create_new_share( _vec362 , ycirc );
                uint32_t _tmp_363 = 4294967295 ;
                share * s_y__tmp_363 = ycirc->PutCONSGate( _tmp_363 ,bitlen);
                share * s_y_tmp_358 = ycirc->PutXORGate( s_y_tmp_359 , s_y__tmp_363 );
                share * s_y_tmp_353 = ycirc->PutMUXGate( s_y_tmp_356 , s_y_tmp_358 , s_y_tmp_354 );
                uint32_t _tmp_364 = 0 ;
                share * s_y__tmp_364 = ycirc->PutCONSGate( _tmp_364 ,bitlen);
                share * s_y_tmp_344 = ycirc->PutMUXGate( s_y_tmp_353 , s_y__tmp_364 , s_y_tmp_345 );
                s_y_tmp47[i63][i65][i67] = ycirc->PutMUXGate( s_y_tmp_330 , s_y_tmp_344 , s_y_tmp_327 );
                uint32_t _tmp_365 = 1 ;
                share * s_y__tmp_365 = ycirc->PutCONSGate( _tmp_365 ,bitlen);
                s_y_tmp49 = ycirc->PutADDGate( s_y_tmp49 , s_y__tmp_365 );
            }
            uint32_t _tmp_367 = 1 ;
            share * s_y__tmp_367 = ycirc->PutCONSGate( _tmp_367 ,bitlen);
            share * s_y_tmp_366 = ycirc->PutADDGate( s_y_tmp48 , s_y__tmp_367 );
            vector<uint32_t> _vec368 = s_y_tmp_366->get_wires();
            _vec368.erase( _vec368.begin(), _vec368.begin() + 1 );
            s_y_tmp48 = create_new_share( _vec368 , ycirc );
        }
        for (uint32_t i66 = 0; i66 < 9; i66++)
        {
            tmp49 = 0 ;
            s_y_tmp49 = ycirc->PutCONSGate( tmp49 ,bitlen);
            for (uint32_t i67 = 0; i67 < 513; i67++)
            {
                vector<uint32_t> _vec371 = s_y_tmp48->get_wires();
                _vec371.erase( _vec371.begin(), _vec371.begin() + 1 );
                share *s_y_tmp_370 = create_new_share( _vec371 , ycirc );
                share * s_y_tmp_369 = ycirc->PutGTGate( s_y_tmp_370 , s_y_tmp49 );
                share * s_y_tmp_372 = ycirc->PutADDGate( s_y_tmp47[i63][i65][(2*i67)] , s_y_tmp47[i63][i65][((2*i67)+1)] );
                vector<uint32_t> _vec377 = s_y_tmp48->get_wires();
                _vec377.erase( _vec377.begin(), _vec377.begin() + 1 );
                share *s_y_tmp_376 = create_new_share( _vec377 , ycirc );
                share * s_y_tmp_375 = ycirc->PutEQGate( s_y_tmp49 , s_y_tmp_376 );
                uint32_t _tmp_380 = 1 ;
                share * s_y__tmp_380 = ycirc->PutCONSGate( _tmp_380 ,bitlen);
                share * s_y_tmp_379 = ycirc->PutANDGate( s_y_tmp48 , s_y__tmp_380 );
                uint32_t _tmp_381 = 1 ;
                share * s_y__tmp_381 = ycirc->PutCONSGate( _tmp_381 ,bitlen);
                share * s_y_tmp_378 = ycirc->PutEQGate( s_y_tmp_379 , s_y__tmp_381 );
                share * s_y_tmp_374 = ycirc->PutANDGate( s_y_tmp_375 , s_y_tmp_378 );
                uint32_t _tmp_382 = 0 ;
                share * s_y__tmp_382 = ycirc->PutCONSGate( _tmp_382 ,bitlen);
                share * s_y_tmp_373 = ycirc->PutMUXGate( s_y_tmp47[i63][i65][(2*i67)] , s_y__tmp_382 , s_y_tmp_374 );
                s_y_tmp47[i63][i65][i67] = ycirc->PutMUXGate( s_y_tmp_372 , s_y_tmp_373 , s_y_tmp_369 );
                uint32_t _tmp_383 = 1 ;
                share * s_y__tmp_383 = ycirc->PutCONSGate( _tmp_383 ,bitlen);
                s_y_tmp49 = ycirc->PutADDGate( s_y_tmp49 , s_y__tmp_383 );
            }
            uint32_t _tmp_385 = 1 ;
            share * s_y__tmp_385 = ycirc->PutCONSGate( _tmp_385 ,bitlen);
            share * s_y_tmp_384 = ycirc->PutADDGate( s_y_tmp48 , s_y__tmp_385 );
            vector<uint32_t> _vec386 = s_y_tmp_384->get_wires();
            _vec386.erase( _vec386.begin(), _vec386.begin() + 1 );
            s_y_tmp48 = create_new_share( _vec386 , ycirc );
        }
        s_y_tmp44[i63][i65] = create_new_share(s_y_tmp47[i63][i65][0]->get_wires(), ycirc );
    }
}
share * s_y_tmp51 ;
auto s_y_bbf2 = make_vector<share*>(10);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
s_y_bbf2[_i1] = ycirc->PutA2YGate( s_a_bbf2[_i1] );
}
share * s_y_tmp52 ;
auto s_y_tmp50 = make_vector<share*>(1, 10);
for (uint32_t i68 = 0; i68 < 1; i68++)
{
    for (uint32_t i69 = 0; i69 < 10; i69++)
    {
        s_y_tmp51 = create_new_share(s_y_tmp44[i68][i69]->get_wires(), ycirc );
        uint32_t _tmp_388 = 2147483648 ;
        share * s_y__tmp_388 = ycirc->PutCONSGate( _tmp_388 ,bitlen);
        share * s_y_tmp_387 = ycirc->PutGTGate( s_y__tmp_388 , s_y_bbf2[i69] );
        vector<uint32_t> _vec390 = s_y_bbf2[i69]->get_wires();
        _vec390.erase( _vec390.begin(), _vec390.begin() + 7 );
        share *s_y_tmp_389 = create_new_share( _vec390 , ycirc );
        uint32_t _tmp_394 = 4294967295 ;
        share * s_y__tmp_394 = ycirc->PutCONSGate( _tmp_394 ,bitlen);
        share * s_y_tmp_393 = ycirc->PutXORGate( s_y_bbf2[i69] , s_y__tmp_394 );
        vector<uint32_t> _vec395 = s_y_tmp_393->get_wires();
        _vec395.erase( _vec395.begin(), _vec395.begin() + 7 );
        share *s_y_tmp_392 = create_new_share( _vec395 , ycirc );
        uint32_t _tmp_396 = 4294967295 ;
        share * s_y__tmp_396 = ycirc->PutCONSGate( _tmp_396 ,bitlen);
        share * s_y_tmp_391 = ycirc->PutXORGate( s_y_tmp_392 , s_y__tmp_396 );
        s_y_tmp52 = ycirc->PutMUXGate( s_y_tmp_389 , s_y_tmp_391 , s_y_tmp_387 );
        s_y_tmp50[i68][i69] = ycirc->PutADDGate( s_y_tmp51 , s_y_tmp52 );
        s_y_tmp50[i68][i69] = create_new_share(s_y_tmp50[i68][i69]->get_wires(), ycirc );
    }
}
tmp53 = 0 ;
share *s_y_tmp53 = ycirc->PutCONSGate( tmp53 ,bitlen);
tmp54 = 0 ;
share *s_y_tmp54 = ycirc->PutCONSGate( tmp54 ,bitlen);
share *s_y_tmp55 = create_new_share(s_y_tmp50[0][0]->get_wires(), ycirc );
share * s_y_tmp56 ;
for (uint32_t i70 = 0; i70 < 1; i70++)
{
    for (uint32_t i71 = 0; i71 < 10; i71++)
    {
        uint32_t _tmp_398 = 2147483648 ;
        share * s_y__tmp_398 = ycirc->PutCONSGate( _tmp_398 ,bitlen);
        share * s_y_tmp_397 = ycirc->PutGTGate( s_y__tmp_398 , s_y_tmp55 );
        uint32_t _tmp_401 = 2147483648 ;
        share * s_y__tmp_401 = ycirc->PutCONSGate( _tmp_401 ,bitlen);
        share * s_y_tmp_400 = ycirc->PutGTGate( s_y__tmp_401 , s_y_tmp50[i70][i71] );
        share * s_y_tmp_403 = ycirc->PutGTGate( s_y_tmp55 , s_y_tmp50[i70][i71] );
        share * s_y_tmp_402 = ycirc->PutMUXGate( s_y_tmp55 , s_y_tmp50[i70][i71] , s_y_tmp_403 );
        share * s_y_tmp_399 = ycirc->PutMUXGate( s_y_tmp_402 , s_y_tmp55 , s_y_tmp_400 );
        uint32_t _tmp_406 = 2147483648 ;
        share * s_y__tmp_406 = ycirc->PutCONSGate( _tmp_406 ,bitlen);
        share * s_y_tmp_405 = ycirc->PutGTGate( s_y__tmp_406 , s_y_tmp50[i70][i71] );
        share * s_y_tmp_408 = ycirc->PutGTGate( s_y_tmp55 , s_y_tmp50[i70][i71] );
        share * s_y_tmp_407 = ycirc->PutMUXGate( s_y_tmp55 , s_y_tmp50[i70][i71] , s_y_tmp_408 );
        share * s_y_tmp_404 = ycirc->PutMUXGate( s_y_tmp50[i70][i71] , s_y_tmp_407 , s_y_tmp_405 );
        s_y_tmp56 = ycirc->PutMUXGate( s_y_tmp_399 , s_y_tmp_404 , s_y_tmp_397 );
        share * s_y_tmp_409 = ycirc->PutEQGate( s_y_tmp55 , s_y_tmp56 );
        s_y_tmp54 = ycirc->PutMUXGate( s_y_tmp54 , s_y_tmp53 , s_y_tmp_409 );
        s_y_tmp55 = create_new_share(s_y_tmp56->get_wires(), ycirc );
        uint32_t _tmp_410 = 1 ;
        share * s_y__tmp_410 = ycirc->PutCONSGate( _tmp_410 ,bitlen);
        s_y_tmp53 = ycirc->PutADDGate( s_y_tmp53 , s_y__tmp_410 );
    }
}
share * s_y_tmp_411 = ycirc->PutOUTGate( s_y_tmp54 , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_411->get_clear_value<uint32_t>();
