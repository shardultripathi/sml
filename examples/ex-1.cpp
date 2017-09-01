ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto WW = make_vector<uint32_t>(784, 10);
auto s_a_WW = make_vector<share*>(784, 10);
auto bb = make_vector<uint32_t>(10);
auto s_a_bb = make_vector<share*>(10);
auto xx = make_vector<uint32_t>(1, 784);
auto s_a_xx = make_vector<share*>(1, 784);
auto tmp0 = make_vector<uint32_t>(1, 10);
auto s_a_tmp0 = make_vector<share*>(1, 10);
auto tmp1 = make_vector<uint32_t>(1, 784);
auto s_a_tmp1 = make_vector<share*>(1, 784);
auto tmp2 = make_vector<uint32_t>(784, 10);
auto s_a_tmp2 = make_vector<share*>(784, 10);
auto tmp3 = make_vector<uint32_t>(1, 10, 784);
auto s_a_tmp3 = make_vector<share*>(1, 10, 784);
uint32_t tmp4;
share *s_a_tmp4;
uint32_t tmp5;
share *s_a_tmp5;
auto tmp6 = make_vector<uint32_t>(1, 10);
auto s_a_tmp6 = make_vector<share*>(1, 10);
uint32_t tmp7;
share *s_a_tmp7;
uint32_t tmp8;
share *s_a_tmp8;
uint32_t tmp9;
share *s_a_tmp9;
uint32_t tmp10;
share *s_a_tmp10;
uint32_t tmp11;
share *s_a_tmp11;
uint32_t tmp12;
share *s_a_tmp12;
for (uint32_t i9 = 0; i9 < 784; i9++)
{
    for (uint32_t i10 = 0; i10 < 10; i10++)
    {
        if (role == CLIENT) {
            WW = 456 ;
            s_a_WW[i9][i10] = acirc->PutINGate( WW ,bitlen,CLIENT);
        } else {
            s_a_WW[i9][i10] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i11 = 0; i11 < 10; i11++)
{
    if (role == CLIENT) {
        bb = 456 ;
        s_a_bb[i11] = acirc->PutINGate( bb ,bitlen,CLIENT);
    } else {
        s_a_bb[i11] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i12 = 0; i12 < 1; i12++)
{
    for (uint32_t i13 = 0; i13 < 784; i13++)
    {
        if (role == SERVER) {
            xx = 123 ;
            s_a_xx[i12][i13] = acirc->PutINGate( xx ,bitlen,SERVER);
        } else {
            s_a_xx[i12][i13] = acirc->PutDummyINGate(bitlen);
        }
    }
}
auto s_y_xx = make_vector<share*>(1, 784);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 784 ; _i4++) {
s_y_xx[_i1][_i4] = ycirc->PutA2YGate( s_a_xx[_i1][_i4] );
}
}
auto s_y_tmp1 = make_vector<share*>(1, 784);
for (uint32_t i0 = 0; i0 < 1; i0++)
{
    for (uint32_t i1 = 0; i1 < 784; i1++)
    {
        uint32_t _tmp_1 = 2147483648 ;
        share * s_y__tmp_1 = ycirc->PutCONSGate( _tmp_1 ,bitlen);
        share * s_y_tmp_0 = ycirc->PutGTGate( s_y__tmp_1 , s_y_xx[i0][i1] );
        vector<uint32_t> _vec3 = s_y_xx[i0][i1]->get_wires();
        _vec3.erase( _vec3.begin(), _vec3.begin() + 15 );
        share *s_y_tmp_2 = create_new_share( _vec3 , ycirc );
        uint32_t _tmp_7 = 4294967295 ;
        share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
        share * s_y_tmp_6 = ycirc->PutXORGate( s_y_xx[i0][i1] , s_y__tmp_7 );
        vector<uint32_t> _vec8 = s_y_tmp_6->get_wires();
        _vec8.erase( _vec8.begin(), _vec8.begin() + 15 );
        share *s_y_tmp_5 = create_new_share( _vec8 , ycirc );
        uint32_t _tmp_9 = 4294967295 ;
        share * s_y__tmp_9 = ycirc->PutCONSGate( _tmp_9 ,bitlen);
        share * s_y_tmp_4 = ycirc->PutXORGate( s_y_tmp_5 , s_y__tmp_9 );
        s_y_tmp1[i0][i1] = ycirc->PutMUXGate( s_y_tmp_2 , s_y_tmp_4 , s_y_tmp_0 );
    }
}
auto s_y_WW = make_vector<share*>(784, 10);
for (int _i1 = 0; _i1 < 784 ; _i1++) {
for (int _i4 = 0; _i4 < 10 ; _i4++) {
s_y_WW[_i1][_i4] = ycirc->PutA2YGate( s_a_WW[_i1][_i4] );
}
}
auto s_y_tmp2 = make_vector<share*>(784, 10);
for (uint32_t i1 = 0; i1 < 784; i1++)
{
    for (uint32_t i2 = 0; i2 < 10; i2++)
    {
        uint32_t _tmp_11 = 2147483648 ;
        share * s_y__tmp_11 = ycirc->PutCONSGate( _tmp_11 ,bitlen);
        share * s_y_tmp_10 = ycirc->PutGTGate( s_y__tmp_11 , s_y_WW[i1][i2] );
        vector<uint32_t> _vec13 = s_y_WW[i1][i2]->get_wires();
        _vec13.erase( _vec13.begin(), _vec13.begin() + 15 );
        share *s_y_tmp_12 = create_new_share( _vec13 , ycirc );
        uint32_t _tmp_17 = 4294967295 ;
        share * s_y__tmp_17 = ycirc->PutCONSGate( _tmp_17 ,bitlen);
        share * s_y_tmp_16 = ycirc->PutXORGate( s_y_WW[i1][i2] , s_y__tmp_17 );
        vector<uint32_t> _vec18 = s_y_tmp_16->get_wires();
        _vec18.erase( _vec18.begin(), _vec18.begin() + 15 );
        share *s_y_tmp_15 = create_new_share( _vec18 , ycirc );
        uint32_t _tmp_19 = 4294967295 ;
        share * s_y__tmp_19 = ycirc->PutCONSGate( _tmp_19 ,bitlen);
        share * s_y_tmp_14 = ycirc->PutXORGate( s_y_tmp_15 , s_y__tmp_19 );
        s_y_tmp2[i1][i2] = ycirc->PutMUXGate( s_y_tmp_12 , s_y_tmp_14 , s_y_tmp_10 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 784 ; _i4++) {
s_a_tmp1[_i1][_i4] = acirc->PutY2AGate( s_y_tmp1[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 784 ; _i1++) {
for (int _i4 = 0; _i4 < 10 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 1; i0++)
{
    for (uint32_t i2 = 0; i2 < 10; i2++)
    {
        for (uint32_t i1 = 0; i1 < 784; i1++)
        {
            s_a_tmp3[i0][i2][i1] = acirc->PutMULGate( s_a_tmp1[i0][i1] , s_a_tmp2[i1][i2] );
        }
    }
}
share * s_y_tmp4 ;
share * s_y_tmp5 ;
auto s_y_tmp3 = make_vector<share*>(1, 10, 784);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 10 ; _i4++) {
for (int _i7 = 0; _i7 < 784 ; _i7++) {
s_y_tmp3[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp3[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp0 = make_vector<share*>(1, 10);
for (uint32_t i0 = 0; i0 < 1; i0++)
{
    for (uint32_t i2 = 0; i2 < 10; i2++)
    {
        tmp4 = 784 ;
        s_y_tmp4 = ycirc->PutCONSGate( tmp4 ,bitlen);
        for (uint32_t i3 = 0; i3 < 5; i3++)
        {
            tmp5 = 0 ;
            s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
            for (uint32_t i4 = 0; i4 < 393; i4++)
            {
                vector<uint32_t> _vec22 = s_y_tmp4->get_wires();
                _vec22.erase( _vec22.begin(), _vec22.begin() + 1 );
                share *s_y_tmp_21 = create_new_share( _vec22 , ycirc );
                share * s_y_tmp_20 = ycirc->PutGTGate( s_y_tmp_21 , s_y_tmp5 );
                share * s_y_tmp_25 = ycirc->PutADDGate( s_y_tmp3[i0][i2][(2*i4)] , s_y_tmp3[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_26 = 2147483648 ;
                share * s_y__tmp_26 = ycirc->PutCONSGate( _tmp_26 ,bitlen);
                share * s_y_tmp_24 = ycirc->PutGTGate( s_y__tmp_26 , s_y_tmp_25 );
                share * s_y_tmp_28 = ycirc->PutADDGate( s_y_tmp3[i0][i2][(2*i4)] , s_y_tmp3[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec29 = s_y_tmp_28->get_wires();
                _vec29.erase( _vec29.begin(), _vec29.begin() + 1 );
                share *s_y_tmp_27 = create_new_share( _vec29 , ycirc );
                share * s_y_tmp_33 = ycirc->PutADDGate( s_y_tmp3[i0][i2][(2*i4)] , s_y_tmp3[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_34 = 4294967295 ;
                share * s_y__tmp_34 = ycirc->PutCONSGate( _tmp_34 ,bitlen);
                share * s_y_tmp_32 = ycirc->PutXORGate( s_y_tmp_33 , s_y__tmp_34 );
                vector<uint32_t> _vec35 = s_y_tmp_32->get_wires();
                _vec35.erase( _vec35.begin(), _vec35.begin() + 1 );
                share *s_y_tmp_31 = create_new_share( _vec35 , ycirc );
                uint32_t _tmp_36 = 4294967295 ;
                share * s_y__tmp_36 = ycirc->PutCONSGate( _tmp_36 ,bitlen);
                share * s_y_tmp_30 = ycirc->PutXORGate( s_y_tmp_31 , s_y__tmp_36 );
                share * s_y_tmp_23 = ycirc->PutMUXGate( s_y_tmp_27 , s_y_tmp_30 , s_y_tmp_24 );
                vector<uint32_t> _vec41 = s_y_tmp4->get_wires();
                _vec41.erase( _vec41.begin(), _vec41.begin() + 1 );
                share *s_y_tmp_40 = create_new_share( _vec41 , ycirc );
                share * s_y_tmp_39 = ycirc->PutEQGate( s_y_tmp5 , s_y_tmp_40 );
                uint32_t _tmp_44 = 1 ;
                share * s_y__tmp_44 = ycirc->PutCONSGate( _tmp_44 ,bitlen);
                share * s_y_tmp_43 = ycirc->PutANDGate( s_y_tmp4 , s_y__tmp_44 );
                uint32_t _tmp_45 = 1 ;
                share * s_y__tmp_45 = ycirc->PutCONSGate( _tmp_45 ,bitlen);
                share * s_y_tmp_42 = ycirc->PutEQGate( s_y_tmp_43 , s_y__tmp_45 );
                share * s_y_tmp_38 = ycirc->PutANDGate( s_y_tmp_39 , s_y_tmp_42 );
                uint32_t _tmp_48 = 2147483648 ;
                share * s_y__tmp_48 = ycirc->PutCONSGate( _tmp_48 ,bitlen);
                share * s_y_tmp_47 = ycirc->PutGTGate( s_y__tmp_48 , s_y_tmp3[i0][i2][(2*i4)] );
                vector<uint32_t> _vec50 = s_y_tmp3[i0][i2][(2*i4)]->get_wires();
                _vec50.erase( _vec50.begin(), _vec50.begin() + 1 );
                share *s_y_tmp_49 = create_new_share( _vec50 , ycirc );
                uint32_t _tmp_54 = 4294967295 ;
                share * s_y__tmp_54 = ycirc->PutCONSGate( _tmp_54 ,bitlen);
                share * s_y_tmp_53 = ycirc->PutXORGate( s_y_tmp3[i0][i2][(2*i4)] , s_y__tmp_54 );
                vector<uint32_t> _vec55 = s_y_tmp_53->get_wires();
                _vec55.erase( _vec55.begin(), _vec55.begin() + 1 );
                share *s_y_tmp_52 = create_new_share( _vec55 , ycirc );
                uint32_t _tmp_56 = 4294967295 ;
                share * s_y__tmp_56 = ycirc->PutCONSGate( _tmp_56 ,bitlen);
                share * s_y_tmp_51 = ycirc->PutXORGate( s_y_tmp_52 , s_y__tmp_56 );
                share * s_y_tmp_46 = ycirc->PutMUXGate( s_y_tmp_49 , s_y_tmp_51 , s_y_tmp_47 );
                uint32_t _tmp_57 = 0 ;
                share * s_y__tmp_57 = ycirc->PutCONSGate( _tmp_57 ,bitlen);
                share * s_y_tmp_37 = ycirc->PutMUXGate( s_y_tmp_46 , s_y__tmp_57 , s_y_tmp_38 );
                s_y_tmp3[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_23 , s_y_tmp_37 , s_y_tmp_20 );
                uint32_t _tmp_58 = 1 ;
                share * s_y__tmp_58 = ycirc->PutCONSGate( _tmp_58 ,bitlen);
                s_y_tmp5 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_58 );
            }
            uint32_t _tmp_60 = 1 ;
            share * s_y__tmp_60 = ycirc->PutCONSGate( _tmp_60 ,bitlen);
            share * s_y_tmp_59 = ycirc->PutADDGate( s_y_tmp4 , s_y__tmp_60 );
            vector<uint32_t> _vec61 = s_y_tmp_59->get_wires();
            _vec61.erase( _vec61.begin(), _vec61.begin() + 1 );
            s_y_tmp4 = create_new_share( _vec61 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 5; i3++)
        {
            tmp5 = 0 ;
            s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
            for (uint32_t i4 = 0; i4 < 393; i4++)
            {
                vector<uint32_t> _vec64 = s_y_tmp4->get_wires();
                _vec64.erase( _vec64.begin(), _vec64.begin() + 1 );
                share *s_y_tmp_63 = create_new_share( _vec64 , ycirc );
                share * s_y_tmp_62 = ycirc->PutGTGate( s_y_tmp_63 , s_y_tmp5 );
                share * s_y_tmp_65 = ycirc->PutADDGate( s_y_tmp3[i0][i2][(2*i4)] , s_y_tmp3[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec70 = s_y_tmp4->get_wires();
                _vec70.erase( _vec70.begin(), _vec70.begin() + 1 );
                share *s_y_tmp_69 = create_new_share( _vec70 , ycirc );
                share * s_y_tmp_68 = ycirc->PutEQGate( s_y_tmp5 , s_y_tmp_69 );
                uint32_t _tmp_73 = 1 ;
                share * s_y__tmp_73 = ycirc->PutCONSGate( _tmp_73 ,bitlen);
                share * s_y_tmp_72 = ycirc->PutANDGate( s_y_tmp4 , s_y__tmp_73 );
                uint32_t _tmp_74 = 1 ;
                share * s_y__tmp_74 = ycirc->PutCONSGate( _tmp_74 ,bitlen);
                share * s_y_tmp_71 = ycirc->PutEQGate( s_y_tmp_72 , s_y__tmp_74 );
                share * s_y_tmp_67 = ycirc->PutANDGate( s_y_tmp_68 , s_y_tmp_71 );
                uint32_t _tmp_75 = 0 ;
                share * s_y__tmp_75 = ycirc->PutCONSGate( _tmp_75 ,bitlen);
                share * s_y_tmp_66 = ycirc->PutMUXGate( s_y_tmp3[i0][i2][(2*i4)] , s_y__tmp_75 , s_y_tmp_67 );
                s_y_tmp3[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_65 , s_y_tmp_66 , s_y_tmp_62 );
                uint32_t _tmp_76 = 1 ;
                share * s_y__tmp_76 = ycirc->PutCONSGate( _tmp_76 ,bitlen);
                s_y_tmp5 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_76 );
            }
            uint32_t _tmp_78 = 1 ;
            share * s_y__tmp_78 = ycirc->PutCONSGate( _tmp_78 ,bitlen);
            share * s_y_tmp_77 = ycirc->PutADDGate( s_y_tmp4 , s_y__tmp_78 );
            vector<uint32_t> _vec79 = s_y_tmp_77->get_wires();
            _vec79.erase( _vec79.begin(), _vec79.begin() + 1 );
            s_y_tmp4 = create_new_share( _vec79 , ycirc );
        }
        s_y_tmp0[i0][i2] = create_new_share(s_y_tmp3[i0][i2][0]->get_wires(), ycirc );
    }
}
share * s_y_tmp7 ;
auto s_y_bb = make_vector<share*>(10);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
s_y_bb[_i1] = ycirc->PutA2YGate( s_a_bb[_i1] );
}
share * s_y_tmp8 ;
auto s_y_tmp6 = make_vector<share*>(1, 10);
for (uint32_t i5 = 0; i5 < 1; i5++)
{
    for (uint32_t i6 = 0; i6 < 10; i6++)
    {
        s_y_tmp7 = create_new_share(s_y_tmp0[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_81 = 2147483648 ;
        share * s_y__tmp_81 = ycirc->PutCONSGate( _tmp_81 ,bitlen);
        share * s_y_tmp_80 = ycirc->PutGTGate( s_y__tmp_81 , s_y_bb[i6] );
        vector<uint32_t> _vec83 = s_y_bb[i6]->get_wires();
        _vec83.erase( _vec83.begin(), _vec83.begin() + 6 );
        share *s_y_tmp_82 = create_new_share( _vec83 , ycirc );
        uint32_t _tmp_87 = 4294967295 ;
        share * s_y__tmp_87 = ycirc->PutCONSGate( _tmp_87 ,bitlen);
        share * s_y_tmp_86 = ycirc->PutXORGate( s_y_bb[i6] , s_y__tmp_87 );
        vector<uint32_t> _vec88 = s_y_tmp_86->get_wires();
        _vec88.erase( _vec88.begin(), _vec88.begin() + 6 );
        share *s_y_tmp_85 = create_new_share( _vec88 , ycirc );
        uint32_t _tmp_89 = 4294967295 ;
        share * s_y__tmp_89 = ycirc->PutCONSGate( _tmp_89 ,bitlen);
        share * s_y_tmp_84 = ycirc->PutXORGate( s_y_tmp_85 , s_y__tmp_89 );
        s_y_tmp8 = ycirc->PutMUXGate( s_y_tmp_82 , s_y_tmp_84 , s_y_tmp_80 );
        s_y_tmp6[i5][i6] = ycirc->PutADDGate( s_y_tmp7 , s_y_tmp8 );
        s_y_tmp6[i5][i6] = create_new_share(s_y_tmp6[i5][i6]->get_wires(), ycirc );
    }
}
tmp9 = 0 ;
share *s_y_tmp9 = ycirc->PutCONSGate( tmp9 ,bitlen);
tmp10 = 0 ;
share *s_y_tmp10 = ycirc->PutCONSGate( tmp10 ,bitlen);
share *s_y_tmp11 = create_new_share(s_y_tmp6[0][0]->get_wires(), ycirc );
share * s_y_tmp12 ;
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 10; i8++)
    {
        uint32_t _tmp_91 = 2147483648 ;
        share * s_y__tmp_91 = ycirc->PutCONSGate( _tmp_91 ,bitlen);
        share * s_y_tmp_90 = ycirc->PutGTGate( s_y__tmp_91 , s_y_tmp11 );
        uint32_t _tmp_94 = 2147483648 ;
        share * s_y__tmp_94 = ycirc->PutCONSGate( _tmp_94 ,bitlen);
        share * s_y_tmp_93 = ycirc->PutGTGate( s_y__tmp_94 , s_y_tmp6[i7][i8] );
        share * s_y_tmp_96 = ycirc->PutGTGate( s_y_tmp11 , s_y_tmp6[i7][i8] );
        share * s_y_tmp_95 = ycirc->PutMUXGate( s_y_tmp11 , s_y_tmp6[i7][i8] , s_y_tmp_96 );
        share * s_y_tmp_92 = ycirc->PutMUXGate( s_y_tmp_95 , s_y_tmp11 , s_y_tmp_93 );
        uint32_t _tmp_99 = 2147483648 ;
        share * s_y__tmp_99 = ycirc->PutCONSGate( _tmp_99 ,bitlen);
        share * s_y_tmp_98 = ycirc->PutGTGate( s_y__tmp_99 , s_y_tmp6[i7][i8] );
        share * s_y_tmp_101 = ycirc->PutGTGate( s_y_tmp11 , s_y_tmp6[i7][i8] );
        share * s_y_tmp_100 = ycirc->PutMUXGate( s_y_tmp11 , s_y_tmp6[i7][i8] , s_y_tmp_101 );
        share * s_y_tmp_97 = ycirc->PutMUXGate( s_y_tmp6[i7][i8] , s_y_tmp_100 , s_y_tmp_98 );
        s_y_tmp12 = ycirc->PutMUXGate( s_y_tmp_92 , s_y_tmp_97 , s_y_tmp_90 );
        share * s_y_tmp_102 = ycirc->PutEQGate( s_y_tmp11 , s_y_tmp12 );
        s_y_tmp10 = ycirc->PutMUXGate( s_y_tmp10 , s_y_tmp9 , s_y_tmp_102 );
        s_y_tmp11 = create_new_share(s_y_tmp12->get_wires(), ycirc );
        uint32_t _tmp_103 = 1 ;
        share * s_y__tmp_103 = ycirc->PutCONSGate( _tmp_103 ,bitlen);
        s_y_tmp9 = ycirc->PutADDGate( s_y_tmp9 , s_y__tmp_103 );
    }
}
share * s_y_tmp_104 = ycirc->PutOUTGate( s_y_tmp10 , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_104->get_clear_value<uint32_t>();
