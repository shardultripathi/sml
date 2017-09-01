ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto WW = make_vector<uint32_t>(4, 1, 7);
auto s_a_WW = make_vector<share*>(4, 1, 7);
auto VV = make_vector<uint32_t>(4, 1, 7);
auto s_a_VV = make_vector<share*>(4, 1, 7);
auto TT = make_vector<uint32_t>(4, 1, 7);
auto s_a_TT = make_vector<share*>(4, 1, 7);
auto ZZ = make_vector<uint32_t>(7, 1000);
auto s_a_ZZ = make_vector<share*>(7, 1000);
auto xx = make_vector<uint32_t>(1000, 1);
auto s_a_xx = make_vector<share*>(1000, 1);
uint32_t tmp0;
share *s_a_tmp0;
uint32_t tmp1;
share *s_a_tmp1;
uint32_t cur1;
share *s_a_cur1;
auto tmp2 = make_vector<uint32_t>(1, 7);
auto s_a_tmp2 = make_vector<share*>(1, 7);
uint32_t tmp3;
share *s_a_tmp3;
auto tmp4 = make_vector<uint32_t>(1, 7);
auto s_a_tmp4 = make_vector<share*>(1, 7);
auto tmp5 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp5 = make_vector<share*>(1, 1000);
auto tmp6 = make_vector<uint32_t>(1, 7);
auto s_a_tmp6 = make_vector<share*>(1, 7);
auto tmp7 = make_vector<uint32_t>(7, 1000);
auto s_a_tmp7 = make_vector<share*>(7, 1000);
auto tmp8 = make_vector<uint32_t>(1, 1000, 7);
auto s_a_tmp8 = make_vector<share*>(1, 1000, 7);
uint32_t tmp9;
share *s_a_tmp9;
uint32_t tmp10;
share *s_a_tmp10;
auto tmp11 = make_vector<uint32_t>(1, 1);
auto s_a_tmp11 = make_vector<share*>(1, 1);
auto tmp12 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp12 = make_vector<share*>(1, 1000);
auto tmp13 = make_vector<uint32_t>(1000, 1);
auto s_a_tmp13 = make_vector<share*>(1000, 1);
auto tmp14 = make_vector<uint32_t>(1, 1, 1000);
auto s_a_tmp14 = make_vector<share*>(1, 1, 1000);
uint32_t tmp15;
share *s_a_tmp15;
uint32_t tmp16;
share *s_a_tmp16;
uint32_t tmp17;
share *s_a_tmp17;
uint32_t tmp18;
share *s_a_tmp18;
uint32_t tmp19;
share *s_a_tmp19;
uint32_t tmp20;
share *s_a_tmp20;
uint32_t tmp21;
share *s_a_tmp21;
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
auto tmp27 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp27 = make_vector<share*>(1, 1000);
auto tmp28 = make_vector<uint32_t>(1, 7);
auto s_a_tmp28 = make_vector<share*>(1, 7);
auto tmp29 = make_vector<uint32_t>(7, 1000);
auto s_a_tmp29 = make_vector<share*>(7, 1000);
auto tmp30 = make_vector<uint32_t>(1, 1000, 7);
auto s_a_tmp30 = make_vector<share*>(1, 1000, 7);
uint32_t tmp31;
share *s_a_tmp31;
uint32_t tmp32;
share *s_a_tmp32;
auto tmp33 = make_vector<uint32_t>(1, 1);
auto s_a_tmp33 = make_vector<share*>(1, 1);
auto tmp34 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp34 = make_vector<share*>(1, 1000);
auto tmp35 = make_vector<uint32_t>(1000, 1);
auto s_a_tmp35 = make_vector<share*>(1000, 1);
auto tmp36 = make_vector<uint32_t>(1, 1, 1000);
auto s_a_tmp36 = make_vector<share*>(1, 1, 1000);
uint32_t tmp37;
share *s_a_tmp37;
uint32_t tmp38;
share *s_a_tmp38;
auto tmp39 = make_vector<uint32_t>(1, 1);
auto s_a_tmp39 = make_vector<share*>(1, 1);
auto tmp40 = make_vector<uint32_t>(1, 1);
auto s_a_tmp40 = make_vector<share*>(1, 1);
uint32_t tmp41;
share *s_a_tmp41;
auto tmp42 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp42 = make_vector<share*>(1, 1000);
auto tmp43 = make_vector<uint32_t>(1, 7);
auto s_a_tmp43 = make_vector<share*>(1, 7);
auto tmp44 = make_vector<uint32_t>(7, 1000);
auto s_a_tmp44 = make_vector<share*>(7, 1000);
auto tmp45 = make_vector<uint32_t>(1, 1000, 7);
auto s_a_tmp45 = make_vector<share*>(1, 1000, 7);
uint32_t tmp46;
share *s_a_tmp46;
uint32_t tmp47;
share *s_a_tmp47;
auto tmp48 = make_vector<uint32_t>(1, 1);
auto s_a_tmp48 = make_vector<share*>(1, 1);
auto tmp49 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp49 = make_vector<share*>(1, 1000);
auto tmp50 = make_vector<uint32_t>(1000, 1);
auto s_a_tmp50 = make_vector<share*>(1000, 1);
auto tmp51 = make_vector<uint32_t>(1, 1, 1000);
auto s_a_tmp51 = make_vector<share*>(1, 1, 1000);
uint32_t tmp52;
share *s_a_tmp52;
uint32_t tmp53;
share *s_a_tmp53;
uint32_t cur2;
share *s_a_cur2;
auto tmp54 = make_vector<uint32_t>(1, 7);
auto s_a_tmp54 = make_vector<share*>(1, 7);
uint32_t tmp55;
share *s_a_tmp55;
auto tmp56 = make_vector<uint32_t>(1, 7);
auto s_a_tmp56 = make_vector<share*>(1, 7);
auto tmp57 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp57 = make_vector<share*>(1, 1000);
auto tmp58 = make_vector<uint32_t>(1, 7);
auto s_a_tmp58 = make_vector<share*>(1, 7);
auto tmp59 = make_vector<uint32_t>(7, 1000);
auto s_a_tmp59 = make_vector<share*>(7, 1000);
auto tmp60 = make_vector<uint32_t>(1, 1000, 7);
auto s_a_tmp60 = make_vector<share*>(1, 1000, 7);
uint32_t tmp61;
share *s_a_tmp61;
uint32_t tmp62;
share *s_a_tmp62;
auto tmp63 = make_vector<uint32_t>(1, 1);
auto s_a_tmp63 = make_vector<share*>(1, 1);
auto tmp64 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp64 = make_vector<share*>(1, 1000);
auto tmp65 = make_vector<uint32_t>(1000, 1);
auto s_a_tmp65 = make_vector<share*>(1000, 1);
auto tmp66 = make_vector<uint32_t>(1, 1, 1000);
auto s_a_tmp66 = make_vector<share*>(1, 1, 1000);
uint32_t tmp67;
share *s_a_tmp67;
uint32_t tmp68;
share *s_a_tmp68;
uint32_t tmp69;
share *s_a_tmp69;
uint32_t tmp70;
share *s_a_tmp70;
uint32_t tmp71;
share *s_a_tmp71;
uint32_t tmp72;
share *s_a_tmp72;
uint32_t tmp73;
share *s_a_tmp73;
uint32_t tmp74;
share *s_a_tmp74;
uint32_t tmp75;
share *s_a_tmp75;
uint32_t tmp76;
share *s_a_tmp76;
uint32_t tmp77;
share *s_a_tmp77;
uint32_t tmp78;
share *s_a_tmp78;
auto tmp79 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp79 = make_vector<share*>(1, 1000);
auto tmp80 = make_vector<uint32_t>(1, 7);
auto s_a_tmp80 = make_vector<share*>(1, 7);
auto tmp81 = make_vector<uint32_t>(7, 1000);
auto s_a_tmp81 = make_vector<share*>(7, 1000);
auto tmp82 = make_vector<uint32_t>(1, 1000, 7);
auto s_a_tmp82 = make_vector<share*>(1, 1000, 7);
uint32_t tmp83;
share *s_a_tmp83;
uint32_t tmp84;
share *s_a_tmp84;
auto tmp85 = make_vector<uint32_t>(1, 1);
auto s_a_tmp85 = make_vector<share*>(1, 1);
auto tmp86 = make_vector<uint32_t>(1, 1000);
auto s_a_tmp86 = make_vector<share*>(1, 1000);
auto tmp87 = make_vector<uint32_t>(1000, 1);
auto s_a_tmp87 = make_vector<share*>(1000, 1);
auto tmp88 = make_vector<uint32_t>(1, 1, 1000);
auto s_a_tmp88 = make_vector<share*>(1, 1, 1000);
uint32_t tmp89;
share *s_a_tmp89;
uint32_t tmp90;
share *s_a_tmp90;
auto tmp91 = make_vector<uint32_t>(1, 1);
auto s_a_tmp91 = make_vector<share*>(1, 1);
auto tmp92 = make_vector<uint32_t>(1, 1);
auto s_a_tmp92 = make_vector<share*>(1, 1);
uint32_t tmp93;
share *s_a_tmp93;
auto tmp94 = make_vector<uint32_t>(1, 1);
auto s_a_tmp94 = make_vector<share*>(1, 1);
uint32_t tmp95;
share *s_a_tmp95;
uint32_t tmp96;
share *s_a_tmp96;
tmp0 = 858993459 ;
s_a_tmp0 = acirc->PutCONSGate( tmp0 ,bitlen);
tmp1 = 858993459 ;
s_a_tmp1 = acirc->PutCONSGate( tmp1 ,bitlen);
for (uint32_t i60 = 0; i60 < 4; i60++)
{
    for (uint32_t i61 = 0; i61 < 1; i61++)
    {
        for (uint32_t i62 = 0; i62 < 7; i62++)
        {
            if (role == CLIENT) {
                WW[i60][i61][i62] = 456 ;
                s_a_WW[i60][i61][i62] = acirc->PutINGate( WW[i60][i61][i62] ,bitlen,CLIENT);
            } else {
                s_a_WW[i60][i61][i62] = acirc->PutDummyINGate(bitlen);
            }
        }
    }
}
for (uint32_t i63 = 0; i63 < 4; i63++)
{
    for (uint32_t i64 = 0; i64 < 1; i64++)
    {
        for (uint32_t i65 = 0; i65 < 7; i65++)
        {
            if (role == CLIENT) {
                VV[i63][i64][i65] = 456 ;
                s_a_VV[i63][i64][i65] = acirc->PutINGate( VV[i63][i64][i65] ,bitlen,CLIENT);
            } else {
                s_a_VV[i63][i64][i65] = acirc->PutDummyINGate(bitlen);
            }
        }
    }
}
for (uint32_t i66 = 0; i66 < 4; i66++)
{
    for (uint32_t i67 = 0; i67 < 1; i67++)
    {
        for (uint32_t i68 = 0; i68 < 7; i68++)
        {
            if (role == CLIENT) {
                TT[i66][i67][i68] = 456 ;
                s_a_TT[i66][i67][i68] = acirc->PutINGate( TT[i66][i67][i68] ,bitlen,CLIENT);
            } else {
                s_a_TT[i66][i67][i68] = acirc->PutDummyINGate(bitlen);
            }
        }
    }
}
for (uint32_t i69 = 0; i69 < 7; i69++)
{
    for (uint32_t i70 = 0; i70 < 1000; i70++)
    {
        if (role == CLIENT) {
            ZZ[i69][i70] = 456 ;
            s_a_ZZ[i69][i70] = acirc->PutINGate( ZZ[i69][i70] ,bitlen,CLIENT);
        } else {
            s_a_ZZ[i69][i70] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i71 = 0; i71 < 1000; i71++)
{
    for (uint32_t i72 = 0; i72 < 1; i72++)
    {
        if (role == SERVER) {
            xx[i71][i72] = 123 ;
            s_a_xx[i71][i72] = acirc->PutINGate( xx[i71][i72] ,bitlen,SERVER);
        } else {
            s_a_xx[i71][i72] = acirc->PutDummyINGate(bitlen);
        }
    }
}
cur1 = 1 ;
s_a_cur1 = acirc->PutCONSGate( cur1 ,bitlen);
share *s_y_tmp0 = ycirc->PutA2YGate( s_a_tmp0 );
uint32_t _tmp_1 = 2147483648 ;
share * s_y__tmp_1 = ycirc->PutCONSGate( _tmp_1 ,bitlen);
share * s_y_tmp_0 = ycirc->PutGTGate( s_y__tmp_1 , s_y_tmp0 );
vector<uint32_t> _vec3 = s_y_tmp0->get_wires();
_vec3.erase( _vec3.begin(), _vec3.begin() + 15 );
share *s_y_tmp_2 = create_new_share( _vec3 , ycirc );
uint32_t _tmp_7 = 4294967295 ;
share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
share * s_y_tmp_6 = ycirc->PutXORGate( s_y_tmp0 , s_y__tmp_7 );
vector<uint32_t> _vec8 = s_y_tmp_6->get_wires();
_vec8.erase( _vec8.begin(), _vec8.begin() + 15 );
share *s_y_tmp_5 = create_new_share( _vec8 , ycirc );
uint32_t _tmp_9 = 4294967295 ;
share * s_y__tmp_9 = ycirc->PutCONSGate( _tmp_9 ,bitlen);
share * s_y_tmp_4 = ycirc->PutXORGate( s_y_tmp_5 , s_y__tmp_9 );
share * s_y_tmp3 = ycirc->PutMUXGate( s_y_tmp_2 , s_y_tmp_4 , s_y_tmp_0 );
auto s_y_VV = make_vector<share*>(4, 1, 7);
for (int _i1 = 0; _i1 < 4 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_VV[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_VV[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp4 = make_vector<share*>(1, 7);
for (uint32_t i0 = 0; i0 < 1; i0++)
{
    for (uint32_t i1 = 0; i1 < 7; i1++)
    {
        uint32_t _tmp_11 = 2147483648 ;
        share * s_y__tmp_11 = ycirc->PutCONSGate( _tmp_11 ,bitlen);
        share * s_y_tmp_10 = ycirc->PutGTGate( s_y__tmp_11 , s_y_VV[cur1][i0][i1] );
        vector<uint32_t> _vec13 = s_y_VV[cur1][i0][i1]->get_wires();
        _vec13.erase( _vec13.begin(), _vec13.begin() + 15 );
        share *s_y_tmp_12 = create_new_share( _vec13 , ycirc );
        uint32_t _tmp_17 = 4294967295 ;
        share * s_y__tmp_17 = ycirc->PutCONSGate( _tmp_17 ,bitlen);
        share * s_y_tmp_16 = ycirc->PutXORGate( s_y_VV[cur1][i0][i1] , s_y__tmp_17 );
        vector<uint32_t> _vec18 = s_y_tmp_16->get_wires();
        _vec18.erase( _vec18.begin(), _vec18.begin() + 15 );
        share *s_y_tmp_15 = create_new_share( _vec18 , ycirc );
        uint32_t _tmp_19 = 4294967295 ;
        share * s_y__tmp_19 = ycirc->PutCONSGate( _tmp_19 ,bitlen);
        share * s_y_tmp_14 = ycirc->PutXORGate( s_y_tmp_15 , s_y__tmp_19 );
        s_y_tmp4[i0][i1] = ycirc->PutMUXGate( s_y_tmp_12 , s_y_tmp_14 , s_y_tmp_10 );
    }
}
s_a_tmp3 = acirc->PutY2AGate( s_y_tmp3 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_a_tmp4[_i1][_i4] = acirc->PutY2AGate( s_y_tmp4[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 1; i0++)
{
    for (uint32_t i1 = 0; i1 < 7; i1++)
    {
        s_a_tmp2[i0][i1] = acirc->PutMULGate( s_a_tmp3 , s_a_tmp4[i0][i1] );
    }
}
auto s_y_tmp2 = make_vector<share*>(1, 7);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_y_tmp2[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp2[_i1][_i4] );
}
}
auto s_y_tmp6 = make_vector<share*>(1, 7);
for (uint32_t i2 = 0; i2 < 1; i2++)
{
    for (uint32_t i3 = 0; i3 < 7; i3++)
    {
        uint32_t _tmp_21 = 2147483648 ;
        share * s_y__tmp_21 = ycirc->PutCONSGate( _tmp_21 ,bitlen);
        share * s_y_tmp_20 = ycirc->PutGTGate( s_y__tmp_21 , s_y_tmp2[i2][i3] );
        vector<uint32_t> _vec23 = s_y_tmp2[i2][i3]->get_wires();
        _vec23.erase( _vec23.begin(), _vec23.begin() + 15 );
        share *s_y_tmp_22 = create_new_share( _vec23 , ycirc );
        uint32_t _tmp_27 = 4294967295 ;
        share * s_y__tmp_27 = ycirc->PutCONSGate( _tmp_27 ,bitlen);
        share * s_y_tmp_26 = ycirc->PutXORGate( s_y_tmp2[i2][i3] , s_y__tmp_27 );
        vector<uint32_t> _vec28 = s_y_tmp_26->get_wires();
        _vec28.erase( _vec28.begin(), _vec28.begin() + 15 );
        share *s_y_tmp_25 = create_new_share( _vec28 , ycirc );
        uint32_t _tmp_29 = 4294967295 ;
        share * s_y__tmp_29 = ycirc->PutCONSGate( _tmp_29 ,bitlen);
        share * s_y_tmp_24 = ycirc->PutXORGate( s_y_tmp_25 , s_y__tmp_29 );
        s_y_tmp6[i2][i3] = ycirc->PutMUXGate( s_y_tmp_22 , s_y_tmp_24 , s_y_tmp_20 );
    }
}
auto s_y_ZZ = make_vector<share*>(7, 1000);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_y_ZZ[_i1][_i4] = ycirc->PutA2YGate( s_a_ZZ[_i1][_i4] );
}
}
auto s_y_tmp7 = make_vector<share*>(7, 1000);
for (uint32_t i3 = 0; i3 < 7; i3++)
{
    for (uint32_t i4 = 0; i4 < 1000; i4++)
    {
        uint32_t _tmp_31 = 2147483648 ;
        share * s_y__tmp_31 = ycirc->PutCONSGate( _tmp_31 ,bitlen);
        share * s_y_tmp_30 = ycirc->PutGTGate( s_y__tmp_31 , s_y_ZZ[i3][i4] );
        vector<uint32_t> _vec33 = s_y_ZZ[i3][i4]->get_wires();
        _vec33.erase( _vec33.begin(), _vec33.begin() + 15 );
        share *s_y_tmp_32 = create_new_share( _vec33 , ycirc );
        uint32_t _tmp_37 = 4294967295 ;
        share * s_y__tmp_37 = ycirc->PutCONSGate( _tmp_37 ,bitlen);
        share * s_y_tmp_36 = ycirc->PutXORGate( s_y_ZZ[i3][i4] , s_y__tmp_37 );
        vector<uint32_t> _vec38 = s_y_tmp_36->get_wires();
        _vec38.erase( _vec38.begin(), _vec38.begin() + 15 );
        share *s_y_tmp_35 = create_new_share( _vec38 , ycirc );
        uint32_t _tmp_39 = 4294967295 ;
        share * s_y__tmp_39 = ycirc->PutCONSGate( _tmp_39 ,bitlen);
        share * s_y_tmp_34 = ycirc->PutXORGate( s_y_tmp_35 , s_y__tmp_39 );
        s_y_tmp7[i3][i4] = ycirc->PutMUXGate( s_y_tmp_32 , s_y_tmp_34 , s_y_tmp_30 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_a_tmp6[_i1][_i4] = acirc->PutY2AGate( s_y_tmp6[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i2 = 0; i2 < 1; i2++)
{
    for (uint32_t i4 = 0; i4 < 1000; i4++)
    {
        for (uint32_t i3 = 0; i3 < 7; i3++)
        {
            s_a_tmp8[i2][i4][i3] = acirc->PutMULGate( s_a_tmp6[i2][i3] , s_a_tmp7[i3][i4] );
        }
    }
}
share * s_y_tmp9 ;
share * s_y_tmp10 ;
auto s_y_tmp8 = make_vector<share*>(1, 1000, 7);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_tmp8[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp8[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp5 = make_vector<share*>(1, 1000);
for (uint32_t i2 = 0; i2 < 1; i2++)
{
    for (uint32_t i4 = 0; i4 < 1000; i4++)
    {
        tmp9 = 7 ;
        s_y_tmp9 = ycirc->PutCONSGate( tmp9 ,bitlen);
        for (uint32_t i5 = 0; i5 < 3; i5++)
        {
            tmp10 = 0 ;
            s_y_tmp10 = ycirc->PutCONSGate( tmp10 ,bitlen);
            for (uint32_t i6 = 0; i6 < 4; i6++)
            {
                vector<uint32_t> _vec42 = s_y_tmp9->get_wires();
                _vec42.erase( _vec42.begin(), _vec42.begin() + 1 );
                share *s_y_tmp_41 = create_new_share( _vec42 , ycirc );
                share * s_y_tmp_40 = ycirc->PutGTGate( s_y_tmp_41 , s_y_tmp10 );
                share * s_y_tmp_45 = ycirc->PutADDGate( s_y_tmp8[i2][i4][(2*i6)] , s_y_tmp8[i2][i4][((2*i6)+1)] );
                uint32_t _tmp_46 = 2147483648 ;
                share * s_y__tmp_46 = ycirc->PutCONSGate( _tmp_46 ,bitlen);
                share * s_y_tmp_44 = ycirc->PutGTGate( s_y__tmp_46 , s_y_tmp_45 );
                share * s_y_tmp_48 = ycirc->PutADDGate( s_y_tmp8[i2][i4][(2*i6)] , s_y_tmp8[i2][i4][((2*i6)+1)] );
                vector<uint32_t> _vec49 = s_y_tmp_48->get_wires();
                _vec49.erase( _vec49.begin(), _vec49.begin() + 1 );
                share *s_y_tmp_47 = create_new_share( _vec49 , ycirc );
                share * s_y_tmp_53 = ycirc->PutADDGate( s_y_tmp8[i2][i4][(2*i6)] , s_y_tmp8[i2][i4][((2*i6)+1)] );
                uint32_t _tmp_54 = 4294967295 ;
                share * s_y__tmp_54 = ycirc->PutCONSGate( _tmp_54 ,bitlen);
                share * s_y_tmp_52 = ycirc->PutXORGate( s_y_tmp_53 , s_y__tmp_54 );
                vector<uint32_t> _vec55 = s_y_tmp_52->get_wires();
                _vec55.erase( _vec55.begin(), _vec55.begin() + 1 );
                share *s_y_tmp_51 = create_new_share( _vec55 , ycirc );
                uint32_t _tmp_56 = 4294967295 ;
                share * s_y__tmp_56 = ycirc->PutCONSGate( _tmp_56 ,bitlen);
                share * s_y_tmp_50 = ycirc->PutXORGate( s_y_tmp_51 , s_y__tmp_56 );
                share * s_y_tmp_43 = ycirc->PutMUXGate( s_y_tmp_47 , s_y_tmp_50 , s_y_tmp_44 );
                vector<uint32_t> _vec61 = s_y_tmp9->get_wires();
                _vec61.erase( _vec61.begin(), _vec61.begin() + 1 );
                share *s_y_tmp_60 = create_new_share( _vec61 , ycirc );
                share * s_y_tmp_59 = ycirc->PutEQGate( s_y_tmp10 , s_y_tmp_60 );
                uint32_t _tmp_64 = 1 ;
                share * s_y__tmp_64 = ycirc->PutCONSGate( _tmp_64 ,bitlen);
                share * s_y_tmp_63 = ycirc->PutANDGate( s_y_tmp9 , s_y__tmp_64 );
                uint32_t _tmp_65 = 1 ;
                share * s_y__tmp_65 = ycirc->PutCONSGate( _tmp_65 ,bitlen);
                share * s_y_tmp_62 = ycirc->PutEQGate( s_y_tmp_63 , s_y__tmp_65 );
                share * s_y_tmp_58 = ycirc->PutANDGate( s_y_tmp_59 , s_y_tmp_62 );
                uint32_t _tmp_68 = 2147483648 ;
                share * s_y__tmp_68 = ycirc->PutCONSGate( _tmp_68 ,bitlen);
                share * s_y_tmp_67 = ycirc->PutGTGate( s_y__tmp_68 , s_y_tmp8[i2][i4][(2*i6)] );
                vector<uint32_t> _vec70 = s_y_tmp8[i2][i4][(2*i6)]->get_wires();
                _vec70.erase( _vec70.begin(), _vec70.begin() + 1 );
                share *s_y_tmp_69 = create_new_share( _vec70 , ycirc );
                uint32_t _tmp_74 = 4294967295 ;
                share * s_y__tmp_74 = ycirc->PutCONSGate( _tmp_74 ,bitlen);
                share * s_y_tmp_73 = ycirc->PutXORGate( s_y_tmp8[i2][i4][(2*i6)] , s_y__tmp_74 );
                vector<uint32_t> _vec75 = s_y_tmp_73->get_wires();
                _vec75.erase( _vec75.begin(), _vec75.begin() + 1 );
                share *s_y_tmp_72 = create_new_share( _vec75 , ycirc );
                uint32_t _tmp_76 = 4294967295 ;
                share * s_y__tmp_76 = ycirc->PutCONSGate( _tmp_76 ,bitlen);
                share * s_y_tmp_71 = ycirc->PutXORGate( s_y_tmp_72 , s_y__tmp_76 );
                share * s_y_tmp_66 = ycirc->PutMUXGate( s_y_tmp_69 , s_y_tmp_71 , s_y_tmp_67 );
                uint32_t _tmp_77 = 0 ;
                share * s_y__tmp_77 = ycirc->PutCONSGate( _tmp_77 ,bitlen);
                share * s_y_tmp_57 = ycirc->PutMUXGate( s_y_tmp_66 , s_y__tmp_77 , s_y_tmp_58 );
                s_y_tmp8[i2][i4][i6] = ycirc->PutMUXGate( s_y_tmp_43 , s_y_tmp_57 , s_y_tmp_40 );
                uint32_t _tmp_78 = 1 ;
                share * s_y__tmp_78 = ycirc->PutCONSGate( _tmp_78 ,bitlen);
                s_y_tmp10 = ycirc->PutADDGate( s_y_tmp10 , s_y__tmp_78 );
            }
            uint32_t _tmp_80 = 1 ;
            share * s_y__tmp_80 = ycirc->PutCONSGate( _tmp_80 ,bitlen);
            share * s_y_tmp_79 = ycirc->PutADDGate( s_y_tmp9 , s_y__tmp_80 );
            vector<uint32_t> _vec81 = s_y_tmp_79->get_wires();
            _vec81.erase( _vec81.begin(), _vec81.begin() + 1 );
            s_y_tmp9 = create_new_share( _vec81 , ycirc );
        }
        for (uint32_t i5 = 0; i5 < 0; i5++)
        {
            tmp10 = 0 ;
            s_y_tmp10 = ycirc->PutCONSGate( tmp10 ,bitlen);
            for (uint32_t i6 = 0; i6 < 4; i6++)
            {
                vector<uint32_t> _vec84 = s_y_tmp9->get_wires();
                _vec84.erase( _vec84.begin(), _vec84.begin() + 1 );
                share *s_y_tmp_83 = create_new_share( _vec84 , ycirc );
                share * s_y_tmp_82 = ycirc->PutGTGate( s_y_tmp_83 , s_y_tmp10 );
                share * s_y_tmp_85 = ycirc->PutADDGate( s_y_tmp8[i2][i4][(2*i6)] , s_y_tmp8[i2][i4][((2*i6)+1)] );
                vector<uint32_t> _vec90 = s_y_tmp9->get_wires();
                _vec90.erase( _vec90.begin(), _vec90.begin() + 1 );
                share *s_y_tmp_89 = create_new_share( _vec90 , ycirc );
                share * s_y_tmp_88 = ycirc->PutEQGate( s_y_tmp10 , s_y_tmp_89 );
                uint32_t _tmp_93 = 1 ;
                share * s_y__tmp_93 = ycirc->PutCONSGate( _tmp_93 ,bitlen);
                share * s_y_tmp_92 = ycirc->PutANDGate( s_y_tmp9 , s_y__tmp_93 );
                uint32_t _tmp_94 = 1 ;
                share * s_y__tmp_94 = ycirc->PutCONSGate( _tmp_94 ,bitlen);
                share * s_y_tmp_91 = ycirc->PutEQGate( s_y_tmp_92 , s_y__tmp_94 );
                share * s_y_tmp_87 = ycirc->PutANDGate( s_y_tmp_88 , s_y_tmp_91 );
                uint32_t _tmp_95 = 0 ;
                share * s_y__tmp_95 = ycirc->PutCONSGate( _tmp_95 ,bitlen);
                share * s_y_tmp_86 = ycirc->PutMUXGate( s_y_tmp8[i2][i4][(2*i6)] , s_y__tmp_95 , s_y_tmp_87 );
                s_y_tmp8[i2][i4][i6] = ycirc->PutMUXGate( s_y_tmp_85 , s_y_tmp_86 , s_y_tmp_82 );
                uint32_t _tmp_96 = 1 ;
                share * s_y__tmp_96 = ycirc->PutCONSGate( _tmp_96 ,bitlen);
                s_y_tmp10 = ycirc->PutADDGate( s_y_tmp10 , s_y__tmp_96 );
            }
            uint32_t _tmp_98 = 1 ;
            share * s_y__tmp_98 = ycirc->PutCONSGate( _tmp_98 ,bitlen);
            share * s_y_tmp_97 = ycirc->PutADDGate( s_y_tmp9 , s_y__tmp_98 );
            vector<uint32_t> _vec99 = s_y_tmp_97->get_wires();
            _vec99.erase( _vec99.begin(), _vec99.begin() + 1 );
            s_y_tmp9 = create_new_share( _vec99 , ycirc );
        }
        s_y_tmp5[i2][i4] = create_new_share(s_y_tmp8[i2][i4][0]->get_wires(), ycirc );
    }
}
auto s_y_tmp12 = make_vector<share*>(1, 1000);
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 1000; i8++)
    {
        uint32_t _tmp_101 = 2147483648 ;
        share * s_y__tmp_101 = ycirc->PutCONSGate( _tmp_101 ,bitlen);
        share * s_y_tmp_100 = ycirc->PutGTGate( s_y__tmp_101 , s_y_tmp5[i7][i8] );
        vector<uint32_t> _vec103 = s_y_tmp5[i7][i8]->get_wires();
        _vec103.erase( _vec103.begin(), _vec103.begin() + 15 );
        share *s_y_tmp_102 = create_new_share( _vec103 , ycirc );
        uint32_t _tmp_107 = 4294967295 ;
        share * s_y__tmp_107 = ycirc->PutCONSGate( _tmp_107 ,bitlen);
        share * s_y_tmp_106 = ycirc->PutXORGate( s_y_tmp5[i7][i8] , s_y__tmp_107 );
        vector<uint32_t> _vec108 = s_y_tmp_106->get_wires();
        _vec108.erase( _vec108.begin(), _vec108.begin() + 15 );
        share *s_y_tmp_105 = create_new_share( _vec108 , ycirc );
        uint32_t _tmp_109 = 4294967295 ;
        share * s_y__tmp_109 = ycirc->PutCONSGate( _tmp_109 ,bitlen);
        share * s_y_tmp_104 = ycirc->PutXORGate( s_y_tmp_105 , s_y__tmp_109 );
        s_y_tmp12[i7][i8] = ycirc->PutMUXGate( s_y_tmp_102 , s_y_tmp_104 , s_y_tmp_100 );
    }
}
auto s_y_xx = make_vector<share*>(1000, 1);
for (int _i1 = 0; _i1 < 1000 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_xx[_i1][_i4] = ycirc->PutA2YGate( s_a_xx[_i1][_i4] );
}
}
auto s_y_tmp13 = make_vector<share*>(1000, 1);
for (uint32_t i8 = 0; i8 < 1000; i8++)
{
    for (uint32_t i9 = 0; i9 < 1; i9++)
    {
        uint32_t _tmp_111 = 2147483648 ;
        share * s_y__tmp_111 = ycirc->PutCONSGate( _tmp_111 ,bitlen);
        share * s_y_tmp_110 = ycirc->PutGTGate( s_y__tmp_111 , s_y_xx[i8][i9] );
        vector<uint32_t> _vec113 = s_y_xx[i8][i9]->get_wires();
        _vec113.erase( _vec113.begin(), _vec113.begin() + 15 );
        share *s_y_tmp_112 = create_new_share( _vec113 , ycirc );
        uint32_t _tmp_117 = 4294967295 ;
        share * s_y__tmp_117 = ycirc->PutCONSGate( _tmp_117 ,bitlen);
        share * s_y_tmp_116 = ycirc->PutXORGate( s_y_xx[i8][i9] , s_y__tmp_117 );
        vector<uint32_t> _vec118 = s_y_tmp_116->get_wires();
        _vec118.erase( _vec118.begin(), _vec118.begin() + 15 );
        share *s_y_tmp_115 = create_new_share( _vec118 , ycirc );
        uint32_t _tmp_119 = 4294967295 ;
        share * s_y__tmp_119 = ycirc->PutCONSGate( _tmp_119 ,bitlen);
        share * s_y_tmp_114 = ycirc->PutXORGate( s_y_tmp_115 , s_y__tmp_119 );
        s_y_tmp13[i8][i9] = ycirc->PutMUXGate( s_y_tmp_112 , s_y_tmp_114 , s_y_tmp_110 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp12[_i1][_i4] = acirc->PutY2AGate( s_y_tmp12[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1000 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i9 = 0; i9 < 1; i9++)
    {
        for (uint32_t i8 = 0; i8 < 1000; i8++)
        {
            s_a_tmp14[i7][i9][i8] = acirc->PutMULGate( s_a_tmp12[i7][i8] , s_a_tmp13[i8][i9] );
        }
    }
}
share * s_y_tmp15 ;
share * s_y_tmp16 ;
auto s_y_tmp14 = make_vector<share*>(1, 1, 1000);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1000 ; _i7++) {
s_y_tmp14[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp14[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp11 = make_vector<share*>(1, 1);
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i9 = 0; i9 < 1; i9++)
    {
        tmp15 = 1000 ;
        s_y_tmp15 = ycirc->PutCONSGate( tmp15 ,bitlen);
        for (uint32_t i10 = 0; i10 < 2; i10++)
        {
            tmp16 = 0 ;
            s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
            for (uint32_t i11 = 0; i11 < 501; i11++)
            {
                vector<uint32_t> _vec122 = s_y_tmp15->get_wires();
                _vec122.erase( _vec122.begin(), _vec122.begin() + 1 );
                share *s_y_tmp_121 = create_new_share( _vec122 , ycirc );
                share * s_y_tmp_120 = ycirc->PutGTGate( s_y_tmp_121 , s_y_tmp16 );
                share * s_y_tmp_125 = ycirc->PutADDGate( s_y_tmp14[i7][i9][(2*i11)] , s_y_tmp14[i7][i9][((2*i11)+1)] );
                uint32_t _tmp_126 = 2147483648 ;
                share * s_y__tmp_126 = ycirc->PutCONSGate( _tmp_126 ,bitlen);
                share * s_y_tmp_124 = ycirc->PutGTGate( s_y__tmp_126 , s_y_tmp_125 );
                share * s_y_tmp_128 = ycirc->PutADDGate( s_y_tmp14[i7][i9][(2*i11)] , s_y_tmp14[i7][i9][((2*i11)+1)] );
                vector<uint32_t> _vec129 = s_y_tmp_128->get_wires();
                _vec129.erase( _vec129.begin(), _vec129.begin() + 1 );
                share *s_y_tmp_127 = create_new_share( _vec129 , ycirc );
                share * s_y_tmp_133 = ycirc->PutADDGate( s_y_tmp14[i7][i9][(2*i11)] , s_y_tmp14[i7][i9][((2*i11)+1)] );
                uint32_t _tmp_134 = 4294967295 ;
                share * s_y__tmp_134 = ycirc->PutCONSGate( _tmp_134 ,bitlen);
                share * s_y_tmp_132 = ycirc->PutXORGate( s_y_tmp_133 , s_y__tmp_134 );
                vector<uint32_t> _vec135 = s_y_tmp_132->get_wires();
                _vec135.erase( _vec135.begin(), _vec135.begin() + 1 );
                share *s_y_tmp_131 = create_new_share( _vec135 , ycirc );
                uint32_t _tmp_136 = 4294967295 ;
                share * s_y__tmp_136 = ycirc->PutCONSGate( _tmp_136 ,bitlen);
                share * s_y_tmp_130 = ycirc->PutXORGate( s_y_tmp_131 , s_y__tmp_136 );
                share * s_y_tmp_123 = ycirc->PutMUXGate( s_y_tmp_127 , s_y_tmp_130 , s_y_tmp_124 );
                vector<uint32_t> _vec141 = s_y_tmp15->get_wires();
                _vec141.erase( _vec141.begin(), _vec141.begin() + 1 );
                share *s_y_tmp_140 = create_new_share( _vec141 , ycirc );
                share * s_y_tmp_139 = ycirc->PutEQGate( s_y_tmp16 , s_y_tmp_140 );
                uint32_t _tmp_144 = 1 ;
                share * s_y__tmp_144 = ycirc->PutCONSGate( _tmp_144 ,bitlen);
                share * s_y_tmp_143 = ycirc->PutANDGate( s_y_tmp15 , s_y__tmp_144 );
                uint32_t _tmp_145 = 1 ;
                share * s_y__tmp_145 = ycirc->PutCONSGate( _tmp_145 ,bitlen);
                share * s_y_tmp_142 = ycirc->PutEQGate( s_y_tmp_143 , s_y__tmp_145 );
                share * s_y_tmp_138 = ycirc->PutANDGate( s_y_tmp_139 , s_y_tmp_142 );
                uint32_t _tmp_148 = 2147483648 ;
                share * s_y__tmp_148 = ycirc->PutCONSGate( _tmp_148 ,bitlen);
                share * s_y_tmp_147 = ycirc->PutGTGate( s_y__tmp_148 , s_y_tmp14[i7][i9][(2*i11)] );
                vector<uint32_t> _vec150 = s_y_tmp14[i7][i9][(2*i11)]->get_wires();
                _vec150.erase( _vec150.begin(), _vec150.begin() + 1 );
                share *s_y_tmp_149 = create_new_share( _vec150 , ycirc );
                uint32_t _tmp_154 = 4294967295 ;
                share * s_y__tmp_154 = ycirc->PutCONSGate( _tmp_154 ,bitlen);
                share * s_y_tmp_153 = ycirc->PutXORGate( s_y_tmp14[i7][i9][(2*i11)] , s_y__tmp_154 );
                vector<uint32_t> _vec155 = s_y_tmp_153->get_wires();
                _vec155.erase( _vec155.begin(), _vec155.begin() + 1 );
                share *s_y_tmp_152 = create_new_share( _vec155 , ycirc );
                uint32_t _tmp_156 = 4294967295 ;
                share * s_y__tmp_156 = ycirc->PutCONSGate( _tmp_156 ,bitlen);
                share * s_y_tmp_151 = ycirc->PutXORGate( s_y_tmp_152 , s_y__tmp_156 );
                share * s_y_tmp_146 = ycirc->PutMUXGate( s_y_tmp_149 , s_y_tmp_151 , s_y_tmp_147 );
                uint32_t _tmp_157 = 0 ;
                share * s_y__tmp_157 = ycirc->PutCONSGate( _tmp_157 ,bitlen);
                share * s_y_tmp_137 = ycirc->PutMUXGate( s_y_tmp_146 , s_y__tmp_157 , s_y_tmp_138 );
                s_y_tmp14[i7][i9][i11] = ycirc->PutMUXGate( s_y_tmp_123 , s_y_tmp_137 , s_y_tmp_120 );
                uint32_t _tmp_158 = 1 ;
                share * s_y__tmp_158 = ycirc->PutCONSGate( _tmp_158 ,bitlen);
                s_y_tmp16 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_158 );
            }
            uint32_t _tmp_160 = 1 ;
            share * s_y__tmp_160 = ycirc->PutCONSGate( _tmp_160 ,bitlen);
            share * s_y_tmp_159 = ycirc->PutADDGate( s_y_tmp15 , s_y__tmp_160 );
            vector<uint32_t> _vec161 = s_y_tmp_159->get_wires();
            _vec161.erase( _vec161.begin(), _vec161.begin() + 1 );
            s_y_tmp15 = create_new_share( _vec161 , ycirc );
        }
        for (uint32_t i10 = 0; i10 < 8; i10++)
        {
            tmp16 = 0 ;
            s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
            for (uint32_t i11 = 0; i11 < 501; i11++)
            {
                vector<uint32_t> _vec164 = s_y_tmp15->get_wires();
                _vec164.erase( _vec164.begin(), _vec164.begin() + 1 );
                share *s_y_tmp_163 = create_new_share( _vec164 , ycirc );
                share * s_y_tmp_162 = ycirc->PutGTGate( s_y_tmp_163 , s_y_tmp16 );
                share * s_y_tmp_165 = ycirc->PutADDGate( s_y_tmp14[i7][i9][(2*i11)] , s_y_tmp14[i7][i9][((2*i11)+1)] );
                vector<uint32_t> _vec170 = s_y_tmp15->get_wires();
                _vec170.erase( _vec170.begin(), _vec170.begin() + 1 );
                share *s_y_tmp_169 = create_new_share( _vec170 , ycirc );
                share * s_y_tmp_168 = ycirc->PutEQGate( s_y_tmp16 , s_y_tmp_169 );
                uint32_t _tmp_173 = 1 ;
                share * s_y__tmp_173 = ycirc->PutCONSGate( _tmp_173 ,bitlen);
                share * s_y_tmp_172 = ycirc->PutANDGate( s_y_tmp15 , s_y__tmp_173 );
                uint32_t _tmp_174 = 1 ;
                share * s_y__tmp_174 = ycirc->PutCONSGate( _tmp_174 ,bitlen);
                share * s_y_tmp_171 = ycirc->PutEQGate( s_y_tmp_172 , s_y__tmp_174 );
                share * s_y_tmp_167 = ycirc->PutANDGate( s_y_tmp_168 , s_y_tmp_171 );
                uint32_t _tmp_175 = 0 ;
                share * s_y__tmp_175 = ycirc->PutCONSGate( _tmp_175 ,bitlen);
                share * s_y_tmp_166 = ycirc->PutMUXGate( s_y_tmp14[i7][i9][(2*i11)] , s_y__tmp_175 , s_y_tmp_167 );
                s_y_tmp14[i7][i9][i11] = ycirc->PutMUXGate( s_y_tmp_165 , s_y_tmp_166 , s_y_tmp_162 );
                uint32_t _tmp_176 = 1 ;
                share * s_y__tmp_176 = ycirc->PutCONSGate( _tmp_176 ,bitlen);
                s_y_tmp16 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_176 );
            }
            uint32_t _tmp_178 = 1 ;
            share * s_y__tmp_178 = ycirc->PutCONSGate( _tmp_178 ,bitlen);
            share * s_y_tmp_177 = ycirc->PutADDGate( s_y_tmp15 , s_y__tmp_178 );
            vector<uint32_t> _vec179 = s_y_tmp_177->get_wires();
            _vec179.erase( _vec179.begin(), _vec179.begin() + 1 );
            s_y_tmp15 = create_new_share( _vec179 , ycirc );
        }
        s_y_tmp11[i7][i9] = create_new_share(s_y_tmp14[i7][i9][0]->get_wires(), ycirc );
    }
}
share *s_y_tmp18 = create_new_share(s_y_tmp11[0][0]->get_wires(), ycirc );
share *s_y_tmp1 = ycirc->PutA2YGate( s_a_tmp1 );
uint32_t _tmp_181 = 2147483648 ;
share * s_y__tmp_181 = ycirc->PutCONSGate( _tmp_181 ,bitlen);
share * s_y_tmp_180 = ycirc->PutGTGate( s_y__tmp_181 , s_y_tmp1 );
vector<uint32_t> _vec183 = s_y_tmp1->get_wires();
_vec183.erase( _vec183.begin(), _vec183.begin() + 8 );
share *s_y_tmp_182 = create_new_share( _vec183 , ycirc );
uint32_t _tmp_187 = 4294967295 ;
share * s_y__tmp_187 = ycirc->PutCONSGate( _tmp_187 ,bitlen);
share * s_y_tmp_186 = ycirc->PutXORGate( s_y_tmp1 , s_y__tmp_187 );
vector<uint32_t> _vec188 = s_y_tmp_186->get_wires();
_vec188.erase( _vec188.begin(), _vec188.begin() + 8 );
share *s_y_tmp_185 = create_new_share( _vec188 , ycirc );
uint32_t _tmp_189 = 4294967295 ;
share * s_y__tmp_189 = ycirc->PutCONSGate( _tmp_189 ,bitlen);
share * s_y_tmp_184 = ycirc->PutXORGate( s_y_tmp_185 , s_y__tmp_189 );
share * s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_182 , s_y_tmp_184 , s_y_tmp_180 );
s_a_tmp18 = acirc->PutY2AGate( s_y_tmp18 ,bcirc);
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
s_a_tmp17 = acirc->PutSUBGate( s_a_tmp18 , s_a_tmp19 );
s_a_tmp17 = create_new_share(s_a_tmp17->get_wires(), acirc );
share * s_y_tmp_190 = ycirc->PutINVGate( s_y_tmp11[0][0] );
uint32_t _tmp_191 = 1 ;
share * s_a__tmp_191 = acirc->PutCONSGate( _tmp_191 ,bitlen);
share *s_a_tmp_190 = acirc->PutY2AGate( s_y_tmp_190 ,bcirc);
s_a_tmp20 = acirc->PutADDGate( s_a_tmp_190 , s_a__tmp_191 );
s_a_tmp22 = create_new_share(s_a_tmp20->get_wires(), acirc );
uint32_t _tmp_193 = 2147483648 ;
share * s_y__tmp_193 = ycirc->PutCONSGate( _tmp_193 ,bitlen);
share * s_y_tmp_192 = ycirc->PutGTGate( s_y__tmp_193 , s_y_tmp1 );
vector<uint32_t> _vec195 = s_y_tmp1->get_wires();
_vec195.erase( _vec195.begin(), _vec195.begin() + 8 );
share *s_y_tmp_194 = create_new_share( _vec195 , ycirc );
uint32_t _tmp_199 = 4294967295 ;
share * s_y__tmp_199 = ycirc->PutCONSGate( _tmp_199 ,bitlen);
share * s_y_tmp_198 = ycirc->PutXORGate( s_y_tmp1 , s_y__tmp_199 );
vector<uint32_t> _vec200 = s_y_tmp_198->get_wires();
_vec200.erase( _vec200.begin(), _vec200.begin() + 8 );
share *s_y_tmp_197 = create_new_share( _vec200 , ycirc );
uint32_t _tmp_201 = 4294967295 ;
share * s_y__tmp_201 = ycirc->PutCONSGate( _tmp_201 ,bitlen);
share * s_y_tmp_196 = ycirc->PutXORGate( s_y_tmp_197 , s_y__tmp_201 );
share * s_y_tmp23 = ycirc->PutMUXGate( s_y_tmp_194 , s_y_tmp_196 , s_y_tmp_192 );
s_a_tmp23 = acirc->PutY2AGate( s_y_tmp23 ,bcirc);
s_a_tmp21 = acirc->PutSUBGate( s_a_tmp22 , s_a_tmp23 );
s_a_tmp21 = create_new_share(s_a_tmp21->get_wires(), acirc );
share * s_y_tmp_202 = ycirc->PutINVGate( s_y_tmp1 );
uint32_t _tmp_203 = 1 ;
share * s_a__tmp_203 = acirc->PutCONSGate( _tmp_203 ,bitlen);
share *s_a_tmp_202 = acirc->PutY2AGate( s_y_tmp_202 ,bcirc);
s_a_tmp24 = acirc->PutADDGate( s_a_tmp_202 , s_a__tmp_203 );
share *s_y_tmp21 = ycirc->PutA2YGate( s_a_tmp21 );
uint32_t _tmp_205 = 2147483648 ;
share * s_y__tmp_205 = ycirc->PutCONSGate( _tmp_205 ,bitlen);
share * s_y_tmp_204 = ycirc->PutGTGate( s_y__tmp_205 , s_y_tmp21 );
share *s_y_tmp24 = ycirc->PutA2YGate( s_a_tmp24 );
uint32_t _tmp_208 = 2147483648 ;
share * s_y__tmp_208 = ycirc->PutCONSGate( _tmp_208 ,bitlen);
share * s_y_tmp_207 = ycirc->PutGTGate( s_y__tmp_208 , s_y_tmp24 );
vector<uint32_t> _vec210 = s_y_tmp24->get_wires();
_vec210.erase( _vec210.begin(), _vec210.begin() + 8 );
share *s_y_tmp_209 = create_new_share( _vec210 , ycirc );
uint32_t _tmp_214 = 4294967295 ;
share * s_y__tmp_214 = ycirc->PutCONSGate( _tmp_214 ,bitlen);
share * s_y_tmp_213 = ycirc->PutXORGate( s_y_tmp24 , s_y__tmp_214 );
vector<uint32_t> _vec215 = s_y_tmp_213->get_wires();
_vec215.erase( _vec215.begin(), _vec215.begin() + 8 );
share *s_y_tmp_212 = create_new_share( _vec215 , ycirc );
uint32_t _tmp_216 = 4294967295 ;
share * s_y__tmp_216 = ycirc->PutCONSGate( _tmp_216 ,bitlen);
share * s_y_tmp_211 = ycirc->PutXORGate( s_y_tmp_212 , s_y__tmp_216 );
share * s_y_tmp_206 = ycirc->PutMUXGate( s_y_tmp_209 , s_y_tmp_211 , s_y_tmp_207 );
share * s_y_tmp25 = ycirc->PutMUXGate( s_y_tmp_206 , s_y_tmp11[0][0] , s_y_tmp_204 );
share *s_y_tmp17 = ycirc->PutA2YGate( s_a_tmp17 );
uint32_t _tmp_218 = 2147483648 ;
share * s_y__tmp_218 = ycirc->PutCONSGate( _tmp_218 ,bitlen);
share * s_y_tmp_217 = ycirc->PutGTGate( s_y__tmp_218 , s_y_tmp17 );
uint32_t _tmp_221 = 2147483648 ;
share * s_y__tmp_221 = ycirc->PutCONSGate( _tmp_221 ,bitlen);
share * s_y_tmp_220 = ycirc->PutGTGate( s_y__tmp_221 , s_y_tmp1 );
vector<uint32_t> _vec223 = s_y_tmp1->get_wires();
_vec223.erase( _vec223.begin(), _vec223.begin() + 8 );
share *s_y_tmp_222 = create_new_share( _vec223 , ycirc );
uint32_t _tmp_227 = 4294967295 ;
share * s_y__tmp_227 = ycirc->PutCONSGate( _tmp_227 ,bitlen);
share * s_y_tmp_226 = ycirc->PutXORGate( s_y_tmp1 , s_y__tmp_227 );
vector<uint32_t> _vec228 = s_y_tmp_226->get_wires();
_vec228.erase( _vec228.begin(), _vec228.begin() + 8 );
share *s_y_tmp_225 = create_new_share( _vec228 , ycirc );
uint32_t _tmp_229 = 4294967295 ;
share * s_y__tmp_229 = ycirc->PutCONSGate( _tmp_229 ,bitlen);
share * s_y_tmp_224 = ycirc->PutXORGate( s_y_tmp_225 , s_y__tmp_229 );
share * s_y_tmp_219 = ycirc->PutMUXGate( s_y_tmp_222 , s_y_tmp_224 , s_y_tmp_220 );
share * s_y_tmp26 = ycirc->PutMUXGate( s_y_tmp_219 , s_y_tmp25 , s_y_tmp_217 );
auto s_y_WW = make_vector<share*>(4, 1, 7);
for (int _i1 = 0; _i1 < 4 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_WW[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_WW[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp28 = make_vector<share*>(1, 7);
for (uint32_t i12 = 0; i12 < 1; i12++)
{
    for (uint32_t i13 = 0; i13 < 7; i13++)
    {
        uint32_t _tmp_231 = 2147483648 ;
        share * s_y__tmp_231 = ycirc->PutCONSGate( _tmp_231 ,bitlen);
        share * s_y_tmp_230 = ycirc->PutGTGate( s_y__tmp_231 , s_y_WW[cur1][i12][i13] );
        vector<uint32_t> _vec233 = s_y_WW[cur1][i12][i13]->get_wires();
        _vec233.erase( _vec233.begin(), _vec233.begin() + 15 );
        share *s_y_tmp_232 = create_new_share( _vec233 , ycirc );
        uint32_t _tmp_237 = 4294967295 ;
        share * s_y__tmp_237 = ycirc->PutCONSGate( _tmp_237 ,bitlen);
        share * s_y_tmp_236 = ycirc->PutXORGate( s_y_WW[cur1][i12][i13] , s_y__tmp_237 );
        vector<uint32_t> _vec238 = s_y_tmp_236->get_wires();
        _vec238.erase( _vec238.begin(), _vec238.begin() + 15 );
        share *s_y_tmp_235 = create_new_share( _vec238 , ycirc );
        uint32_t _tmp_239 = 4294967295 ;
        share * s_y__tmp_239 = ycirc->PutCONSGate( _tmp_239 ,bitlen);
        share * s_y_tmp_234 = ycirc->PutXORGate( s_y_tmp_235 , s_y__tmp_239 );
        s_y_tmp28[i12][i13] = ycirc->PutMUXGate( s_y_tmp_232 , s_y_tmp_234 , s_y_tmp_230 );
    }
}
auto s_y_tmp29 = make_vector<share*>(7, 1000);
for (uint32_t i13 = 0; i13 < 7; i13++)
{
    for (uint32_t i14 = 0; i14 < 1000; i14++)
    {
        uint32_t _tmp_241 = 2147483648 ;
        share * s_y__tmp_241 = ycirc->PutCONSGate( _tmp_241 ,bitlen);
        share * s_y_tmp_240 = ycirc->PutGTGate( s_y__tmp_241 , s_y_ZZ[i13][i14] );
        vector<uint32_t> _vec243 = s_y_ZZ[i13][i14]->get_wires();
        _vec243.erase( _vec243.begin(), _vec243.begin() + 15 );
        share *s_y_tmp_242 = create_new_share( _vec243 , ycirc );
        uint32_t _tmp_247 = 4294967295 ;
        share * s_y__tmp_247 = ycirc->PutCONSGate( _tmp_247 ,bitlen);
        share * s_y_tmp_246 = ycirc->PutXORGate( s_y_ZZ[i13][i14] , s_y__tmp_247 );
        vector<uint32_t> _vec248 = s_y_tmp_246->get_wires();
        _vec248.erase( _vec248.begin(), _vec248.begin() + 15 );
        share *s_y_tmp_245 = create_new_share( _vec248 , ycirc );
        uint32_t _tmp_249 = 4294967295 ;
        share * s_y__tmp_249 = ycirc->PutCONSGate( _tmp_249 ,bitlen);
        share * s_y_tmp_244 = ycirc->PutXORGate( s_y_tmp_245 , s_y__tmp_249 );
        s_y_tmp29[i13][i14] = ycirc->PutMUXGate( s_y_tmp_242 , s_y_tmp_244 , s_y_tmp_240 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_a_tmp28[_i1][_i4] = acirc->PutY2AGate( s_y_tmp28[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp29[_i1][_i4] = acirc->PutY2AGate( s_y_tmp29[_i1][_i4] ,bcirc);
}
}
for (uint32_t i12 = 0; i12 < 1; i12++)
{
    for (uint32_t i14 = 0; i14 < 1000; i14++)
    {
        for (uint32_t i13 = 0; i13 < 7; i13++)
        {
            s_a_tmp30[i12][i14][i13] = acirc->PutMULGate( s_a_tmp28[i12][i13] , s_a_tmp29[i13][i14] );
        }
    }
}
share * s_y_tmp31 ;
share * s_y_tmp32 ;
auto s_y_tmp30 = make_vector<share*>(1, 1000, 7);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_tmp30[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp30[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp27 = make_vector<share*>(1, 1000);
for (uint32_t i12 = 0; i12 < 1; i12++)
{
    for (uint32_t i14 = 0; i14 < 1000; i14++)
    {
        tmp31 = 7 ;
        s_y_tmp31 = ycirc->PutCONSGate( tmp31 ,bitlen);
        for (uint32_t i15 = 0; i15 < 3; i15++)
        {
            tmp32 = 0 ;
            s_y_tmp32 = ycirc->PutCONSGate( tmp32 ,bitlen);
            for (uint32_t i16 = 0; i16 < 4; i16++)
            {
                vector<uint32_t> _vec252 = s_y_tmp31->get_wires();
                _vec252.erase( _vec252.begin(), _vec252.begin() + 1 );
                share *s_y_tmp_251 = create_new_share( _vec252 , ycirc );
                share * s_y_tmp_250 = ycirc->PutGTGate( s_y_tmp_251 , s_y_tmp32 );
                share * s_y_tmp_255 = ycirc->PutADDGate( s_y_tmp30[i12][i14][(2*i16)] , s_y_tmp30[i12][i14][((2*i16)+1)] );
                uint32_t _tmp_256 = 2147483648 ;
                share * s_y__tmp_256 = ycirc->PutCONSGate( _tmp_256 ,bitlen);
                share * s_y_tmp_254 = ycirc->PutGTGate( s_y__tmp_256 , s_y_tmp_255 );
                share * s_y_tmp_258 = ycirc->PutADDGate( s_y_tmp30[i12][i14][(2*i16)] , s_y_tmp30[i12][i14][((2*i16)+1)] );
                vector<uint32_t> _vec259 = s_y_tmp_258->get_wires();
                _vec259.erase( _vec259.begin(), _vec259.begin() + 1 );
                share *s_y_tmp_257 = create_new_share( _vec259 , ycirc );
                share * s_y_tmp_263 = ycirc->PutADDGate( s_y_tmp30[i12][i14][(2*i16)] , s_y_tmp30[i12][i14][((2*i16)+1)] );
                uint32_t _tmp_264 = 4294967295 ;
                share * s_y__tmp_264 = ycirc->PutCONSGate( _tmp_264 ,bitlen);
                share * s_y_tmp_262 = ycirc->PutXORGate( s_y_tmp_263 , s_y__tmp_264 );
                vector<uint32_t> _vec265 = s_y_tmp_262->get_wires();
                _vec265.erase( _vec265.begin(), _vec265.begin() + 1 );
                share *s_y_tmp_261 = create_new_share( _vec265 , ycirc );
                uint32_t _tmp_266 = 4294967295 ;
                share * s_y__tmp_266 = ycirc->PutCONSGate( _tmp_266 ,bitlen);
                share * s_y_tmp_260 = ycirc->PutXORGate( s_y_tmp_261 , s_y__tmp_266 );
                share * s_y_tmp_253 = ycirc->PutMUXGate( s_y_tmp_257 , s_y_tmp_260 , s_y_tmp_254 );
                vector<uint32_t> _vec271 = s_y_tmp31->get_wires();
                _vec271.erase( _vec271.begin(), _vec271.begin() + 1 );
                share *s_y_tmp_270 = create_new_share( _vec271 , ycirc );
                share * s_y_tmp_269 = ycirc->PutEQGate( s_y_tmp32 , s_y_tmp_270 );
                uint32_t _tmp_274 = 1 ;
                share * s_y__tmp_274 = ycirc->PutCONSGate( _tmp_274 ,bitlen);
                share * s_y_tmp_273 = ycirc->PutANDGate( s_y_tmp31 , s_y__tmp_274 );
                uint32_t _tmp_275 = 1 ;
                share * s_y__tmp_275 = ycirc->PutCONSGate( _tmp_275 ,bitlen);
                share * s_y_tmp_272 = ycirc->PutEQGate( s_y_tmp_273 , s_y__tmp_275 );
                share * s_y_tmp_268 = ycirc->PutANDGate( s_y_tmp_269 , s_y_tmp_272 );
                uint32_t _tmp_278 = 2147483648 ;
                share * s_y__tmp_278 = ycirc->PutCONSGate( _tmp_278 ,bitlen);
                share * s_y_tmp_277 = ycirc->PutGTGate( s_y__tmp_278 , s_y_tmp30[i12][i14][(2*i16)] );
                vector<uint32_t> _vec280 = s_y_tmp30[i12][i14][(2*i16)]->get_wires();
                _vec280.erase( _vec280.begin(), _vec280.begin() + 1 );
                share *s_y_tmp_279 = create_new_share( _vec280 , ycirc );
                uint32_t _tmp_284 = 4294967295 ;
                share * s_y__tmp_284 = ycirc->PutCONSGate( _tmp_284 ,bitlen);
                share * s_y_tmp_283 = ycirc->PutXORGate( s_y_tmp30[i12][i14][(2*i16)] , s_y__tmp_284 );
                vector<uint32_t> _vec285 = s_y_tmp_283->get_wires();
                _vec285.erase( _vec285.begin(), _vec285.begin() + 1 );
                share *s_y_tmp_282 = create_new_share( _vec285 , ycirc );
                uint32_t _tmp_286 = 4294967295 ;
                share * s_y__tmp_286 = ycirc->PutCONSGate( _tmp_286 ,bitlen);
                share * s_y_tmp_281 = ycirc->PutXORGate( s_y_tmp_282 , s_y__tmp_286 );
                share * s_y_tmp_276 = ycirc->PutMUXGate( s_y_tmp_279 , s_y_tmp_281 , s_y_tmp_277 );
                uint32_t _tmp_287 = 0 ;
                share * s_y__tmp_287 = ycirc->PutCONSGate( _tmp_287 ,bitlen);
                share * s_y_tmp_267 = ycirc->PutMUXGate( s_y_tmp_276 , s_y__tmp_287 , s_y_tmp_268 );
                s_y_tmp30[i12][i14][i16] = ycirc->PutMUXGate( s_y_tmp_253 , s_y_tmp_267 , s_y_tmp_250 );
                uint32_t _tmp_288 = 1 ;
                share * s_y__tmp_288 = ycirc->PutCONSGate( _tmp_288 ,bitlen);
                s_y_tmp32 = ycirc->PutADDGate( s_y_tmp32 , s_y__tmp_288 );
            }
            uint32_t _tmp_290 = 1 ;
            share * s_y__tmp_290 = ycirc->PutCONSGate( _tmp_290 ,bitlen);
            share * s_y_tmp_289 = ycirc->PutADDGate( s_y_tmp31 , s_y__tmp_290 );
            vector<uint32_t> _vec291 = s_y_tmp_289->get_wires();
            _vec291.erase( _vec291.begin(), _vec291.begin() + 1 );
            s_y_tmp31 = create_new_share( _vec291 , ycirc );
        }
        for (uint32_t i15 = 0; i15 < 0; i15++)
        {
            tmp32 = 0 ;
            s_y_tmp32 = ycirc->PutCONSGate( tmp32 ,bitlen);
            for (uint32_t i16 = 0; i16 < 4; i16++)
            {
                vector<uint32_t> _vec294 = s_y_tmp31->get_wires();
                _vec294.erase( _vec294.begin(), _vec294.begin() + 1 );
                share *s_y_tmp_293 = create_new_share( _vec294 , ycirc );
                share * s_y_tmp_292 = ycirc->PutGTGate( s_y_tmp_293 , s_y_tmp32 );
                share * s_y_tmp_295 = ycirc->PutADDGate( s_y_tmp30[i12][i14][(2*i16)] , s_y_tmp30[i12][i14][((2*i16)+1)] );
                vector<uint32_t> _vec300 = s_y_tmp31->get_wires();
                _vec300.erase( _vec300.begin(), _vec300.begin() + 1 );
                share *s_y_tmp_299 = create_new_share( _vec300 , ycirc );
                share * s_y_tmp_298 = ycirc->PutEQGate( s_y_tmp32 , s_y_tmp_299 );
                uint32_t _tmp_303 = 1 ;
                share * s_y__tmp_303 = ycirc->PutCONSGate( _tmp_303 ,bitlen);
                share * s_y_tmp_302 = ycirc->PutANDGate( s_y_tmp31 , s_y__tmp_303 );
                uint32_t _tmp_304 = 1 ;
                share * s_y__tmp_304 = ycirc->PutCONSGate( _tmp_304 ,bitlen);
                share * s_y_tmp_301 = ycirc->PutEQGate( s_y_tmp_302 , s_y__tmp_304 );
                share * s_y_tmp_297 = ycirc->PutANDGate( s_y_tmp_298 , s_y_tmp_301 );
                uint32_t _tmp_305 = 0 ;
                share * s_y__tmp_305 = ycirc->PutCONSGate( _tmp_305 ,bitlen);
                share * s_y_tmp_296 = ycirc->PutMUXGate( s_y_tmp30[i12][i14][(2*i16)] , s_y__tmp_305 , s_y_tmp_297 );
                s_y_tmp30[i12][i14][i16] = ycirc->PutMUXGate( s_y_tmp_295 , s_y_tmp_296 , s_y_tmp_292 );
                uint32_t _tmp_306 = 1 ;
                share * s_y__tmp_306 = ycirc->PutCONSGate( _tmp_306 ,bitlen);
                s_y_tmp32 = ycirc->PutADDGate( s_y_tmp32 , s_y__tmp_306 );
            }
            uint32_t _tmp_308 = 1 ;
            share * s_y__tmp_308 = ycirc->PutCONSGate( _tmp_308 ,bitlen);
            share * s_y_tmp_307 = ycirc->PutADDGate( s_y_tmp31 , s_y__tmp_308 );
            vector<uint32_t> _vec309 = s_y_tmp_307->get_wires();
            _vec309.erase( _vec309.begin(), _vec309.begin() + 1 );
            s_y_tmp31 = create_new_share( _vec309 , ycirc );
        }
        s_y_tmp27[i12][i14] = create_new_share(s_y_tmp30[i12][i14][0]->get_wires(), ycirc );
    }
}
auto s_y_tmp34 = make_vector<share*>(1, 1000);
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1000; i18++)
    {
        uint32_t _tmp_311 = 2147483648 ;
        share * s_y__tmp_311 = ycirc->PutCONSGate( _tmp_311 ,bitlen);
        share * s_y_tmp_310 = ycirc->PutGTGate( s_y__tmp_311 , s_y_tmp27[i17][i18] );
        vector<uint32_t> _vec313 = s_y_tmp27[i17][i18]->get_wires();
        _vec313.erase( _vec313.begin(), _vec313.begin() + 15 );
        share *s_y_tmp_312 = create_new_share( _vec313 , ycirc );
        uint32_t _tmp_317 = 4294967295 ;
        share * s_y__tmp_317 = ycirc->PutCONSGate( _tmp_317 ,bitlen);
        share * s_y_tmp_316 = ycirc->PutXORGate( s_y_tmp27[i17][i18] , s_y__tmp_317 );
        vector<uint32_t> _vec318 = s_y_tmp_316->get_wires();
        _vec318.erase( _vec318.begin(), _vec318.begin() + 15 );
        share *s_y_tmp_315 = create_new_share( _vec318 , ycirc );
        uint32_t _tmp_319 = 4294967295 ;
        share * s_y__tmp_319 = ycirc->PutCONSGate( _tmp_319 ,bitlen);
        share * s_y_tmp_314 = ycirc->PutXORGate( s_y_tmp_315 , s_y__tmp_319 );
        s_y_tmp34[i17][i18] = ycirc->PutMUXGate( s_y_tmp_312 , s_y_tmp_314 , s_y_tmp_310 );
    }
}
auto s_y_tmp35 = make_vector<share*>(1000, 1);
for (uint32_t i18 = 0; i18 < 1000; i18++)
{
    for (uint32_t i19 = 0; i19 < 1; i19++)
    {
        uint32_t _tmp_321 = 2147483648 ;
        share * s_y__tmp_321 = ycirc->PutCONSGate( _tmp_321 ,bitlen);
        share * s_y_tmp_320 = ycirc->PutGTGate( s_y__tmp_321 , s_y_xx[i18][i19] );
        vector<uint32_t> _vec323 = s_y_xx[i18][i19]->get_wires();
        _vec323.erase( _vec323.begin(), _vec323.begin() + 15 );
        share *s_y_tmp_322 = create_new_share( _vec323 , ycirc );
        uint32_t _tmp_327 = 4294967295 ;
        share * s_y__tmp_327 = ycirc->PutCONSGate( _tmp_327 ,bitlen);
        share * s_y_tmp_326 = ycirc->PutXORGate( s_y_xx[i18][i19] , s_y__tmp_327 );
        vector<uint32_t> _vec328 = s_y_tmp_326->get_wires();
        _vec328.erase( _vec328.begin(), _vec328.begin() + 15 );
        share *s_y_tmp_325 = create_new_share( _vec328 , ycirc );
        uint32_t _tmp_329 = 4294967295 ;
        share * s_y__tmp_329 = ycirc->PutCONSGate( _tmp_329 ,bitlen);
        share * s_y_tmp_324 = ycirc->PutXORGate( s_y_tmp_325 , s_y__tmp_329 );
        s_y_tmp35[i18][i19] = ycirc->PutMUXGate( s_y_tmp_322 , s_y_tmp_324 , s_y_tmp_320 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp34[_i1][_i4] = acirc->PutY2AGate( s_y_tmp34[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1000 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp35[_i1][_i4] = acirc->PutY2AGate( s_y_tmp35[_i1][_i4] ,bcirc);
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i19 = 0; i19 < 1; i19++)
    {
        for (uint32_t i18 = 0; i18 < 1000; i18++)
        {
            s_a_tmp36[i17][i19][i18] = acirc->PutMULGate( s_a_tmp34[i17][i18] , s_a_tmp35[i18][i19] );
        }
    }
}
share * s_y_tmp37 ;
share * s_y_tmp38 ;
auto s_y_tmp36 = make_vector<share*>(1, 1, 1000);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1000 ; _i7++) {
s_y_tmp36[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp36[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp33 = make_vector<share*>(1, 1);
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i19 = 0; i19 < 1; i19++)
    {
        tmp37 = 1000 ;
        s_y_tmp37 = ycirc->PutCONSGate( tmp37 ,bitlen);
        for (uint32_t i20 = 0; i20 < 0; i20++)
        {
            tmp38 = 0 ;
            s_y_tmp38 = ycirc->PutCONSGate( tmp38 ,bitlen);
            for (uint32_t i21 = 0; i21 < 501; i21++)
            {
                vector<uint32_t> _vec332 = s_y_tmp37->get_wires();
                _vec332.erase( _vec332.begin(), _vec332.begin() + 1 );
                share *s_y_tmp_331 = create_new_share( _vec332 , ycirc );
                share * s_y_tmp_330 = ycirc->PutGTGate( s_y_tmp_331 , s_y_tmp38 );
                share * s_y_tmp_335 = ycirc->PutADDGate( s_y_tmp36[i17][i19][(2*i21)] , s_y_tmp36[i17][i19][((2*i21)+1)] );
                uint32_t _tmp_336 = 2147483648 ;
                share * s_y__tmp_336 = ycirc->PutCONSGate( _tmp_336 ,bitlen);
                share * s_y_tmp_334 = ycirc->PutGTGate( s_y__tmp_336 , s_y_tmp_335 );
                share * s_y_tmp_338 = ycirc->PutADDGate( s_y_tmp36[i17][i19][(2*i21)] , s_y_tmp36[i17][i19][((2*i21)+1)] );
                vector<uint32_t> _vec339 = s_y_tmp_338->get_wires();
                _vec339.erase( _vec339.begin(), _vec339.begin() + 1 );
                share *s_y_tmp_337 = create_new_share( _vec339 , ycirc );
                share * s_y_tmp_343 = ycirc->PutADDGate( s_y_tmp36[i17][i19][(2*i21)] , s_y_tmp36[i17][i19][((2*i21)+1)] );
                uint32_t _tmp_344 = 4294967295 ;
                share * s_y__tmp_344 = ycirc->PutCONSGate( _tmp_344 ,bitlen);
                share * s_y_tmp_342 = ycirc->PutXORGate( s_y_tmp_343 , s_y__tmp_344 );
                vector<uint32_t> _vec345 = s_y_tmp_342->get_wires();
                _vec345.erase( _vec345.begin(), _vec345.begin() + 1 );
                share *s_y_tmp_341 = create_new_share( _vec345 , ycirc );
                uint32_t _tmp_346 = 4294967295 ;
                share * s_y__tmp_346 = ycirc->PutCONSGate( _tmp_346 ,bitlen);
                share * s_y_tmp_340 = ycirc->PutXORGate( s_y_tmp_341 , s_y__tmp_346 );
                share * s_y_tmp_333 = ycirc->PutMUXGate( s_y_tmp_337 , s_y_tmp_340 , s_y_tmp_334 );
                vector<uint32_t> _vec351 = s_y_tmp37->get_wires();
                _vec351.erase( _vec351.begin(), _vec351.begin() + 1 );
                share *s_y_tmp_350 = create_new_share( _vec351 , ycirc );
                share * s_y_tmp_349 = ycirc->PutEQGate( s_y_tmp38 , s_y_tmp_350 );
                uint32_t _tmp_354 = 1 ;
                share * s_y__tmp_354 = ycirc->PutCONSGate( _tmp_354 ,bitlen);
                share * s_y_tmp_353 = ycirc->PutANDGate( s_y_tmp37 , s_y__tmp_354 );
                uint32_t _tmp_355 = 1 ;
                share * s_y__tmp_355 = ycirc->PutCONSGate( _tmp_355 ,bitlen);
                share * s_y_tmp_352 = ycirc->PutEQGate( s_y_tmp_353 , s_y__tmp_355 );
                share * s_y_tmp_348 = ycirc->PutANDGate( s_y_tmp_349 , s_y_tmp_352 );
                uint32_t _tmp_358 = 2147483648 ;
                share * s_y__tmp_358 = ycirc->PutCONSGate( _tmp_358 ,bitlen);
                share * s_y_tmp_357 = ycirc->PutGTGate( s_y__tmp_358 , s_y_tmp36[i17][i19][(2*i21)] );
                vector<uint32_t> _vec360 = s_y_tmp36[i17][i19][(2*i21)]->get_wires();
                _vec360.erase( _vec360.begin(), _vec360.begin() + 1 );
                share *s_y_tmp_359 = create_new_share( _vec360 , ycirc );
                uint32_t _tmp_364 = 4294967295 ;
                share * s_y__tmp_364 = ycirc->PutCONSGate( _tmp_364 ,bitlen);
                share * s_y_tmp_363 = ycirc->PutXORGate( s_y_tmp36[i17][i19][(2*i21)] , s_y__tmp_364 );
                vector<uint32_t> _vec365 = s_y_tmp_363->get_wires();
                _vec365.erase( _vec365.begin(), _vec365.begin() + 1 );
                share *s_y_tmp_362 = create_new_share( _vec365 , ycirc );
                uint32_t _tmp_366 = 4294967295 ;
                share * s_y__tmp_366 = ycirc->PutCONSGate( _tmp_366 ,bitlen);
                share * s_y_tmp_361 = ycirc->PutXORGate( s_y_tmp_362 , s_y__tmp_366 );
                share * s_y_tmp_356 = ycirc->PutMUXGate( s_y_tmp_359 , s_y_tmp_361 , s_y_tmp_357 );
                uint32_t _tmp_367 = 0 ;
                share * s_y__tmp_367 = ycirc->PutCONSGate( _tmp_367 ,bitlen);
                share * s_y_tmp_347 = ycirc->PutMUXGate( s_y_tmp_356 , s_y__tmp_367 , s_y_tmp_348 );
                s_y_tmp36[i17][i19][i21] = ycirc->PutMUXGate( s_y_tmp_333 , s_y_tmp_347 , s_y_tmp_330 );
                uint32_t _tmp_368 = 1 ;
                share * s_y__tmp_368 = ycirc->PutCONSGate( _tmp_368 ,bitlen);
                s_y_tmp38 = ycirc->PutADDGate( s_y_tmp38 , s_y__tmp_368 );
            }
            uint32_t _tmp_370 = 1 ;
            share * s_y__tmp_370 = ycirc->PutCONSGate( _tmp_370 ,bitlen);
            share * s_y_tmp_369 = ycirc->PutADDGate( s_y_tmp37 , s_y__tmp_370 );
            vector<uint32_t> _vec371 = s_y_tmp_369->get_wires();
            _vec371.erase( _vec371.begin(), _vec371.begin() + 1 );
            s_y_tmp37 = create_new_share( _vec371 , ycirc );
        }
        for (uint32_t i20 = 0; i20 < 10; i20++)
        {
            tmp38 = 0 ;
            s_y_tmp38 = ycirc->PutCONSGate( tmp38 ,bitlen);
            for (uint32_t i21 = 0; i21 < 501; i21++)
            {
                vector<uint32_t> _vec374 = s_y_tmp37->get_wires();
                _vec374.erase( _vec374.begin(), _vec374.begin() + 1 );
                share *s_y_tmp_373 = create_new_share( _vec374 , ycirc );
                share * s_y_tmp_372 = ycirc->PutGTGate( s_y_tmp_373 , s_y_tmp38 );
                share * s_y_tmp_375 = ycirc->PutADDGate( s_y_tmp36[i17][i19][(2*i21)] , s_y_tmp36[i17][i19][((2*i21)+1)] );
                vector<uint32_t> _vec380 = s_y_tmp37->get_wires();
                _vec380.erase( _vec380.begin(), _vec380.begin() + 1 );
                share *s_y_tmp_379 = create_new_share( _vec380 , ycirc );
                share * s_y_tmp_378 = ycirc->PutEQGate( s_y_tmp38 , s_y_tmp_379 );
                uint32_t _tmp_383 = 1 ;
                share * s_y__tmp_383 = ycirc->PutCONSGate( _tmp_383 ,bitlen);
                share * s_y_tmp_382 = ycirc->PutANDGate( s_y_tmp37 , s_y__tmp_383 );
                uint32_t _tmp_384 = 1 ;
                share * s_y__tmp_384 = ycirc->PutCONSGate( _tmp_384 ,bitlen);
                share * s_y_tmp_381 = ycirc->PutEQGate( s_y_tmp_382 , s_y__tmp_384 );
                share * s_y_tmp_377 = ycirc->PutANDGate( s_y_tmp_378 , s_y_tmp_381 );
                uint32_t _tmp_385 = 0 ;
                share * s_y__tmp_385 = ycirc->PutCONSGate( _tmp_385 ,bitlen);
                share * s_y_tmp_376 = ycirc->PutMUXGate( s_y_tmp36[i17][i19][(2*i21)] , s_y__tmp_385 , s_y_tmp_377 );
                s_y_tmp36[i17][i19][i21] = ycirc->PutMUXGate( s_y_tmp_375 , s_y_tmp_376 , s_y_tmp_372 );
                uint32_t _tmp_386 = 1 ;
                share * s_y__tmp_386 = ycirc->PutCONSGate( _tmp_386 ,bitlen);
                s_y_tmp38 = ycirc->PutADDGate( s_y_tmp38 , s_y__tmp_386 );
            }
            uint32_t _tmp_388 = 1 ;
            share * s_y__tmp_388 = ycirc->PutCONSGate( _tmp_388 ,bitlen);
            share * s_y_tmp_387 = ycirc->PutADDGate( s_y_tmp37 , s_y__tmp_388 );
            vector<uint32_t> _vec389 = s_y_tmp_387->get_wires();
            _vec389.erase( _vec389.begin(), _vec389.begin() + 1 );
            s_y_tmp37 = create_new_share( _vec389 , ycirc );
        }
        s_y_tmp33[i17][i19] = create_new_share(s_y_tmp36[i17][i19][0]->get_wires(), ycirc );
    }
}
auto s_y_tmp40 = make_vector<share*>(1, 1);
for (uint32_t i22 = 0; i22 < 1; i22++)
{
    for (uint32_t i23 = 0; i23 < 1; i23++)
    {
        uint32_t _tmp_391 = 2147483648 ;
        share * s_y__tmp_391 = ycirc->PutCONSGate( _tmp_391 ,bitlen);
        share * s_y_tmp_390 = ycirc->PutGTGate( s_y__tmp_391 , s_y_tmp33[i22][i23] );
        vector<uint32_t> _vec393 = s_y_tmp33[i22][i23]->get_wires();
        _vec393.erase( _vec393.begin(), _vec393.begin() + 15 );
        share *s_y_tmp_392 = create_new_share( _vec393 , ycirc );
        uint32_t _tmp_397 = 4294967295 ;
        share * s_y__tmp_397 = ycirc->PutCONSGate( _tmp_397 ,bitlen);
        share * s_y_tmp_396 = ycirc->PutXORGate( s_y_tmp33[i22][i23] , s_y__tmp_397 );
        vector<uint32_t> _vec398 = s_y_tmp_396->get_wires();
        _vec398.erase( _vec398.begin(), _vec398.begin() + 15 );
        share *s_y_tmp_395 = create_new_share( _vec398 , ycirc );
        uint32_t _tmp_399 = 4294967295 ;
        share * s_y__tmp_399 = ycirc->PutCONSGate( _tmp_399 ,bitlen);
        share * s_y_tmp_394 = ycirc->PutXORGate( s_y_tmp_395 , s_y__tmp_399 );
        s_y_tmp40[i22][i23] = ycirc->PutMUXGate( s_y_tmp_392 , s_y_tmp_394 , s_y_tmp_390 );
    }
}
uint32_t _tmp_401 = 2147483648 ;
share * s_y__tmp_401 = ycirc->PutCONSGate( _tmp_401 ,bitlen);
share * s_y_tmp_400 = ycirc->PutGTGate( s_y__tmp_401 , s_y_tmp26 );
vector<uint32_t> _vec403 = s_y_tmp26->get_wires();
_vec403.erase( _vec403.begin(), _vec403.begin() + 15 );
share *s_y_tmp_402 = create_new_share( _vec403 , ycirc );
uint32_t _tmp_407 = 4294967295 ;
share * s_y__tmp_407 = ycirc->PutCONSGate( _tmp_407 ,bitlen);
share * s_y_tmp_406 = ycirc->PutXORGate( s_y_tmp26 , s_y__tmp_407 );
vector<uint32_t> _vec408 = s_y_tmp_406->get_wires();
_vec408.erase( _vec408.begin(), _vec408.begin() + 15 );
share *s_y_tmp_405 = create_new_share( _vec408 , ycirc );
uint32_t _tmp_409 = 4294967295 ;
share * s_y__tmp_409 = ycirc->PutCONSGate( _tmp_409 ,bitlen);
share * s_y_tmp_404 = ycirc->PutXORGate( s_y_tmp_405 , s_y__tmp_409 );
share * s_y_tmp41 = ycirc->PutMUXGate( s_y_tmp_402 , s_y_tmp_404 , s_y_tmp_400 );
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp40[_i1][_i4] = acirc->PutY2AGate( s_y_tmp40[_i1][_i4] ,bcirc);
}
}
s_a_tmp41 = acirc->PutY2AGate( s_y_tmp41 ,bcirc);
for (uint32_t i22 = 0; i22 < 1; i22++)
{
    for (uint32_t i23 = 0; i23 < 1; i23++)
    {
        s_a_tmp39[i22][i23] = acirc->PutMULGate( s_a_tmp40[i22][i23] , s_a_tmp41 );
    }
}
auto s_y_TT = make_vector<share*>(4, 1, 7);
for (int _i1 = 0; _i1 < 4 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_TT[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_TT[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp43 = make_vector<share*>(1, 7);
for (uint32_t i24 = 0; i24 < 1; i24++)
{
    for (uint32_t i25 = 0; i25 < 7; i25++)
    {
        uint32_t _tmp_411 = 2147483648 ;
        share * s_y__tmp_411 = ycirc->PutCONSGate( _tmp_411 ,bitlen);
        share * s_y_tmp_410 = ycirc->PutGTGate( s_y__tmp_411 , s_y_TT[cur1][i24][i25] );
        vector<uint32_t> _vec413 = s_y_TT[cur1][i24][i25]->get_wires();
        _vec413.erase( _vec413.begin(), _vec413.begin() + 15 );
        share *s_y_tmp_412 = create_new_share( _vec413 , ycirc );
        uint32_t _tmp_417 = 4294967295 ;
        share * s_y__tmp_417 = ycirc->PutCONSGate( _tmp_417 ,bitlen);
        share * s_y_tmp_416 = ycirc->PutXORGate( s_y_TT[cur1][i24][i25] , s_y__tmp_417 );
        vector<uint32_t> _vec418 = s_y_tmp_416->get_wires();
        _vec418.erase( _vec418.begin(), _vec418.begin() + 15 );
        share *s_y_tmp_415 = create_new_share( _vec418 , ycirc );
        uint32_t _tmp_419 = 4294967295 ;
        share * s_y__tmp_419 = ycirc->PutCONSGate( _tmp_419 ,bitlen);
        share * s_y_tmp_414 = ycirc->PutXORGate( s_y_tmp_415 , s_y__tmp_419 );
        s_y_tmp43[i24][i25] = ycirc->PutMUXGate( s_y_tmp_412 , s_y_tmp_414 , s_y_tmp_410 );
    }
}
auto s_y_tmp44 = make_vector<share*>(7, 1000);
for (uint32_t i25 = 0; i25 < 7; i25++)
{
    for (uint32_t i26 = 0; i26 < 1000; i26++)
    {
        uint32_t _tmp_421 = 2147483648 ;
        share * s_y__tmp_421 = ycirc->PutCONSGate( _tmp_421 ,bitlen);
        share * s_y_tmp_420 = ycirc->PutGTGate( s_y__tmp_421 , s_y_ZZ[i25][i26] );
        vector<uint32_t> _vec423 = s_y_ZZ[i25][i26]->get_wires();
        _vec423.erase( _vec423.begin(), _vec423.begin() + 15 );
        share *s_y_tmp_422 = create_new_share( _vec423 , ycirc );
        uint32_t _tmp_427 = 4294967295 ;
        share * s_y__tmp_427 = ycirc->PutCONSGate( _tmp_427 ,bitlen);
        share * s_y_tmp_426 = ycirc->PutXORGate( s_y_ZZ[i25][i26] , s_y__tmp_427 );
        vector<uint32_t> _vec428 = s_y_tmp_426->get_wires();
        _vec428.erase( _vec428.begin(), _vec428.begin() + 15 );
        share *s_y_tmp_425 = create_new_share( _vec428 , ycirc );
        uint32_t _tmp_429 = 4294967295 ;
        share * s_y__tmp_429 = ycirc->PutCONSGate( _tmp_429 ,bitlen);
        share * s_y_tmp_424 = ycirc->PutXORGate( s_y_tmp_425 , s_y__tmp_429 );
        s_y_tmp44[i25][i26] = ycirc->PutMUXGate( s_y_tmp_422 , s_y_tmp_424 , s_y_tmp_420 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_a_tmp43[_i1][_i4] = acirc->PutY2AGate( s_y_tmp43[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp44[_i1][_i4] = acirc->PutY2AGate( s_y_tmp44[_i1][_i4] ,bcirc);
}
}
for (uint32_t i24 = 0; i24 < 1; i24++)
{
    for (uint32_t i26 = 0; i26 < 1000; i26++)
    {
        for (uint32_t i25 = 0; i25 < 7; i25++)
        {
            s_a_tmp45[i24][i26][i25] = acirc->PutMULGate( s_a_tmp43[i24][i25] , s_a_tmp44[i25][i26] );
        }
    }
}
share * s_y_tmp46 ;
share * s_y_tmp47 ;
auto s_y_tmp45 = make_vector<share*>(1, 1000, 7);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_tmp45[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp45[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp42 = make_vector<share*>(1, 1000);
for (uint32_t i24 = 0; i24 < 1; i24++)
{
    for (uint32_t i26 = 0; i26 < 1000; i26++)
    {
        tmp46 = 7 ;
        s_y_tmp46 = ycirc->PutCONSGate( tmp46 ,bitlen);
        for (uint32_t i27 = 0; i27 < 3; i27++)
        {
            tmp47 = 0 ;
            s_y_tmp47 = ycirc->PutCONSGate( tmp47 ,bitlen);
            for (uint32_t i28 = 0; i28 < 4; i28++)
            {
                vector<uint32_t> _vec432 = s_y_tmp46->get_wires();
                _vec432.erase( _vec432.begin(), _vec432.begin() + 1 );
                share *s_y_tmp_431 = create_new_share( _vec432 , ycirc );
                share * s_y_tmp_430 = ycirc->PutGTGate( s_y_tmp_431 , s_y_tmp47 );
                share * s_y_tmp_435 = ycirc->PutADDGate( s_y_tmp45[i24][i26][(2*i28)] , s_y_tmp45[i24][i26][((2*i28)+1)] );
                uint32_t _tmp_436 = 2147483648 ;
                share * s_y__tmp_436 = ycirc->PutCONSGate( _tmp_436 ,bitlen);
                share * s_y_tmp_434 = ycirc->PutGTGate( s_y__tmp_436 , s_y_tmp_435 );
                share * s_y_tmp_438 = ycirc->PutADDGate( s_y_tmp45[i24][i26][(2*i28)] , s_y_tmp45[i24][i26][((2*i28)+1)] );
                vector<uint32_t> _vec439 = s_y_tmp_438->get_wires();
                _vec439.erase( _vec439.begin(), _vec439.begin() + 1 );
                share *s_y_tmp_437 = create_new_share( _vec439 , ycirc );
                share * s_y_tmp_443 = ycirc->PutADDGate( s_y_tmp45[i24][i26][(2*i28)] , s_y_tmp45[i24][i26][((2*i28)+1)] );
                uint32_t _tmp_444 = 4294967295 ;
                share * s_y__tmp_444 = ycirc->PutCONSGate( _tmp_444 ,bitlen);
                share * s_y_tmp_442 = ycirc->PutXORGate( s_y_tmp_443 , s_y__tmp_444 );
                vector<uint32_t> _vec445 = s_y_tmp_442->get_wires();
                _vec445.erase( _vec445.begin(), _vec445.begin() + 1 );
                share *s_y_tmp_441 = create_new_share( _vec445 , ycirc );
                uint32_t _tmp_446 = 4294967295 ;
                share * s_y__tmp_446 = ycirc->PutCONSGate( _tmp_446 ,bitlen);
                share * s_y_tmp_440 = ycirc->PutXORGate( s_y_tmp_441 , s_y__tmp_446 );
                share * s_y_tmp_433 = ycirc->PutMUXGate( s_y_tmp_437 , s_y_tmp_440 , s_y_tmp_434 );
                vector<uint32_t> _vec451 = s_y_tmp46->get_wires();
                _vec451.erase( _vec451.begin(), _vec451.begin() + 1 );
                share *s_y_tmp_450 = create_new_share( _vec451 , ycirc );
                share * s_y_tmp_449 = ycirc->PutEQGate( s_y_tmp47 , s_y_tmp_450 );
                uint32_t _tmp_454 = 1 ;
                share * s_y__tmp_454 = ycirc->PutCONSGate( _tmp_454 ,bitlen);
                share * s_y_tmp_453 = ycirc->PutANDGate( s_y_tmp46 , s_y__tmp_454 );
                uint32_t _tmp_455 = 1 ;
                share * s_y__tmp_455 = ycirc->PutCONSGate( _tmp_455 ,bitlen);
                share * s_y_tmp_452 = ycirc->PutEQGate( s_y_tmp_453 , s_y__tmp_455 );
                share * s_y_tmp_448 = ycirc->PutANDGate( s_y_tmp_449 , s_y_tmp_452 );
                uint32_t _tmp_458 = 2147483648 ;
                share * s_y__tmp_458 = ycirc->PutCONSGate( _tmp_458 ,bitlen);
                share * s_y_tmp_457 = ycirc->PutGTGate( s_y__tmp_458 , s_y_tmp45[i24][i26][(2*i28)] );
                vector<uint32_t> _vec460 = s_y_tmp45[i24][i26][(2*i28)]->get_wires();
                _vec460.erase( _vec460.begin(), _vec460.begin() + 1 );
                share *s_y_tmp_459 = create_new_share( _vec460 , ycirc );
                uint32_t _tmp_464 = 4294967295 ;
                share * s_y__tmp_464 = ycirc->PutCONSGate( _tmp_464 ,bitlen);
                share * s_y_tmp_463 = ycirc->PutXORGate( s_y_tmp45[i24][i26][(2*i28)] , s_y__tmp_464 );
                vector<uint32_t> _vec465 = s_y_tmp_463->get_wires();
                _vec465.erase( _vec465.begin(), _vec465.begin() + 1 );
                share *s_y_tmp_462 = create_new_share( _vec465 , ycirc );
                uint32_t _tmp_466 = 4294967295 ;
                share * s_y__tmp_466 = ycirc->PutCONSGate( _tmp_466 ,bitlen);
                share * s_y_tmp_461 = ycirc->PutXORGate( s_y_tmp_462 , s_y__tmp_466 );
                share * s_y_tmp_456 = ycirc->PutMUXGate( s_y_tmp_459 , s_y_tmp_461 , s_y_tmp_457 );
                uint32_t _tmp_467 = 0 ;
                share * s_y__tmp_467 = ycirc->PutCONSGate( _tmp_467 ,bitlen);
                share * s_y_tmp_447 = ycirc->PutMUXGate( s_y_tmp_456 , s_y__tmp_467 , s_y_tmp_448 );
                s_y_tmp45[i24][i26][i28] = ycirc->PutMUXGate( s_y_tmp_433 , s_y_tmp_447 , s_y_tmp_430 );
                uint32_t _tmp_468 = 1 ;
                share * s_y__tmp_468 = ycirc->PutCONSGate( _tmp_468 ,bitlen);
                s_y_tmp47 = ycirc->PutADDGate( s_y_tmp47 , s_y__tmp_468 );
            }
            uint32_t _tmp_470 = 1 ;
            share * s_y__tmp_470 = ycirc->PutCONSGate( _tmp_470 ,bitlen);
            share * s_y_tmp_469 = ycirc->PutADDGate( s_y_tmp46 , s_y__tmp_470 );
            vector<uint32_t> _vec471 = s_y_tmp_469->get_wires();
            _vec471.erase( _vec471.begin(), _vec471.begin() + 1 );
            s_y_tmp46 = create_new_share( _vec471 , ycirc );
        }
        for (uint32_t i27 = 0; i27 < 0; i27++)
        {
            tmp47 = 0 ;
            s_y_tmp47 = ycirc->PutCONSGate( tmp47 ,bitlen);
            for (uint32_t i28 = 0; i28 < 4; i28++)
            {
                vector<uint32_t> _vec474 = s_y_tmp46->get_wires();
                _vec474.erase( _vec474.begin(), _vec474.begin() + 1 );
                share *s_y_tmp_473 = create_new_share( _vec474 , ycirc );
                share * s_y_tmp_472 = ycirc->PutGTGate( s_y_tmp_473 , s_y_tmp47 );
                share * s_y_tmp_475 = ycirc->PutADDGate( s_y_tmp45[i24][i26][(2*i28)] , s_y_tmp45[i24][i26][((2*i28)+1)] );
                vector<uint32_t> _vec480 = s_y_tmp46->get_wires();
                _vec480.erase( _vec480.begin(), _vec480.begin() + 1 );
                share *s_y_tmp_479 = create_new_share( _vec480 , ycirc );
                share * s_y_tmp_478 = ycirc->PutEQGate( s_y_tmp47 , s_y_tmp_479 );
                uint32_t _tmp_483 = 1 ;
                share * s_y__tmp_483 = ycirc->PutCONSGate( _tmp_483 ,bitlen);
                share * s_y_tmp_482 = ycirc->PutANDGate( s_y_tmp46 , s_y__tmp_483 );
                uint32_t _tmp_484 = 1 ;
                share * s_y__tmp_484 = ycirc->PutCONSGate( _tmp_484 ,bitlen);
                share * s_y_tmp_481 = ycirc->PutEQGate( s_y_tmp_482 , s_y__tmp_484 );
                share * s_y_tmp_477 = ycirc->PutANDGate( s_y_tmp_478 , s_y_tmp_481 );
                uint32_t _tmp_485 = 0 ;
                share * s_y__tmp_485 = ycirc->PutCONSGate( _tmp_485 ,bitlen);
                share * s_y_tmp_476 = ycirc->PutMUXGate( s_y_tmp45[i24][i26][(2*i28)] , s_y__tmp_485 , s_y_tmp_477 );
                s_y_tmp45[i24][i26][i28] = ycirc->PutMUXGate( s_y_tmp_475 , s_y_tmp_476 , s_y_tmp_472 );
                uint32_t _tmp_486 = 1 ;
                share * s_y__tmp_486 = ycirc->PutCONSGate( _tmp_486 ,bitlen);
                s_y_tmp47 = ycirc->PutADDGate( s_y_tmp47 , s_y__tmp_486 );
            }
            uint32_t _tmp_488 = 1 ;
            share * s_y__tmp_488 = ycirc->PutCONSGate( _tmp_488 ,bitlen);
            share * s_y_tmp_487 = ycirc->PutADDGate( s_y_tmp46 , s_y__tmp_488 );
            vector<uint32_t> _vec489 = s_y_tmp_487->get_wires();
            _vec489.erase( _vec489.begin(), _vec489.begin() + 1 );
            s_y_tmp46 = create_new_share( _vec489 , ycirc );
        }
        s_y_tmp42[i24][i26] = create_new_share(s_y_tmp45[i24][i26][0]->get_wires(), ycirc );
    }
}
auto s_y_tmp49 = make_vector<share*>(1, 1000);
for (uint32_t i29 = 0; i29 < 1; i29++)
{
    for (uint32_t i30 = 0; i30 < 1000; i30++)
    {
        uint32_t _tmp_491 = 2147483648 ;
        share * s_y__tmp_491 = ycirc->PutCONSGate( _tmp_491 ,bitlen);
        share * s_y_tmp_490 = ycirc->PutGTGate( s_y__tmp_491 , s_y_tmp42[i29][i30] );
        vector<uint32_t> _vec493 = s_y_tmp42[i29][i30]->get_wires();
        _vec493.erase( _vec493.begin(), _vec493.begin() + 15 );
        share *s_y_tmp_492 = create_new_share( _vec493 , ycirc );
        uint32_t _tmp_497 = 4294967295 ;
        share * s_y__tmp_497 = ycirc->PutCONSGate( _tmp_497 ,bitlen);
        share * s_y_tmp_496 = ycirc->PutXORGate( s_y_tmp42[i29][i30] , s_y__tmp_497 );
        vector<uint32_t> _vec498 = s_y_tmp_496->get_wires();
        _vec498.erase( _vec498.begin(), _vec498.begin() + 15 );
        share *s_y_tmp_495 = create_new_share( _vec498 , ycirc );
        uint32_t _tmp_499 = 4294967295 ;
        share * s_y__tmp_499 = ycirc->PutCONSGate( _tmp_499 ,bitlen);
        share * s_y_tmp_494 = ycirc->PutXORGate( s_y_tmp_495 , s_y__tmp_499 );
        s_y_tmp49[i29][i30] = ycirc->PutMUXGate( s_y_tmp_492 , s_y_tmp_494 , s_y_tmp_490 );
    }
}
auto s_y_tmp50 = make_vector<share*>(1000, 1);
for (uint32_t i30 = 0; i30 < 1000; i30++)
{
    for (uint32_t i31 = 0; i31 < 1; i31++)
    {
        uint32_t _tmp_501 = 2147483648 ;
        share * s_y__tmp_501 = ycirc->PutCONSGate( _tmp_501 ,bitlen);
        share * s_y_tmp_500 = ycirc->PutGTGate( s_y__tmp_501 , s_y_xx[i30][i31] );
        vector<uint32_t> _vec503 = s_y_xx[i30][i31]->get_wires();
        _vec503.erase( _vec503.begin(), _vec503.begin() + 15 );
        share *s_y_tmp_502 = create_new_share( _vec503 , ycirc );
        uint32_t _tmp_507 = 4294967295 ;
        share * s_y__tmp_507 = ycirc->PutCONSGate( _tmp_507 ,bitlen);
        share * s_y_tmp_506 = ycirc->PutXORGate( s_y_xx[i30][i31] , s_y__tmp_507 );
        vector<uint32_t> _vec508 = s_y_tmp_506->get_wires();
        _vec508.erase( _vec508.begin(), _vec508.begin() + 15 );
        share *s_y_tmp_505 = create_new_share( _vec508 , ycirc );
        uint32_t _tmp_509 = 4294967295 ;
        share * s_y__tmp_509 = ycirc->PutCONSGate( _tmp_509 ,bitlen);
        share * s_y_tmp_504 = ycirc->PutXORGate( s_y_tmp_505 , s_y__tmp_509 );
        s_y_tmp50[i30][i31] = ycirc->PutMUXGate( s_y_tmp_502 , s_y_tmp_504 , s_y_tmp_500 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp49[_i1][_i4] = acirc->PutY2AGate( s_y_tmp49[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1000 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp50[_i1][_i4] = acirc->PutY2AGate( s_y_tmp50[_i1][_i4] ,bcirc);
}
}
for (uint32_t i29 = 0; i29 < 1; i29++)
{
    for (uint32_t i31 = 0; i31 < 1; i31++)
    {
        for (uint32_t i30 = 0; i30 < 1000; i30++)
        {
            s_a_tmp51[i29][i31][i30] = acirc->PutMULGate( s_a_tmp49[i29][i30] , s_a_tmp50[i30][i31] );
        }
    }
}
share * s_y_tmp52 ;
share * s_y_tmp53 ;
auto s_y_tmp51 = make_vector<share*>(1, 1, 1000);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1000 ; _i7++) {
s_y_tmp51[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp51[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp48 = make_vector<share*>(1, 1);
for (uint32_t i29 = 0; i29 < 1; i29++)
{
    for (uint32_t i31 = 0; i31 < 1; i31++)
    {
        tmp52 = 1000 ;
        s_y_tmp52 = ycirc->PutCONSGate( tmp52 ,bitlen);
        for (uint32_t i32 = 0; i32 < 0; i32++)
        {
            tmp53 = 0 ;
            s_y_tmp53 = ycirc->PutCONSGate( tmp53 ,bitlen);
            for (uint32_t i33 = 0; i33 < 501; i33++)
            {
                vector<uint32_t> _vec512 = s_y_tmp52->get_wires();
                _vec512.erase( _vec512.begin(), _vec512.begin() + 1 );
                share *s_y_tmp_511 = create_new_share( _vec512 , ycirc );
                share * s_y_tmp_510 = ycirc->PutGTGate( s_y_tmp_511 , s_y_tmp53 );
                share * s_y_tmp_515 = ycirc->PutADDGate( s_y_tmp51[i29][i31][(2*i33)] , s_y_tmp51[i29][i31][((2*i33)+1)] );
                uint32_t _tmp_516 = 2147483648 ;
                share * s_y__tmp_516 = ycirc->PutCONSGate( _tmp_516 ,bitlen);
                share * s_y_tmp_514 = ycirc->PutGTGate( s_y__tmp_516 , s_y_tmp_515 );
                share * s_y_tmp_518 = ycirc->PutADDGate( s_y_tmp51[i29][i31][(2*i33)] , s_y_tmp51[i29][i31][((2*i33)+1)] );
                vector<uint32_t> _vec519 = s_y_tmp_518->get_wires();
                _vec519.erase( _vec519.begin(), _vec519.begin() + 1 );
                share *s_y_tmp_517 = create_new_share( _vec519 , ycirc );
                share * s_y_tmp_523 = ycirc->PutADDGate( s_y_tmp51[i29][i31][(2*i33)] , s_y_tmp51[i29][i31][((2*i33)+1)] );
                uint32_t _tmp_524 = 4294967295 ;
                share * s_y__tmp_524 = ycirc->PutCONSGate( _tmp_524 ,bitlen);
                share * s_y_tmp_522 = ycirc->PutXORGate( s_y_tmp_523 , s_y__tmp_524 );
                vector<uint32_t> _vec525 = s_y_tmp_522->get_wires();
                _vec525.erase( _vec525.begin(), _vec525.begin() + 1 );
                share *s_y_tmp_521 = create_new_share( _vec525 , ycirc );
                uint32_t _tmp_526 = 4294967295 ;
                share * s_y__tmp_526 = ycirc->PutCONSGate( _tmp_526 ,bitlen);
                share * s_y_tmp_520 = ycirc->PutXORGate( s_y_tmp_521 , s_y__tmp_526 );
                share * s_y_tmp_513 = ycirc->PutMUXGate( s_y_tmp_517 , s_y_tmp_520 , s_y_tmp_514 );
                vector<uint32_t> _vec531 = s_y_tmp52->get_wires();
                _vec531.erase( _vec531.begin(), _vec531.begin() + 1 );
                share *s_y_tmp_530 = create_new_share( _vec531 , ycirc );
                share * s_y_tmp_529 = ycirc->PutEQGate( s_y_tmp53 , s_y_tmp_530 );
                uint32_t _tmp_534 = 1 ;
                share * s_y__tmp_534 = ycirc->PutCONSGate( _tmp_534 ,bitlen);
                share * s_y_tmp_533 = ycirc->PutANDGate( s_y_tmp52 , s_y__tmp_534 );
                uint32_t _tmp_535 = 1 ;
                share * s_y__tmp_535 = ycirc->PutCONSGate( _tmp_535 ,bitlen);
                share * s_y_tmp_532 = ycirc->PutEQGate( s_y_tmp_533 , s_y__tmp_535 );
                share * s_y_tmp_528 = ycirc->PutANDGate( s_y_tmp_529 , s_y_tmp_532 );
                uint32_t _tmp_538 = 2147483648 ;
                share * s_y__tmp_538 = ycirc->PutCONSGate( _tmp_538 ,bitlen);
                share * s_y_tmp_537 = ycirc->PutGTGate( s_y__tmp_538 , s_y_tmp51[i29][i31][(2*i33)] );
                vector<uint32_t> _vec540 = s_y_tmp51[i29][i31][(2*i33)]->get_wires();
                _vec540.erase( _vec540.begin(), _vec540.begin() + 1 );
                share *s_y_tmp_539 = create_new_share( _vec540 , ycirc );
                uint32_t _tmp_544 = 4294967295 ;
                share * s_y__tmp_544 = ycirc->PutCONSGate( _tmp_544 ,bitlen);
                share * s_y_tmp_543 = ycirc->PutXORGate( s_y_tmp51[i29][i31][(2*i33)] , s_y__tmp_544 );
                vector<uint32_t> _vec545 = s_y_tmp_543->get_wires();
                _vec545.erase( _vec545.begin(), _vec545.begin() + 1 );
                share *s_y_tmp_542 = create_new_share( _vec545 , ycirc );
                uint32_t _tmp_546 = 4294967295 ;
                share * s_y__tmp_546 = ycirc->PutCONSGate( _tmp_546 ,bitlen);
                share * s_y_tmp_541 = ycirc->PutXORGate( s_y_tmp_542 , s_y__tmp_546 );
                share * s_y_tmp_536 = ycirc->PutMUXGate( s_y_tmp_539 , s_y_tmp_541 , s_y_tmp_537 );
                uint32_t _tmp_547 = 0 ;
                share * s_y__tmp_547 = ycirc->PutCONSGate( _tmp_547 ,bitlen);
                share * s_y_tmp_527 = ycirc->PutMUXGate( s_y_tmp_536 , s_y__tmp_547 , s_y_tmp_528 );
                s_y_tmp51[i29][i31][i33] = ycirc->PutMUXGate( s_y_tmp_513 , s_y_tmp_527 , s_y_tmp_510 );
                uint32_t _tmp_548 = 1 ;
                share * s_y__tmp_548 = ycirc->PutCONSGate( _tmp_548 ,bitlen);
                s_y_tmp53 = ycirc->PutADDGate( s_y_tmp53 , s_y__tmp_548 );
            }
            uint32_t _tmp_550 = 1 ;
            share * s_y__tmp_550 = ycirc->PutCONSGate( _tmp_550 ,bitlen);
            share * s_y_tmp_549 = ycirc->PutADDGate( s_y_tmp52 , s_y__tmp_550 );
            vector<uint32_t> _vec551 = s_y_tmp_549->get_wires();
            _vec551.erase( _vec551.begin(), _vec551.begin() + 1 );
            s_y_tmp52 = create_new_share( _vec551 , ycirc );
        }
        for (uint32_t i32 = 0; i32 < 10; i32++)
        {
            tmp53 = 0 ;
            s_y_tmp53 = ycirc->PutCONSGate( tmp53 ,bitlen);
            for (uint32_t i33 = 0; i33 < 501; i33++)
            {
                vector<uint32_t> _vec554 = s_y_tmp52->get_wires();
                _vec554.erase( _vec554.begin(), _vec554.begin() + 1 );
                share *s_y_tmp_553 = create_new_share( _vec554 , ycirc );
                share * s_y_tmp_552 = ycirc->PutGTGate( s_y_tmp_553 , s_y_tmp53 );
                share * s_y_tmp_555 = ycirc->PutADDGate( s_y_tmp51[i29][i31][(2*i33)] , s_y_tmp51[i29][i31][((2*i33)+1)] );
                vector<uint32_t> _vec560 = s_y_tmp52->get_wires();
                _vec560.erase( _vec560.begin(), _vec560.begin() + 1 );
                share *s_y_tmp_559 = create_new_share( _vec560 , ycirc );
                share * s_y_tmp_558 = ycirc->PutEQGate( s_y_tmp53 , s_y_tmp_559 );
                uint32_t _tmp_563 = 1 ;
                share * s_y__tmp_563 = ycirc->PutCONSGate( _tmp_563 ,bitlen);
                share * s_y_tmp_562 = ycirc->PutANDGate( s_y_tmp52 , s_y__tmp_563 );
                uint32_t _tmp_564 = 1 ;
                share * s_y__tmp_564 = ycirc->PutCONSGate( _tmp_564 ,bitlen);
                share * s_y_tmp_561 = ycirc->PutEQGate( s_y_tmp_562 , s_y__tmp_564 );
                share * s_y_tmp_557 = ycirc->PutANDGate( s_y_tmp_558 , s_y_tmp_561 );
                uint32_t _tmp_565 = 0 ;
                share * s_y__tmp_565 = ycirc->PutCONSGate( _tmp_565 ,bitlen);
                share * s_y_tmp_556 = ycirc->PutMUXGate( s_y_tmp51[i29][i31][(2*i33)] , s_y__tmp_565 , s_y_tmp_557 );
                s_y_tmp51[i29][i31][i33] = ycirc->PutMUXGate( s_y_tmp_555 , s_y_tmp_556 , s_y_tmp_552 );
                uint32_t _tmp_566 = 1 ;
                share * s_y__tmp_566 = ycirc->PutCONSGate( _tmp_566 ,bitlen);
                s_y_tmp53 = ycirc->PutADDGate( s_y_tmp53 , s_y__tmp_566 );
            }
            uint32_t _tmp_568 = 1 ;
            share * s_y__tmp_568 = ycirc->PutCONSGate( _tmp_568 ,bitlen);
            share * s_y_tmp_567 = ycirc->PutADDGate( s_y_tmp52 , s_y__tmp_568 );
            vector<uint32_t> _vec569 = s_y_tmp_567->get_wires();
            _vec569.erase( _vec569.begin(), _vec569.begin() + 1 );
            s_y_tmp52 = create_new_share( _vec569 , ycirc );
        }
        s_y_tmp48[i29][i31] = create_new_share(s_y_tmp51[i29][i31][0]->get_wires(), ycirc );
    }
}
uint32_t _tmp_571 = 2147483648 ;
share * s_y__tmp_571 = ycirc->PutCONSGate( _tmp_571 ,bitlen);
share * s_y_tmp_570 = ycirc->PutGTGate( s_y__tmp_571 , s_y_tmp48[0][0] );
uint32_t _tmp_574 = 2 ;
share * s_a__tmp_574 = acirc->PutCONSGate( _tmp_574 ,bitlen);
share * s_a_tmp_573 = acirc->PutMULGate( s_a__tmp_574 , s_a_cur1 );
uint32_t _tmp_575 = 1 ;
share * s_a__tmp_575 = acirc->PutCONSGate( _tmp_575 ,bitlen);
share * s_a_tmp_572 = acirc->PutADDGate( s_a_tmp_573 , s_a__tmp_575 );
uint32_t _tmp_577 = 2 ;
share * s_a__tmp_577 = acirc->PutCONSGate( _tmp_577 ,bitlen);
share * s_a_tmp_576 = acirc->PutMULGate( s_a__tmp_577 , s_a_cur1 );
share *s_y_tmp_572 = ycirc->PutA2YGate( s_a_tmp_572 );
share *s_y_tmp_576 = ycirc->PutA2YGate( s_a_tmp_576 );
share * s_y_cur2 = ycirc->PutMUXGate( s_y_tmp_572 , s_y_tmp_576 , s_y_tmp_570 );
uint32_t _tmp_579 = 2147483648 ;
share * s_y__tmp_579 = ycirc->PutCONSGate( _tmp_579 ,bitlen);
share * s_y_tmp_578 = ycirc->PutGTGate( s_y__tmp_579 , s_y_tmp0 );
vector<uint32_t> _vec581 = s_y_tmp0->get_wires();
_vec581.erase( _vec581.begin(), _vec581.begin() + 15 );
share *s_y_tmp_580 = create_new_share( _vec581 , ycirc );
uint32_t _tmp_585 = 4294967295 ;
share * s_y__tmp_585 = ycirc->PutCONSGate( _tmp_585 ,bitlen);
share * s_y_tmp_584 = ycirc->PutXORGate( s_y_tmp0 , s_y__tmp_585 );
vector<uint32_t> _vec586 = s_y_tmp_584->get_wires();
_vec586.erase( _vec586.begin(), _vec586.begin() + 15 );
share *s_y_tmp_583 = create_new_share( _vec586 , ycirc );
uint32_t _tmp_587 = 4294967295 ;
share * s_y__tmp_587 = ycirc->PutCONSGate( _tmp_587 ,bitlen);
share * s_y_tmp_582 = ycirc->PutXORGate( s_y_tmp_583 , s_y__tmp_587 );
share * s_y_tmp55 = ycirc->PutMUXGate( s_y_tmp_580 , s_y_tmp_582 , s_y_tmp_578 );
auto s_y_tmp56 = make_vector<share*>(1, 7);
for (uint32_t i34 = 0; i34 < 1; i34++)
{
    for (uint32_t i35 = 0; i35 < 7; i35++)
    {
        uint32_t _tmp_589 = 2147483648 ;
        share * s_y__tmp_589 = ycirc->PutCONSGate( _tmp_589 ,bitlen);
        share * s_y_tmp_588 = ycirc->PutGTGate( s_y__tmp_589 , s_y_VV[cur2][i34][i35] );
        vector<uint32_t> _vec591 = s_y_VV[cur2][i34][i35]->get_wires();
        _vec591.erase( _vec591.begin(), _vec591.begin() + 15 );
        share *s_y_tmp_590 = create_new_share( _vec591 , ycirc );
        uint32_t _tmp_595 = 4294967295 ;
        share * s_y__tmp_595 = ycirc->PutCONSGate( _tmp_595 ,bitlen);
        share * s_y_tmp_594 = ycirc->PutXORGate( s_y_VV[cur2][i34][i35] , s_y__tmp_595 );
        vector<uint32_t> _vec596 = s_y_tmp_594->get_wires();
        _vec596.erase( _vec596.begin(), _vec596.begin() + 15 );
        share *s_y_tmp_593 = create_new_share( _vec596 , ycirc );
        uint32_t _tmp_597 = 4294967295 ;
        share * s_y__tmp_597 = ycirc->PutCONSGate( _tmp_597 ,bitlen);
        share * s_y_tmp_592 = ycirc->PutXORGate( s_y_tmp_593 , s_y__tmp_597 );
        s_y_tmp56[i34][i35] = ycirc->PutMUXGate( s_y_tmp_590 , s_y_tmp_592 , s_y_tmp_588 );
    }
}
s_a_tmp55 = acirc->PutY2AGate( s_y_tmp55 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_a_tmp56[_i1][_i4] = acirc->PutY2AGate( s_y_tmp56[_i1][_i4] ,bcirc);
}
}
for (uint32_t i34 = 0; i34 < 1; i34++)
{
    for (uint32_t i35 = 0; i35 < 7; i35++)
    {
        s_a_tmp54[i34][i35] = acirc->PutMULGate( s_a_tmp55 , s_a_tmp56[i34][i35] );
    }
}
auto s_y_tmp54 = make_vector<share*>(1, 7);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_y_tmp54[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp54[_i1][_i4] );
}
}
auto s_y_tmp58 = make_vector<share*>(1, 7);
for (uint32_t i36 = 0; i36 < 1; i36++)
{
    for (uint32_t i37 = 0; i37 < 7; i37++)
    {
        uint32_t _tmp_599 = 2147483648 ;
        share * s_y__tmp_599 = ycirc->PutCONSGate( _tmp_599 ,bitlen);
        share * s_y_tmp_598 = ycirc->PutGTGate( s_y__tmp_599 , s_y_tmp54[i36][i37] );
        vector<uint32_t> _vec601 = s_y_tmp54[i36][i37]->get_wires();
        _vec601.erase( _vec601.begin(), _vec601.begin() + 15 );
        share *s_y_tmp_600 = create_new_share( _vec601 , ycirc );
        uint32_t _tmp_605 = 4294967295 ;
        share * s_y__tmp_605 = ycirc->PutCONSGate( _tmp_605 ,bitlen);
        share * s_y_tmp_604 = ycirc->PutXORGate( s_y_tmp54[i36][i37] , s_y__tmp_605 );
        vector<uint32_t> _vec606 = s_y_tmp_604->get_wires();
        _vec606.erase( _vec606.begin(), _vec606.begin() + 15 );
        share *s_y_tmp_603 = create_new_share( _vec606 , ycirc );
        uint32_t _tmp_607 = 4294967295 ;
        share * s_y__tmp_607 = ycirc->PutCONSGate( _tmp_607 ,bitlen);
        share * s_y_tmp_602 = ycirc->PutXORGate( s_y_tmp_603 , s_y__tmp_607 );
        s_y_tmp58[i36][i37] = ycirc->PutMUXGate( s_y_tmp_600 , s_y_tmp_602 , s_y_tmp_598 );
    }
}
auto s_y_tmp59 = make_vector<share*>(7, 1000);
for (uint32_t i37 = 0; i37 < 7; i37++)
{
    for (uint32_t i38 = 0; i38 < 1000; i38++)
    {
        uint32_t _tmp_609 = 2147483648 ;
        share * s_y__tmp_609 = ycirc->PutCONSGate( _tmp_609 ,bitlen);
        share * s_y_tmp_608 = ycirc->PutGTGate( s_y__tmp_609 , s_y_ZZ[i37][i38] );
        vector<uint32_t> _vec611 = s_y_ZZ[i37][i38]->get_wires();
        _vec611.erase( _vec611.begin(), _vec611.begin() + 15 );
        share *s_y_tmp_610 = create_new_share( _vec611 , ycirc );
        uint32_t _tmp_615 = 4294967295 ;
        share * s_y__tmp_615 = ycirc->PutCONSGate( _tmp_615 ,bitlen);
        share * s_y_tmp_614 = ycirc->PutXORGate( s_y_ZZ[i37][i38] , s_y__tmp_615 );
        vector<uint32_t> _vec616 = s_y_tmp_614->get_wires();
        _vec616.erase( _vec616.begin(), _vec616.begin() + 15 );
        share *s_y_tmp_613 = create_new_share( _vec616 , ycirc );
        uint32_t _tmp_617 = 4294967295 ;
        share * s_y__tmp_617 = ycirc->PutCONSGate( _tmp_617 ,bitlen);
        share * s_y_tmp_612 = ycirc->PutXORGate( s_y_tmp_613 , s_y__tmp_617 );
        s_y_tmp59[i37][i38] = ycirc->PutMUXGate( s_y_tmp_610 , s_y_tmp_612 , s_y_tmp_608 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_a_tmp58[_i1][_i4] = acirc->PutY2AGate( s_y_tmp58[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp59[_i1][_i4] = acirc->PutY2AGate( s_y_tmp59[_i1][_i4] ,bcirc);
}
}
for (uint32_t i36 = 0; i36 < 1; i36++)
{
    for (uint32_t i38 = 0; i38 < 1000; i38++)
    {
        for (uint32_t i37 = 0; i37 < 7; i37++)
        {
            s_a_tmp60[i36][i38][i37] = acirc->PutMULGate( s_a_tmp58[i36][i37] , s_a_tmp59[i37][i38] );
        }
    }
}
share * s_y_tmp61 ;
share * s_y_tmp62 ;
auto s_y_tmp60 = make_vector<share*>(1, 1000, 7);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_tmp60[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp60[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp57 = make_vector<share*>(1, 1000);
for (uint32_t i36 = 0; i36 < 1; i36++)
{
    for (uint32_t i38 = 0; i38 < 1000; i38++)
    {
        tmp61 = 7 ;
        s_y_tmp61 = ycirc->PutCONSGate( tmp61 ,bitlen);
        for (uint32_t i39 = 0; i39 < 3; i39++)
        {
            tmp62 = 0 ;
            s_y_tmp62 = ycirc->PutCONSGate( tmp62 ,bitlen);
            for (uint32_t i40 = 0; i40 < 4; i40++)
            {
                vector<uint32_t> _vec620 = s_y_tmp61->get_wires();
                _vec620.erase( _vec620.begin(), _vec620.begin() + 1 );
                share *s_y_tmp_619 = create_new_share( _vec620 , ycirc );
                share * s_y_tmp_618 = ycirc->PutGTGate( s_y_tmp_619 , s_y_tmp62 );
                share * s_y_tmp_623 = ycirc->PutADDGate( s_y_tmp60[i36][i38][(2*i40)] , s_y_tmp60[i36][i38][((2*i40)+1)] );
                uint32_t _tmp_624 = 2147483648 ;
                share * s_y__tmp_624 = ycirc->PutCONSGate( _tmp_624 ,bitlen);
                share * s_y_tmp_622 = ycirc->PutGTGate( s_y__tmp_624 , s_y_tmp_623 );
                share * s_y_tmp_626 = ycirc->PutADDGate( s_y_tmp60[i36][i38][(2*i40)] , s_y_tmp60[i36][i38][((2*i40)+1)] );
                vector<uint32_t> _vec627 = s_y_tmp_626->get_wires();
                _vec627.erase( _vec627.begin(), _vec627.begin() + 1 );
                share *s_y_tmp_625 = create_new_share( _vec627 , ycirc );
                share * s_y_tmp_631 = ycirc->PutADDGate( s_y_tmp60[i36][i38][(2*i40)] , s_y_tmp60[i36][i38][((2*i40)+1)] );
                uint32_t _tmp_632 = 4294967295 ;
                share * s_y__tmp_632 = ycirc->PutCONSGate( _tmp_632 ,bitlen);
                share * s_y_tmp_630 = ycirc->PutXORGate( s_y_tmp_631 , s_y__tmp_632 );
                vector<uint32_t> _vec633 = s_y_tmp_630->get_wires();
                _vec633.erase( _vec633.begin(), _vec633.begin() + 1 );
                share *s_y_tmp_629 = create_new_share( _vec633 , ycirc );
                uint32_t _tmp_634 = 4294967295 ;
                share * s_y__tmp_634 = ycirc->PutCONSGate( _tmp_634 ,bitlen);
                share * s_y_tmp_628 = ycirc->PutXORGate( s_y_tmp_629 , s_y__tmp_634 );
                share * s_y_tmp_621 = ycirc->PutMUXGate( s_y_tmp_625 , s_y_tmp_628 , s_y_tmp_622 );
                vector<uint32_t> _vec639 = s_y_tmp61->get_wires();
                _vec639.erase( _vec639.begin(), _vec639.begin() + 1 );
                share *s_y_tmp_638 = create_new_share( _vec639 , ycirc );
                share * s_y_tmp_637 = ycirc->PutEQGate( s_y_tmp62 , s_y_tmp_638 );
                uint32_t _tmp_642 = 1 ;
                share * s_y__tmp_642 = ycirc->PutCONSGate( _tmp_642 ,bitlen);
                share * s_y_tmp_641 = ycirc->PutANDGate( s_y_tmp61 , s_y__tmp_642 );
                uint32_t _tmp_643 = 1 ;
                share * s_y__tmp_643 = ycirc->PutCONSGate( _tmp_643 ,bitlen);
                share * s_y_tmp_640 = ycirc->PutEQGate( s_y_tmp_641 , s_y__tmp_643 );
                share * s_y_tmp_636 = ycirc->PutANDGate( s_y_tmp_637 , s_y_tmp_640 );
                uint32_t _tmp_646 = 2147483648 ;
                share * s_y__tmp_646 = ycirc->PutCONSGate( _tmp_646 ,bitlen);
                share * s_y_tmp_645 = ycirc->PutGTGate( s_y__tmp_646 , s_y_tmp60[i36][i38][(2*i40)] );
                vector<uint32_t> _vec648 = s_y_tmp60[i36][i38][(2*i40)]->get_wires();
                _vec648.erase( _vec648.begin(), _vec648.begin() + 1 );
                share *s_y_tmp_647 = create_new_share( _vec648 , ycirc );
                uint32_t _tmp_652 = 4294967295 ;
                share * s_y__tmp_652 = ycirc->PutCONSGate( _tmp_652 ,bitlen);
                share * s_y_tmp_651 = ycirc->PutXORGate( s_y_tmp60[i36][i38][(2*i40)] , s_y__tmp_652 );
                vector<uint32_t> _vec653 = s_y_tmp_651->get_wires();
                _vec653.erase( _vec653.begin(), _vec653.begin() + 1 );
                share *s_y_tmp_650 = create_new_share( _vec653 , ycirc );
                uint32_t _tmp_654 = 4294967295 ;
                share * s_y__tmp_654 = ycirc->PutCONSGate( _tmp_654 ,bitlen);
                share * s_y_tmp_649 = ycirc->PutXORGate( s_y_tmp_650 , s_y__tmp_654 );
                share * s_y_tmp_644 = ycirc->PutMUXGate( s_y_tmp_647 , s_y_tmp_649 , s_y_tmp_645 );
                uint32_t _tmp_655 = 0 ;
                share * s_y__tmp_655 = ycirc->PutCONSGate( _tmp_655 ,bitlen);
                share * s_y_tmp_635 = ycirc->PutMUXGate( s_y_tmp_644 , s_y__tmp_655 , s_y_tmp_636 );
                s_y_tmp60[i36][i38][i40] = ycirc->PutMUXGate( s_y_tmp_621 , s_y_tmp_635 , s_y_tmp_618 );
                uint32_t _tmp_656 = 1 ;
                share * s_y__tmp_656 = ycirc->PutCONSGate( _tmp_656 ,bitlen);
                s_y_tmp62 = ycirc->PutADDGate( s_y_tmp62 , s_y__tmp_656 );
            }
            uint32_t _tmp_658 = 1 ;
            share * s_y__tmp_658 = ycirc->PutCONSGate( _tmp_658 ,bitlen);
            share * s_y_tmp_657 = ycirc->PutADDGate( s_y_tmp61 , s_y__tmp_658 );
            vector<uint32_t> _vec659 = s_y_tmp_657->get_wires();
            _vec659.erase( _vec659.begin(), _vec659.begin() + 1 );
            s_y_tmp61 = create_new_share( _vec659 , ycirc );
        }
        for (uint32_t i39 = 0; i39 < 0; i39++)
        {
            tmp62 = 0 ;
            s_y_tmp62 = ycirc->PutCONSGate( tmp62 ,bitlen);
            for (uint32_t i40 = 0; i40 < 4; i40++)
            {
                vector<uint32_t> _vec662 = s_y_tmp61->get_wires();
                _vec662.erase( _vec662.begin(), _vec662.begin() + 1 );
                share *s_y_tmp_661 = create_new_share( _vec662 , ycirc );
                share * s_y_tmp_660 = ycirc->PutGTGate( s_y_tmp_661 , s_y_tmp62 );
                share * s_y_tmp_663 = ycirc->PutADDGate( s_y_tmp60[i36][i38][(2*i40)] , s_y_tmp60[i36][i38][((2*i40)+1)] );
                vector<uint32_t> _vec668 = s_y_tmp61->get_wires();
                _vec668.erase( _vec668.begin(), _vec668.begin() + 1 );
                share *s_y_tmp_667 = create_new_share( _vec668 , ycirc );
                share * s_y_tmp_666 = ycirc->PutEQGate( s_y_tmp62 , s_y_tmp_667 );
                uint32_t _tmp_671 = 1 ;
                share * s_y__tmp_671 = ycirc->PutCONSGate( _tmp_671 ,bitlen);
                share * s_y_tmp_670 = ycirc->PutANDGate( s_y_tmp61 , s_y__tmp_671 );
                uint32_t _tmp_672 = 1 ;
                share * s_y__tmp_672 = ycirc->PutCONSGate( _tmp_672 ,bitlen);
                share * s_y_tmp_669 = ycirc->PutEQGate( s_y_tmp_670 , s_y__tmp_672 );
                share * s_y_tmp_665 = ycirc->PutANDGate( s_y_tmp_666 , s_y_tmp_669 );
                uint32_t _tmp_673 = 0 ;
                share * s_y__tmp_673 = ycirc->PutCONSGate( _tmp_673 ,bitlen);
                share * s_y_tmp_664 = ycirc->PutMUXGate( s_y_tmp60[i36][i38][(2*i40)] , s_y__tmp_673 , s_y_tmp_665 );
                s_y_tmp60[i36][i38][i40] = ycirc->PutMUXGate( s_y_tmp_663 , s_y_tmp_664 , s_y_tmp_660 );
                uint32_t _tmp_674 = 1 ;
                share * s_y__tmp_674 = ycirc->PutCONSGate( _tmp_674 ,bitlen);
                s_y_tmp62 = ycirc->PutADDGate( s_y_tmp62 , s_y__tmp_674 );
            }
            uint32_t _tmp_676 = 1 ;
            share * s_y__tmp_676 = ycirc->PutCONSGate( _tmp_676 ,bitlen);
            share * s_y_tmp_675 = ycirc->PutADDGate( s_y_tmp61 , s_y__tmp_676 );
            vector<uint32_t> _vec677 = s_y_tmp_675->get_wires();
            _vec677.erase( _vec677.begin(), _vec677.begin() + 1 );
            s_y_tmp61 = create_new_share( _vec677 , ycirc );
        }
        s_y_tmp57[i36][i38] = create_new_share(s_y_tmp60[i36][i38][0]->get_wires(), ycirc );
    }
}
auto s_y_tmp64 = make_vector<share*>(1, 1000);
for (uint32_t i41 = 0; i41 < 1; i41++)
{
    for (uint32_t i42 = 0; i42 < 1000; i42++)
    {
        uint32_t _tmp_679 = 2147483648 ;
        share * s_y__tmp_679 = ycirc->PutCONSGate( _tmp_679 ,bitlen);
        share * s_y_tmp_678 = ycirc->PutGTGate( s_y__tmp_679 , s_y_tmp57[i41][i42] );
        vector<uint32_t> _vec681 = s_y_tmp57[i41][i42]->get_wires();
        _vec681.erase( _vec681.begin(), _vec681.begin() + 15 );
        share *s_y_tmp_680 = create_new_share( _vec681 , ycirc );
        uint32_t _tmp_685 = 4294967295 ;
        share * s_y__tmp_685 = ycirc->PutCONSGate( _tmp_685 ,bitlen);
        share * s_y_tmp_684 = ycirc->PutXORGate( s_y_tmp57[i41][i42] , s_y__tmp_685 );
        vector<uint32_t> _vec686 = s_y_tmp_684->get_wires();
        _vec686.erase( _vec686.begin(), _vec686.begin() + 15 );
        share *s_y_tmp_683 = create_new_share( _vec686 , ycirc );
        uint32_t _tmp_687 = 4294967295 ;
        share * s_y__tmp_687 = ycirc->PutCONSGate( _tmp_687 ,bitlen);
        share * s_y_tmp_682 = ycirc->PutXORGate( s_y_tmp_683 , s_y__tmp_687 );
        s_y_tmp64[i41][i42] = ycirc->PutMUXGate( s_y_tmp_680 , s_y_tmp_682 , s_y_tmp_678 );
    }
}
auto s_y_tmp65 = make_vector<share*>(1000, 1);
for (uint32_t i42 = 0; i42 < 1000; i42++)
{
    for (uint32_t i43 = 0; i43 < 1; i43++)
    {
        uint32_t _tmp_689 = 2147483648 ;
        share * s_y__tmp_689 = ycirc->PutCONSGate( _tmp_689 ,bitlen);
        share * s_y_tmp_688 = ycirc->PutGTGate( s_y__tmp_689 , s_y_xx[i42][i43] );
        vector<uint32_t> _vec691 = s_y_xx[i42][i43]->get_wires();
        _vec691.erase( _vec691.begin(), _vec691.begin() + 15 );
        share *s_y_tmp_690 = create_new_share( _vec691 , ycirc );
        uint32_t _tmp_695 = 4294967295 ;
        share * s_y__tmp_695 = ycirc->PutCONSGate( _tmp_695 ,bitlen);
        share * s_y_tmp_694 = ycirc->PutXORGate( s_y_xx[i42][i43] , s_y__tmp_695 );
        vector<uint32_t> _vec696 = s_y_tmp_694->get_wires();
        _vec696.erase( _vec696.begin(), _vec696.begin() + 15 );
        share *s_y_tmp_693 = create_new_share( _vec696 , ycirc );
        uint32_t _tmp_697 = 4294967295 ;
        share * s_y__tmp_697 = ycirc->PutCONSGate( _tmp_697 ,bitlen);
        share * s_y_tmp_692 = ycirc->PutXORGate( s_y_tmp_693 , s_y__tmp_697 );
        s_y_tmp65[i42][i43] = ycirc->PutMUXGate( s_y_tmp_690 , s_y_tmp_692 , s_y_tmp_688 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp64[_i1][_i4] = acirc->PutY2AGate( s_y_tmp64[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1000 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp65[_i1][_i4] = acirc->PutY2AGate( s_y_tmp65[_i1][_i4] ,bcirc);
}
}
for (uint32_t i41 = 0; i41 < 1; i41++)
{
    for (uint32_t i43 = 0; i43 < 1; i43++)
    {
        for (uint32_t i42 = 0; i42 < 1000; i42++)
        {
            s_a_tmp66[i41][i43][i42] = acirc->PutMULGate( s_a_tmp64[i41][i42] , s_a_tmp65[i42][i43] );
        }
    }
}
share * s_y_tmp67 ;
share * s_y_tmp68 ;
auto s_y_tmp66 = make_vector<share*>(1, 1, 1000);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1000 ; _i7++) {
s_y_tmp66[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp66[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp63 = make_vector<share*>(1, 1);
for (uint32_t i41 = 0; i41 < 1; i41++)
{
    for (uint32_t i43 = 0; i43 < 1; i43++)
    {
        tmp67 = 1000 ;
        s_y_tmp67 = ycirc->PutCONSGate( tmp67 ,bitlen);
        for (uint32_t i44 = 0; i44 < 2; i44++)
        {
            tmp68 = 0 ;
            s_y_tmp68 = ycirc->PutCONSGate( tmp68 ,bitlen);
            for (uint32_t i45 = 0; i45 < 501; i45++)
            {
                vector<uint32_t> _vec700 = s_y_tmp67->get_wires();
                _vec700.erase( _vec700.begin(), _vec700.begin() + 1 );
                share *s_y_tmp_699 = create_new_share( _vec700 , ycirc );
                share * s_y_tmp_698 = ycirc->PutGTGate( s_y_tmp_699 , s_y_tmp68 );
                share * s_y_tmp_703 = ycirc->PutADDGate( s_y_tmp66[i41][i43][(2*i45)] , s_y_tmp66[i41][i43][((2*i45)+1)] );
                uint32_t _tmp_704 = 2147483648 ;
                share * s_y__tmp_704 = ycirc->PutCONSGate( _tmp_704 ,bitlen);
                share * s_y_tmp_702 = ycirc->PutGTGate( s_y__tmp_704 , s_y_tmp_703 );
                share * s_y_tmp_706 = ycirc->PutADDGate( s_y_tmp66[i41][i43][(2*i45)] , s_y_tmp66[i41][i43][((2*i45)+1)] );
                vector<uint32_t> _vec707 = s_y_tmp_706->get_wires();
                _vec707.erase( _vec707.begin(), _vec707.begin() + 1 );
                share *s_y_tmp_705 = create_new_share( _vec707 , ycirc );
                share * s_y_tmp_711 = ycirc->PutADDGate( s_y_tmp66[i41][i43][(2*i45)] , s_y_tmp66[i41][i43][((2*i45)+1)] );
                uint32_t _tmp_712 = 4294967295 ;
                share * s_y__tmp_712 = ycirc->PutCONSGate( _tmp_712 ,bitlen);
                share * s_y_tmp_710 = ycirc->PutXORGate( s_y_tmp_711 , s_y__tmp_712 );
                vector<uint32_t> _vec713 = s_y_tmp_710->get_wires();
                _vec713.erase( _vec713.begin(), _vec713.begin() + 1 );
                share *s_y_tmp_709 = create_new_share( _vec713 , ycirc );
                uint32_t _tmp_714 = 4294967295 ;
                share * s_y__tmp_714 = ycirc->PutCONSGate( _tmp_714 ,bitlen);
                share * s_y_tmp_708 = ycirc->PutXORGate( s_y_tmp_709 , s_y__tmp_714 );
                share * s_y_tmp_701 = ycirc->PutMUXGate( s_y_tmp_705 , s_y_tmp_708 , s_y_tmp_702 );
                vector<uint32_t> _vec719 = s_y_tmp67->get_wires();
                _vec719.erase( _vec719.begin(), _vec719.begin() + 1 );
                share *s_y_tmp_718 = create_new_share( _vec719 , ycirc );
                share * s_y_tmp_717 = ycirc->PutEQGate( s_y_tmp68 , s_y_tmp_718 );
                uint32_t _tmp_722 = 1 ;
                share * s_y__tmp_722 = ycirc->PutCONSGate( _tmp_722 ,bitlen);
                share * s_y_tmp_721 = ycirc->PutANDGate( s_y_tmp67 , s_y__tmp_722 );
                uint32_t _tmp_723 = 1 ;
                share * s_y__tmp_723 = ycirc->PutCONSGate( _tmp_723 ,bitlen);
                share * s_y_tmp_720 = ycirc->PutEQGate( s_y_tmp_721 , s_y__tmp_723 );
                share * s_y_tmp_716 = ycirc->PutANDGate( s_y_tmp_717 , s_y_tmp_720 );
                uint32_t _tmp_726 = 2147483648 ;
                share * s_y__tmp_726 = ycirc->PutCONSGate( _tmp_726 ,bitlen);
                share * s_y_tmp_725 = ycirc->PutGTGate( s_y__tmp_726 , s_y_tmp66[i41][i43][(2*i45)] );
                vector<uint32_t> _vec728 = s_y_tmp66[i41][i43][(2*i45)]->get_wires();
                _vec728.erase( _vec728.begin(), _vec728.begin() + 1 );
                share *s_y_tmp_727 = create_new_share( _vec728 , ycirc );
                uint32_t _tmp_732 = 4294967295 ;
                share * s_y__tmp_732 = ycirc->PutCONSGate( _tmp_732 ,bitlen);
                share * s_y_tmp_731 = ycirc->PutXORGate( s_y_tmp66[i41][i43][(2*i45)] , s_y__tmp_732 );
                vector<uint32_t> _vec733 = s_y_tmp_731->get_wires();
                _vec733.erase( _vec733.begin(), _vec733.begin() + 1 );
                share *s_y_tmp_730 = create_new_share( _vec733 , ycirc );
                uint32_t _tmp_734 = 4294967295 ;
                share * s_y__tmp_734 = ycirc->PutCONSGate( _tmp_734 ,bitlen);
                share * s_y_tmp_729 = ycirc->PutXORGate( s_y_tmp_730 , s_y__tmp_734 );
                share * s_y_tmp_724 = ycirc->PutMUXGate( s_y_tmp_727 , s_y_tmp_729 , s_y_tmp_725 );
                uint32_t _tmp_735 = 0 ;
                share * s_y__tmp_735 = ycirc->PutCONSGate( _tmp_735 ,bitlen);
                share * s_y_tmp_715 = ycirc->PutMUXGate( s_y_tmp_724 , s_y__tmp_735 , s_y_tmp_716 );
                s_y_tmp66[i41][i43][i45] = ycirc->PutMUXGate( s_y_tmp_701 , s_y_tmp_715 , s_y_tmp_698 );
                uint32_t _tmp_736 = 1 ;
                share * s_y__tmp_736 = ycirc->PutCONSGate( _tmp_736 ,bitlen);
                s_y_tmp68 = ycirc->PutADDGate( s_y_tmp68 , s_y__tmp_736 );
            }
            uint32_t _tmp_738 = 1 ;
            share * s_y__tmp_738 = ycirc->PutCONSGate( _tmp_738 ,bitlen);
            share * s_y_tmp_737 = ycirc->PutADDGate( s_y_tmp67 , s_y__tmp_738 );
            vector<uint32_t> _vec739 = s_y_tmp_737->get_wires();
            _vec739.erase( _vec739.begin(), _vec739.begin() + 1 );
            s_y_tmp67 = create_new_share( _vec739 , ycirc );
        }
        for (uint32_t i44 = 0; i44 < 8; i44++)
        {
            tmp68 = 0 ;
            s_y_tmp68 = ycirc->PutCONSGate( tmp68 ,bitlen);
            for (uint32_t i45 = 0; i45 < 501; i45++)
            {
                vector<uint32_t> _vec742 = s_y_tmp67->get_wires();
                _vec742.erase( _vec742.begin(), _vec742.begin() + 1 );
                share *s_y_tmp_741 = create_new_share( _vec742 , ycirc );
                share * s_y_tmp_740 = ycirc->PutGTGate( s_y_tmp_741 , s_y_tmp68 );
                share * s_y_tmp_743 = ycirc->PutADDGate( s_y_tmp66[i41][i43][(2*i45)] , s_y_tmp66[i41][i43][((2*i45)+1)] );
                vector<uint32_t> _vec748 = s_y_tmp67->get_wires();
                _vec748.erase( _vec748.begin(), _vec748.begin() + 1 );
                share *s_y_tmp_747 = create_new_share( _vec748 , ycirc );
                share * s_y_tmp_746 = ycirc->PutEQGate( s_y_tmp68 , s_y_tmp_747 );
                uint32_t _tmp_751 = 1 ;
                share * s_y__tmp_751 = ycirc->PutCONSGate( _tmp_751 ,bitlen);
                share * s_y_tmp_750 = ycirc->PutANDGate( s_y_tmp67 , s_y__tmp_751 );
                uint32_t _tmp_752 = 1 ;
                share * s_y__tmp_752 = ycirc->PutCONSGate( _tmp_752 ,bitlen);
                share * s_y_tmp_749 = ycirc->PutEQGate( s_y_tmp_750 , s_y__tmp_752 );
                share * s_y_tmp_745 = ycirc->PutANDGate( s_y_tmp_746 , s_y_tmp_749 );
                uint32_t _tmp_753 = 0 ;
                share * s_y__tmp_753 = ycirc->PutCONSGate( _tmp_753 ,bitlen);
                share * s_y_tmp_744 = ycirc->PutMUXGate( s_y_tmp66[i41][i43][(2*i45)] , s_y__tmp_753 , s_y_tmp_745 );
                s_y_tmp66[i41][i43][i45] = ycirc->PutMUXGate( s_y_tmp_743 , s_y_tmp_744 , s_y_tmp_740 );
                uint32_t _tmp_754 = 1 ;
                share * s_y__tmp_754 = ycirc->PutCONSGate( _tmp_754 ,bitlen);
                s_y_tmp68 = ycirc->PutADDGate( s_y_tmp68 , s_y__tmp_754 );
            }
            uint32_t _tmp_756 = 1 ;
            share * s_y__tmp_756 = ycirc->PutCONSGate( _tmp_756 ,bitlen);
            share * s_y_tmp_755 = ycirc->PutADDGate( s_y_tmp67 , s_y__tmp_756 );
            vector<uint32_t> _vec757 = s_y_tmp_755->get_wires();
            _vec757.erase( _vec757.begin(), _vec757.begin() + 1 );
            s_y_tmp67 = create_new_share( _vec757 , ycirc );
        }
        s_y_tmp63[i41][i43] = create_new_share(s_y_tmp66[i41][i43][0]->get_wires(), ycirc );
    }
}
share *s_y_tmp70 = create_new_share(s_y_tmp63[0][0]->get_wires(), ycirc );
uint32_t _tmp_759 = 2147483648 ;
share * s_y__tmp_759 = ycirc->PutCONSGate( _tmp_759 ,bitlen);
share * s_y_tmp_758 = ycirc->PutGTGate( s_y__tmp_759 , s_y_tmp1 );
vector<uint32_t> _vec761 = s_y_tmp1->get_wires();
_vec761.erase( _vec761.begin(), _vec761.begin() + 8 );
share *s_y_tmp_760 = create_new_share( _vec761 , ycirc );
uint32_t _tmp_765 = 4294967295 ;
share * s_y__tmp_765 = ycirc->PutCONSGate( _tmp_765 ,bitlen);
share * s_y_tmp_764 = ycirc->PutXORGate( s_y_tmp1 , s_y__tmp_765 );
vector<uint32_t> _vec766 = s_y_tmp_764->get_wires();
_vec766.erase( _vec766.begin(), _vec766.begin() + 8 );
share *s_y_tmp_763 = create_new_share( _vec766 , ycirc );
uint32_t _tmp_767 = 4294967295 ;
share * s_y__tmp_767 = ycirc->PutCONSGate( _tmp_767 ,bitlen);
share * s_y_tmp_762 = ycirc->PutXORGate( s_y_tmp_763 , s_y__tmp_767 );
share * s_y_tmp71 = ycirc->PutMUXGate( s_y_tmp_760 , s_y_tmp_762 , s_y_tmp_758 );
s_a_tmp70 = acirc->PutY2AGate( s_y_tmp70 ,bcirc);
s_a_tmp71 = acirc->PutY2AGate( s_y_tmp71 ,bcirc);
s_a_tmp69 = acirc->PutSUBGate( s_a_tmp70 , s_a_tmp71 );
s_a_tmp69 = create_new_share(s_a_tmp69->get_wires(), acirc );
share * s_y_tmp_768 = ycirc->PutINVGate( s_y_tmp63[0][0] );
uint32_t _tmp_769 = 1 ;
share * s_a__tmp_769 = acirc->PutCONSGate( _tmp_769 ,bitlen);
share *s_a_tmp_768 = acirc->PutY2AGate( s_y_tmp_768 ,bcirc);
s_a_tmp72 = acirc->PutADDGate( s_a_tmp_768 , s_a__tmp_769 );
s_a_tmp74 = create_new_share(s_a_tmp72->get_wires(), acirc );
uint32_t _tmp_771 = 2147483648 ;
share * s_y__tmp_771 = ycirc->PutCONSGate( _tmp_771 ,bitlen);
share * s_y_tmp_770 = ycirc->PutGTGate( s_y__tmp_771 , s_y_tmp1 );
vector<uint32_t> _vec773 = s_y_tmp1->get_wires();
_vec773.erase( _vec773.begin(), _vec773.begin() + 8 );
share *s_y_tmp_772 = create_new_share( _vec773 , ycirc );
uint32_t _tmp_777 = 4294967295 ;
share * s_y__tmp_777 = ycirc->PutCONSGate( _tmp_777 ,bitlen);
share * s_y_tmp_776 = ycirc->PutXORGate( s_y_tmp1 , s_y__tmp_777 );
vector<uint32_t> _vec778 = s_y_tmp_776->get_wires();
_vec778.erase( _vec778.begin(), _vec778.begin() + 8 );
share *s_y_tmp_775 = create_new_share( _vec778 , ycirc );
uint32_t _tmp_779 = 4294967295 ;
share * s_y__tmp_779 = ycirc->PutCONSGate( _tmp_779 ,bitlen);
share * s_y_tmp_774 = ycirc->PutXORGate( s_y_tmp_775 , s_y__tmp_779 );
share * s_y_tmp75 = ycirc->PutMUXGate( s_y_tmp_772 , s_y_tmp_774 , s_y_tmp_770 );
s_a_tmp75 = acirc->PutY2AGate( s_y_tmp75 ,bcirc);
s_a_tmp73 = acirc->PutSUBGate( s_a_tmp74 , s_a_tmp75 );
s_a_tmp73 = create_new_share(s_a_tmp73->get_wires(), acirc );
share * s_y_tmp_780 = ycirc->PutINVGate( s_y_tmp1 );
uint32_t _tmp_781 = 1 ;
share * s_a__tmp_781 = acirc->PutCONSGate( _tmp_781 ,bitlen);
share *s_a_tmp_780 = acirc->PutY2AGate( s_y_tmp_780 ,bcirc);
s_a_tmp76 = acirc->PutADDGate( s_a_tmp_780 , s_a__tmp_781 );
share *s_y_tmp73 = ycirc->PutA2YGate( s_a_tmp73 );
uint32_t _tmp_783 = 2147483648 ;
share * s_y__tmp_783 = ycirc->PutCONSGate( _tmp_783 ,bitlen);
share * s_y_tmp_782 = ycirc->PutGTGate( s_y__tmp_783 , s_y_tmp73 );
share *s_y_tmp76 = ycirc->PutA2YGate( s_a_tmp76 );
uint32_t _tmp_786 = 2147483648 ;
share * s_y__tmp_786 = ycirc->PutCONSGate( _tmp_786 ,bitlen);
share * s_y_tmp_785 = ycirc->PutGTGate( s_y__tmp_786 , s_y_tmp76 );
vector<uint32_t> _vec788 = s_y_tmp76->get_wires();
_vec788.erase( _vec788.begin(), _vec788.begin() + 8 );
share *s_y_tmp_787 = create_new_share( _vec788 , ycirc );
uint32_t _tmp_792 = 4294967295 ;
share * s_y__tmp_792 = ycirc->PutCONSGate( _tmp_792 ,bitlen);
share * s_y_tmp_791 = ycirc->PutXORGate( s_y_tmp76 , s_y__tmp_792 );
vector<uint32_t> _vec793 = s_y_tmp_791->get_wires();
_vec793.erase( _vec793.begin(), _vec793.begin() + 8 );
share *s_y_tmp_790 = create_new_share( _vec793 , ycirc );
uint32_t _tmp_794 = 4294967295 ;
share * s_y__tmp_794 = ycirc->PutCONSGate( _tmp_794 ,bitlen);
share * s_y_tmp_789 = ycirc->PutXORGate( s_y_tmp_790 , s_y__tmp_794 );
share * s_y_tmp_784 = ycirc->PutMUXGate( s_y_tmp_787 , s_y_tmp_789 , s_y_tmp_785 );
share * s_y_tmp77 = ycirc->PutMUXGate( s_y_tmp_784 , s_y_tmp63[0][0] , s_y_tmp_782 );
share *s_y_tmp69 = ycirc->PutA2YGate( s_a_tmp69 );
uint32_t _tmp_796 = 2147483648 ;
share * s_y__tmp_796 = ycirc->PutCONSGate( _tmp_796 ,bitlen);
share * s_y_tmp_795 = ycirc->PutGTGate( s_y__tmp_796 , s_y_tmp69 );
uint32_t _tmp_799 = 2147483648 ;
share * s_y__tmp_799 = ycirc->PutCONSGate( _tmp_799 ,bitlen);
share * s_y_tmp_798 = ycirc->PutGTGate( s_y__tmp_799 , s_y_tmp1 );
vector<uint32_t> _vec801 = s_y_tmp1->get_wires();
_vec801.erase( _vec801.begin(), _vec801.begin() + 8 );
share *s_y_tmp_800 = create_new_share( _vec801 , ycirc );
uint32_t _tmp_805 = 4294967295 ;
share * s_y__tmp_805 = ycirc->PutCONSGate( _tmp_805 ,bitlen);
share * s_y_tmp_804 = ycirc->PutXORGate( s_y_tmp1 , s_y__tmp_805 );
vector<uint32_t> _vec806 = s_y_tmp_804->get_wires();
_vec806.erase( _vec806.begin(), _vec806.begin() + 8 );
share *s_y_tmp_803 = create_new_share( _vec806 , ycirc );
uint32_t _tmp_807 = 4294967295 ;
share * s_y__tmp_807 = ycirc->PutCONSGate( _tmp_807 ,bitlen);
share * s_y_tmp_802 = ycirc->PutXORGate( s_y_tmp_803 , s_y__tmp_807 );
share * s_y_tmp_797 = ycirc->PutMUXGate( s_y_tmp_800 , s_y_tmp_802 , s_y_tmp_798 );
share * s_y_tmp78 = ycirc->PutMUXGate( s_y_tmp_797 , s_y_tmp77 , s_y_tmp_795 );
auto s_y_tmp80 = make_vector<share*>(1, 7);
for (uint32_t i46 = 0; i46 < 1; i46++)
{
    for (uint32_t i47 = 0; i47 < 7; i47++)
    {
        uint32_t _tmp_809 = 2147483648 ;
        share * s_y__tmp_809 = ycirc->PutCONSGate( _tmp_809 ,bitlen);
        share * s_y_tmp_808 = ycirc->PutGTGate( s_y__tmp_809 , s_y_WW[cur2][i46][i47] );
        vector<uint32_t> _vec811 = s_y_WW[cur2][i46][i47]->get_wires();
        _vec811.erase( _vec811.begin(), _vec811.begin() + 15 );
        share *s_y_tmp_810 = create_new_share( _vec811 , ycirc );
        uint32_t _tmp_815 = 4294967295 ;
        share * s_y__tmp_815 = ycirc->PutCONSGate( _tmp_815 ,bitlen);
        share * s_y_tmp_814 = ycirc->PutXORGate( s_y_WW[cur2][i46][i47] , s_y__tmp_815 );
        vector<uint32_t> _vec816 = s_y_tmp_814->get_wires();
        _vec816.erase( _vec816.begin(), _vec816.begin() + 15 );
        share *s_y_tmp_813 = create_new_share( _vec816 , ycirc );
        uint32_t _tmp_817 = 4294967295 ;
        share * s_y__tmp_817 = ycirc->PutCONSGate( _tmp_817 ,bitlen);
        share * s_y_tmp_812 = ycirc->PutXORGate( s_y_tmp_813 , s_y__tmp_817 );
        s_y_tmp80[i46][i47] = ycirc->PutMUXGate( s_y_tmp_810 , s_y_tmp_812 , s_y_tmp_808 );
    }
}
auto s_y_tmp81 = make_vector<share*>(7, 1000);
for (uint32_t i47 = 0; i47 < 7; i47++)
{
    for (uint32_t i48 = 0; i48 < 1000; i48++)
    {
        uint32_t _tmp_819 = 2147483648 ;
        share * s_y__tmp_819 = ycirc->PutCONSGate( _tmp_819 ,bitlen);
        share * s_y_tmp_818 = ycirc->PutGTGate( s_y__tmp_819 , s_y_ZZ[i47][i48] );
        vector<uint32_t> _vec821 = s_y_ZZ[i47][i48]->get_wires();
        _vec821.erase( _vec821.begin(), _vec821.begin() + 15 );
        share *s_y_tmp_820 = create_new_share( _vec821 , ycirc );
        uint32_t _tmp_825 = 4294967295 ;
        share * s_y__tmp_825 = ycirc->PutCONSGate( _tmp_825 ,bitlen);
        share * s_y_tmp_824 = ycirc->PutXORGate( s_y_ZZ[i47][i48] , s_y__tmp_825 );
        vector<uint32_t> _vec826 = s_y_tmp_824->get_wires();
        _vec826.erase( _vec826.begin(), _vec826.begin() + 15 );
        share *s_y_tmp_823 = create_new_share( _vec826 , ycirc );
        uint32_t _tmp_827 = 4294967295 ;
        share * s_y__tmp_827 = ycirc->PutCONSGate( _tmp_827 ,bitlen);
        share * s_y_tmp_822 = ycirc->PutXORGate( s_y_tmp_823 , s_y__tmp_827 );
        s_y_tmp81[i47][i48] = ycirc->PutMUXGate( s_y_tmp_820 , s_y_tmp_822 , s_y_tmp_818 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 7 ; _i4++) {
s_a_tmp80[_i1][_i4] = acirc->PutY2AGate( s_y_tmp80[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp81[_i1][_i4] = acirc->PutY2AGate( s_y_tmp81[_i1][_i4] ,bcirc);
}
}
for (uint32_t i46 = 0; i46 < 1; i46++)
{
    for (uint32_t i48 = 0; i48 < 1000; i48++)
    {
        for (uint32_t i47 = 0; i47 < 7; i47++)
        {
            s_a_tmp82[i46][i48][i47] = acirc->PutMULGate( s_a_tmp80[i46][i47] , s_a_tmp81[i47][i48] );
        }
    }
}
share * s_y_tmp83 ;
share * s_y_tmp84 ;
auto s_y_tmp82 = make_vector<share*>(1, 1000, 7);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
for (int _i7 = 0; _i7 < 7 ; _i7++) {
s_y_tmp82[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp82[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp79 = make_vector<share*>(1, 1000);
for (uint32_t i46 = 0; i46 < 1; i46++)
{
    for (uint32_t i48 = 0; i48 < 1000; i48++)
    {
        tmp83 = 7 ;
        s_y_tmp83 = ycirc->PutCONSGate( tmp83 ,bitlen);
        for (uint32_t i49 = 0; i49 < 3; i49++)
        {
            tmp84 = 0 ;
            s_y_tmp84 = ycirc->PutCONSGate( tmp84 ,bitlen);
            for (uint32_t i50 = 0; i50 < 4; i50++)
            {
                vector<uint32_t> _vec830 = s_y_tmp83->get_wires();
                _vec830.erase( _vec830.begin(), _vec830.begin() + 1 );
                share *s_y_tmp_829 = create_new_share( _vec830 , ycirc );
                share * s_y_tmp_828 = ycirc->PutGTGate( s_y_tmp_829 , s_y_tmp84 );
                share * s_y_tmp_833 = ycirc->PutADDGate( s_y_tmp82[i46][i48][(2*i50)] , s_y_tmp82[i46][i48][((2*i50)+1)] );
                uint32_t _tmp_834 = 2147483648 ;
                share * s_y__tmp_834 = ycirc->PutCONSGate( _tmp_834 ,bitlen);
                share * s_y_tmp_832 = ycirc->PutGTGate( s_y__tmp_834 , s_y_tmp_833 );
                share * s_y_tmp_836 = ycirc->PutADDGate( s_y_tmp82[i46][i48][(2*i50)] , s_y_tmp82[i46][i48][((2*i50)+1)] );
                vector<uint32_t> _vec837 = s_y_tmp_836->get_wires();
                _vec837.erase( _vec837.begin(), _vec837.begin() + 1 );
                share *s_y_tmp_835 = create_new_share( _vec837 , ycirc );
                share * s_y_tmp_841 = ycirc->PutADDGate( s_y_tmp82[i46][i48][(2*i50)] , s_y_tmp82[i46][i48][((2*i50)+1)] );
                uint32_t _tmp_842 = 4294967295 ;
                share * s_y__tmp_842 = ycirc->PutCONSGate( _tmp_842 ,bitlen);
                share * s_y_tmp_840 = ycirc->PutXORGate( s_y_tmp_841 , s_y__tmp_842 );
                vector<uint32_t> _vec843 = s_y_tmp_840->get_wires();
                _vec843.erase( _vec843.begin(), _vec843.begin() + 1 );
                share *s_y_tmp_839 = create_new_share( _vec843 , ycirc );
                uint32_t _tmp_844 = 4294967295 ;
                share * s_y__tmp_844 = ycirc->PutCONSGate( _tmp_844 ,bitlen);
                share * s_y_tmp_838 = ycirc->PutXORGate( s_y_tmp_839 , s_y__tmp_844 );
                share * s_y_tmp_831 = ycirc->PutMUXGate( s_y_tmp_835 , s_y_tmp_838 , s_y_tmp_832 );
                vector<uint32_t> _vec849 = s_y_tmp83->get_wires();
                _vec849.erase( _vec849.begin(), _vec849.begin() + 1 );
                share *s_y_tmp_848 = create_new_share( _vec849 , ycirc );
                share * s_y_tmp_847 = ycirc->PutEQGate( s_y_tmp84 , s_y_tmp_848 );
                uint32_t _tmp_852 = 1 ;
                share * s_y__tmp_852 = ycirc->PutCONSGate( _tmp_852 ,bitlen);
                share * s_y_tmp_851 = ycirc->PutANDGate( s_y_tmp83 , s_y__tmp_852 );
                uint32_t _tmp_853 = 1 ;
                share * s_y__tmp_853 = ycirc->PutCONSGate( _tmp_853 ,bitlen);
                share * s_y_tmp_850 = ycirc->PutEQGate( s_y_tmp_851 , s_y__tmp_853 );
                share * s_y_tmp_846 = ycirc->PutANDGate( s_y_tmp_847 , s_y_tmp_850 );
                uint32_t _tmp_856 = 2147483648 ;
                share * s_y__tmp_856 = ycirc->PutCONSGate( _tmp_856 ,bitlen);
                share * s_y_tmp_855 = ycirc->PutGTGate( s_y__tmp_856 , s_y_tmp82[i46][i48][(2*i50)] );
                vector<uint32_t> _vec858 = s_y_tmp82[i46][i48][(2*i50)]->get_wires();
                _vec858.erase( _vec858.begin(), _vec858.begin() + 1 );
                share *s_y_tmp_857 = create_new_share( _vec858 , ycirc );
                uint32_t _tmp_862 = 4294967295 ;
                share * s_y__tmp_862 = ycirc->PutCONSGate( _tmp_862 ,bitlen);
                share * s_y_tmp_861 = ycirc->PutXORGate( s_y_tmp82[i46][i48][(2*i50)] , s_y__tmp_862 );
                vector<uint32_t> _vec863 = s_y_tmp_861->get_wires();
                _vec863.erase( _vec863.begin(), _vec863.begin() + 1 );
                share *s_y_tmp_860 = create_new_share( _vec863 , ycirc );
                uint32_t _tmp_864 = 4294967295 ;
                share * s_y__tmp_864 = ycirc->PutCONSGate( _tmp_864 ,bitlen);
                share * s_y_tmp_859 = ycirc->PutXORGate( s_y_tmp_860 , s_y__tmp_864 );
                share * s_y_tmp_854 = ycirc->PutMUXGate( s_y_tmp_857 , s_y_tmp_859 , s_y_tmp_855 );
                uint32_t _tmp_865 = 0 ;
                share * s_y__tmp_865 = ycirc->PutCONSGate( _tmp_865 ,bitlen);
                share * s_y_tmp_845 = ycirc->PutMUXGate( s_y_tmp_854 , s_y__tmp_865 , s_y_tmp_846 );
                s_y_tmp82[i46][i48][i50] = ycirc->PutMUXGate( s_y_tmp_831 , s_y_tmp_845 , s_y_tmp_828 );
                uint32_t _tmp_866 = 1 ;
                share * s_y__tmp_866 = ycirc->PutCONSGate( _tmp_866 ,bitlen);
                s_y_tmp84 = ycirc->PutADDGate( s_y_tmp84 , s_y__tmp_866 );
            }
            uint32_t _tmp_868 = 1 ;
            share * s_y__tmp_868 = ycirc->PutCONSGate( _tmp_868 ,bitlen);
            share * s_y_tmp_867 = ycirc->PutADDGate( s_y_tmp83 , s_y__tmp_868 );
            vector<uint32_t> _vec869 = s_y_tmp_867->get_wires();
            _vec869.erase( _vec869.begin(), _vec869.begin() + 1 );
            s_y_tmp83 = create_new_share( _vec869 , ycirc );
        }
        for (uint32_t i49 = 0; i49 < 0; i49++)
        {
            tmp84 = 0 ;
            s_y_tmp84 = ycirc->PutCONSGate( tmp84 ,bitlen);
            for (uint32_t i50 = 0; i50 < 4; i50++)
            {
                vector<uint32_t> _vec872 = s_y_tmp83->get_wires();
                _vec872.erase( _vec872.begin(), _vec872.begin() + 1 );
                share *s_y_tmp_871 = create_new_share( _vec872 , ycirc );
                share * s_y_tmp_870 = ycirc->PutGTGate( s_y_tmp_871 , s_y_tmp84 );
                share * s_y_tmp_873 = ycirc->PutADDGate( s_y_tmp82[i46][i48][(2*i50)] , s_y_tmp82[i46][i48][((2*i50)+1)] );
                vector<uint32_t> _vec878 = s_y_tmp83->get_wires();
                _vec878.erase( _vec878.begin(), _vec878.begin() + 1 );
                share *s_y_tmp_877 = create_new_share( _vec878 , ycirc );
                share * s_y_tmp_876 = ycirc->PutEQGate( s_y_tmp84 , s_y_tmp_877 );
                uint32_t _tmp_881 = 1 ;
                share * s_y__tmp_881 = ycirc->PutCONSGate( _tmp_881 ,bitlen);
                share * s_y_tmp_880 = ycirc->PutANDGate( s_y_tmp83 , s_y__tmp_881 );
                uint32_t _tmp_882 = 1 ;
                share * s_y__tmp_882 = ycirc->PutCONSGate( _tmp_882 ,bitlen);
                share * s_y_tmp_879 = ycirc->PutEQGate( s_y_tmp_880 , s_y__tmp_882 );
                share * s_y_tmp_875 = ycirc->PutANDGate( s_y_tmp_876 , s_y_tmp_879 );
                uint32_t _tmp_883 = 0 ;
                share * s_y__tmp_883 = ycirc->PutCONSGate( _tmp_883 ,bitlen);
                share * s_y_tmp_874 = ycirc->PutMUXGate( s_y_tmp82[i46][i48][(2*i50)] , s_y__tmp_883 , s_y_tmp_875 );
                s_y_tmp82[i46][i48][i50] = ycirc->PutMUXGate( s_y_tmp_873 , s_y_tmp_874 , s_y_tmp_870 );
                uint32_t _tmp_884 = 1 ;
                share * s_y__tmp_884 = ycirc->PutCONSGate( _tmp_884 ,bitlen);
                s_y_tmp84 = ycirc->PutADDGate( s_y_tmp84 , s_y__tmp_884 );
            }
            uint32_t _tmp_886 = 1 ;
            share * s_y__tmp_886 = ycirc->PutCONSGate( _tmp_886 ,bitlen);
            share * s_y_tmp_885 = ycirc->PutADDGate( s_y_tmp83 , s_y__tmp_886 );
            vector<uint32_t> _vec887 = s_y_tmp_885->get_wires();
            _vec887.erase( _vec887.begin(), _vec887.begin() + 1 );
            s_y_tmp83 = create_new_share( _vec887 , ycirc );
        }
        s_y_tmp79[i46][i48] = create_new_share(s_y_tmp82[i46][i48][0]->get_wires(), ycirc );
    }
}
auto s_y_tmp86 = make_vector<share*>(1, 1000);
for (uint32_t i51 = 0; i51 < 1; i51++)
{
    for (uint32_t i52 = 0; i52 < 1000; i52++)
    {
        uint32_t _tmp_889 = 2147483648 ;
        share * s_y__tmp_889 = ycirc->PutCONSGate( _tmp_889 ,bitlen);
        share * s_y_tmp_888 = ycirc->PutGTGate( s_y__tmp_889 , s_y_tmp79[i51][i52] );
        vector<uint32_t> _vec891 = s_y_tmp79[i51][i52]->get_wires();
        _vec891.erase( _vec891.begin(), _vec891.begin() + 15 );
        share *s_y_tmp_890 = create_new_share( _vec891 , ycirc );
        uint32_t _tmp_895 = 4294967295 ;
        share * s_y__tmp_895 = ycirc->PutCONSGate( _tmp_895 ,bitlen);
        share * s_y_tmp_894 = ycirc->PutXORGate( s_y_tmp79[i51][i52] , s_y__tmp_895 );
        vector<uint32_t> _vec896 = s_y_tmp_894->get_wires();
        _vec896.erase( _vec896.begin(), _vec896.begin() + 15 );
        share *s_y_tmp_893 = create_new_share( _vec896 , ycirc );
        uint32_t _tmp_897 = 4294967295 ;
        share * s_y__tmp_897 = ycirc->PutCONSGate( _tmp_897 ,bitlen);
        share * s_y_tmp_892 = ycirc->PutXORGate( s_y_tmp_893 , s_y__tmp_897 );
        s_y_tmp86[i51][i52] = ycirc->PutMUXGate( s_y_tmp_890 , s_y_tmp_892 , s_y_tmp_888 );
    }
}
auto s_y_tmp87 = make_vector<share*>(1000, 1);
for (uint32_t i52 = 0; i52 < 1000; i52++)
{
    for (uint32_t i53 = 0; i53 < 1; i53++)
    {
        uint32_t _tmp_899 = 2147483648 ;
        share * s_y__tmp_899 = ycirc->PutCONSGate( _tmp_899 ,bitlen);
        share * s_y_tmp_898 = ycirc->PutGTGate( s_y__tmp_899 , s_y_xx[i52][i53] );
        vector<uint32_t> _vec901 = s_y_xx[i52][i53]->get_wires();
        _vec901.erase( _vec901.begin(), _vec901.begin() + 15 );
        share *s_y_tmp_900 = create_new_share( _vec901 , ycirc );
        uint32_t _tmp_905 = 4294967295 ;
        share * s_y__tmp_905 = ycirc->PutCONSGate( _tmp_905 ,bitlen);
        share * s_y_tmp_904 = ycirc->PutXORGate( s_y_xx[i52][i53] , s_y__tmp_905 );
        vector<uint32_t> _vec906 = s_y_tmp_904->get_wires();
        _vec906.erase( _vec906.begin(), _vec906.begin() + 15 );
        share *s_y_tmp_903 = create_new_share( _vec906 , ycirc );
        uint32_t _tmp_907 = 4294967295 ;
        share * s_y__tmp_907 = ycirc->PutCONSGate( _tmp_907 ,bitlen);
        share * s_y_tmp_902 = ycirc->PutXORGate( s_y_tmp_903 , s_y__tmp_907 );
        s_y_tmp87[i52][i53] = ycirc->PutMUXGate( s_y_tmp_900 , s_y_tmp_902 , s_y_tmp_898 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1000 ; _i4++) {
s_a_tmp86[_i1][_i4] = acirc->PutY2AGate( s_y_tmp86[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1000 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp87[_i1][_i4] = acirc->PutY2AGate( s_y_tmp87[_i1][_i4] ,bcirc);
}
}
for (uint32_t i51 = 0; i51 < 1; i51++)
{
    for (uint32_t i53 = 0; i53 < 1; i53++)
    {
        for (uint32_t i52 = 0; i52 < 1000; i52++)
        {
            s_a_tmp88[i51][i53][i52] = acirc->PutMULGate( s_a_tmp86[i51][i52] , s_a_tmp87[i52][i53] );
        }
    }
}
share * s_y_tmp89 ;
share * s_y_tmp90 ;
auto s_y_tmp88 = make_vector<share*>(1, 1, 1000);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1000 ; _i7++) {
s_y_tmp88[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp88[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp85 = make_vector<share*>(1, 1);
for (uint32_t i51 = 0; i51 < 1; i51++)
{
    for (uint32_t i53 = 0; i53 < 1; i53++)
    {
        tmp89 = 1000 ;
        s_y_tmp89 = ycirc->PutCONSGate( tmp89 ,bitlen);
        for (uint32_t i54 = 0; i54 < 0; i54++)
        {
            tmp90 = 0 ;
            s_y_tmp90 = ycirc->PutCONSGate( tmp90 ,bitlen);
            for (uint32_t i55 = 0; i55 < 501; i55++)
            {
                vector<uint32_t> _vec910 = s_y_tmp89->get_wires();
                _vec910.erase( _vec910.begin(), _vec910.begin() + 1 );
                share *s_y_tmp_909 = create_new_share( _vec910 , ycirc );
                share * s_y_tmp_908 = ycirc->PutGTGate( s_y_tmp_909 , s_y_tmp90 );
                share * s_y_tmp_913 = ycirc->PutADDGate( s_y_tmp88[i51][i53][(2*i55)] , s_y_tmp88[i51][i53][((2*i55)+1)] );
                uint32_t _tmp_914 = 2147483648 ;
                share * s_y__tmp_914 = ycirc->PutCONSGate( _tmp_914 ,bitlen);
                share * s_y_tmp_912 = ycirc->PutGTGate( s_y__tmp_914 , s_y_tmp_913 );
                share * s_y_tmp_916 = ycirc->PutADDGate( s_y_tmp88[i51][i53][(2*i55)] , s_y_tmp88[i51][i53][((2*i55)+1)] );
                vector<uint32_t> _vec917 = s_y_tmp_916->get_wires();
                _vec917.erase( _vec917.begin(), _vec917.begin() + 1 );
                share *s_y_tmp_915 = create_new_share( _vec917 , ycirc );
                share * s_y_tmp_921 = ycirc->PutADDGate( s_y_tmp88[i51][i53][(2*i55)] , s_y_tmp88[i51][i53][((2*i55)+1)] );
                uint32_t _tmp_922 = 4294967295 ;
                share * s_y__tmp_922 = ycirc->PutCONSGate( _tmp_922 ,bitlen);
                share * s_y_tmp_920 = ycirc->PutXORGate( s_y_tmp_921 , s_y__tmp_922 );
                vector<uint32_t> _vec923 = s_y_tmp_920->get_wires();
                _vec923.erase( _vec923.begin(), _vec923.begin() + 1 );
                share *s_y_tmp_919 = create_new_share( _vec923 , ycirc );
                uint32_t _tmp_924 = 4294967295 ;
                share * s_y__tmp_924 = ycirc->PutCONSGate( _tmp_924 ,bitlen);
                share * s_y_tmp_918 = ycirc->PutXORGate( s_y_tmp_919 , s_y__tmp_924 );
                share * s_y_tmp_911 = ycirc->PutMUXGate( s_y_tmp_915 , s_y_tmp_918 , s_y_tmp_912 );
                vector<uint32_t> _vec929 = s_y_tmp89->get_wires();
                _vec929.erase( _vec929.begin(), _vec929.begin() + 1 );
                share *s_y_tmp_928 = create_new_share( _vec929 , ycirc );
                share * s_y_tmp_927 = ycirc->PutEQGate( s_y_tmp90 , s_y_tmp_928 );
                uint32_t _tmp_932 = 1 ;
                share * s_y__tmp_932 = ycirc->PutCONSGate( _tmp_932 ,bitlen);
                share * s_y_tmp_931 = ycirc->PutANDGate( s_y_tmp89 , s_y__tmp_932 );
                uint32_t _tmp_933 = 1 ;
                share * s_y__tmp_933 = ycirc->PutCONSGate( _tmp_933 ,bitlen);
                share * s_y_tmp_930 = ycirc->PutEQGate( s_y_tmp_931 , s_y__tmp_933 );
                share * s_y_tmp_926 = ycirc->PutANDGate( s_y_tmp_927 , s_y_tmp_930 );
                uint32_t _tmp_936 = 2147483648 ;
                share * s_y__tmp_936 = ycirc->PutCONSGate( _tmp_936 ,bitlen);
                share * s_y_tmp_935 = ycirc->PutGTGate( s_y__tmp_936 , s_y_tmp88[i51][i53][(2*i55)] );
                vector<uint32_t> _vec938 = s_y_tmp88[i51][i53][(2*i55)]->get_wires();
                _vec938.erase( _vec938.begin(), _vec938.begin() + 1 );
                share *s_y_tmp_937 = create_new_share( _vec938 , ycirc );
                uint32_t _tmp_942 = 4294967295 ;
                share * s_y__tmp_942 = ycirc->PutCONSGate( _tmp_942 ,bitlen);
                share * s_y_tmp_941 = ycirc->PutXORGate( s_y_tmp88[i51][i53][(2*i55)] , s_y__tmp_942 );
                vector<uint32_t> _vec943 = s_y_tmp_941->get_wires();
                _vec943.erase( _vec943.begin(), _vec943.begin() + 1 );
                share *s_y_tmp_940 = create_new_share( _vec943 , ycirc );
                uint32_t _tmp_944 = 4294967295 ;
                share * s_y__tmp_944 = ycirc->PutCONSGate( _tmp_944 ,bitlen);
                share * s_y_tmp_939 = ycirc->PutXORGate( s_y_tmp_940 , s_y__tmp_944 );
                share * s_y_tmp_934 = ycirc->PutMUXGate( s_y_tmp_937 , s_y_tmp_939 , s_y_tmp_935 );
                uint32_t _tmp_945 = 0 ;
                share * s_y__tmp_945 = ycirc->PutCONSGate( _tmp_945 ,bitlen);
                share * s_y_tmp_925 = ycirc->PutMUXGate( s_y_tmp_934 , s_y__tmp_945 , s_y_tmp_926 );
                s_y_tmp88[i51][i53][i55] = ycirc->PutMUXGate( s_y_tmp_911 , s_y_tmp_925 , s_y_tmp_908 );
                uint32_t _tmp_946 = 1 ;
                share * s_y__tmp_946 = ycirc->PutCONSGate( _tmp_946 ,bitlen);
                s_y_tmp90 = ycirc->PutADDGate( s_y_tmp90 , s_y__tmp_946 );
            }
            uint32_t _tmp_948 = 1 ;
            share * s_y__tmp_948 = ycirc->PutCONSGate( _tmp_948 ,bitlen);
            share * s_y_tmp_947 = ycirc->PutADDGate( s_y_tmp89 , s_y__tmp_948 );
            vector<uint32_t> _vec949 = s_y_tmp_947->get_wires();
            _vec949.erase( _vec949.begin(), _vec949.begin() + 1 );
            s_y_tmp89 = create_new_share( _vec949 , ycirc );
        }
        for (uint32_t i54 = 0; i54 < 10; i54++)
        {
            tmp90 = 0 ;
            s_y_tmp90 = ycirc->PutCONSGate( tmp90 ,bitlen);
            for (uint32_t i55 = 0; i55 < 501; i55++)
            {
                vector<uint32_t> _vec952 = s_y_tmp89->get_wires();
                _vec952.erase( _vec952.begin(), _vec952.begin() + 1 );
                share *s_y_tmp_951 = create_new_share( _vec952 , ycirc );
                share * s_y_tmp_950 = ycirc->PutGTGate( s_y_tmp_951 , s_y_tmp90 );
                share * s_y_tmp_953 = ycirc->PutADDGate( s_y_tmp88[i51][i53][(2*i55)] , s_y_tmp88[i51][i53][((2*i55)+1)] );
                vector<uint32_t> _vec958 = s_y_tmp89->get_wires();
                _vec958.erase( _vec958.begin(), _vec958.begin() + 1 );
                share *s_y_tmp_957 = create_new_share( _vec958 , ycirc );
                share * s_y_tmp_956 = ycirc->PutEQGate( s_y_tmp90 , s_y_tmp_957 );
                uint32_t _tmp_961 = 1 ;
                share * s_y__tmp_961 = ycirc->PutCONSGate( _tmp_961 ,bitlen);
                share * s_y_tmp_960 = ycirc->PutANDGate( s_y_tmp89 , s_y__tmp_961 );
                uint32_t _tmp_962 = 1 ;
                share * s_y__tmp_962 = ycirc->PutCONSGate( _tmp_962 ,bitlen);
                share * s_y_tmp_959 = ycirc->PutEQGate( s_y_tmp_960 , s_y__tmp_962 );
                share * s_y_tmp_955 = ycirc->PutANDGate( s_y_tmp_956 , s_y_tmp_959 );
                uint32_t _tmp_963 = 0 ;
                share * s_y__tmp_963 = ycirc->PutCONSGate( _tmp_963 ,bitlen);
                share * s_y_tmp_954 = ycirc->PutMUXGate( s_y_tmp88[i51][i53][(2*i55)] , s_y__tmp_963 , s_y_tmp_955 );
                s_y_tmp88[i51][i53][i55] = ycirc->PutMUXGate( s_y_tmp_953 , s_y_tmp_954 , s_y_tmp_950 );
                uint32_t _tmp_964 = 1 ;
                share * s_y__tmp_964 = ycirc->PutCONSGate( _tmp_964 ,bitlen);
                s_y_tmp90 = ycirc->PutADDGate( s_y_tmp90 , s_y__tmp_964 );
            }
            uint32_t _tmp_966 = 1 ;
            share * s_y__tmp_966 = ycirc->PutCONSGate( _tmp_966 ,bitlen);
            share * s_y_tmp_965 = ycirc->PutADDGate( s_y_tmp89 , s_y__tmp_966 );
            vector<uint32_t> _vec967 = s_y_tmp_965->get_wires();
            _vec967.erase( _vec967.begin(), _vec967.begin() + 1 );
            s_y_tmp89 = create_new_share( _vec967 , ycirc );
        }
        s_y_tmp85[i51][i53] = create_new_share(s_y_tmp88[i51][i53][0]->get_wires(), ycirc );
    }
}
auto s_y_tmp92 = make_vector<share*>(1, 1);
for (uint32_t i56 = 0; i56 < 1; i56++)
{
    for (uint32_t i57 = 0; i57 < 1; i57++)
    {
        uint32_t _tmp_969 = 2147483648 ;
        share * s_y__tmp_969 = ycirc->PutCONSGate( _tmp_969 ,bitlen);
        share * s_y_tmp_968 = ycirc->PutGTGate( s_y__tmp_969 , s_y_tmp85[i56][i57] );
        vector<uint32_t> _vec971 = s_y_tmp85[i56][i57]->get_wires();
        _vec971.erase( _vec971.begin(), _vec971.begin() + 15 );
        share *s_y_tmp_970 = create_new_share( _vec971 , ycirc );
        uint32_t _tmp_975 = 4294967295 ;
        share * s_y__tmp_975 = ycirc->PutCONSGate( _tmp_975 ,bitlen);
        share * s_y_tmp_974 = ycirc->PutXORGate( s_y_tmp85[i56][i57] , s_y__tmp_975 );
        vector<uint32_t> _vec976 = s_y_tmp_974->get_wires();
        _vec976.erase( _vec976.begin(), _vec976.begin() + 15 );
        share *s_y_tmp_973 = create_new_share( _vec976 , ycirc );
        uint32_t _tmp_977 = 4294967295 ;
        share * s_y__tmp_977 = ycirc->PutCONSGate( _tmp_977 ,bitlen);
        share * s_y_tmp_972 = ycirc->PutXORGate( s_y_tmp_973 , s_y__tmp_977 );
        s_y_tmp92[i56][i57] = ycirc->PutMUXGate( s_y_tmp_970 , s_y_tmp_972 , s_y_tmp_968 );
    }
}
uint32_t _tmp_979 = 2147483648 ;
share * s_y__tmp_979 = ycirc->PutCONSGate( _tmp_979 ,bitlen);
share * s_y_tmp_978 = ycirc->PutGTGate( s_y__tmp_979 , s_y_tmp78 );
vector<uint32_t> _vec981 = s_y_tmp78->get_wires();
_vec981.erase( _vec981.begin(), _vec981.begin() + 15 );
share *s_y_tmp_980 = create_new_share( _vec981 , ycirc );
uint32_t _tmp_985 = 4294967295 ;
share * s_y__tmp_985 = ycirc->PutCONSGate( _tmp_985 ,bitlen);
share * s_y_tmp_984 = ycirc->PutXORGate( s_y_tmp78 , s_y__tmp_985 );
vector<uint32_t> _vec986 = s_y_tmp_984->get_wires();
_vec986.erase( _vec986.begin(), _vec986.begin() + 15 );
share *s_y_tmp_983 = create_new_share( _vec986 , ycirc );
uint32_t _tmp_987 = 4294967295 ;
share * s_y__tmp_987 = ycirc->PutCONSGate( _tmp_987 ,bitlen);
share * s_y_tmp_982 = ycirc->PutXORGate( s_y_tmp_983 , s_y__tmp_987 );
share * s_y_tmp93 = ycirc->PutMUXGate( s_y_tmp_980 , s_y_tmp_982 , s_y_tmp_978 );
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp92[_i1][_i4] = acirc->PutY2AGate( s_y_tmp92[_i1][_i4] ,bcirc);
}
}
s_a_tmp93 = acirc->PutY2AGate( s_y_tmp93 ,bcirc);
for (uint32_t i56 = 0; i56 < 1; i56++)
{
    for (uint32_t i57 = 0; i57 < 1; i57++)
    {
        s_a_tmp91[i56][i57] = acirc->PutMULGate( s_a_tmp92[i56][i57] , s_a_tmp93 );
    }
}
for (uint32_t i58 = 0; i58 < 1; i58++)
{
    for (uint32_t i59 = 0; i59 < 1; i59++)
    {
        s_a_tmp95 = create_new_share(s_a_tmp91[i58][i59]->get_wires(), acirc );
        s_a_tmp96 = create_new_share(s_a_tmp39[i58][i59]->get_wires(), acirc );
        s_a_tmp94[i58][i59] = acirc->PutADDGate( s_a_tmp95 , s_a_tmp96 );
        s_a_tmp94[i58][i59] = create_new_share(s_a_tmp94[i58][i59]->get_wires(), acirc );
    }
}
auto s_y_tmp94 = make_vector<share*>(1, 1);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp94[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp94[_i1][_i4] );
}
}
uint32_t _tmp_991 = 2147483648 ;
share * s_y__tmp_991 = ycirc->PutCONSGate( _tmp_991 ,bitlen);
share * s_y_tmp_990 = ycirc->PutGTGate( s_y__tmp_991 , s_y_tmp94[0][0] );
uint32_t _tmp_992 = 1 ;
share * s_y__tmp_992 = ycirc->PutCONSGate( _tmp_992 ,bitlen);
uint32_t _tmp_993 = 0 ;
share * s_y__tmp_993 = ycirc->PutCONSGate( _tmp_993 ,bitlen);
share * s_y_tmp_989 = ycirc->PutMUXGate( s_y__tmp_992 , s_y__tmp_993 , s_y_tmp_990 );
share * s_y_tmp_988 = ycirc->PutOUTGate( s_y_tmp_989 , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_988->get_clear_value<uint32_t>();
