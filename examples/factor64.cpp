bitlen = 64;
ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 120000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto S1 = make_vector<uint64_t>(16384, 24);
auto s_a_S1 = make_vector<share*>(16384, 24);
auto S2 = make_vector<uint64_t>(16384, 24);
auto s_a_S2 = make_vector<share*>(16384, 24);
auto S = make_vector<uint64_t>(16384, 24);
auto s_a_S = make_vector<share*>(16384, 24);
auto outmat = make_vector<uint64_t>(16384, 24);
auto s_a_outmat = make_vector<share*>(16384, 24);
auto boolarr = make_vector<uint64_t>(1000000);
auto s_a_boolarr = make_vector<share*>(1000000);
auto temp = make_vector<uint64_t>(10);
auto s_a_temp = make_vector<share*>(10);
auto dots = make_vector<uint64_t>(15444);
auto s_a_dots = make_vector<share*>(15444);
uint64_t boolidx;
uint64_t b;
share *s_a_b;
uint64_t b1;
share *s_a_b1;
boolidx = 0;
for (uint64_t i = 0; i < 16384; i++)
{
    for (uint64_t j = 0; j < 24; j++)
    {
        if (role == SERVER) {
            S1[i][j] = 50 ;
            s_a_S1[i][j] = acirc->PutINGate( S1[i][j] ,bitlen,SERVER);
        } else {
            s_a_S1[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint64_t i = 0; i < 1000000; i++)
{
    if (role == SERVER) {
        boolarr[i] = 1 ;
        s_a_boolarr[i] = acirc->PutINGate( boolarr[i] ,bitlen,SERVER);
    } else {
        s_a_boolarr[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint64_t i = 0; i < 16384; i++)
{
    for (uint64_t j = 0; j < 24; j++)
    {
        if (role == CLIENT) {
            S2[i][j] = 60 ;
            s_a_S2[i][j] = acirc->PutINGate( S2[i][j] ,bitlen,CLIENT);
        } else {
            s_a_S2[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint64_t i = 0; i < 16384; i++)
{
    for (uint64_t j = 0; j < 24; j++)
    {
        s_a_S[i][j] = acirc->PutADDGate( s_a_S1[i][j] , s_a_S2[i][j] );
    }
}
for (uint64_t i = 0; i < 8192; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_0 = 1 ;
    share * s_a__tmp_0 = acirc->PutCONSGate( _tmp_0 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_0 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_1 = acirc->PutMULGate( s_a_b , s_a_S[2*i][j] );
        share * s_a_tmp_2 = acirc->PutMULGate( s_a_b1 , s_a_S[2*i+1][j] );
        s_a_outmat[2*i][j] = acirc->PutADDGate( s_a_tmp_1 , s_a_tmp_2 );
        share * s_a_tmp_3 = acirc->PutMULGate( s_a_b1 , s_a_S[2*i][j] );
        share * s_a_tmp_4 = acirc->PutMULGate( s_a_b , s_a_S[2*i+1][j] );
        s_a_outmat[2*i+1][j] = acirc->PutADDGate( s_a_tmp_3 , s_a_tmp_4 );
    }
}
for (uint64_t i = 0; i < 4096; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_5 = 1 ;
    share * s_a__tmp_5 = acirc->PutCONSGate( _tmp_5 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_5 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_6 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i][j] );
        share * s_a_tmp_7 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i][j] = acirc->PutADDGate( s_a_tmp_6 , s_a_tmp_7 );
        share * s_a_tmp_8 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i][j] );
        share * s_a_tmp_9 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+2][j] = acirc->PutADDGate( s_a_tmp_8 , s_a_tmp_9 );
    }
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_10 = 1 ;
    share * s_a__tmp_10 = acirc->PutCONSGate( _tmp_10 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_10 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_11 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_12 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+3][j] );
        s_a_outmat[4*i+1][j] = acirc->PutADDGate( s_a_tmp_11 , s_a_tmp_12 );
        share * s_a_tmp_13 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_14 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+3][j] );
        s_a_outmat[4*i+3][j] = acirc->PutADDGate( s_a_tmp_13 , s_a_tmp_14 );
    }
}
for (uint64_t i = 0; i < 4096; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_15 = 1 ;
    share * s_a__tmp_15 = acirc->PutCONSGate( _tmp_15 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_15 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_16 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_17 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+2][j] = acirc->PutADDGate( s_a_tmp_16 , s_a_tmp_17 );
        share * s_a_tmp_18 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_19 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+1][j] = acirc->PutADDGate( s_a_tmp_18 , s_a_tmp_19 );
    }
}
for (uint64_t i = 0; i < 2048; i++)
{
    for (uint64_t k = 0; k < 2; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_20 = 1 ;
        share * s_a__tmp_20 = acirc->PutCONSGate( _tmp_20 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_20 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_21 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2*k][j] );
            share * s_a_tmp_22 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+4+2*k][j] );
            s_a_outmat[8*i+2*k][j] = acirc->PutADDGate( s_a_tmp_21 , s_a_tmp_22 );
            share * s_a_tmp_23 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2*k][j] );
            share * s_a_tmp_24 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+4+2*k][j] );
            s_a_outmat[8*i+4+2*k][j] = acirc->PutADDGate( s_a_tmp_23 , s_a_tmp_24 );
        }
    }
    for (uint64_t k = 0; k < 2; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_25 = 1 ;
        share * s_a__tmp_25 = acirc->PutCONSGate( _tmp_25 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_25 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_26 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2*k+1][j] );
            share * s_a_tmp_27 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+4+2*k+1][j] );
            s_a_outmat[8*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_26 , s_a_tmp_27 );
            share * s_a_tmp_28 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2*k+1][j] );
            share * s_a_tmp_29 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+4+2*k+1][j] );
            s_a_outmat[8*i+4+2*k+1][j] = acirc->PutADDGate( s_a_tmp_28 , s_a_tmp_29 );
        }
    }
}
for (uint64_t i = 0; i < 2048; i++)
{
    for (uint64_t k = 0; k < 3; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_30 = 1 ;
        share * s_a__tmp_30 = acirc->PutCONSGate( _tmp_30 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_30 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_31 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+1+2*k][j] );
            share * s_a_tmp_32 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2+2*k][j] );
            s_a_outmat[8*i+2+2*k][j] = acirc->PutADDGate( s_a_tmp_31 , s_a_tmp_32 );
            share * s_a_tmp_33 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+1+2*k][j] );
            share * s_a_tmp_34 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2+2*k][j] );
            s_a_outmat[8*i+1+2*k][j] = acirc->PutADDGate( s_a_tmp_33 , s_a_tmp_34 );
        }
    }
}
for (uint64_t i = 0; i < 1024; i++)
{
    for (uint64_t k = 0; k < 4; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_35 = 1 ;
        share * s_a__tmp_35 = acirc->PutCONSGate( _tmp_35 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_35 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_36 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k][j] );
            share * s_a_tmp_37 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+8][j] );
            s_a_outmat[16*i+2*k][j] = acirc->PutADDGate( s_a_tmp_36 , s_a_tmp_37 );
            share * s_a_tmp_38 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k][j] );
            share * s_a_tmp_39 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+8][j] );
            s_a_outmat[16*i+2*k+8][j] = acirc->PutADDGate( s_a_tmp_38 , s_a_tmp_39 );
        }
    }
    for (uint64_t k = 0; k < 4; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_40 = 1 ;
        share * s_a__tmp_40 = acirc->PutCONSGate( _tmp_40 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_40 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_41 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_42 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+8+1][j] );
            s_a_outmat[16*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_41 , s_a_tmp_42 );
            share * s_a_tmp_43 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_44 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+8+1][j] );
            s_a_outmat[16*i+2*k+8+1][j] = acirc->PutADDGate( s_a_tmp_43 , s_a_tmp_44 );
        }
    }
}
for (uint64_t i = 0; i < 1024; i++)
{
    for (uint64_t k = 0; k < 7; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_45 = 1 ;
        share * s_a__tmp_45 = acirc->PutCONSGate( _tmp_45 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_45 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_46 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_47 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+2][j] );
            s_a_outmat[16*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_46 , s_a_tmp_47 );
            share * s_a_tmp_48 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_49 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+2][j] );
            s_a_outmat[16*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_48 , s_a_tmp_49 );
        }
    }
}
for (uint64_t i = 0; i < 512; i++)
{
    for (uint64_t k = 0; k < 8; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_50 = 1 ;
        share * s_a__tmp_50 = acirc->PutCONSGate( _tmp_50 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_50 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_51 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k][j] );
            share * s_a_tmp_52 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+16][j] );
            s_a_outmat[32*i+2*k][j] = acirc->PutADDGate( s_a_tmp_51 , s_a_tmp_52 );
            share * s_a_tmp_53 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k][j] );
            share * s_a_tmp_54 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+16][j] );
            s_a_outmat[32*i+2*k+16][j] = acirc->PutADDGate( s_a_tmp_53 , s_a_tmp_54 );
        }
    }
    for (uint64_t k = 0; k < 8; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_55 = 1 ;
        share * s_a__tmp_55 = acirc->PutCONSGate( _tmp_55 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_55 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_56 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_57 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+16+1][j] );
            s_a_outmat[32*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_56 , s_a_tmp_57 );
            share * s_a_tmp_58 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_59 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+16+1][j] );
            s_a_outmat[32*i+2*k+16+1][j] = acirc->PutADDGate( s_a_tmp_58 , s_a_tmp_59 );
        }
    }
}
for (uint64_t i = 0; i < 512; i++)
{
    for (uint64_t k = 0; k < 15; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_60 = 1 ;
        share * s_a__tmp_60 = acirc->PutCONSGate( _tmp_60 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_60 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_61 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_62 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+2][j] );
            s_a_outmat[32*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_61 , s_a_tmp_62 );
            share * s_a_tmp_63 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_64 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+2][j] );
            s_a_outmat[32*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_63 , s_a_tmp_64 );
        }
    }
}
for (uint64_t i = 0; i < 256; i++)
{
    for (uint64_t k = 0; k < 16; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_65 = 1 ;
        share * s_a__tmp_65 = acirc->PutCONSGate( _tmp_65 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_65 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_66 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k][j] );
            share * s_a_tmp_67 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+32][j] );
            s_a_outmat[64*i+2*k][j] = acirc->PutADDGate( s_a_tmp_66 , s_a_tmp_67 );
            share * s_a_tmp_68 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k][j] );
            share * s_a_tmp_69 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+32][j] );
            s_a_outmat[64*i+2*k+32][j] = acirc->PutADDGate( s_a_tmp_68 , s_a_tmp_69 );
        }
    }
    for (uint64_t k = 0; k < 16; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_70 = 1 ;
        share * s_a__tmp_70 = acirc->PutCONSGate( _tmp_70 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_70 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_71 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_72 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+32+1][j] );
            s_a_outmat[64*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_71 , s_a_tmp_72 );
            share * s_a_tmp_73 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_74 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+32+1][j] );
            s_a_outmat[64*i+2*k+32+1][j] = acirc->PutADDGate( s_a_tmp_73 , s_a_tmp_74 );
        }
    }
}
for (uint64_t i = 0; i < 256; i++)
{
    for (uint64_t k = 0; k < 31; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_75 = 1 ;
        share * s_a__tmp_75 = acirc->PutCONSGate( _tmp_75 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_75 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_76 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_77 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+2][j] );
            s_a_outmat[64*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_76 , s_a_tmp_77 );
            share * s_a_tmp_78 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_79 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+2][j] );
            s_a_outmat[64*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_78 , s_a_tmp_79 );
        }
    }
}
for (uint64_t i = 0; i < 128; i++)
{
    for (uint64_t k = 0; k < 32; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_80 = 1 ;
        share * s_a__tmp_80 = acirc->PutCONSGate( _tmp_80 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_80 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_81 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k][j] );
            share * s_a_tmp_82 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+64][j] );
            s_a_outmat[128*i+2*k][j] = acirc->PutADDGate( s_a_tmp_81 , s_a_tmp_82 );
            share * s_a_tmp_83 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k][j] );
            share * s_a_tmp_84 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+64][j] );
            s_a_outmat[128*i+2*k+64][j] = acirc->PutADDGate( s_a_tmp_83 , s_a_tmp_84 );
        }
    }
    for (uint64_t k = 0; k < 32; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_85 = 1 ;
        share * s_a__tmp_85 = acirc->PutCONSGate( _tmp_85 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_85 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_86 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_87 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+64+1][j] );
            s_a_outmat[128*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_86 , s_a_tmp_87 );
            share * s_a_tmp_88 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_89 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+64+1][j] );
            s_a_outmat[128*i+2*k+64+1][j] = acirc->PutADDGate( s_a_tmp_88 , s_a_tmp_89 );
        }
    }
}
for (uint64_t i = 0; i < 128; i++)
{
    for (uint64_t k = 0; k < 63; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_90 = 1 ;
        share * s_a__tmp_90 = acirc->PutCONSGate( _tmp_90 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_90 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_91 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_92 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+2][j] );
            s_a_outmat[128*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_91 , s_a_tmp_92 );
            share * s_a_tmp_93 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_94 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+2][j] );
            s_a_outmat[128*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_93 , s_a_tmp_94 );
        }
    }
}
for (uint64_t i = 0; i < 64; i++)
{
    for (uint64_t k = 0; k < 64; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_95 = 1 ;
        share * s_a__tmp_95 = acirc->PutCONSGate( _tmp_95 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_95 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_96 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k][j] );
            share * s_a_tmp_97 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+128][j] );
            s_a_outmat[256*i+2*k][j] = acirc->PutADDGate( s_a_tmp_96 , s_a_tmp_97 );
            share * s_a_tmp_98 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k][j] );
            share * s_a_tmp_99 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+128][j] );
            s_a_outmat[256*i+2*k+128][j] = acirc->PutADDGate( s_a_tmp_98 , s_a_tmp_99 );
        }
    }
    for (uint64_t k = 0; k < 64; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_100 = 1 ;
        share * s_a__tmp_100 = acirc->PutCONSGate( _tmp_100 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_100 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_101 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_102 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+128+1][j] );
            s_a_outmat[256*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_101 , s_a_tmp_102 );
            share * s_a_tmp_103 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_104 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+128+1][j] );
            s_a_outmat[256*i+2*k+128+1][j] = acirc->PutADDGate( s_a_tmp_103 , s_a_tmp_104 );
        }
    }
}
for (uint64_t i = 0; i < 64; i++)
{
    for (uint64_t k = 0; k < 127; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_105 = 1 ;
        share * s_a__tmp_105 = acirc->PutCONSGate( _tmp_105 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_105 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_106 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_107 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+2][j] );
            s_a_outmat[256*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_106 , s_a_tmp_107 );
            share * s_a_tmp_108 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_109 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+2][j] );
            s_a_outmat[256*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_108 , s_a_tmp_109 );
        }
    }
}
for (uint64_t i = 0; i < 32; i++)
{
    for (uint64_t k = 0; k < 128; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_110 = 1 ;
        share * s_a__tmp_110 = acirc->PutCONSGate( _tmp_110 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_110 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_111 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k][j] );
            share * s_a_tmp_112 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+256][j] );
            s_a_outmat[512*i+2*k][j] = acirc->PutADDGate( s_a_tmp_111 , s_a_tmp_112 );
            share * s_a_tmp_113 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k][j] );
            share * s_a_tmp_114 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+256][j] );
            s_a_outmat[512*i+2*k+256][j] = acirc->PutADDGate( s_a_tmp_113 , s_a_tmp_114 );
        }
    }
    for (uint64_t k = 0; k < 128; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_115 = 1 ;
        share * s_a__tmp_115 = acirc->PutCONSGate( _tmp_115 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_115 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_116 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_117 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+256+1][j] );
            s_a_outmat[512*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_116 , s_a_tmp_117 );
            share * s_a_tmp_118 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_119 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+256+1][j] );
            s_a_outmat[512*i+2*k+256+1][j] = acirc->PutADDGate( s_a_tmp_118 , s_a_tmp_119 );
        }
    }
}
for (uint64_t i = 0; i < 32; i++)
{
    for (uint64_t k = 0; k < 255; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_120 = 1 ;
        share * s_a__tmp_120 = acirc->PutCONSGate( _tmp_120 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_120 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_121 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_122 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+2][j] );
            s_a_outmat[512*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_121 , s_a_tmp_122 );
            share * s_a_tmp_123 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_124 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+2][j] );
            s_a_outmat[512*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_123 , s_a_tmp_124 );
        }
    }
}
for (uint64_t i = 0; i < 16; i++)
{
    for (uint64_t k = 0; k < 256; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_125 = 1 ;
        share * s_a__tmp_125 = acirc->PutCONSGate( _tmp_125 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_125 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_126 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k][j] );
            share * s_a_tmp_127 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+512][j] );
            s_a_outmat[1024*i+2*k][j] = acirc->PutADDGate( s_a_tmp_126 , s_a_tmp_127 );
            share * s_a_tmp_128 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k][j] );
            share * s_a_tmp_129 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+512][j] );
            s_a_outmat[1024*i+2*k+512][j] = acirc->PutADDGate( s_a_tmp_128 , s_a_tmp_129 );
        }
    }
    for (uint64_t k = 0; k < 256; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_130 = 1 ;
        share * s_a__tmp_130 = acirc->PutCONSGate( _tmp_130 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_130 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_131 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_132 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+512+1][j] );
            s_a_outmat[1024*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_131 , s_a_tmp_132 );
            share * s_a_tmp_133 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_134 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+512+1][j] );
            s_a_outmat[1024*i+2*k+512+1][j] = acirc->PutADDGate( s_a_tmp_133 , s_a_tmp_134 );
        }
    }
}
for (uint64_t i = 0; i < 16; i++)
{
    for (uint64_t k = 0; k < 511; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_135 = 1 ;
        share * s_a__tmp_135 = acirc->PutCONSGate( _tmp_135 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_135 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_136 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_137 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+2][j] );
            s_a_outmat[1024*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_136 , s_a_tmp_137 );
            share * s_a_tmp_138 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_139 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+2][j] );
            s_a_outmat[1024*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_138 , s_a_tmp_139 );
        }
    }
}
for (uint64_t i = 0; i < 8; i++)
{
    for (uint64_t k = 0; k < 512; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_140 = 1 ;
        share * s_a__tmp_140 = acirc->PutCONSGate( _tmp_140 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_140 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_141 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k][j] );
            share * s_a_tmp_142 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1024][j] );
            s_a_outmat[2048*i+2*k][j] = acirc->PutADDGate( s_a_tmp_141 , s_a_tmp_142 );
            share * s_a_tmp_143 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k][j] );
            share * s_a_tmp_144 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1024][j] );
            s_a_outmat[2048*i+2*k+1024][j] = acirc->PutADDGate( s_a_tmp_143 , s_a_tmp_144 );
        }
    }
    for (uint64_t k = 0; k < 512; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_145 = 1 ;
        share * s_a__tmp_145 = acirc->PutCONSGate( _tmp_145 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_145 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_146 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_147 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1024+1][j] );
            s_a_outmat[2048*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_146 , s_a_tmp_147 );
            share * s_a_tmp_148 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_149 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1024+1][j] );
            s_a_outmat[2048*i+2*k+1024+1][j] = acirc->PutADDGate( s_a_tmp_148 , s_a_tmp_149 );
        }
    }
}
for (uint64_t i = 0; i < 8; i++)
{
    for (uint64_t k = 0; k < 1023; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_150 = 1 ;
        share * s_a__tmp_150 = acirc->PutCONSGate( _tmp_150 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_150 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_151 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_152 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+2][j] );
            s_a_outmat[2048*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_151 , s_a_tmp_152 );
            share * s_a_tmp_153 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_154 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+2][j] );
            s_a_outmat[2048*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_153 , s_a_tmp_154 );
        }
    }
}
for (uint64_t i = 0; i < 4; i++)
{
    for (uint64_t k = 0; k < 1024; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_155 = 1 ;
        share * s_a__tmp_155 = acirc->PutCONSGate( _tmp_155 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_155 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_156 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k][j] );
            share * s_a_tmp_157 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2048][j] );
            s_a_outmat[4096*i+2*k][j] = acirc->PutADDGate( s_a_tmp_156 , s_a_tmp_157 );
            share * s_a_tmp_158 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k][j] );
            share * s_a_tmp_159 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2048][j] );
            s_a_outmat[4096*i+2*k+2048][j] = acirc->PutADDGate( s_a_tmp_158 , s_a_tmp_159 );
        }
    }
    for (uint64_t k = 0; k < 1024; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_160 = 1 ;
        share * s_a__tmp_160 = acirc->PutCONSGate( _tmp_160 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_160 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_161 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_162 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2048+1][j] );
            s_a_outmat[4096*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_161 , s_a_tmp_162 );
            share * s_a_tmp_163 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_164 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2048+1][j] );
            s_a_outmat[4096*i+2*k+2048+1][j] = acirc->PutADDGate( s_a_tmp_163 , s_a_tmp_164 );
        }
    }
}
for (uint64_t i = 0; i < 4; i++)
{
    for (uint64_t k = 0; k < 2047; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_165 = 1 ;
        share * s_a__tmp_165 = acirc->PutCONSGate( _tmp_165 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_165 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_166 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_167 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2][j] );
            s_a_outmat[4096*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_166 , s_a_tmp_167 );
            share * s_a_tmp_168 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_169 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2][j] );
            s_a_outmat[4096*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_168 , s_a_tmp_169 );
        }
    }
}
for (uint64_t i = 0; i < 2; i++)
{
    for (uint64_t k = 0; k < 2048; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_170 = 1 ;
        share * s_a__tmp_170 = acirc->PutCONSGate( _tmp_170 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_170 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_171 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k][j] );
            share * s_a_tmp_172 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+4096][j] );
            s_a_outmat[8192*i+2*k][j] = acirc->PutADDGate( s_a_tmp_171 , s_a_tmp_172 );
            share * s_a_tmp_173 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k][j] );
            share * s_a_tmp_174 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+4096][j] );
            s_a_outmat[8192*i+2*k+4096][j] = acirc->PutADDGate( s_a_tmp_173 , s_a_tmp_174 );
        }
    }
    for (uint64_t k = 0; k < 2048; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_175 = 1 ;
        share * s_a__tmp_175 = acirc->PutCONSGate( _tmp_175 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_175 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_176 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_177 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+4096+1][j] );
            s_a_outmat[8192*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_176 , s_a_tmp_177 );
            share * s_a_tmp_178 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_179 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+4096+1][j] );
            s_a_outmat[8192*i+2*k+4096+1][j] = acirc->PutADDGate( s_a_tmp_178 , s_a_tmp_179 );
        }
    }
}
for (uint64_t i = 0; i < 2; i++)
{
    for (uint64_t k = 0; k < 4095; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_180 = 1 ;
        share * s_a__tmp_180 = acirc->PutCONSGate( _tmp_180 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_180 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_181 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_182 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+2][j] );
            s_a_outmat[8192*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_181 , s_a_tmp_182 );
            share * s_a_tmp_183 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_184 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+2][j] );
            s_a_outmat[8192*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_183 , s_a_tmp_184 );
        }
    }
}
for (uint64_t i = 1; i < 16344; i++)
{
    for (uint64_t j = 4; j < 14; j++)
    {
        share * s_a_tmp_185 = acirc->PutMULGate( s_a_outmat[i][2] , s_a_outmat[i-1][j] );
        uint64_t _tmp_188 = 1 ;
        share * s_a__tmp_188 = acirc->PutCONSGate( _tmp_188 ,bitlen);
        share * s_a_tmp_187 = acirc->PutSUBGate( s_a__tmp_188 , s_a_outmat[i][2] );
        share * s_a_tmp_186 = acirc->PutMULGate( s_a_tmp_187 , s_a_outmat[i][j] );
        s_a_outmat[i][j] = acirc->PutADDGate( s_a_tmp_185 , s_a_tmp_186 );
    }
}
for (uint64_t i = 0; i < 8192; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_189 = 1 ;
    share * s_a__tmp_189 = acirc->PutCONSGate( _tmp_189 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_189 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_190 = acirc->PutMULGate( s_a_b , s_a_outmat[2*i][j] );
        share * s_a_tmp_191 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2*i+1][j] );
        s_a_outmat[2*i][j] = acirc->PutADDGate( s_a_tmp_190 , s_a_tmp_191 );
        share * s_a_tmp_192 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2*i][j] );
        share * s_a_tmp_193 = acirc->PutMULGate( s_a_b , s_a_outmat[2*i+1][j] );
        s_a_outmat[2*i+1][j] = acirc->PutADDGate( s_a_tmp_192 , s_a_tmp_193 );
    }
}
for (uint64_t i = 0; i < 4096; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_194 = 1 ;
    share * s_a__tmp_194 = acirc->PutCONSGate( _tmp_194 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_194 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_195 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i][j] );
        share * s_a_tmp_196 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i][j] = acirc->PutADDGate( s_a_tmp_195 , s_a_tmp_196 );
        share * s_a_tmp_197 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i][j] );
        share * s_a_tmp_198 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+2][j] = acirc->PutADDGate( s_a_tmp_197 , s_a_tmp_198 );
    }
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_199 = 1 ;
    share * s_a__tmp_199 = acirc->PutCONSGate( _tmp_199 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_199 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_200 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_201 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+3][j] );
        s_a_outmat[4*i+1][j] = acirc->PutADDGate( s_a_tmp_200 , s_a_tmp_201 );
        share * s_a_tmp_202 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_203 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+3][j] );
        s_a_outmat[4*i+3][j] = acirc->PutADDGate( s_a_tmp_202 , s_a_tmp_203 );
    }
}
for (uint64_t i = 0; i < 4096; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_204 = 1 ;
    share * s_a__tmp_204 = acirc->PutCONSGate( _tmp_204 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_204 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_205 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_206 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+2][j] = acirc->PutADDGate( s_a_tmp_205 , s_a_tmp_206 );
        share * s_a_tmp_207 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_208 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+1][j] = acirc->PutADDGate( s_a_tmp_207 , s_a_tmp_208 );
    }
}
for (uint64_t i = 0; i < 2048; i++)
{
    for (uint64_t k = 0; k < 2; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_209 = 1 ;
        share * s_a__tmp_209 = acirc->PutCONSGate( _tmp_209 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_209 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_210 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2*k][j] );
            share * s_a_tmp_211 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+4+2*k][j] );
            s_a_outmat[8*i+2*k][j] = acirc->PutADDGate( s_a_tmp_210 , s_a_tmp_211 );
            share * s_a_tmp_212 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2*k][j] );
            share * s_a_tmp_213 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+4+2*k][j] );
            s_a_outmat[8*i+4+2*k][j] = acirc->PutADDGate( s_a_tmp_212 , s_a_tmp_213 );
        }
    }
    for (uint64_t k = 0; k < 2; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_214 = 1 ;
        share * s_a__tmp_214 = acirc->PutCONSGate( _tmp_214 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_214 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_215 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2*k+1][j] );
            share * s_a_tmp_216 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+4+2*k+1][j] );
            s_a_outmat[8*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_215 , s_a_tmp_216 );
            share * s_a_tmp_217 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2*k+1][j] );
            share * s_a_tmp_218 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+4+2*k+1][j] );
            s_a_outmat[8*i+4+2*k+1][j] = acirc->PutADDGate( s_a_tmp_217 , s_a_tmp_218 );
        }
    }
}
for (uint64_t i = 0; i < 2048; i++)
{
    for (uint64_t k = 0; k < 3; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_219 = 1 ;
        share * s_a__tmp_219 = acirc->PutCONSGate( _tmp_219 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_219 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_220 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+1+2*k][j] );
            share * s_a_tmp_221 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2+2*k][j] );
            s_a_outmat[8*i+2+2*k][j] = acirc->PutADDGate( s_a_tmp_220 , s_a_tmp_221 );
            share * s_a_tmp_222 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+1+2*k][j] );
            share * s_a_tmp_223 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2+2*k][j] );
            s_a_outmat[8*i+1+2*k][j] = acirc->PutADDGate( s_a_tmp_222 , s_a_tmp_223 );
        }
    }
}
for (uint64_t i = 0; i < 1024; i++)
{
    for (uint64_t k = 0; k < 4; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_224 = 1 ;
        share * s_a__tmp_224 = acirc->PutCONSGate( _tmp_224 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_224 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_225 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k][j] );
            share * s_a_tmp_226 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+8][j] );
            s_a_outmat[16*i+2*k][j] = acirc->PutADDGate( s_a_tmp_225 , s_a_tmp_226 );
            share * s_a_tmp_227 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k][j] );
            share * s_a_tmp_228 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+8][j] );
            s_a_outmat[16*i+2*k+8][j] = acirc->PutADDGate( s_a_tmp_227 , s_a_tmp_228 );
        }
    }
    for (uint64_t k = 0; k < 4; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_229 = 1 ;
        share * s_a__tmp_229 = acirc->PutCONSGate( _tmp_229 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_229 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_230 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_231 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+8+1][j] );
            s_a_outmat[16*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_230 , s_a_tmp_231 );
            share * s_a_tmp_232 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_233 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+8+1][j] );
            s_a_outmat[16*i+2*k+8+1][j] = acirc->PutADDGate( s_a_tmp_232 , s_a_tmp_233 );
        }
    }
}
for (uint64_t i = 0; i < 1024; i++)
{
    for (uint64_t k = 0; k < 7; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_234 = 1 ;
        share * s_a__tmp_234 = acirc->PutCONSGate( _tmp_234 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_234 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_235 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_236 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+2][j] );
            s_a_outmat[16*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_235 , s_a_tmp_236 );
            share * s_a_tmp_237 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_238 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+2][j] );
            s_a_outmat[16*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_237 , s_a_tmp_238 );
        }
    }
}
for (uint64_t i = 0; i < 512; i++)
{
    for (uint64_t k = 0; k < 8; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_239 = 1 ;
        share * s_a__tmp_239 = acirc->PutCONSGate( _tmp_239 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_239 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_240 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k][j] );
            share * s_a_tmp_241 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+16][j] );
            s_a_outmat[32*i+2*k][j] = acirc->PutADDGate( s_a_tmp_240 , s_a_tmp_241 );
            share * s_a_tmp_242 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k][j] );
            share * s_a_tmp_243 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+16][j] );
            s_a_outmat[32*i+2*k+16][j] = acirc->PutADDGate( s_a_tmp_242 , s_a_tmp_243 );
        }
    }
    for (uint64_t k = 0; k < 8; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_244 = 1 ;
        share * s_a__tmp_244 = acirc->PutCONSGate( _tmp_244 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_244 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_245 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_246 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+16+1][j] );
            s_a_outmat[32*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_245 , s_a_tmp_246 );
            share * s_a_tmp_247 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_248 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+16+1][j] );
            s_a_outmat[32*i+2*k+16+1][j] = acirc->PutADDGate( s_a_tmp_247 , s_a_tmp_248 );
        }
    }
}
for (uint64_t i = 0; i < 512; i++)
{
    for (uint64_t k = 0; k < 15; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_249 = 1 ;
        share * s_a__tmp_249 = acirc->PutCONSGate( _tmp_249 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_249 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_250 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_251 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+2][j] );
            s_a_outmat[32*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_250 , s_a_tmp_251 );
            share * s_a_tmp_252 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_253 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+2][j] );
            s_a_outmat[32*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_252 , s_a_tmp_253 );
        }
    }
}
for (uint64_t i = 0; i < 256; i++)
{
    for (uint64_t k = 0; k < 16; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_254 = 1 ;
        share * s_a__tmp_254 = acirc->PutCONSGate( _tmp_254 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_254 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_255 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k][j] );
            share * s_a_tmp_256 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+32][j] );
            s_a_outmat[64*i+2*k][j] = acirc->PutADDGate( s_a_tmp_255 , s_a_tmp_256 );
            share * s_a_tmp_257 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k][j] );
            share * s_a_tmp_258 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+32][j] );
            s_a_outmat[64*i+2*k+32][j] = acirc->PutADDGate( s_a_tmp_257 , s_a_tmp_258 );
        }
    }
    for (uint64_t k = 0; k < 16; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_259 = 1 ;
        share * s_a__tmp_259 = acirc->PutCONSGate( _tmp_259 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_259 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_260 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_261 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+32+1][j] );
            s_a_outmat[64*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_260 , s_a_tmp_261 );
            share * s_a_tmp_262 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_263 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+32+1][j] );
            s_a_outmat[64*i+2*k+32+1][j] = acirc->PutADDGate( s_a_tmp_262 , s_a_tmp_263 );
        }
    }
}
for (uint64_t i = 0; i < 256; i++)
{
    for (uint64_t k = 0; k < 31; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_264 = 1 ;
        share * s_a__tmp_264 = acirc->PutCONSGate( _tmp_264 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_264 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_265 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_266 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+2][j] );
            s_a_outmat[64*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_265 , s_a_tmp_266 );
            share * s_a_tmp_267 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_268 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+2][j] );
            s_a_outmat[64*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_267 , s_a_tmp_268 );
        }
    }
}
for (uint64_t i = 0; i < 128; i++)
{
    for (uint64_t k = 0; k < 32; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_269 = 1 ;
        share * s_a__tmp_269 = acirc->PutCONSGate( _tmp_269 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_269 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_270 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k][j] );
            share * s_a_tmp_271 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+64][j] );
            s_a_outmat[128*i+2*k][j] = acirc->PutADDGate( s_a_tmp_270 , s_a_tmp_271 );
            share * s_a_tmp_272 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k][j] );
            share * s_a_tmp_273 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+64][j] );
            s_a_outmat[128*i+2*k+64][j] = acirc->PutADDGate( s_a_tmp_272 , s_a_tmp_273 );
        }
    }
    for (uint64_t k = 0; k < 32; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_274 = 1 ;
        share * s_a__tmp_274 = acirc->PutCONSGate( _tmp_274 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_274 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_275 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_276 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+64+1][j] );
            s_a_outmat[128*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_275 , s_a_tmp_276 );
            share * s_a_tmp_277 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_278 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+64+1][j] );
            s_a_outmat[128*i+2*k+64+1][j] = acirc->PutADDGate( s_a_tmp_277 , s_a_tmp_278 );
        }
    }
}
for (uint64_t i = 0; i < 128; i++)
{
    for (uint64_t k = 0; k < 63; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_279 = 1 ;
        share * s_a__tmp_279 = acirc->PutCONSGate( _tmp_279 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_279 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_280 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_281 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+2][j] );
            s_a_outmat[128*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_280 , s_a_tmp_281 );
            share * s_a_tmp_282 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_283 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+2][j] );
            s_a_outmat[128*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_282 , s_a_tmp_283 );
        }
    }
}
for (uint64_t i = 0; i < 64; i++)
{
    for (uint64_t k = 0; k < 64; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_284 = 1 ;
        share * s_a__tmp_284 = acirc->PutCONSGate( _tmp_284 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_284 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_285 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k][j] );
            share * s_a_tmp_286 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+128][j] );
            s_a_outmat[256*i+2*k][j] = acirc->PutADDGate( s_a_tmp_285 , s_a_tmp_286 );
            share * s_a_tmp_287 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k][j] );
            share * s_a_tmp_288 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+128][j] );
            s_a_outmat[256*i+2*k+128][j] = acirc->PutADDGate( s_a_tmp_287 , s_a_tmp_288 );
        }
    }
    for (uint64_t k = 0; k < 64; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_289 = 1 ;
        share * s_a__tmp_289 = acirc->PutCONSGate( _tmp_289 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_289 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_290 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_291 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+128+1][j] );
            s_a_outmat[256*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_290 , s_a_tmp_291 );
            share * s_a_tmp_292 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_293 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+128+1][j] );
            s_a_outmat[256*i+2*k+128+1][j] = acirc->PutADDGate( s_a_tmp_292 , s_a_tmp_293 );
        }
    }
}
for (uint64_t i = 0; i < 64; i++)
{
    for (uint64_t k = 0; k < 127; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_294 = 1 ;
        share * s_a__tmp_294 = acirc->PutCONSGate( _tmp_294 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_294 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_295 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_296 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+2][j] );
            s_a_outmat[256*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_295 , s_a_tmp_296 );
            share * s_a_tmp_297 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_298 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+2][j] );
            s_a_outmat[256*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_297 , s_a_tmp_298 );
        }
    }
}
for (uint64_t i = 0; i < 32; i++)
{
    for (uint64_t k = 0; k < 128; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_299 = 1 ;
        share * s_a__tmp_299 = acirc->PutCONSGate( _tmp_299 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_299 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_300 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k][j] );
            share * s_a_tmp_301 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+256][j] );
            s_a_outmat[512*i+2*k][j] = acirc->PutADDGate( s_a_tmp_300 , s_a_tmp_301 );
            share * s_a_tmp_302 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k][j] );
            share * s_a_tmp_303 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+256][j] );
            s_a_outmat[512*i+2*k+256][j] = acirc->PutADDGate( s_a_tmp_302 , s_a_tmp_303 );
        }
    }
    for (uint64_t k = 0; k < 128; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_304 = 1 ;
        share * s_a__tmp_304 = acirc->PutCONSGate( _tmp_304 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_304 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_305 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_306 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+256+1][j] );
            s_a_outmat[512*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_305 , s_a_tmp_306 );
            share * s_a_tmp_307 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_308 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+256+1][j] );
            s_a_outmat[512*i+2*k+256+1][j] = acirc->PutADDGate( s_a_tmp_307 , s_a_tmp_308 );
        }
    }
}
for (uint64_t i = 0; i < 32; i++)
{
    for (uint64_t k = 0; k < 255; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_309 = 1 ;
        share * s_a__tmp_309 = acirc->PutCONSGate( _tmp_309 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_309 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_310 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_311 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+2][j] );
            s_a_outmat[512*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_310 , s_a_tmp_311 );
            share * s_a_tmp_312 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_313 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+2][j] );
            s_a_outmat[512*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_312 , s_a_tmp_313 );
        }
    }
}
for (uint64_t i = 0; i < 16; i++)
{
    for (uint64_t k = 0; k < 256; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_314 = 1 ;
        share * s_a__tmp_314 = acirc->PutCONSGate( _tmp_314 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_314 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_315 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k][j] );
            share * s_a_tmp_316 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+512][j] );
            s_a_outmat[1024*i+2*k][j] = acirc->PutADDGate( s_a_tmp_315 , s_a_tmp_316 );
            share * s_a_tmp_317 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k][j] );
            share * s_a_tmp_318 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+512][j] );
            s_a_outmat[1024*i+2*k+512][j] = acirc->PutADDGate( s_a_tmp_317 , s_a_tmp_318 );
        }
    }
    for (uint64_t k = 0; k < 256; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_319 = 1 ;
        share * s_a__tmp_319 = acirc->PutCONSGate( _tmp_319 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_319 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_320 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_321 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+512+1][j] );
            s_a_outmat[1024*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_320 , s_a_tmp_321 );
            share * s_a_tmp_322 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_323 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+512+1][j] );
            s_a_outmat[1024*i+2*k+512+1][j] = acirc->PutADDGate( s_a_tmp_322 , s_a_tmp_323 );
        }
    }
}
for (uint64_t i = 0; i < 16; i++)
{
    for (uint64_t k = 0; k < 511; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_324 = 1 ;
        share * s_a__tmp_324 = acirc->PutCONSGate( _tmp_324 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_324 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_325 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_326 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+2][j] );
            s_a_outmat[1024*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_325 , s_a_tmp_326 );
            share * s_a_tmp_327 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_328 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+2][j] );
            s_a_outmat[1024*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_327 , s_a_tmp_328 );
        }
    }
}
for (uint64_t i = 0; i < 8; i++)
{
    for (uint64_t k = 0; k < 512; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_329 = 1 ;
        share * s_a__tmp_329 = acirc->PutCONSGate( _tmp_329 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_329 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_330 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k][j] );
            share * s_a_tmp_331 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1024][j] );
            s_a_outmat[2048*i+2*k][j] = acirc->PutADDGate( s_a_tmp_330 , s_a_tmp_331 );
            share * s_a_tmp_332 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k][j] );
            share * s_a_tmp_333 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1024][j] );
            s_a_outmat[2048*i+2*k+1024][j] = acirc->PutADDGate( s_a_tmp_332 , s_a_tmp_333 );
        }
    }
    for (uint64_t k = 0; k < 512; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_334 = 1 ;
        share * s_a__tmp_334 = acirc->PutCONSGate( _tmp_334 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_334 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_335 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_336 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1024+1][j] );
            s_a_outmat[2048*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_335 , s_a_tmp_336 );
            share * s_a_tmp_337 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_338 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1024+1][j] );
            s_a_outmat[2048*i+2*k+1024+1][j] = acirc->PutADDGate( s_a_tmp_337 , s_a_tmp_338 );
        }
    }
}
for (uint64_t i = 0; i < 8; i++)
{
    for (uint64_t k = 0; k < 1023; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_339 = 1 ;
        share * s_a__tmp_339 = acirc->PutCONSGate( _tmp_339 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_339 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_340 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_341 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+2][j] );
            s_a_outmat[2048*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_340 , s_a_tmp_341 );
            share * s_a_tmp_342 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_343 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+2][j] );
            s_a_outmat[2048*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_342 , s_a_tmp_343 );
        }
    }
}
for (uint64_t i = 0; i < 4; i++)
{
    for (uint64_t k = 0; k < 1024; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_344 = 1 ;
        share * s_a__tmp_344 = acirc->PutCONSGate( _tmp_344 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_344 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_345 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k][j] );
            share * s_a_tmp_346 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2048][j] );
            s_a_outmat[4096*i+2*k][j] = acirc->PutADDGate( s_a_tmp_345 , s_a_tmp_346 );
            share * s_a_tmp_347 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k][j] );
            share * s_a_tmp_348 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2048][j] );
            s_a_outmat[4096*i+2*k+2048][j] = acirc->PutADDGate( s_a_tmp_347 , s_a_tmp_348 );
        }
    }
    for (uint64_t k = 0; k < 1024; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_349 = 1 ;
        share * s_a__tmp_349 = acirc->PutCONSGate( _tmp_349 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_349 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_350 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_351 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2048+1][j] );
            s_a_outmat[4096*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_350 , s_a_tmp_351 );
            share * s_a_tmp_352 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_353 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2048+1][j] );
            s_a_outmat[4096*i+2*k+2048+1][j] = acirc->PutADDGate( s_a_tmp_352 , s_a_tmp_353 );
        }
    }
}
for (uint64_t i = 0; i < 4; i++)
{
    for (uint64_t k = 0; k < 2047; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_354 = 1 ;
        share * s_a__tmp_354 = acirc->PutCONSGate( _tmp_354 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_354 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_355 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_356 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2][j] );
            s_a_outmat[4096*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_355 , s_a_tmp_356 );
            share * s_a_tmp_357 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_358 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2][j] );
            s_a_outmat[4096*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_357 , s_a_tmp_358 );
        }
    }
}
for (uint64_t i = 0; i < 2; i++)
{
    for (uint64_t k = 0; k < 2048; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_359 = 1 ;
        share * s_a__tmp_359 = acirc->PutCONSGate( _tmp_359 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_359 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_360 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k][j] );
            share * s_a_tmp_361 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+4096][j] );
            s_a_outmat[8192*i+2*k][j] = acirc->PutADDGate( s_a_tmp_360 , s_a_tmp_361 );
            share * s_a_tmp_362 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k][j] );
            share * s_a_tmp_363 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+4096][j] );
            s_a_outmat[8192*i+2*k+4096][j] = acirc->PutADDGate( s_a_tmp_362 , s_a_tmp_363 );
        }
    }
    for (uint64_t k = 0; k < 2048; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_364 = 1 ;
        share * s_a__tmp_364 = acirc->PutCONSGate( _tmp_364 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_364 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_365 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_366 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+4096+1][j] );
            s_a_outmat[8192*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_365 , s_a_tmp_366 );
            share * s_a_tmp_367 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_368 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+4096+1][j] );
            s_a_outmat[8192*i+2*k+4096+1][j] = acirc->PutADDGate( s_a_tmp_367 , s_a_tmp_368 );
        }
    }
}
for (uint64_t i = 0; i < 2; i++)
{
    for (uint64_t k = 0; k < 4095; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_369 = 1 ;
        share * s_a__tmp_369 = acirc->PutCONSGate( _tmp_369 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_369 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_370 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_371 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+2][j] );
            s_a_outmat[8192*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_370 , s_a_tmp_371 );
            share * s_a_tmp_372 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_373 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+2][j] );
            s_a_outmat[8192*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_372 , s_a_tmp_373 );
        }
    }
}
for (uint64_t i = 1; i < 15444; i++)
{
    for (uint64_t j = 14; j < 24; j++)
    {
        share * s_a_tmp_374 = acirc->PutMULGate( s_a_outmat[i][2] , s_a_outmat[i-1][j] );
        uint64_t _tmp_377 = 1 ;
        share * s_a__tmp_377 = acirc->PutCONSGate( _tmp_377 ,bitlen);
        share * s_a_tmp_376 = acirc->PutSUBGate( s_a__tmp_377 , s_a_outmat[i][2] );
        share * s_a_tmp_375 = acirc->PutMULGate( s_a_tmp_376 , s_a_outmat[i][j] );
        s_a_outmat[i][j] = acirc->PutADDGate( s_a_tmp_374 , s_a_tmp_375 );
    }
}
for (uint64_t i = 0; i < 15444; i++)
{
    dots[i] = 0 ;
    s_a_dots[i] = acirc->PutCONSGate( dots[i] ,bitlen);
    for (uint64_t j = 4; j < 14; j++)
    {
        share * s_a_tmp_378 = acirc->PutMULGate( s_a_outmat[i][j] , s_a_outmat[i][j+10] );
        s_a_dots[i] = acirc->PutADDGate( s_a_dots[i] , s_a_tmp_378 );
    }
    s_a_dots[i] = acirc->PutSUBGate( s_a_outmat[i][3] , s_a_dots[i] );
}
for (uint64_t i = 0; i < 15444; i++)
{
    for (uint64_t j = 14; j < 24; j++)
    {
        s_a_temp[j-14] = create_new_share(s_a_outmat[i][j]->get_wires(), acirc );
        share * s_a_tmp_380 = acirc->PutMULGate( s_a_outmat[i][2] , s_a_dots[i] );
        share * s_a_tmp_379 = acirc->PutMULGate( s_a_tmp_380 , s_a_outmat[i][j-10] );
        uint64_t _tmp_383 = 1 ;
        share * s_a__tmp_383 = acirc->PutCONSGate( _tmp_383 ,bitlen);
        share * s_a_tmp_382 = acirc->PutSUBGate( s_a__tmp_383 , s_a_outmat[i][2] );
        share * s_a_tmp_381 = acirc->PutMULGate( s_a_tmp_382 , s_a_outmat[i][j] );
        s_a_outmat[i][j] = acirc->PutADDGate( s_a_tmp_379 , s_a_tmp_381 );
    }
    for (uint64_t j = 4; j < 14; j++)
    {
        share * s_a_tmp_385 = acirc->PutMULGate( s_a_outmat[i][2] , s_a_dots[i] );
        share * s_a_tmp_384 = acirc->PutMULGate( s_a_tmp_385 , s_a_temp[j-4] );
        uint64_t _tmp_388 = 1 ;
        share * s_a__tmp_388 = acirc->PutCONSGate( _tmp_388 ,bitlen);
        share * s_a_tmp_387 = acirc->PutSUBGate( s_a__tmp_388 , s_a_outmat[i][2] );
        share * s_a_tmp_386 = acirc->PutMULGate( s_a_tmp_387 , s_a_outmat[i][j] );
        s_a_outmat[i][j] = acirc->PutADDGate( s_a_tmp_384 , s_a_tmp_386 );
    }
}
uint64_t t;
for (uint64_t i = 941; i < 16384; i++)
{
    t = 16384-i;
    for (uint64_t j = 14; j < 24; j++)
    {
        share * s_a_tmp_390 = acirc->PutMULGate( s_a_outmat[t+1][2] , s_a_outmat[t+1][j] );
        share * s_a_tmp_389 = acirc->PutADDGate( s_a_outmat[t][j] , s_a_tmp_390 );
        uint64_t _tmp_393 = 1 ;
        share * s_a__tmp_393 = acirc->PutCONSGate( _tmp_393 ,bitlen);
        share * s_a_tmp_392 = acirc->PutSUBGate( s_a__tmp_393 , s_a_outmat[t+1][2] );
        share * s_a_tmp_391 = acirc->PutMULGate( s_a_tmp_392 , s_a_outmat[t][j] );
        s_a_outmat[t][j] = acirc->PutADDGate( s_a_tmp_389 , s_a_tmp_391 );
    }
}
for (uint64_t i = 0; i < 8192; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_394 = 1 ;
    share * s_a__tmp_394 = acirc->PutCONSGate( _tmp_394 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_394 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_395 = acirc->PutMULGate( s_a_b , s_a_outmat[2*i][j] );
        share * s_a_tmp_396 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2*i+1][j] );
        s_a_outmat[2*i][j] = acirc->PutADDGate( s_a_tmp_395 , s_a_tmp_396 );
        share * s_a_tmp_397 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2*i][j] );
        share * s_a_tmp_398 = acirc->PutMULGate( s_a_b , s_a_outmat[2*i+1][j] );
        s_a_outmat[2*i+1][j] = acirc->PutADDGate( s_a_tmp_397 , s_a_tmp_398 );
    }
}
for (uint64_t i = 0; i < 4096; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_399 = 1 ;
    share * s_a__tmp_399 = acirc->PutCONSGate( _tmp_399 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_399 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_400 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i][j] );
        share * s_a_tmp_401 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i][j] = acirc->PutADDGate( s_a_tmp_400 , s_a_tmp_401 );
        share * s_a_tmp_402 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i][j] );
        share * s_a_tmp_403 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+2][j] = acirc->PutADDGate( s_a_tmp_402 , s_a_tmp_403 );
    }
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_404 = 1 ;
    share * s_a__tmp_404 = acirc->PutCONSGate( _tmp_404 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_404 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_405 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_406 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+3][j] );
        s_a_outmat[4*i+1][j] = acirc->PutADDGate( s_a_tmp_405 , s_a_tmp_406 );
        share * s_a_tmp_407 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_408 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+3][j] );
        s_a_outmat[4*i+3][j] = acirc->PutADDGate( s_a_tmp_407 , s_a_tmp_408 );
    }
}
for (uint64_t i = 0; i < 4096; i++)
{
    s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
    uint64_t _tmp_409 = 1 ;
    share * s_a__tmp_409 = acirc->PutCONSGate( _tmp_409 ,bitlen);
    s_a_b1 = acirc->PutSUBGate( s_a__tmp_409 , s_a_b );
    boolidx = boolidx+1;
    for (uint64_t j = 0; j < 24; j++)
    {
        share * s_a_tmp_410 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_411 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+2][j] = acirc->PutADDGate( s_a_tmp_410 , s_a_tmp_411 );
        share * s_a_tmp_412 = acirc->PutMULGate( s_a_b , s_a_outmat[4*i+1][j] );
        share * s_a_tmp_413 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4*i+2][j] );
        s_a_outmat[4*i+1][j] = acirc->PutADDGate( s_a_tmp_412 , s_a_tmp_413 );
    }
}
for (uint64_t i = 0; i < 2048; i++)
{
    for (uint64_t k = 0; k < 2; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_414 = 1 ;
        share * s_a__tmp_414 = acirc->PutCONSGate( _tmp_414 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_414 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_415 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2*k][j] );
            share * s_a_tmp_416 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+4+2*k][j] );
            s_a_outmat[8*i+2*k][j] = acirc->PutADDGate( s_a_tmp_415 , s_a_tmp_416 );
            share * s_a_tmp_417 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2*k][j] );
            share * s_a_tmp_418 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+4+2*k][j] );
            s_a_outmat[8*i+4+2*k][j] = acirc->PutADDGate( s_a_tmp_417 , s_a_tmp_418 );
        }
    }
    for (uint64_t k = 0; k < 2; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_419 = 1 ;
        share * s_a__tmp_419 = acirc->PutCONSGate( _tmp_419 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_419 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_420 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2*k+1][j] );
            share * s_a_tmp_421 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+4+2*k+1][j] );
            s_a_outmat[8*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_420 , s_a_tmp_421 );
            share * s_a_tmp_422 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2*k+1][j] );
            share * s_a_tmp_423 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+4+2*k+1][j] );
            s_a_outmat[8*i+4+2*k+1][j] = acirc->PutADDGate( s_a_tmp_422 , s_a_tmp_423 );
        }
    }
}
for (uint64_t i = 0; i < 2048; i++)
{
    for (uint64_t k = 0; k < 3; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_424 = 1 ;
        share * s_a__tmp_424 = acirc->PutCONSGate( _tmp_424 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_424 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_425 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+1+2*k][j] );
            share * s_a_tmp_426 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+2+2*k][j] );
            s_a_outmat[8*i+2+2*k][j] = acirc->PutADDGate( s_a_tmp_425 , s_a_tmp_426 );
            share * s_a_tmp_427 = acirc->PutMULGate( s_a_b , s_a_outmat[8*i+1+2*k][j] );
            share * s_a_tmp_428 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8*i+2+2*k][j] );
            s_a_outmat[8*i+1+2*k][j] = acirc->PutADDGate( s_a_tmp_427 , s_a_tmp_428 );
        }
    }
}
for (uint64_t i = 0; i < 1024; i++)
{
    for (uint64_t k = 0; k < 4; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_429 = 1 ;
        share * s_a__tmp_429 = acirc->PutCONSGate( _tmp_429 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_429 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_430 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k][j] );
            share * s_a_tmp_431 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+8][j] );
            s_a_outmat[16*i+2*k][j] = acirc->PutADDGate( s_a_tmp_430 , s_a_tmp_431 );
            share * s_a_tmp_432 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k][j] );
            share * s_a_tmp_433 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+8][j] );
            s_a_outmat[16*i+2*k+8][j] = acirc->PutADDGate( s_a_tmp_432 , s_a_tmp_433 );
        }
    }
    for (uint64_t k = 0; k < 4; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_434 = 1 ;
        share * s_a__tmp_434 = acirc->PutCONSGate( _tmp_434 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_434 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_435 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_436 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+8+1][j] );
            s_a_outmat[16*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_435 , s_a_tmp_436 );
            share * s_a_tmp_437 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_438 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+8+1][j] );
            s_a_outmat[16*i+2*k+8+1][j] = acirc->PutADDGate( s_a_tmp_437 , s_a_tmp_438 );
        }
    }
}
for (uint64_t i = 0; i < 1024; i++)
{
    for (uint64_t k = 0; k < 7; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_439 = 1 ;
        share * s_a__tmp_439 = acirc->PutCONSGate( _tmp_439 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_439 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_440 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_441 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+2][j] );
            s_a_outmat[16*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_440 , s_a_tmp_441 );
            share * s_a_tmp_442 = acirc->PutMULGate( s_a_b1 , s_a_outmat[16*i+2*k+1][j] );
            share * s_a_tmp_443 = acirc->PutMULGate( s_a_b , s_a_outmat[16*i+2*k+2][j] );
            s_a_outmat[16*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_442 , s_a_tmp_443 );
        }
    }
}
for (uint64_t i = 0; i < 512; i++)
{
    for (uint64_t k = 0; k < 8; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_444 = 1 ;
        share * s_a__tmp_444 = acirc->PutCONSGate( _tmp_444 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_444 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_445 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k][j] );
            share * s_a_tmp_446 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+16][j] );
            s_a_outmat[32*i+2*k][j] = acirc->PutADDGate( s_a_tmp_445 , s_a_tmp_446 );
            share * s_a_tmp_447 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k][j] );
            share * s_a_tmp_448 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+16][j] );
            s_a_outmat[32*i+2*k+16][j] = acirc->PutADDGate( s_a_tmp_447 , s_a_tmp_448 );
        }
    }
    for (uint64_t k = 0; k < 8; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_449 = 1 ;
        share * s_a__tmp_449 = acirc->PutCONSGate( _tmp_449 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_449 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_450 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_451 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+16+1][j] );
            s_a_outmat[32*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_450 , s_a_tmp_451 );
            share * s_a_tmp_452 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_453 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+16+1][j] );
            s_a_outmat[32*i+2*k+16+1][j] = acirc->PutADDGate( s_a_tmp_452 , s_a_tmp_453 );
        }
    }
}
for (uint64_t i = 0; i < 512; i++)
{
    for (uint64_t k = 0; k < 15; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_454 = 1 ;
        share * s_a__tmp_454 = acirc->PutCONSGate( _tmp_454 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_454 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_455 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_456 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+2][j] );
            s_a_outmat[32*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_455 , s_a_tmp_456 );
            share * s_a_tmp_457 = acirc->PutMULGate( s_a_b1 , s_a_outmat[32*i+2*k+1][j] );
            share * s_a_tmp_458 = acirc->PutMULGate( s_a_b , s_a_outmat[32*i+2*k+2][j] );
            s_a_outmat[32*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_457 , s_a_tmp_458 );
        }
    }
}
for (uint64_t i = 0; i < 256; i++)
{
    for (uint64_t k = 0; k < 16; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_459 = 1 ;
        share * s_a__tmp_459 = acirc->PutCONSGate( _tmp_459 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_459 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_460 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k][j] );
            share * s_a_tmp_461 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+32][j] );
            s_a_outmat[64*i+2*k][j] = acirc->PutADDGate( s_a_tmp_460 , s_a_tmp_461 );
            share * s_a_tmp_462 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k][j] );
            share * s_a_tmp_463 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+32][j] );
            s_a_outmat[64*i+2*k+32][j] = acirc->PutADDGate( s_a_tmp_462 , s_a_tmp_463 );
        }
    }
    for (uint64_t k = 0; k < 16; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_464 = 1 ;
        share * s_a__tmp_464 = acirc->PutCONSGate( _tmp_464 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_464 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_465 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_466 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+32+1][j] );
            s_a_outmat[64*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_465 , s_a_tmp_466 );
            share * s_a_tmp_467 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_468 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+32+1][j] );
            s_a_outmat[64*i+2*k+32+1][j] = acirc->PutADDGate( s_a_tmp_467 , s_a_tmp_468 );
        }
    }
}
for (uint64_t i = 0; i < 256; i++)
{
    for (uint64_t k = 0; k < 31; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_469 = 1 ;
        share * s_a__tmp_469 = acirc->PutCONSGate( _tmp_469 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_469 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_470 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_471 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+2][j] );
            s_a_outmat[64*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_470 , s_a_tmp_471 );
            share * s_a_tmp_472 = acirc->PutMULGate( s_a_b1 , s_a_outmat[64*i+2*k+1][j] );
            share * s_a_tmp_473 = acirc->PutMULGate( s_a_b , s_a_outmat[64*i+2*k+2][j] );
            s_a_outmat[64*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_472 , s_a_tmp_473 );
        }
    }
}
for (uint64_t i = 0; i < 128; i++)
{
    for (uint64_t k = 0; k < 32; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_474 = 1 ;
        share * s_a__tmp_474 = acirc->PutCONSGate( _tmp_474 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_474 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_475 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k][j] );
            share * s_a_tmp_476 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+64][j] );
            s_a_outmat[128*i+2*k][j] = acirc->PutADDGate( s_a_tmp_475 , s_a_tmp_476 );
            share * s_a_tmp_477 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k][j] );
            share * s_a_tmp_478 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+64][j] );
            s_a_outmat[128*i+2*k+64][j] = acirc->PutADDGate( s_a_tmp_477 , s_a_tmp_478 );
        }
    }
    for (uint64_t k = 0; k < 32; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_479 = 1 ;
        share * s_a__tmp_479 = acirc->PutCONSGate( _tmp_479 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_479 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_480 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_481 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+64+1][j] );
            s_a_outmat[128*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_480 , s_a_tmp_481 );
            share * s_a_tmp_482 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_483 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+64+1][j] );
            s_a_outmat[128*i+2*k+64+1][j] = acirc->PutADDGate( s_a_tmp_482 , s_a_tmp_483 );
        }
    }
}
for (uint64_t i = 0; i < 128; i++)
{
    for (uint64_t k = 0; k < 63; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_484 = 1 ;
        share * s_a__tmp_484 = acirc->PutCONSGate( _tmp_484 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_484 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_485 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_486 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+2][j] );
            s_a_outmat[128*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_485 , s_a_tmp_486 );
            share * s_a_tmp_487 = acirc->PutMULGate( s_a_b1 , s_a_outmat[128*i+2*k+1][j] );
            share * s_a_tmp_488 = acirc->PutMULGate( s_a_b , s_a_outmat[128*i+2*k+2][j] );
            s_a_outmat[128*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_487 , s_a_tmp_488 );
        }
    }
}
for (uint64_t i = 0; i < 64; i++)
{
    for (uint64_t k = 0; k < 64; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_489 = 1 ;
        share * s_a__tmp_489 = acirc->PutCONSGate( _tmp_489 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_489 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_490 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k][j] );
            share * s_a_tmp_491 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+128][j] );
            s_a_outmat[256*i+2*k][j] = acirc->PutADDGate( s_a_tmp_490 , s_a_tmp_491 );
            share * s_a_tmp_492 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k][j] );
            share * s_a_tmp_493 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+128][j] );
            s_a_outmat[256*i+2*k+128][j] = acirc->PutADDGate( s_a_tmp_492 , s_a_tmp_493 );
        }
    }
    for (uint64_t k = 0; k < 64; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_494 = 1 ;
        share * s_a__tmp_494 = acirc->PutCONSGate( _tmp_494 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_494 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_495 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_496 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+128+1][j] );
            s_a_outmat[256*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_495 , s_a_tmp_496 );
            share * s_a_tmp_497 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_498 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+128+1][j] );
            s_a_outmat[256*i+2*k+128+1][j] = acirc->PutADDGate( s_a_tmp_497 , s_a_tmp_498 );
        }
    }
}
for (uint64_t i = 0; i < 64; i++)
{
    for (uint64_t k = 0; k < 127; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_499 = 1 ;
        share * s_a__tmp_499 = acirc->PutCONSGate( _tmp_499 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_499 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_500 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_501 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+2][j] );
            s_a_outmat[256*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_500 , s_a_tmp_501 );
            share * s_a_tmp_502 = acirc->PutMULGate( s_a_b1 , s_a_outmat[256*i+2*k+1][j] );
            share * s_a_tmp_503 = acirc->PutMULGate( s_a_b , s_a_outmat[256*i+2*k+2][j] );
            s_a_outmat[256*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_502 , s_a_tmp_503 );
        }
    }
}
for (uint64_t i = 0; i < 32; i++)
{
    for (uint64_t k = 0; k < 128; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_504 = 1 ;
        share * s_a__tmp_504 = acirc->PutCONSGate( _tmp_504 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_504 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_505 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k][j] );
            share * s_a_tmp_506 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+256][j] );
            s_a_outmat[512*i+2*k][j] = acirc->PutADDGate( s_a_tmp_505 , s_a_tmp_506 );
            share * s_a_tmp_507 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k][j] );
            share * s_a_tmp_508 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+256][j] );
            s_a_outmat[512*i+2*k+256][j] = acirc->PutADDGate( s_a_tmp_507 , s_a_tmp_508 );
        }
    }
    for (uint64_t k = 0; k < 128; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_509 = 1 ;
        share * s_a__tmp_509 = acirc->PutCONSGate( _tmp_509 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_509 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_510 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_511 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+256+1][j] );
            s_a_outmat[512*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_510 , s_a_tmp_511 );
            share * s_a_tmp_512 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_513 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+256+1][j] );
            s_a_outmat[512*i+2*k+256+1][j] = acirc->PutADDGate( s_a_tmp_512 , s_a_tmp_513 );
        }
    }
}
for (uint64_t i = 0; i < 32; i++)
{
    for (uint64_t k = 0; k < 255; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_514 = 1 ;
        share * s_a__tmp_514 = acirc->PutCONSGate( _tmp_514 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_514 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_515 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_516 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+2][j] );
            s_a_outmat[512*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_515 , s_a_tmp_516 );
            share * s_a_tmp_517 = acirc->PutMULGate( s_a_b1 , s_a_outmat[512*i+2*k+1][j] );
            share * s_a_tmp_518 = acirc->PutMULGate( s_a_b , s_a_outmat[512*i+2*k+2][j] );
            s_a_outmat[512*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_517 , s_a_tmp_518 );
        }
    }
}
for (uint64_t i = 0; i < 16; i++)
{
    for (uint64_t k = 0; k < 256; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_519 = 1 ;
        share * s_a__tmp_519 = acirc->PutCONSGate( _tmp_519 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_519 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_520 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k][j] );
            share * s_a_tmp_521 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+512][j] );
            s_a_outmat[1024*i+2*k][j] = acirc->PutADDGate( s_a_tmp_520 , s_a_tmp_521 );
            share * s_a_tmp_522 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k][j] );
            share * s_a_tmp_523 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+512][j] );
            s_a_outmat[1024*i+2*k+512][j] = acirc->PutADDGate( s_a_tmp_522 , s_a_tmp_523 );
        }
    }
    for (uint64_t k = 0; k < 256; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_524 = 1 ;
        share * s_a__tmp_524 = acirc->PutCONSGate( _tmp_524 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_524 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_525 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_526 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+512+1][j] );
            s_a_outmat[1024*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_525 , s_a_tmp_526 );
            share * s_a_tmp_527 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_528 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+512+1][j] );
            s_a_outmat[1024*i+2*k+512+1][j] = acirc->PutADDGate( s_a_tmp_527 , s_a_tmp_528 );
        }
    }
}
for (uint64_t i = 0; i < 16; i++)
{
    for (uint64_t k = 0; k < 511; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_529 = 1 ;
        share * s_a__tmp_529 = acirc->PutCONSGate( _tmp_529 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_529 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_530 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_531 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+2][j] );
            s_a_outmat[1024*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_530 , s_a_tmp_531 );
            share * s_a_tmp_532 = acirc->PutMULGate( s_a_b1 , s_a_outmat[1024*i+2*k+1][j] );
            share * s_a_tmp_533 = acirc->PutMULGate( s_a_b , s_a_outmat[1024*i+2*k+2][j] );
            s_a_outmat[1024*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_532 , s_a_tmp_533 );
        }
    }
}
for (uint64_t i = 0; i < 8; i++)
{
    for (uint64_t k = 0; k < 512; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_534 = 1 ;
        share * s_a__tmp_534 = acirc->PutCONSGate( _tmp_534 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_534 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_535 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k][j] );
            share * s_a_tmp_536 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1024][j] );
            s_a_outmat[2048*i+2*k][j] = acirc->PutADDGate( s_a_tmp_535 , s_a_tmp_536 );
            share * s_a_tmp_537 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k][j] );
            share * s_a_tmp_538 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1024][j] );
            s_a_outmat[2048*i+2*k+1024][j] = acirc->PutADDGate( s_a_tmp_537 , s_a_tmp_538 );
        }
    }
    for (uint64_t k = 0; k < 512; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_539 = 1 ;
        share * s_a__tmp_539 = acirc->PutCONSGate( _tmp_539 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_539 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_540 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_541 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1024+1][j] );
            s_a_outmat[2048*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_540 , s_a_tmp_541 );
            share * s_a_tmp_542 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_543 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1024+1][j] );
            s_a_outmat[2048*i+2*k+1024+1][j] = acirc->PutADDGate( s_a_tmp_542 , s_a_tmp_543 );
        }
    }
}
for (uint64_t i = 0; i < 8; i++)
{
    for (uint64_t k = 0; k < 1023; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_544 = 1 ;
        share * s_a__tmp_544 = acirc->PutCONSGate( _tmp_544 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_544 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_545 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_546 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+2][j] );
            s_a_outmat[2048*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_545 , s_a_tmp_546 );
            share * s_a_tmp_547 = acirc->PutMULGate( s_a_b1 , s_a_outmat[2048*i+2*k+1][j] );
            share * s_a_tmp_548 = acirc->PutMULGate( s_a_b , s_a_outmat[2048*i+2*k+2][j] );
            s_a_outmat[2048*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_547 , s_a_tmp_548 );
        }
    }
}
for (uint64_t i = 0; i < 4; i++)
{
    for (uint64_t k = 0; k < 1024; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_549 = 1 ;
        share * s_a__tmp_549 = acirc->PutCONSGate( _tmp_549 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_549 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_550 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k][j] );
            share * s_a_tmp_551 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2048][j] );
            s_a_outmat[4096*i+2*k][j] = acirc->PutADDGate( s_a_tmp_550 , s_a_tmp_551 );
            share * s_a_tmp_552 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k][j] );
            share * s_a_tmp_553 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2048][j] );
            s_a_outmat[4096*i+2*k+2048][j] = acirc->PutADDGate( s_a_tmp_552 , s_a_tmp_553 );
        }
    }
    for (uint64_t k = 0; k < 1024; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_554 = 1 ;
        share * s_a__tmp_554 = acirc->PutCONSGate( _tmp_554 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_554 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_555 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_556 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2048+1][j] );
            s_a_outmat[4096*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_555 , s_a_tmp_556 );
            share * s_a_tmp_557 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_558 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2048+1][j] );
            s_a_outmat[4096*i+2*k+2048+1][j] = acirc->PutADDGate( s_a_tmp_557 , s_a_tmp_558 );
        }
    }
}
for (uint64_t i = 0; i < 4; i++)
{
    for (uint64_t k = 0; k < 2047; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_559 = 1 ;
        share * s_a__tmp_559 = acirc->PutCONSGate( _tmp_559 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_559 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_560 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_561 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+2][j] );
            s_a_outmat[4096*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_560 , s_a_tmp_561 );
            share * s_a_tmp_562 = acirc->PutMULGate( s_a_b1 , s_a_outmat[4096*i+2*k+1][j] );
            share * s_a_tmp_563 = acirc->PutMULGate( s_a_b , s_a_outmat[4096*i+2*k+2][j] );
            s_a_outmat[4096*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_562 , s_a_tmp_563 );
        }
    }
}
for (uint64_t i = 0; i < 2; i++)
{
    for (uint64_t k = 0; k < 2048; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_564 = 1 ;
        share * s_a__tmp_564 = acirc->PutCONSGate( _tmp_564 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_564 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_565 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k][j] );
            share * s_a_tmp_566 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+4096][j] );
            s_a_outmat[8192*i+2*k][j] = acirc->PutADDGate( s_a_tmp_565 , s_a_tmp_566 );
            share * s_a_tmp_567 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k][j] );
            share * s_a_tmp_568 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+4096][j] );
            s_a_outmat[8192*i+2*k+4096][j] = acirc->PutADDGate( s_a_tmp_567 , s_a_tmp_568 );
        }
    }
    for (uint64_t k = 0; k < 2048; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_569 = 1 ;
        share * s_a__tmp_569 = acirc->PutCONSGate( _tmp_569 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_569 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_570 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_571 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+4096+1][j] );
            s_a_outmat[8192*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_570 , s_a_tmp_571 );
            share * s_a_tmp_572 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_573 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+4096+1][j] );
            s_a_outmat[8192*i+2*k+4096+1][j] = acirc->PutADDGate( s_a_tmp_572 , s_a_tmp_573 );
        }
    }
}
for (uint64_t i = 0; i < 2; i++)
{
    for (uint64_t k = 0; k < 4095; k++)
    {
        s_a_b = create_new_share(s_a_boolarr[boolidx]->get_wires(), acirc );
        uint64_t _tmp_574 = 1 ;
        share * s_a__tmp_574 = acirc->PutCONSGate( _tmp_574 ,bitlen);
        s_a_b1 = acirc->PutSUBGate( s_a__tmp_574 , s_a_b );
        boolidx = boolidx+1;
        for (uint64_t j = 0; j < 24; j++)
        {
            share * s_a_tmp_575 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_576 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+2][j] );
            s_a_outmat[8192*i+2*k+1][j] = acirc->PutADDGate( s_a_tmp_575 , s_a_tmp_576 );
            share * s_a_tmp_577 = acirc->PutMULGate( s_a_b1 , s_a_outmat[8192*i+2*k+1][j] );
            share * s_a_tmp_578 = acirc->PutMULGate( s_a_b , s_a_outmat[8192*i+2*k+2][j] );
            s_a_outmat[8192*i+2*k+2][j] = acirc->PutADDGate( s_a_tmp_577 , s_a_tmp_578 );
        }
    }
}
for (uint64_t i = 41; i < 16384; i++)
{
    t = 16384-i;
    for (uint64_t j = 4; j < 14; j++)
    {
        share * s_a_tmp_580 = acirc->PutMULGate( s_a_outmat[t+1][2] , s_a_outmat[t+1][j] );
        share * s_a_tmp_579 = acirc->PutADDGate( s_a_outmat[t][j] , s_a_tmp_580 );
        uint64_t _tmp_583 = 1 ;
        share * s_a__tmp_583 = acirc->PutCONSGate( _tmp_583 ,bitlen);
        share * s_a_tmp_582 = acirc->PutSUBGate( s_a__tmp_583 , s_a_outmat[t+1][2] );
        share * s_a_tmp_581 = acirc->PutMULGate( s_a_tmp_582 , s_a_outmat[t][j] );
        s_a_outmat[t][j] = acirc->PutADDGate( s_a_tmp_579 , s_a_tmp_581 );
    }
}
uint64_t _tmp_585 = 1 ;
share * s_a__tmp_585 = acirc->PutCONSGate( _tmp_585 ,bitlen);
share * s_a_tmp_584 = acirc->PutOUTGate( s_a__tmp_585 , ALL);
party->ExecCircuit();
uint64_t _output586 = s_a_tmp_584->get_clear_value<uint64_t>();
