ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto WW = make_vector<uint32_t>(5, 400);
auto s_a_WW = make_vector<share*>(5, 400);
auto xx = make_vector<uint32_t>(400, 1);
auto s_a_xx = make_vector<share*>(400, 1);
auto BB = make_vector<uint32_t>(10, 5, 1);
auto s_a_BB = make_vector<share*>(10, 5, 1);
auto ZZ = make_vector<uint32_t>(10, 2, 1);
auto s_a_ZZ = make_vector<share*>(10, 2, 1);
uint32_t tmp0;
share *s_a_tmp0;
uint32_t i;
share *s_a_i;
auto tmp1 = make_vector<uint32_t>(5, 1);
auto s_a_tmp1 = make_vector<share*>(5, 1);
auto tmp2 = make_vector<uint32_t>(5, 400);
auto s_a_tmp2 = make_vector<share*>(5, 400);
auto tmp3 = make_vector<uint32_t>(400, 1);
auto s_a_tmp3 = make_vector<share*>(400, 1);
auto tmp4 = make_vector<uint32_t>(5, 1, 400);
auto s_a_tmp4 = make_vector<share*>(5, 1, 400);
uint32_t tmp5;
share *s_a_tmp5;
uint32_t tmp6;
share *s_a_tmp6;
auto tmp7 = make_vector<uint32_t>(5, 1);
auto s_a_tmp7 = make_vector<share*>(5, 1);
uint32_t tmp8;
share *s_a_tmp8;
uint32_t tmp9;
share *s_a_tmp9;
uint32_t tmp10;
share *s_a_tmp10;
auto tmp11 = make_vector<uint32_t>(1, 5);
auto s_a_tmp11 = make_vector<share*>(1, 5);
auto tmp12 = make_vector<uint32_t>(1, 1);
auto s_a_tmp12 = make_vector<share*>(1, 1);
auto tmp13 = make_vector<uint32_t>(1, 5);
auto s_a_tmp13 = make_vector<share*>(1, 5);
auto tmp14 = make_vector<uint32_t>(5, 1);
auto s_a_tmp14 = make_vector<share*>(5, 1);
auto tmp15 = make_vector<uint32_t>(1, 1, 5);
auto s_a_tmp15 = make_vector<share*>(1, 1, 5);
uint32_t tmp16;
share *s_a_tmp16;
uint32_t tmp17;
share *s_a_tmp17;
auto tmp18 = make_vector<uint32_t>(1, 1);
auto s_a_tmp18 = make_vector<share*>(1, 1);
uint32_t tmp19;
share *s_a_tmp19;
auto tmp20 = make_vector<uint32_t>(1, 1);
auto s_a_tmp20 = make_vector<share*>(1, 1);
auto tmp21 = make_vector<uint32_t>(1, 1);
auto s_a_tmp21 = make_vector<share*>(1, 1);
auto tmp24 = make_vector<uint32_t>(2, 1);
auto s_a_tmp24 = make_vector<share*>(2, 1);
auto tmp25 = make_vector<uint32_t>(2, 1);
auto s_a_tmp25 = make_vector<share*>(2, 1);
auto tmp26 = make_vector<uint32_t>(1, 1);
auto s_a_tmp26 = make_vector<share*>(1, 1);
auto tmp27 = make_vector<uint32_t>(2, 1, 1);
auto s_a_tmp27 = make_vector<share*>(2, 1, 1);
uint32_t tmp28;
share *s_a_tmp28;
uint32_t tmp29;
share *s_a_tmp29;
auto tmp30 = make_vector<uint32_t>(2, 1);
auto s_a_tmp30 = make_vector<share*>(2, 1);
auto tmp31 = make_vector<uint32_t>(10, 2, 1);
auto s_a_tmp31 = make_vector<share*>(10, 2, 1);
uint32_t tmp32;
share *s_a_tmp32;
uint32_t tmp33;
share *s_a_tmp33;
uint32_t tmp34;
share *s_a_tmp34;
uint32_t tmp35;
share *s_a_tmp35;
uint32_t tmp36;
share *s_a_tmp36;
uint32_t tmp37;
share *s_a_tmp37;
tmp0 = 670014898 ;
s_a_tmp0 = acirc->PutCONSGate( tmp0 ,bitlen);
auto s_y_WW = make_vector<share*>(5, 400);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_y_WW[_i1][_i4] = ycirc->PutA2YGate( s_a_WW[_i1][_i4] );
}
}
auto s_y_tmp2 = make_vector<share*>(5, 400);
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_1 = 2147483648 ;
        share * s_y__tmp_1 = ycirc->PutCONSGate( _tmp_1 ,bitlen);
        share * s_y_tmp_0 = ycirc->PutGTGate( s_y__tmp_1 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec3 = s_y_WW[i0][i1]->get_wires();
        _vec3.erase( _vec3.begin(), _vec3.begin() + 15 );
        share *s_y_tmp_2 = create_new_share( _vec3 , ycirc );
        uint32_t _tmp_7 = 4294967295 ;
        share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
        share * s_y_tmp_6 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_7 );
        vector<uint32_t> _vec8 = s_y_tmp_6->get_wires();
        _vec8.erase( _vec8.begin(), _vec8.begin() + 15 );
        share *s_y_tmp_5 = create_new_share( _vec8 , ycirc );
        uint32_t _tmp_9 = 4294967295 ;
        share * s_y__tmp_9 = ycirc->PutCONSGate( _tmp_9 ,bitlen);
        share * s_y_tmp_4 = ycirc->PutXORGate( s_y_tmp_5 , s_y__tmp_9 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_2 , s_y_tmp_4 , s_y_tmp_0 );
    }
}
auto s_y_xx = make_vector<share*>(400, 1);
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_xx[_i1][_i4] = ycirc->PutA2YGate( s_a_xx[_i1][_i4] );
}
}
auto s_y_tmp3 = make_vector<share*>(400, 1);
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_11 = 2147483648 ;
        share * s_y__tmp_11 = ycirc->PutCONSGate( _tmp_11 ,bitlen);
        share * s_y_tmp_10 = ycirc->PutGTGate( s_y__tmp_11 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec13 = s_y_xx[i1][i2]->get_wires();
        _vec13.erase( _vec13.begin(), _vec13.begin() + 15 );
        share *s_y_tmp_12 = create_new_share( _vec13 , ycirc );
        uint32_t _tmp_17 = 4294967295 ;
        share * s_y__tmp_17 = ycirc->PutCONSGate( _tmp_17 ,bitlen);
        share * s_y_tmp_16 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_17 );
        vector<uint32_t> _vec18 = s_y_tmp_16->get_wires();
        _vec18.erase( _vec18.begin(), _vec18.begin() + 15 );
        share *s_y_tmp_15 = create_new_share( _vec18 , ycirc );
        uint32_t _tmp_19 = 4294967295 ;
        share * s_y__tmp_19 = ycirc->PutCONSGate( _tmp_19 ,bitlen);
        share * s_y_tmp_14 = ycirc->PutXORGate( s_y_tmp_15 , s_y__tmp_19 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_12 , s_y_tmp_14 , s_y_tmp_10 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
share * s_y_tmp5 ;
share * s_y_tmp6 ;
auto s_y_tmp4 = make_vector<share*>(5, 1, 400);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp1 = make_vector<share*>(5, 1);
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec22 = s_y_tmp5->get_wires();
                _vec22.erase( _vec22.begin(), _vec22.begin() + 1 );
                share *s_y_tmp_21 = create_new_share( _vec22 , ycirc );
                share * s_y_tmp_20 = ycirc->PutGTGate( s_y_tmp_21 , s_y_tmp6 );
                share * s_y_tmp_25 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_26 = 2147483648 ;
                share * s_y__tmp_26 = ycirc->PutCONSGate( _tmp_26 ,bitlen);
                share * s_y_tmp_24 = ycirc->PutGTGate( s_y__tmp_26 , s_y_tmp_25 );
                share * s_y_tmp_28 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec29 = s_y_tmp_28->get_wires();
                _vec29.erase( _vec29.begin(), _vec29.begin() + 1 );
                share *s_y_tmp_27 = create_new_share( _vec29 , ycirc );
                share * s_y_tmp_33 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
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
                vector<uint32_t> _vec41 = s_y_tmp5->get_wires();
                _vec41.erase( _vec41.begin(), _vec41.begin() + 1 );
                share *s_y_tmp_40 = create_new_share( _vec41 , ycirc );
                share * s_y_tmp_39 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_40 );
                uint32_t _tmp_44 = 1 ;
                share * s_y__tmp_44 = ycirc->PutCONSGate( _tmp_44 ,bitlen);
                share * s_y_tmp_43 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_44 );
                uint32_t _tmp_45 = 1 ;
                share * s_y__tmp_45 = ycirc->PutCONSGate( _tmp_45 ,bitlen);
                share * s_y_tmp_42 = ycirc->PutEQGate( s_y_tmp_43 , s_y__tmp_45 );
                share * s_y_tmp_38 = ycirc->PutANDGate( s_y_tmp_39 , s_y_tmp_42 );
                uint32_t _tmp_48 = 2147483648 ;
                share * s_y__tmp_48 = ycirc->PutCONSGate( _tmp_48 ,bitlen);
                share * s_y_tmp_47 = ycirc->PutGTGate( s_y__tmp_48 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec50 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec50.erase( _vec50.begin(), _vec50.begin() + 1 );
                share *s_y_tmp_49 = create_new_share( _vec50 , ycirc );
                uint32_t _tmp_54 = 4294967295 ;
                share * s_y__tmp_54 = ycirc->PutCONSGate( _tmp_54 ,bitlen);
                share * s_y_tmp_53 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_54 );
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
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_23 , s_y_tmp_37 , s_y_tmp_20 );
                uint32_t _tmp_58 = 1 ;
                share * s_y__tmp_58 = ycirc->PutCONSGate( _tmp_58 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_58 );
            }
            uint32_t _tmp_60 = 1 ;
            share * s_y__tmp_60 = ycirc->PutCONSGate( _tmp_60 ,bitlen);
            share * s_y_tmp_59 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_60 );
            vector<uint32_t> _vec61 = s_y_tmp_59->get_wires();
            _vec61.erase( _vec61.begin(), _vec61.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec61 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec64 = s_y_tmp5->get_wires();
                _vec64.erase( _vec64.begin(), _vec64.begin() + 1 );
                share *s_y_tmp_63 = create_new_share( _vec64 , ycirc );
                share * s_y_tmp_62 = ycirc->PutGTGate( s_y_tmp_63 , s_y_tmp6 );
                share * s_y_tmp_65 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec70 = s_y_tmp5->get_wires();
                _vec70.erase( _vec70.begin(), _vec70.begin() + 1 );
                share *s_y_tmp_69 = create_new_share( _vec70 , ycirc );
                share * s_y_tmp_68 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_69 );
                uint32_t _tmp_73 = 1 ;
                share * s_y__tmp_73 = ycirc->PutCONSGate( _tmp_73 ,bitlen);
                share * s_y_tmp_72 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_73 );
                uint32_t _tmp_74 = 1 ;
                share * s_y__tmp_74 = ycirc->PutCONSGate( _tmp_74 ,bitlen);
                share * s_y_tmp_71 = ycirc->PutEQGate( s_y_tmp_72 , s_y__tmp_74 );
                share * s_y_tmp_67 = ycirc->PutANDGate( s_y_tmp_68 , s_y_tmp_71 );
                uint32_t _tmp_75 = 0 ;
                share * s_y__tmp_75 = ycirc->PutCONSGate( _tmp_75 ,bitlen);
                share * s_y_tmp_66 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_75 , s_y_tmp_67 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_65 , s_y_tmp_66 , s_y_tmp_62 );
                uint32_t _tmp_76 = 1 ;
                share * s_y__tmp_76 = ycirc->PutCONSGate( _tmp_76 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_76 );
            }
            uint32_t _tmp_78 = 1 ;
            share * s_y__tmp_78 = ycirc->PutCONSGate( _tmp_78 ,bitlen);
            share * s_y_tmp_77 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_78 );
            vector<uint32_t> _vec79 = s_y_tmp_77->get_wires();
            _vec79.erase( _vec79.begin(), _vec79.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec79 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
share * s_y_tmp8 ;
auto s_y_BB = make_vector<share*>(10, 5, 1);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_BB[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_BB[_i1][_i4][_i7] );
}
}
}
share * s_y_tmp9 ;
auto s_y_tmp7 = make_vector<share*>(5, 1);
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_81 = 2147483648 ;
        share * s_y__tmp_81 = ycirc->PutCONSGate( _tmp_81 ,bitlen);
        share * s_y_tmp_80 = ycirc->PutGTGate( s_y__tmp_81 , s_y_BB[0][i5][i6] );
        vector<uint32_t> _vec83 = s_y_BB[0][i5][i6]->get_wires();
        _vec83.erase( _vec83.begin(), _vec83.begin() + 4 );
        share *s_y_tmp_82 = create_new_share( _vec83 , ycirc );
        uint32_t _tmp_87 = 4294967295 ;
        share * s_y__tmp_87 = ycirc->PutCONSGate( _tmp_87 ,bitlen);
        share * s_y_tmp_86 = ycirc->PutXORGate( s_y_BB[0][i5][i6] , s_y__tmp_87 );
        vector<uint32_t> _vec88 = s_y_tmp_86->get_wires();
        _vec88.erase( _vec88.begin(), _vec88.begin() + 4 );
        share *s_y_tmp_85 = create_new_share( _vec88 , ycirc );
        uint32_t _tmp_89 = 4294967295 ;
        share * s_y__tmp_89 = ycirc->PutCONSGate( _tmp_89 ,bitlen);
        share * s_y_tmp_84 = ycirc->PutXORGate( s_y_tmp_85 , s_y__tmp_89 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_82 , s_y_tmp_84 , s_y_tmp_80 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share *s_y_tmp0 = ycirc->PutA2YGate( s_a_tmp0 );
share * s_y_tmp_90 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_91 = 1 ;
share * s_a__tmp_91 = acirc->PutCONSGate( _tmp_91 ,bitlen);
share *s_a_tmp_90 = acirc->PutY2AGate( s_y_tmp_90 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_90 , s_a__tmp_91 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
auto s_y_tmp11 = make_vector<share*>(1, 5);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
auto s_y_tmp13 = make_vector<share*>(1, 5);
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_93 = 2147483648 ;
        share * s_y__tmp_93 = ycirc->PutCONSGate( _tmp_93 ,bitlen);
        share * s_y_tmp_92 = ycirc->PutGTGate( s_y__tmp_93 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec95 = s_y_tmp11[i9][i10]->get_wires();
        _vec95.erase( _vec95.begin(), _vec95.begin() + 15 );
        share *s_y_tmp_94 = create_new_share( _vec95 , ycirc );
        uint32_t _tmp_99 = 4294967295 ;
        share * s_y__tmp_99 = ycirc->PutCONSGate( _tmp_99 ,bitlen);
        share * s_y_tmp_98 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_99 );
        vector<uint32_t> _vec100 = s_y_tmp_98->get_wires();
        _vec100.erase( _vec100.begin(), _vec100.begin() + 15 );
        share *s_y_tmp_97 = create_new_share( _vec100 , ycirc );
        uint32_t _tmp_101 = 4294967295 ;
        share * s_y__tmp_101 = ycirc->PutCONSGate( _tmp_101 ,bitlen);
        share * s_y_tmp_96 = ycirc->PutXORGate( s_y_tmp_97 , s_y__tmp_101 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_94 , s_y_tmp_96 , s_y_tmp_92 );
    }
}
auto s_y_tmp14 = make_vector<share*>(5, 1);
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_103 = 2147483648 ;
        share * s_y__tmp_103 = ycirc->PutCONSGate( _tmp_103 ,bitlen);
        share * s_y_tmp_102 = ycirc->PutGTGate( s_y__tmp_103 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec105 = s_y_tmp7[i10][i11]->get_wires();
        _vec105.erase( _vec105.begin(), _vec105.begin() + 15 );
        share *s_y_tmp_104 = create_new_share( _vec105 , ycirc );
        uint32_t _tmp_109 = 4294967295 ;
        share * s_y__tmp_109 = ycirc->PutCONSGate( _tmp_109 ,bitlen);
        share * s_y_tmp_108 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_109 );
        vector<uint32_t> _vec110 = s_y_tmp_108->get_wires();
        _vec110.erase( _vec110.begin(), _vec110.begin() + 15 );
        share *s_y_tmp_107 = create_new_share( _vec110 , ycirc );
        uint32_t _tmp_111 = 4294967295 ;
        share * s_y__tmp_111 = ycirc->PutCONSGate( _tmp_111 ,bitlen);
        share * s_y_tmp_106 = ycirc->PutXORGate( s_y_tmp_107 , s_y__tmp_111 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_104 , s_y_tmp_106 , s_y_tmp_102 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
share * s_y_tmp16 ;
share * s_y_tmp17 ;
auto s_y_tmp15 = make_vector<share*>(1, 1, 5);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp12 = make_vector<share*>(1, 1);
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec114 = s_y_tmp16->get_wires();
                _vec114.erase( _vec114.begin(), _vec114.begin() + 1 );
                share *s_y_tmp_113 = create_new_share( _vec114 , ycirc );
                share * s_y_tmp_112 = ycirc->PutGTGate( s_y_tmp_113 , s_y_tmp17 );
                share * s_y_tmp_117 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_118 = 2147483648 ;
                share * s_y__tmp_118 = ycirc->PutCONSGate( _tmp_118 ,bitlen);
                share * s_y_tmp_116 = ycirc->PutGTGate( s_y__tmp_118 , s_y_tmp_117 );
                share * s_y_tmp_120 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec121 = s_y_tmp_120->get_wires();
                _vec121.erase( _vec121.begin(), _vec121.begin() + 1 );
                share *s_y_tmp_119 = create_new_share( _vec121 , ycirc );
                share * s_y_tmp_125 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_126 = 4294967295 ;
                share * s_y__tmp_126 = ycirc->PutCONSGate( _tmp_126 ,bitlen);
                share * s_y_tmp_124 = ycirc->PutXORGate( s_y_tmp_125 , s_y__tmp_126 );
                vector<uint32_t> _vec127 = s_y_tmp_124->get_wires();
                _vec127.erase( _vec127.begin(), _vec127.begin() + 1 );
                share *s_y_tmp_123 = create_new_share( _vec127 , ycirc );
                uint32_t _tmp_128 = 4294967295 ;
                share * s_y__tmp_128 = ycirc->PutCONSGate( _tmp_128 ,bitlen);
                share * s_y_tmp_122 = ycirc->PutXORGate( s_y_tmp_123 , s_y__tmp_128 );
                share * s_y_tmp_115 = ycirc->PutMUXGate( s_y_tmp_119 , s_y_tmp_122 , s_y_tmp_116 );
                vector<uint32_t> _vec133 = s_y_tmp16->get_wires();
                _vec133.erase( _vec133.begin(), _vec133.begin() + 1 );
                share *s_y_tmp_132 = create_new_share( _vec133 , ycirc );
                share * s_y_tmp_131 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_132 );
                uint32_t _tmp_136 = 1 ;
                share * s_y__tmp_136 = ycirc->PutCONSGate( _tmp_136 ,bitlen);
                share * s_y_tmp_135 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_136 );
                uint32_t _tmp_137 = 1 ;
                share * s_y__tmp_137 = ycirc->PutCONSGate( _tmp_137 ,bitlen);
                share * s_y_tmp_134 = ycirc->PutEQGate( s_y_tmp_135 , s_y__tmp_137 );
                share * s_y_tmp_130 = ycirc->PutANDGate( s_y_tmp_131 , s_y_tmp_134 );
                uint32_t _tmp_140 = 2147483648 ;
                share * s_y__tmp_140 = ycirc->PutCONSGate( _tmp_140 ,bitlen);
                share * s_y_tmp_139 = ycirc->PutGTGate( s_y__tmp_140 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec142 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec142.erase( _vec142.begin(), _vec142.begin() + 1 );
                share *s_y_tmp_141 = create_new_share( _vec142 , ycirc );
                uint32_t _tmp_146 = 4294967295 ;
                share * s_y__tmp_146 = ycirc->PutCONSGate( _tmp_146 ,bitlen);
                share * s_y_tmp_145 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_146 );
                vector<uint32_t> _vec147 = s_y_tmp_145->get_wires();
                _vec147.erase( _vec147.begin(), _vec147.begin() + 1 );
                share *s_y_tmp_144 = create_new_share( _vec147 , ycirc );
                uint32_t _tmp_148 = 4294967295 ;
                share * s_y__tmp_148 = ycirc->PutCONSGate( _tmp_148 ,bitlen);
                share * s_y_tmp_143 = ycirc->PutXORGate( s_y_tmp_144 , s_y__tmp_148 );
                share * s_y_tmp_138 = ycirc->PutMUXGate( s_y_tmp_141 , s_y_tmp_143 , s_y_tmp_139 );
                uint32_t _tmp_149 = 0 ;
                share * s_y__tmp_149 = ycirc->PutCONSGate( _tmp_149 ,bitlen);
                share * s_y_tmp_129 = ycirc->PutMUXGate( s_y_tmp_138 , s_y__tmp_149 , s_y_tmp_130 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_115 , s_y_tmp_129 , s_y_tmp_112 );
                uint32_t _tmp_150 = 1 ;
                share * s_y__tmp_150 = ycirc->PutCONSGate( _tmp_150 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_150 );
            }
            uint32_t _tmp_152 = 1 ;
            share * s_y__tmp_152 = ycirc->PutCONSGate( _tmp_152 ,bitlen);
            share * s_y_tmp_151 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_152 );
            vector<uint32_t> _vec153 = s_y_tmp_151->get_wires();
            _vec153.erase( _vec153.begin(), _vec153.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec153 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec156 = s_y_tmp16->get_wires();
                _vec156.erase( _vec156.begin(), _vec156.begin() + 1 );
                share *s_y_tmp_155 = create_new_share( _vec156 , ycirc );
                share * s_y_tmp_154 = ycirc->PutGTGate( s_y_tmp_155 , s_y_tmp17 );
                share * s_y_tmp_157 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec162 = s_y_tmp16->get_wires();
                _vec162.erase( _vec162.begin(), _vec162.begin() + 1 );
                share *s_y_tmp_161 = create_new_share( _vec162 , ycirc );
                share * s_y_tmp_160 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_161 );
                uint32_t _tmp_165 = 1 ;
                share * s_y__tmp_165 = ycirc->PutCONSGate( _tmp_165 ,bitlen);
                share * s_y_tmp_164 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_165 );
                uint32_t _tmp_166 = 1 ;
                share * s_y__tmp_166 = ycirc->PutCONSGate( _tmp_166 ,bitlen);
                share * s_y_tmp_163 = ycirc->PutEQGate( s_y_tmp_164 , s_y__tmp_166 );
                share * s_y_tmp_159 = ycirc->PutANDGate( s_y_tmp_160 , s_y_tmp_163 );
                uint32_t _tmp_167 = 0 ;
                share * s_y__tmp_167 = ycirc->PutCONSGate( _tmp_167 ,bitlen);
                share * s_y_tmp_158 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_167 , s_y_tmp_159 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_157 , s_y_tmp_158 , s_y_tmp_154 );
                uint32_t _tmp_168 = 1 ;
                share * s_y__tmp_168 = ycirc->PutCONSGate( _tmp_168 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_168 );
            }
            uint32_t _tmp_170 = 1 ;
            share * s_y__tmp_170 = ycirc->PutCONSGate( _tmp_170 ,bitlen);
            share * s_y_tmp_169 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_170 );
            vector<uint32_t> _vec171 = s_y_tmp_169->get_wires();
            _vec171.erase( _vec171.begin(), _vec171.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec171 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
share *s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_173 = 2147483648 ;
share * s_y__tmp_173 = ycirc->PutCONSGate( _tmp_173 ,bitlen);
share * s_y_tmp_172 = ycirc->PutGTGate( s_y__tmp_173 , s_y_tmp10 );
vector<uint32_t> _vec175 = s_y_tmp10->get_wires();
_vec175.erase( _vec175.begin(), _vec175.begin() + 15 );
share *s_y_tmp_174 = create_new_share( _vec175 , ycirc );
uint32_t _tmp_179 = 4294967295 ;
share * s_y__tmp_179 = ycirc->PutCONSGate( _tmp_179 ,bitlen);
share * s_y_tmp_178 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_179 );
vector<uint32_t> _vec180 = s_y_tmp_178->get_wires();
_vec180.erase( _vec180.begin(), _vec180.begin() + 15 );
share *s_y_tmp_177 = create_new_share( _vec180 , ycirc );
uint32_t _tmp_181 = 4294967295 ;
share * s_y__tmp_181 = ycirc->PutCONSGate( _tmp_181 ,bitlen);
share * s_y_tmp_176 = ycirc->PutXORGate( s_y_tmp_177 , s_y__tmp_181 );
share * s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_174 , s_y_tmp_176 , s_y_tmp_172 );
auto s_y_tmp20 = make_vector<share*>(1, 1);
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_183 = 2147483648 ;
        share * s_y__tmp_183 = ycirc->PutCONSGate( _tmp_183 ,bitlen);
        share * s_y_tmp_182 = ycirc->PutGTGate( s_y__tmp_183 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec185 = s_y_tmp12[i14][i15]->get_wires();
        _vec185.erase( _vec185.begin(), _vec185.begin() + 15 );
        share *s_y_tmp_184 = create_new_share( _vec185 , ycirc );
        uint32_t _tmp_189 = 4294967295 ;
        share * s_y__tmp_189 = ycirc->PutCONSGate( _tmp_189 ,bitlen);
        share * s_y_tmp_188 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_189 );
        vector<uint32_t> _vec190 = s_y_tmp_188->get_wires();
        _vec190.erase( _vec190.begin(), _vec190.begin() + 15 );
        share *s_y_tmp_187 = create_new_share( _vec190 , ycirc );
        uint32_t _tmp_191 = 4294967295 ;
        share * s_y__tmp_191 = ycirc->PutCONSGate( _tmp_191 ,bitlen);
        share * s_y_tmp_186 = ycirc->PutXORGate( s_y_tmp_187 , s_y__tmp_191 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_184 , s_y_tmp_186 , s_y_tmp_182 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
auto s_y_ZZ = make_vector<share*>(10, 2, 1);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
for (int _i4 = 0; _i4 < 2 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_ZZ[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_ZZ[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp25 = make_vector<share*>(2, 1);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_193 = 2147483648 ;
        share * s_y__tmp_193 = ycirc->PutCONSGate( _tmp_193 ,bitlen);
        share * s_y_tmp_192 = ycirc->PutGTGate( s_y__tmp_193 , s_y_ZZ[0][i16][i17] );
        vector<uint32_t> _vec195 = s_y_ZZ[0][i16][i17]->get_wires();
        _vec195.erase( _vec195.begin(), _vec195.begin() + 15 );
        share *s_y_tmp_194 = create_new_share( _vec195 , ycirc );
        uint32_t _tmp_199 = 4294967295 ;
        share * s_y__tmp_199 = ycirc->PutCONSGate( _tmp_199 ,bitlen);
        share * s_y_tmp_198 = ycirc->PutXORGate( s_y_ZZ[0][i16][i17] , s_y__tmp_199 );
        vector<uint32_t> _vec200 = s_y_tmp_198->get_wires();
        _vec200.erase( _vec200.begin(), _vec200.begin() + 15 );
        share *s_y_tmp_197 = create_new_share( _vec200 , ycirc );
        uint32_t _tmp_201 = 4294967295 ;
        share * s_y__tmp_201 = ycirc->PutCONSGate( _tmp_201 ,bitlen);
        share * s_y_tmp_196 = ycirc->PutXORGate( s_y_tmp_197 , s_y__tmp_201 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_194 , s_y_tmp_196 , s_y_tmp_192 );
    }
}
auto s_y_tmp21 = make_vector<share*>(1, 1);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
auto s_y_tmp26 = make_vector<share*>(1, 1);
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_203 = 2147483648 ;
        share * s_y__tmp_203 = ycirc->PutCONSGate( _tmp_203 ,bitlen);
        share * s_y_tmp_202 = ycirc->PutGTGate( s_y__tmp_203 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec205 = s_y_tmp21[i17][i18]->get_wires();
        _vec205.erase( _vec205.begin(), _vec205.begin() + 15 );
        share *s_y_tmp_204 = create_new_share( _vec205 , ycirc );
        uint32_t _tmp_209 = 4294967295 ;
        share * s_y__tmp_209 = ycirc->PutCONSGate( _tmp_209 ,bitlen);
        share * s_y_tmp_208 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_209 );
        vector<uint32_t> _vec210 = s_y_tmp_208->get_wires();
        _vec210.erase( _vec210.begin(), _vec210.begin() + 15 );
        share *s_y_tmp_207 = create_new_share( _vec210 , ycirc );
        uint32_t _tmp_211 = 4294967295 ;
        share * s_y__tmp_211 = ycirc->PutCONSGate( _tmp_211 ,bitlen);
        share * s_y_tmp_206 = ycirc->PutXORGate( s_y_tmp_207 , s_y__tmp_211 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_204 , s_y_tmp_206 , s_y_tmp_202 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
share * s_y_tmp28 ;
share * s_y_tmp29 ;
auto s_y_tmp27 = make_vector<share*>(2, 1, 1);
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
auto s_y_tmp31 = make_vector<share*>(10, 2, 1);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec214 = s_y_tmp28->get_wires();
                _vec214.erase( _vec214.begin(), _vec214.begin() + 1 );
                share *s_y_tmp_213 = create_new_share( _vec214 , ycirc );
                share * s_y_tmp_212 = ycirc->PutGTGate( s_y_tmp_213 , s_y_tmp29 );
                share * s_y_tmp_217 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_218 = 2147483648 ;
                share * s_y__tmp_218 = ycirc->PutCONSGate( _tmp_218 ,bitlen);
                share * s_y_tmp_216 = ycirc->PutGTGate( s_y__tmp_218 , s_y_tmp_217 );
                share * s_y_tmp_220 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec221 = s_y_tmp_220->get_wires();
                _vec221.erase( _vec221.begin(), _vec221.begin() + 1 );
                share *s_y_tmp_219 = create_new_share( _vec221 , ycirc );
                share * s_y_tmp_225 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_226 = 4294967295 ;
                share * s_y__tmp_226 = ycirc->PutCONSGate( _tmp_226 ,bitlen);
                share * s_y_tmp_224 = ycirc->PutXORGate( s_y_tmp_225 , s_y__tmp_226 );
                vector<uint32_t> _vec227 = s_y_tmp_224->get_wires();
                _vec227.erase( _vec227.begin(), _vec227.begin() + 1 );
                share *s_y_tmp_223 = create_new_share( _vec227 , ycirc );
                uint32_t _tmp_228 = 4294967295 ;
                share * s_y__tmp_228 = ycirc->PutCONSGate( _tmp_228 ,bitlen);
                share * s_y_tmp_222 = ycirc->PutXORGate( s_y_tmp_223 , s_y__tmp_228 );
                share * s_y_tmp_215 = ycirc->PutMUXGate( s_y_tmp_219 , s_y_tmp_222 , s_y_tmp_216 );
                vector<uint32_t> _vec233 = s_y_tmp28->get_wires();
                _vec233.erase( _vec233.begin(), _vec233.begin() + 1 );
                share *s_y_tmp_232 = create_new_share( _vec233 , ycirc );
                share * s_y_tmp_231 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_232 );
                uint32_t _tmp_236 = 1 ;
                share * s_y__tmp_236 = ycirc->PutCONSGate( _tmp_236 ,bitlen);
                share * s_y_tmp_235 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_236 );
                uint32_t _tmp_237 = 1 ;
                share * s_y__tmp_237 = ycirc->PutCONSGate( _tmp_237 ,bitlen);
                share * s_y_tmp_234 = ycirc->PutEQGate( s_y_tmp_235 , s_y__tmp_237 );
                share * s_y_tmp_230 = ycirc->PutANDGate( s_y_tmp_231 , s_y_tmp_234 );
                uint32_t _tmp_240 = 2147483648 ;
                share * s_y__tmp_240 = ycirc->PutCONSGate( _tmp_240 ,bitlen);
                share * s_y_tmp_239 = ycirc->PutGTGate( s_y__tmp_240 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec242 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec242.erase( _vec242.begin(), _vec242.begin() + 1 );
                share *s_y_tmp_241 = create_new_share( _vec242 , ycirc );
                uint32_t _tmp_246 = 4294967295 ;
                share * s_y__tmp_246 = ycirc->PutCONSGate( _tmp_246 ,bitlen);
                share * s_y_tmp_245 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_246 );
                vector<uint32_t> _vec247 = s_y_tmp_245->get_wires();
                _vec247.erase( _vec247.begin(), _vec247.begin() + 1 );
                share *s_y_tmp_244 = create_new_share( _vec247 , ycirc );
                uint32_t _tmp_248 = 4294967295 ;
                share * s_y__tmp_248 = ycirc->PutCONSGate( _tmp_248 ,bitlen);
                share * s_y_tmp_243 = ycirc->PutXORGate( s_y_tmp_244 , s_y__tmp_248 );
                share * s_y_tmp_238 = ycirc->PutMUXGate( s_y_tmp_241 , s_y_tmp_243 , s_y_tmp_239 );
                uint32_t _tmp_249 = 0 ;
                share * s_y__tmp_249 = ycirc->PutCONSGate( _tmp_249 ,bitlen);
                share * s_y_tmp_229 = ycirc->PutMUXGate( s_y_tmp_238 , s_y__tmp_249 , s_y_tmp_230 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_215 , s_y_tmp_229 , s_y_tmp_212 );
                uint32_t _tmp_250 = 1 ;
                share * s_y__tmp_250 = ycirc->PutCONSGate( _tmp_250 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_250 );
            }
            uint32_t _tmp_252 = 1 ;
            share * s_y__tmp_252 = ycirc->PutCONSGate( _tmp_252 ,bitlen);
            share * s_y_tmp_251 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_252 );
            vector<uint32_t> _vec253 = s_y_tmp_251->get_wires();
            _vec253.erase( _vec253.begin(), _vec253.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec253 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec256 = s_y_tmp28->get_wires();
                _vec256.erase( _vec256.begin(), _vec256.begin() + 1 );
                share *s_y_tmp_255 = create_new_share( _vec256 , ycirc );
                share * s_y_tmp_254 = ycirc->PutGTGate( s_y_tmp_255 , s_y_tmp29 );
                share * s_y_tmp_257 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec262 = s_y_tmp28->get_wires();
                _vec262.erase( _vec262.begin(), _vec262.begin() + 1 );
                share *s_y_tmp_261 = create_new_share( _vec262 , ycirc );
                share * s_y_tmp_260 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_261 );
                uint32_t _tmp_265 = 1 ;
                share * s_y__tmp_265 = ycirc->PutCONSGate( _tmp_265 ,bitlen);
                share * s_y_tmp_264 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_265 );
                uint32_t _tmp_266 = 1 ;
                share * s_y__tmp_266 = ycirc->PutCONSGate( _tmp_266 ,bitlen);
                share * s_y_tmp_263 = ycirc->PutEQGate( s_y_tmp_264 , s_y__tmp_266 );
                share * s_y_tmp_259 = ycirc->PutANDGate( s_y_tmp_260 , s_y_tmp_263 );
                uint32_t _tmp_267 = 0 ;
                share * s_y__tmp_267 = ycirc->PutCONSGate( _tmp_267 ,bitlen);
                share * s_y_tmp_258 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_267 , s_y_tmp_259 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_257 , s_y_tmp_258 , s_y_tmp_254 );
                uint32_t _tmp_268 = 1 ;
                share * s_y__tmp_268 = ycirc->PutCONSGate( _tmp_268 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_268 );
            }
            uint32_t _tmp_270 = 1 ;
            share * s_y__tmp_270 = ycirc->PutCONSGate( _tmp_270 ,bitlen);
            share * s_y_tmp_269 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_270 );
            vector<uint32_t> _vec271 = s_y_tmp_269->get_wires();
            _vec271.erase( _vec271.begin(), _vec271.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec271 , ycirc );
        }
        s_y_tmp31[0][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_273 = 2147483648 ;
        share * s_y__tmp_273 = ycirc->PutCONSGate( _tmp_273 ,bitlen);
        share * s_y_tmp_272 = ycirc->PutGTGate( s_y__tmp_273 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec275 = s_y_WW[i0][i1]->get_wires();
        _vec275.erase( _vec275.begin(), _vec275.begin() + 15 );
        share *s_y_tmp_274 = create_new_share( _vec275 , ycirc );
        uint32_t _tmp_279 = 4294967295 ;
        share * s_y__tmp_279 = ycirc->PutCONSGate( _tmp_279 ,bitlen);
        share * s_y_tmp_278 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_279 );
        vector<uint32_t> _vec280 = s_y_tmp_278->get_wires();
        _vec280.erase( _vec280.begin(), _vec280.begin() + 15 );
        share *s_y_tmp_277 = create_new_share( _vec280 , ycirc );
        uint32_t _tmp_281 = 4294967295 ;
        share * s_y__tmp_281 = ycirc->PutCONSGate( _tmp_281 ,bitlen);
        share * s_y_tmp_276 = ycirc->PutXORGate( s_y_tmp_277 , s_y__tmp_281 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_274 , s_y_tmp_276 , s_y_tmp_272 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_283 = 2147483648 ;
        share * s_y__tmp_283 = ycirc->PutCONSGate( _tmp_283 ,bitlen);
        share * s_y_tmp_282 = ycirc->PutGTGate( s_y__tmp_283 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec285 = s_y_xx[i1][i2]->get_wires();
        _vec285.erase( _vec285.begin(), _vec285.begin() + 15 );
        share *s_y_tmp_284 = create_new_share( _vec285 , ycirc );
        uint32_t _tmp_289 = 4294967295 ;
        share * s_y__tmp_289 = ycirc->PutCONSGate( _tmp_289 ,bitlen);
        share * s_y_tmp_288 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_289 );
        vector<uint32_t> _vec290 = s_y_tmp_288->get_wires();
        _vec290.erase( _vec290.begin(), _vec290.begin() + 15 );
        share *s_y_tmp_287 = create_new_share( _vec290 , ycirc );
        uint32_t _tmp_291 = 4294967295 ;
        share * s_y__tmp_291 = ycirc->PutCONSGate( _tmp_291 ,bitlen);
        share * s_y_tmp_286 = ycirc->PutXORGate( s_y_tmp_287 , s_y__tmp_291 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_284 , s_y_tmp_286 , s_y_tmp_282 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec294 = s_y_tmp5->get_wires();
                _vec294.erase( _vec294.begin(), _vec294.begin() + 1 );
                share *s_y_tmp_293 = create_new_share( _vec294 , ycirc );
                share * s_y_tmp_292 = ycirc->PutGTGate( s_y_tmp_293 , s_y_tmp6 );
                share * s_y_tmp_297 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_298 = 2147483648 ;
                share * s_y__tmp_298 = ycirc->PutCONSGate( _tmp_298 ,bitlen);
                share * s_y_tmp_296 = ycirc->PutGTGate( s_y__tmp_298 , s_y_tmp_297 );
                share * s_y_tmp_300 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec301 = s_y_tmp_300->get_wires();
                _vec301.erase( _vec301.begin(), _vec301.begin() + 1 );
                share *s_y_tmp_299 = create_new_share( _vec301 , ycirc );
                share * s_y_tmp_305 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_306 = 4294967295 ;
                share * s_y__tmp_306 = ycirc->PutCONSGate( _tmp_306 ,bitlen);
                share * s_y_tmp_304 = ycirc->PutXORGate( s_y_tmp_305 , s_y__tmp_306 );
                vector<uint32_t> _vec307 = s_y_tmp_304->get_wires();
                _vec307.erase( _vec307.begin(), _vec307.begin() + 1 );
                share *s_y_tmp_303 = create_new_share( _vec307 , ycirc );
                uint32_t _tmp_308 = 4294967295 ;
                share * s_y__tmp_308 = ycirc->PutCONSGate( _tmp_308 ,bitlen);
                share * s_y_tmp_302 = ycirc->PutXORGate( s_y_tmp_303 , s_y__tmp_308 );
                share * s_y_tmp_295 = ycirc->PutMUXGate( s_y_tmp_299 , s_y_tmp_302 , s_y_tmp_296 );
                vector<uint32_t> _vec313 = s_y_tmp5->get_wires();
                _vec313.erase( _vec313.begin(), _vec313.begin() + 1 );
                share *s_y_tmp_312 = create_new_share( _vec313 , ycirc );
                share * s_y_tmp_311 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_312 );
                uint32_t _tmp_316 = 1 ;
                share * s_y__tmp_316 = ycirc->PutCONSGate( _tmp_316 ,bitlen);
                share * s_y_tmp_315 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_316 );
                uint32_t _tmp_317 = 1 ;
                share * s_y__tmp_317 = ycirc->PutCONSGate( _tmp_317 ,bitlen);
                share * s_y_tmp_314 = ycirc->PutEQGate( s_y_tmp_315 , s_y__tmp_317 );
                share * s_y_tmp_310 = ycirc->PutANDGate( s_y_tmp_311 , s_y_tmp_314 );
                uint32_t _tmp_320 = 2147483648 ;
                share * s_y__tmp_320 = ycirc->PutCONSGate( _tmp_320 ,bitlen);
                share * s_y_tmp_319 = ycirc->PutGTGate( s_y__tmp_320 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec322 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec322.erase( _vec322.begin(), _vec322.begin() + 1 );
                share *s_y_tmp_321 = create_new_share( _vec322 , ycirc );
                uint32_t _tmp_326 = 4294967295 ;
                share * s_y__tmp_326 = ycirc->PutCONSGate( _tmp_326 ,bitlen);
                share * s_y_tmp_325 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_326 );
                vector<uint32_t> _vec327 = s_y_tmp_325->get_wires();
                _vec327.erase( _vec327.begin(), _vec327.begin() + 1 );
                share *s_y_tmp_324 = create_new_share( _vec327 , ycirc );
                uint32_t _tmp_328 = 4294967295 ;
                share * s_y__tmp_328 = ycirc->PutCONSGate( _tmp_328 ,bitlen);
                share * s_y_tmp_323 = ycirc->PutXORGate( s_y_tmp_324 , s_y__tmp_328 );
                share * s_y_tmp_318 = ycirc->PutMUXGate( s_y_tmp_321 , s_y_tmp_323 , s_y_tmp_319 );
                uint32_t _tmp_329 = 0 ;
                share * s_y__tmp_329 = ycirc->PutCONSGate( _tmp_329 ,bitlen);
                share * s_y_tmp_309 = ycirc->PutMUXGate( s_y_tmp_318 , s_y__tmp_329 , s_y_tmp_310 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_295 , s_y_tmp_309 , s_y_tmp_292 );
                uint32_t _tmp_330 = 1 ;
                share * s_y__tmp_330 = ycirc->PutCONSGate( _tmp_330 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_330 );
            }
            uint32_t _tmp_332 = 1 ;
            share * s_y__tmp_332 = ycirc->PutCONSGate( _tmp_332 ,bitlen);
            share * s_y_tmp_331 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_332 );
            vector<uint32_t> _vec333 = s_y_tmp_331->get_wires();
            _vec333.erase( _vec333.begin(), _vec333.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec333 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec336 = s_y_tmp5->get_wires();
                _vec336.erase( _vec336.begin(), _vec336.begin() + 1 );
                share *s_y_tmp_335 = create_new_share( _vec336 , ycirc );
                share * s_y_tmp_334 = ycirc->PutGTGate( s_y_tmp_335 , s_y_tmp6 );
                share * s_y_tmp_337 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec342 = s_y_tmp5->get_wires();
                _vec342.erase( _vec342.begin(), _vec342.begin() + 1 );
                share *s_y_tmp_341 = create_new_share( _vec342 , ycirc );
                share * s_y_tmp_340 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_341 );
                uint32_t _tmp_345 = 1 ;
                share * s_y__tmp_345 = ycirc->PutCONSGate( _tmp_345 ,bitlen);
                share * s_y_tmp_344 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_345 );
                uint32_t _tmp_346 = 1 ;
                share * s_y__tmp_346 = ycirc->PutCONSGate( _tmp_346 ,bitlen);
                share * s_y_tmp_343 = ycirc->PutEQGate( s_y_tmp_344 , s_y__tmp_346 );
                share * s_y_tmp_339 = ycirc->PutANDGate( s_y_tmp_340 , s_y_tmp_343 );
                uint32_t _tmp_347 = 0 ;
                share * s_y__tmp_347 = ycirc->PutCONSGate( _tmp_347 ,bitlen);
                share * s_y_tmp_338 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_347 , s_y_tmp_339 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_337 , s_y_tmp_338 , s_y_tmp_334 );
                uint32_t _tmp_348 = 1 ;
                share * s_y__tmp_348 = ycirc->PutCONSGate( _tmp_348 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_348 );
            }
            uint32_t _tmp_350 = 1 ;
            share * s_y__tmp_350 = ycirc->PutCONSGate( _tmp_350 ,bitlen);
            share * s_y_tmp_349 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_350 );
            vector<uint32_t> _vec351 = s_y_tmp_349->get_wires();
            _vec351.erase( _vec351.begin(), _vec351.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec351 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_353 = 2147483648 ;
        share * s_y__tmp_353 = ycirc->PutCONSGate( _tmp_353 ,bitlen);
        share * s_y_tmp_352 = ycirc->PutGTGate( s_y__tmp_353 , s_y_BB[1][i5][i6] );
        vector<uint32_t> _vec355 = s_y_BB[1][i5][i6]->get_wires();
        _vec355.erase( _vec355.begin(), _vec355.begin() + 4 );
        share *s_y_tmp_354 = create_new_share( _vec355 , ycirc );
        uint32_t _tmp_359 = 4294967295 ;
        share * s_y__tmp_359 = ycirc->PutCONSGate( _tmp_359 ,bitlen);
        share * s_y_tmp_358 = ycirc->PutXORGate( s_y_BB[1][i5][i6] , s_y__tmp_359 );
        vector<uint32_t> _vec360 = s_y_tmp_358->get_wires();
        _vec360.erase( _vec360.begin(), _vec360.begin() + 4 );
        share *s_y_tmp_357 = create_new_share( _vec360 , ycirc );
        uint32_t _tmp_361 = 4294967295 ;
        share * s_y__tmp_361 = ycirc->PutCONSGate( _tmp_361 ,bitlen);
        share * s_y_tmp_356 = ycirc->PutXORGate( s_y_tmp_357 , s_y__tmp_361 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_354 , s_y_tmp_356 , s_y_tmp_352 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_362 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_363 = 1 ;
share * s_a__tmp_363 = acirc->PutCONSGate( _tmp_363 ,bitlen);
share *s_a_tmp_362 = acirc->PutY2AGate( s_y_tmp_362 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_362 , s_a__tmp_363 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_365 = 2147483648 ;
        share * s_y__tmp_365 = ycirc->PutCONSGate( _tmp_365 ,bitlen);
        share * s_y_tmp_364 = ycirc->PutGTGate( s_y__tmp_365 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec367 = s_y_tmp11[i9][i10]->get_wires();
        _vec367.erase( _vec367.begin(), _vec367.begin() + 15 );
        share *s_y_tmp_366 = create_new_share( _vec367 , ycirc );
        uint32_t _tmp_371 = 4294967295 ;
        share * s_y__tmp_371 = ycirc->PutCONSGate( _tmp_371 ,bitlen);
        share * s_y_tmp_370 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_371 );
        vector<uint32_t> _vec372 = s_y_tmp_370->get_wires();
        _vec372.erase( _vec372.begin(), _vec372.begin() + 15 );
        share *s_y_tmp_369 = create_new_share( _vec372 , ycirc );
        uint32_t _tmp_373 = 4294967295 ;
        share * s_y__tmp_373 = ycirc->PutCONSGate( _tmp_373 ,bitlen);
        share * s_y_tmp_368 = ycirc->PutXORGate( s_y_tmp_369 , s_y__tmp_373 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_366 , s_y_tmp_368 , s_y_tmp_364 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_375 = 2147483648 ;
        share * s_y__tmp_375 = ycirc->PutCONSGate( _tmp_375 ,bitlen);
        share * s_y_tmp_374 = ycirc->PutGTGate( s_y__tmp_375 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec377 = s_y_tmp7[i10][i11]->get_wires();
        _vec377.erase( _vec377.begin(), _vec377.begin() + 15 );
        share *s_y_tmp_376 = create_new_share( _vec377 , ycirc );
        uint32_t _tmp_381 = 4294967295 ;
        share * s_y__tmp_381 = ycirc->PutCONSGate( _tmp_381 ,bitlen);
        share * s_y_tmp_380 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_381 );
        vector<uint32_t> _vec382 = s_y_tmp_380->get_wires();
        _vec382.erase( _vec382.begin(), _vec382.begin() + 15 );
        share *s_y_tmp_379 = create_new_share( _vec382 , ycirc );
        uint32_t _tmp_383 = 4294967295 ;
        share * s_y__tmp_383 = ycirc->PutCONSGate( _tmp_383 ,bitlen);
        share * s_y_tmp_378 = ycirc->PutXORGate( s_y_tmp_379 , s_y__tmp_383 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_376 , s_y_tmp_378 , s_y_tmp_374 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec386 = s_y_tmp16->get_wires();
                _vec386.erase( _vec386.begin(), _vec386.begin() + 1 );
                share *s_y_tmp_385 = create_new_share( _vec386 , ycirc );
                share * s_y_tmp_384 = ycirc->PutGTGate( s_y_tmp_385 , s_y_tmp17 );
                share * s_y_tmp_389 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_390 = 2147483648 ;
                share * s_y__tmp_390 = ycirc->PutCONSGate( _tmp_390 ,bitlen);
                share * s_y_tmp_388 = ycirc->PutGTGate( s_y__tmp_390 , s_y_tmp_389 );
                share * s_y_tmp_392 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec393 = s_y_tmp_392->get_wires();
                _vec393.erase( _vec393.begin(), _vec393.begin() + 1 );
                share *s_y_tmp_391 = create_new_share( _vec393 , ycirc );
                share * s_y_tmp_397 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_398 = 4294967295 ;
                share * s_y__tmp_398 = ycirc->PutCONSGate( _tmp_398 ,bitlen);
                share * s_y_tmp_396 = ycirc->PutXORGate( s_y_tmp_397 , s_y__tmp_398 );
                vector<uint32_t> _vec399 = s_y_tmp_396->get_wires();
                _vec399.erase( _vec399.begin(), _vec399.begin() + 1 );
                share *s_y_tmp_395 = create_new_share( _vec399 , ycirc );
                uint32_t _tmp_400 = 4294967295 ;
                share * s_y__tmp_400 = ycirc->PutCONSGate( _tmp_400 ,bitlen);
                share * s_y_tmp_394 = ycirc->PutXORGate( s_y_tmp_395 , s_y__tmp_400 );
                share * s_y_tmp_387 = ycirc->PutMUXGate( s_y_tmp_391 , s_y_tmp_394 , s_y_tmp_388 );
                vector<uint32_t> _vec405 = s_y_tmp16->get_wires();
                _vec405.erase( _vec405.begin(), _vec405.begin() + 1 );
                share *s_y_tmp_404 = create_new_share( _vec405 , ycirc );
                share * s_y_tmp_403 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_404 );
                uint32_t _tmp_408 = 1 ;
                share * s_y__tmp_408 = ycirc->PutCONSGate( _tmp_408 ,bitlen);
                share * s_y_tmp_407 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_408 );
                uint32_t _tmp_409 = 1 ;
                share * s_y__tmp_409 = ycirc->PutCONSGate( _tmp_409 ,bitlen);
                share * s_y_tmp_406 = ycirc->PutEQGate( s_y_tmp_407 , s_y__tmp_409 );
                share * s_y_tmp_402 = ycirc->PutANDGate( s_y_tmp_403 , s_y_tmp_406 );
                uint32_t _tmp_412 = 2147483648 ;
                share * s_y__tmp_412 = ycirc->PutCONSGate( _tmp_412 ,bitlen);
                share * s_y_tmp_411 = ycirc->PutGTGate( s_y__tmp_412 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec414 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec414.erase( _vec414.begin(), _vec414.begin() + 1 );
                share *s_y_tmp_413 = create_new_share( _vec414 , ycirc );
                uint32_t _tmp_418 = 4294967295 ;
                share * s_y__tmp_418 = ycirc->PutCONSGate( _tmp_418 ,bitlen);
                share * s_y_tmp_417 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_418 );
                vector<uint32_t> _vec419 = s_y_tmp_417->get_wires();
                _vec419.erase( _vec419.begin(), _vec419.begin() + 1 );
                share *s_y_tmp_416 = create_new_share( _vec419 , ycirc );
                uint32_t _tmp_420 = 4294967295 ;
                share * s_y__tmp_420 = ycirc->PutCONSGate( _tmp_420 ,bitlen);
                share * s_y_tmp_415 = ycirc->PutXORGate( s_y_tmp_416 , s_y__tmp_420 );
                share * s_y_tmp_410 = ycirc->PutMUXGate( s_y_tmp_413 , s_y_tmp_415 , s_y_tmp_411 );
                uint32_t _tmp_421 = 0 ;
                share * s_y__tmp_421 = ycirc->PutCONSGate( _tmp_421 ,bitlen);
                share * s_y_tmp_401 = ycirc->PutMUXGate( s_y_tmp_410 , s_y__tmp_421 , s_y_tmp_402 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_387 , s_y_tmp_401 , s_y_tmp_384 );
                uint32_t _tmp_422 = 1 ;
                share * s_y__tmp_422 = ycirc->PutCONSGate( _tmp_422 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_422 );
            }
            uint32_t _tmp_424 = 1 ;
            share * s_y__tmp_424 = ycirc->PutCONSGate( _tmp_424 ,bitlen);
            share * s_y_tmp_423 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_424 );
            vector<uint32_t> _vec425 = s_y_tmp_423->get_wires();
            _vec425.erase( _vec425.begin(), _vec425.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec425 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec428 = s_y_tmp16->get_wires();
                _vec428.erase( _vec428.begin(), _vec428.begin() + 1 );
                share *s_y_tmp_427 = create_new_share( _vec428 , ycirc );
                share * s_y_tmp_426 = ycirc->PutGTGate( s_y_tmp_427 , s_y_tmp17 );
                share * s_y_tmp_429 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec434 = s_y_tmp16->get_wires();
                _vec434.erase( _vec434.begin(), _vec434.begin() + 1 );
                share *s_y_tmp_433 = create_new_share( _vec434 , ycirc );
                share * s_y_tmp_432 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_433 );
                uint32_t _tmp_437 = 1 ;
                share * s_y__tmp_437 = ycirc->PutCONSGate( _tmp_437 ,bitlen);
                share * s_y_tmp_436 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_437 );
                uint32_t _tmp_438 = 1 ;
                share * s_y__tmp_438 = ycirc->PutCONSGate( _tmp_438 ,bitlen);
                share * s_y_tmp_435 = ycirc->PutEQGate( s_y_tmp_436 , s_y__tmp_438 );
                share * s_y_tmp_431 = ycirc->PutANDGate( s_y_tmp_432 , s_y_tmp_435 );
                uint32_t _tmp_439 = 0 ;
                share * s_y__tmp_439 = ycirc->PutCONSGate( _tmp_439 ,bitlen);
                share * s_y_tmp_430 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_439 , s_y_tmp_431 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_429 , s_y_tmp_430 , s_y_tmp_426 );
                uint32_t _tmp_440 = 1 ;
                share * s_y__tmp_440 = ycirc->PutCONSGate( _tmp_440 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_440 );
            }
            uint32_t _tmp_442 = 1 ;
            share * s_y__tmp_442 = ycirc->PutCONSGate( _tmp_442 ,bitlen);
            share * s_y_tmp_441 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_442 );
            vector<uint32_t> _vec443 = s_y_tmp_441->get_wires();
            _vec443.erase( _vec443.begin(), _vec443.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec443 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_445 = 2147483648 ;
share * s_y__tmp_445 = ycirc->PutCONSGate( _tmp_445 ,bitlen);
share * s_y_tmp_444 = ycirc->PutGTGate( s_y__tmp_445 , s_y_tmp10 );
vector<uint32_t> _vec447 = s_y_tmp10->get_wires();
_vec447.erase( _vec447.begin(), _vec447.begin() + 15 );
share *s_y_tmp_446 = create_new_share( _vec447 , ycirc );
uint32_t _tmp_451 = 4294967295 ;
share * s_y__tmp_451 = ycirc->PutCONSGate( _tmp_451 ,bitlen);
share * s_y_tmp_450 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_451 );
vector<uint32_t> _vec452 = s_y_tmp_450->get_wires();
_vec452.erase( _vec452.begin(), _vec452.begin() + 15 );
share *s_y_tmp_449 = create_new_share( _vec452 , ycirc );
uint32_t _tmp_453 = 4294967295 ;
share * s_y__tmp_453 = ycirc->PutCONSGate( _tmp_453 ,bitlen);
share * s_y_tmp_448 = ycirc->PutXORGate( s_y_tmp_449 , s_y__tmp_453 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_446 , s_y_tmp_448 , s_y_tmp_444 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_455 = 2147483648 ;
        share * s_y__tmp_455 = ycirc->PutCONSGate( _tmp_455 ,bitlen);
        share * s_y_tmp_454 = ycirc->PutGTGate( s_y__tmp_455 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec457 = s_y_tmp12[i14][i15]->get_wires();
        _vec457.erase( _vec457.begin(), _vec457.begin() + 15 );
        share *s_y_tmp_456 = create_new_share( _vec457 , ycirc );
        uint32_t _tmp_461 = 4294967295 ;
        share * s_y__tmp_461 = ycirc->PutCONSGate( _tmp_461 ,bitlen);
        share * s_y_tmp_460 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_461 );
        vector<uint32_t> _vec462 = s_y_tmp_460->get_wires();
        _vec462.erase( _vec462.begin(), _vec462.begin() + 15 );
        share *s_y_tmp_459 = create_new_share( _vec462 , ycirc );
        uint32_t _tmp_463 = 4294967295 ;
        share * s_y__tmp_463 = ycirc->PutCONSGate( _tmp_463 ,bitlen);
        share * s_y_tmp_458 = ycirc->PutXORGate( s_y_tmp_459 , s_y__tmp_463 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_456 , s_y_tmp_458 , s_y_tmp_454 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_465 = 2147483648 ;
        share * s_y__tmp_465 = ycirc->PutCONSGate( _tmp_465 ,bitlen);
        share * s_y_tmp_464 = ycirc->PutGTGate( s_y__tmp_465 , s_y_ZZ[1][i16][i17] );
        vector<uint32_t> _vec467 = s_y_ZZ[1][i16][i17]->get_wires();
        _vec467.erase( _vec467.begin(), _vec467.begin() + 15 );
        share *s_y_tmp_466 = create_new_share( _vec467 , ycirc );
        uint32_t _tmp_471 = 4294967295 ;
        share * s_y__tmp_471 = ycirc->PutCONSGate( _tmp_471 ,bitlen);
        share * s_y_tmp_470 = ycirc->PutXORGate( s_y_ZZ[1][i16][i17] , s_y__tmp_471 );
        vector<uint32_t> _vec472 = s_y_tmp_470->get_wires();
        _vec472.erase( _vec472.begin(), _vec472.begin() + 15 );
        share *s_y_tmp_469 = create_new_share( _vec472 , ycirc );
        uint32_t _tmp_473 = 4294967295 ;
        share * s_y__tmp_473 = ycirc->PutCONSGate( _tmp_473 ,bitlen);
        share * s_y_tmp_468 = ycirc->PutXORGate( s_y_tmp_469 , s_y__tmp_473 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_466 , s_y_tmp_468 , s_y_tmp_464 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_475 = 2147483648 ;
        share * s_y__tmp_475 = ycirc->PutCONSGate( _tmp_475 ,bitlen);
        share * s_y_tmp_474 = ycirc->PutGTGate( s_y__tmp_475 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec477 = s_y_tmp21[i17][i18]->get_wires();
        _vec477.erase( _vec477.begin(), _vec477.begin() + 15 );
        share *s_y_tmp_476 = create_new_share( _vec477 , ycirc );
        uint32_t _tmp_481 = 4294967295 ;
        share * s_y__tmp_481 = ycirc->PutCONSGate( _tmp_481 ,bitlen);
        share * s_y_tmp_480 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_481 );
        vector<uint32_t> _vec482 = s_y_tmp_480->get_wires();
        _vec482.erase( _vec482.begin(), _vec482.begin() + 15 );
        share *s_y_tmp_479 = create_new_share( _vec482 , ycirc );
        uint32_t _tmp_483 = 4294967295 ;
        share * s_y__tmp_483 = ycirc->PutCONSGate( _tmp_483 ,bitlen);
        share * s_y_tmp_478 = ycirc->PutXORGate( s_y_tmp_479 , s_y__tmp_483 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_476 , s_y_tmp_478 , s_y_tmp_474 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec486 = s_y_tmp28->get_wires();
                _vec486.erase( _vec486.begin(), _vec486.begin() + 1 );
                share *s_y_tmp_485 = create_new_share( _vec486 , ycirc );
                share * s_y_tmp_484 = ycirc->PutGTGate( s_y_tmp_485 , s_y_tmp29 );
                share * s_y_tmp_489 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_490 = 2147483648 ;
                share * s_y__tmp_490 = ycirc->PutCONSGate( _tmp_490 ,bitlen);
                share * s_y_tmp_488 = ycirc->PutGTGate( s_y__tmp_490 , s_y_tmp_489 );
                share * s_y_tmp_492 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec493 = s_y_tmp_492->get_wires();
                _vec493.erase( _vec493.begin(), _vec493.begin() + 1 );
                share *s_y_tmp_491 = create_new_share( _vec493 , ycirc );
                share * s_y_tmp_497 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_498 = 4294967295 ;
                share * s_y__tmp_498 = ycirc->PutCONSGate( _tmp_498 ,bitlen);
                share * s_y_tmp_496 = ycirc->PutXORGate( s_y_tmp_497 , s_y__tmp_498 );
                vector<uint32_t> _vec499 = s_y_tmp_496->get_wires();
                _vec499.erase( _vec499.begin(), _vec499.begin() + 1 );
                share *s_y_tmp_495 = create_new_share( _vec499 , ycirc );
                uint32_t _tmp_500 = 4294967295 ;
                share * s_y__tmp_500 = ycirc->PutCONSGate( _tmp_500 ,bitlen);
                share * s_y_tmp_494 = ycirc->PutXORGate( s_y_tmp_495 , s_y__tmp_500 );
                share * s_y_tmp_487 = ycirc->PutMUXGate( s_y_tmp_491 , s_y_tmp_494 , s_y_tmp_488 );
                vector<uint32_t> _vec505 = s_y_tmp28->get_wires();
                _vec505.erase( _vec505.begin(), _vec505.begin() + 1 );
                share *s_y_tmp_504 = create_new_share( _vec505 , ycirc );
                share * s_y_tmp_503 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_504 );
                uint32_t _tmp_508 = 1 ;
                share * s_y__tmp_508 = ycirc->PutCONSGate( _tmp_508 ,bitlen);
                share * s_y_tmp_507 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_508 );
                uint32_t _tmp_509 = 1 ;
                share * s_y__tmp_509 = ycirc->PutCONSGate( _tmp_509 ,bitlen);
                share * s_y_tmp_506 = ycirc->PutEQGate( s_y_tmp_507 , s_y__tmp_509 );
                share * s_y_tmp_502 = ycirc->PutANDGate( s_y_tmp_503 , s_y_tmp_506 );
                uint32_t _tmp_512 = 2147483648 ;
                share * s_y__tmp_512 = ycirc->PutCONSGate( _tmp_512 ,bitlen);
                share * s_y_tmp_511 = ycirc->PutGTGate( s_y__tmp_512 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec514 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec514.erase( _vec514.begin(), _vec514.begin() + 1 );
                share *s_y_tmp_513 = create_new_share( _vec514 , ycirc );
                uint32_t _tmp_518 = 4294967295 ;
                share * s_y__tmp_518 = ycirc->PutCONSGate( _tmp_518 ,bitlen);
                share * s_y_tmp_517 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_518 );
                vector<uint32_t> _vec519 = s_y_tmp_517->get_wires();
                _vec519.erase( _vec519.begin(), _vec519.begin() + 1 );
                share *s_y_tmp_516 = create_new_share( _vec519 , ycirc );
                uint32_t _tmp_520 = 4294967295 ;
                share * s_y__tmp_520 = ycirc->PutCONSGate( _tmp_520 ,bitlen);
                share * s_y_tmp_515 = ycirc->PutXORGate( s_y_tmp_516 , s_y__tmp_520 );
                share * s_y_tmp_510 = ycirc->PutMUXGate( s_y_tmp_513 , s_y_tmp_515 , s_y_tmp_511 );
                uint32_t _tmp_521 = 0 ;
                share * s_y__tmp_521 = ycirc->PutCONSGate( _tmp_521 ,bitlen);
                share * s_y_tmp_501 = ycirc->PutMUXGate( s_y_tmp_510 , s_y__tmp_521 , s_y_tmp_502 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_487 , s_y_tmp_501 , s_y_tmp_484 );
                uint32_t _tmp_522 = 1 ;
                share * s_y__tmp_522 = ycirc->PutCONSGate( _tmp_522 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_522 );
            }
            uint32_t _tmp_524 = 1 ;
            share * s_y__tmp_524 = ycirc->PutCONSGate( _tmp_524 ,bitlen);
            share * s_y_tmp_523 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_524 );
            vector<uint32_t> _vec525 = s_y_tmp_523->get_wires();
            _vec525.erase( _vec525.begin(), _vec525.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec525 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec528 = s_y_tmp28->get_wires();
                _vec528.erase( _vec528.begin(), _vec528.begin() + 1 );
                share *s_y_tmp_527 = create_new_share( _vec528 , ycirc );
                share * s_y_tmp_526 = ycirc->PutGTGate( s_y_tmp_527 , s_y_tmp29 );
                share * s_y_tmp_529 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec534 = s_y_tmp28->get_wires();
                _vec534.erase( _vec534.begin(), _vec534.begin() + 1 );
                share *s_y_tmp_533 = create_new_share( _vec534 , ycirc );
                share * s_y_tmp_532 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_533 );
                uint32_t _tmp_537 = 1 ;
                share * s_y__tmp_537 = ycirc->PutCONSGate( _tmp_537 ,bitlen);
                share * s_y_tmp_536 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_537 );
                uint32_t _tmp_538 = 1 ;
                share * s_y__tmp_538 = ycirc->PutCONSGate( _tmp_538 ,bitlen);
                share * s_y_tmp_535 = ycirc->PutEQGate( s_y_tmp_536 , s_y__tmp_538 );
                share * s_y_tmp_531 = ycirc->PutANDGate( s_y_tmp_532 , s_y_tmp_535 );
                uint32_t _tmp_539 = 0 ;
                share * s_y__tmp_539 = ycirc->PutCONSGate( _tmp_539 ,bitlen);
                share * s_y_tmp_530 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_539 , s_y_tmp_531 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_529 , s_y_tmp_530 , s_y_tmp_526 );
                uint32_t _tmp_540 = 1 ;
                share * s_y__tmp_540 = ycirc->PutCONSGate( _tmp_540 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_540 );
            }
            uint32_t _tmp_542 = 1 ;
            share * s_y__tmp_542 = ycirc->PutCONSGate( _tmp_542 ,bitlen);
            share * s_y_tmp_541 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_542 );
            vector<uint32_t> _vec543 = s_y_tmp_541->get_wires();
            _vec543.erase( _vec543.begin(), _vec543.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec543 , ycirc );
        }
        s_y_tmp31[1][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_545 = 2147483648 ;
        share * s_y__tmp_545 = ycirc->PutCONSGate( _tmp_545 ,bitlen);
        share * s_y_tmp_544 = ycirc->PutGTGate( s_y__tmp_545 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec547 = s_y_WW[i0][i1]->get_wires();
        _vec547.erase( _vec547.begin(), _vec547.begin() + 15 );
        share *s_y_tmp_546 = create_new_share( _vec547 , ycirc );
        uint32_t _tmp_551 = 4294967295 ;
        share * s_y__tmp_551 = ycirc->PutCONSGate( _tmp_551 ,bitlen);
        share * s_y_tmp_550 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_551 );
        vector<uint32_t> _vec552 = s_y_tmp_550->get_wires();
        _vec552.erase( _vec552.begin(), _vec552.begin() + 15 );
        share *s_y_tmp_549 = create_new_share( _vec552 , ycirc );
        uint32_t _tmp_553 = 4294967295 ;
        share * s_y__tmp_553 = ycirc->PutCONSGate( _tmp_553 ,bitlen);
        share * s_y_tmp_548 = ycirc->PutXORGate( s_y_tmp_549 , s_y__tmp_553 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_546 , s_y_tmp_548 , s_y_tmp_544 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_555 = 2147483648 ;
        share * s_y__tmp_555 = ycirc->PutCONSGate( _tmp_555 ,bitlen);
        share * s_y_tmp_554 = ycirc->PutGTGate( s_y__tmp_555 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec557 = s_y_xx[i1][i2]->get_wires();
        _vec557.erase( _vec557.begin(), _vec557.begin() + 15 );
        share *s_y_tmp_556 = create_new_share( _vec557 , ycirc );
        uint32_t _tmp_561 = 4294967295 ;
        share * s_y__tmp_561 = ycirc->PutCONSGate( _tmp_561 ,bitlen);
        share * s_y_tmp_560 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_561 );
        vector<uint32_t> _vec562 = s_y_tmp_560->get_wires();
        _vec562.erase( _vec562.begin(), _vec562.begin() + 15 );
        share *s_y_tmp_559 = create_new_share( _vec562 , ycirc );
        uint32_t _tmp_563 = 4294967295 ;
        share * s_y__tmp_563 = ycirc->PutCONSGate( _tmp_563 ,bitlen);
        share * s_y_tmp_558 = ycirc->PutXORGate( s_y_tmp_559 , s_y__tmp_563 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_556 , s_y_tmp_558 , s_y_tmp_554 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec566 = s_y_tmp5->get_wires();
                _vec566.erase( _vec566.begin(), _vec566.begin() + 1 );
                share *s_y_tmp_565 = create_new_share( _vec566 , ycirc );
                share * s_y_tmp_564 = ycirc->PutGTGate( s_y_tmp_565 , s_y_tmp6 );
                share * s_y_tmp_569 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_570 = 2147483648 ;
                share * s_y__tmp_570 = ycirc->PutCONSGate( _tmp_570 ,bitlen);
                share * s_y_tmp_568 = ycirc->PutGTGate( s_y__tmp_570 , s_y_tmp_569 );
                share * s_y_tmp_572 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec573 = s_y_tmp_572->get_wires();
                _vec573.erase( _vec573.begin(), _vec573.begin() + 1 );
                share *s_y_tmp_571 = create_new_share( _vec573 , ycirc );
                share * s_y_tmp_577 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_578 = 4294967295 ;
                share * s_y__tmp_578 = ycirc->PutCONSGate( _tmp_578 ,bitlen);
                share * s_y_tmp_576 = ycirc->PutXORGate( s_y_tmp_577 , s_y__tmp_578 );
                vector<uint32_t> _vec579 = s_y_tmp_576->get_wires();
                _vec579.erase( _vec579.begin(), _vec579.begin() + 1 );
                share *s_y_tmp_575 = create_new_share( _vec579 , ycirc );
                uint32_t _tmp_580 = 4294967295 ;
                share * s_y__tmp_580 = ycirc->PutCONSGate( _tmp_580 ,bitlen);
                share * s_y_tmp_574 = ycirc->PutXORGate( s_y_tmp_575 , s_y__tmp_580 );
                share * s_y_tmp_567 = ycirc->PutMUXGate( s_y_tmp_571 , s_y_tmp_574 , s_y_tmp_568 );
                vector<uint32_t> _vec585 = s_y_tmp5->get_wires();
                _vec585.erase( _vec585.begin(), _vec585.begin() + 1 );
                share *s_y_tmp_584 = create_new_share( _vec585 , ycirc );
                share * s_y_tmp_583 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_584 );
                uint32_t _tmp_588 = 1 ;
                share * s_y__tmp_588 = ycirc->PutCONSGate( _tmp_588 ,bitlen);
                share * s_y_tmp_587 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_588 );
                uint32_t _tmp_589 = 1 ;
                share * s_y__tmp_589 = ycirc->PutCONSGate( _tmp_589 ,bitlen);
                share * s_y_tmp_586 = ycirc->PutEQGate( s_y_tmp_587 , s_y__tmp_589 );
                share * s_y_tmp_582 = ycirc->PutANDGate( s_y_tmp_583 , s_y_tmp_586 );
                uint32_t _tmp_592 = 2147483648 ;
                share * s_y__tmp_592 = ycirc->PutCONSGate( _tmp_592 ,bitlen);
                share * s_y_tmp_591 = ycirc->PutGTGate( s_y__tmp_592 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec594 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec594.erase( _vec594.begin(), _vec594.begin() + 1 );
                share *s_y_tmp_593 = create_new_share( _vec594 , ycirc );
                uint32_t _tmp_598 = 4294967295 ;
                share * s_y__tmp_598 = ycirc->PutCONSGate( _tmp_598 ,bitlen);
                share * s_y_tmp_597 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_598 );
                vector<uint32_t> _vec599 = s_y_tmp_597->get_wires();
                _vec599.erase( _vec599.begin(), _vec599.begin() + 1 );
                share *s_y_tmp_596 = create_new_share( _vec599 , ycirc );
                uint32_t _tmp_600 = 4294967295 ;
                share * s_y__tmp_600 = ycirc->PutCONSGate( _tmp_600 ,bitlen);
                share * s_y_tmp_595 = ycirc->PutXORGate( s_y_tmp_596 , s_y__tmp_600 );
                share * s_y_tmp_590 = ycirc->PutMUXGate( s_y_tmp_593 , s_y_tmp_595 , s_y_tmp_591 );
                uint32_t _tmp_601 = 0 ;
                share * s_y__tmp_601 = ycirc->PutCONSGate( _tmp_601 ,bitlen);
                share * s_y_tmp_581 = ycirc->PutMUXGate( s_y_tmp_590 , s_y__tmp_601 , s_y_tmp_582 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_567 , s_y_tmp_581 , s_y_tmp_564 );
                uint32_t _tmp_602 = 1 ;
                share * s_y__tmp_602 = ycirc->PutCONSGate( _tmp_602 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_602 );
            }
            uint32_t _tmp_604 = 1 ;
            share * s_y__tmp_604 = ycirc->PutCONSGate( _tmp_604 ,bitlen);
            share * s_y_tmp_603 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_604 );
            vector<uint32_t> _vec605 = s_y_tmp_603->get_wires();
            _vec605.erase( _vec605.begin(), _vec605.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec605 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec608 = s_y_tmp5->get_wires();
                _vec608.erase( _vec608.begin(), _vec608.begin() + 1 );
                share *s_y_tmp_607 = create_new_share( _vec608 , ycirc );
                share * s_y_tmp_606 = ycirc->PutGTGate( s_y_tmp_607 , s_y_tmp6 );
                share * s_y_tmp_609 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec614 = s_y_tmp5->get_wires();
                _vec614.erase( _vec614.begin(), _vec614.begin() + 1 );
                share *s_y_tmp_613 = create_new_share( _vec614 , ycirc );
                share * s_y_tmp_612 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_613 );
                uint32_t _tmp_617 = 1 ;
                share * s_y__tmp_617 = ycirc->PutCONSGate( _tmp_617 ,bitlen);
                share * s_y_tmp_616 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_617 );
                uint32_t _tmp_618 = 1 ;
                share * s_y__tmp_618 = ycirc->PutCONSGate( _tmp_618 ,bitlen);
                share * s_y_tmp_615 = ycirc->PutEQGate( s_y_tmp_616 , s_y__tmp_618 );
                share * s_y_tmp_611 = ycirc->PutANDGate( s_y_tmp_612 , s_y_tmp_615 );
                uint32_t _tmp_619 = 0 ;
                share * s_y__tmp_619 = ycirc->PutCONSGate( _tmp_619 ,bitlen);
                share * s_y_tmp_610 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_619 , s_y_tmp_611 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_609 , s_y_tmp_610 , s_y_tmp_606 );
                uint32_t _tmp_620 = 1 ;
                share * s_y__tmp_620 = ycirc->PutCONSGate( _tmp_620 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_620 );
            }
            uint32_t _tmp_622 = 1 ;
            share * s_y__tmp_622 = ycirc->PutCONSGate( _tmp_622 ,bitlen);
            share * s_y_tmp_621 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_622 );
            vector<uint32_t> _vec623 = s_y_tmp_621->get_wires();
            _vec623.erase( _vec623.begin(), _vec623.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec623 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_625 = 2147483648 ;
        share * s_y__tmp_625 = ycirc->PutCONSGate( _tmp_625 ,bitlen);
        share * s_y_tmp_624 = ycirc->PutGTGate( s_y__tmp_625 , s_y_BB[2][i5][i6] );
        vector<uint32_t> _vec627 = s_y_BB[2][i5][i6]->get_wires();
        _vec627.erase( _vec627.begin(), _vec627.begin() + 4 );
        share *s_y_tmp_626 = create_new_share( _vec627 , ycirc );
        uint32_t _tmp_631 = 4294967295 ;
        share * s_y__tmp_631 = ycirc->PutCONSGate( _tmp_631 ,bitlen);
        share * s_y_tmp_630 = ycirc->PutXORGate( s_y_BB[2][i5][i6] , s_y__tmp_631 );
        vector<uint32_t> _vec632 = s_y_tmp_630->get_wires();
        _vec632.erase( _vec632.begin(), _vec632.begin() + 4 );
        share *s_y_tmp_629 = create_new_share( _vec632 , ycirc );
        uint32_t _tmp_633 = 4294967295 ;
        share * s_y__tmp_633 = ycirc->PutCONSGate( _tmp_633 ,bitlen);
        share * s_y_tmp_628 = ycirc->PutXORGate( s_y_tmp_629 , s_y__tmp_633 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_626 , s_y_tmp_628 , s_y_tmp_624 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_634 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_635 = 1 ;
share * s_a__tmp_635 = acirc->PutCONSGate( _tmp_635 ,bitlen);
share *s_a_tmp_634 = acirc->PutY2AGate( s_y_tmp_634 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_634 , s_a__tmp_635 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_637 = 2147483648 ;
        share * s_y__tmp_637 = ycirc->PutCONSGate( _tmp_637 ,bitlen);
        share * s_y_tmp_636 = ycirc->PutGTGate( s_y__tmp_637 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec639 = s_y_tmp11[i9][i10]->get_wires();
        _vec639.erase( _vec639.begin(), _vec639.begin() + 15 );
        share *s_y_tmp_638 = create_new_share( _vec639 , ycirc );
        uint32_t _tmp_643 = 4294967295 ;
        share * s_y__tmp_643 = ycirc->PutCONSGate( _tmp_643 ,bitlen);
        share * s_y_tmp_642 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_643 );
        vector<uint32_t> _vec644 = s_y_tmp_642->get_wires();
        _vec644.erase( _vec644.begin(), _vec644.begin() + 15 );
        share *s_y_tmp_641 = create_new_share( _vec644 , ycirc );
        uint32_t _tmp_645 = 4294967295 ;
        share * s_y__tmp_645 = ycirc->PutCONSGate( _tmp_645 ,bitlen);
        share * s_y_tmp_640 = ycirc->PutXORGate( s_y_tmp_641 , s_y__tmp_645 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_638 , s_y_tmp_640 , s_y_tmp_636 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_647 = 2147483648 ;
        share * s_y__tmp_647 = ycirc->PutCONSGate( _tmp_647 ,bitlen);
        share * s_y_tmp_646 = ycirc->PutGTGate( s_y__tmp_647 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec649 = s_y_tmp7[i10][i11]->get_wires();
        _vec649.erase( _vec649.begin(), _vec649.begin() + 15 );
        share *s_y_tmp_648 = create_new_share( _vec649 , ycirc );
        uint32_t _tmp_653 = 4294967295 ;
        share * s_y__tmp_653 = ycirc->PutCONSGate( _tmp_653 ,bitlen);
        share * s_y_tmp_652 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_653 );
        vector<uint32_t> _vec654 = s_y_tmp_652->get_wires();
        _vec654.erase( _vec654.begin(), _vec654.begin() + 15 );
        share *s_y_tmp_651 = create_new_share( _vec654 , ycirc );
        uint32_t _tmp_655 = 4294967295 ;
        share * s_y__tmp_655 = ycirc->PutCONSGate( _tmp_655 ,bitlen);
        share * s_y_tmp_650 = ycirc->PutXORGate( s_y_tmp_651 , s_y__tmp_655 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_648 , s_y_tmp_650 , s_y_tmp_646 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec658 = s_y_tmp16->get_wires();
                _vec658.erase( _vec658.begin(), _vec658.begin() + 1 );
                share *s_y_tmp_657 = create_new_share( _vec658 , ycirc );
                share * s_y_tmp_656 = ycirc->PutGTGate( s_y_tmp_657 , s_y_tmp17 );
                share * s_y_tmp_661 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_662 = 2147483648 ;
                share * s_y__tmp_662 = ycirc->PutCONSGate( _tmp_662 ,bitlen);
                share * s_y_tmp_660 = ycirc->PutGTGate( s_y__tmp_662 , s_y_tmp_661 );
                share * s_y_tmp_664 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec665 = s_y_tmp_664->get_wires();
                _vec665.erase( _vec665.begin(), _vec665.begin() + 1 );
                share *s_y_tmp_663 = create_new_share( _vec665 , ycirc );
                share * s_y_tmp_669 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_670 = 4294967295 ;
                share * s_y__tmp_670 = ycirc->PutCONSGate( _tmp_670 ,bitlen);
                share * s_y_tmp_668 = ycirc->PutXORGate( s_y_tmp_669 , s_y__tmp_670 );
                vector<uint32_t> _vec671 = s_y_tmp_668->get_wires();
                _vec671.erase( _vec671.begin(), _vec671.begin() + 1 );
                share *s_y_tmp_667 = create_new_share( _vec671 , ycirc );
                uint32_t _tmp_672 = 4294967295 ;
                share * s_y__tmp_672 = ycirc->PutCONSGate( _tmp_672 ,bitlen);
                share * s_y_tmp_666 = ycirc->PutXORGate( s_y_tmp_667 , s_y__tmp_672 );
                share * s_y_tmp_659 = ycirc->PutMUXGate( s_y_tmp_663 , s_y_tmp_666 , s_y_tmp_660 );
                vector<uint32_t> _vec677 = s_y_tmp16->get_wires();
                _vec677.erase( _vec677.begin(), _vec677.begin() + 1 );
                share *s_y_tmp_676 = create_new_share( _vec677 , ycirc );
                share * s_y_tmp_675 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_676 );
                uint32_t _tmp_680 = 1 ;
                share * s_y__tmp_680 = ycirc->PutCONSGate( _tmp_680 ,bitlen);
                share * s_y_tmp_679 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_680 );
                uint32_t _tmp_681 = 1 ;
                share * s_y__tmp_681 = ycirc->PutCONSGate( _tmp_681 ,bitlen);
                share * s_y_tmp_678 = ycirc->PutEQGate( s_y_tmp_679 , s_y__tmp_681 );
                share * s_y_tmp_674 = ycirc->PutANDGate( s_y_tmp_675 , s_y_tmp_678 );
                uint32_t _tmp_684 = 2147483648 ;
                share * s_y__tmp_684 = ycirc->PutCONSGate( _tmp_684 ,bitlen);
                share * s_y_tmp_683 = ycirc->PutGTGate( s_y__tmp_684 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec686 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec686.erase( _vec686.begin(), _vec686.begin() + 1 );
                share *s_y_tmp_685 = create_new_share( _vec686 , ycirc );
                uint32_t _tmp_690 = 4294967295 ;
                share * s_y__tmp_690 = ycirc->PutCONSGate( _tmp_690 ,bitlen);
                share * s_y_tmp_689 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_690 );
                vector<uint32_t> _vec691 = s_y_tmp_689->get_wires();
                _vec691.erase( _vec691.begin(), _vec691.begin() + 1 );
                share *s_y_tmp_688 = create_new_share( _vec691 , ycirc );
                uint32_t _tmp_692 = 4294967295 ;
                share * s_y__tmp_692 = ycirc->PutCONSGate( _tmp_692 ,bitlen);
                share * s_y_tmp_687 = ycirc->PutXORGate( s_y_tmp_688 , s_y__tmp_692 );
                share * s_y_tmp_682 = ycirc->PutMUXGate( s_y_tmp_685 , s_y_tmp_687 , s_y_tmp_683 );
                uint32_t _tmp_693 = 0 ;
                share * s_y__tmp_693 = ycirc->PutCONSGate( _tmp_693 ,bitlen);
                share * s_y_tmp_673 = ycirc->PutMUXGate( s_y_tmp_682 , s_y__tmp_693 , s_y_tmp_674 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_659 , s_y_tmp_673 , s_y_tmp_656 );
                uint32_t _tmp_694 = 1 ;
                share * s_y__tmp_694 = ycirc->PutCONSGate( _tmp_694 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_694 );
            }
            uint32_t _tmp_696 = 1 ;
            share * s_y__tmp_696 = ycirc->PutCONSGate( _tmp_696 ,bitlen);
            share * s_y_tmp_695 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_696 );
            vector<uint32_t> _vec697 = s_y_tmp_695->get_wires();
            _vec697.erase( _vec697.begin(), _vec697.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec697 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec700 = s_y_tmp16->get_wires();
                _vec700.erase( _vec700.begin(), _vec700.begin() + 1 );
                share *s_y_tmp_699 = create_new_share( _vec700 , ycirc );
                share * s_y_tmp_698 = ycirc->PutGTGate( s_y_tmp_699 , s_y_tmp17 );
                share * s_y_tmp_701 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec706 = s_y_tmp16->get_wires();
                _vec706.erase( _vec706.begin(), _vec706.begin() + 1 );
                share *s_y_tmp_705 = create_new_share( _vec706 , ycirc );
                share * s_y_tmp_704 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_705 );
                uint32_t _tmp_709 = 1 ;
                share * s_y__tmp_709 = ycirc->PutCONSGate( _tmp_709 ,bitlen);
                share * s_y_tmp_708 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_709 );
                uint32_t _tmp_710 = 1 ;
                share * s_y__tmp_710 = ycirc->PutCONSGate( _tmp_710 ,bitlen);
                share * s_y_tmp_707 = ycirc->PutEQGate( s_y_tmp_708 , s_y__tmp_710 );
                share * s_y_tmp_703 = ycirc->PutANDGate( s_y_tmp_704 , s_y_tmp_707 );
                uint32_t _tmp_711 = 0 ;
                share * s_y__tmp_711 = ycirc->PutCONSGate( _tmp_711 ,bitlen);
                share * s_y_tmp_702 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_711 , s_y_tmp_703 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_701 , s_y_tmp_702 , s_y_tmp_698 );
                uint32_t _tmp_712 = 1 ;
                share * s_y__tmp_712 = ycirc->PutCONSGate( _tmp_712 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_712 );
            }
            uint32_t _tmp_714 = 1 ;
            share * s_y__tmp_714 = ycirc->PutCONSGate( _tmp_714 ,bitlen);
            share * s_y_tmp_713 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_714 );
            vector<uint32_t> _vec715 = s_y_tmp_713->get_wires();
            _vec715.erase( _vec715.begin(), _vec715.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec715 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_717 = 2147483648 ;
share * s_y__tmp_717 = ycirc->PutCONSGate( _tmp_717 ,bitlen);
share * s_y_tmp_716 = ycirc->PutGTGate( s_y__tmp_717 , s_y_tmp10 );
vector<uint32_t> _vec719 = s_y_tmp10->get_wires();
_vec719.erase( _vec719.begin(), _vec719.begin() + 15 );
share *s_y_tmp_718 = create_new_share( _vec719 , ycirc );
uint32_t _tmp_723 = 4294967295 ;
share * s_y__tmp_723 = ycirc->PutCONSGate( _tmp_723 ,bitlen);
share * s_y_tmp_722 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_723 );
vector<uint32_t> _vec724 = s_y_tmp_722->get_wires();
_vec724.erase( _vec724.begin(), _vec724.begin() + 15 );
share *s_y_tmp_721 = create_new_share( _vec724 , ycirc );
uint32_t _tmp_725 = 4294967295 ;
share * s_y__tmp_725 = ycirc->PutCONSGate( _tmp_725 ,bitlen);
share * s_y_tmp_720 = ycirc->PutXORGate( s_y_tmp_721 , s_y__tmp_725 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_718 , s_y_tmp_720 , s_y_tmp_716 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_727 = 2147483648 ;
        share * s_y__tmp_727 = ycirc->PutCONSGate( _tmp_727 ,bitlen);
        share * s_y_tmp_726 = ycirc->PutGTGate( s_y__tmp_727 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec729 = s_y_tmp12[i14][i15]->get_wires();
        _vec729.erase( _vec729.begin(), _vec729.begin() + 15 );
        share *s_y_tmp_728 = create_new_share( _vec729 , ycirc );
        uint32_t _tmp_733 = 4294967295 ;
        share * s_y__tmp_733 = ycirc->PutCONSGate( _tmp_733 ,bitlen);
        share * s_y_tmp_732 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_733 );
        vector<uint32_t> _vec734 = s_y_tmp_732->get_wires();
        _vec734.erase( _vec734.begin(), _vec734.begin() + 15 );
        share *s_y_tmp_731 = create_new_share( _vec734 , ycirc );
        uint32_t _tmp_735 = 4294967295 ;
        share * s_y__tmp_735 = ycirc->PutCONSGate( _tmp_735 ,bitlen);
        share * s_y_tmp_730 = ycirc->PutXORGate( s_y_tmp_731 , s_y__tmp_735 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_728 , s_y_tmp_730 , s_y_tmp_726 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_737 = 2147483648 ;
        share * s_y__tmp_737 = ycirc->PutCONSGate( _tmp_737 ,bitlen);
        share * s_y_tmp_736 = ycirc->PutGTGate( s_y__tmp_737 , s_y_ZZ[2][i16][i17] );
        vector<uint32_t> _vec739 = s_y_ZZ[2][i16][i17]->get_wires();
        _vec739.erase( _vec739.begin(), _vec739.begin() + 15 );
        share *s_y_tmp_738 = create_new_share( _vec739 , ycirc );
        uint32_t _tmp_743 = 4294967295 ;
        share * s_y__tmp_743 = ycirc->PutCONSGate( _tmp_743 ,bitlen);
        share * s_y_tmp_742 = ycirc->PutXORGate( s_y_ZZ[2][i16][i17] , s_y__tmp_743 );
        vector<uint32_t> _vec744 = s_y_tmp_742->get_wires();
        _vec744.erase( _vec744.begin(), _vec744.begin() + 15 );
        share *s_y_tmp_741 = create_new_share( _vec744 , ycirc );
        uint32_t _tmp_745 = 4294967295 ;
        share * s_y__tmp_745 = ycirc->PutCONSGate( _tmp_745 ,bitlen);
        share * s_y_tmp_740 = ycirc->PutXORGate( s_y_tmp_741 , s_y__tmp_745 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_738 , s_y_tmp_740 , s_y_tmp_736 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_747 = 2147483648 ;
        share * s_y__tmp_747 = ycirc->PutCONSGate( _tmp_747 ,bitlen);
        share * s_y_tmp_746 = ycirc->PutGTGate( s_y__tmp_747 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec749 = s_y_tmp21[i17][i18]->get_wires();
        _vec749.erase( _vec749.begin(), _vec749.begin() + 15 );
        share *s_y_tmp_748 = create_new_share( _vec749 , ycirc );
        uint32_t _tmp_753 = 4294967295 ;
        share * s_y__tmp_753 = ycirc->PutCONSGate( _tmp_753 ,bitlen);
        share * s_y_tmp_752 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_753 );
        vector<uint32_t> _vec754 = s_y_tmp_752->get_wires();
        _vec754.erase( _vec754.begin(), _vec754.begin() + 15 );
        share *s_y_tmp_751 = create_new_share( _vec754 , ycirc );
        uint32_t _tmp_755 = 4294967295 ;
        share * s_y__tmp_755 = ycirc->PutCONSGate( _tmp_755 ,bitlen);
        share * s_y_tmp_750 = ycirc->PutXORGate( s_y_tmp_751 , s_y__tmp_755 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_748 , s_y_tmp_750 , s_y_tmp_746 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec758 = s_y_tmp28->get_wires();
                _vec758.erase( _vec758.begin(), _vec758.begin() + 1 );
                share *s_y_tmp_757 = create_new_share( _vec758 , ycirc );
                share * s_y_tmp_756 = ycirc->PutGTGate( s_y_tmp_757 , s_y_tmp29 );
                share * s_y_tmp_761 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_762 = 2147483648 ;
                share * s_y__tmp_762 = ycirc->PutCONSGate( _tmp_762 ,bitlen);
                share * s_y_tmp_760 = ycirc->PutGTGate( s_y__tmp_762 , s_y_tmp_761 );
                share * s_y_tmp_764 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec765 = s_y_tmp_764->get_wires();
                _vec765.erase( _vec765.begin(), _vec765.begin() + 1 );
                share *s_y_tmp_763 = create_new_share( _vec765 , ycirc );
                share * s_y_tmp_769 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_770 = 4294967295 ;
                share * s_y__tmp_770 = ycirc->PutCONSGate( _tmp_770 ,bitlen);
                share * s_y_tmp_768 = ycirc->PutXORGate( s_y_tmp_769 , s_y__tmp_770 );
                vector<uint32_t> _vec771 = s_y_tmp_768->get_wires();
                _vec771.erase( _vec771.begin(), _vec771.begin() + 1 );
                share *s_y_tmp_767 = create_new_share( _vec771 , ycirc );
                uint32_t _tmp_772 = 4294967295 ;
                share * s_y__tmp_772 = ycirc->PutCONSGate( _tmp_772 ,bitlen);
                share * s_y_tmp_766 = ycirc->PutXORGate( s_y_tmp_767 , s_y__tmp_772 );
                share * s_y_tmp_759 = ycirc->PutMUXGate( s_y_tmp_763 , s_y_tmp_766 , s_y_tmp_760 );
                vector<uint32_t> _vec777 = s_y_tmp28->get_wires();
                _vec777.erase( _vec777.begin(), _vec777.begin() + 1 );
                share *s_y_tmp_776 = create_new_share( _vec777 , ycirc );
                share * s_y_tmp_775 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_776 );
                uint32_t _tmp_780 = 1 ;
                share * s_y__tmp_780 = ycirc->PutCONSGate( _tmp_780 ,bitlen);
                share * s_y_tmp_779 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_780 );
                uint32_t _tmp_781 = 1 ;
                share * s_y__tmp_781 = ycirc->PutCONSGate( _tmp_781 ,bitlen);
                share * s_y_tmp_778 = ycirc->PutEQGate( s_y_tmp_779 , s_y__tmp_781 );
                share * s_y_tmp_774 = ycirc->PutANDGate( s_y_tmp_775 , s_y_tmp_778 );
                uint32_t _tmp_784 = 2147483648 ;
                share * s_y__tmp_784 = ycirc->PutCONSGate( _tmp_784 ,bitlen);
                share * s_y_tmp_783 = ycirc->PutGTGate( s_y__tmp_784 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec786 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec786.erase( _vec786.begin(), _vec786.begin() + 1 );
                share *s_y_tmp_785 = create_new_share( _vec786 , ycirc );
                uint32_t _tmp_790 = 4294967295 ;
                share * s_y__tmp_790 = ycirc->PutCONSGate( _tmp_790 ,bitlen);
                share * s_y_tmp_789 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_790 );
                vector<uint32_t> _vec791 = s_y_tmp_789->get_wires();
                _vec791.erase( _vec791.begin(), _vec791.begin() + 1 );
                share *s_y_tmp_788 = create_new_share( _vec791 , ycirc );
                uint32_t _tmp_792 = 4294967295 ;
                share * s_y__tmp_792 = ycirc->PutCONSGate( _tmp_792 ,bitlen);
                share * s_y_tmp_787 = ycirc->PutXORGate( s_y_tmp_788 , s_y__tmp_792 );
                share * s_y_tmp_782 = ycirc->PutMUXGate( s_y_tmp_785 , s_y_tmp_787 , s_y_tmp_783 );
                uint32_t _tmp_793 = 0 ;
                share * s_y__tmp_793 = ycirc->PutCONSGate( _tmp_793 ,bitlen);
                share * s_y_tmp_773 = ycirc->PutMUXGate( s_y_tmp_782 , s_y__tmp_793 , s_y_tmp_774 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_759 , s_y_tmp_773 , s_y_tmp_756 );
                uint32_t _tmp_794 = 1 ;
                share * s_y__tmp_794 = ycirc->PutCONSGate( _tmp_794 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_794 );
            }
            uint32_t _tmp_796 = 1 ;
            share * s_y__tmp_796 = ycirc->PutCONSGate( _tmp_796 ,bitlen);
            share * s_y_tmp_795 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_796 );
            vector<uint32_t> _vec797 = s_y_tmp_795->get_wires();
            _vec797.erase( _vec797.begin(), _vec797.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec797 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec800 = s_y_tmp28->get_wires();
                _vec800.erase( _vec800.begin(), _vec800.begin() + 1 );
                share *s_y_tmp_799 = create_new_share( _vec800 , ycirc );
                share * s_y_tmp_798 = ycirc->PutGTGate( s_y_tmp_799 , s_y_tmp29 );
                share * s_y_tmp_801 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec806 = s_y_tmp28->get_wires();
                _vec806.erase( _vec806.begin(), _vec806.begin() + 1 );
                share *s_y_tmp_805 = create_new_share( _vec806 , ycirc );
                share * s_y_tmp_804 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_805 );
                uint32_t _tmp_809 = 1 ;
                share * s_y__tmp_809 = ycirc->PutCONSGate( _tmp_809 ,bitlen);
                share * s_y_tmp_808 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_809 );
                uint32_t _tmp_810 = 1 ;
                share * s_y__tmp_810 = ycirc->PutCONSGate( _tmp_810 ,bitlen);
                share * s_y_tmp_807 = ycirc->PutEQGate( s_y_tmp_808 , s_y__tmp_810 );
                share * s_y_tmp_803 = ycirc->PutANDGate( s_y_tmp_804 , s_y_tmp_807 );
                uint32_t _tmp_811 = 0 ;
                share * s_y__tmp_811 = ycirc->PutCONSGate( _tmp_811 ,bitlen);
                share * s_y_tmp_802 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_811 , s_y_tmp_803 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_801 , s_y_tmp_802 , s_y_tmp_798 );
                uint32_t _tmp_812 = 1 ;
                share * s_y__tmp_812 = ycirc->PutCONSGate( _tmp_812 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_812 );
            }
            uint32_t _tmp_814 = 1 ;
            share * s_y__tmp_814 = ycirc->PutCONSGate( _tmp_814 ,bitlen);
            share * s_y_tmp_813 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_814 );
            vector<uint32_t> _vec815 = s_y_tmp_813->get_wires();
            _vec815.erase( _vec815.begin(), _vec815.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec815 , ycirc );
        }
        s_y_tmp31[2][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_817 = 2147483648 ;
        share * s_y__tmp_817 = ycirc->PutCONSGate( _tmp_817 ,bitlen);
        share * s_y_tmp_816 = ycirc->PutGTGate( s_y__tmp_817 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec819 = s_y_WW[i0][i1]->get_wires();
        _vec819.erase( _vec819.begin(), _vec819.begin() + 15 );
        share *s_y_tmp_818 = create_new_share( _vec819 , ycirc );
        uint32_t _tmp_823 = 4294967295 ;
        share * s_y__tmp_823 = ycirc->PutCONSGate( _tmp_823 ,bitlen);
        share * s_y_tmp_822 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_823 );
        vector<uint32_t> _vec824 = s_y_tmp_822->get_wires();
        _vec824.erase( _vec824.begin(), _vec824.begin() + 15 );
        share *s_y_tmp_821 = create_new_share( _vec824 , ycirc );
        uint32_t _tmp_825 = 4294967295 ;
        share * s_y__tmp_825 = ycirc->PutCONSGate( _tmp_825 ,bitlen);
        share * s_y_tmp_820 = ycirc->PutXORGate( s_y_tmp_821 , s_y__tmp_825 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_818 , s_y_tmp_820 , s_y_tmp_816 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_827 = 2147483648 ;
        share * s_y__tmp_827 = ycirc->PutCONSGate( _tmp_827 ,bitlen);
        share * s_y_tmp_826 = ycirc->PutGTGate( s_y__tmp_827 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec829 = s_y_xx[i1][i2]->get_wires();
        _vec829.erase( _vec829.begin(), _vec829.begin() + 15 );
        share *s_y_tmp_828 = create_new_share( _vec829 , ycirc );
        uint32_t _tmp_833 = 4294967295 ;
        share * s_y__tmp_833 = ycirc->PutCONSGate( _tmp_833 ,bitlen);
        share * s_y_tmp_832 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_833 );
        vector<uint32_t> _vec834 = s_y_tmp_832->get_wires();
        _vec834.erase( _vec834.begin(), _vec834.begin() + 15 );
        share *s_y_tmp_831 = create_new_share( _vec834 , ycirc );
        uint32_t _tmp_835 = 4294967295 ;
        share * s_y__tmp_835 = ycirc->PutCONSGate( _tmp_835 ,bitlen);
        share * s_y_tmp_830 = ycirc->PutXORGate( s_y_tmp_831 , s_y__tmp_835 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_828 , s_y_tmp_830 , s_y_tmp_826 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec838 = s_y_tmp5->get_wires();
                _vec838.erase( _vec838.begin(), _vec838.begin() + 1 );
                share *s_y_tmp_837 = create_new_share( _vec838 , ycirc );
                share * s_y_tmp_836 = ycirc->PutGTGate( s_y_tmp_837 , s_y_tmp6 );
                share * s_y_tmp_841 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_842 = 2147483648 ;
                share * s_y__tmp_842 = ycirc->PutCONSGate( _tmp_842 ,bitlen);
                share * s_y_tmp_840 = ycirc->PutGTGate( s_y__tmp_842 , s_y_tmp_841 );
                share * s_y_tmp_844 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec845 = s_y_tmp_844->get_wires();
                _vec845.erase( _vec845.begin(), _vec845.begin() + 1 );
                share *s_y_tmp_843 = create_new_share( _vec845 , ycirc );
                share * s_y_tmp_849 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_850 = 4294967295 ;
                share * s_y__tmp_850 = ycirc->PutCONSGate( _tmp_850 ,bitlen);
                share * s_y_tmp_848 = ycirc->PutXORGate( s_y_tmp_849 , s_y__tmp_850 );
                vector<uint32_t> _vec851 = s_y_tmp_848->get_wires();
                _vec851.erase( _vec851.begin(), _vec851.begin() + 1 );
                share *s_y_tmp_847 = create_new_share( _vec851 , ycirc );
                uint32_t _tmp_852 = 4294967295 ;
                share * s_y__tmp_852 = ycirc->PutCONSGate( _tmp_852 ,bitlen);
                share * s_y_tmp_846 = ycirc->PutXORGate( s_y_tmp_847 , s_y__tmp_852 );
                share * s_y_tmp_839 = ycirc->PutMUXGate( s_y_tmp_843 , s_y_tmp_846 , s_y_tmp_840 );
                vector<uint32_t> _vec857 = s_y_tmp5->get_wires();
                _vec857.erase( _vec857.begin(), _vec857.begin() + 1 );
                share *s_y_tmp_856 = create_new_share( _vec857 , ycirc );
                share * s_y_tmp_855 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_856 );
                uint32_t _tmp_860 = 1 ;
                share * s_y__tmp_860 = ycirc->PutCONSGate( _tmp_860 ,bitlen);
                share * s_y_tmp_859 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_860 );
                uint32_t _tmp_861 = 1 ;
                share * s_y__tmp_861 = ycirc->PutCONSGate( _tmp_861 ,bitlen);
                share * s_y_tmp_858 = ycirc->PutEQGate( s_y_tmp_859 , s_y__tmp_861 );
                share * s_y_tmp_854 = ycirc->PutANDGate( s_y_tmp_855 , s_y_tmp_858 );
                uint32_t _tmp_864 = 2147483648 ;
                share * s_y__tmp_864 = ycirc->PutCONSGate( _tmp_864 ,bitlen);
                share * s_y_tmp_863 = ycirc->PutGTGate( s_y__tmp_864 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec866 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec866.erase( _vec866.begin(), _vec866.begin() + 1 );
                share *s_y_tmp_865 = create_new_share( _vec866 , ycirc );
                uint32_t _tmp_870 = 4294967295 ;
                share * s_y__tmp_870 = ycirc->PutCONSGate( _tmp_870 ,bitlen);
                share * s_y_tmp_869 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_870 );
                vector<uint32_t> _vec871 = s_y_tmp_869->get_wires();
                _vec871.erase( _vec871.begin(), _vec871.begin() + 1 );
                share *s_y_tmp_868 = create_new_share( _vec871 , ycirc );
                uint32_t _tmp_872 = 4294967295 ;
                share * s_y__tmp_872 = ycirc->PutCONSGate( _tmp_872 ,bitlen);
                share * s_y_tmp_867 = ycirc->PutXORGate( s_y_tmp_868 , s_y__tmp_872 );
                share * s_y_tmp_862 = ycirc->PutMUXGate( s_y_tmp_865 , s_y_tmp_867 , s_y_tmp_863 );
                uint32_t _tmp_873 = 0 ;
                share * s_y__tmp_873 = ycirc->PutCONSGate( _tmp_873 ,bitlen);
                share * s_y_tmp_853 = ycirc->PutMUXGate( s_y_tmp_862 , s_y__tmp_873 , s_y_tmp_854 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_839 , s_y_tmp_853 , s_y_tmp_836 );
                uint32_t _tmp_874 = 1 ;
                share * s_y__tmp_874 = ycirc->PutCONSGate( _tmp_874 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_874 );
            }
            uint32_t _tmp_876 = 1 ;
            share * s_y__tmp_876 = ycirc->PutCONSGate( _tmp_876 ,bitlen);
            share * s_y_tmp_875 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_876 );
            vector<uint32_t> _vec877 = s_y_tmp_875->get_wires();
            _vec877.erase( _vec877.begin(), _vec877.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec877 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec880 = s_y_tmp5->get_wires();
                _vec880.erase( _vec880.begin(), _vec880.begin() + 1 );
                share *s_y_tmp_879 = create_new_share( _vec880 , ycirc );
                share * s_y_tmp_878 = ycirc->PutGTGate( s_y_tmp_879 , s_y_tmp6 );
                share * s_y_tmp_881 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec886 = s_y_tmp5->get_wires();
                _vec886.erase( _vec886.begin(), _vec886.begin() + 1 );
                share *s_y_tmp_885 = create_new_share( _vec886 , ycirc );
                share * s_y_tmp_884 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_885 );
                uint32_t _tmp_889 = 1 ;
                share * s_y__tmp_889 = ycirc->PutCONSGate( _tmp_889 ,bitlen);
                share * s_y_tmp_888 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_889 );
                uint32_t _tmp_890 = 1 ;
                share * s_y__tmp_890 = ycirc->PutCONSGate( _tmp_890 ,bitlen);
                share * s_y_tmp_887 = ycirc->PutEQGate( s_y_tmp_888 , s_y__tmp_890 );
                share * s_y_tmp_883 = ycirc->PutANDGate( s_y_tmp_884 , s_y_tmp_887 );
                uint32_t _tmp_891 = 0 ;
                share * s_y__tmp_891 = ycirc->PutCONSGate( _tmp_891 ,bitlen);
                share * s_y_tmp_882 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_891 , s_y_tmp_883 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_881 , s_y_tmp_882 , s_y_tmp_878 );
                uint32_t _tmp_892 = 1 ;
                share * s_y__tmp_892 = ycirc->PutCONSGate( _tmp_892 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_892 );
            }
            uint32_t _tmp_894 = 1 ;
            share * s_y__tmp_894 = ycirc->PutCONSGate( _tmp_894 ,bitlen);
            share * s_y_tmp_893 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_894 );
            vector<uint32_t> _vec895 = s_y_tmp_893->get_wires();
            _vec895.erase( _vec895.begin(), _vec895.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec895 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_897 = 2147483648 ;
        share * s_y__tmp_897 = ycirc->PutCONSGate( _tmp_897 ,bitlen);
        share * s_y_tmp_896 = ycirc->PutGTGate( s_y__tmp_897 , s_y_BB[3][i5][i6] );
        vector<uint32_t> _vec899 = s_y_BB[3][i5][i6]->get_wires();
        _vec899.erase( _vec899.begin(), _vec899.begin() + 4 );
        share *s_y_tmp_898 = create_new_share( _vec899 , ycirc );
        uint32_t _tmp_903 = 4294967295 ;
        share * s_y__tmp_903 = ycirc->PutCONSGate( _tmp_903 ,bitlen);
        share * s_y_tmp_902 = ycirc->PutXORGate( s_y_BB[3][i5][i6] , s_y__tmp_903 );
        vector<uint32_t> _vec904 = s_y_tmp_902->get_wires();
        _vec904.erase( _vec904.begin(), _vec904.begin() + 4 );
        share *s_y_tmp_901 = create_new_share( _vec904 , ycirc );
        uint32_t _tmp_905 = 4294967295 ;
        share * s_y__tmp_905 = ycirc->PutCONSGate( _tmp_905 ,bitlen);
        share * s_y_tmp_900 = ycirc->PutXORGate( s_y_tmp_901 , s_y__tmp_905 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_898 , s_y_tmp_900 , s_y_tmp_896 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_906 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_907 = 1 ;
share * s_a__tmp_907 = acirc->PutCONSGate( _tmp_907 ,bitlen);
share *s_a_tmp_906 = acirc->PutY2AGate( s_y_tmp_906 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_906 , s_a__tmp_907 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_909 = 2147483648 ;
        share * s_y__tmp_909 = ycirc->PutCONSGate( _tmp_909 ,bitlen);
        share * s_y_tmp_908 = ycirc->PutGTGate( s_y__tmp_909 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec911 = s_y_tmp11[i9][i10]->get_wires();
        _vec911.erase( _vec911.begin(), _vec911.begin() + 15 );
        share *s_y_tmp_910 = create_new_share( _vec911 , ycirc );
        uint32_t _tmp_915 = 4294967295 ;
        share * s_y__tmp_915 = ycirc->PutCONSGate( _tmp_915 ,bitlen);
        share * s_y_tmp_914 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_915 );
        vector<uint32_t> _vec916 = s_y_tmp_914->get_wires();
        _vec916.erase( _vec916.begin(), _vec916.begin() + 15 );
        share *s_y_tmp_913 = create_new_share( _vec916 , ycirc );
        uint32_t _tmp_917 = 4294967295 ;
        share * s_y__tmp_917 = ycirc->PutCONSGate( _tmp_917 ,bitlen);
        share * s_y_tmp_912 = ycirc->PutXORGate( s_y_tmp_913 , s_y__tmp_917 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_910 , s_y_tmp_912 , s_y_tmp_908 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_919 = 2147483648 ;
        share * s_y__tmp_919 = ycirc->PutCONSGate( _tmp_919 ,bitlen);
        share * s_y_tmp_918 = ycirc->PutGTGate( s_y__tmp_919 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec921 = s_y_tmp7[i10][i11]->get_wires();
        _vec921.erase( _vec921.begin(), _vec921.begin() + 15 );
        share *s_y_tmp_920 = create_new_share( _vec921 , ycirc );
        uint32_t _tmp_925 = 4294967295 ;
        share * s_y__tmp_925 = ycirc->PutCONSGate( _tmp_925 ,bitlen);
        share * s_y_tmp_924 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_925 );
        vector<uint32_t> _vec926 = s_y_tmp_924->get_wires();
        _vec926.erase( _vec926.begin(), _vec926.begin() + 15 );
        share *s_y_tmp_923 = create_new_share( _vec926 , ycirc );
        uint32_t _tmp_927 = 4294967295 ;
        share * s_y__tmp_927 = ycirc->PutCONSGate( _tmp_927 ,bitlen);
        share * s_y_tmp_922 = ycirc->PutXORGate( s_y_tmp_923 , s_y__tmp_927 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_920 , s_y_tmp_922 , s_y_tmp_918 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec930 = s_y_tmp16->get_wires();
                _vec930.erase( _vec930.begin(), _vec930.begin() + 1 );
                share *s_y_tmp_929 = create_new_share( _vec930 , ycirc );
                share * s_y_tmp_928 = ycirc->PutGTGate( s_y_tmp_929 , s_y_tmp17 );
                share * s_y_tmp_933 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_934 = 2147483648 ;
                share * s_y__tmp_934 = ycirc->PutCONSGate( _tmp_934 ,bitlen);
                share * s_y_tmp_932 = ycirc->PutGTGate( s_y__tmp_934 , s_y_tmp_933 );
                share * s_y_tmp_936 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec937 = s_y_tmp_936->get_wires();
                _vec937.erase( _vec937.begin(), _vec937.begin() + 1 );
                share *s_y_tmp_935 = create_new_share( _vec937 , ycirc );
                share * s_y_tmp_941 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_942 = 4294967295 ;
                share * s_y__tmp_942 = ycirc->PutCONSGate( _tmp_942 ,bitlen);
                share * s_y_tmp_940 = ycirc->PutXORGate( s_y_tmp_941 , s_y__tmp_942 );
                vector<uint32_t> _vec943 = s_y_tmp_940->get_wires();
                _vec943.erase( _vec943.begin(), _vec943.begin() + 1 );
                share *s_y_tmp_939 = create_new_share( _vec943 , ycirc );
                uint32_t _tmp_944 = 4294967295 ;
                share * s_y__tmp_944 = ycirc->PutCONSGate( _tmp_944 ,bitlen);
                share * s_y_tmp_938 = ycirc->PutXORGate( s_y_tmp_939 , s_y__tmp_944 );
                share * s_y_tmp_931 = ycirc->PutMUXGate( s_y_tmp_935 , s_y_tmp_938 , s_y_tmp_932 );
                vector<uint32_t> _vec949 = s_y_tmp16->get_wires();
                _vec949.erase( _vec949.begin(), _vec949.begin() + 1 );
                share *s_y_tmp_948 = create_new_share( _vec949 , ycirc );
                share * s_y_tmp_947 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_948 );
                uint32_t _tmp_952 = 1 ;
                share * s_y__tmp_952 = ycirc->PutCONSGate( _tmp_952 ,bitlen);
                share * s_y_tmp_951 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_952 );
                uint32_t _tmp_953 = 1 ;
                share * s_y__tmp_953 = ycirc->PutCONSGate( _tmp_953 ,bitlen);
                share * s_y_tmp_950 = ycirc->PutEQGate( s_y_tmp_951 , s_y__tmp_953 );
                share * s_y_tmp_946 = ycirc->PutANDGate( s_y_tmp_947 , s_y_tmp_950 );
                uint32_t _tmp_956 = 2147483648 ;
                share * s_y__tmp_956 = ycirc->PutCONSGate( _tmp_956 ,bitlen);
                share * s_y_tmp_955 = ycirc->PutGTGate( s_y__tmp_956 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec958 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec958.erase( _vec958.begin(), _vec958.begin() + 1 );
                share *s_y_tmp_957 = create_new_share( _vec958 , ycirc );
                uint32_t _tmp_962 = 4294967295 ;
                share * s_y__tmp_962 = ycirc->PutCONSGate( _tmp_962 ,bitlen);
                share * s_y_tmp_961 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_962 );
                vector<uint32_t> _vec963 = s_y_tmp_961->get_wires();
                _vec963.erase( _vec963.begin(), _vec963.begin() + 1 );
                share *s_y_tmp_960 = create_new_share( _vec963 , ycirc );
                uint32_t _tmp_964 = 4294967295 ;
                share * s_y__tmp_964 = ycirc->PutCONSGate( _tmp_964 ,bitlen);
                share * s_y_tmp_959 = ycirc->PutXORGate( s_y_tmp_960 , s_y__tmp_964 );
                share * s_y_tmp_954 = ycirc->PutMUXGate( s_y_tmp_957 , s_y_tmp_959 , s_y_tmp_955 );
                uint32_t _tmp_965 = 0 ;
                share * s_y__tmp_965 = ycirc->PutCONSGate( _tmp_965 ,bitlen);
                share * s_y_tmp_945 = ycirc->PutMUXGate( s_y_tmp_954 , s_y__tmp_965 , s_y_tmp_946 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_931 , s_y_tmp_945 , s_y_tmp_928 );
                uint32_t _tmp_966 = 1 ;
                share * s_y__tmp_966 = ycirc->PutCONSGate( _tmp_966 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_966 );
            }
            uint32_t _tmp_968 = 1 ;
            share * s_y__tmp_968 = ycirc->PutCONSGate( _tmp_968 ,bitlen);
            share * s_y_tmp_967 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_968 );
            vector<uint32_t> _vec969 = s_y_tmp_967->get_wires();
            _vec969.erase( _vec969.begin(), _vec969.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec969 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec972 = s_y_tmp16->get_wires();
                _vec972.erase( _vec972.begin(), _vec972.begin() + 1 );
                share *s_y_tmp_971 = create_new_share( _vec972 , ycirc );
                share * s_y_tmp_970 = ycirc->PutGTGate( s_y_tmp_971 , s_y_tmp17 );
                share * s_y_tmp_973 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec978 = s_y_tmp16->get_wires();
                _vec978.erase( _vec978.begin(), _vec978.begin() + 1 );
                share *s_y_tmp_977 = create_new_share( _vec978 , ycirc );
                share * s_y_tmp_976 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_977 );
                uint32_t _tmp_981 = 1 ;
                share * s_y__tmp_981 = ycirc->PutCONSGate( _tmp_981 ,bitlen);
                share * s_y_tmp_980 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_981 );
                uint32_t _tmp_982 = 1 ;
                share * s_y__tmp_982 = ycirc->PutCONSGate( _tmp_982 ,bitlen);
                share * s_y_tmp_979 = ycirc->PutEQGate( s_y_tmp_980 , s_y__tmp_982 );
                share * s_y_tmp_975 = ycirc->PutANDGate( s_y_tmp_976 , s_y_tmp_979 );
                uint32_t _tmp_983 = 0 ;
                share * s_y__tmp_983 = ycirc->PutCONSGate( _tmp_983 ,bitlen);
                share * s_y_tmp_974 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_983 , s_y_tmp_975 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_973 , s_y_tmp_974 , s_y_tmp_970 );
                uint32_t _tmp_984 = 1 ;
                share * s_y__tmp_984 = ycirc->PutCONSGate( _tmp_984 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_984 );
            }
            uint32_t _tmp_986 = 1 ;
            share * s_y__tmp_986 = ycirc->PutCONSGate( _tmp_986 ,bitlen);
            share * s_y_tmp_985 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_986 );
            vector<uint32_t> _vec987 = s_y_tmp_985->get_wires();
            _vec987.erase( _vec987.begin(), _vec987.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec987 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_989 = 2147483648 ;
share * s_y__tmp_989 = ycirc->PutCONSGate( _tmp_989 ,bitlen);
share * s_y_tmp_988 = ycirc->PutGTGate( s_y__tmp_989 , s_y_tmp10 );
vector<uint32_t> _vec991 = s_y_tmp10->get_wires();
_vec991.erase( _vec991.begin(), _vec991.begin() + 15 );
share *s_y_tmp_990 = create_new_share( _vec991 , ycirc );
uint32_t _tmp_995 = 4294967295 ;
share * s_y__tmp_995 = ycirc->PutCONSGate( _tmp_995 ,bitlen);
share * s_y_tmp_994 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_995 );
vector<uint32_t> _vec996 = s_y_tmp_994->get_wires();
_vec996.erase( _vec996.begin(), _vec996.begin() + 15 );
share *s_y_tmp_993 = create_new_share( _vec996 , ycirc );
uint32_t _tmp_997 = 4294967295 ;
share * s_y__tmp_997 = ycirc->PutCONSGate( _tmp_997 ,bitlen);
share * s_y_tmp_992 = ycirc->PutXORGate( s_y_tmp_993 , s_y__tmp_997 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_990 , s_y_tmp_992 , s_y_tmp_988 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_999 = 2147483648 ;
        share * s_y__tmp_999 = ycirc->PutCONSGate( _tmp_999 ,bitlen);
        share * s_y_tmp_998 = ycirc->PutGTGate( s_y__tmp_999 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec1001 = s_y_tmp12[i14][i15]->get_wires();
        _vec1001.erase( _vec1001.begin(), _vec1001.begin() + 15 );
        share *s_y_tmp_1000 = create_new_share( _vec1001 , ycirc );
        uint32_t _tmp_1005 = 4294967295 ;
        share * s_y__tmp_1005 = ycirc->PutCONSGate( _tmp_1005 ,bitlen);
        share * s_y_tmp_1004 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_1005 );
        vector<uint32_t> _vec1006 = s_y_tmp_1004->get_wires();
        _vec1006.erase( _vec1006.begin(), _vec1006.begin() + 15 );
        share *s_y_tmp_1003 = create_new_share( _vec1006 , ycirc );
        uint32_t _tmp_1007 = 4294967295 ;
        share * s_y__tmp_1007 = ycirc->PutCONSGate( _tmp_1007 ,bitlen);
        share * s_y_tmp_1002 = ycirc->PutXORGate( s_y_tmp_1003 , s_y__tmp_1007 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_1000 , s_y_tmp_1002 , s_y_tmp_998 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_1009 = 2147483648 ;
        share * s_y__tmp_1009 = ycirc->PutCONSGate( _tmp_1009 ,bitlen);
        share * s_y_tmp_1008 = ycirc->PutGTGate( s_y__tmp_1009 , s_y_ZZ[3][i16][i17] );
        vector<uint32_t> _vec1011 = s_y_ZZ[3][i16][i17]->get_wires();
        _vec1011.erase( _vec1011.begin(), _vec1011.begin() + 15 );
        share *s_y_tmp_1010 = create_new_share( _vec1011 , ycirc );
        uint32_t _tmp_1015 = 4294967295 ;
        share * s_y__tmp_1015 = ycirc->PutCONSGate( _tmp_1015 ,bitlen);
        share * s_y_tmp_1014 = ycirc->PutXORGate( s_y_ZZ[3][i16][i17] , s_y__tmp_1015 );
        vector<uint32_t> _vec1016 = s_y_tmp_1014->get_wires();
        _vec1016.erase( _vec1016.begin(), _vec1016.begin() + 15 );
        share *s_y_tmp_1013 = create_new_share( _vec1016 , ycirc );
        uint32_t _tmp_1017 = 4294967295 ;
        share * s_y__tmp_1017 = ycirc->PutCONSGate( _tmp_1017 ,bitlen);
        share * s_y_tmp_1012 = ycirc->PutXORGate( s_y_tmp_1013 , s_y__tmp_1017 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_1010 , s_y_tmp_1012 , s_y_tmp_1008 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_1019 = 2147483648 ;
        share * s_y__tmp_1019 = ycirc->PutCONSGate( _tmp_1019 ,bitlen);
        share * s_y_tmp_1018 = ycirc->PutGTGate( s_y__tmp_1019 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec1021 = s_y_tmp21[i17][i18]->get_wires();
        _vec1021.erase( _vec1021.begin(), _vec1021.begin() + 15 );
        share *s_y_tmp_1020 = create_new_share( _vec1021 , ycirc );
        uint32_t _tmp_1025 = 4294967295 ;
        share * s_y__tmp_1025 = ycirc->PutCONSGate( _tmp_1025 ,bitlen);
        share * s_y_tmp_1024 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_1025 );
        vector<uint32_t> _vec1026 = s_y_tmp_1024->get_wires();
        _vec1026.erase( _vec1026.begin(), _vec1026.begin() + 15 );
        share *s_y_tmp_1023 = create_new_share( _vec1026 , ycirc );
        uint32_t _tmp_1027 = 4294967295 ;
        share * s_y__tmp_1027 = ycirc->PutCONSGate( _tmp_1027 ,bitlen);
        share * s_y_tmp_1022 = ycirc->PutXORGate( s_y_tmp_1023 , s_y__tmp_1027 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_1020 , s_y_tmp_1022 , s_y_tmp_1018 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1030 = s_y_tmp28->get_wires();
                _vec1030.erase( _vec1030.begin(), _vec1030.begin() + 1 );
                share *s_y_tmp_1029 = create_new_share( _vec1030 , ycirc );
                share * s_y_tmp_1028 = ycirc->PutGTGate( s_y_tmp_1029 , s_y_tmp29 );
                share * s_y_tmp_1033 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1034 = 2147483648 ;
                share * s_y__tmp_1034 = ycirc->PutCONSGate( _tmp_1034 ,bitlen);
                share * s_y_tmp_1032 = ycirc->PutGTGate( s_y__tmp_1034 , s_y_tmp_1033 );
                share * s_y_tmp_1036 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1037 = s_y_tmp_1036->get_wires();
                _vec1037.erase( _vec1037.begin(), _vec1037.begin() + 1 );
                share *s_y_tmp_1035 = create_new_share( _vec1037 , ycirc );
                share * s_y_tmp_1041 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1042 = 4294967295 ;
                share * s_y__tmp_1042 = ycirc->PutCONSGate( _tmp_1042 ,bitlen);
                share * s_y_tmp_1040 = ycirc->PutXORGate( s_y_tmp_1041 , s_y__tmp_1042 );
                vector<uint32_t> _vec1043 = s_y_tmp_1040->get_wires();
                _vec1043.erase( _vec1043.begin(), _vec1043.begin() + 1 );
                share *s_y_tmp_1039 = create_new_share( _vec1043 , ycirc );
                uint32_t _tmp_1044 = 4294967295 ;
                share * s_y__tmp_1044 = ycirc->PutCONSGate( _tmp_1044 ,bitlen);
                share * s_y_tmp_1038 = ycirc->PutXORGate( s_y_tmp_1039 , s_y__tmp_1044 );
                share * s_y_tmp_1031 = ycirc->PutMUXGate( s_y_tmp_1035 , s_y_tmp_1038 , s_y_tmp_1032 );
                vector<uint32_t> _vec1049 = s_y_tmp28->get_wires();
                _vec1049.erase( _vec1049.begin(), _vec1049.begin() + 1 );
                share *s_y_tmp_1048 = create_new_share( _vec1049 , ycirc );
                share * s_y_tmp_1047 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1048 );
                uint32_t _tmp_1052 = 1 ;
                share * s_y__tmp_1052 = ycirc->PutCONSGate( _tmp_1052 ,bitlen);
                share * s_y_tmp_1051 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1052 );
                uint32_t _tmp_1053 = 1 ;
                share * s_y__tmp_1053 = ycirc->PutCONSGate( _tmp_1053 ,bitlen);
                share * s_y_tmp_1050 = ycirc->PutEQGate( s_y_tmp_1051 , s_y__tmp_1053 );
                share * s_y_tmp_1046 = ycirc->PutANDGate( s_y_tmp_1047 , s_y_tmp_1050 );
                uint32_t _tmp_1056 = 2147483648 ;
                share * s_y__tmp_1056 = ycirc->PutCONSGate( _tmp_1056 ,bitlen);
                share * s_y_tmp_1055 = ycirc->PutGTGate( s_y__tmp_1056 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec1058 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec1058.erase( _vec1058.begin(), _vec1058.begin() + 1 );
                share *s_y_tmp_1057 = create_new_share( _vec1058 , ycirc );
                uint32_t _tmp_1062 = 4294967295 ;
                share * s_y__tmp_1062 = ycirc->PutCONSGate( _tmp_1062 ,bitlen);
                share * s_y_tmp_1061 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1062 );
                vector<uint32_t> _vec1063 = s_y_tmp_1061->get_wires();
                _vec1063.erase( _vec1063.begin(), _vec1063.begin() + 1 );
                share *s_y_tmp_1060 = create_new_share( _vec1063 , ycirc );
                uint32_t _tmp_1064 = 4294967295 ;
                share * s_y__tmp_1064 = ycirc->PutCONSGate( _tmp_1064 ,bitlen);
                share * s_y_tmp_1059 = ycirc->PutXORGate( s_y_tmp_1060 , s_y__tmp_1064 );
                share * s_y_tmp_1054 = ycirc->PutMUXGate( s_y_tmp_1057 , s_y_tmp_1059 , s_y_tmp_1055 );
                uint32_t _tmp_1065 = 0 ;
                share * s_y__tmp_1065 = ycirc->PutCONSGate( _tmp_1065 ,bitlen);
                share * s_y_tmp_1045 = ycirc->PutMUXGate( s_y_tmp_1054 , s_y__tmp_1065 , s_y_tmp_1046 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1031 , s_y_tmp_1045 , s_y_tmp_1028 );
                uint32_t _tmp_1066 = 1 ;
                share * s_y__tmp_1066 = ycirc->PutCONSGate( _tmp_1066 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1066 );
            }
            uint32_t _tmp_1068 = 1 ;
            share * s_y__tmp_1068 = ycirc->PutCONSGate( _tmp_1068 ,bitlen);
            share * s_y_tmp_1067 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1068 );
            vector<uint32_t> _vec1069 = s_y_tmp_1067->get_wires();
            _vec1069.erase( _vec1069.begin(), _vec1069.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1069 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1072 = s_y_tmp28->get_wires();
                _vec1072.erase( _vec1072.begin(), _vec1072.begin() + 1 );
                share *s_y_tmp_1071 = create_new_share( _vec1072 , ycirc );
                share * s_y_tmp_1070 = ycirc->PutGTGate( s_y_tmp_1071 , s_y_tmp29 );
                share * s_y_tmp_1073 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1078 = s_y_tmp28->get_wires();
                _vec1078.erase( _vec1078.begin(), _vec1078.begin() + 1 );
                share *s_y_tmp_1077 = create_new_share( _vec1078 , ycirc );
                share * s_y_tmp_1076 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1077 );
                uint32_t _tmp_1081 = 1 ;
                share * s_y__tmp_1081 = ycirc->PutCONSGate( _tmp_1081 ,bitlen);
                share * s_y_tmp_1080 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1081 );
                uint32_t _tmp_1082 = 1 ;
                share * s_y__tmp_1082 = ycirc->PutCONSGate( _tmp_1082 ,bitlen);
                share * s_y_tmp_1079 = ycirc->PutEQGate( s_y_tmp_1080 , s_y__tmp_1082 );
                share * s_y_tmp_1075 = ycirc->PutANDGate( s_y_tmp_1076 , s_y_tmp_1079 );
                uint32_t _tmp_1083 = 0 ;
                share * s_y__tmp_1083 = ycirc->PutCONSGate( _tmp_1083 ,bitlen);
                share * s_y_tmp_1074 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1083 , s_y_tmp_1075 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1073 , s_y_tmp_1074 , s_y_tmp_1070 );
                uint32_t _tmp_1084 = 1 ;
                share * s_y__tmp_1084 = ycirc->PutCONSGate( _tmp_1084 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1084 );
            }
            uint32_t _tmp_1086 = 1 ;
            share * s_y__tmp_1086 = ycirc->PutCONSGate( _tmp_1086 ,bitlen);
            share * s_y_tmp_1085 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1086 );
            vector<uint32_t> _vec1087 = s_y_tmp_1085->get_wires();
            _vec1087.erase( _vec1087.begin(), _vec1087.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1087 , ycirc );
        }
        s_y_tmp31[3][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_1089 = 2147483648 ;
        share * s_y__tmp_1089 = ycirc->PutCONSGate( _tmp_1089 ,bitlen);
        share * s_y_tmp_1088 = ycirc->PutGTGate( s_y__tmp_1089 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec1091 = s_y_WW[i0][i1]->get_wires();
        _vec1091.erase( _vec1091.begin(), _vec1091.begin() + 15 );
        share *s_y_tmp_1090 = create_new_share( _vec1091 , ycirc );
        uint32_t _tmp_1095 = 4294967295 ;
        share * s_y__tmp_1095 = ycirc->PutCONSGate( _tmp_1095 ,bitlen);
        share * s_y_tmp_1094 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_1095 );
        vector<uint32_t> _vec1096 = s_y_tmp_1094->get_wires();
        _vec1096.erase( _vec1096.begin(), _vec1096.begin() + 15 );
        share *s_y_tmp_1093 = create_new_share( _vec1096 , ycirc );
        uint32_t _tmp_1097 = 4294967295 ;
        share * s_y__tmp_1097 = ycirc->PutCONSGate( _tmp_1097 ,bitlen);
        share * s_y_tmp_1092 = ycirc->PutXORGate( s_y_tmp_1093 , s_y__tmp_1097 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_1090 , s_y_tmp_1092 , s_y_tmp_1088 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_1099 = 2147483648 ;
        share * s_y__tmp_1099 = ycirc->PutCONSGate( _tmp_1099 ,bitlen);
        share * s_y_tmp_1098 = ycirc->PutGTGate( s_y__tmp_1099 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec1101 = s_y_xx[i1][i2]->get_wires();
        _vec1101.erase( _vec1101.begin(), _vec1101.begin() + 15 );
        share *s_y_tmp_1100 = create_new_share( _vec1101 , ycirc );
        uint32_t _tmp_1105 = 4294967295 ;
        share * s_y__tmp_1105 = ycirc->PutCONSGate( _tmp_1105 ,bitlen);
        share * s_y_tmp_1104 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_1105 );
        vector<uint32_t> _vec1106 = s_y_tmp_1104->get_wires();
        _vec1106.erase( _vec1106.begin(), _vec1106.begin() + 15 );
        share *s_y_tmp_1103 = create_new_share( _vec1106 , ycirc );
        uint32_t _tmp_1107 = 4294967295 ;
        share * s_y__tmp_1107 = ycirc->PutCONSGate( _tmp_1107 ,bitlen);
        share * s_y_tmp_1102 = ycirc->PutXORGate( s_y_tmp_1103 , s_y__tmp_1107 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_1100 , s_y_tmp_1102 , s_y_tmp_1098 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1110 = s_y_tmp5->get_wires();
                _vec1110.erase( _vec1110.begin(), _vec1110.begin() + 1 );
                share *s_y_tmp_1109 = create_new_share( _vec1110 , ycirc );
                share * s_y_tmp_1108 = ycirc->PutGTGate( s_y_tmp_1109 , s_y_tmp6 );
                share * s_y_tmp_1113 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1114 = 2147483648 ;
                share * s_y__tmp_1114 = ycirc->PutCONSGate( _tmp_1114 ,bitlen);
                share * s_y_tmp_1112 = ycirc->PutGTGate( s_y__tmp_1114 , s_y_tmp_1113 );
                share * s_y_tmp_1116 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1117 = s_y_tmp_1116->get_wires();
                _vec1117.erase( _vec1117.begin(), _vec1117.begin() + 1 );
                share *s_y_tmp_1115 = create_new_share( _vec1117 , ycirc );
                share * s_y_tmp_1121 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1122 = 4294967295 ;
                share * s_y__tmp_1122 = ycirc->PutCONSGate( _tmp_1122 ,bitlen);
                share * s_y_tmp_1120 = ycirc->PutXORGate( s_y_tmp_1121 , s_y__tmp_1122 );
                vector<uint32_t> _vec1123 = s_y_tmp_1120->get_wires();
                _vec1123.erase( _vec1123.begin(), _vec1123.begin() + 1 );
                share *s_y_tmp_1119 = create_new_share( _vec1123 , ycirc );
                uint32_t _tmp_1124 = 4294967295 ;
                share * s_y__tmp_1124 = ycirc->PutCONSGate( _tmp_1124 ,bitlen);
                share * s_y_tmp_1118 = ycirc->PutXORGate( s_y_tmp_1119 , s_y__tmp_1124 );
                share * s_y_tmp_1111 = ycirc->PutMUXGate( s_y_tmp_1115 , s_y_tmp_1118 , s_y_tmp_1112 );
                vector<uint32_t> _vec1129 = s_y_tmp5->get_wires();
                _vec1129.erase( _vec1129.begin(), _vec1129.begin() + 1 );
                share *s_y_tmp_1128 = create_new_share( _vec1129 , ycirc );
                share * s_y_tmp_1127 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1128 );
                uint32_t _tmp_1132 = 1 ;
                share * s_y__tmp_1132 = ycirc->PutCONSGate( _tmp_1132 ,bitlen);
                share * s_y_tmp_1131 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1132 );
                uint32_t _tmp_1133 = 1 ;
                share * s_y__tmp_1133 = ycirc->PutCONSGate( _tmp_1133 ,bitlen);
                share * s_y_tmp_1130 = ycirc->PutEQGate( s_y_tmp_1131 , s_y__tmp_1133 );
                share * s_y_tmp_1126 = ycirc->PutANDGate( s_y_tmp_1127 , s_y_tmp_1130 );
                uint32_t _tmp_1136 = 2147483648 ;
                share * s_y__tmp_1136 = ycirc->PutCONSGate( _tmp_1136 ,bitlen);
                share * s_y_tmp_1135 = ycirc->PutGTGate( s_y__tmp_1136 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec1138 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec1138.erase( _vec1138.begin(), _vec1138.begin() + 1 );
                share *s_y_tmp_1137 = create_new_share( _vec1138 , ycirc );
                uint32_t _tmp_1142 = 4294967295 ;
                share * s_y__tmp_1142 = ycirc->PutCONSGate( _tmp_1142 ,bitlen);
                share * s_y_tmp_1141 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1142 );
                vector<uint32_t> _vec1143 = s_y_tmp_1141->get_wires();
                _vec1143.erase( _vec1143.begin(), _vec1143.begin() + 1 );
                share *s_y_tmp_1140 = create_new_share( _vec1143 , ycirc );
                uint32_t _tmp_1144 = 4294967295 ;
                share * s_y__tmp_1144 = ycirc->PutCONSGate( _tmp_1144 ,bitlen);
                share * s_y_tmp_1139 = ycirc->PutXORGate( s_y_tmp_1140 , s_y__tmp_1144 );
                share * s_y_tmp_1134 = ycirc->PutMUXGate( s_y_tmp_1137 , s_y_tmp_1139 , s_y_tmp_1135 );
                uint32_t _tmp_1145 = 0 ;
                share * s_y__tmp_1145 = ycirc->PutCONSGate( _tmp_1145 ,bitlen);
                share * s_y_tmp_1125 = ycirc->PutMUXGate( s_y_tmp_1134 , s_y__tmp_1145 , s_y_tmp_1126 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1111 , s_y_tmp_1125 , s_y_tmp_1108 );
                uint32_t _tmp_1146 = 1 ;
                share * s_y__tmp_1146 = ycirc->PutCONSGate( _tmp_1146 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1146 );
            }
            uint32_t _tmp_1148 = 1 ;
            share * s_y__tmp_1148 = ycirc->PutCONSGate( _tmp_1148 ,bitlen);
            share * s_y_tmp_1147 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1148 );
            vector<uint32_t> _vec1149 = s_y_tmp_1147->get_wires();
            _vec1149.erase( _vec1149.begin(), _vec1149.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1149 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1152 = s_y_tmp5->get_wires();
                _vec1152.erase( _vec1152.begin(), _vec1152.begin() + 1 );
                share *s_y_tmp_1151 = create_new_share( _vec1152 , ycirc );
                share * s_y_tmp_1150 = ycirc->PutGTGate( s_y_tmp_1151 , s_y_tmp6 );
                share * s_y_tmp_1153 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1158 = s_y_tmp5->get_wires();
                _vec1158.erase( _vec1158.begin(), _vec1158.begin() + 1 );
                share *s_y_tmp_1157 = create_new_share( _vec1158 , ycirc );
                share * s_y_tmp_1156 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1157 );
                uint32_t _tmp_1161 = 1 ;
                share * s_y__tmp_1161 = ycirc->PutCONSGate( _tmp_1161 ,bitlen);
                share * s_y_tmp_1160 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1161 );
                uint32_t _tmp_1162 = 1 ;
                share * s_y__tmp_1162 = ycirc->PutCONSGate( _tmp_1162 ,bitlen);
                share * s_y_tmp_1159 = ycirc->PutEQGate( s_y_tmp_1160 , s_y__tmp_1162 );
                share * s_y_tmp_1155 = ycirc->PutANDGate( s_y_tmp_1156 , s_y_tmp_1159 );
                uint32_t _tmp_1163 = 0 ;
                share * s_y__tmp_1163 = ycirc->PutCONSGate( _tmp_1163 ,bitlen);
                share * s_y_tmp_1154 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1163 , s_y_tmp_1155 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1153 , s_y_tmp_1154 , s_y_tmp_1150 );
                uint32_t _tmp_1164 = 1 ;
                share * s_y__tmp_1164 = ycirc->PutCONSGate( _tmp_1164 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1164 );
            }
            uint32_t _tmp_1166 = 1 ;
            share * s_y__tmp_1166 = ycirc->PutCONSGate( _tmp_1166 ,bitlen);
            share * s_y_tmp_1165 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1166 );
            vector<uint32_t> _vec1167 = s_y_tmp_1165->get_wires();
            _vec1167.erase( _vec1167.begin(), _vec1167.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1167 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_1169 = 2147483648 ;
        share * s_y__tmp_1169 = ycirc->PutCONSGate( _tmp_1169 ,bitlen);
        share * s_y_tmp_1168 = ycirc->PutGTGate( s_y__tmp_1169 , s_y_BB[4][i5][i6] );
        vector<uint32_t> _vec1171 = s_y_BB[4][i5][i6]->get_wires();
        _vec1171.erase( _vec1171.begin(), _vec1171.begin() + 4 );
        share *s_y_tmp_1170 = create_new_share( _vec1171 , ycirc );
        uint32_t _tmp_1175 = 4294967295 ;
        share * s_y__tmp_1175 = ycirc->PutCONSGate( _tmp_1175 ,bitlen);
        share * s_y_tmp_1174 = ycirc->PutXORGate( s_y_BB[4][i5][i6] , s_y__tmp_1175 );
        vector<uint32_t> _vec1176 = s_y_tmp_1174->get_wires();
        _vec1176.erase( _vec1176.begin(), _vec1176.begin() + 4 );
        share *s_y_tmp_1173 = create_new_share( _vec1176 , ycirc );
        uint32_t _tmp_1177 = 4294967295 ;
        share * s_y__tmp_1177 = ycirc->PutCONSGate( _tmp_1177 ,bitlen);
        share * s_y_tmp_1172 = ycirc->PutXORGate( s_y_tmp_1173 , s_y__tmp_1177 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_1170 , s_y_tmp_1172 , s_y_tmp_1168 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_1178 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_1179 = 1 ;
share * s_a__tmp_1179 = acirc->PutCONSGate( _tmp_1179 ,bitlen);
share *s_a_tmp_1178 = acirc->PutY2AGate( s_y_tmp_1178 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_1178 , s_a__tmp_1179 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_1181 = 2147483648 ;
        share * s_y__tmp_1181 = ycirc->PutCONSGate( _tmp_1181 ,bitlen);
        share * s_y_tmp_1180 = ycirc->PutGTGate( s_y__tmp_1181 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec1183 = s_y_tmp11[i9][i10]->get_wires();
        _vec1183.erase( _vec1183.begin(), _vec1183.begin() + 15 );
        share *s_y_tmp_1182 = create_new_share( _vec1183 , ycirc );
        uint32_t _tmp_1187 = 4294967295 ;
        share * s_y__tmp_1187 = ycirc->PutCONSGate( _tmp_1187 ,bitlen);
        share * s_y_tmp_1186 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_1187 );
        vector<uint32_t> _vec1188 = s_y_tmp_1186->get_wires();
        _vec1188.erase( _vec1188.begin(), _vec1188.begin() + 15 );
        share *s_y_tmp_1185 = create_new_share( _vec1188 , ycirc );
        uint32_t _tmp_1189 = 4294967295 ;
        share * s_y__tmp_1189 = ycirc->PutCONSGate( _tmp_1189 ,bitlen);
        share * s_y_tmp_1184 = ycirc->PutXORGate( s_y_tmp_1185 , s_y__tmp_1189 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_1182 , s_y_tmp_1184 , s_y_tmp_1180 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_1191 = 2147483648 ;
        share * s_y__tmp_1191 = ycirc->PutCONSGate( _tmp_1191 ,bitlen);
        share * s_y_tmp_1190 = ycirc->PutGTGate( s_y__tmp_1191 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec1193 = s_y_tmp7[i10][i11]->get_wires();
        _vec1193.erase( _vec1193.begin(), _vec1193.begin() + 15 );
        share *s_y_tmp_1192 = create_new_share( _vec1193 , ycirc );
        uint32_t _tmp_1197 = 4294967295 ;
        share * s_y__tmp_1197 = ycirc->PutCONSGate( _tmp_1197 ,bitlen);
        share * s_y_tmp_1196 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_1197 );
        vector<uint32_t> _vec1198 = s_y_tmp_1196->get_wires();
        _vec1198.erase( _vec1198.begin(), _vec1198.begin() + 15 );
        share *s_y_tmp_1195 = create_new_share( _vec1198 , ycirc );
        uint32_t _tmp_1199 = 4294967295 ;
        share * s_y__tmp_1199 = ycirc->PutCONSGate( _tmp_1199 ,bitlen);
        share * s_y_tmp_1194 = ycirc->PutXORGate( s_y_tmp_1195 , s_y__tmp_1199 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_1192 , s_y_tmp_1194 , s_y_tmp_1190 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec1202 = s_y_tmp16->get_wires();
                _vec1202.erase( _vec1202.begin(), _vec1202.begin() + 1 );
                share *s_y_tmp_1201 = create_new_share( _vec1202 , ycirc );
                share * s_y_tmp_1200 = ycirc->PutGTGate( s_y_tmp_1201 , s_y_tmp17 );
                share * s_y_tmp_1205 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_1206 = 2147483648 ;
                share * s_y__tmp_1206 = ycirc->PutCONSGate( _tmp_1206 ,bitlen);
                share * s_y_tmp_1204 = ycirc->PutGTGate( s_y__tmp_1206 , s_y_tmp_1205 );
                share * s_y_tmp_1208 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec1209 = s_y_tmp_1208->get_wires();
                _vec1209.erase( _vec1209.begin(), _vec1209.begin() + 1 );
                share *s_y_tmp_1207 = create_new_share( _vec1209 , ycirc );
                share * s_y_tmp_1213 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_1214 = 4294967295 ;
                share * s_y__tmp_1214 = ycirc->PutCONSGate( _tmp_1214 ,bitlen);
                share * s_y_tmp_1212 = ycirc->PutXORGate( s_y_tmp_1213 , s_y__tmp_1214 );
                vector<uint32_t> _vec1215 = s_y_tmp_1212->get_wires();
                _vec1215.erase( _vec1215.begin(), _vec1215.begin() + 1 );
                share *s_y_tmp_1211 = create_new_share( _vec1215 , ycirc );
                uint32_t _tmp_1216 = 4294967295 ;
                share * s_y__tmp_1216 = ycirc->PutCONSGate( _tmp_1216 ,bitlen);
                share * s_y_tmp_1210 = ycirc->PutXORGate( s_y_tmp_1211 , s_y__tmp_1216 );
                share * s_y_tmp_1203 = ycirc->PutMUXGate( s_y_tmp_1207 , s_y_tmp_1210 , s_y_tmp_1204 );
                vector<uint32_t> _vec1221 = s_y_tmp16->get_wires();
                _vec1221.erase( _vec1221.begin(), _vec1221.begin() + 1 );
                share *s_y_tmp_1220 = create_new_share( _vec1221 , ycirc );
                share * s_y_tmp_1219 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_1220 );
                uint32_t _tmp_1224 = 1 ;
                share * s_y__tmp_1224 = ycirc->PutCONSGate( _tmp_1224 ,bitlen);
                share * s_y_tmp_1223 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_1224 );
                uint32_t _tmp_1225 = 1 ;
                share * s_y__tmp_1225 = ycirc->PutCONSGate( _tmp_1225 ,bitlen);
                share * s_y_tmp_1222 = ycirc->PutEQGate( s_y_tmp_1223 , s_y__tmp_1225 );
                share * s_y_tmp_1218 = ycirc->PutANDGate( s_y_tmp_1219 , s_y_tmp_1222 );
                uint32_t _tmp_1228 = 2147483648 ;
                share * s_y__tmp_1228 = ycirc->PutCONSGate( _tmp_1228 ,bitlen);
                share * s_y_tmp_1227 = ycirc->PutGTGate( s_y__tmp_1228 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec1230 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec1230.erase( _vec1230.begin(), _vec1230.begin() + 1 );
                share *s_y_tmp_1229 = create_new_share( _vec1230 , ycirc );
                uint32_t _tmp_1234 = 4294967295 ;
                share * s_y__tmp_1234 = ycirc->PutCONSGate( _tmp_1234 ,bitlen);
                share * s_y_tmp_1233 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_1234 );
                vector<uint32_t> _vec1235 = s_y_tmp_1233->get_wires();
                _vec1235.erase( _vec1235.begin(), _vec1235.begin() + 1 );
                share *s_y_tmp_1232 = create_new_share( _vec1235 , ycirc );
                uint32_t _tmp_1236 = 4294967295 ;
                share * s_y__tmp_1236 = ycirc->PutCONSGate( _tmp_1236 ,bitlen);
                share * s_y_tmp_1231 = ycirc->PutXORGate( s_y_tmp_1232 , s_y__tmp_1236 );
                share * s_y_tmp_1226 = ycirc->PutMUXGate( s_y_tmp_1229 , s_y_tmp_1231 , s_y_tmp_1227 );
                uint32_t _tmp_1237 = 0 ;
                share * s_y__tmp_1237 = ycirc->PutCONSGate( _tmp_1237 ,bitlen);
                share * s_y_tmp_1217 = ycirc->PutMUXGate( s_y_tmp_1226 , s_y__tmp_1237 , s_y_tmp_1218 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_1203 , s_y_tmp_1217 , s_y_tmp_1200 );
                uint32_t _tmp_1238 = 1 ;
                share * s_y__tmp_1238 = ycirc->PutCONSGate( _tmp_1238 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_1238 );
            }
            uint32_t _tmp_1240 = 1 ;
            share * s_y__tmp_1240 = ycirc->PutCONSGate( _tmp_1240 ,bitlen);
            share * s_y_tmp_1239 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_1240 );
            vector<uint32_t> _vec1241 = s_y_tmp_1239->get_wires();
            _vec1241.erase( _vec1241.begin(), _vec1241.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec1241 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec1244 = s_y_tmp16->get_wires();
                _vec1244.erase( _vec1244.begin(), _vec1244.begin() + 1 );
                share *s_y_tmp_1243 = create_new_share( _vec1244 , ycirc );
                share * s_y_tmp_1242 = ycirc->PutGTGate( s_y_tmp_1243 , s_y_tmp17 );
                share * s_y_tmp_1245 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec1250 = s_y_tmp16->get_wires();
                _vec1250.erase( _vec1250.begin(), _vec1250.begin() + 1 );
                share *s_y_tmp_1249 = create_new_share( _vec1250 , ycirc );
                share * s_y_tmp_1248 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_1249 );
                uint32_t _tmp_1253 = 1 ;
                share * s_y__tmp_1253 = ycirc->PutCONSGate( _tmp_1253 ,bitlen);
                share * s_y_tmp_1252 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_1253 );
                uint32_t _tmp_1254 = 1 ;
                share * s_y__tmp_1254 = ycirc->PutCONSGate( _tmp_1254 ,bitlen);
                share * s_y_tmp_1251 = ycirc->PutEQGate( s_y_tmp_1252 , s_y__tmp_1254 );
                share * s_y_tmp_1247 = ycirc->PutANDGate( s_y_tmp_1248 , s_y_tmp_1251 );
                uint32_t _tmp_1255 = 0 ;
                share * s_y__tmp_1255 = ycirc->PutCONSGate( _tmp_1255 ,bitlen);
                share * s_y_tmp_1246 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_1255 , s_y_tmp_1247 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_1245 , s_y_tmp_1246 , s_y_tmp_1242 );
                uint32_t _tmp_1256 = 1 ;
                share * s_y__tmp_1256 = ycirc->PutCONSGate( _tmp_1256 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_1256 );
            }
            uint32_t _tmp_1258 = 1 ;
            share * s_y__tmp_1258 = ycirc->PutCONSGate( _tmp_1258 ,bitlen);
            share * s_y_tmp_1257 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_1258 );
            vector<uint32_t> _vec1259 = s_y_tmp_1257->get_wires();
            _vec1259.erase( _vec1259.begin(), _vec1259.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec1259 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_1261 = 2147483648 ;
share * s_y__tmp_1261 = ycirc->PutCONSGate( _tmp_1261 ,bitlen);
share * s_y_tmp_1260 = ycirc->PutGTGate( s_y__tmp_1261 , s_y_tmp10 );
vector<uint32_t> _vec1263 = s_y_tmp10->get_wires();
_vec1263.erase( _vec1263.begin(), _vec1263.begin() + 15 );
share *s_y_tmp_1262 = create_new_share( _vec1263 , ycirc );
uint32_t _tmp_1267 = 4294967295 ;
share * s_y__tmp_1267 = ycirc->PutCONSGate( _tmp_1267 ,bitlen);
share * s_y_tmp_1266 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_1267 );
vector<uint32_t> _vec1268 = s_y_tmp_1266->get_wires();
_vec1268.erase( _vec1268.begin(), _vec1268.begin() + 15 );
share *s_y_tmp_1265 = create_new_share( _vec1268 , ycirc );
uint32_t _tmp_1269 = 4294967295 ;
share * s_y__tmp_1269 = ycirc->PutCONSGate( _tmp_1269 ,bitlen);
share * s_y_tmp_1264 = ycirc->PutXORGate( s_y_tmp_1265 , s_y__tmp_1269 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_1262 , s_y_tmp_1264 , s_y_tmp_1260 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_1271 = 2147483648 ;
        share * s_y__tmp_1271 = ycirc->PutCONSGate( _tmp_1271 ,bitlen);
        share * s_y_tmp_1270 = ycirc->PutGTGate( s_y__tmp_1271 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec1273 = s_y_tmp12[i14][i15]->get_wires();
        _vec1273.erase( _vec1273.begin(), _vec1273.begin() + 15 );
        share *s_y_tmp_1272 = create_new_share( _vec1273 , ycirc );
        uint32_t _tmp_1277 = 4294967295 ;
        share * s_y__tmp_1277 = ycirc->PutCONSGate( _tmp_1277 ,bitlen);
        share * s_y_tmp_1276 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_1277 );
        vector<uint32_t> _vec1278 = s_y_tmp_1276->get_wires();
        _vec1278.erase( _vec1278.begin(), _vec1278.begin() + 15 );
        share *s_y_tmp_1275 = create_new_share( _vec1278 , ycirc );
        uint32_t _tmp_1279 = 4294967295 ;
        share * s_y__tmp_1279 = ycirc->PutCONSGate( _tmp_1279 ,bitlen);
        share * s_y_tmp_1274 = ycirc->PutXORGate( s_y_tmp_1275 , s_y__tmp_1279 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_1272 , s_y_tmp_1274 , s_y_tmp_1270 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_1281 = 2147483648 ;
        share * s_y__tmp_1281 = ycirc->PutCONSGate( _tmp_1281 ,bitlen);
        share * s_y_tmp_1280 = ycirc->PutGTGate( s_y__tmp_1281 , s_y_ZZ[4][i16][i17] );
        vector<uint32_t> _vec1283 = s_y_ZZ[4][i16][i17]->get_wires();
        _vec1283.erase( _vec1283.begin(), _vec1283.begin() + 15 );
        share *s_y_tmp_1282 = create_new_share( _vec1283 , ycirc );
        uint32_t _tmp_1287 = 4294967295 ;
        share * s_y__tmp_1287 = ycirc->PutCONSGate( _tmp_1287 ,bitlen);
        share * s_y_tmp_1286 = ycirc->PutXORGate( s_y_ZZ[4][i16][i17] , s_y__tmp_1287 );
        vector<uint32_t> _vec1288 = s_y_tmp_1286->get_wires();
        _vec1288.erase( _vec1288.begin(), _vec1288.begin() + 15 );
        share *s_y_tmp_1285 = create_new_share( _vec1288 , ycirc );
        uint32_t _tmp_1289 = 4294967295 ;
        share * s_y__tmp_1289 = ycirc->PutCONSGate( _tmp_1289 ,bitlen);
        share * s_y_tmp_1284 = ycirc->PutXORGate( s_y_tmp_1285 , s_y__tmp_1289 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_1282 , s_y_tmp_1284 , s_y_tmp_1280 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_1291 = 2147483648 ;
        share * s_y__tmp_1291 = ycirc->PutCONSGate( _tmp_1291 ,bitlen);
        share * s_y_tmp_1290 = ycirc->PutGTGate( s_y__tmp_1291 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec1293 = s_y_tmp21[i17][i18]->get_wires();
        _vec1293.erase( _vec1293.begin(), _vec1293.begin() + 15 );
        share *s_y_tmp_1292 = create_new_share( _vec1293 , ycirc );
        uint32_t _tmp_1297 = 4294967295 ;
        share * s_y__tmp_1297 = ycirc->PutCONSGate( _tmp_1297 ,bitlen);
        share * s_y_tmp_1296 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_1297 );
        vector<uint32_t> _vec1298 = s_y_tmp_1296->get_wires();
        _vec1298.erase( _vec1298.begin(), _vec1298.begin() + 15 );
        share *s_y_tmp_1295 = create_new_share( _vec1298 , ycirc );
        uint32_t _tmp_1299 = 4294967295 ;
        share * s_y__tmp_1299 = ycirc->PutCONSGate( _tmp_1299 ,bitlen);
        share * s_y_tmp_1294 = ycirc->PutXORGate( s_y_tmp_1295 , s_y__tmp_1299 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_1292 , s_y_tmp_1294 , s_y_tmp_1290 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1302 = s_y_tmp28->get_wires();
                _vec1302.erase( _vec1302.begin(), _vec1302.begin() + 1 );
                share *s_y_tmp_1301 = create_new_share( _vec1302 , ycirc );
                share * s_y_tmp_1300 = ycirc->PutGTGate( s_y_tmp_1301 , s_y_tmp29 );
                share * s_y_tmp_1305 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1306 = 2147483648 ;
                share * s_y__tmp_1306 = ycirc->PutCONSGate( _tmp_1306 ,bitlen);
                share * s_y_tmp_1304 = ycirc->PutGTGate( s_y__tmp_1306 , s_y_tmp_1305 );
                share * s_y_tmp_1308 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1309 = s_y_tmp_1308->get_wires();
                _vec1309.erase( _vec1309.begin(), _vec1309.begin() + 1 );
                share *s_y_tmp_1307 = create_new_share( _vec1309 , ycirc );
                share * s_y_tmp_1313 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1314 = 4294967295 ;
                share * s_y__tmp_1314 = ycirc->PutCONSGate( _tmp_1314 ,bitlen);
                share * s_y_tmp_1312 = ycirc->PutXORGate( s_y_tmp_1313 , s_y__tmp_1314 );
                vector<uint32_t> _vec1315 = s_y_tmp_1312->get_wires();
                _vec1315.erase( _vec1315.begin(), _vec1315.begin() + 1 );
                share *s_y_tmp_1311 = create_new_share( _vec1315 , ycirc );
                uint32_t _tmp_1316 = 4294967295 ;
                share * s_y__tmp_1316 = ycirc->PutCONSGate( _tmp_1316 ,bitlen);
                share * s_y_tmp_1310 = ycirc->PutXORGate( s_y_tmp_1311 , s_y__tmp_1316 );
                share * s_y_tmp_1303 = ycirc->PutMUXGate( s_y_tmp_1307 , s_y_tmp_1310 , s_y_tmp_1304 );
                vector<uint32_t> _vec1321 = s_y_tmp28->get_wires();
                _vec1321.erase( _vec1321.begin(), _vec1321.begin() + 1 );
                share *s_y_tmp_1320 = create_new_share( _vec1321 , ycirc );
                share * s_y_tmp_1319 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1320 );
                uint32_t _tmp_1324 = 1 ;
                share * s_y__tmp_1324 = ycirc->PutCONSGate( _tmp_1324 ,bitlen);
                share * s_y_tmp_1323 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1324 );
                uint32_t _tmp_1325 = 1 ;
                share * s_y__tmp_1325 = ycirc->PutCONSGate( _tmp_1325 ,bitlen);
                share * s_y_tmp_1322 = ycirc->PutEQGate( s_y_tmp_1323 , s_y__tmp_1325 );
                share * s_y_tmp_1318 = ycirc->PutANDGate( s_y_tmp_1319 , s_y_tmp_1322 );
                uint32_t _tmp_1328 = 2147483648 ;
                share * s_y__tmp_1328 = ycirc->PutCONSGate( _tmp_1328 ,bitlen);
                share * s_y_tmp_1327 = ycirc->PutGTGate( s_y__tmp_1328 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec1330 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec1330.erase( _vec1330.begin(), _vec1330.begin() + 1 );
                share *s_y_tmp_1329 = create_new_share( _vec1330 , ycirc );
                uint32_t _tmp_1334 = 4294967295 ;
                share * s_y__tmp_1334 = ycirc->PutCONSGate( _tmp_1334 ,bitlen);
                share * s_y_tmp_1333 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1334 );
                vector<uint32_t> _vec1335 = s_y_tmp_1333->get_wires();
                _vec1335.erase( _vec1335.begin(), _vec1335.begin() + 1 );
                share *s_y_tmp_1332 = create_new_share( _vec1335 , ycirc );
                uint32_t _tmp_1336 = 4294967295 ;
                share * s_y__tmp_1336 = ycirc->PutCONSGate( _tmp_1336 ,bitlen);
                share * s_y_tmp_1331 = ycirc->PutXORGate( s_y_tmp_1332 , s_y__tmp_1336 );
                share * s_y_tmp_1326 = ycirc->PutMUXGate( s_y_tmp_1329 , s_y_tmp_1331 , s_y_tmp_1327 );
                uint32_t _tmp_1337 = 0 ;
                share * s_y__tmp_1337 = ycirc->PutCONSGate( _tmp_1337 ,bitlen);
                share * s_y_tmp_1317 = ycirc->PutMUXGate( s_y_tmp_1326 , s_y__tmp_1337 , s_y_tmp_1318 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1303 , s_y_tmp_1317 , s_y_tmp_1300 );
                uint32_t _tmp_1338 = 1 ;
                share * s_y__tmp_1338 = ycirc->PutCONSGate( _tmp_1338 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1338 );
            }
            uint32_t _tmp_1340 = 1 ;
            share * s_y__tmp_1340 = ycirc->PutCONSGate( _tmp_1340 ,bitlen);
            share * s_y_tmp_1339 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1340 );
            vector<uint32_t> _vec1341 = s_y_tmp_1339->get_wires();
            _vec1341.erase( _vec1341.begin(), _vec1341.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1341 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1344 = s_y_tmp28->get_wires();
                _vec1344.erase( _vec1344.begin(), _vec1344.begin() + 1 );
                share *s_y_tmp_1343 = create_new_share( _vec1344 , ycirc );
                share * s_y_tmp_1342 = ycirc->PutGTGate( s_y_tmp_1343 , s_y_tmp29 );
                share * s_y_tmp_1345 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1350 = s_y_tmp28->get_wires();
                _vec1350.erase( _vec1350.begin(), _vec1350.begin() + 1 );
                share *s_y_tmp_1349 = create_new_share( _vec1350 , ycirc );
                share * s_y_tmp_1348 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1349 );
                uint32_t _tmp_1353 = 1 ;
                share * s_y__tmp_1353 = ycirc->PutCONSGate( _tmp_1353 ,bitlen);
                share * s_y_tmp_1352 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1353 );
                uint32_t _tmp_1354 = 1 ;
                share * s_y__tmp_1354 = ycirc->PutCONSGate( _tmp_1354 ,bitlen);
                share * s_y_tmp_1351 = ycirc->PutEQGate( s_y_tmp_1352 , s_y__tmp_1354 );
                share * s_y_tmp_1347 = ycirc->PutANDGate( s_y_tmp_1348 , s_y_tmp_1351 );
                uint32_t _tmp_1355 = 0 ;
                share * s_y__tmp_1355 = ycirc->PutCONSGate( _tmp_1355 ,bitlen);
                share * s_y_tmp_1346 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1355 , s_y_tmp_1347 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1345 , s_y_tmp_1346 , s_y_tmp_1342 );
                uint32_t _tmp_1356 = 1 ;
                share * s_y__tmp_1356 = ycirc->PutCONSGate( _tmp_1356 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1356 );
            }
            uint32_t _tmp_1358 = 1 ;
            share * s_y__tmp_1358 = ycirc->PutCONSGate( _tmp_1358 ,bitlen);
            share * s_y_tmp_1357 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1358 );
            vector<uint32_t> _vec1359 = s_y_tmp_1357->get_wires();
            _vec1359.erase( _vec1359.begin(), _vec1359.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1359 , ycirc );
        }
        s_y_tmp31[4][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_1361 = 2147483648 ;
        share * s_y__tmp_1361 = ycirc->PutCONSGate( _tmp_1361 ,bitlen);
        share * s_y_tmp_1360 = ycirc->PutGTGate( s_y__tmp_1361 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec1363 = s_y_WW[i0][i1]->get_wires();
        _vec1363.erase( _vec1363.begin(), _vec1363.begin() + 15 );
        share *s_y_tmp_1362 = create_new_share( _vec1363 , ycirc );
        uint32_t _tmp_1367 = 4294967295 ;
        share * s_y__tmp_1367 = ycirc->PutCONSGate( _tmp_1367 ,bitlen);
        share * s_y_tmp_1366 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_1367 );
        vector<uint32_t> _vec1368 = s_y_tmp_1366->get_wires();
        _vec1368.erase( _vec1368.begin(), _vec1368.begin() + 15 );
        share *s_y_tmp_1365 = create_new_share( _vec1368 , ycirc );
        uint32_t _tmp_1369 = 4294967295 ;
        share * s_y__tmp_1369 = ycirc->PutCONSGate( _tmp_1369 ,bitlen);
        share * s_y_tmp_1364 = ycirc->PutXORGate( s_y_tmp_1365 , s_y__tmp_1369 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_1362 , s_y_tmp_1364 , s_y_tmp_1360 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_1371 = 2147483648 ;
        share * s_y__tmp_1371 = ycirc->PutCONSGate( _tmp_1371 ,bitlen);
        share * s_y_tmp_1370 = ycirc->PutGTGate( s_y__tmp_1371 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec1373 = s_y_xx[i1][i2]->get_wires();
        _vec1373.erase( _vec1373.begin(), _vec1373.begin() + 15 );
        share *s_y_tmp_1372 = create_new_share( _vec1373 , ycirc );
        uint32_t _tmp_1377 = 4294967295 ;
        share * s_y__tmp_1377 = ycirc->PutCONSGate( _tmp_1377 ,bitlen);
        share * s_y_tmp_1376 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_1377 );
        vector<uint32_t> _vec1378 = s_y_tmp_1376->get_wires();
        _vec1378.erase( _vec1378.begin(), _vec1378.begin() + 15 );
        share *s_y_tmp_1375 = create_new_share( _vec1378 , ycirc );
        uint32_t _tmp_1379 = 4294967295 ;
        share * s_y__tmp_1379 = ycirc->PutCONSGate( _tmp_1379 ,bitlen);
        share * s_y_tmp_1374 = ycirc->PutXORGate( s_y_tmp_1375 , s_y__tmp_1379 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_1372 , s_y_tmp_1374 , s_y_tmp_1370 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1382 = s_y_tmp5->get_wires();
                _vec1382.erase( _vec1382.begin(), _vec1382.begin() + 1 );
                share *s_y_tmp_1381 = create_new_share( _vec1382 , ycirc );
                share * s_y_tmp_1380 = ycirc->PutGTGate( s_y_tmp_1381 , s_y_tmp6 );
                share * s_y_tmp_1385 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1386 = 2147483648 ;
                share * s_y__tmp_1386 = ycirc->PutCONSGate( _tmp_1386 ,bitlen);
                share * s_y_tmp_1384 = ycirc->PutGTGate( s_y__tmp_1386 , s_y_tmp_1385 );
                share * s_y_tmp_1388 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1389 = s_y_tmp_1388->get_wires();
                _vec1389.erase( _vec1389.begin(), _vec1389.begin() + 1 );
                share *s_y_tmp_1387 = create_new_share( _vec1389 , ycirc );
                share * s_y_tmp_1393 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1394 = 4294967295 ;
                share * s_y__tmp_1394 = ycirc->PutCONSGate( _tmp_1394 ,bitlen);
                share * s_y_tmp_1392 = ycirc->PutXORGate( s_y_tmp_1393 , s_y__tmp_1394 );
                vector<uint32_t> _vec1395 = s_y_tmp_1392->get_wires();
                _vec1395.erase( _vec1395.begin(), _vec1395.begin() + 1 );
                share *s_y_tmp_1391 = create_new_share( _vec1395 , ycirc );
                uint32_t _tmp_1396 = 4294967295 ;
                share * s_y__tmp_1396 = ycirc->PutCONSGate( _tmp_1396 ,bitlen);
                share * s_y_tmp_1390 = ycirc->PutXORGate( s_y_tmp_1391 , s_y__tmp_1396 );
                share * s_y_tmp_1383 = ycirc->PutMUXGate( s_y_tmp_1387 , s_y_tmp_1390 , s_y_tmp_1384 );
                vector<uint32_t> _vec1401 = s_y_tmp5->get_wires();
                _vec1401.erase( _vec1401.begin(), _vec1401.begin() + 1 );
                share *s_y_tmp_1400 = create_new_share( _vec1401 , ycirc );
                share * s_y_tmp_1399 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1400 );
                uint32_t _tmp_1404 = 1 ;
                share * s_y__tmp_1404 = ycirc->PutCONSGate( _tmp_1404 ,bitlen);
                share * s_y_tmp_1403 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1404 );
                uint32_t _tmp_1405 = 1 ;
                share * s_y__tmp_1405 = ycirc->PutCONSGate( _tmp_1405 ,bitlen);
                share * s_y_tmp_1402 = ycirc->PutEQGate( s_y_tmp_1403 , s_y__tmp_1405 );
                share * s_y_tmp_1398 = ycirc->PutANDGate( s_y_tmp_1399 , s_y_tmp_1402 );
                uint32_t _tmp_1408 = 2147483648 ;
                share * s_y__tmp_1408 = ycirc->PutCONSGate( _tmp_1408 ,bitlen);
                share * s_y_tmp_1407 = ycirc->PutGTGate( s_y__tmp_1408 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec1410 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec1410.erase( _vec1410.begin(), _vec1410.begin() + 1 );
                share *s_y_tmp_1409 = create_new_share( _vec1410 , ycirc );
                uint32_t _tmp_1414 = 4294967295 ;
                share * s_y__tmp_1414 = ycirc->PutCONSGate( _tmp_1414 ,bitlen);
                share * s_y_tmp_1413 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1414 );
                vector<uint32_t> _vec1415 = s_y_tmp_1413->get_wires();
                _vec1415.erase( _vec1415.begin(), _vec1415.begin() + 1 );
                share *s_y_tmp_1412 = create_new_share( _vec1415 , ycirc );
                uint32_t _tmp_1416 = 4294967295 ;
                share * s_y__tmp_1416 = ycirc->PutCONSGate( _tmp_1416 ,bitlen);
                share * s_y_tmp_1411 = ycirc->PutXORGate( s_y_tmp_1412 , s_y__tmp_1416 );
                share * s_y_tmp_1406 = ycirc->PutMUXGate( s_y_tmp_1409 , s_y_tmp_1411 , s_y_tmp_1407 );
                uint32_t _tmp_1417 = 0 ;
                share * s_y__tmp_1417 = ycirc->PutCONSGate( _tmp_1417 ,bitlen);
                share * s_y_tmp_1397 = ycirc->PutMUXGate( s_y_tmp_1406 , s_y__tmp_1417 , s_y_tmp_1398 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1383 , s_y_tmp_1397 , s_y_tmp_1380 );
                uint32_t _tmp_1418 = 1 ;
                share * s_y__tmp_1418 = ycirc->PutCONSGate( _tmp_1418 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1418 );
            }
            uint32_t _tmp_1420 = 1 ;
            share * s_y__tmp_1420 = ycirc->PutCONSGate( _tmp_1420 ,bitlen);
            share * s_y_tmp_1419 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1420 );
            vector<uint32_t> _vec1421 = s_y_tmp_1419->get_wires();
            _vec1421.erase( _vec1421.begin(), _vec1421.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1421 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1424 = s_y_tmp5->get_wires();
                _vec1424.erase( _vec1424.begin(), _vec1424.begin() + 1 );
                share *s_y_tmp_1423 = create_new_share( _vec1424 , ycirc );
                share * s_y_tmp_1422 = ycirc->PutGTGate( s_y_tmp_1423 , s_y_tmp6 );
                share * s_y_tmp_1425 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1430 = s_y_tmp5->get_wires();
                _vec1430.erase( _vec1430.begin(), _vec1430.begin() + 1 );
                share *s_y_tmp_1429 = create_new_share( _vec1430 , ycirc );
                share * s_y_tmp_1428 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1429 );
                uint32_t _tmp_1433 = 1 ;
                share * s_y__tmp_1433 = ycirc->PutCONSGate( _tmp_1433 ,bitlen);
                share * s_y_tmp_1432 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1433 );
                uint32_t _tmp_1434 = 1 ;
                share * s_y__tmp_1434 = ycirc->PutCONSGate( _tmp_1434 ,bitlen);
                share * s_y_tmp_1431 = ycirc->PutEQGate( s_y_tmp_1432 , s_y__tmp_1434 );
                share * s_y_tmp_1427 = ycirc->PutANDGate( s_y_tmp_1428 , s_y_tmp_1431 );
                uint32_t _tmp_1435 = 0 ;
                share * s_y__tmp_1435 = ycirc->PutCONSGate( _tmp_1435 ,bitlen);
                share * s_y_tmp_1426 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1435 , s_y_tmp_1427 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1425 , s_y_tmp_1426 , s_y_tmp_1422 );
                uint32_t _tmp_1436 = 1 ;
                share * s_y__tmp_1436 = ycirc->PutCONSGate( _tmp_1436 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1436 );
            }
            uint32_t _tmp_1438 = 1 ;
            share * s_y__tmp_1438 = ycirc->PutCONSGate( _tmp_1438 ,bitlen);
            share * s_y_tmp_1437 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1438 );
            vector<uint32_t> _vec1439 = s_y_tmp_1437->get_wires();
            _vec1439.erase( _vec1439.begin(), _vec1439.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1439 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_1441 = 2147483648 ;
        share * s_y__tmp_1441 = ycirc->PutCONSGate( _tmp_1441 ,bitlen);
        share * s_y_tmp_1440 = ycirc->PutGTGate( s_y__tmp_1441 , s_y_BB[5][i5][i6] );
        vector<uint32_t> _vec1443 = s_y_BB[5][i5][i6]->get_wires();
        _vec1443.erase( _vec1443.begin(), _vec1443.begin() + 4 );
        share *s_y_tmp_1442 = create_new_share( _vec1443 , ycirc );
        uint32_t _tmp_1447 = 4294967295 ;
        share * s_y__tmp_1447 = ycirc->PutCONSGate( _tmp_1447 ,bitlen);
        share * s_y_tmp_1446 = ycirc->PutXORGate( s_y_BB[5][i5][i6] , s_y__tmp_1447 );
        vector<uint32_t> _vec1448 = s_y_tmp_1446->get_wires();
        _vec1448.erase( _vec1448.begin(), _vec1448.begin() + 4 );
        share *s_y_tmp_1445 = create_new_share( _vec1448 , ycirc );
        uint32_t _tmp_1449 = 4294967295 ;
        share * s_y__tmp_1449 = ycirc->PutCONSGate( _tmp_1449 ,bitlen);
        share * s_y_tmp_1444 = ycirc->PutXORGate( s_y_tmp_1445 , s_y__tmp_1449 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_1442 , s_y_tmp_1444 , s_y_tmp_1440 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_1450 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_1451 = 1 ;
share * s_a__tmp_1451 = acirc->PutCONSGate( _tmp_1451 ,bitlen);
share *s_a_tmp_1450 = acirc->PutY2AGate( s_y_tmp_1450 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_1450 , s_a__tmp_1451 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_1453 = 2147483648 ;
        share * s_y__tmp_1453 = ycirc->PutCONSGate( _tmp_1453 ,bitlen);
        share * s_y_tmp_1452 = ycirc->PutGTGate( s_y__tmp_1453 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec1455 = s_y_tmp11[i9][i10]->get_wires();
        _vec1455.erase( _vec1455.begin(), _vec1455.begin() + 15 );
        share *s_y_tmp_1454 = create_new_share( _vec1455 , ycirc );
        uint32_t _tmp_1459 = 4294967295 ;
        share * s_y__tmp_1459 = ycirc->PutCONSGate( _tmp_1459 ,bitlen);
        share * s_y_tmp_1458 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_1459 );
        vector<uint32_t> _vec1460 = s_y_tmp_1458->get_wires();
        _vec1460.erase( _vec1460.begin(), _vec1460.begin() + 15 );
        share *s_y_tmp_1457 = create_new_share( _vec1460 , ycirc );
        uint32_t _tmp_1461 = 4294967295 ;
        share * s_y__tmp_1461 = ycirc->PutCONSGate( _tmp_1461 ,bitlen);
        share * s_y_tmp_1456 = ycirc->PutXORGate( s_y_tmp_1457 , s_y__tmp_1461 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_1454 , s_y_tmp_1456 , s_y_tmp_1452 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_1463 = 2147483648 ;
        share * s_y__tmp_1463 = ycirc->PutCONSGate( _tmp_1463 ,bitlen);
        share * s_y_tmp_1462 = ycirc->PutGTGate( s_y__tmp_1463 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec1465 = s_y_tmp7[i10][i11]->get_wires();
        _vec1465.erase( _vec1465.begin(), _vec1465.begin() + 15 );
        share *s_y_tmp_1464 = create_new_share( _vec1465 , ycirc );
        uint32_t _tmp_1469 = 4294967295 ;
        share * s_y__tmp_1469 = ycirc->PutCONSGate( _tmp_1469 ,bitlen);
        share * s_y_tmp_1468 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_1469 );
        vector<uint32_t> _vec1470 = s_y_tmp_1468->get_wires();
        _vec1470.erase( _vec1470.begin(), _vec1470.begin() + 15 );
        share *s_y_tmp_1467 = create_new_share( _vec1470 , ycirc );
        uint32_t _tmp_1471 = 4294967295 ;
        share * s_y__tmp_1471 = ycirc->PutCONSGate( _tmp_1471 ,bitlen);
        share * s_y_tmp_1466 = ycirc->PutXORGate( s_y_tmp_1467 , s_y__tmp_1471 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_1464 , s_y_tmp_1466 , s_y_tmp_1462 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec1474 = s_y_tmp16->get_wires();
                _vec1474.erase( _vec1474.begin(), _vec1474.begin() + 1 );
                share *s_y_tmp_1473 = create_new_share( _vec1474 , ycirc );
                share * s_y_tmp_1472 = ycirc->PutGTGate( s_y_tmp_1473 , s_y_tmp17 );
                share * s_y_tmp_1477 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_1478 = 2147483648 ;
                share * s_y__tmp_1478 = ycirc->PutCONSGate( _tmp_1478 ,bitlen);
                share * s_y_tmp_1476 = ycirc->PutGTGate( s_y__tmp_1478 , s_y_tmp_1477 );
                share * s_y_tmp_1480 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec1481 = s_y_tmp_1480->get_wires();
                _vec1481.erase( _vec1481.begin(), _vec1481.begin() + 1 );
                share *s_y_tmp_1479 = create_new_share( _vec1481 , ycirc );
                share * s_y_tmp_1485 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_1486 = 4294967295 ;
                share * s_y__tmp_1486 = ycirc->PutCONSGate( _tmp_1486 ,bitlen);
                share * s_y_tmp_1484 = ycirc->PutXORGate( s_y_tmp_1485 , s_y__tmp_1486 );
                vector<uint32_t> _vec1487 = s_y_tmp_1484->get_wires();
                _vec1487.erase( _vec1487.begin(), _vec1487.begin() + 1 );
                share *s_y_tmp_1483 = create_new_share( _vec1487 , ycirc );
                uint32_t _tmp_1488 = 4294967295 ;
                share * s_y__tmp_1488 = ycirc->PutCONSGate( _tmp_1488 ,bitlen);
                share * s_y_tmp_1482 = ycirc->PutXORGate( s_y_tmp_1483 , s_y__tmp_1488 );
                share * s_y_tmp_1475 = ycirc->PutMUXGate( s_y_tmp_1479 , s_y_tmp_1482 , s_y_tmp_1476 );
                vector<uint32_t> _vec1493 = s_y_tmp16->get_wires();
                _vec1493.erase( _vec1493.begin(), _vec1493.begin() + 1 );
                share *s_y_tmp_1492 = create_new_share( _vec1493 , ycirc );
                share * s_y_tmp_1491 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_1492 );
                uint32_t _tmp_1496 = 1 ;
                share * s_y__tmp_1496 = ycirc->PutCONSGate( _tmp_1496 ,bitlen);
                share * s_y_tmp_1495 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_1496 );
                uint32_t _tmp_1497 = 1 ;
                share * s_y__tmp_1497 = ycirc->PutCONSGate( _tmp_1497 ,bitlen);
                share * s_y_tmp_1494 = ycirc->PutEQGate( s_y_tmp_1495 , s_y__tmp_1497 );
                share * s_y_tmp_1490 = ycirc->PutANDGate( s_y_tmp_1491 , s_y_tmp_1494 );
                uint32_t _tmp_1500 = 2147483648 ;
                share * s_y__tmp_1500 = ycirc->PutCONSGate( _tmp_1500 ,bitlen);
                share * s_y_tmp_1499 = ycirc->PutGTGate( s_y__tmp_1500 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec1502 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec1502.erase( _vec1502.begin(), _vec1502.begin() + 1 );
                share *s_y_tmp_1501 = create_new_share( _vec1502 , ycirc );
                uint32_t _tmp_1506 = 4294967295 ;
                share * s_y__tmp_1506 = ycirc->PutCONSGate( _tmp_1506 ,bitlen);
                share * s_y_tmp_1505 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_1506 );
                vector<uint32_t> _vec1507 = s_y_tmp_1505->get_wires();
                _vec1507.erase( _vec1507.begin(), _vec1507.begin() + 1 );
                share *s_y_tmp_1504 = create_new_share( _vec1507 , ycirc );
                uint32_t _tmp_1508 = 4294967295 ;
                share * s_y__tmp_1508 = ycirc->PutCONSGate( _tmp_1508 ,bitlen);
                share * s_y_tmp_1503 = ycirc->PutXORGate( s_y_tmp_1504 , s_y__tmp_1508 );
                share * s_y_tmp_1498 = ycirc->PutMUXGate( s_y_tmp_1501 , s_y_tmp_1503 , s_y_tmp_1499 );
                uint32_t _tmp_1509 = 0 ;
                share * s_y__tmp_1509 = ycirc->PutCONSGate( _tmp_1509 ,bitlen);
                share * s_y_tmp_1489 = ycirc->PutMUXGate( s_y_tmp_1498 , s_y__tmp_1509 , s_y_tmp_1490 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_1475 , s_y_tmp_1489 , s_y_tmp_1472 );
                uint32_t _tmp_1510 = 1 ;
                share * s_y__tmp_1510 = ycirc->PutCONSGate( _tmp_1510 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_1510 );
            }
            uint32_t _tmp_1512 = 1 ;
            share * s_y__tmp_1512 = ycirc->PutCONSGate( _tmp_1512 ,bitlen);
            share * s_y_tmp_1511 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_1512 );
            vector<uint32_t> _vec1513 = s_y_tmp_1511->get_wires();
            _vec1513.erase( _vec1513.begin(), _vec1513.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec1513 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec1516 = s_y_tmp16->get_wires();
                _vec1516.erase( _vec1516.begin(), _vec1516.begin() + 1 );
                share *s_y_tmp_1515 = create_new_share( _vec1516 , ycirc );
                share * s_y_tmp_1514 = ycirc->PutGTGate( s_y_tmp_1515 , s_y_tmp17 );
                share * s_y_tmp_1517 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec1522 = s_y_tmp16->get_wires();
                _vec1522.erase( _vec1522.begin(), _vec1522.begin() + 1 );
                share *s_y_tmp_1521 = create_new_share( _vec1522 , ycirc );
                share * s_y_tmp_1520 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_1521 );
                uint32_t _tmp_1525 = 1 ;
                share * s_y__tmp_1525 = ycirc->PutCONSGate( _tmp_1525 ,bitlen);
                share * s_y_tmp_1524 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_1525 );
                uint32_t _tmp_1526 = 1 ;
                share * s_y__tmp_1526 = ycirc->PutCONSGate( _tmp_1526 ,bitlen);
                share * s_y_tmp_1523 = ycirc->PutEQGate( s_y_tmp_1524 , s_y__tmp_1526 );
                share * s_y_tmp_1519 = ycirc->PutANDGate( s_y_tmp_1520 , s_y_tmp_1523 );
                uint32_t _tmp_1527 = 0 ;
                share * s_y__tmp_1527 = ycirc->PutCONSGate( _tmp_1527 ,bitlen);
                share * s_y_tmp_1518 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_1527 , s_y_tmp_1519 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_1517 , s_y_tmp_1518 , s_y_tmp_1514 );
                uint32_t _tmp_1528 = 1 ;
                share * s_y__tmp_1528 = ycirc->PutCONSGate( _tmp_1528 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_1528 );
            }
            uint32_t _tmp_1530 = 1 ;
            share * s_y__tmp_1530 = ycirc->PutCONSGate( _tmp_1530 ,bitlen);
            share * s_y_tmp_1529 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_1530 );
            vector<uint32_t> _vec1531 = s_y_tmp_1529->get_wires();
            _vec1531.erase( _vec1531.begin(), _vec1531.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec1531 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_1533 = 2147483648 ;
share * s_y__tmp_1533 = ycirc->PutCONSGate( _tmp_1533 ,bitlen);
share * s_y_tmp_1532 = ycirc->PutGTGate( s_y__tmp_1533 , s_y_tmp10 );
vector<uint32_t> _vec1535 = s_y_tmp10->get_wires();
_vec1535.erase( _vec1535.begin(), _vec1535.begin() + 15 );
share *s_y_tmp_1534 = create_new_share( _vec1535 , ycirc );
uint32_t _tmp_1539 = 4294967295 ;
share * s_y__tmp_1539 = ycirc->PutCONSGate( _tmp_1539 ,bitlen);
share * s_y_tmp_1538 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_1539 );
vector<uint32_t> _vec1540 = s_y_tmp_1538->get_wires();
_vec1540.erase( _vec1540.begin(), _vec1540.begin() + 15 );
share *s_y_tmp_1537 = create_new_share( _vec1540 , ycirc );
uint32_t _tmp_1541 = 4294967295 ;
share * s_y__tmp_1541 = ycirc->PutCONSGate( _tmp_1541 ,bitlen);
share * s_y_tmp_1536 = ycirc->PutXORGate( s_y_tmp_1537 , s_y__tmp_1541 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_1534 , s_y_tmp_1536 , s_y_tmp_1532 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_1543 = 2147483648 ;
        share * s_y__tmp_1543 = ycirc->PutCONSGate( _tmp_1543 ,bitlen);
        share * s_y_tmp_1542 = ycirc->PutGTGate( s_y__tmp_1543 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec1545 = s_y_tmp12[i14][i15]->get_wires();
        _vec1545.erase( _vec1545.begin(), _vec1545.begin() + 15 );
        share *s_y_tmp_1544 = create_new_share( _vec1545 , ycirc );
        uint32_t _tmp_1549 = 4294967295 ;
        share * s_y__tmp_1549 = ycirc->PutCONSGate( _tmp_1549 ,bitlen);
        share * s_y_tmp_1548 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_1549 );
        vector<uint32_t> _vec1550 = s_y_tmp_1548->get_wires();
        _vec1550.erase( _vec1550.begin(), _vec1550.begin() + 15 );
        share *s_y_tmp_1547 = create_new_share( _vec1550 , ycirc );
        uint32_t _tmp_1551 = 4294967295 ;
        share * s_y__tmp_1551 = ycirc->PutCONSGate( _tmp_1551 ,bitlen);
        share * s_y_tmp_1546 = ycirc->PutXORGate( s_y_tmp_1547 , s_y__tmp_1551 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_1544 , s_y_tmp_1546 , s_y_tmp_1542 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_1553 = 2147483648 ;
        share * s_y__tmp_1553 = ycirc->PutCONSGate( _tmp_1553 ,bitlen);
        share * s_y_tmp_1552 = ycirc->PutGTGate( s_y__tmp_1553 , s_y_ZZ[5][i16][i17] );
        vector<uint32_t> _vec1555 = s_y_ZZ[5][i16][i17]->get_wires();
        _vec1555.erase( _vec1555.begin(), _vec1555.begin() + 15 );
        share *s_y_tmp_1554 = create_new_share( _vec1555 , ycirc );
        uint32_t _tmp_1559 = 4294967295 ;
        share * s_y__tmp_1559 = ycirc->PutCONSGate( _tmp_1559 ,bitlen);
        share * s_y_tmp_1558 = ycirc->PutXORGate( s_y_ZZ[5][i16][i17] , s_y__tmp_1559 );
        vector<uint32_t> _vec1560 = s_y_tmp_1558->get_wires();
        _vec1560.erase( _vec1560.begin(), _vec1560.begin() + 15 );
        share *s_y_tmp_1557 = create_new_share( _vec1560 , ycirc );
        uint32_t _tmp_1561 = 4294967295 ;
        share * s_y__tmp_1561 = ycirc->PutCONSGate( _tmp_1561 ,bitlen);
        share * s_y_tmp_1556 = ycirc->PutXORGate( s_y_tmp_1557 , s_y__tmp_1561 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_1554 , s_y_tmp_1556 , s_y_tmp_1552 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_1563 = 2147483648 ;
        share * s_y__tmp_1563 = ycirc->PutCONSGate( _tmp_1563 ,bitlen);
        share * s_y_tmp_1562 = ycirc->PutGTGate( s_y__tmp_1563 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec1565 = s_y_tmp21[i17][i18]->get_wires();
        _vec1565.erase( _vec1565.begin(), _vec1565.begin() + 15 );
        share *s_y_tmp_1564 = create_new_share( _vec1565 , ycirc );
        uint32_t _tmp_1569 = 4294967295 ;
        share * s_y__tmp_1569 = ycirc->PutCONSGate( _tmp_1569 ,bitlen);
        share * s_y_tmp_1568 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_1569 );
        vector<uint32_t> _vec1570 = s_y_tmp_1568->get_wires();
        _vec1570.erase( _vec1570.begin(), _vec1570.begin() + 15 );
        share *s_y_tmp_1567 = create_new_share( _vec1570 , ycirc );
        uint32_t _tmp_1571 = 4294967295 ;
        share * s_y__tmp_1571 = ycirc->PutCONSGate( _tmp_1571 ,bitlen);
        share * s_y_tmp_1566 = ycirc->PutXORGate( s_y_tmp_1567 , s_y__tmp_1571 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_1564 , s_y_tmp_1566 , s_y_tmp_1562 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1574 = s_y_tmp28->get_wires();
                _vec1574.erase( _vec1574.begin(), _vec1574.begin() + 1 );
                share *s_y_tmp_1573 = create_new_share( _vec1574 , ycirc );
                share * s_y_tmp_1572 = ycirc->PutGTGate( s_y_tmp_1573 , s_y_tmp29 );
                share * s_y_tmp_1577 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1578 = 2147483648 ;
                share * s_y__tmp_1578 = ycirc->PutCONSGate( _tmp_1578 ,bitlen);
                share * s_y_tmp_1576 = ycirc->PutGTGate( s_y__tmp_1578 , s_y_tmp_1577 );
                share * s_y_tmp_1580 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1581 = s_y_tmp_1580->get_wires();
                _vec1581.erase( _vec1581.begin(), _vec1581.begin() + 1 );
                share *s_y_tmp_1579 = create_new_share( _vec1581 , ycirc );
                share * s_y_tmp_1585 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1586 = 4294967295 ;
                share * s_y__tmp_1586 = ycirc->PutCONSGate( _tmp_1586 ,bitlen);
                share * s_y_tmp_1584 = ycirc->PutXORGate( s_y_tmp_1585 , s_y__tmp_1586 );
                vector<uint32_t> _vec1587 = s_y_tmp_1584->get_wires();
                _vec1587.erase( _vec1587.begin(), _vec1587.begin() + 1 );
                share *s_y_tmp_1583 = create_new_share( _vec1587 , ycirc );
                uint32_t _tmp_1588 = 4294967295 ;
                share * s_y__tmp_1588 = ycirc->PutCONSGate( _tmp_1588 ,bitlen);
                share * s_y_tmp_1582 = ycirc->PutXORGate( s_y_tmp_1583 , s_y__tmp_1588 );
                share * s_y_tmp_1575 = ycirc->PutMUXGate( s_y_tmp_1579 , s_y_tmp_1582 , s_y_tmp_1576 );
                vector<uint32_t> _vec1593 = s_y_tmp28->get_wires();
                _vec1593.erase( _vec1593.begin(), _vec1593.begin() + 1 );
                share *s_y_tmp_1592 = create_new_share( _vec1593 , ycirc );
                share * s_y_tmp_1591 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1592 );
                uint32_t _tmp_1596 = 1 ;
                share * s_y__tmp_1596 = ycirc->PutCONSGate( _tmp_1596 ,bitlen);
                share * s_y_tmp_1595 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1596 );
                uint32_t _tmp_1597 = 1 ;
                share * s_y__tmp_1597 = ycirc->PutCONSGate( _tmp_1597 ,bitlen);
                share * s_y_tmp_1594 = ycirc->PutEQGate( s_y_tmp_1595 , s_y__tmp_1597 );
                share * s_y_tmp_1590 = ycirc->PutANDGate( s_y_tmp_1591 , s_y_tmp_1594 );
                uint32_t _tmp_1600 = 2147483648 ;
                share * s_y__tmp_1600 = ycirc->PutCONSGate( _tmp_1600 ,bitlen);
                share * s_y_tmp_1599 = ycirc->PutGTGate( s_y__tmp_1600 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec1602 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec1602.erase( _vec1602.begin(), _vec1602.begin() + 1 );
                share *s_y_tmp_1601 = create_new_share( _vec1602 , ycirc );
                uint32_t _tmp_1606 = 4294967295 ;
                share * s_y__tmp_1606 = ycirc->PutCONSGate( _tmp_1606 ,bitlen);
                share * s_y_tmp_1605 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1606 );
                vector<uint32_t> _vec1607 = s_y_tmp_1605->get_wires();
                _vec1607.erase( _vec1607.begin(), _vec1607.begin() + 1 );
                share *s_y_tmp_1604 = create_new_share( _vec1607 , ycirc );
                uint32_t _tmp_1608 = 4294967295 ;
                share * s_y__tmp_1608 = ycirc->PutCONSGate( _tmp_1608 ,bitlen);
                share * s_y_tmp_1603 = ycirc->PutXORGate( s_y_tmp_1604 , s_y__tmp_1608 );
                share * s_y_tmp_1598 = ycirc->PutMUXGate( s_y_tmp_1601 , s_y_tmp_1603 , s_y_tmp_1599 );
                uint32_t _tmp_1609 = 0 ;
                share * s_y__tmp_1609 = ycirc->PutCONSGate( _tmp_1609 ,bitlen);
                share * s_y_tmp_1589 = ycirc->PutMUXGate( s_y_tmp_1598 , s_y__tmp_1609 , s_y_tmp_1590 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1575 , s_y_tmp_1589 , s_y_tmp_1572 );
                uint32_t _tmp_1610 = 1 ;
                share * s_y__tmp_1610 = ycirc->PutCONSGate( _tmp_1610 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1610 );
            }
            uint32_t _tmp_1612 = 1 ;
            share * s_y__tmp_1612 = ycirc->PutCONSGate( _tmp_1612 ,bitlen);
            share * s_y_tmp_1611 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1612 );
            vector<uint32_t> _vec1613 = s_y_tmp_1611->get_wires();
            _vec1613.erase( _vec1613.begin(), _vec1613.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1613 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1616 = s_y_tmp28->get_wires();
                _vec1616.erase( _vec1616.begin(), _vec1616.begin() + 1 );
                share *s_y_tmp_1615 = create_new_share( _vec1616 , ycirc );
                share * s_y_tmp_1614 = ycirc->PutGTGate( s_y_tmp_1615 , s_y_tmp29 );
                share * s_y_tmp_1617 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1622 = s_y_tmp28->get_wires();
                _vec1622.erase( _vec1622.begin(), _vec1622.begin() + 1 );
                share *s_y_tmp_1621 = create_new_share( _vec1622 , ycirc );
                share * s_y_tmp_1620 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1621 );
                uint32_t _tmp_1625 = 1 ;
                share * s_y__tmp_1625 = ycirc->PutCONSGate( _tmp_1625 ,bitlen);
                share * s_y_tmp_1624 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1625 );
                uint32_t _tmp_1626 = 1 ;
                share * s_y__tmp_1626 = ycirc->PutCONSGate( _tmp_1626 ,bitlen);
                share * s_y_tmp_1623 = ycirc->PutEQGate( s_y_tmp_1624 , s_y__tmp_1626 );
                share * s_y_tmp_1619 = ycirc->PutANDGate( s_y_tmp_1620 , s_y_tmp_1623 );
                uint32_t _tmp_1627 = 0 ;
                share * s_y__tmp_1627 = ycirc->PutCONSGate( _tmp_1627 ,bitlen);
                share * s_y_tmp_1618 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1627 , s_y_tmp_1619 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1617 , s_y_tmp_1618 , s_y_tmp_1614 );
                uint32_t _tmp_1628 = 1 ;
                share * s_y__tmp_1628 = ycirc->PutCONSGate( _tmp_1628 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1628 );
            }
            uint32_t _tmp_1630 = 1 ;
            share * s_y__tmp_1630 = ycirc->PutCONSGate( _tmp_1630 ,bitlen);
            share * s_y_tmp_1629 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1630 );
            vector<uint32_t> _vec1631 = s_y_tmp_1629->get_wires();
            _vec1631.erase( _vec1631.begin(), _vec1631.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1631 , ycirc );
        }
        s_y_tmp31[5][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_1633 = 2147483648 ;
        share * s_y__tmp_1633 = ycirc->PutCONSGate( _tmp_1633 ,bitlen);
        share * s_y_tmp_1632 = ycirc->PutGTGate( s_y__tmp_1633 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec1635 = s_y_WW[i0][i1]->get_wires();
        _vec1635.erase( _vec1635.begin(), _vec1635.begin() + 15 );
        share *s_y_tmp_1634 = create_new_share( _vec1635 , ycirc );
        uint32_t _tmp_1639 = 4294967295 ;
        share * s_y__tmp_1639 = ycirc->PutCONSGate( _tmp_1639 ,bitlen);
        share * s_y_tmp_1638 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_1639 );
        vector<uint32_t> _vec1640 = s_y_tmp_1638->get_wires();
        _vec1640.erase( _vec1640.begin(), _vec1640.begin() + 15 );
        share *s_y_tmp_1637 = create_new_share( _vec1640 , ycirc );
        uint32_t _tmp_1641 = 4294967295 ;
        share * s_y__tmp_1641 = ycirc->PutCONSGate( _tmp_1641 ,bitlen);
        share * s_y_tmp_1636 = ycirc->PutXORGate( s_y_tmp_1637 , s_y__tmp_1641 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_1634 , s_y_tmp_1636 , s_y_tmp_1632 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_1643 = 2147483648 ;
        share * s_y__tmp_1643 = ycirc->PutCONSGate( _tmp_1643 ,bitlen);
        share * s_y_tmp_1642 = ycirc->PutGTGate( s_y__tmp_1643 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec1645 = s_y_xx[i1][i2]->get_wires();
        _vec1645.erase( _vec1645.begin(), _vec1645.begin() + 15 );
        share *s_y_tmp_1644 = create_new_share( _vec1645 , ycirc );
        uint32_t _tmp_1649 = 4294967295 ;
        share * s_y__tmp_1649 = ycirc->PutCONSGate( _tmp_1649 ,bitlen);
        share * s_y_tmp_1648 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_1649 );
        vector<uint32_t> _vec1650 = s_y_tmp_1648->get_wires();
        _vec1650.erase( _vec1650.begin(), _vec1650.begin() + 15 );
        share *s_y_tmp_1647 = create_new_share( _vec1650 , ycirc );
        uint32_t _tmp_1651 = 4294967295 ;
        share * s_y__tmp_1651 = ycirc->PutCONSGate( _tmp_1651 ,bitlen);
        share * s_y_tmp_1646 = ycirc->PutXORGate( s_y_tmp_1647 , s_y__tmp_1651 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_1644 , s_y_tmp_1646 , s_y_tmp_1642 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1654 = s_y_tmp5->get_wires();
                _vec1654.erase( _vec1654.begin(), _vec1654.begin() + 1 );
                share *s_y_tmp_1653 = create_new_share( _vec1654 , ycirc );
                share * s_y_tmp_1652 = ycirc->PutGTGate( s_y_tmp_1653 , s_y_tmp6 );
                share * s_y_tmp_1657 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1658 = 2147483648 ;
                share * s_y__tmp_1658 = ycirc->PutCONSGate( _tmp_1658 ,bitlen);
                share * s_y_tmp_1656 = ycirc->PutGTGate( s_y__tmp_1658 , s_y_tmp_1657 );
                share * s_y_tmp_1660 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1661 = s_y_tmp_1660->get_wires();
                _vec1661.erase( _vec1661.begin(), _vec1661.begin() + 1 );
                share *s_y_tmp_1659 = create_new_share( _vec1661 , ycirc );
                share * s_y_tmp_1665 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1666 = 4294967295 ;
                share * s_y__tmp_1666 = ycirc->PutCONSGate( _tmp_1666 ,bitlen);
                share * s_y_tmp_1664 = ycirc->PutXORGate( s_y_tmp_1665 , s_y__tmp_1666 );
                vector<uint32_t> _vec1667 = s_y_tmp_1664->get_wires();
                _vec1667.erase( _vec1667.begin(), _vec1667.begin() + 1 );
                share *s_y_tmp_1663 = create_new_share( _vec1667 , ycirc );
                uint32_t _tmp_1668 = 4294967295 ;
                share * s_y__tmp_1668 = ycirc->PutCONSGate( _tmp_1668 ,bitlen);
                share * s_y_tmp_1662 = ycirc->PutXORGate( s_y_tmp_1663 , s_y__tmp_1668 );
                share * s_y_tmp_1655 = ycirc->PutMUXGate( s_y_tmp_1659 , s_y_tmp_1662 , s_y_tmp_1656 );
                vector<uint32_t> _vec1673 = s_y_tmp5->get_wires();
                _vec1673.erase( _vec1673.begin(), _vec1673.begin() + 1 );
                share *s_y_tmp_1672 = create_new_share( _vec1673 , ycirc );
                share * s_y_tmp_1671 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1672 );
                uint32_t _tmp_1676 = 1 ;
                share * s_y__tmp_1676 = ycirc->PutCONSGate( _tmp_1676 ,bitlen);
                share * s_y_tmp_1675 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1676 );
                uint32_t _tmp_1677 = 1 ;
                share * s_y__tmp_1677 = ycirc->PutCONSGate( _tmp_1677 ,bitlen);
                share * s_y_tmp_1674 = ycirc->PutEQGate( s_y_tmp_1675 , s_y__tmp_1677 );
                share * s_y_tmp_1670 = ycirc->PutANDGate( s_y_tmp_1671 , s_y_tmp_1674 );
                uint32_t _tmp_1680 = 2147483648 ;
                share * s_y__tmp_1680 = ycirc->PutCONSGate( _tmp_1680 ,bitlen);
                share * s_y_tmp_1679 = ycirc->PutGTGate( s_y__tmp_1680 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec1682 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec1682.erase( _vec1682.begin(), _vec1682.begin() + 1 );
                share *s_y_tmp_1681 = create_new_share( _vec1682 , ycirc );
                uint32_t _tmp_1686 = 4294967295 ;
                share * s_y__tmp_1686 = ycirc->PutCONSGate( _tmp_1686 ,bitlen);
                share * s_y_tmp_1685 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1686 );
                vector<uint32_t> _vec1687 = s_y_tmp_1685->get_wires();
                _vec1687.erase( _vec1687.begin(), _vec1687.begin() + 1 );
                share *s_y_tmp_1684 = create_new_share( _vec1687 , ycirc );
                uint32_t _tmp_1688 = 4294967295 ;
                share * s_y__tmp_1688 = ycirc->PutCONSGate( _tmp_1688 ,bitlen);
                share * s_y_tmp_1683 = ycirc->PutXORGate( s_y_tmp_1684 , s_y__tmp_1688 );
                share * s_y_tmp_1678 = ycirc->PutMUXGate( s_y_tmp_1681 , s_y_tmp_1683 , s_y_tmp_1679 );
                uint32_t _tmp_1689 = 0 ;
                share * s_y__tmp_1689 = ycirc->PutCONSGate( _tmp_1689 ,bitlen);
                share * s_y_tmp_1669 = ycirc->PutMUXGate( s_y_tmp_1678 , s_y__tmp_1689 , s_y_tmp_1670 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1655 , s_y_tmp_1669 , s_y_tmp_1652 );
                uint32_t _tmp_1690 = 1 ;
                share * s_y__tmp_1690 = ycirc->PutCONSGate( _tmp_1690 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1690 );
            }
            uint32_t _tmp_1692 = 1 ;
            share * s_y__tmp_1692 = ycirc->PutCONSGate( _tmp_1692 ,bitlen);
            share * s_y_tmp_1691 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1692 );
            vector<uint32_t> _vec1693 = s_y_tmp_1691->get_wires();
            _vec1693.erase( _vec1693.begin(), _vec1693.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1693 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1696 = s_y_tmp5->get_wires();
                _vec1696.erase( _vec1696.begin(), _vec1696.begin() + 1 );
                share *s_y_tmp_1695 = create_new_share( _vec1696 , ycirc );
                share * s_y_tmp_1694 = ycirc->PutGTGate( s_y_tmp_1695 , s_y_tmp6 );
                share * s_y_tmp_1697 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1702 = s_y_tmp5->get_wires();
                _vec1702.erase( _vec1702.begin(), _vec1702.begin() + 1 );
                share *s_y_tmp_1701 = create_new_share( _vec1702 , ycirc );
                share * s_y_tmp_1700 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1701 );
                uint32_t _tmp_1705 = 1 ;
                share * s_y__tmp_1705 = ycirc->PutCONSGate( _tmp_1705 ,bitlen);
                share * s_y_tmp_1704 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1705 );
                uint32_t _tmp_1706 = 1 ;
                share * s_y__tmp_1706 = ycirc->PutCONSGate( _tmp_1706 ,bitlen);
                share * s_y_tmp_1703 = ycirc->PutEQGate( s_y_tmp_1704 , s_y__tmp_1706 );
                share * s_y_tmp_1699 = ycirc->PutANDGate( s_y_tmp_1700 , s_y_tmp_1703 );
                uint32_t _tmp_1707 = 0 ;
                share * s_y__tmp_1707 = ycirc->PutCONSGate( _tmp_1707 ,bitlen);
                share * s_y_tmp_1698 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1707 , s_y_tmp_1699 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1697 , s_y_tmp_1698 , s_y_tmp_1694 );
                uint32_t _tmp_1708 = 1 ;
                share * s_y__tmp_1708 = ycirc->PutCONSGate( _tmp_1708 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1708 );
            }
            uint32_t _tmp_1710 = 1 ;
            share * s_y__tmp_1710 = ycirc->PutCONSGate( _tmp_1710 ,bitlen);
            share * s_y_tmp_1709 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1710 );
            vector<uint32_t> _vec1711 = s_y_tmp_1709->get_wires();
            _vec1711.erase( _vec1711.begin(), _vec1711.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1711 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_1713 = 2147483648 ;
        share * s_y__tmp_1713 = ycirc->PutCONSGate( _tmp_1713 ,bitlen);
        share * s_y_tmp_1712 = ycirc->PutGTGate( s_y__tmp_1713 , s_y_BB[6][i5][i6] );
        vector<uint32_t> _vec1715 = s_y_BB[6][i5][i6]->get_wires();
        _vec1715.erase( _vec1715.begin(), _vec1715.begin() + 4 );
        share *s_y_tmp_1714 = create_new_share( _vec1715 , ycirc );
        uint32_t _tmp_1719 = 4294967295 ;
        share * s_y__tmp_1719 = ycirc->PutCONSGate( _tmp_1719 ,bitlen);
        share * s_y_tmp_1718 = ycirc->PutXORGate( s_y_BB[6][i5][i6] , s_y__tmp_1719 );
        vector<uint32_t> _vec1720 = s_y_tmp_1718->get_wires();
        _vec1720.erase( _vec1720.begin(), _vec1720.begin() + 4 );
        share *s_y_tmp_1717 = create_new_share( _vec1720 , ycirc );
        uint32_t _tmp_1721 = 4294967295 ;
        share * s_y__tmp_1721 = ycirc->PutCONSGate( _tmp_1721 ,bitlen);
        share * s_y_tmp_1716 = ycirc->PutXORGate( s_y_tmp_1717 , s_y__tmp_1721 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_1714 , s_y_tmp_1716 , s_y_tmp_1712 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_1722 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_1723 = 1 ;
share * s_a__tmp_1723 = acirc->PutCONSGate( _tmp_1723 ,bitlen);
share *s_a_tmp_1722 = acirc->PutY2AGate( s_y_tmp_1722 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_1722 , s_a__tmp_1723 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_1725 = 2147483648 ;
        share * s_y__tmp_1725 = ycirc->PutCONSGate( _tmp_1725 ,bitlen);
        share * s_y_tmp_1724 = ycirc->PutGTGate( s_y__tmp_1725 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec1727 = s_y_tmp11[i9][i10]->get_wires();
        _vec1727.erase( _vec1727.begin(), _vec1727.begin() + 15 );
        share *s_y_tmp_1726 = create_new_share( _vec1727 , ycirc );
        uint32_t _tmp_1731 = 4294967295 ;
        share * s_y__tmp_1731 = ycirc->PutCONSGate( _tmp_1731 ,bitlen);
        share * s_y_tmp_1730 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_1731 );
        vector<uint32_t> _vec1732 = s_y_tmp_1730->get_wires();
        _vec1732.erase( _vec1732.begin(), _vec1732.begin() + 15 );
        share *s_y_tmp_1729 = create_new_share( _vec1732 , ycirc );
        uint32_t _tmp_1733 = 4294967295 ;
        share * s_y__tmp_1733 = ycirc->PutCONSGate( _tmp_1733 ,bitlen);
        share * s_y_tmp_1728 = ycirc->PutXORGate( s_y_tmp_1729 , s_y__tmp_1733 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_1726 , s_y_tmp_1728 , s_y_tmp_1724 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_1735 = 2147483648 ;
        share * s_y__tmp_1735 = ycirc->PutCONSGate( _tmp_1735 ,bitlen);
        share * s_y_tmp_1734 = ycirc->PutGTGate( s_y__tmp_1735 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec1737 = s_y_tmp7[i10][i11]->get_wires();
        _vec1737.erase( _vec1737.begin(), _vec1737.begin() + 15 );
        share *s_y_tmp_1736 = create_new_share( _vec1737 , ycirc );
        uint32_t _tmp_1741 = 4294967295 ;
        share * s_y__tmp_1741 = ycirc->PutCONSGate( _tmp_1741 ,bitlen);
        share * s_y_tmp_1740 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_1741 );
        vector<uint32_t> _vec1742 = s_y_tmp_1740->get_wires();
        _vec1742.erase( _vec1742.begin(), _vec1742.begin() + 15 );
        share *s_y_tmp_1739 = create_new_share( _vec1742 , ycirc );
        uint32_t _tmp_1743 = 4294967295 ;
        share * s_y__tmp_1743 = ycirc->PutCONSGate( _tmp_1743 ,bitlen);
        share * s_y_tmp_1738 = ycirc->PutXORGate( s_y_tmp_1739 , s_y__tmp_1743 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_1736 , s_y_tmp_1738 , s_y_tmp_1734 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec1746 = s_y_tmp16->get_wires();
                _vec1746.erase( _vec1746.begin(), _vec1746.begin() + 1 );
                share *s_y_tmp_1745 = create_new_share( _vec1746 , ycirc );
                share * s_y_tmp_1744 = ycirc->PutGTGate( s_y_tmp_1745 , s_y_tmp17 );
                share * s_y_tmp_1749 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_1750 = 2147483648 ;
                share * s_y__tmp_1750 = ycirc->PutCONSGate( _tmp_1750 ,bitlen);
                share * s_y_tmp_1748 = ycirc->PutGTGate( s_y__tmp_1750 , s_y_tmp_1749 );
                share * s_y_tmp_1752 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec1753 = s_y_tmp_1752->get_wires();
                _vec1753.erase( _vec1753.begin(), _vec1753.begin() + 1 );
                share *s_y_tmp_1751 = create_new_share( _vec1753 , ycirc );
                share * s_y_tmp_1757 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_1758 = 4294967295 ;
                share * s_y__tmp_1758 = ycirc->PutCONSGate( _tmp_1758 ,bitlen);
                share * s_y_tmp_1756 = ycirc->PutXORGate( s_y_tmp_1757 , s_y__tmp_1758 );
                vector<uint32_t> _vec1759 = s_y_tmp_1756->get_wires();
                _vec1759.erase( _vec1759.begin(), _vec1759.begin() + 1 );
                share *s_y_tmp_1755 = create_new_share( _vec1759 , ycirc );
                uint32_t _tmp_1760 = 4294967295 ;
                share * s_y__tmp_1760 = ycirc->PutCONSGate( _tmp_1760 ,bitlen);
                share * s_y_tmp_1754 = ycirc->PutXORGate( s_y_tmp_1755 , s_y__tmp_1760 );
                share * s_y_tmp_1747 = ycirc->PutMUXGate( s_y_tmp_1751 , s_y_tmp_1754 , s_y_tmp_1748 );
                vector<uint32_t> _vec1765 = s_y_tmp16->get_wires();
                _vec1765.erase( _vec1765.begin(), _vec1765.begin() + 1 );
                share *s_y_tmp_1764 = create_new_share( _vec1765 , ycirc );
                share * s_y_tmp_1763 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_1764 );
                uint32_t _tmp_1768 = 1 ;
                share * s_y__tmp_1768 = ycirc->PutCONSGate( _tmp_1768 ,bitlen);
                share * s_y_tmp_1767 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_1768 );
                uint32_t _tmp_1769 = 1 ;
                share * s_y__tmp_1769 = ycirc->PutCONSGate( _tmp_1769 ,bitlen);
                share * s_y_tmp_1766 = ycirc->PutEQGate( s_y_tmp_1767 , s_y__tmp_1769 );
                share * s_y_tmp_1762 = ycirc->PutANDGate( s_y_tmp_1763 , s_y_tmp_1766 );
                uint32_t _tmp_1772 = 2147483648 ;
                share * s_y__tmp_1772 = ycirc->PutCONSGate( _tmp_1772 ,bitlen);
                share * s_y_tmp_1771 = ycirc->PutGTGate( s_y__tmp_1772 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec1774 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec1774.erase( _vec1774.begin(), _vec1774.begin() + 1 );
                share *s_y_tmp_1773 = create_new_share( _vec1774 , ycirc );
                uint32_t _tmp_1778 = 4294967295 ;
                share * s_y__tmp_1778 = ycirc->PutCONSGate( _tmp_1778 ,bitlen);
                share * s_y_tmp_1777 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_1778 );
                vector<uint32_t> _vec1779 = s_y_tmp_1777->get_wires();
                _vec1779.erase( _vec1779.begin(), _vec1779.begin() + 1 );
                share *s_y_tmp_1776 = create_new_share( _vec1779 , ycirc );
                uint32_t _tmp_1780 = 4294967295 ;
                share * s_y__tmp_1780 = ycirc->PutCONSGate( _tmp_1780 ,bitlen);
                share * s_y_tmp_1775 = ycirc->PutXORGate( s_y_tmp_1776 , s_y__tmp_1780 );
                share * s_y_tmp_1770 = ycirc->PutMUXGate( s_y_tmp_1773 , s_y_tmp_1775 , s_y_tmp_1771 );
                uint32_t _tmp_1781 = 0 ;
                share * s_y__tmp_1781 = ycirc->PutCONSGate( _tmp_1781 ,bitlen);
                share * s_y_tmp_1761 = ycirc->PutMUXGate( s_y_tmp_1770 , s_y__tmp_1781 , s_y_tmp_1762 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_1747 , s_y_tmp_1761 , s_y_tmp_1744 );
                uint32_t _tmp_1782 = 1 ;
                share * s_y__tmp_1782 = ycirc->PutCONSGate( _tmp_1782 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_1782 );
            }
            uint32_t _tmp_1784 = 1 ;
            share * s_y__tmp_1784 = ycirc->PutCONSGate( _tmp_1784 ,bitlen);
            share * s_y_tmp_1783 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_1784 );
            vector<uint32_t> _vec1785 = s_y_tmp_1783->get_wires();
            _vec1785.erase( _vec1785.begin(), _vec1785.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec1785 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec1788 = s_y_tmp16->get_wires();
                _vec1788.erase( _vec1788.begin(), _vec1788.begin() + 1 );
                share *s_y_tmp_1787 = create_new_share( _vec1788 , ycirc );
                share * s_y_tmp_1786 = ycirc->PutGTGate( s_y_tmp_1787 , s_y_tmp17 );
                share * s_y_tmp_1789 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec1794 = s_y_tmp16->get_wires();
                _vec1794.erase( _vec1794.begin(), _vec1794.begin() + 1 );
                share *s_y_tmp_1793 = create_new_share( _vec1794 , ycirc );
                share * s_y_tmp_1792 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_1793 );
                uint32_t _tmp_1797 = 1 ;
                share * s_y__tmp_1797 = ycirc->PutCONSGate( _tmp_1797 ,bitlen);
                share * s_y_tmp_1796 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_1797 );
                uint32_t _tmp_1798 = 1 ;
                share * s_y__tmp_1798 = ycirc->PutCONSGate( _tmp_1798 ,bitlen);
                share * s_y_tmp_1795 = ycirc->PutEQGate( s_y_tmp_1796 , s_y__tmp_1798 );
                share * s_y_tmp_1791 = ycirc->PutANDGate( s_y_tmp_1792 , s_y_tmp_1795 );
                uint32_t _tmp_1799 = 0 ;
                share * s_y__tmp_1799 = ycirc->PutCONSGate( _tmp_1799 ,bitlen);
                share * s_y_tmp_1790 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_1799 , s_y_tmp_1791 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_1789 , s_y_tmp_1790 , s_y_tmp_1786 );
                uint32_t _tmp_1800 = 1 ;
                share * s_y__tmp_1800 = ycirc->PutCONSGate( _tmp_1800 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_1800 );
            }
            uint32_t _tmp_1802 = 1 ;
            share * s_y__tmp_1802 = ycirc->PutCONSGate( _tmp_1802 ,bitlen);
            share * s_y_tmp_1801 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_1802 );
            vector<uint32_t> _vec1803 = s_y_tmp_1801->get_wires();
            _vec1803.erase( _vec1803.begin(), _vec1803.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec1803 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_1805 = 2147483648 ;
share * s_y__tmp_1805 = ycirc->PutCONSGate( _tmp_1805 ,bitlen);
share * s_y_tmp_1804 = ycirc->PutGTGate( s_y__tmp_1805 , s_y_tmp10 );
vector<uint32_t> _vec1807 = s_y_tmp10->get_wires();
_vec1807.erase( _vec1807.begin(), _vec1807.begin() + 15 );
share *s_y_tmp_1806 = create_new_share( _vec1807 , ycirc );
uint32_t _tmp_1811 = 4294967295 ;
share * s_y__tmp_1811 = ycirc->PutCONSGate( _tmp_1811 ,bitlen);
share * s_y_tmp_1810 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_1811 );
vector<uint32_t> _vec1812 = s_y_tmp_1810->get_wires();
_vec1812.erase( _vec1812.begin(), _vec1812.begin() + 15 );
share *s_y_tmp_1809 = create_new_share( _vec1812 , ycirc );
uint32_t _tmp_1813 = 4294967295 ;
share * s_y__tmp_1813 = ycirc->PutCONSGate( _tmp_1813 ,bitlen);
share * s_y_tmp_1808 = ycirc->PutXORGate( s_y_tmp_1809 , s_y__tmp_1813 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_1806 , s_y_tmp_1808 , s_y_tmp_1804 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_1815 = 2147483648 ;
        share * s_y__tmp_1815 = ycirc->PutCONSGate( _tmp_1815 ,bitlen);
        share * s_y_tmp_1814 = ycirc->PutGTGate( s_y__tmp_1815 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec1817 = s_y_tmp12[i14][i15]->get_wires();
        _vec1817.erase( _vec1817.begin(), _vec1817.begin() + 15 );
        share *s_y_tmp_1816 = create_new_share( _vec1817 , ycirc );
        uint32_t _tmp_1821 = 4294967295 ;
        share * s_y__tmp_1821 = ycirc->PutCONSGate( _tmp_1821 ,bitlen);
        share * s_y_tmp_1820 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_1821 );
        vector<uint32_t> _vec1822 = s_y_tmp_1820->get_wires();
        _vec1822.erase( _vec1822.begin(), _vec1822.begin() + 15 );
        share *s_y_tmp_1819 = create_new_share( _vec1822 , ycirc );
        uint32_t _tmp_1823 = 4294967295 ;
        share * s_y__tmp_1823 = ycirc->PutCONSGate( _tmp_1823 ,bitlen);
        share * s_y_tmp_1818 = ycirc->PutXORGate( s_y_tmp_1819 , s_y__tmp_1823 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_1816 , s_y_tmp_1818 , s_y_tmp_1814 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_1825 = 2147483648 ;
        share * s_y__tmp_1825 = ycirc->PutCONSGate( _tmp_1825 ,bitlen);
        share * s_y_tmp_1824 = ycirc->PutGTGate( s_y__tmp_1825 , s_y_ZZ[6][i16][i17] );
        vector<uint32_t> _vec1827 = s_y_ZZ[6][i16][i17]->get_wires();
        _vec1827.erase( _vec1827.begin(), _vec1827.begin() + 15 );
        share *s_y_tmp_1826 = create_new_share( _vec1827 , ycirc );
        uint32_t _tmp_1831 = 4294967295 ;
        share * s_y__tmp_1831 = ycirc->PutCONSGate( _tmp_1831 ,bitlen);
        share * s_y_tmp_1830 = ycirc->PutXORGate( s_y_ZZ[6][i16][i17] , s_y__tmp_1831 );
        vector<uint32_t> _vec1832 = s_y_tmp_1830->get_wires();
        _vec1832.erase( _vec1832.begin(), _vec1832.begin() + 15 );
        share *s_y_tmp_1829 = create_new_share( _vec1832 , ycirc );
        uint32_t _tmp_1833 = 4294967295 ;
        share * s_y__tmp_1833 = ycirc->PutCONSGate( _tmp_1833 ,bitlen);
        share * s_y_tmp_1828 = ycirc->PutXORGate( s_y_tmp_1829 , s_y__tmp_1833 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_1826 , s_y_tmp_1828 , s_y_tmp_1824 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_1835 = 2147483648 ;
        share * s_y__tmp_1835 = ycirc->PutCONSGate( _tmp_1835 ,bitlen);
        share * s_y_tmp_1834 = ycirc->PutGTGate( s_y__tmp_1835 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec1837 = s_y_tmp21[i17][i18]->get_wires();
        _vec1837.erase( _vec1837.begin(), _vec1837.begin() + 15 );
        share *s_y_tmp_1836 = create_new_share( _vec1837 , ycirc );
        uint32_t _tmp_1841 = 4294967295 ;
        share * s_y__tmp_1841 = ycirc->PutCONSGate( _tmp_1841 ,bitlen);
        share * s_y_tmp_1840 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_1841 );
        vector<uint32_t> _vec1842 = s_y_tmp_1840->get_wires();
        _vec1842.erase( _vec1842.begin(), _vec1842.begin() + 15 );
        share *s_y_tmp_1839 = create_new_share( _vec1842 , ycirc );
        uint32_t _tmp_1843 = 4294967295 ;
        share * s_y__tmp_1843 = ycirc->PutCONSGate( _tmp_1843 ,bitlen);
        share * s_y_tmp_1838 = ycirc->PutXORGate( s_y_tmp_1839 , s_y__tmp_1843 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_1836 , s_y_tmp_1838 , s_y_tmp_1834 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1846 = s_y_tmp28->get_wires();
                _vec1846.erase( _vec1846.begin(), _vec1846.begin() + 1 );
                share *s_y_tmp_1845 = create_new_share( _vec1846 , ycirc );
                share * s_y_tmp_1844 = ycirc->PutGTGate( s_y_tmp_1845 , s_y_tmp29 );
                share * s_y_tmp_1849 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1850 = 2147483648 ;
                share * s_y__tmp_1850 = ycirc->PutCONSGate( _tmp_1850 ,bitlen);
                share * s_y_tmp_1848 = ycirc->PutGTGate( s_y__tmp_1850 , s_y_tmp_1849 );
                share * s_y_tmp_1852 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1853 = s_y_tmp_1852->get_wires();
                _vec1853.erase( _vec1853.begin(), _vec1853.begin() + 1 );
                share *s_y_tmp_1851 = create_new_share( _vec1853 , ycirc );
                share * s_y_tmp_1857 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_1858 = 4294967295 ;
                share * s_y__tmp_1858 = ycirc->PutCONSGate( _tmp_1858 ,bitlen);
                share * s_y_tmp_1856 = ycirc->PutXORGate( s_y_tmp_1857 , s_y__tmp_1858 );
                vector<uint32_t> _vec1859 = s_y_tmp_1856->get_wires();
                _vec1859.erase( _vec1859.begin(), _vec1859.begin() + 1 );
                share *s_y_tmp_1855 = create_new_share( _vec1859 , ycirc );
                uint32_t _tmp_1860 = 4294967295 ;
                share * s_y__tmp_1860 = ycirc->PutCONSGate( _tmp_1860 ,bitlen);
                share * s_y_tmp_1854 = ycirc->PutXORGate( s_y_tmp_1855 , s_y__tmp_1860 );
                share * s_y_tmp_1847 = ycirc->PutMUXGate( s_y_tmp_1851 , s_y_tmp_1854 , s_y_tmp_1848 );
                vector<uint32_t> _vec1865 = s_y_tmp28->get_wires();
                _vec1865.erase( _vec1865.begin(), _vec1865.begin() + 1 );
                share *s_y_tmp_1864 = create_new_share( _vec1865 , ycirc );
                share * s_y_tmp_1863 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1864 );
                uint32_t _tmp_1868 = 1 ;
                share * s_y__tmp_1868 = ycirc->PutCONSGate( _tmp_1868 ,bitlen);
                share * s_y_tmp_1867 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1868 );
                uint32_t _tmp_1869 = 1 ;
                share * s_y__tmp_1869 = ycirc->PutCONSGate( _tmp_1869 ,bitlen);
                share * s_y_tmp_1866 = ycirc->PutEQGate( s_y_tmp_1867 , s_y__tmp_1869 );
                share * s_y_tmp_1862 = ycirc->PutANDGate( s_y_tmp_1863 , s_y_tmp_1866 );
                uint32_t _tmp_1872 = 2147483648 ;
                share * s_y__tmp_1872 = ycirc->PutCONSGate( _tmp_1872 ,bitlen);
                share * s_y_tmp_1871 = ycirc->PutGTGate( s_y__tmp_1872 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec1874 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec1874.erase( _vec1874.begin(), _vec1874.begin() + 1 );
                share *s_y_tmp_1873 = create_new_share( _vec1874 , ycirc );
                uint32_t _tmp_1878 = 4294967295 ;
                share * s_y__tmp_1878 = ycirc->PutCONSGate( _tmp_1878 ,bitlen);
                share * s_y_tmp_1877 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1878 );
                vector<uint32_t> _vec1879 = s_y_tmp_1877->get_wires();
                _vec1879.erase( _vec1879.begin(), _vec1879.begin() + 1 );
                share *s_y_tmp_1876 = create_new_share( _vec1879 , ycirc );
                uint32_t _tmp_1880 = 4294967295 ;
                share * s_y__tmp_1880 = ycirc->PutCONSGate( _tmp_1880 ,bitlen);
                share * s_y_tmp_1875 = ycirc->PutXORGate( s_y_tmp_1876 , s_y__tmp_1880 );
                share * s_y_tmp_1870 = ycirc->PutMUXGate( s_y_tmp_1873 , s_y_tmp_1875 , s_y_tmp_1871 );
                uint32_t _tmp_1881 = 0 ;
                share * s_y__tmp_1881 = ycirc->PutCONSGate( _tmp_1881 ,bitlen);
                share * s_y_tmp_1861 = ycirc->PutMUXGate( s_y_tmp_1870 , s_y__tmp_1881 , s_y_tmp_1862 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1847 , s_y_tmp_1861 , s_y_tmp_1844 );
                uint32_t _tmp_1882 = 1 ;
                share * s_y__tmp_1882 = ycirc->PutCONSGate( _tmp_1882 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1882 );
            }
            uint32_t _tmp_1884 = 1 ;
            share * s_y__tmp_1884 = ycirc->PutCONSGate( _tmp_1884 ,bitlen);
            share * s_y_tmp_1883 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1884 );
            vector<uint32_t> _vec1885 = s_y_tmp_1883->get_wires();
            _vec1885.erase( _vec1885.begin(), _vec1885.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1885 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec1888 = s_y_tmp28->get_wires();
                _vec1888.erase( _vec1888.begin(), _vec1888.begin() + 1 );
                share *s_y_tmp_1887 = create_new_share( _vec1888 , ycirc );
                share * s_y_tmp_1886 = ycirc->PutGTGate( s_y_tmp_1887 , s_y_tmp29 );
                share * s_y_tmp_1889 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec1894 = s_y_tmp28->get_wires();
                _vec1894.erase( _vec1894.begin(), _vec1894.begin() + 1 );
                share *s_y_tmp_1893 = create_new_share( _vec1894 , ycirc );
                share * s_y_tmp_1892 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_1893 );
                uint32_t _tmp_1897 = 1 ;
                share * s_y__tmp_1897 = ycirc->PutCONSGate( _tmp_1897 ,bitlen);
                share * s_y_tmp_1896 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_1897 );
                uint32_t _tmp_1898 = 1 ;
                share * s_y__tmp_1898 = ycirc->PutCONSGate( _tmp_1898 ,bitlen);
                share * s_y_tmp_1895 = ycirc->PutEQGate( s_y_tmp_1896 , s_y__tmp_1898 );
                share * s_y_tmp_1891 = ycirc->PutANDGate( s_y_tmp_1892 , s_y_tmp_1895 );
                uint32_t _tmp_1899 = 0 ;
                share * s_y__tmp_1899 = ycirc->PutCONSGate( _tmp_1899 ,bitlen);
                share * s_y_tmp_1890 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_1899 , s_y_tmp_1891 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_1889 , s_y_tmp_1890 , s_y_tmp_1886 );
                uint32_t _tmp_1900 = 1 ;
                share * s_y__tmp_1900 = ycirc->PutCONSGate( _tmp_1900 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_1900 );
            }
            uint32_t _tmp_1902 = 1 ;
            share * s_y__tmp_1902 = ycirc->PutCONSGate( _tmp_1902 ,bitlen);
            share * s_y_tmp_1901 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_1902 );
            vector<uint32_t> _vec1903 = s_y_tmp_1901->get_wires();
            _vec1903.erase( _vec1903.begin(), _vec1903.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec1903 , ycirc );
        }
        s_y_tmp31[6][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_1905 = 2147483648 ;
        share * s_y__tmp_1905 = ycirc->PutCONSGate( _tmp_1905 ,bitlen);
        share * s_y_tmp_1904 = ycirc->PutGTGate( s_y__tmp_1905 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec1907 = s_y_WW[i0][i1]->get_wires();
        _vec1907.erase( _vec1907.begin(), _vec1907.begin() + 15 );
        share *s_y_tmp_1906 = create_new_share( _vec1907 , ycirc );
        uint32_t _tmp_1911 = 4294967295 ;
        share * s_y__tmp_1911 = ycirc->PutCONSGate( _tmp_1911 ,bitlen);
        share * s_y_tmp_1910 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_1911 );
        vector<uint32_t> _vec1912 = s_y_tmp_1910->get_wires();
        _vec1912.erase( _vec1912.begin(), _vec1912.begin() + 15 );
        share *s_y_tmp_1909 = create_new_share( _vec1912 , ycirc );
        uint32_t _tmp_1913 = 4294967295 ;
        share * s_y__tmp_1913 = ycirc->PutCONSGate( _tmp_1913 ,bitlen);
        share * s_y_tmp_1908 = ycirc->PutXORGate( s_y_tmp_1909 , s_y__tmp_1913 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_1906 , s_y_tmp_1908 , s_y_tmp_1904 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_1915 = 2147483648 ;
        share * s_y__tmp_1915 = ycirc->PutCONSGate( _tmp_1915 ,bitlen);
        share * s_y_tmp_1914 = ycirc->PutGTGate( s_y__tmp_1915 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec1917 = s_y_xx[i1][i2]->get_wires();
        _vec1917.erase( _vec1917.begin(), _vec1917.begin() + 15 );
        share *s_y_tmp_1916 = create_new_share( _vec1917 , ycirc );
        uint32_t _tmp_1921 = 4294967295 ;
        share * s_y__tmp_1921 = ycirc->PutCONSGate( _tmp_1921 ,bitlen);
        share * s_y_tmp_1920 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_1921 );
        vector<uint32_t> _vec1922 = s_y_tmp_1920->get_wires();
        _vec1922.erase( _vec1922.begin(), _vec1922.begin() + 15 );
        share *s_y_tmp_1919 = create_new_share( _vec1922 , ycirc );
        uint32_t _tmp_1923 = 4294967295 ;
        share * s_y__tmp_1923 = ycirc->PutCONSGate( _tmp_1923 ,bitlen);
        share * s_y_tmp_1918 = ycirc->PutXORGate( s_y_tmp_1919 , s_y__tmp_1923 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_1916 , s_y_tmp_1918 , s_y_tmp_1914 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1926 = s_y_tmp5->get_wires();
                _vec1926.erase( _vec1926.begin(), _vec1926.begin() + 1 );
                share *s_y_tmp_1925 = create_new_share( _vec1926 , ycirc );
                share * s_y_tmp_1924 = ycirc->PutGTGate( s_y_tmp_1925 , s_y_tmp6 );
                share * s_y_tmp_1929 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1930 = 2147483648 ;
                share * s_y__tmp_1930 = ycirc->PutCONSGate( _tmp_1930 ,bitlen);
                share * s_y_tmp_1928 = ycirc->PutGTGate( s_y__tmp_1930 , s_y_tmp_1929 );
                share * s_y_tmp_1932 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1933 = s_y_tmp_1932->get_wires();
                _vec1933.erase( _vec1933.begin(), _vec1933.begin() + 1 );
                share *s_y_tmp_1931 = create_new_share( _vec1933 , ycirc );
                share * s_y_tmp_1937 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_1938 = 4294967295 ;
                share * s_y__tmp_1938 = ycirc->PutCONSGate( _tmp_1938 ,bitlen);
                share * s_y_tmp_1936 = ycirc->PutXORGate( s_y_tmp_1937 , s_y__tmp_1938 );
                vector<uint32_t> _vec1939 = s_y_tmp_1936->get_wires();
                _vec1939.erase( _vec1939.begin(), _vec1939.begin() + 1 );
                share *s_y_tmp_1935 = create_new_share( _vec1939 , ycirc );
                uint32_t _tmp_1940 = 4294967295 ;
                share * s_y__tmp_1940 = ycirc->PutCONSGate( _tmp_1940 ,bitlen);
                share * s_y_tmp_1934 = ycirc->PutXORGate( s_y_tmp_1935 , s_y__tmp_1940 );
                share * s_y_tmp_1927 = ycirc->PutMUXGate( s_y_tmp_1931 , s_y_tmp_1934 , s_y_tmp_1928 );
                vector<uint32_t> _vec1945 = s_y_tmp5->get_wires();
                _vec1945.erase( _vec1945.begin(), _vec1945.begin() + 1 );
                share *s_y_tmp_1944 = create_new_share( _vec1945 , ycirc );
                share * s_y_tmp_1943 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1944 );
                uint32_t _tmp_1948 = 1 ;
                share * s_y__tmp_1948 = ycirc->PutCONSGate( _tmp_1948 ,bitlen);
                share * s_y_tmp_1947 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1948 );
                uint32_t _tmp_1949 = 1 ;
                share * s_y__tmp_1949 = ycirc->PutCONSGate( _tmp_1949 ,bitlen);
                share * s_y_tmp_1946 = ycirc->PutEQGate( s_y_tmp_1947 , s_y__tmp_1949 );
                share * s_y_tmp_1942 = ycirc->PutANDGate( s_y_tmp_1943 , s_y_tmp_1946 );
                uint32_t _tmp_1952 = 2147483648 ;
                share * s_y__tmp_1952 = ycirc->PutCONSGate( _tmp_1952 ,bitlen);
                share * s_y_tmp_1951 = ycirc->PutGTGate( s_y__tmp_1952 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec1954 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec1954.erase( _vec1954.begin(), _vec1954.begin() + 1 );
                share *s_y_tmp_1953 = create_new_share( _vec1954 , ycirc );
                uint32_t _tmp_1958 = 4294967295 ;
                share * s_y__tmp_1958 = ycirc->PutCONSGate( _tmp_1958 ,bitlen);
                share * s_y_tmp_1957 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1958 );
                vector<uint32_t> _vec1959 = s_y_tmp_1957->get_wires();
                _vec1959.erase( _vec1959.begin(), _vec1959.begin() + 1 );
                share *s_y_tmp_1956 = create_new_share( _vec1959 , ycirc );
                uint32_t _tmp_1960 = 4294967295 ;
                share * s_y__tmp_1960 = ycirc->PutCONSGate( _tmp_1960 ,bitlen);
                share * s_y_tmp_1955 = ycirc->PutXORGate( s_y_tmp_1956 , s_y__tmp_1960 );
                share * s_y_tmp_1950 = ycirc->PutMUXGate( s_y_tmp_1953 , s_y_tmp_1955 , s_y_tmp_1951 );
                uint32_t _tmp_1961 = 0 ;
                share * s_y__tmp_1961 = ycirc->PutCONSGate( _tmp_1961 ,bitlen);
                share * s_y_tmp_1941 = ycirc->PutMUXGate( s_y_tmp_1950 , s_y__tmp_1961 , s_y_tmp_1942 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1927 , s_y_tmp_1941 , s_y_tmp_1924 );
                uint32_t _tmp_1962 = 1 ;
                share * s_y__tmp_1962 = ycirc->PutCONSGate( _tmp_1962 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1962 );
            }
            uint32_t _tmp_1964 = 1 ;
            share * s_y__tmp_1964 = ycirc->PutCONSGate( _tmp_1964 ,bitlen);
            share * s_y_tmp_1963 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1964 );
            vector<uint32_t> _vec1965 = s_y_tmp_1963->get_wires();
            _vec1965.erase( _vec1965.begin(), _vec1965.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1965 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec1968 = s_y_tmp5->get_wires();
                _vec1968.erase( _vec1968.begin(), _vec1968.begin() + 1 );
                share *s_y_tmp_1967 = create_new_share( _vec1968 , ycirc );
                share * s_y_tmp_1966 = ycirc->PutGTGate( s_y_tmp_1967 , s_y_tmp6 );
                share * s_y_tmp_1969 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec1974 = s_y_tmp5->get_wires();
                _vec1974.erase( _vec1974.begin(), _vec1974.begin() + 1 );
                share *s_y_tmp_1973 = create_new_share( _vec1974 , ycirc );
                share * s_y_tmp_1972 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_1973 );
                uint32_t _tmp_1977 = 1 ;
                share * s_y__tmp_1977 = ycirc->PutCONSGate( _tmp_1977 ,bitlen);
                share * s_y_tmp_1976 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_1977 );
                uint32_t _tmp_1978 = 1 ;
                share * s_y__tmp_1978 = ycirc->PutCONSGate( _tmp_1978 ,bitlen);
                share * s_y_tmp_1975 = ycirc->PutEQGate( s_y_tmp_1976 , s_y__tmp_1978 );
                share * s_y_tmp_1971 = ycirc->PutANDGate( s_y_tmp_1972 , s_y_tmp_1975 );
                uint32_t _tmp_1979 = 0 ;
                share * s_y__tmp_1979 = ycirc->PutCONSGate( _tmp_1979 ,bitlen);
                share * s_y_tmp_1970 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_1979 , s_y_tmp_1971 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_1969 , s_y_tmp_1970 , s_y_tmp_1966 );
                uint32_t _tmp_1980 = 1 ;
                share * s_y__tmp_1980 = ycirc->PutCONSGate( _tmp_1980 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_1980 );
            }
            uint32_t _tmp_1982 = 1 ;
            share * s_y__tmp_1982 = ycirc->PutCONSGate( _tmp_1982 ,bitlen);
            share * s_y_tmp_1981 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_1982 );
            vector<uint32_t> _vec1983 = s_y_tmp_1981->get_wires();
            _vec1983.erase( _vec1983.begin(), _vec1983.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec1983 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_1985 = 2147483648 ;
        share * s_y__tmp_1985 = ycirc->PutCONSGate( _tmp_1985 ,bitlen);
        share * s_y_tmp_1984 = ycirc->PutGTGate( s_y__tmp_1985 , s_y_BB[7][i5][i6] );
        vector<uint32_t> _vec1987 = s_y_BB[7][i5][i6]->get_wires();
        _vec1987.erase( _vec1987.begin(), _vec1987.begin() + 4 );
        share *s_y_tmp_1986 = create_new_share( _vec1987 , ycirc );
        uint32_t _tmp_1991 = 4294967295 ;
        share * s_y__tmp_1991 = ycirc->PutCONSGate( _tmp_1991 ,bitlen);
        share * s_y_tmp_1990 = ycirc->PutXORGate( s_y_BB[7][i5][i6] , s_y__tmp_1991 );
        vector<uint32_t> _vec1992 = s_y_tmp_1990->get_wires();
        _vec1992.erase( _vec1992.begin(), _vec1992.begin() + 4 );
        share *s_y_tmp_1989 = create_new_share( _vec1992 , ycirc );
        uint32_t _tmp_1993 = 4294967295 ;
        share * s_y__tmp_1993 = ycirc->PutCONSGate( _tmp_1993 ,bitlen);
        share * s_y_tmp_1988 = ycirc->PutXORGate( s_y_tmp_1989 , s_y__tmp_1993 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_1986 , s_y_tmp_1988 , s_y_tmp_1984 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_1994 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_1995 = 1 ;
share * s_a__tmp_1995 = acirc->PutCONSGate( _tmp_1995 ,bitlen);
share *s_a_tmp_1994 = acirc->PutY2AGate( s_y_tmp_1994 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_1994 , s_a__tmp_1995 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_1997 = 2147483648 ;
        share * s_y__tmp_1997 = ycirc->PutCONSGate( _tmp_1997 ,bitlen);
        share * s_y_tmp_1996 = ycirc->PutGTGate( s_y__tmp_1997 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec1999 = s_y_tmp11[i9][i10]->get_wires();
        _vec1999.erase( _vec1999.begin(), _vec1999.begin() + 15 );
        share *s_y_tmp_1998 = create_new_share( _vec1999 , ycirc );
        uint32_t _tmp_2003 = 4294967295 ;
        share * s_y__tmp_2003 = ycirc->PutCONSGate( _tmp_2003 ,bitlen);
        share * s_y_tmp_2002 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_2003 );
        vector<uint32_t> _vec2004 = s_y_tmp_2002->get_wires();
        _vec2004.erase( _vec2004.begin(), _vec2004.begin() + 15 );
        share *s_y_tmp_2001 = create_new_share( _vec2004 , ycirc );
        uint32_t _tmp_2005 = 4294967295 ;
        share * s_y__tmp_2005 = ycirc->PutCONSGate( _tmp_2005 ,bitlen);
        share * s_y_tmp_2000 = ycirc->PutXORGate( s_y_tmp_2001 , s_y__tmp_2005 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_1998 , s_y_tmp_2000 , s_y_tmp_1996 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_2007 = 2147483648 ;
        share * s_y__tmp_2007 = ycirc->PutCONSGate( _tmp_2007 ,bitlen);
        share * s_y_tmp_2006 = ycirc->PutGTGate( s_y__tmp_2007 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec2009 = s_y_tmp7[i10][i11]->get_wires();
        _vec2009.erase( _vec2009.begin(), _vec2009.begin() + 15 );
        share *s_y_tmp_2008 = create_new_share( _vec2009 , ycirc );
        uint32_t _tmp_2013 = 4294967295 ;
        share * s_y__tmp_2013 = ycirc->PutCONSGate( _tmp_2013 ,bitlen);
        share * s_y_tmp_2012 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_2013 );
        vector<uint32_t> _vec2014 = s_y_tmp_2012->get_wires();
        _vec2014.erase( _vec2014.begin(), _vec2014.begin() + 15 );
        share *s_y_tmp_2011 = create_new_share( _vec2014 , ycirc );
        uint32_t _tmp_2015 = 4294967295 ;
        share * s_y__tmp_2015 = ycirc->PutCONSGate( _tmp_2015 ,bitlen);
        share * s_y_tmp_2010 = ycirc->PutXORGate( s_y_tmp_2011 , s_y__tmp_2015 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_2008 , s_y_tmp_2010 , s_y_tmp_2006 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec2018 = s_y_tmp16->get_wires();
                _vec2018.erase( _vec2018.begin(), _vec2018.begin() + 1 );
                share *s_y_tmp_2017 = create_new_share( _vec2018 , ycirc );
                share * s_y_tmp_2016 = ycirc->PutGTGate( s_y_tmp_2017 , s_y_tmp17 );
                share * s_y_tmp_2021 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_2022 = 2147483648 ;
                share * s_y__tmp_2022 = ycirc->PutCONSGate( _tmp_2022 ,bitlen);
                share * s_y_tmp_2020 = ycirc->PutGTGate( s_y__tmp_2022 , s_y_tmp_2021 );
                share * s_y_tmp_2024 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec2025 = s_y_tmp_2024->get_wires();
                _vec2025.erase( _vec2025.begin(), _vec2025.begin() + 1 );
                share *s_y_tmp_2023 = create_new_share( _vec2025 , ycirc );
                share * s_y_tmp_2029 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_2030 = 4294967295 ;
                share * s_y__tmp_2030 = ycirc->PutCONSGate( _tmp_2030 ,bitlen);
                share * s_y_tmp_2028 = ycirc->PutXORGate( s_y_tmp_2029 , s_y__tmp_2030 );
                vector<uint32_t> _vec2031 = s_y_tmp_2028->get_wires();
                _vec2031.erase( _vec2031.begin(), _vec2031.begin() + 1 );
                share *s_y_tmp_2027 = create_new_share( _vec2031 , ycirc );
                uint32_t _tmp_2032 = 4294967295 ;
                share * s_y__tmp_2032 = ycirc->PutCONSGate( _tmp_2032 ,bitlen);
                share * s_y_tmp_2026 = ycirc->PutXORGate( s_y_tmp_2027 , s_y__tmp_2032 );
                share * s_y_tmp_2019 = ycirc->PutMUXGate( s_y_tmp_2023 , s_y_tmp_2026 , s_y_tmp_2020 );
                vector<uint32_t> _vec2037 = s_y_tmp16->get_wires();
                _vec2037.erase( _vec2037.begin(), _vec2037.begin() + 1 );
                share *s_y_tmp_2036 = create_new_share( _vec2037 , ycirc );
                share * s_y_tmp_2035 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_2036 );
                uint32_t _tmp_2040 = 1 ;
                share * s_y__tmp_2040 = ycirc->PutCONSGate( _tmp_2040 ,bitlen);
                share * s_y_tmp_2039 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_2040 );
                uint32_t _tmp_2041 = 1 ;
                share * s_y__tmp_2041 = ycirc->PutCONSGate( _tmp_2041 ,bitlen);
                share * s_y_tmp_2038 = ycirc->PutEQGate( s_y_tmp_2039 , s_y__tmp_2041 );
                share * s_y_tmp_2034 = ycirc->PutANDGate( s_y_tmp_2035 , s_y_tmp_2038 );
                uint32_t _tmp_2044 = 2147483648 ;
                share * s_y__tmp_2044 = ycirc->PutCONSGate( _tmp_2044 ,bitlen);
                share * s_y_tmp_2043 = ycirc->PutGTGate( s_y__tmp_2044 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec2046 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec2046.erase( _vec2046.begin(), _vec2046.begin() + 1 );
                share *s_y_tmp_2045 = create_new_share( _vec2046 , ycirc );
                uint32_t _tmp_2050 = 4294967295 ;
                share * s_y__tmp_2050 = ycirc->PutCONSGate( _tmp_2050 ,bitlen);
                share * s_y_tmp_2049 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_2050 );
                vector<uint32_t> _vec2051 = s_y_tmp_2049->get_wires();
                _vec2051.erase( _vec2051.begin(), _vec2051.begin() + 1 );
                share *s_y_tmp_2048 = create_new_share( _vec2051 , ycirc );
                uint32_t _tmp_2052 = 4294967295 ;
                share * s_y__tmp_2052 = ycirc->PutCONSGate( _tmp_2052 ,bitlen);
                share * s_y_tmp_2047 = ycirc->PutXORGate( s_y_tmp_2048 , s_y__tmp_2052 );
                share * s_y_tmp_2042 = ycirc->PutMUXGate( s_y_tmp_2045 , s_y_tmp_2047 , s_y_tmp_2043 );
                uint32_t _tmp_2053 = 0 ;
                share * s_y__tmp_2053 = ycirc->PutCONSGate( _tmp_2053 ,bitlen);
                share * s_y_tmp_2033 = ycirc->PutMUXGate( s_y_tmp_2042 , s_y__tmp_2053 , s_y_tmp_2034 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_2019 , s_y_tmp_2033 , s_y_tmp_2016 );
                uint32_t _tmp_2054 = 1 ;
                share * s_y__tmp_2054 = ycirc->PutCONSGate( _tmp_2054 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_2054 );
            }
            uint32_t _tmp_2056 = 1 ;
            share * s_y__tmp_2056 = ycirc->PutCONSGate( _tmp_2056 ,bitlen);
            share * s_y_tmp_2055 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_2056 );
            vector<uint32_t> _vec2057 = s_y_tmp_2055->get_wires();
            _vec2057.erase( _vec2057.begin(), _vec2057.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec2057 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec2060 = s_y_tmp16->get_wires();
                _vec2060.erase( _vec2060.begin(), _vec2060.begin() + 1 );
                share *s_y_tmp_2059 = create_new_share( _vec2060 , ycirc );
                share * s_y_tmp_2058 = ycirc->PutGTGate( s_y_tmp_2059 , s_y_tmp17 );
                share * s_y_tmp_2061 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec2066 = s_y_tmp16->get_wires();
                _vec2066.erase( _vec2066.begin(), _vec2066.begin() + 1 );
                share *s_y_tmp_2065 = create_new_share( _vec2066 , ycirc );
                share * s_y_tmp_2064 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_2065 );
                uint32_t _tmp_2069 = 1 ;
                share * s_y__tmp_2069 = ycirc->PutCONSGate( _tmp_2069 ,bitlen);
                share * s_y_tmp_2068 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_2069 );
                uint32_t _tmp_2070 = 1 ;
                share * s_y__tmp_2070 = ycirc->PutCONSGate( _tmp_2070 ,bitlen);
                share * s_y_tmp_2067 = ycirc->PutEQGate( s_y_tmp_2068 , s_y__tmp_2070 );
                share * s_y_tmp_2063 = ycirc->PutANDGate( s_y_tmp_2064 , s_y_tmp_2067 );
                uint32_t _tmp_2071 = 0 ;
                share * s_y__tmp_2071 = ycirc->PutCONSGate( _tmp_2071 ,bitlen);
                share * s_y_tmp_2062 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_2071 , s_y_tmp_2063 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_2061 , s_y_tmp_2062 , s_y_tmp_2058 );
                uint32_t _tmp_2072 = 1 ;
                share * s_y__tmp_2072 = ycirc->PutCONSGate( _tmp_2072 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_2072 );
            }
            uint32_t _tmp_2074 = 1 ;
            share * s_y__tmp_2074 = ycirc->PutCONSGate( _tmp_2074 ,bitlen);
            share * s_y_tmp_2073 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_2074 );
            vector<uint32_t> _vec2075 = s_y_tmp_2073->get_wires();
            _vec2075.erase( _vec2075.begin(), _vec2075.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec2075 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_2077 = 2147483648 ;
share * s_y__tmp_2077 = ycirc->PutCONSGate( _tmp_2077 ,bitlen);
share * s_y_tmp_2076 = ycirc->PutGTGate( s_y__tmp_2077 , s_y_tmp10 );
vector<uint32_t> _vec2079 = s_y_tmp10->get_wires();
_vec2079.erase( _vec2079.begin(), _vec2079.begin() + 15 );
share *s_y_tmp_2078 = create_new_share( _vec2079 , ycirc );
uint32_t _tmp_2083 = 4294967295 ;
share * s_y__tmp_2083 = ycirc->PutCONSGate( _tmp_2083 ,bitlen);
share * s_y_tmp_2082 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_2083 );
vector<uint32_t> _vec2084 = s_y_tmp_2082->get_wires();
_vec2084.erase( _vec2084.begin(), _vec2084.begin() + 15 );
share *s_y_tmp_2081 = create_new_share( _vec2084 , ycirc );
uint32_t _tmp_2085 = 4294967295 ;
share * s_y__tmp_2085 = ycirc->PutCONSGate( _tmp_2085 ,bitlen);
share * s_y_tmp_2080 = ycirc->PutXORGate( s_y_tmp_2081 , s_y__tmp_2085 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_2078 , s_y_tmp_2080 , s_y_tmp_2076 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_2087 = 2147483648 ;
        share * s_y__tmp_2087 = ycirc->PutCONSGate( _tmp_2087 ,bitlen);
        share * s_y_tmp_2086 = ycirc->PutGTGate( s_y__tmp_2087 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec2089 = s_y_tmp12[i14][i15]->get_wires();
        _vec2089.erase( _vec2089.begin(), _vec2089.begin() + 15 );
        share *s_y_tmp_2088 = create_new_share( _vec2089 , ycirc );
        uint32_t _tmp_2093 = 4294967295 ;
        share * s_y__tmp_2093 = ycirc->PutCONSGate( _tmp_2093 ,bitlen);
        share * s_y_tmp_2092 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_2093 );
        vector<uint32_t> _vec2094 = s_y_tmp_2092->get_wires();
        _vec2094.erase( _vec2094.begin(), _vec2094.begin() + 15 );
        share *s_y_tmp_2091 = create_new_share( _vec2094 , ycirc );
        uint32_t _tmp_2095 = 4294967295 ;
        share * s_y__tmp_2095 = ycirc->PutCONSGate( _tmp_2095 ,bitlen);
        share * s_y_tmp_2090 = ycirc->PutXORGate( s_y_tmp_2091 , s_y__tmp_2095 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_2088 , s_y_tmp_2090 , s_y_tmp_2086 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_2097 = 2147483648 ;
        share * s_y__tmp_2097 = ycirc->PutCONSGate( _tmp_2097 ,bitlen);
        share * s_y_tmp_2096 = ycirc->PutGTGate( s_y__tmp_2097 , s_y_ZZ[7][i16][i17] );
        vector<uint32_t> _vec2099 = s_y_ZZ[7][i16][i17]->get_wires();
        _vec2099.erase( _vec2099.begin(), _vec2099.begin() + 15 );
        share *s_y_tmp_2098 = create_new_share( _vec2099 , ycirc );
        uint32_t _tmp_2103 = 4294967295 ;
        share * s_y__tmp_2103 = ycirc->PutCONSGate( _tmp_2103 ,bitlen);
        share * s_y_tmp_2102 = ycirc->PutXORGate( s_y_ZZ[7][i16][i17] , s_y__tmp_2103 );
        vector<uint32_t> _vec2104 = s_y_tmp_2102->get_wires();
        _vec2104.erase( _vec2104.begin(), _vec2104.begin() + 15 );
        share *s_y_tmp_2101 = create_new_share( _vec2104 , ycirc );
        uint32_t _tmp_2105 = 4294967295 ;
        share * s_y__tmp_2105 = ycirc->PutCONSGate( _tmp_2105 ,bitlen);
        share * s_y_tmp_2100 = ycirc->PutXORGate( s_y_tmp_2101 , s_y__tmp_2105 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_2098 , s_y_tmp_2100 , s_y_tmp_2096 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_2107 = 2147483648 ;
        share * s_y__tmp_2107 = ycirc->PutCONSGate( _tmp_2107 ,bitlen);
        share * s_y_tmp_2106 = ycirc->PutGTGate( s_y__tmp_2107 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec2109 = s_y_tmp21[i17][i18]->get_wires();
        _vec2109.erase( _vec2109.begin(), _vec2109.begin() + 15 );
        share *s_y_tmp_2108 = create_new_share( _vec2109 , ycirc );
        uint32_t _tmp_2113 = 4294967295 ;
        share * s_y__tmp_2113 = ycirc->PutCONSGate( _tmp_2113 ,bitlen);
        share * s_y_tmp_2112 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_2113 );
        vector<uint32_t> _vec2114 = s_y_tmp_2112->get_wires();
        _vec2114.erase( _vec2114.begin(), _vec2114.begin() + 15 );
        share *s_y_tmp_2111 = create_new_share( _vec2114 , ycirc );
        uint32_t _tmp_2115 = 4294967295 ;
        share * s_y__tmp_2115 = ycirc->PutCONSGate( _tmp_2115 ,bitlen);
        share * s_y_tmp_2110 = ycirc->PutXORGate( s_y_tmp_2111 , s_y__tmp_2115 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_2108 , s_y_tmp_2110 , s_y_tmp_2106 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec2118 = s_y_tmp28->get_wires();
                _vec2118.erase( _vec2118.begin(), _vec2118.begin() + 1 );
                share *s_y_tmp_2117 = create_new_share( _vec2118 , ycirc );
                share * s_y_tmp_2116 = ycirc->PutGTGate( s_y_tmp_2117 , s_y_tmp29 );
                share * s_y_tmp_2121 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_2122 = 2147483648 ;
                share * s_y__tmp_2122 = ycirc->PutCONSGate( _tmp_2122 ,bitlen);
                share * s_y_tmp_2120 = ycirc->PutGTGate( s_y__tmp_2122 , s_y_tmp_2121 );
                share * s_y_tmp_2124 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec2125 = s_y_tmp_2124->get_wires();
                _vec2125.erase( _vec2125.begin(), _vec2125.begin() + 1 );
                share *s_y_tmp_2123 = create_new_share( _vec2125 , ycirc );
                share * s_y_tmp_2129 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_2130 = 4294967295 ;
                share * s_y__tmp_2130 = ycirc->PutCONSGate( _tmp_2130 ,bitlen);
                share * s_y_tmp_2128 = ycirc->PutXORGate( s_y_tmp_2129 , s_y__tmp_2130 );
                vector<uint32_t> _vec2131 = s_y_tmp_2128->get_wires();
                _vec2131.erase( _vec2131.begin(), _vec2131.begin() + 1 );
                share *s_y_tmp_2127 = create_new_share( _vec2131 , ycirc );
                uint32_t _tmp_2132 = 4294967295 ;
                share * s_y__tmp_2132 = ycirc->PutCONSGate( _tmp_2132 ,bitlen);
                share * s_y_tmp_2126 = ycirc->PutXORGate( s_y_tmp_2127 , s_y__tmp_2132 );
                share * s_y_tmp_2119 = ycirc->PutMUXGate( s_y_tmp_2123 , s_y_tmp_2126 , s_y_tmp_2120 );
                vector<uint32_t> _vec2137 = s_y_tmp28->get_wires();
                _vec2137.erase( _vec2137.begin(), _vec2137.begin() + 1 );
                share *s_y_tmp_2136 = create_new_share( _vec2137 , ycirc );
                share * s_y_tmp_2135 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_2136 );
                uint32_t _tmp_2140 = 1 ;
                share * s_y__tmp_2140 = ycirc->PutCONSGate( _tmp_2140 ,bitlen);
                share * s_y_tmp_2139 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_2140 );
                uint32_t _tmp_2141 = 1 ;
                share * s_y__tmp_2141 = ycirc->PutCONSGate( _tmp_2141 ,bitlen);
                share * s_y_tmp_2138 = ycirc->PutEQGate( s_y_tmp_2139 , s_y__tmp_2141 );
                share * s_y_tmp_2134 = ycirc->PutANDGate( s_y_tmp_2135 , s_y_tmp_2138 );
                uint32_t _tmp_2144 = 2147483648 ;
                share * s_y__tmp_2144 = ycirc->PutCONSGate( _tmp_2144 ,bitlen);
                share * s_y_tmp_2143 = ycirc->PutGTGate( s_y__tmp_2144 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec2146 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec2146.erase( _vec2146.begin(), _vec2146.begin() + 1 );
                share *s_y_tmp_2145 = create_new_share( _vec2146 , ycirc );
                uint32_t _tmp_2150 = 4294967295 ;
                share * s_y__tmp_2150 = ycirc->PutCONSGate( _tmp_2150 ,bitlen);
                share * s_y_tmp_2149 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_2150 );
                vector<uint32_t> _vec2151 = s_y_tmp_2149->get_wires();
                _vec2151.erase( _vec2151.begin(), _vec2151.begin() + 1 );
                share *s_y_tmp_2148 = create_new_share( _vec2151 , ycirc );
                uint32_t _tmp_2152 = 4294967295 ;
                share * s_y__tmp_2152 = ycirc->PutCONSGate( _tmp_2152 ,bitlen);
                share * s_y_tmp_2147 = ycirc->PutXORGate( s_y_tmp_2148 , s_y__tmp_2152 );
                share * s_y_tmp_2142 = ycirc->PutMUXGate( s_y_tmp_2145 , s_y_tmp_2147 , s_y_tmp_2143 );
                uint32_t _tmp_2153 = 0 ;
                share * s_y__tmp_2153 = ycirc->PutCONSGate( _tmp_2153 ,bitlen);
                share * s_y_tmp_2133 = ycirc->PutMUXGate( s_y_tmp_2142 , s_y__tmp_2153 , s_y_tmp_2134 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_2119 , s_y_tmp_2133 , s_y_tmp_2116 );
                uint32_t _tmp_2154 = 1 ;
                share * s_y__tmp_2154 = ycirc->PutCONSGate( _tmp_2154 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_2154 );
            }
            uint32_t _tmp_2156 = 1 ;
            share * s_y__tmp_2156 = ycirc->PutCONSGate( _tmp_2156 ,bitlen);
            share * s_y_tmp_2155 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_2156 );
            vector<uint32_t> _vec2157 = s_y_tmp_2155->get_wires();
            _vec2157.erase( _vec2157.begin(), _vec2157.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec2157 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec2160 = s_y_tmp28->get_wires();
                _vec2160.erase( _vec2160.begin(), _vec2160.begin() + 1 );
                share *s_y_tmp_2159 = create_new_share( _vec2160 , ycirc );
                share * s_y_tmp_2158 = ycirc->PutGTGate( s_y_tmp_2159 , s_y_tmp29 );
                share * s_y_tmp_2161 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec2166 = s_y_tmp28->get_wires();
                _vec2166.erase( _vec2166.begin(), _vec2166.begin() + 1 );
                share *s_y_tmp_2165 = create_new_share( _vec2166 , ycirc );
                share * s_y_tmp_2164 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_2165 );
                uint32_t _tmp_2169 = 1 ;
                share * s_y__tmp_2169 = ycirc->PutCONSGate( _tmp_2169 ,bitlen);
                share * s_y_tmp_2168 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_2169 );
                uint32_t _tmp_2170 = 1 ;
                share * s_y__tmp_2170 = ycirc->PutCONSGate( _tmp_2170 ,bitlen);
                share * s_y_tmp_2167 = ycirc->PutEQGate( s_y_tmp_2168 , s_y__tmp_2170 );
                share * s_y_tmp_2163 = ycirc->PutANDGate( s_y_tmp_2164 , s_y_tmp_2167 );
                uint32_t _tmp_2171 = 0 ;
                share * s_y__tmp_2171 = ycirc->PutCONSGate( _tmp_2171 ,bitlen);
                share * s_y_tmp_2162 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_2171 , s_y_tmp_2163 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_2161 , s_y_tmp_2162 , s_y_tmp_2158 );
                uint32_t _tmp_2172 = 1 ;
                share * s_y__tmp_2172 = ycirc->PutCONSGate( _tmp_2172 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_2172 );
            }
            uint32_t _tmp_2174 = 1 ;
            share * s_y__tmp_2174 = ycirc->PutCONSGate( _tmp_2174 ,bitlen);
            share * s_y_tmp_2173 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_2174 );
            vector<uint32_t> _vec2175 = s_y_tmp_2173->get_wires();
            _vec2175.erase( _vec2175.begin(), _vec2175.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec2175 , ycirc );
        }
        s_y_tmp31[7][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_2177 = 2147483648 ;
        share * s_y__tmp_2177 = ycirc->PutCONSGate( _tmp_2177 ,bitlen);
        share * s_y_tmp_2176 = ycirc->PutGTGate( s_y__tmp_2177 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec2179 = s_y_WW[i0][i1]->get_wires();
        _vec2179.erase( _vec2179.begin(), _vec2179.begin() + 15 );
        share *s_y_tmp_2178 = create_new_share( _vec2179 , ycirc );
        uint32_t _tmp_2183 = 4294967295 ;
        share * s_y__tmp_2183 = ycirc->PutCONSGate( _tmp_2183 ,bitlen);
        share * s_y_tmp_2182 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_2183 );
        vector<uint32_t> _vec2184 = s_y_tmp_2182->get_wires();
        _vec2184.erase( _vec2184.begin(), _vec2184.begin() + 15 );
        share *s_y_tmp_2181 = create_new_share( _vec2184 , ycirc );
        uint32_t _tmp_2185 = 4294967295 ;
        share * s_y__tmp_2185 = ycirc->PutCONSGate( _tmp_2185 ,bitlen);
        share * s_y_tmp_2180 = ycirc->PutXORGate( s_y_tmp_2181 , s_y__tmp_2185 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_2178 , s_y_tmp_2180 , s_y_tmp_2176 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_2187 = 2147483648 ;
        share * s_y__tmp_2187 = ycirc->PutCONSGate( _tmp_2187 ,bitlen);
        share * s_y_tmp_2186 = ycirc->PutGTGate( s_y__tmp_2187 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec2189 = s_y_xx[i1][i2]->get_wires();
        _vec2189.erase( _vec2189.begin(), _vec2189.begin() + 15 );
        share *s_y_tmp_2188 = create_new_share( _vec2189 , ycirc );
        uint32_t _tmp_2193 = 4294967295 ;
        share * s_y__tmp_2193 = ycirc->PutCONSGate( _tmp_2193 ,bitlen);
        share * s_y_tmp_2192 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_2193 );
        vector<uint32_t> _vec2194 = s_y_tmp_2192->get_wires();
        _vec2194.erase( _vec2194.begin(), _vec2194.begin() + 15 );
        share *s_y_tmp_2191 = create_new_share( _vec2194 , ycirc );
        uint32_t _tmp_2195 = 4294967295 ;
        share * s_y__tmp_2195 = ycirc->PutCONSGate( _tmp_2195 ,bitlen);
        share * s_y_tmp_2190 = ycirc->PutXORGate( s_y_tmp_2191 , s_y__tmp_2195 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_2188 , s_y_tmp_2190 , s_y_tmp_2186 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec2198 = s_y_tmp5->get_wires();
                _vec2198.erase( _vec2198.begin(), _vec2198.begin() + 1 );
                share *s_y_tmp_2197 = create_new_share( _vec2198 , ycirc );
                share * s_y_tmp_2196 = ycirc->PutGTGate( s_y_tmp_2197 , s_y_tmp6 );
                share * s_y_tmp_2201 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_2202 = 2147483648 ;
                share * s_y__tmp_2202 = ycirc->PutCONSGate( _tmp_2202 ,bitlen);
                share * s_y_tmp_2200 = ycirc->PutGTGate( s_y__tmp_2202 , s_y_tmp_2201 );
                share * s_y_tmp_2204 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec2205 = s_y_tmp_2204->get_wires();
                _vec2205.erase( _vec2205.begin(), _vec2205.begin() + 1 );
                share *s_y_tmp_2203 = create_new_share( _vec2205 , ycirc );
                share * s_y_tmp_2209 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_2210 = 4294967295 ;
                share * s_y__tmp_2210 = ycirc->PutCONSGate( _tmp_2210 ,bitlen);
                share * s_y_tmp_2208 = ycirc->PutXORGate( s_y_tmp_2209 , s_y__tmp_2210 );
                vector<uint32_t> _vec2211 = s_y_tmp_2208->get_wires();
                _vec2211.erase( _vec2211.begin(), _vec2211.begin() + 1 );
                share *s_y_tmp_2207 = create_new_share( _vec2211 , ycirc );
                uint32_t _tmp_2212 = 4294967295 ;
                share * s_y__tmp_2212 = ycirc->PutCONSGate( _tmp_2212 ,bitlen);
                share * s_y_tmp_2206 = ycirc->PutXORGate( s_y_tmp_2207 , s_y__tmp_2212 );
                share * s_y_tmp_2199 = ycirc->PutMUXGate( s_y_tmp_2203 , s_y_tmp_2206 , s_y_tmp_2200 );
                vector<uint32_t> _vec2217 = s_y_tmp5->get_wires();
                _vec2217.erase( _vec2217.begin(), _vec2217.begin() + 1 );
                share *s_y_tmp_2216 = create_new_share( _vec2217 , ycirc );
                share * s_y_tmp_2215 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_2216 );
                uint32_t _tmp_2220 = 1 ;
                share * s_y__tmp_2220 = ycirc->PutCONSGate( _tmp_2220 ,bitlen);
                share * s_y_tmp_2219 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_2220 );
                uint32_t _tmp_2221 = 1 ;
                share * s_y__tmp_2221 = ycirc->PutCONSGate( _tmp_2221 ,bitlen);
                share * s_y_tmp_2218 = ycirc->PutEQGate( s_y_tmp_2219 , s_y__tmp_2221 );
                share * s_y_tmp_2214 = ycirc->PutANDGate( s_y_tmp_2215 , s_y_tmp_2218 );
                uint32_t _tmp_2224 = 2147483648 ;
                share * s_y__tmp_2224 = ycirc->PutCONSGate( _tmp_2224 ,bitlen);
                share * s_y_tmp_2223 = ycirc->PutGTGate( s_y__tmp_2224 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec2226 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec2226.erase( _vec2226.begin(), _vec2226.begin() + 1 );
                share *s_y_tmp_2225 = create_new_share( _vec2226 , ycirc );
                uint32_t _tmp_2230 = 4294967295 ;
                share * s_y__tmp_2230 = ycirc->PutCONSGate( _tmp_2230 ,bitlen);
                share * s_y_tmp_2229 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_2230 );
                vector<uint32_t> _vec2231 = s_y_tmp_2229->get_wires();
                _vec2231.erase( _vec2231.begin(), _vec2231.begin() + 1 );
                share *s_y_tmp_2228 = create_new_share( _vec2231 , ycirc );
                uint32_t _tmp_2232 = 4294967295 ;
                share * s_y__tmp_2232 = ycirc->PutCONSGate( _tmp_2232 ,bitlen);
                share * s_y_tmp_2227 = ycirc->PutXORGate( s_y_tmp_2228 , s_y__tmp_2232 );
                share * s_y_tmp_2222 = ycirc->PutMUXGate( s_y_tmp_2225 , s_y_tmp_2227 , s_y_tmp_2223 );
                uint32_t _tmp_2233 = 0 ;
                share * s_y__tmp_2233 = ycirc->PutCONSGate( _tmp_2233 ,bitlen);
                share * s_y_tmp_2213 = ycirc->PutMUXGate( s_y_tmp_2222 , s_y__tmp_2233 , s_y_tmp_2214 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_2199 , s_y_tmp_2213 , s_y_tmp_2196 );
                uint32_t _tmp_2234 = 1 ;
                share * s_y__tmp_2234 = ycirc->PutCONSGate( _tmp_2234 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_2234 );
            }
            uint32_t _tmp_2236 = 1 ;
            share * s_y__tmp_2236 = ycirc->PutCONSGate( _tmp_2236 ,bitlen);
            share * s_y_tmp_2235 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_2236 );
            vector<uint32_t> _vec2237 = s_y_tmp_2235->get_wires();
            _vec2237.erase( _vec2237.begin(), _vec2237.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec2237 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec2240 = s_y_tmp5->get_wires();
                _vec2240.erase( _vec2240.begin(), _vec2240.begin() + 1 );
                share *s_y_tmp_2239 = create_new_share( _vec2240 , ycirc );
                share * s_y_tmp_2238 = ycirc->PutGTGate( s_y_tmp_2239 , s_y_tmp6 );
                share * s_y_tmp_2241 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec2246 = s_y_tmp5->get_wires();
                _vec2246.erase( _vec2246.begin(), _vec2246.begin() + 1 );
                share *s_y_tmp_2245 = create_new_share( _vec2246 , ycirc );
                share * s_y_tmp_2244 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_2245 );
                uint32_t _tmp_2249 = 1 ;
                share * s_y__tmp_2249 = ycirc->PutCONSGate( _tmp_2249 ,bitlen);
                share * s_y_tmp_2248 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_2249 );
                uint32_t _tmp_2250 = 1 ;
                share * s_y__tmp_2250 = ycirc->PutCONSGate( _tmp_2250 ,bitlen);
                share * s_y_tmp_2247 = ycirc->PutEQGate( s_y_tmp_2248 , s_y__tmp_2250 );
                share * s_y_tmp_2243 = ycirc->PutANDGate( s_y_tmp_2244 , s_y_tmp_2247 );
                uint32_t _tmp_2251 = 0 ;
                share * s_y__tmp_2251 = ycirc->PutCONSGate( _tmp_2251 ,bitlen);
                share * s_y_tmp_2242 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_2251 , s_y_tmp_2243 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_2241 , s_y_tmp_2242 , s_y_tmp_2238 );
                uint32_t _tmp_2252 = 1 ;
                share * s_y__tmp_2252 = ycirc->PutCONSGate( _tmp_2252 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_2252 );
            }
            uint32_t _tmp_2254 = 1 ;
            share * s_y__tmp_2254 = ycirc->PutCONSGate( _tmp_2254 ,bitlen);
            share * s_y_tmp_2253 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_2254 );
            vector<uint32_t> _vec2255 = s_y_tmp_2253->get_wires();
            _vec2255.erase( _vec2255.begin(), _vec2255.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec2255 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_2257 = 2147483648 ;
        share * s_y__tmp_2257 = ycirc->PutCONSGate( _tmp_2257 ,bitlen);
        share * s_y_tmp_2256 = ycirc->PutGTGate( s_y__tmp_2257 , s_y_BB[8][i5][i6] );
        vector<uint32_t> _vec2259 = s_y_BB[8][i5][i6]->get_wires();
        _vec2259.erase( _vec2259.begin(), _vec2259.begin() + 4 );
        share *s_y_tmp_2258 = create_new_share( _vec2259 , ycirc );
        uint32_t _tmp_2263 = 4294967295 ;
        share * s_y__tmp_2263 = ycirc->PutCONSGate( _tmp_2263 ,bitlen);
        share * s_y_tmp_2262 = ycirc->PutXORGate( s_y_BB[8][i5][i6] , s_y__tmp_2263 );
        vector<uint32_t> _vec2264 = s_y_tmp_2262->get_wires();
        _vec2264.erase( _vec2264.begin(), _vec2264.begin() + 4 );
        share *s_y_tmp_2261 = create_new_share( _vec2264 , ycirc );
        uint32_t _tmp_2265 = 4294967295 ;
        share * s_y__tmp_2265 = ycirc->PutCONSGate( _tmp_2265 ,bitlen);
        share * s_y_tmp_2260 = ycirc->PutXORGate( s_y_tmp_2261 , s_y__tmp_2265 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_2258 , s_y_tmp_2260 , s_y_tmp_2256 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_2266 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_2267 = 1 ;
share * s_a__tmp_2267 = acirc->PutCONSGate( _tmp_2267 ,bitlen);
share *s_a_tmp_2266 = acirc->PutY2AGate( s_y_tmp_2266 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_2266 , s_a__tmp_2267 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_2269 = 2147483648 ;
        share * s_y__tmp_2269 = ycirc->PutCONSGate( _tmp_2269 ,bitlen);
        share * s_y_tmp_2268 = ycirc->PutGTGate( s_y__tmp_2269 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec2271 = s_y_tmp11[i9][i10]->get_wires();
        _vec2271.erase( _vec2271.begin(), _vec2271.begin() + 15 );
        share *s_y_tmp_2270 = create_new_share( _vec2271 , ycirc );
        uint32_t _tmp_2275 = 4294967295 ;
        share * s_y__tmp_2275 = ycirc->PutCONSGate( _tmp_2275 ,bitlen);
        share * s_y_tmp_2274 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_2275 );
        vector<uint32_t> _vec2276 = s_y_tmp_2274->get_wires();
        _vec2276.erase( _vec2276.begin(), _vec2276.begin() + 15 );
        share *s_y_tmp_2273 = create_new_share( _vec2276 , ycirc );
        uint32_t _tmp_2277 = 4294967295 ;
        share * s_y__tmp_2277 = ycirc->PutCONSGate( _tmp_2277 ,bitlen);
        share * s_y_tmp_2272 = ycirc->PutXORGate( s_y_tmp_2273 , s_y__tmp_2277 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_2270 , s_y_tmp_2272 , s_y_tmp_2268 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_2279 = 2147483648 ;
        share * s_y__tmp_2279 = ycirc->PutCONSGate( _tmp_2279 ,bitlen);
        share * s_y_tmp_2278 = ycirc->PutGTGate( s_y__tmp_2279 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec2281 = s_y_tmp7[i10][i11]->get_wires();
        _vec2281.erase( _vec2281.begin(), _vec2281.begin() + 15 );
        share *s_y_tmp_2280 = create_new_share( _vec2281 , ycirc );
        uint32_t _tmp_2285 = 4294967295 ;
        share * s_y__tmp_2285 = ycirc->PutCONSGate( _tmp_2285 ,bitlen);
        share * s_y_tmp_2284 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_2285 );
        vector<uint32_t> _vec2286 = s_y_tmp_2284->get_wires();
        _vec2286.erase( _vec2286.begin(), _vec2286.begin() + 15 );
        share *s_y_tmp_2283 = create_new_share( _vec2286 , ycirc );
        uint32_t _tmp_2287 = 4294967295 ;
        share * s_y__tmp_2287 = ycirc->PutCONSGate( _tmp_2287 ,bitlen);
        share * s_y_tmp_2282 = ycirc->PutXORGate( s_y_tmp_2283 , s_y__tmp_2287 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_2280 , s_y_tmp_2282 , s_y_tmp_2278 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec2290 = s_y_tmp16->get_wires();
                _vec2290.erase( _vec2290.begin(), _vec2290.begin() + 1 );
                share *s_y_tmp_2289 = create_new_share( _vec2290 , ycirc );
                share * s_y_tmp_2288 = ycirc->PutGTGate( s_y_tmp_2289 , s_y_tmp17 );
                share * s_y_tmp_2293 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_2294 = 2147483648 ;
                share * s_y__tmp_2294 = ycirc->PutCONSGate( _tmp_2294 ,bitlen);
                share * s_y_tmp_2292 = ycirc->PutGTGate( s_y__tmp_2294 , s_y_tmp_2293 );
                share * s_y_tmp_2296 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec2297 = s_y_tmp_2296->get_wires();
                _vec2297.erase( _vec2297.begin(), _vec2297.begin() + 1 );
                share *s_y_tmp_2295 = create_new_share( _vec2297 , ycirc );
                share * s_y_tmp_2301 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_2302 = 4294967295 ;
                share * s_y__tmp_2302 = ycirc->PutCONSGate( _tmp_2302 ,bitlen);
                share * s_y_tmp_2300 = ycirc->PutXORGate( s_y_tmp_2301 , s_y__tmp_2302 );
                vector<uint32_t> _vec2303 = s_y_tmp_2300->get_wires();
                _vec2303.erase( _vec2303.begin(), _vec2303.begin() + 1 );
                share *s_y_tmp_2299 = create_new_share( _vec2303 , ycirc );
                uint32_t _tmp_2304 = 4294967295 ;
                share * s_y__tmp_2304 = ycirc->PutCONSGate( _tmp_2304 ,bitlen);
                share * s_y_tmp_2298 = ycirc->PutXORGate( s_y_tmp_2299 , s_y__tmp_2304 );
                share * s_y_tmp_2291 = ycirc->PutMUXGate( s_y_tmp_2295 , s_y_tmp_2298 , s_y_tmp_2292 );
                vector<uint32_t> _vec2309 = s_y_tmp16->get_wires();
                _vec2309.erase( _vec2309.begin(), _vec2309.begin() + 1 );
                share *s_y_tmp_2308 = create_new_share( _vec2309 , ycirc );
                share * s_y_tmp_2307 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_2308 );
                uint32_t _tmp_2312 = 1 ;
                share * s_y__tmp_2312 = ycirc->PutCONSGate( _tmp_2312 ,bitlen);
                share * s_y_tmp_2311 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_2312 );
                uint32_t _tmp_2313 = 1 ;
                share * s_y__tmp_2313 = ycirc->PutCONSGate( _tmp_2313 ,bitlen);
                share * s_y_tmp_2310 = ycirc->PutEQGate( s_y_tmp_2311 , s_y__tmp_2313 );
                share * s_y_tmp_2306 = ycirc->PutANDGate( s_y_tmp_2307 , s_y_tmp_2310 );
                uint32_t _tmp_2316 = 2147483648 ;
                share * s_y__tmp_2316 = ycirc->PutCONSGate( _tmp_2316 ,bitlen);
                share * s_y_tmp_2315 = ycirc->PutGTGate( s_y__tmp_2316 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec2318 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec2318.erase( _vec2318.begin(), _vec2318.begin() + 1 );
                share *s_y_tmp_2317 = create_new_share( _vec2318 , ycirc );
                uint32_t _tmp_2322 = 4294967295 ;
                share * s_y__tmp_2322 = ycirc->PutCONSGate( _tmp_2322 ,bitlen);
                share * s_y_tmp_2321 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_2322 );
                vector<uint32_t> _vec2323 = s_y_tmp_2321->get_wires();
                _vec2323.erase( _vec2323.begin(), _vec2323.begin() + 1 );
                share *s_y_tmp_2320 = create_new_share( _vec2323 , ycirc );
                uint32_t _tmp_2324 = 4294967295 ;
                share * s_y__tmp_2324 = ycirc->PutCONSGate( _tmp_2324 ,bitlen);
                share * s_y_tmp_2319 = ycirc->PutXORGate( s_y_tmp_2320 , s_y__tmp_2324 );
                share * s_y_tmp_2314 = ycirc->PutMUXGate( s_y_tmp_2317 , s_y_tmp_2319 , s_y_tmp_2315 );
                uint32_t _tmp_2325 = 0 ;
                share * s_y__tmp_2325 = ycirc->PutCONSGate( _tmp_2325 ,bitlen);
                share * s_y_tmp_2305 = ycirc->PutMUXGate( s_y_tmp_2314 , s_y__tmp_2325 , s_y_tmp_2306 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_2291 , s_y_tmp_2305 , s_y_tmp_2288 );
                uint32_t _tmp_2326 = 1 ;
                share * s_y__tmp_2326 = ycirc->PutCONSGate( _tmp_2326 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_2326 );
            }
            uint32_t _tmp_2328 = 1 ;
            share * s_y__tmp_2328 = ycirc->PutCONSGate( _tmp_2328 ,bitlen);
            share * s_y_tmp_2327 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_2328 );
            vector<uint32_t> _vec2329 = s_y_tmp_2327->get_wires();
            _vec2329.erase( _vec2329.begin(), _vec2329.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec2329 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec2332 = s_y_tmp16->get_wires();
                _vec2332.erase( _vec2332.begin(), _vec2332.begin() + 1 );
                share *s_y_tmp_2331 = create_new_share( _vec2332 , ycirc );
                share * s_y_tmp_2330 = ycirc->PutGTGate( s_y_tmp_2331 , s_y_tmp17 );
                share * s_y_tmp_2333 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec2338 = s_y_tmp16->get_wires();
                _vec2338.erase( _vec2338.begin(), _vec2338.begin() + 1 );
                share *s_y_tmp_2337 = create_new_share( _vec2338 , ycirc );
                share * s_y_tmp_2336 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_2337 );
                uint32_t _tmp_2341 = 1 ;
                share * s_y__tmp_2341 = ycirc->PutCONSGate( _tmp_2341 ,bitlen);
                share * s_y_tmp_2340 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_2341 );
                uint32_t _tmp_2342 = 1 ;
                share * s_y__tmp_2342 = ycirc->PutCONSGate( _tmp_2342 ,bitlen);
                share * s_y_tmp_2339 = ycirc->PutEQGate( s_y_tmp_2340 , s_y__tmp_2342 );
                share * s_y_tmp_2335 = ycirc->PutANDGate( s_y_tmp_2336 , s_y_tmp_2339 );
                uint32_t _tmp_2343 = 0 ;
                share * s_y__tmp_2343 = ycirc->PutCONSGate( _tmp_2343 ,bitlen);
                share * s_y_tmp_2334 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_2343 , s_y_tmp_2335 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_2333 , s_y_tmp_2334 , s_y_tmp_2330 );
                uint32_t _tmp_2344 = 1 ;
                share * s_y__tmp_2344 = ycirc->PutCONSGate( _tmp_2344 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_2344 );
            }
            uint32_t _tmp_2346 = 1 ;
            share * s_y__tmp_2346 = ycirc->PutCONSGate( _tmp_2346 ,bitlen);
            share * s_y_tmp_2345 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_2346 );
            vector<uint32_t> _vec2347 = s_y_tmp_2345->get_wires();
            _vec2347.erase( _vec2347.begin(), _vec2347.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec2347 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_2349 = 2147483648 ;
share * s_y__tmp_2349 = ycirc->PutCONSGate( _tmp_2349 ,bitlen);
share * s_y_tmp_2348 = ycirc->PutGTGate( s_y__tmp_2349 , s_y_tmp10 );
vector<uint32_t> _vec2351 = s_y_tmp10->get_wires();
_vec2351.erase( _vec2351.begin(), _vec2351.begin() + 15 );
share *s_y_tmp_2350 = create_new_share( _vec2351 , ycirc );
uint32_t _tmp_2355 = 4294967295 ;
share * s_y__tmp_2355 = ycirc->PutCONSGate( _tmp_2355 ,bitlen);
share * s_y_tmp_2354 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_2355 );
vector<uint32_t> _vec2356 = s_y_tmp_2354->get_wires();
_vec2356.erase( _vec2356.begin(), _vec2356.begin() + 15 );
share *s_y_tmp_2353 = create_new_share( _vec2356 , ycirc );
uint32_t _tmp_2357 = 4294967295 ;
share * s_y__tmp_2357 = ycirc->PutCONSGate( _tmp_2357 ,bitlen);
share * s_y_tmp_2352 = ycirc->PutXORGate( s_y_tmp_2353 , s_y__tmp_2357 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_2350 , s_y_tmp_2352 , s_y_tmp_2348 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_2359 = 2147483648 ;
        share * s_y__tmp_2359 = ycirc->PutCONSGate( _tmp_2359 ,bitlen);
        share * s_y_tmp_2358 = ycirc->PutGTGate( s_y__tmp_2359 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec2361 = s_y_tmp12[i14][i15]->get_wires();
        _vec2361.erase( _vec2361.begin(), _vec2361.begin() + 15 );
        share *s_y_tmp_2360 = create_new_share( _vec2361 , ycirc );
        uint32_t _tmp_2365 = 4294967295 ;
        share * s_y__tmp_2365 = ycirc->PutCONSGate( _tmp_2365 ,bitlen);
        share * s_y_tmp_2364 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_2365 );
        vector<uint32_t> _vec2366 = s_y_tmp_2364->get_wires();
        _vec2366.erase( _vec2366.begin(), _vec2366.begin() + 15 );
        share *s_y_tmp_2363 = create_new_share( _vec2366 , ycirc );
        uint32_t _tmp_2367 = 4294967295 ;
        share * s_y__tmp_2367 = ycirc->PutCONSGate( _tmp_2367 ,bitlen);
        share * s_y_tmp_2362 = ycirc->PutXORGate( s_y_tmp_2363 , s_y__tmp_2367 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_2360 , s_y_tmp_2362 , s_y_tmp_2358 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_2369 = 2147483648 ;
        share * s_y__tmp_2369 = ycirc->PutCONSGate( _tmp_2369 ,bitlen);
        share * s_y_tmp_2368 = ycirc->PutGTGate( s_y__tmp_2369 , s_y_ZZ[8][i16][i17] );
        vector<uint32_t> _vec2371 = s_y_ZZ[8][i16][i17]->get_wires();
        _vec2371.erase( _vec2371.begin(), _vec2371.begin() + 15 );
        share *s_y_tmp_2370 = create_new_share( _vec2371 , ycirc );
        uint32_t _tmp_2375 = 4294967295 ;
        share * s_y__tmp_2375 = ycirc->PutCONSGate( _tmp_2375 ,bitlen);
        share * s_y_tmp_2374 = ycirc->PutXORGate( s_y_ZZ[8][i16][i17] , s_y__tmp_2375 );
        vector<uint32_t> _vec2376 = s_y_tmp_2374->get_wires();
        _vec2376.erase( _vec2376.begin(), _vec2376.begin() + 15 );
        share *s_y_tmp_2373 = create_new_share( _vec2376 , ycirc );
        uint32_t _tmp_2377 = 4294967295 ;
        share * s_y__tmp_2377 = ycirc->PutCONSGate( _tmp_2377 ,bitlen);
        share * s_y_tmp_2372 = ycirc->PutXORGate( s_y_tmp_2373 , s_y__tmp_2377 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_2370 , s_y_tmp_2372 , s_y_tmp_2368 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_2379 = 2147483648 ;
        share * s_y__tmp_2379 = ycirc->PutCONSGate( _tmp_2379 ,bitlen);
        share * s_y_tmp_2378 = ycirc->PutGTGate( s_y__tmp_2379 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec2381 = s_y_tmp21[i17][i18]->get_wires();
        _vec2381.erase( _vec2381.begin(), _vec2381.begin() + 15 );
        share *s_y_tmp_2380 = create_new_share( _vec2381 , ycirc );
        uint32_t _tmp_2385 = 4294967295 ;
        share * s_y__tmp_2385 = ycirc->PutCONSGate( _tmp_2385 ,bitlen);
        share * s_y_tmp_2384 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_2385 );
        vector<uint32_t> _vec2386 = s_y_tmp_2384->get_wires();
        _vec2386.erase( _vec2386.begin(), _vec2386.begin() + 15 );
        share *s_y_tmp_2383 = create_new_share( _vec2386 , ycirc );
        uint32_t _tmp_2387 = 4294967295 ;
        share * s_y__tmp_2387 = ycirc->PutCONSGate( _tmp_2387 ,bitlen);
        share * s_y_tmp_2382 = ycirc->PutXORGate( s_y_tmp_2383 , s_y__tmp_2387 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_2380 , s_y_tmp_2382 , s_y_tmp_2378 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec2390 = s_y_tmp28->get_wires();
                _vec2390.erase( _vec2390.begin(), _vec2390.begin() + 1 );
                share *s_y_tmp_2389 = create_new_share( _vec2390 , ycirc );
                share * s_y_tmp_2388 = ycirc->PutGTGate( s_y_tmp_2389 , s_y_tmp29 );
                share * s_y_tmp_2393 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_2394 = 2147483648 ;
                share * s_y__tmp_2394 = ycirc->PutCONSGate( _tmp_2394 ,bitlen);
                share * s_y_tmp_2392 = ycirc->PutGTGate( s_y__tmp_2394 , s_y_tmp_2393 );
                share * s_y_tmp_2396 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec2397 = s_y_tmp_2396->get_wires();
                _vec2397.erase( _vec2397.begin(), _vec2397.begin() + 1 );
                share *s_y_tmp_2395 = create_new_share( _vec2397 , ycirc );
                share * s_y_tmp_2401 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_2402 = 4294967295 ;
                share * s_y__tmp_2402 = ycirc->PutCONSGate( _tmp_2402 ,bitlen);
                share * s_y_tmp_2400 = ycirc->PutXORGate( s_y_tmp_2401 , s_y__tmp_2402 );
                vector<uint32_t> _vec2403 = s_y_tmp_2400->get_wires();
                _vec2403.erase( _vec2403.begin(), _vec2403.begin() + 1 );
                share *s_y_tmp_2399 = create_new_share( _vec2403 , ycirc );
                uint32_t _tmp_2404 = 4294967295 ;
                share * s_y__tmp_2404 = ycirc->PutCONSGate( _tmp_2404 ,bitlen);
                share * s_y_tmp_2398 = ycirc->PutXORGate( s_y_tmp_2399 , s_y__tmp_2404 );
                share * s_y_tmp_2391 = ycirc->PutMUXGate( s_y_tmp_2395 , s_y_tmp_2398 , s_y_tmp_2392 );
                vector<uint32_t> _vec2409 = s_y_tmp28->get_wires();
                _vec2409.erase( _vec2409.begin(), _vec2409.begin() + 1 );
                share *s_y_tmp_2408 = create_new_share( _vec2409 , ycirc );
                share * s_y_tmp_2407 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_2408 );
                uint32_t _tmp_2412 = 1 ;
                share * s_y__tmp_2412 = ycirc->PutCONSGate( _tmp_2412 ,bitlen);
                share * s_y_tmp_2411 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_2412 );
                uint32_t _tmp_2413 = 1 ;
                share * s_y__tmp_2413 = ycirc->PutCONSGate( _tmp_2413 ,bitlen);
                share * s_y_tmp_2410 = ycirc->PutEQGate( s_y_tmp_2411 , s_y__tmp_2413 );
                share * s_y_tmp_2406 = ycirc->PutANDGate( s_y_tmp_2407 , s_y_tmp_2410 );
                uint32_t _tmp_2416 = 2147483648 ;
                share * s_y__tmp_2416 = ycirc->PutCONSGate( _tmp_2416 ,bitlen);
                share * s_y_tmp_2415 = ycirc->PutGTGate( s_y__tmp_2416 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec2418 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec2418.erase( _vec2418.begin(), _vec2418.begin() + 1 );
                share *s_y_tmp_2417 = create_new_share( _vec2418 , ycirc );
                uint32_t _tmp_2422 = 4294967295 ;
                share * s_y__tmp_2422 = ycirc->PutCONSGate( _tmp_2422 ,bitlen);
                share * s_y_tmp_2421 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_2422 );
                vector<uint32_t> _vec2423 = s_y_tmp_2421->get_wires();
                _vec2423.erase( _vec2423.begin(), _vec2423.begin() + 1 );
                share *s_y_tmp_2420 = create_new_share( _vec2423 , ycirc );
                uint32_t _tmp_2424 = 4294967295 ;
                share * s_y__tmp_2424 = ycirc->PutCONSGate( _tmp_2424 ,bitlen);
                share * s_y_tmp_2419 = ycirc->PutXORGate( s_y_tmp_2420 , s_y__tmp_2424 );
                share * s_y_tmp_2414 = ycirc->PutMUXGate( s_y_tmp_2417 , s_y_tmp_2419 , s_y_tmp_2415 );
                uint32_t _tmp_2425 = 0 ;
                share * s_y__tmp_2425 = ycirc->PutCONSGate( _tmp_2425 ,bitlen);
                share * s_y_tmp_2405 = ycirc->PutMUXGate( s_y_tmp_2414 , s_y__tmp_2425 , s_y_tmp_2406 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_2391 , s_y_tmp_2405 , s_y_tmp_2388 );
                uint32_t _tmp_2426 = 1 ;
                share * s_y__tmp_2426 = ycirc->PutCONSGate( _tmp_2426 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_2426 );
            }
            uint32_t _tmp_2428 = 1 ;
            share * s_y__tmp_2428 = ycirc->PutCONSGate( _tmp_2428 ,bitlen);
            share * s_y_tmp_2427 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_2428 );
            vector<uint32_t> _vec2429 = s_y_tmp_2427->get_wires();
            _vec2429.erase( _vec2429.begin(), _vec2429.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec2429 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec2432 = s_y_tmp28->get_wires();
                _vec2432.erase( _vec2432.begin(), _vec2432.begin() + 1 );
                share *s_y_tmp_2431 = create_new_share( _vec2432 , ycirc );
                share * s_y_tmp_2430 = ycirc->PutGTGate( s_y_tmp_2431 , s_y_tmp29 );
                share * s_y_tmp_2433 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec2438 = s_y_tmp28->get_wires();
                _vec2438.erase( _vec2438.begin(), _vec2438.begin() + 1 );
                share *s_y_tmp_2437 = create_new_share( _vec2438 , ycirc );
                share * s_y_tmp_2436 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_2437 );
                uint32_t _tmp_2441 = 1 ;
                share * s_y__tmp_2441 = ycirc->PutCONSGate( _tmp_2441 ,bitlen);
                share * s_y_tmp_2440 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_2441 );
                uint32_t _tmp_2442 = 1 ;
                share * s_y__tmp_2442 = ycirc->PutCONSGate( _tmp_2442 ,bitlen);
                share * s_y_tmp_2439 = ycirc->PutEQGate( s_y_tmp_2440 , s_y__tmp_2442 );
                share * s_y_tmp_2435 = ycirc->PutANDGate( s_y_tmp_2436 , s_y_tmp_2439 );
                uint32_t _tmp_2443 = 0 ;
                share * s_y__tmp_2443 = ycirc->PutCONSGate( _tmp_2443 ,bitlen);
                share * s_y_tmp_2434 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_2443 , s_y_tmp_2435 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_2433 , s_y_tmp_2434 , s_y_tmp_2430 );
                uint32_t _tmp_2444 = 1 ;
                share * s_y__tmp_2444 = ycirc->PutCONSGate( _tmp_2444 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_2444 );
            }
            uint32_t _tmp_2446 = 1 ;
            share * s_y__tmp_2446 = ycirc->PutCONSGate( _tmp_2446 ,bitlen);
            share * s_y_tmp_2445 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_2446 );
            vector<uint32_t> _vec2447 = s_y_tmp_2445->get_wires();
            _vec2447.erase( _vec2447.begin(), _vec2447.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec2447 , ycirc );
        }
        s_y_tmp31[8][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i1 = 0; i1 < 400; i1++)
    {
        uint32_t _tmp_2449 = 2147483648 ;
        share * s_y__tmp_2449 = ycirc->PutCONSGate( _tmp_2449 ,bitlen);
        share * s_y_tmp_2448 = ycirc->PutGTGate( s_y__tmp_2449 , s_y_WW[i0][i1] );
        vector<uint32_t> _vec2451 = s_y_WW[i0][i1]->get_wires();
        _vec2451.erase( _vec2451.begin(), _vec2451.begin() + 15 );
        share *s_y_tmp_2450 = create_new_share( _vec2451 , ycirc );
        uint32_t _tmp_2455 = 4294967295 ;
        share * s_y__tmp_2455 = ycirc->PutCONSGate( _tmp_2455 ,bitlen);
        share * s_y_tmp_2454 = ycirc->PutXORGate( s_y_WW[i0][i1] , s_y__tmp_2455 );
        vector<uint32_t> _vec2456 = s_y_tmp_2454->get_wires();
        _vec2456.erase( _vec2456.begin(), _vec2456.begin() + 15 );
        share *s_y_tmp_2453 = create_new_share( _vec2456 , ycirc );
        uint32_t _tmp_2457 = 4294967295 ;
        share * s_y__tmp_2457 = ycirc->PutCONSGate( _tmp_2457 ,bitlen);
        share * s_y_tmp_2452 = ycirc->PutXORGate( s_y_tmp_2453 , s_y__tmp_2457 );
        s_y_tmp2[i0][i1] = ycirc->PutMUXGate( s_y_tmp_2450 , s_y_tmp_2452 , s_y_tmp_2448 );
    }
}
for (uint32_t i1 = 0; i1 < 400; i1++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        uint32_t _tmp_2459 = 2147483648 ;
        share * s_y__tmp_2459 = ycirc->PutCONSGate( _tmp_2459 ,bitlen);
        share * s_y_tmp_2458 = ycirc->PutGTGate( s_y__tmp_2459 , s_y_xx[i1][i2] );
        vector<uint32_t> _vec2461 = s_y_xx[i1][i2]->get_wires();
        _vec2461.erase( _vec2461.begin(), _vec2461.begin() + 15 );
        share *s_y_tmp_2460 = create_new_share( _vec2461 , ycirc );
        uint32_t _tmp_2465 = 4294967295 ;
        share * s_y__tmp_2465 = ycirc->PutCONSGate( _tmp_2465 ,bitlen);
        share * s_y_tmp_2464 = ycirc->PutXORGate( s_y_xx[i1][i2] , s_y__tmp_2465 );
        vector<uint32_t> _vec2466 = s_y_tmp_2464->get_wires();
        _vec2466.erase( _vec2466.begin(), _vec2466.begin() + 15 );
        share *s_y_tmp_2463 = create_new_share( _vec2466 , ycirc );
        uint32_t _tmp_2467 = 4294967295 ;
        share * s_y__tmp_2467 = ycirc->PutCONSGate( _tmp_2467 ,bitlen);
        share * s_y_tmp_2462 = ycirc->PutXORGate( s_y_tmp_2463 , s_y__tmp_2467 );
        s_y_tmp3[i1][i2] = ycirc->PutMUXGate( s_y_tmp_2460 , s_y_tmp_2462 , s_y_tmp_2458 );
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 400 ; _i4++) {
s_a_tmp2[_i1][_i4] = acirc->PutY2AGate( s_y_tmp2[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 400 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp3[_i1][_i4] = acirc->PutY2AGate( s_y_tmp3[_i1][_i4] ,bcirc);
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        for (uint32_t i1 = 0; i1 < 400; i1++)
        {
            s_a_tmp4[i0][i2][i1] = acirc->PutMULGate( s_a_tmp2[i0][i1] , s_a_tmp3[i1][i2] );
        }
    }
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 400 ; _i7++) {
s_y_tmp4[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp4[_i1][_i4][_i7] );
}
}
}
for (uint32_t i0 = 0; i0 < 5; i0++)
{
    for (uint32_t i2 = 0; i2 < 1; i2++)
    {
        tmp5 = 400 ;
        s_y_tmp5 = ycirc->PutCONSGate( tmp5 ,bitlen);
        for (uint32_t i3 = 0; i3 < 3; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec2470 = s_y_tmp5->get_wires();
                _vec2470.erase( _vec2470.begin(), _vec2470.begin() + 1 );
                share *s_y_tmp_2469 = create_new_share( _vec2470 , ycirc );
                share * s_y_tmp_2468 = ycirc->PutGTGate( s_y_tmp_2469 , s_y_tmp6 );
                share * s_y_tmp_2473 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_2474 = 2147483648 ;
                share * s_y__tmp_2474 = ycirc->PutCONSGate( _tmp_2474 ,bitlen);
                share * s_y_tmp_2472 = ycirc->PutGTGate( s_y__tmp_2474 , s_y_tmp_2473 );
                share * s_y_tmp_2476 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec2477 = s_y_tmp_2476->get_wires();
                _vec2477.erase( _vec2477.begin(), _vec2477.begin() + 1 );
                share *s_y_tmp_2475 = create_new_share( _vec2477 , ycirc );
                share * s_y_tmp_2481 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                uint32_t _tmp_2482 = 4294967295 ;
                share * s_y__tmp_2482 = ycirc->PutCONSGate( _tmp_2482 ,bitlen);
                share * s_y_tmp_2480 = ycirc->PutXORGate( s_y_tmp_2481 , s_y__tmp_2482 );
                vector<uint32_t> _vec2483 = s_y_tmp_2480->get_wires();
                _vec2483.erase( _vec2483.begin(), _vec2483.begin() + 1 );
                share *s_y_tmp_2479 = create_new_share( _vec2483 , ycirc );
                uint32_t _tmp_2484 = 4294967295 ;
                share * s_y__tmp_2484 = ycirc->PutCONSGate( _tmp_2484 ,bitlen);
                share * s_y_tmp_2478 = ycirc->PutXORGate( s_y_tmp_2479 , s_y__tmp_2484 );
                share * s_y_tmp_2471 = ycirc->PutMUXGate( s_y_tmp_2475 , s_y_tmp_2478 , s_y_tmp_2472 );
                vector<uint32_t> _vec2489 = s_y_tmp5->get_wires();
                _vec2489.erase( _vec2489.begin(), _vec2489.begin() + 1 );
                share *s_y_tmp_2488 = create_new_share( _vec2489 , ycirc );
                share * s_y_tmp_2487 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_2488 );
                uint32_t _tmp_2492 = 1 ;
                share * s_y__tmp_2492 = ycirc->PutCONSGate( _tmp_2492 ,bitlen);
                share * s_y_tmp_2491 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_2492 );
                uint32_t _tmp_2493 = 1 ;
                share * s_y__tmp_2493 = ycirc->PutCONSGate( _tmp_2493 ,bitlen);
                share * s_y_tmp_2490 = ycirc->PutEQGate( s_y_tmp_2491 , s_y__tmp_2493 );
                share * s_y_tmp_2486 = ycirc->PutANDGate( s_y_tmp_2487 , s_y_tmp_2490 );
                uint32_t _tmp_2496 = 2147483648 ;
                share * s_y__tmp_2496 = ycirc->PutCONSGate( _tmp_2496 ,bitlen);
                share * s_y_tmp_2495 = ycirc->PutGTGate( s_y__tmp_2496 , s_y_tmp4[i0][i2][(2*i4)] );
                vector<uint32_t> _vec2498 = s_y_tmp4[i0][i2][(2*i4)]->get_wires();
                _vec2498.erase( _vec2498.begin(), _vec2498.begin() + 1 );
                share *s_y_tmp_2497 = create_new_share( _vec2498 , ycirc );
                uint32_t _tmp_2502 = 4294967295 ;
                share * s_y__tmp_2502 = ycirc->PutCONSGate( _tmp_2502 ,bitlen);
                share * s_y_tmp_2501 = ycirc->PutXORGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_2502 );
                vector<uint32_t> _vec2503 = s_y_tmp_2501->get_wires();
                _vec2503.erase( _vec2503.begin(), _vec2503.begin() + 1 );
                share *s_y_tmp_2500 = create_new_share( _vec2503 , ycirc );
                uint32_t _tmp_2504 = 4294967295 ;
                share * s_y__tmp_2504 = ycirc->PutCONSGate( _tmp_2504 ,bitlen);
                share * s_y_tmp_2499 = ycirc->PutXORGate( s_y_tmp_2500 , s_y__tmp_2504 );
                share * s_y_tmp_2494 = ycirc->PutMUXGate( s_y_tmp_2497 , s_y_tmp_2499 , s_y_tmp_2495 );
                uint32_t _tmp_2505 = 0 ;
                share * s_y__tmp_2505 = ycirc->PutCONSGate( _tmp_2505 ,bitlen);
                share * s_y_tmp_2485 = ycirc->PutMUXGate( s_y_tmp_2494 , s_y__tmp_2505 , s_y_tmp_2486 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_2471 , s_y_tmp_2485 , s_y_tmp_2468 );
                uint32_t _tmp_2506 = 1 ;
                share * s_y__tmp_2506 = ycirc->PutCONSGate( _tmp_2506 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_2506 );
            }
            uint32_t _tmp_2508 = 1 ;
            share * s_y__tmp_2508 = ycirc->PutCONSGate( _tmp_2508 ,bitlen);
            share * s_y_tmp_2507 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_2508 );
            vector<uint32_t> _vec2509 = s_y_tmp_2507->get_wires();
            _vec2509.erase( _vec2509.begin(), _vec2509.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec2509 , ycirc );
        }
        for (uint32_t i3 = 0; i3 < 6; i3++)
        {
            tmp6 = 0 ;
            s_y_tmp6 = ycirc->PutCONSGate( tmp6 ,bitlen);
            for (uint32_t i4 = 0; i4 < 201; i4++)
            {
                vector<uint32_t> _vec2512 = s_y_tmp5->get_wires();
                _vec2512.erase( _vec2512.begin(), _vec2512.begin() + 1 );
                share *s_y_tmp_2511 = create_new_share( _vec2512 , ycirc );
                share * s_y_tmp_2510 = ycirc->PutGTGate( s_y_tmp_2511 , s_y_tmp6 );
                share * s_y_tmp_2513 = ycirc->PutADDGate( s_y_tmp4[i0][i2][(2*i4)] , s_y_tmp4[i0][i2][((2*i4)+1)] );
                vector<uint32_t> _vec2518 = s_y_tmp5->get_wires();
                _vec2518.erase( _vec2518.begin(), _vec2518.begin() + 1 );
                share *s_y_tmp_2517 = create_new_share( _vec2518 , ycirc );
                share * s_y_tmp_2516 = ycirc->PutEQGate( s_y_tmp6 , s_y_tmp_2517 );
                uint32_t _tmp_2521 = 1 ;
                share * s_y__tmp_2521 = ycirc->PutCONSGate( _tmp_2521 ,bitlen);
                share * s_y_tmp_2520 = ycirc->PutANDGate( s_y_tmp5 , s_y__tmp_2521 );
                uint32_t _tmp_2522 = 1 ;
                share * s_y__tmp_2522 = ycirc->PutCONSGate( _tmp_2522 ,bitlen);
                share * s_y_tmp_2519 = ycirc->PutEQGate( s_y_tmp_2520 , s_y__tmp_2522 );
                share * s_y_tmp_2515 = ycirc->PutANDGate( s_y_tmp_2516 , s_y_tmp_2519 );
                uint32_t _tmp_2523 = 0 ;
                share * s_y__tmp_2523 = ycirc->PutCONSGate( _tmp_2523 ,bitlen);
                share * s_y_tmp_2514 = ycirc->PutMUXGate( s_y_tmp4[i0][i2][(2*i4)] , s_y__tmp_2523 , s_y_tmp_2515 );
                s_y_tmp4[i0][i2][i4] = ycirc->PutMUXGate( s_y_tmp_2513 , s_y_tmp_2514 , s_y_tmp_2510 );
                uint32_t _tmp_2524 = 1 ;
                share * s_y__tmp_2524 = ycirc->PutCONSGate( _tmp_2524 ,bitlen);
                s_y_tmp6 = ycirc->PutADDGate( s_y_tmp6 , s_y__tmp_2524 );
            }
            uint32_t _tmp_2526 = 1 ;
            share * s_y__tmp_2526 = ycirc->PutCONSGate( _tmp_2526 ,bitlen);
            share * s_y_tmp_2525 = ycirc->PutADDGate( s_y_tmp5 , s_y__tmp_2526 );
            vector<uint32_t> _vec2527 = s_y_tmp_2525->get_wires();
            _vec2527.erase( _vec2527.begin(), _vec2527.begin() + 1 );
            s_y_tmp5 = create_new_share( _vec2527 , ycirc );
        }
        s_y_tmp1[i0][i2] = create_new_share(s_y_tmp4[i0][i2][0]->get_wires(), ycirc );
    }
}
for (uint32_t i5 = 0; i5 < 5; i5++)
{
    for (uint32_t i6 = 0; i6 < 1; i6++)
    {
        s_y_tmp8 = create_new_share(s_y_tmp1[i5][i6]->get_wires(), ycirc );
        uint32_t _tmp_2529 = 2147483648 ;
        share * s_y__tmp_2529 = ycirc->PutCONSGate( _tmp_2529 ,bitlen);
        share * s_y_tmp_2528 = ycirc->PutGTGate( s_y__tmp_2529 , s_y_BB[9][i5][i6] );
        vector<uint32_t> _vec2531 = s_y_BB[9][i5][i6]->get_wires();
        _vec2531.erase( _vec2531.begin(), _vec2531.begin() + 4 );
        share *s_y_tmp_2530 = create_new_share( _vec2531 , ycirc );
        uint32_t _tmp_2535 = 4294967295 ;
        share * s_y__tmp_2535 = ycirc->PutCONSGate( _tmp_2535 ,bitlen);
        share * s_y_tmp_2534 = ycirc->PutXORGate( s_y_BB[9][i5][i6] , s_y__tmp_2535 );
        vector<uint32_t> _vec2536 = s_y_tmp_2534->get_wires();
        _vec2536.erase( _vec2536.begin(), _vec2536.begin() + 4 );
        share *s_y_tmp_2533 = create_new_share( _vec2536 , ycirc );
        uint32_t _tmp_2537 = 4294967295 ;
        share * s_y__tmp_2537 = ycirc->PutCONSGate( _tmp_2537 ,bitlen);
        share * s_y_tmp_2532 = ycirc->PutXORGate( s_y_tmp_2533 , s_y__tmp_2537 );
        s_y_tmp9 = ycirc->PutMUXGate( s_y_tmp_2530 , s_y_tmp_2532 , s_y_tmp_2528 );
        s_y_tmp7[i5][i6] = ycirc->PutSUBGate( s_y_tmp8 , s_y_tmp9 );
        s_y_tmp7[i5][i6] = create_new_share(s_y_tmp7[i5][i6]->get_wires(), ycirc );
    }
}
share * s_y_tmp_2538 = ycirc->PutINVGate( s_y_tmp0 );
uint32_t _tmp_2539 = 1 ;
share * s_a__tmp_2539 = acirc->PutCONSGate( _tmp_2539 ,bitlen);
share *s_a_tmp_2538 = acirc->PutY2AGate( s_y_tmp_2538 ,bcirc);
s_a_tmp10 = acirc->PutADDGate( s_a_tmp_2538 , s_a__tmp_2539 );
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp7[_i1][_i4] = acirc->PutY2AGate( s_y_tmp7[_i1][_i4] ,bcirc);
}
}
for (uint32_t i7 = 0; i7 < 1; i7++)
{
    for (uint32_t i8 = 0; i8 < 5; i8++)
    {
        s_a_tmp11[i7][i8] = create_new_share(s_a_tmp7[i8][i7]->get_wires(), acirc );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_y_tmp11[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp11[_i1][_i4] );
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i10 = 0; i10 < 5; i10++)
    {
        uint32_t _tmp_2541 = 2147483648 ;
        share * s_y__tmp_2541 = ycirc->PutCONSGate( _tmp_2541 ,bitlen);
        share * s_y_tmp_2540 = ycirc->PutGTGate( s_y__tmp_2541 , s_y_tmp11[i9][i10] );
        vector<uint32_t> _vec2543 = s_y_tmp11[i9][i10]->get_wires();
        _vec2543.erase( _vec2543.begin(), _vec2543.begin() + 15 );
        share *s_y_tmp_2542 = create_new_share( _vec2543 , ycirc );
        uint32_t _tmp_2547 = 4294967295 ;
        share * s_y__tmp_2547 = ycirc->PutCONSGate( _tmp_2547 ,bitlen);
        share * s_y_tmp_2546 = ycirc->PutXORGate( s_y_tmp11[i9][i10] , s_y__tmp_2547 );
        vector<uint32_t> _vec2548 = s_y_tmp_2546->get_wires();
        _vec2548.erase( _vec2548.begin(), _vec2548.begin() + 15 );
        share *s_y_tmp_2545 = create_new_share( _vec2548 , ycirc );
        uint32_t _tmp_2549 = 4294967295 ;
        share * s_y__tmp_2549 = ycirc->PutCONSGate( _tmp_2549 ,bitlen);
        share * s_y_tmp_2544 = ycirc->PutXORGate( s_y_tmp_2545 , s_y__tmp_2549 );
        s_y_tmp13[i9][i10] = ycirc->PutMUXGate( s_y_tmp_2542 , s_y_tmp_2544 , s_y_tmp_2540 );
    }
}
for (uint32_t i10 = 0; i10 < 5; i10++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        uint32_t _tmp_2551 = 2147483648 ;
        share * s_y__tmp_2551 = ycirc->PutCONSGate( _tmp_2551 ,bitlen);
        share * s_y_tmp_2550 = ycirc->PutGTGate( s_y__tmp_2551 , s_y_tmp7[i10][i11] );
        vector<uint32_t> _vec2553 = s_y_tmp7[i10][i11]->get_wires();
        _vec2553.erase( _vec2553.begin(), _vec2553.begin() + 15 );
        share *s_y_tmp_2552 = create_new_share( _vec2553 , ycirc );
        uint32_t _tmp_2557 = 4294967295 ;
        share * s_y__tmp_2557 = ycirc->PutCONSGate( _tmp_2557 ,bitlen);
        share * s_y_tmp_2556 = ycirc->PutXORGate( s_y_tmp7[i10][i11] , s_y__tmp_2557 );
        vector<uint32_t> _vec2558 = s_y_tmp_2556->get_wires();
        _vec2558.erase( _vec2558.begin(), _vec2558.begin() + 15 );
        share *s_y_tmp_2555 = create_new_share( _vec2558 , ycirc );
        uint32_t _tmp_2559 = 4294967295 ;
        share * s_y__tmp_2559 = ycirc->PutCONSGate( _tmp_2559 ,bitlen);
        share * s_y_tmp_2554 = ycirc->PutXORGate( s_y_tmp_2555 , s_y__tmp_2559 );
        s_y_tmp14[i10][i11] = ycirc->PutMUXGate( s_y_tmp_2552 , s_y_tmp_2554 , s_y_tmp_2550 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
s_a_tmp13[_i1][_i4] = acirc->PutY2AGate( s_y_tmp13[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp14[_i1][_i4] = acirc->PutY2AGate( s_y_tmp14[_i1][_i4] ,bcirc);
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        for (uint32_t i10 = 0; i10 < 5; i10++)
        {
            s_a_tmp15[i9][i11][i10] = acirc->PutMULGate( s_a_tmp13[i9][i10] , s_a_tmp14[i10][i11] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 5 ; _i7++) {
s_y_tmp15[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp15[_i1][_i4][_i7] );
}
}
}
for (uint32_t i9 = 0; i9 < 1; i9++)
{
    for (uint32_t i11 = 0; i11 < 1; i11++)
    {
        tmp16 = 5 ;
        s_y_tmp16 = ycirc->PutCONSGate( tmp16 ,bitlen);
        for (uint32_t i12 = 0; i12 < 0; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec2562 = s_y_tmp16->get_wires();
                _vec2562.erase( _vec2562.begin(), _vec2562.begin() + 1 );
                share *s_y_tmp_2561 = create_new_share( _vec2562 , ycirc );
                share * s_y_tmp_2560 = ycirc->PutGTGate( s_y_tmp_2561 , s_y_tmp17 );
                share * s_y_tmp_2565 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_2566 = 2147483648 ;
                share * s_y__tmp_2566 = ycirc->PutCONSGate( _tmp_2566 ,bitlen);
                share * s_y_tmp_2564 = ycirc->PutGTGate( s_y__tmp_2566 , s_y_tmp_2565 );
                share * s_y_tmp_2568 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec2569 = s_y_tmp_2568->get_wires();
                _vec2569.erase( _vec2569.begin(), _vec2569.begin() + 1 );
                share *s_y_tmp_2567 = create_new_share( _vec2569 , ycirc );
                share * s_y_tmp_2573 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                uint32_t _tmp_2574 = 4294967295 ;
                share * s_y__tmp_2574 = ycirc->PutCONSGate( _tmp_2574 ,bitlen);
                share * s_y_tmp_2572 = ycirc->PutXORGate( s_y_tmp_2573 , s_y__tmp_2574 );
                vector<uint32_t> _vec2575 = s_y_tmp_2572->get_wires();
                _vec2575.erase( _vec2575.begin(), _vec2575.begin() + 1 );
                share *s_y_tmp_2571 = create_new_share( _vec2575 , ycirc );
                uint32_t _tmp_2576 = 4294967295 ;
                share * s_y__tmp_2576 = ycirc->PutCONSGate( _tmp_2576 ,bitlen);
                share * s_y_tmp_2570 = ycirc->PutXORGate( s_y_tmp_2571 , s_y__tmp_2576 );
                share * s_y_tmp_2563 = ycirc->PutMUXGate( s_y_tmp_2567 , s_y_tmp_2570 , s_y_tmp_2564 );
                vector<uint32_t> _vec2581 = s_y_tmp16->get_wires();
                _vec2581.erase( _vec2581.begin(), _vec2581.begin() + 1 );
                share *s_y_tmp_2580 = create_new_share( _vec2581 , ycirc );
                share * s_y_tmp_2579 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_2580 );
                uint32_t _tmp_2584 = 1 ;
                share * s_y__tmp_2584 = ycirc->PutCONSGate( _tmp_2584 ,bitlen);
                share * s_y_tmp_2583 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_2584 );
                uint32_t _tmp_2585 = 1 ;
                share * s_y__tmp_2585 = ycirc->PutCONSGate( _tmp_2585 ,bitlen);
                share * s_y_tmp_2582 = ycirc->PutEQGate( s_y_tmp_2583 , s_y__tmp_2585 );
                share * s_y_tmp_2578 = ycirc->PutANDGate( s_y_tmp_2579 , s_y_tmp_2582 );
                uint32_t _tmp_2588 = 2147483648 ;
                share * s_y__tmp_2588 = ycirc->PutCONSGate( _tmp_2588 ,bitlen);
                share * s_y_tmp_2587 = ycirc->PutGTGate( s_y__tmp_2588 , s_y_tmp15[i9][i11][(2*i13)] );
                vector<uint32_t> _vec2590 = s_y_tmp15[i9][i11][(2*i13)]->get_wires();
                _vec2590.erase( _vec2590.begin(), _vec2590.begin() + 1 );
                share *s_y_tmp_2589 = create_new_share( _vec2590 , ycirc );
                uint32_t _tmp_2594 = 4294967295 ;
                share * s_y__tmp_2594 = ycirc->PutCONSGate( _tmp_2594 ,bitlen);
                share * s_y_tmp_2593 = ycirc->PutXORGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_2594 );
                vector<uint32_t> _vec2595 = s_y_tmp_2593->get_wires();
                _vec2595.erase( _vec2595.begin(), _vec2595.begin() + 1 );
                share *s_y_tmp_2592 = create_new_share( _vec2595 , ycirc );
                uint32_t _tmp_2596 = 4294967295 ;
                share * s_y__tmp_2596 = ycirc->PutCONSGate( _tmp_2596 ,bitlen);
                share * s_y_tmp_2591 = ycirc->PutXORGate( s_y_tmp_2592 , s_y__tmp_2596 );
                share * s_y_tmp_2586 = ycirc->PutMUXGate( s_y_tmp_2589 , s_y_tmp_2591 , s_y_tmp_2587 );
                uint32_t _tmp_2597 = 0 ;
                share * s_y__tmp_2597 = ycirc->PutCONSGate( _tmp_2597 ,bitlen);
                share * s_y_tmp_2577 = ycirc->PutMUXGate( s_y_tmp_2586 , s_y__tmp_2597 , s_y_tmp_2578 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_2563 , s_y_tmp_2577 , s_y_tmp_2560 );
                uint32_t _tmp_2598 = 1 ;
                share * s_y__tmp_2598 = ycirc->PutCONSGate( _tmp_2598 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_2598 );
            }
            uint32_t _tmp_2600 = 1 ;
            share * s_y__tmp_2600 = ycirc->PutCONSGate( _tmp_2600 ,bitlen);
            share * s_y_tmp_2599 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_2600 );
            vector<uint32_t> _vec2601 = s_y_tmp_2599->get_wires();
            _vec2601.erase( _vec2601.begin(), _vec2601.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec2601 , ycirc );
        }
        for (uint32_t i12 = 0; i12 < 3; i12++)
        {
            tmp17 = 0 ;
            s_y_tmp17 = ycirc->PutCONSGate( tmp17 ,bitlen);
            for (uint32_t i13 = 0; i13 < 3; i13++)
            {
                vector<uint32_t> _vec2604 = s_y_tmp16->get_wires();
                _vec2604.erase( _vec2604.begin(), _vec2604.begin() + 1 );
                share *s_y_tmp_2603 = create_new_share( _vec2604 , ycirc );
                share * s_y_tmp_2602 = ycirc->PutGTGate( s_y_tmp_2603 , s_y_tmp17 );
                share * s_y_tmp_2605 = ycirc->PutADDGate( s_y_tmp15[i9][i11][(2*i13)] , s_y_tmp15[i9][i11][((2*i13)+1)] );
                vector<uint32_t> _vec2610 = s_y_tmp16->get_wires();
                _vec2610.erase( _vec2610.begin(), _vec2610.begin() + 1 );
                share *s_y_tmp_2609 = create_new_share( _vec2610 , ycirc );
                share * s_y_tmp_2608 = ycirc->PutEQGate( s_y_tmp17 , s_y_tmp_2609 );
                uint32_t _tmp_2613 = 1 ;
                share * s_y__tmp_2613 = ycirc->PutCONSGate( _tmp_2613 ,bitlen);
                share * s_y_tmp_2612 = ycirc->PutANDGate( s_y_tmp16 , s_y__tmp_2613 );
                uint32_t _tmp_2614 = 1 ;
                share * s_y__tmp_2614 = ycirc->PutCONSGate( _tmp_2614 ,bitlen);
                share * s_y_tmp_2611 = ycirc->PutEQGate( s_y_tmp_2612 , s_y__tmp_2614 );
                share * s_y_tmp_2607 = ycirc->PutANDGate( s_y_tmp_2608 , s_y_tmp_2611 );
                uint32_t _tmp_2615 = 0 ;
                share * s_y__tmp_2615 = ycirc->PutCONSGate( _tmp_2615 ,bitlen);
                share * s_y_tmp_2606 = ycirc->PutMUXGate( s_y_tmp15[i9][i11][(2*i13)] , s_y__tmp_2615 , s_y_tmp_2607 );
                s_y_tmp15[i9][i11][i13] = ycirc->PutMUXGate( s_y_tmp_2605 , s_y_tmp_2606 , s_y_tmp_2602 );
                uint32_t _tmp_2616 = 1 ;
                share * s_y__tmp_2616 = ycirc->PutCONSGate( _tmp_2616 ,bitlen);
                s_y_tmp17 = ycirc->PutADDGate( s_y_tmp17 , s_y__tmp_2616 );
            }
            uint32_t _tmp_2618 = 1 ;
            share * s_y__tmp_2618 = ycirc->PutCONSGate( _tmp_2618 ,bitlen);
            share * s_y_tmp_2617 = ycirc->PutADDGate( s_y_tmp16 , s_y__tmp_2618 );
            vector<uint32_t> _vec2619 = s_y_tmp_2617->get_wires();
            _vec2619.erase( _vec2619.begin(), _vec2619.begin() + 1 );
            s_y_tmp16 = create_new_share( _vec2619 , ycirc );
        }
        s_y_tmp12[i9][i11] = create_new_share(s_y_tmp15[i9][i11][0]->get_wires(), ycirc );
    }
}
s_y_tmp10 = ycirc->PutA2YGate( s_a_tmp10 );
uint32_t _tmp_2621 = 2147483648 ;
share * s_y__tmp_2621 = ycirc->PutCONSGate( _tmp_2621 ,bitlen);
share * s_y_tmp_2620 = ycirc->PutGTGate( s_y__tmp_2621 , s_y_tmp10 );
vector<uint32_t> _vec2623 = s_y_tmp10->get_wires();
_vec2623.erase( _vec2623.begin(), _vec2623.begin() + 15 );
share *s_y_tmp_2622 = create_new_share( _vec2623 , ycirc );
uint32_t _tmp_2627 = 4294967295 ;
share * s_y__tmp_2627 = ycirc->PutCONSGate( _tmp_2627 ,bitlen);
share * s_y_tmp_2626 = ycirc->PutXORGate( s_y_tmp10 , s_y__tmp_2627 );
vector<uint32_t> _vec2628 = s_y_tmp_2626->get_wires();
_vec2628.erase( _vec2628.begin(), _vec2628.begin() + 15 );
share *s_y_tmp_2625 = create_new_share( _vec2628 , ycirc );
uint32_t _tmp_2629 = 4294967295 ;
share * s_y__tmp_2629 = ycirc->PutCONSGate( _tmp_2629 ,bitlen);
share * s_y_tmp_2624 = ycirc->PutXORGate( s_y_tmp_2625 , s_y__tmp_2629 );
s_y_tmp19 = ycirc->PutMUXGate( s_y_tmp_2622 , s_y_tmp_2624 , s_y_tmp_2620 );
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        uint32_t _tmp_2631 = 2147483648 ;
        share * s_y__tmp_2631 = ycirc->PutCONSGate( _tmp_2631 ,bitlen);
        share * s_y_tmp_2630 = ycirc->PutGTGate( s_y__tmp_2631 , s_y_tmp12[i14][i15] );
        vector<uint32_t> _vec2633 = s_y_tmp12[i14][i15]->get_wires();
        _vec2633.erase( _vec2633.begin(), _vec2633.begin() + 15 );
        share *s_y_tmp_2632 = create_new_share( _vec2633 , ycirc );
        uint32_t _tmp_2637 = 4294967295 ;
        share * s_y__tmp_2637 = ycirc->PutCONSGate( _tmp_2637 ,bitlen);
        share * s_y_tmp_2636 = ycirc->PutXORGate( s_y_tmp12[i14][i15] , s_y__tmp_2637 );
        vector<uint32_t> _vec2638 = s_y_tmp_2636->get_wires();
        _vec2638.erase( _vec2638.begin(), _vec2638.begin() + 15 );
        share *s_y_tmp_2635 = create_new_share( _vec2638 , ycirc );
        uint32_t _tmp_2639 = 4294967295 ;
        share * s_y__tmp_2639 = ycirc->PutCONSGate( _tmp_2639 ,bitlen);
        share * s_y_tmp_2634 = ycirc->PutXORGate( s_y_tmp_2635 , s_y__tmp_2639 );
        s_y_tmp20[i14][i15] = ycirc->PutMUXGate( s_y_tmp_2632 , s_y_tmp_2634 , s_y_tmp_2630 );
    }
}
s_a_tmp19 = acirc->PutY2AGate( s_y_tmp19 ,bcirc);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp20[_i1][_i4] = acirc->PutY2AGate( s_y_tmp20[_i1][_i4] ,bcirc);
}
}
for (uint32_t i14 = 0; i14 < 1; i14++)
{
    for (uint32_t i15 = 0; i15 < 1; i15++)
    {
        s_a_tmp18[i14][i15] = acirc->PutMULGate( s_a_tmp19 , s_a_tmp20[i14][i15] );
    }
}
tmp21 = 0 ;
s_a_tmp21[0][0] = acirc->PutCONSGate( tmp21 ,bitlen);
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i17 = 0; i17 < 1; i17++)
    {
        uint32_t _tmp_2641 = 2147483648 ;
        share * s_y__tmp_2641 = ycirc->PutCONSGate( _tmp_2641 ,bitlen);
        share * s_y_tmp_2640 = ycirc->PutGTGate( s_y__tmp_2641 , s_y_ZZ[9][i16][i17] );
        vector<uint32_t> _vec2643 = s_y_ZZ[9][i16][i17]->get_wires();
        _vec2643.erase( _vec2643.begin(), _vec2643.begin() + 15 );
        share *s_y_tmp_2642 = create_new_share( _vec2643 , ycirc );
        uint32_t _tmp_2647 = 4294967295 ;
        share * s_y__tmp_2647 = ycirc->PutCONSGate( _tmp_2647 ,bitlen);
        share * s_y_tmp_2646 = ycirc->PutXORGate( s_y_ZZ[9][i16][i17] , s_y__tmp_2647 );
        vector<uint32_t> _vec2648 = s_y_tmp_2646->get_wires();
        _vec2648.erase( _vec2648.begin(), _vec2648.begin() + 15 );
        share *s_y_tmp_2645 = create_new_share( _vec2648 , ycirc );
        uint32_t _tmp_2649 = 4294967295 ;
        share * s_y__tmp_2649 = ycirc->PutCONSGate( _tmp_2649 ,bitlen);
        share * s_y_tmp_2644 = ycirc->PutXORGate( s_y_tmp_2645 , s_y__tmp_2649 );
        s_y_tmp25[i16][i17] = ycirc->PutMUXGate( s_y_tmp_2642 , s_y_tmp_2644 , s_y_tmp_2640 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_y_tmp21[_i1][_i4] = ycirc->PutA2YGate( s_a_tmp21[_i1][_i4] );
}
}
for (uint32_t i17 = 0; i17 < 1; i17++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        uint32_t _tmp_2651 = 2147483648 ;
        share * s_y__tmp_2651 = ycirc->PutCONSGate( _tmp_2651 ,bitlen);
        share * s_y_tmp_2650 = ycirc->PutGTGate( s_y__tmp_2651 , s_y_tmp21[i17][i18] );
        vector<uint32_t> _vec2653 = s_y_tmp21[i17][i18]->get_wires();
        _vec2653.erase( _vec2653.begin(), _vec2653.begin() + 15 );
        share *s_y_tmp_2652 = create_new_share( _vec2653 , ycirc );
        uint32_t _tmp_2657 = 4294967295 ;
        share * s_y__tmp_2657 = ycirc->PutCONSGate( _tmp_2657 ,bitlen);
        share * s_y_tmp_2656 = ycirc->PutXORGate( s_y_tmp21[i17][i18] , s_y__tmp_2657 );
        vector<uint32_t> _vec2658 = s_y_tmp_2656->get_wires();
        _vec2658.erase( _vec2658.begin(), _vec2658.begin() + 15 );
        share *s_y_tmp_2655 = create_new_share( _vec2658 , ycirc );
        uint32_t _tmp_2659 = 4294967295 ;
        share * s_y__tmp_2659 = ycirc->PutCONSGate( _tmp_2659 ,bitlen);
        share * s_y_tmp_2654 = ycirc->PutXORGate( s_y_tmp_2655 , s_y__tmp_2659 );
        s_y_tmp26[i17][i18] = ycirc->PutMUXGate( s_y_tmp_2652 , s_y_tmp_2654 , s_y_tmp_2650 );
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp25[_i1][_i4] = acirc->PutY2AGate( s_y_tmp25[_i1][_i4] ,bcirc);
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
s_a_tmp26[_i1][_i4] = acirc->PutY2AGate( s_y_tmp26[_i1][_i4] ,bcirc);
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        for (uint32_t i17 = 0; i17 < 1; i17++)
        {
            s_a_tmp27[i16][i18][i17] = acirc->PutMULGate( s_a_tmp25[i16][i17] , s_a_tmp26[i17][i18] );
        }
    }
}
for (int _i1 = 0; _i1 < 2 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
s_y_tmp27[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_tmp27[_i1][_i4][_i7] );
}
}
}
for (uint32_t i16 = 0; i16 < 2; i16++)
{
    for (uint32_t i18 = 0; i18 < 1; i18++)
    {
        tmp28 = 1 ;
        s_y_tmp28 = ycirc->PutCONSGate( tmp28 ,bitlen);
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec2662 = s_y_tmp28->get_wires();
                _vec2662.erase( _vec2662.begin(), _vec2662.begin() + 1 );
                share *s_y_tmp_2661 = create_new_share( _vec2662 , ycirc );
                share * s_y_tmp_2660 = ycirc->PutGTGate( s_y_tmp_2661 , s_y_tmp29 );
                share * s_y_tmp_2665 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_2666 = 2147483648 ;
                share * s_y__tmp_2666 = ycirc->PutCONSGate( _tmp_2666 ,bitlen);
                share * s_y_tmp_2664 = ycirc->PutGTGate( s_y__tmp_2666 , s_y_tmp_2665 );
                share * s_y_tmp_2668 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec2669 = s_y_tmp_2668->get_wires();
                _vec2669.erase( _vec2669.begin(), _vec2669.begin() + 1 );
                share *s_y_tmp_2667 = create_new_share( _vec2669 , ycirc );
                share * s_y_tmp_2673 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                uint32_t _tmp_2674 = 4294967295 ;
                share * s_y__tmp_2674 = ycirc->PutCONSGate( _tmp_2674 ,bitlen);
                share * s_y_tmp_2672 = ycirc->PutXORGate( s_y_tmp_2673 , s_y__tmp_2674 );
                vector<uint32_t> _vec2675 = s_y_tmp_2672->get_wires();
                _vec2675.erase( _vec2675.begin(), _vec2675.begin() + 1 );
                share *s_y_tmp_2671 = create_new_share( _vec2675 , ycirc );
                uint32_t _tmp_2676 = 4294967295 ;
                share * s_y__tmp_2676 = ycirc->PutCONSGate( _tmp_2676 ,bitlen);
                share * s_y_tmp_2670 = ycirc->PutXORGate( s_y_tmp_2671 , s_y__tmp_2676 );
                share * s_y_tmp_2663 = ycirc->PutMUXGate( s_y_tmp_2667 , s_y_tmp_2670 , s_y_tmp_2664 );
                vector<uint32_t> _vec2681 = s_y_tmp28->get_wires();
                _vec2681.erase( _vec2681.begin(), _vec2681.begin() + 1 );
                share *s_y_tmp_2680 = create_new_share( _vec2681 , ycirc );
                share * s_y_tmp_2679 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_2680 );
                uint32_t _tmp_2684 = 1 ;
                share * s_y__tmp_2684 = ycirc->PutCONSGate( _tmp_2684 ,bitlen);
                share * s_y_tmp_2683 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_2684 );
                uint32_t _tmp_2685 = 1 ;
                share * s_y__tmp_2685 = ycirc->PutCONSGate( _tmp_2685 ,bitlen);
                share * s_y_tmp_2682 = ycirc->PutEQGate( s_y_tmp_2683 , s_y__tmp_2685 );
                share * s_y_tmp_2678 = ycirc->PutANDGate( s_y_tmp_2679 , s_y_tmp_2682 );
                uint32_t _tmp_2688 = 2147483648 ;
                share * s_y__tmp_2688 = ycirc->PutCONSGate( _tmp_2688 ,bitlen);
                share * s_y_tmp_2687 = ycirc->PutGTGate( s_y__tmp_2688 , s_y_tmp27[i16][i18][(2*i20)] );
                vector<uint32_t> _vec2690 = s_y_tmp27[i16][i18][(2*i20)]->get_wires();
                _vec2690.erase( _vec2690.begin(), _vec2690.begin() + 1 );
                share *s_y_tmp_2689 = create_new_share( _vec2690 , ycirc );
                uint32_t _tmp_2694 = 4294967295 ;
                share * s_y__tmp_2694 = ycirc->PutCONSGate( _tmp_2694 ,bitlen);
                share * s_y_tmp_2693 = ycirc->PutXORGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_2694 );
                vector<uint32_t> _vec2695 = s_y_tmp_2693->get_wires();
                _vec2695.erase( _vec2695.begin(), _vec2695.begin() + 1 );
                share *s_y_tmp_2692 = create_new_share( _vec2695 , ycirc );
                uint32_t _tmp_2696 = 4294967295 ;
                share * s_y__tmp_2696 = ycirc->PutCONSGate( _tmp_2696 ,bitlen);
                share * s_y_tmp_2691 = ycirc->PutXORGate( s_y_tmp_2692 , s_y__tmp_2696 );
                share * s_y_tmp_2686 = ycirc->PutMUXGate( s_y_tmp_2689 , s_y_tmp_2691 , s_y_tmp_2687 );
                uint32_t _tmp_2697 = 0 ;
                share * s_y__tmp_2697 = ycirc->PutCONSGate( _tmp_2697 ,bitlen);
                share * s_y_tmp_2677 = ycirc->PutMUXGate( s_y_tmp_2686 , s_y__tmp_2697 , s_y_tmp_2678 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_2663 , s_y_tmp_2677 , s_y_tmp_2660 );
                uint32_t _tmp_2698 = 1 ;
                share * s_y__tmp_2698 = ycirc->PutCONSGate( _tmp_2698 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_2698 );
            }
            uint32_t _tmp_2700 = 1 ;
            share * s_y__tmp_2700 = ycirc->PutCONSGate( _tmp_2700 ,bitlen);
            share * s_y_tmp_2699 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_2700 );
            vector<uint32_t> _vec2701 = s_y_tmp_2699->get_wires();
            _vec2701.erase( _vec2701.begin(), _vec2701.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec2701 , ycirc );
        }
        for (uint32_t i19 = 0; i19 < 0; i19++)
        {
            tmp29 = 0 ;
            s_y_tmp29 = ycirc->PutCONSGate( tmp29 ,bitlen);
            for (uint32_t i20 = 0; i20 < 1; i20++)
            {
                vector<uint32_t> _vec2704 = s_y_tmp28->get_wires();
                _vec2704.erase( _vec2704.begin(), _vec2704.begin() + 1 );
                share *s_y_tmp_2703 = create_new_share( _vec2704 , ycirc );
                share * s_y_tmp_2702 = ycirc->PutGTGate( s_y_tmp_2703 , s_y_tmp29 );
                share * s_y_tmp_2705 = ycirc->PutADDGate( s_y_tmp27[i16][i18][(2*i20)] , s_y_tmp27[i16][i18][((2*i20)+1)] );
                vector<uint32_t> _vec2710 = s_y_tmp28->get_wires();
                _vec2710.erase( _vec2710.begin(), _vec2710.begin() + 1 );
                share *s_y_tmp_2709 = create_new_share( _vec2710 , ycirc );
                share * s_y_tmp_2708 = ycirc->PutEQGate( s_y_tmp29 , s_y_tmp_2709 );
                uint32_t _tmp_2713 = 1 ;
                share * s_y__tmp_2713 = ycirc->PutCONSGate( _tmp_2713 ,bitlen);
                share * s_y_tmp_2712 = ycirc->PutANDGate( s_y_tmp28 , s_y__tmp_2713 );
                uint32_t _tmp_2714 = 1 ;
                share * s_y__tmp_2714 = ycirc->PutCONSGate( _tmp_2714 ,bitlen);
                share * s_y_tmp_2711 = ycirc->PutEQGate( s_y_tmp_2712 , s_y__tmp_2714 );
                share * s_y_tmp_2707 = ycirc->PutANDGate( s_y_tmp_2708 , s_y_tmp_2711 );
                uint32_t _tmp_2715 = 0 ;
                share * s_y__tmp_2715 = ycirc->PutCONSGate( _tmp_2715 ,bitlen);
                share * s_y_tmp_2706 = ycirc->PutMUXGate( s_y_tmp27[i16][i18][(2*i20)] , s_y__tmp_2715 , s_y_tmp_2707 );
                s_y_tmp27[i16][i18][i20] = ycirc->PutMUXGate( s_y_tmp_2705 , s_y_tmp_2706 , s_y_tmp_2702 );
                uint32_t _tmp_2716 = 1 ;
                share * s_y__tmp_2716 = ycirc->PutCONSGate( _tmp_2716 ,bitlen);
                s_y_tmp29 = ycirc->PutADDGate( s_y_tmp29 , s_y__tmp_2716 );
            }
            uint32_t _tmp_2718 = 1 ;
            share * s_y__tmp_2718 = ycirc->PutCONSGate( _tmp_2718 ,bitlen);
            share * s_y_tmp_2717 = ycirc->PutADDGate( s_y_tmp28 , s_y__tmp_2718 );
            vector<uint32_t> _vec2719 = s_y_tmp_2717->get_wires();
            _vec2719.erase( _vec2719.begin(), _vec2719.begin() + 1 );
            s_y_tmp28 = create_new_share( _vec2719 , ycirc );
        }
        s_y_tmp31[9][i16][i18] = create_new_share(s_y_tmp27[i16][i18][0]->get_wires(), ycirc );
    }
}
share * s_y_tmp32 ;
share * s_y_tmp33 ;
auto s_y_tmp30 = make_vector<share*>(2, 1);
for (uint32_t i21 = 0; i21 < 2; i21++)
{
    for (uint32_t i22 = 0; i22 < 1; i22++)
    {
        tmp32 = 10 ;
        s_y_tmp32 = ycirc->PutCONSGate( tmp32 ,bitlen);
        for (uint32_t i23 = 0; i23 < 4; i23++)
        {
            tmp33 = 0 ;
            s_y_tmp33 = ycirc->PutCONSGate( tmp33 ,bitlen);
            for (uint32_t i24 = 0; i24 < 6; i24++)
            {
                vector<uint32_t> _vec2722 = s_y_tmp32->get_wires();
                _vec2722.erase( _vec2722.begin(), _vec2722.begin() + 1 );
                share *s_y_tmp_2721 = create_new_share( _vec2722 , ycirc );
                share * s_y_tmp_2720 = ycirc->PutGTGate( s_y_tmp_2721 , s_y_tmp33 );
                share * s_y_tmp_2725 = ycirc->PutADDGate( s_y_tmp31[(2*i24)][i21][i22] , s_y_tmp31[((2*i24)+1)][i21][i22] );
                uint32_t _tmp_2726 = 2147483648 ;
                share * s_y__tmp_2726 = ycirc->PutCONSGate( _tmp_2726 ,bitlen);
                share * s_y_tmp_2724 = ycirc->PutGTGate( s_y__tmp_2726 , s_y_tmp_2725 );
                share * s_y_tmp_2728 = ycirc->PutADDGate( s_y_tmp31[(2*i24)][i21][i22] , s_y_tmp31[((2*i24)+1)][i21][i22] );
                vector<uint32_t> _vec2729 = s_y_tmp_2728->get_wires();
                _vec2729.erase( _vec2729.begin(), _vec2729.begin() + 1 );
                share *s_y_tmp_2727 = create_new_share( _vec2729 , ycirc );
                share * s_y_tmp_2733 = ycirc->PutADDGate( s_y_tmp31[(2*i24)][i21][i22] , s_y_tmp31[((2*i24)+1)][i21][i22] );
                uint32_t _tmp_2734 = 4294967295 ;
                share * s_y__tmp_2734 = ycirc->PutCONSGate( _tmp_2734 ,bitlen);
                share * s_y_tmp_2732 = ycirc->PutXORGate( s_y_tmp_2733 , s_y__tmp_2734 );
                vector<uint32_t> _vec2735 = s_y_tmp_2732->get_wires();
                _vec2735.erase( _vec2735.begin(), _vec2735.begin() + 1 );
                share *s_y_tmp_2731 = create_new_share( _vec2735 , ycirc );
                uint32_t _tmp_2736 = 4294967295 ;
                share * s_y__tmp_2736 = ycirc->PutCONSGate( _tmp_2736 ,bitlen);
                share * s_y_tmp_2730 = ycirc->PutXORGate( s_y_tmp_2731 , s_y__tmp_2736 );
                share * s_y_tmp_2723 = ycirc->PutMUXGate( s_y_tmp_2727 , s_y_tmp_2730 , s_y_tmp_2724 );
                vector<uint32_t> _vec2741 = s_y_tmp32->get_wires();
                _vec2741.erase( _vec2741.begin(), _vec2741.begin() + 1 );
                share *s_y_tmp_2740 = create_new_share( _vec2741 , ycirc );
                share * s_y_tmp_2739 = ycirc->PutEQGate( s_y_tmp33 , s_y_tmp_2740 );
                uint32_t _tmp_2744 = 1 ;
                share * s_y__tmp_2744 = ycirc->PutCONSGate( _tmp_2744 ,bitlen);
                share * s_y_tmp_2743 = ycirc->PutANDGate( s_y_tmp32 , s_y__tmp_2744 );
                uint32_t _tmp_2745 = 1 ;
                share * s_y__tmp_2745 = ycirc->PutCONSGate( _tmp_2745 ,bitlen);
                share * s_y_tmp_2742 = ycirc->PutEQGate( s_y_tmp_2743 , s_y__tmp_2745 );
                share * s_y_tmp_2738 = ycirc->PutANDGate( s_y_tmp_2739 , s_y_tmp_2742 );
                uint32_t _tmp_2748 = 2147483648 ;
                share * s_y__tmp_2748 = ycirc->PutCONSGate( _tmp_2748 ,bitlen);
                share * s_y_tmp_2747 = ycirc->PutGTGate( s_y__tmp_2748 , s_y_tmp31[(2*i24)][i21][i22] );
                vector<uint32_t> _vec2750 = s_y_tmp31[(2*i24)][i21][i22]->get_wires();
                _vec2750.erase( _vec2750.begin(), _vec2750.begin() + 1 );
                share *s_y_tmp_2749 = create_new_share( _vec2750 , ycirc );
                uint32_t _tmp_2754 = 4294967295 ;
                share * s_y__tmp_2754 = ycirc->PutCONSGate( _tmp_2754 ,bitlen);
                share * s_y_tmp_2753 = ycirc->PutXORGate( s_y_tmp31[(2*i24)][i21][i22] , s_y__tmp_2754 );
                vector<uint32_t> _vec2755 = s_y_tmp_2753->get_wires();
                _vec2755.erase( _vec2755.begin(), _vec2755.begin() + 1 );
                share *s_y_tmp_2752 = create_new_share( _vec2755 , ycirc );
                uint32_t _tmp_2756 = 4294967295 ;
                share * s_y__tmp_2756 = ycirc->PutCONSGate( _tmp_2756 ,bitlen);
                share * s_y_tmp_2751 = ycirc->PutXORGate( s_y_tmp_2752 , s_y__tmp_2756 );
                share * s_y_tmp_2746 = ycirc->PutMUXGate( s_y_tmp_2749 , s_y_tmp_2751 , s_y_tmp_2747 );
                uint32_t _tmp_2757 = 0 ;
                share * s_y__tmp_2757 = ycirc->PutCONSGate( _tmp_2757 ,bitlen);
                share * s_y_tmp_2737 = ycirc->PutMUXGate( s_y_tmp_2746 , s_y__tmp_2757 , s_y_tmp_2738 );
                s_y_tmp31[i24][i21][i22] = ycirc->PutMUXGate( s_y_tmp_2723 , s_y_tmp_2737 , s_y_tmp_2720 );
                uint32_t _tmp_2758 = 1 ;
                share * s_y__tmp_2758 = ycirc->PutCONSGate( _tmp_2758 ,bitlen);
                s_y_tmp33 = ycirc->PutADDGate( s_y_tmp33 , s_y__tmp_2758 );
            }
            uint32_t _tmp_2760 = 1 ;
            share * s_y__tmp_2760 = ycirc->PutCONSGate( _tmp_2760 ,bitlen);
            share * s_y_tmp_2759 = ycirc->PutADDGate( s_y_tmp32 , s_y__tmp_2760 );
            vector<uint32_t> _vec2761 = s_y_tmp_2759->get_wires();
            _vec2761.erase( _vec2761.begin(), _vec2761.begin() + 1 );
            s_y_tmp32 = create_new_share( _vec2761 , ycirc );
        }
        for (uint32_t i23 = 0; i23 < 0; i23++)
        {
            tmp33 = 0 ;
            s_y_tmp33 = ycirc->PutCONSGate( tmp33 ,bitlen);
            for (uint32_t i24 = 0; i24 < 6; i24++)
            {
                vector<uint32_t> _vec2764 = s_y_tmp32->get_wires();
                _vec2764.erase( _vec2764.begin(), _vec2764.begin() + 1 );
                share *s_y_tmp_2763 = create_new_share( _vec2764 , ycirc );
                share * s_y_tmp_2762 = ycirc->PutGTGate( s_y_tmp_2763 , s_y_tmp33 );
                share * s_y_tmp_2765 = ycirc->PutADDGate( s_y_tmp31[(2*i24)][i21][i22] , s_y_tmp31[((2*i24)+1)][i21][i22] );
                vector<uint32_t> _vec2770 = s_y_tmp32->get_wires();
                _vec2770.erase( _vec2770.begin(), _vec2770.begin() + 1 );
                share *s_y_tmp_2769 = create_new_share( _vec2770 , ycirc );
                share * s_y_tmp_2768 = ycirc->PutEQGate( s_y_tmp33 , s_y_tmp_2769 );
                uint32_t _tmp_2773 = 1 ;
                share * s_y__tmp_2773 = ycirc->PutCONSGate( _tmp_2773 ,bitlen);
                share * s_y_tmp_2772 = ycirc->PutANDGate( s_y_tmp32 , s_y__tmp_2773 );
                uint32_t _tmp_2774 = 1 ;
                share * s_y__tmp_2774 = ycirc->PutCONSGate( _tmp_2774 ,bitlen);
                share * s_y_tmp_2771 = ycirc->PutEQGate( s_y_tmp_2772 , s_y__tmp_2774 );
                share * s_y_tmp_2767 = ycirc->PutANDGate( s_y_tmp_2768 , s_y_tmp_2771 );
                uint32_t _tmp_2775 = 0 ;
                share * s_y__tmp_2775 = ycirc->PutCONSGate( _tmp_2775 ,bitlen);
                share * s_y_tmp_2766 = ycirc->PutMUXGate( s_y_tmp31[(2*i24)][i21][i22] , s_y__tmp_2775 , s_y_tmp_2767 );
                s_y_tmp31[i24][i21][i22] = ycirc->PutMUXGate( s_y_tmp_2765 , s_y_tmp_2766 , s_y_tmp_2762 );
                uint32_t _tmp_2776 = 1 ;
                share * s_y__tmp_2776 = ycirc->PutCONSGate( _tmp_2776 ,bitlen);
                s_y_tmp33 = ycirc->PutADDGate( s_y_tmp33 , s_y__tmp_2776 );
            }
            uint32_t _tmp_2778 = 1 ;
            share * s_y__tmp_2778 = ycirc->PutCONSGate( _tmp_2778 ,bitlen);
            share * s_y_tmp_2777 = ycirc->PutADDGate( s_y_tmp32 , s_y__tmp_2778 );
            vector<uint32_t> _vec2779 = s_y_tmp_2777->get_wires();
            _vec2779.erase( _vec2779.begin(), _vec2779.begin() + 1 );
            s_y_tmp32 = create_new_share( _vec2779 , ycirc );
        }
        s_y_tmp30[i21][i22] = create_new_share(s_y_tmp31[0][i21][i22]->get_wires(), ycirc );
    }
}
tmp34 = 0 ;
share *s_y_tmp34 = ycirc->PutCONSGate( tmp34 ,bitlen);
tmp35 = 0 ;
share *s_y_tmp35 = ycirc->PutCONSGate( tmp35 ,bitlen);
share *s_y_tmp36 = create_new_share(s_y_tmp30[0][0]->get_wires(), ycirc );
share * s_y_tmp37 ;
for (uint32_t i25 = 0; i25 < 2; i25++)
{
    for (uint32_t i26 = 0; i26 < 1; i26++)
    {
        uint32_t _tmp_2781 = 2147483648 ;
        share * s_y__tmp_2781 = ycirc->PutCONSGate( _tmp_2781 ,bitlen);
        share * s_y_tmp_2780 = ycirc->PutGTGate( s_y__tmp_2781 , s_y_tmp36 );
        uint32_t _tmp_2784 = 2147483648 ;
        share * s_y__tmp_2784 = ycirc->PutCONSGate( _tmp_2784 ,bitlen);
        share * s_y_tmp_2783 = ycirc->PutGTGate( s_y__tmp_2784 , s_y_tmp30[i25][i26] );
        share * s_y_tmp_2786 = ycirc->PutGTGate( s_y_tmp36 , s_y_tmp30[i25][i26] );
        share * s_y_tmp_2785 = ycirc->PutMUXGate( s_y_tmp36 , s_y_tmp30[i25][i26] , s_y_tmp_2786 );
        share * s_y_tmp_2782 = ycirc->PutMUXGate( s_y_tmp_2785 , s_y_tmp36 , s_y_tmp_2783 );
        uint32_t _tmp_2789 = 2147483648 ;
        share * s_y__tmp_2789 = ycirc->PutCONSGate( _tmp_2789 ,bitlen);
        share * s_y_tmp_2788 = ycirc->PutGTGate( s_y__tmp_2789 , s_y_tmp30[i25][i26] );
        share * s_y_tmp_2791 = ycirc->PutGTGate( s_y_tmp36 , s_y_tmp30[i25][i26] );
        share * s_y_tmp_2790 = ycirc->PutMUXGate( s_y_tmp36 , s_y_tmp30[i25][i26] , s_y_tmp_2791 );
        share * s_y_tmp_2787 = ycirc->PutMUXGate( s_y_tmp30[i25][i26] , s_y_tmp_2790 , s_y_tmp_2788 );
        s_y_tmp37 = ycirc->PutMUXGate( s_y_tmp_2782 , s_y_tmp_2787 , s_y_tmp_2780 );
        share * s_y_tmp_2792 = ycirc->PutEQGate( s_y_tmp36 , s_y_tmp37 );
        s_y_tmp35 = ycirc->PutMUXGate( s_y_tmp35 , s_y_tmp34 , s_y_tmp_2792 );
        s_y_tmp36 = create_new_share(s_y_tmp37->get_wires(), ycirc );
        uint32_t _tmp_2793 = 1 ;
        share * s_y__tmp_2793 = ycirc->PutCONSGate( _tmp_2793 ,bitlen);
        s_y_tmp34 = ycirc->PutADDGate( s_y_tmp34 , s_y__tmp_2793 );
    }
}
share * s_y_tmp_2794 = ycirc->PutOUTGate( s_y_tmp35 , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_2794->get_clear_value<uint32_t>();
