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
auto Routmat = make_vector<uint64_t>(16384, 24);
auto s_a_Routmat = make_vector<share*>(16384, 24);
auto IRoutmat = make_vector<uint64_t>(16384, 24);
auto s_a_IRoutmat = make_vector<share*>(16384, 24);
uint64_t b;
share *s_a_b;
uint64_t b1;
share *s_a_b1;
boolidx = 0;
if(role == SERVER){
ofstream fout("IRoutmat", std::ofstream::out | std::ofstream::app);
for(int i = 0; i < 16384; i++) {
	for(int j = 0; j < 24; j++) {
		fout << i << " " << j << " " <<(IRoutmat[i][j] = rand()) << endl;
	}
}
fout.close();
}
for (uint64_t i = 0; i < 16384; i++)
{
    for (uint64_t j = 0; j < 24; j++)
    {
        if (role == SERVER) {
            Routmat[i][j] = IRoutmat[i][j] ;
            s_a_Routmat[i][j] = acirc->PutINGate( Routmat[i][j] ,bitlen,SERVER);
        } else {
            s_a_Routmat[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
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
for (uint64_t i = 0; i < 16384; i++)
{
    for (uint64_t j = 0; j < 24; j++)
    {
        s_a_outmat[i][j] = acirc->PutADDGate( s_a_outmat[i][j] , s_a_Routmat[i][j] );
    }
}
uint64_t _tmp_190 = 1 ;
share * s_a__tmp_190 = acirc->PutCONSGate( _tmp_190 ,bitlen);
share * s_a_tmp_189 = acirc->PutOUTGate( s_a__tmp_190 , ALL);
auto s_a_outmat_o = make_vector<share*>(16384, 24);
for(int i = 0; i < 16384; i++) {
	for(int j = 0; j < 24; j++) {
		s_a_outmat_o[i][j] = acirc->PutOUTGate(s_a_outmat[i][j], CLIENT);
	}
}
party->ExecCircuit();
if(role == CLIENT) {
	ofstream fout("outmat", std::ofstream::out | std::ofstream::app);
	for(int i = 0; i < 16384; i++) {
		for(int j = 0; j < 24; j++) {
			fout << i << " " << j << " " << (s_a_outmat_o[i][j]->get_clear_value<uint64_t>()) << endl;
		}
	}
	fout.close();
}
uint64_t _output191 = s_a_tmp_189->get_clear_value<uint64_t>();

