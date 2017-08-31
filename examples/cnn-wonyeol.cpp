ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
uint32_t maxind;
share *s_a_maxind;
uint32_t N;
share *s_a_N;
uint32_t cnt;
share *s_a_cnt;
uint32_t ii;
share *s_a_ii;
uint32_t jj;
share *s_a_jj;
uint32_t kk;
share *s_a_kk;
uint32_t ll;
share *s_a_ll;
uint32_t jjover;
share *s_a_jjover;
uint32_t kkover;
share *s_a_kkover;
uint32_t llover;
share *s_a_llover;
uint32_t mtmp;
share *s_a_mtmp;
uint32_t htmp;
share *s_a_htmp;
uint32_t wtmp;
share *s_a_wtmp;
uint32_t maxval;
share *s_a_maxval;
uint32_t tmp;
share *s_a_tmp;
uint32_t tmp0;
share *s_a_tmp0;
uint32_t tmp1;
share *s_a_tmp1;
auto Wc1 = make_vector<uint32_t>(5, 5, 1, 32);
auto s_a_Wc1 = make_vector<share*>(5, 5, 1, 32);
auto Wc2 = make_vector<uint32_t>(5, 5, 32, 64);
auto s_a_Wc2 = make_vector<share*>(5, 5, 32, 64);
auto Wf1 = make_vector<uint32_t>(1, 1, 3136, 1024);
auto s_a_Wf1 = make_vector<share*>(1, 1, 3136, 1024);
auto Wf2 = make_vector<uint32_t>(1, 1, 1024, 10);
auto s_a_Wf2 = make_vector<share*>(1, 1, 1024, 10);
auto bc1 = make_vector<uint32_t>(1, 1, 1, 32);
auto s_a_bc1 = make_vector<share*>(1, 1, 1, 32);
auto bc2 = make_vector<uint32_t>(1, 1, 1, 64);
auto s_a_bc2 = make_vector<share*>(1, 1, 1, 64);
auto bf1 = make_vector<uint32_t>(1, 1, 1, 1024);
auto s_a_bf1 = make_vector<share*>(1, 1, 1, 1024);
auto bf2 = make_vector<uint32_t>(1, 1, 1, 10);
auto s_a_bf2 = make_vector<share*>(1, 1, 1, 10);
auto x = make_vector<uint32_t>(1, 1, 1, 784);
auto s_a_x = make_vector<share*>(1, 1, 1, 784);
auto ximg = make_vector<uint32_t>(1, 28, 28, 1);
auto s_a_ximg = make_vector<share*>(1, 28, 28, 1);
auto hc11 = make_vector<uint32_t>(1, 28, 28, 32);
auto s_a_hc11 = make_vector<share*>(1, 28, 28, 32);
auto hc12 = make_vector<uint32_t>(1, 28, 28, 32);
auto s_a_hc12 = make_vector<share*>(1, 28, 28, 32);
auto hc13 = make_vector<uint32_t>(1, 28, 28, 32);
auto s_a_hc13 = make_vector<share*>(1, 28, 28, 32);
auto hp1 = make_vector<uint32_t>(1, 14, 14, 32);
auto s_a_hp1 = make_vector<share*>(1, 14, 14, 32);
auto hc21 = make_vector<uint32_t>(1, 14, 14, 64);
auto s_a_hc21 = make_vector<share*>(1, 14, 14, 64);
auto hc22 = make_vector<uint32_t>(1, 14, 14, 64);
auto s_a_hc22 = make_vector<share*>(1, 14, 14, 64);
auto hc23 = make_vector<uint32_t>(1, 14, 14, 64);
auto s_a_hc23 = make_vector<share*>(1, 14, 14, 64);
auto hp2 = make_vector<uint32_t>(1, 7, 7, 64);
auto s_a_hp2 = make_vector<share*>(1, 7, 7, 64);
auto ht2 = make_vector<uint32_t>(1, 1, 1, 3136);
auto s_a_ht2 = make_vector<share*>(1, 1, 1, 3136);
auto hf11 = make_vector<uint32_t>(1, 1, 1, 1024);
auto s_a_hf11 = make_vector<share*>(1, 1, 1, 1024);
auto hf12 = make_vector<uint32_t>(1, 1, 1, 1024);
auto s_a_hf12 = make_vector<share*>(1, 1, 1, 1024);
auto hf13 = make_vector<uint32_t>(1, 1, 1, 1024);
auto s_a_hf13 = make_vector<share*>(1, 1, 1, 1024);
auto hf21 = make_vector<uint32_t>(1, 1, 1, 10);
auto s_a_hf21 = make_vector<share*>(1, 1, 1, 10);
auto hf22 = make_vector<uint32_t>(1, 1, 1, 10);
auto s_a_hf22 = make_vector<share*>(1, 1, 1, 10);
for (uint32_t i = 0; i < 5; i++)
{
    for (uint32_t j = 0; j < 5; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 32; l++)
            {
                if (role == CLIENT) {
                    Wc1[i][j][k][l] = 1 ;
                    s_a_Wc1[i][j][k][l] = acirc->PutINGate( Wc1[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_Wc1[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 5; i++)
{
    for (uint32_t j = 0; j < 5; j++)
    {
        for (uint32_t k = 0; k < 32; k++)
        {
            for (uint32_t l = 0; l < 64; l++)
            {
                if (role == CLIENT) {
                    Wc2[i][j][k][l] = 1 ;
                    s_a_Wc2[i][j][k][l] = acirc->PutINGate( Wc2[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_Wc2[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 3136; k++)
        {
            for (uint32_t l = 0; l < 1024; l++)
            {
                if (role == CLIENT) {
                    Wf1[i][j][k][l] = 1 ;
                    s_a_Wf1[i][j][k][l] = acirc->PutINGate( Wf1[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_Wf1[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1024; k++)
        {
            for (uint32_t l = 0; l < 10; l++)
            {
                if (role == CLIENT) {
                    Wf2[i][j][k][l] = 1 ;
                    s_a_Wf2[i][j][k][l] = acirc->PutINGate( Wf2[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_Wf2[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 32; l++)
            {
                if (role == CLIENT) {
                    bc1[i][j][k][l] = 1 ;
                    s_a_bc1[i][j][k][l] = acirc->PutINGate( bc1[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_bc1[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 64; l++)
            {
                if (role == CLIENT) {
                    bc2[i][j][k][l] = 1 ;
                    s_a_bc2[i][j][k][l] = acirc->PutINGate( bc2[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_bc2[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 1024; l++)
            {
                if (role == CLIENT) {
                    bf1[i][j][k][l] = 1 ;
                    s_a_bf1[i][j][k][l] = acirc->PutINGate( bf1[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_bf1[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 10; l++)
            {
                if (role == CLIENT) {
                    bf2[i][j][k][l] = 1 ;
                    s_a_bf2[i][j][k][l] = acirc->PutINGate( bf2[i][j][k][l] ,bitlen,CLIENT);
                } else {
                    s_a_bf2[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 784; l++)
            {
                if (role == SERVER) {
                    x[i][j][k][l] = 1 ;
                    s_a_x[i][j][k][l] = acirc->PutINGate( x[i][j][k][l] ,bitlen,SERVER);
                } else {
                    s_a_x[i][j][k][l] = acirc->PutDummyINGate(bitlen);
                }
            }
        }
    }
}
ii = 0 ;
s_a_ii = acirc->PutCONSGate( ii ,bitlen);
jj = 0 ;
s_a_jj = acirc->PutCONSGate( jj ,bitlen);
kk = 0 ;
s_a_kk = acirc->PutCONSGate( kk ,bitlen);
ll = 0 ;
s_a_ll = acirc->PutCONSGate( ll ,bitlen);
auto s_y_x = make_vector<share*>(1, 1, 1, 784);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 784 ; _i10++) {
s_y_x[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_x[_i1][_i4][_i7][_i10] );
}
}
}
}
auto s_y_ximg = make_vector<share*>(1, 28, 28, 1);
share *s_y_ll = ycirc->PutA2YGate( s_a_ll );
share * s_y_llover ;
share *s_y_kk = ycirc->PutA2YGate( s_a_kk );
share * s_y_kkover ;
share *s_y_jj = ycirc->PutA2YGate( s_a_jj );
share * s_y_jjover ;
share *s_y_ii = ycirc->PutA2YGate( s_a_ii );
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 28; j++)
    {
        for (uint32_t k = 0; k < 28; k++)
        {
            for (uint32_t l = 0; l < 1; l++)
            {
                s_y_ximg[i][j][k][l] = create_new_share(s_y_x[ii][jj][kk][ll]->get_wires(), ycirc );
                uint32_t _tmp_0 = 1 ;
                share * s_y__tmp_0 = ycirc->PutCONSGate( _tmp_0 ,bitlen);
                s_y_ll = ycirc->PutADDGate( s_y_ll , s_y__tmp_0 );
                uint32_t _tmp_2 = 784 ;
                share * s_y__tmp_2 = ycirc->PutCONSGate( _tmp_2 ,bitlen);
                share * s_y_tmp_1 = ycirc->PutEQGate( s_y_ll , s_y__tmp_2 );
                uint32_t _tmp_3 = 1 ;
                share * s_y__tmp_3 = ycirc->PutCONSGate( _tmp_3 ,bitlen);
                uint32_t _tmp_4 = 0 ;
                share * s_y__tmp_4 = ycirc->PutCONSGate( _tmp_4 ,bitlen);
                s_y_llover = ycirc->PutMUXGate( s_y__tmp_3 , s_y__tmp_4 , s_y_tmp_1 );
                uint32_t _tmp_6 = 1 ;
                share * s_y__tmp_6 = ycirc->PutCONSGate( _tmp_6 ,bitlen);
                share * s_y_tmp_5 = ycirc->PutEQGate( s_y_llover , s_y__tmp_6 );
                uint32_t _tmp_7 = 0 ;
                share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
                s_y_ll = ycirc->PutMUXGate( s_y__tmp_7 , s_y_ll , s_y_tmp_5 );
                uint32_t _tmp_9 = 1 ;
                share * s_y__tmp_9 = ycirc->PutCONSGate( _tmp_9 ,bitlen);
                share * s_y_tmp_8 = ycirc->PutEQGate( s_y_llover , s_y__tmp_9 );
                uint32_t _tmp_11 = 1 ;
                share * s_y__tmp_11 = ycirc->PutCONSGate( _tmp_11 ,bitlen);
                share * s_y_tmp_10 = ycirc->PutADDGate( s_y_kk , s_y__tmp_11 );
                s_y_kk = ycirc->PutMUXGate( s_y_tmp_10 , s_y_kk , s_y_tmp_8 );
                uint32_t _tmp_13 = 1 ;
                share * s_y__tmp_13 = ycirc->PutCONSGate( _tmp_13 ,bitlen);
                share * s_y_tmp_12 = ycirc->PutEQGate( s_y_kk , s_y__tmp_13 );
                uint32_t _tmp_14 = 1 ;
                share * s_y__tmp_14 = ycirc->PutCONSGate( _tmp_14 ,bitlen);
                uint32_t _tmp_15 = 0 ;
                share * s_y__tmp_15 = ycirc->PutCONSGate( _tmp_15 ,bitlen);
                s_y_kkover = ycirc->PutMUXGate( s_y__tmp_14 , s_y__tmp_15 , s_y_tmp_12 );
                uint32_t _tmp_17 = 1 ;
                share * s_y__tmp_17 = ycirc->PutCONSGate( _tmp_17 ,bitlen);
                share * s_y_tmp_16 = ycirc->PutEQGate( s_y_kkover , s_y__tmp_17 );
                uint32_t _tmp_18 = 0 ;
                share * s_y__tmp_18 = ycirc->PutCONSGate( _tmp_18 ,bitlen);
                s_y_kk = ycirc->PutMUXGate( s_y__tmp_18 , s_y_kk , s_y_tmp_16 );
                uint32_t _tmp_20 = 1 ;
                share * s_y__tmp_20 = ycirc->PutCONSGate( _tmp_20 ,bitlen);
                share * s_y_tmp_19 = ycirc->PutEQGate( s_y_kkover , s_y__tmp_20 );
                uint32_t _tmp_22 = 1 ;
                share * s_y__tmp_22 = ycirc->PutCONSGate( _tmp_22 ,bitlen);
                share * s_y_tmp_21 = ycirc->PutADDGate( s_y_jj , s_y__tmp_22 );
                s_y_jj = ycirc->PutMUXGate( s_y_tmp_21 , s_y_jj , s_y_tmp_19 );
                uint32_t _tmp_24 = 1 ;
                share * s_y__tmp_24 = ycirc->PutCONSGate( _tmp_24 ,bitlen);
                share * s_y_tmp_23 = ycirc->PutEQGate( s_y_jj , s_y__tmp_24 );
                uint32_t _tmp_25 = 1 ;
                share * s_y__tmp_25 = ycirc->PutCONSGate( _tmp_25 ,bitlen);
                uint32_t _tmp_26 = 0 ;
                share * s_y__tmp_26 = ycirc->PutCONSGate( _tmp_26 ,bitlen);
                s_y_jjover = ycirc->PutMUXGate( s_y__tmp_25 , s_y__tmp_26 , s_y_tmp_23 );
                uint32_t _tmp_28 = 1 ;
                share * s_y__tmp_28 = ycirc->PutCONSGate( _tmp_28 ,bitlen);
                share * s_y_tmp_27 = ycirc->PutEQGate( s_y_jjover , s_y__tmp_28 );
                uint32_t _tmp_29 = 0 ;
                share * s_y__tmp_29 = ycirc->PutCONSGate( _tmp_29 ,bitlen);
                s_y_jj = ycirc->PutMUXGate( s_y__tmp_29 , s_y_jj , s_y_tmp_27 );
                uint32_t _tmp_31 = 1 ;
                share * s_y__tmp_31 = ycirc->PutCONSGate( _tmp_31 ,bitlen);
                share * s_y_tmp_30 = ycirc->PutEQGate( s_y_jjover , s_y__tmp_31 );
                uint32_t _tmp_33 = 1 ;
                share * s_y__tmp_33 = ycirc->PutCONSGate( _tmp_33 ,bitlen);
                share * s_y_tmp_32 = ycirc->PutADDGate( s_y_ii , s_y__tmp_33 );
                s_y_ii = ycirc->PutMUXGate( s_y_tmp_32 , s_y_ii , s_y_tmp_30 );
            }
        }
    }
}
auto ximgBuf = make_vector<uint32_t>(1, 32, 32, 1);
auto s_y_ximgBuf = make_vector<share*>(1, 32, 32, 1);
auto hc11Buf = make_vector<uint32_t>(1, 28, 28, 32, 25);
auto s_y_hc11Buf = make_vector<share*>(1, 28, 28, 32, 25);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 28; j++)
    {
        for (uint32_t k = 0; k < 28; k++)
        {
            for (uint32_t l = 0; l < 1; l++)
            {
                uint32_t _tmp_35 = 2147483648 ;
                share * s_y__tmp_35 = ycirc->PutCONSGate( _tmp_35 ,bitlen);
                share * s_y_tmp_34 = ycirc->PutGTGate( s_y__tmp_35 , s_y_ximg[i][j][k][l] );
                vector<uint32_t> _vec37 = s_y_ximg[i][j][k][l]->get_wires();
                _vec37.erase( _vec37.begin(), _vec37.begin() + 15 );
                share *s_y_tmp_36 = create_new_share( _vec37 , ycirc );
                uint32_t _tmp_41 = 4294967295 ;
                share * s_y__tmp_41 = ycirc->PutCONSGate( _tmp_41 ,bitlen);
                share * s_y_tmp_40 = ycirc->PutXORGate( s_y_ximg[i][j][k][l] , s_y__tmp_41 );
                vector<uint32_t> _vec42 = s_y_tmp_40->get_wires();
                _vec42.erase( _vec42.begin(), _vec42.begin() + 15 );
                share *s_y_tmp_39 = create_new_share( _vec42 , ycirc );
                uint32_t _tmp_43 = 4294967295 ;
                share * s_y__tmp_43 = ycirc->PutCONSGate( _tmp_43 ,bitlen);
                share * s_y_tmp_38 = ycirc->PutXORGate( s_y_tmp_39 , s_y__tmp_43 );
                s_y_ximg[i][j][k][l] = ycirc->PutMUXGate( s_y_tmp_36 , s_y_tmp_38 , s_y_tmp_34 );
            }
        }
    }
}
auto s_y_Wc1 = make_vector<share*>(5, 5, 1, 32);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
s_y_Wc1[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_Wc1[_i1][_i4][_i7][_i10] );
}
}
}
}
for (uint32_t i = 0; i < 5; i++)
{
    for (uint32_t j = 0; j < 5; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 32; l++)
            {
                uint32_t _tmp_45 = 2147483648 ;
                share * s_y__tmp_45 = ycirc->PutCONSGate( _tmp_45 ,bitlen);
                share * s_y_tmp_44 = ycirc->PutGTGate( s_y__tmp_45 , s_y_Wc1[i][j][k][l] );
                vector<uint32_t> _vec47 = s_y_Wc1[i][j][k][l]->get_wires();
                _vec47.erase( _vec47.begin(), _vec47.begin() + 15 );
                share *s_y_tmp_46 = create_new_share( _vec47 , ycirc );
                uint32_t _tmp_51 = 4294967295 ;
                share * s_y__tmp_51 = ycirc->PutCONSGate( _tmp_51 ,bitlen);
                share * s_y_tmp_50 = ycirc->PutXORGate( s_y_Wc1[i][j][k][l] , s_y__tmp_51 );
                vector<uint32_t> _vec52 = s_y_tmp_50->get_wires();
                _vec52.erase( _vec52.begin(), _vec52.begin() + 15 );
                share *s_y_tmp_49 = create_new_share( _vec52 , ycirc );
                uint32_t _tmp_53 = 4294967295 ;
                share * s_y__tmp_53 = ycirc->PutCONSGate( _tmp_53 ,bitlen);
                share * s_y_tmp_48 = ycirc->PutXORGate( s_y_tmp_49 , s_y__tmp_53 );
                s_y_Wc1[i][j][k][l] = ycirc->PutMUXGate( s_y_tmp_46 , s_y_tmp_48 , s_y_tmp_44 );
            }
        }
    }
}
share * s_y_htmp ;
share * s_y_wtmp ;
for (uint32_t n = 0; n < 1; n++)
{
    htmp = 0 ;
    s_y_htmp = ycirc->PutCONSGate( htmp ,bitlen);
    for (uint32_t h = 0; h < 32; h++)
    {
        wtmp = 0 ;
        s_y_wtmp = ycirc->PutCONSGate( wtmp ,bitlen);
        for (uint32_t w = 0; w < 32; w++)
        {
            for (uint32_t ci = 0; ci < 1; ci++)
            {
                uint32_t _tmp_57 = 2 ;
                share * s_y__tmp_57 = ycirc->PutCONSGate( _tmp_57 ,bitlen);
                share * s_y_tmp_56 = ycirc->PutSUBGate( s_y_htmp , s_y__tmp_57 );
                uint32_t _tmp_58 = 28 ;
                share * s_y__tmp_58 = ycirc->PutCONSGate( _tmp_58 ,bitlen);
                share * s_y_tmp_55 = ycirc->PutGTGate( s_y__tmp_58 , s_y_tmp_56 );
                uint32_t _tmp_61 = 2 ;
                share * s_y__tmp_61 = ycirc->PutCONSGate( _tmp_61 ,bitlen);
                share * s_y_tmp_60 = ycirc->PutSUBGate( s_y_wtmp , s_y__tmp_61 );
                uint32_t _tmp_62 = 28 ;
                share * s_y__tmp_62 = ycirc->PutCONSGate( _tmp_62 ,bitlen);
                share * s_y_tmp_59 = ycirc->PutGTGate( s_y__tmp_62 , s_y_tmp_60 );
                share * s_y_tmp_54 = ycirc->PutANDGate( s_y_tmp_55 , s_y_tmp_59 );
                uint32_t _tmp_63 = 0 ;
                share * s_y__tmp_63 = ycirc->PutCONSGate( _tmp_63 ,bitlen);
                s_y_ximgBuf[n][h][w][ci] = ycirc->PutMUXGate( s_y_ximg[n][h-2][w-2][ci] , s_y__tmp_63 , s_y_tmp_54 );
            }
            uint32_t _tmp_64 = 1 ;
            share * s_y__tmp_64 = ycirc->PutCONSGate( _tmp_64 ,bitlen);
            s_y_wtmp = ycirc->PutADDGate( s_y_wtmp , s_y__tmp_64 );
        }
        uint32_t _tmp_65 = 1 ;
        share * s_y__tmp_65 = ycirc->PutCONSGate( _tmp_65 ,bitlen);
        s_y_htmp = ycirc->PutADDGate( s_y_htmp , s_y__tmp_65 );
    }
}
auto s_a_ximgBuf = make_vector<share*>(1, 32, 32, 1);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 32 ; _i4++) {
for (int _i7 = 0; _i7 < 32 ; _i7++) {
for (int _i10 = 0; _i10 < 1 ; _i10++) {
s_a_ximgBuf[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_ximgBuf[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
s_a_Wc1[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_Wc1[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
auto s_a_hc11Buf = make_vector<share*>(1, 28, 28, 32, 25);
for (uint32_t n = 0; n < 1; n++)
{
    for (uint32_t h = 0; h < 28; h++)
    {
        for (uint32_t w = 0; w < 28; w++)
        {
            for (uint32_t co = 0; co < 32; co++)
            {
                cnt = 0 ;
                s_a_cnt = acirc->PutCONSGate( cnt ,bitlen);
                for (uint32_t hf = 0; hf < 5; hf++)
                {
                    for (uint32_t wf = 0; wf < 5; wf++)
                    {
                        for (uint32_t ci = 0; ci < 1; ci++)
                        {
                            s_a_hc11Buf[n][h][w][co][cnt] = acirc->PutMULGate( s_a_ximgBuf[n][h+hf][w+wf][ci] , s_a_Wc1[hf][wf][ci][co] );
                            uint32_t _tmp_66 = 1 ;
                            share * s_a__tmp_66 = acirc->PutCONSGate( _tmp_66 ,bitlen);
                            s_a_cnt = acirc->PutADDGate( s_a_cnt , s_a__tmp_66 );
                        }
                    }
                }
            }
        }
    }
}
share * s_y_N ;
share * s_y_mtmp ;
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 28 ; _i4++) {
for (int _i7 = 0; _i7 < 28 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
for (int _i13 = 0; _i13 < 25 ; _i13++) {
s_y_hc11Buf[_i1][_i4][_i7][_i10][_i13] = ycirc->PutA2YGate( s_a_hc11Buf[_i1][_i4][_i7][_i10][_i13] );
}
}
}
}
}
auto s_y_hc11 = make_vector<share*>(1, 28, 28, 32);
for (uint32_t n = 0; n < 1; n++)
{
    for (uint32_t h = 0; h < 28; h++)
    {
        for (uint32_t w = 0; w < 28; w++)
        {
            for (uint32_t co = 0; co < 32; co++)
            {
                N = 25 ;
                s_y_N = ycirc->PutCONSGate( N ,bitlen);
                for (uint32_t a = 0; a < 5; a++)
                {
                    mtmp = 0 ;
                    s_y_mtmp = ycirc->PutCONSGate( mtmp ,bitlen);
                    for (uint32_t m = 0; m < 25; m++)
                    {
                        vector<uint32_t> _vec69 = s_y_N->get_wires();
                        _vec69.erase( _vec69.begin(), _vec69.begin() + 1 );
                        share *s_y_tmp_68 = create_new_share( _vec69 , ycirc );
                        share * s_y_tmp_67 = ycirc->PutGTGate( s_y_tmp_68 , s_y_mtmp );
                        share * s_y_tmp_72 = ycirc->PutADDGate( s_y_hc11Buf[n][h][w][co][2*mtmp] , s_y_hc11Buf[n][h][w][co][2*mtmp+1] );
                        uint32_t _tmp_73 = 2147483648 ;
                        share * s_y__tmp_73 = ycirc->PutCONSGate( _tmp_73 ,bitlen);
                        share * s_y_tmp_71 = ycirc->PutGTGate( s_y__tmp_73 , s_y_tmp_72 );
                        share * s_y_tmp_75 = ycirc->PutADDGate( s_y_hc11Buf[n][h][w][co][2*mtmp] , s_y_hc11Buf[n][h][w][co][2*mtmp+1] );
                        vector<uint32_t> _vec76 = s_y_tmp_75->get_wires();
                        _vec76.erase( _vec76.begin(), _vec76.begin() + 1 );
                        share *s_y_tmp_74 = create_new_share( _vec76 , ycirc );
                        share * s_y_tmp_80 = ycirc->PutADDGate( s_y_hc11Buf[n][h][w][co][2*mtmp] , s_y_hc11Buf[n][h][w][co][2*mtmp+1] );
                        uint32_t _tmp_81 = 4294967295 ;
                        share * s_y__tmp_81 = ycirc->PutCONSGate( _tmp_81 ,bitlen);
                        share * s_y_tmp_79 = ycirc->PutXORGate( s_y_tmp_80 , s_y__tmp_81 );
                        vector<uint32_t> _vec82 = s_y_tmp_79->get_wires();
                        _vec82.erase( _vec82.begin(), _vec82.begin() + 1 );
                        share *s_y_tmp_78 = create_new_share( _vec82 , ycirc );
                        uint32_t _tmp_83 = 4294967295 ;
                        share * s_y__tmp_83 = ycirc->PutCONSGate( _tmp_83 ,bitlen);
                        share * s_y_tmp_77 = ycirc->PutXORGate( s_y_tmp_78 , s_y__tmp_83 );
                        share * s_y_tmp_70 = ycirc->PutMUXGate( s_y_tmp_74 , s_y_tmp_77 , s_y_tmp_71 );
                        s_y_hc11Buf[n][h][w][co][mtmp] = ycirc->PutMUXGate( s_y_tmp_70 , s_y_hc11Buf[n][h][w][co][mtmp] , s_y_tmp_67 );
                        uint32_t _tmp_84 = 1 ;
                        share * s_y__tmp_84 = ycirc->PutCONSGate( _tmp_84 ,bitlen);
                        s_y_mtmp = ycirc->PutADDGate( s_y_mtmp , s_y__tmp_84 );
                    }
                    uint32_t _tmp_87 = 1 ;
                    share * s_y__tmp_87 = ycirc->PutCONSGate( _tmp_87 ,bitlen);
                    share * s_y_tmp_86 = ycirc->PutANDGate( s_y_N , s_y__tmp_87 );
                    uint32_t _tmp_88 = 1 ;
                    share * s_y__tmp_88 = ycirc->PutCONSGate( _tmp_88 ,bitlen);
                    share * s_y_tmp_85 = ycirc->PutEQGate( s_y_tmp_86 , s_y__tmp_88 );
                    uint32_t _tmp_91 = 2147483648 ;
                    share * s_y__tmp_91 = ycirc->PutCONSGate( _tmp_91 ,bitlen);
                    share * s_y_tmp_90 = ycirc->PutGTGate( s_y__tmp_91 , s_y_hc11Buf[n][h][w][co][N-1] );
                    vector<uint32_t> _vec93 = s_y_hc11Buf[n][h][w][co][N-1]->get_wires();
                    _vec93.erase( _vec93.begin(), _vec93.begin() + 1 );
                    share *s_y_tmp_92 = create_new_share( _vec93 , ycirc );
                    uint32_t _tmp_97 = 4294967295 ;
                    share * s_y__tmp_97 = ycirc->PutCONSGate( _tmp_97 ,bitlen);
                    share * s_y_tmp_96 = ycirc->PutXORGate( s_y_hc11Buf[n][h][w][co][N-1] , s_y__tmp_97 );
                    vector<uint32_t> _vec98 = s_y_tmp_96->get_wires();
                    _vec98.erase( _vec98.begin(), _vec98.begin() + 1 );
                    share *s_y_tmp_95 = create_new_share( _vec98 , ycirc );
                    uint32_t _tmp_99 = 4294967295 ;
                    share * s_y__tmp_99 = ycirc->PutCONSGate( _tmp_99 ,bitlen);
                    share * s_y_tmp_94 = ycirc->PutXORGate( s_y_tmp_95 , s_y__tmp_99 );
                    share * s_y_tmp_89 = ycirc->PutMUXGate( s_y_tmp_92 , s_y_tmp_94 , s_y_tmp_90 );
                    uint32_t _tmp_100 = 0 ;
                    share * s_y__tmp_100 = ycirc->PutCONSGate( _tmp_100 ,bitlen);
                    s_y_hc11Buf[n][h][w][co][N>>1] = ycirc->PutMUXGate( s_y_tmp_89 , s_y__tmp_100 , s_y_tmp_85 );
                    uint32_t _tmp_102 = 1 ;
                    share * s_y__tmp_102 = ycirc->PutCONSGate( _tmp_102 ,bitlen);
                    share * s_y_tmp_101 = ycirc->PutADDGate( s_y_N , s_y__tmp_102 );
                    vector<uint32_t> _vec103 = s_y_tmp_101->get_wires();
                    _vec103.erase( _vec103.begin(), _vec103.begin() + 1 );
                    s_y_N = create_new_share( _vec103 , ycirc );
                }
                s_y_hc11[n][h][w][co] = create_new_share(s_y_hc11Buf[n][h][w][co][0]->get_wires(), ycirc );
            }
        }
    }
}
share * s_y_tmp0 ;
auto s_y_bc1 = make_vector<share*>(1, 1, 1, 32);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
s_y_bc1[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_bc1[_i1][_i4][_i7][_i10] );
}
}
}
}
share * s_y_tmp1 ;
auto s_y_hc12 = make_vector<share*>(1, 28, 28, 32);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 28; j++)
    {
        for (uint32_t k = 0; k < 28; k++)
        {
            for (uint32_t l = 0; l < 32; l++)
            {
                s_y_tmp0 = create_new_share(s_y_hc11[i][j][k][l]->get_wires(), ycirc );
                uint32_t _tmp_105 = 2147483648 ;
                share * s_y__tmp_105 = ycirc->PutCONSGate( _tmp_105 ,bitlen);
                share * s_y_tmp_104 = ycirc->PutGTGate( s_y__tmp_105 , s_y_bc1[0][0][0][l] );
                vector<uint32_t> _vec107 = s_y_bc1[0][0][0][l]->get_wires();
                _vec107.erase( _vec107.begin(), _vec107.begin() + 7 );
                share *s_y_tmp_106 = create_new_share( _vec107 , ycirc );
                uint32_t _tmp_111 = 4294967295 ;
                share * s_y__tmp_111 = ycirc->PutCONSGate( _tmp_111 ,bitlen);
                share * s_y_tmp_110 = ycirc->PutXORGate( s_y_bc1[0][0][0][l] , s_y__tmp_111 );
                vector<uint32_t> _vec112 = s_y_tmp_110->get_wires();
                _vec112.erase( _vec112.begin(), _vec112.begin() + 7 );
                share *s_y_tmp_109 = create_new_share( _vec112 , ycirc );
                uint32_t _tmp_113 = 4294967295 ;
                share * s_y__tmp_113 = ycirc->PutCONSGate( _tmp_113 ,bitlen);
                share * s_y_tmp_108 = ycirc->PutXORGate( s_y_tmp_109 , s_y__tmp_113 );
                s_y_tmp1 = ycirc->PutMUXGate( s_y_tmp_106 , s_y_tmp_108 , s_y_tmp_104 );
                s_y_hc12[i][j][k][l] = ycirc->PutADDGate( s_y_tmp0 , s_y_tmp1 );
                s_y_hc12[i][j][k][l] = create_new_share(s_y_hc12[i][j][k][l]->get_wires(), ycirc );
            }
        }
    }
}
auto s_y_hc13 = make_vector<share*>(1, 28, 28, 32);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 28; j++)
    {
        for (uint32_t k = 0; k < 28; k++)
        {
            for (uint32_t l = 0; l < 32; l++)
            {
                uint32_t _tmp_115 = 2147483648 ;
                share * s_y__tmp_115 = ycirc->PutCONSGate( _tmp_115 ,bitlen);
                share * s_y_tmp_114 = ycirc->PutGTGate( s_y__tmp_115 , s_y_hc12[i][j][k][l] );
                uint32_t _tmp_116 = 0 ;
                share * s_y__tmp_116 = ycirc->PutCONSGate( _tmp_116 ,bitlen);
                s_y_hc13[i][j][k][l] = ycirc->PutMUXGate( s_y_hc12[i][j][k][l] , s_y__tmp_116 , s_y_tmp_114 );
            }
        }
    }
}
auto s_y_hp1 = make_vector<share*>(1, 14, 14, 32);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 14; j++)
    {
        for (uint32_t k = 0; k < 14; k++)
        {
            for (uint32_t l = 0; l < 32; l++)
            {
                uint32_t _tmp_118 = 2147483648 ;
                share * s_y__tmp_118 = ycirc->PutCONSGate( _tmp_118 ,bitlen);
                share * s_y_tmp_117 = ycirc->PutGTGate( s_y__tmp_118 , s_y_hc13[i][2*j][2*k][l] );
                uint32_t _tmp_121 = 2147483648 ;
                share * s_y__tmp_121 = ycirc->PutCONSGate( _tmp_121 ,bitlen);
                share * s_y_tmp_120 = ycirc->PutGTGate( s_y__tmp_121 , s_y_hc13[i][2*j][2*k+1][l] );
                share * s_y_tmp_123 = ycirc->PutGTGate( s_y_hc13[i][2*j][2*k][l] , s_y_hc13[i][2*j][2*k+1][l] );
                share * s_y_tmp_122 = ycirc->PutMUXGate( s_y_hc13[i][2*j][2*k][l] , s_y_hc13[i][2*j][2*k+1][l] , s_y_tmp_123 );
                share * s_y_tmp_119 = ycirc->PutMUXGate( s_y_tmp_122 , s_y_hc13[i][2*j][2*k][l] , s_y_tmp_120 );
                uint32_t _tmp_126 = 2147483648 ;
                share * s_y__tmp_126 = ycirc->PutCONSGate( _tmp_126 ,bitlen);
                share * s_y_tmp_125 = ycirc->PutGTGate( s_y__tmp_126 , s_y_hc13[i][2*j][2*k+1][l] );
                share * s_y_tmp_128 = ycirc->PutGTGate( s_y_hc13[i][2*j][2*k][l] , s_y_hc13[i][2*j][2*k+1][l] );
                share * s_y_tmp_127 = ycirc->PutMUXGate( s_y_hc13[i][2*j][2*k+1][l] , s_y_hc13[i][2*j][2*k][l] , s_y_tmp_128 );
                share * s_y_tmp_124 = ycirc->PutMUXGate( s_y_hc13[i][2*j][2*k+1][l] , s_y_tmp_127 , s_y_tmp_125 );
                s_y_tmp0 = ycirc->PutMUXGate( s_y_tmp_119 , s_y_tmp_124 , s_y_tmp_117 );
                uint32_t _tmp_130 = 2147483648 ;
                share * s_y__tmp_130 = ycirc->PutCONSGate( _tmp_130 ,bitlen);
                share * s_y_tmp_129 = ycirc->PutGTGate( s_y__tmp_130 , s_y_hc13[i][2*j+1][2*k][l] );
                uint32_t _tmp_133 = 2147483648 ;
                share * s_y__tmp_133 = ycirc->PutCONSGate( _tmp_133 ,bitlen);
                share * s_y_tmp_132 = ycirc->PutGTGate( s_y__tmp_133 , s_y_hc13[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_135 = ycirc->PutGTGate( s_y_hc13[i][2*j+1][2*k][l] , s_y_hc13[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_134 = ycirc->PutMUXGate( s_y_hc13[i][2*j+1][2*k][l] , s_y_hc13[i][2*j+1][2*k+1][l] , s_y_tmp_135 );
                share * s_y_tmp_131 = ycirc->PutMUXGate( s_y_tmp_134 , s_y_hc13[i][2*j+1][2*k][l] , s_y_tmp_132 );
                uint32_t _tmp_138 = 2147483648 ;
                share * s_y__tmp_138 = ycirc->PutCONSGate( _tmp_138 ,bitlen);
                share * s_y_tmp_137 = ycirc->PutGTGate( s_y__tmp_138 , s_y_hc13[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_140 = ycirc->PutGTGate( s_y_hc13[i][2*j+1][2*k][l] , s_y_hc13[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_139 = ycirc->PutMUXGate( s_y_hc13[i][2*j+1][2*k+1][l] , s_y_hc13[i][2*j+1][2*k][l] , s_y_tmp_140 );
                share * s_y_tmp_136 = ycirc->PutMUXGate( s_y_hc13[i][2*j+1][2*k+1][l] , s_y_tmp_139 , s_y_tmp_137 );
                s_y_tmp1 = ycirc->PutMUXGate( s_y_tmp_131 , s_y_tmp_136 , s_y_tmp_129 );
                uint32_t _tmp_142 = 2147483648 ;
                share * s_y__tmp_142 = ycirc->PutCONSGate( _tmp_142 ,bitlen);
                share * s_y_tmp_141 = ycirc->PutGTGate( s_y__tmp_142 , s_y_tmp0 );
                uint32_t _tmp_145 = 2147483648 ;
                share * s_y__tmp_145 = ycirc->PutCONSGate( _tmp_145 ,bitlen);
                share * s_y_tmp_144 = ycirc->PutGTGate( s_y__tmp_145 , s_y_tmp1 );
                share * s_y_tmp_147 = ycirc->PutGTGate( s_y_tmp0 , s_y_tmp1 );
                share * s_y_tmp_146 = ycirc->PutMUXGate( s_y_tmp0 , s_y_tmp1 , s_y_tmp_147 );
                share * s_y_tmp_143 = ycirc->PutMUXGate( s_y_tmp_146 , s_y_tmp0 , s_y_tmp_144 );
                uint32_t _tmp_150 = 2147483648 ;
                share * s_y__tmp_150 = ycirc->PutCONSGate( _tmp_150 ,bitlen);
                share * s_y_tmp_149 = ycirc->PutGTGate( s_y__tmp_150 , s_y_tmp1 );
                share * s_y_tmp_152 = ycirc->PutGTGate( s_y_tmp0 , s_y_tmp1 );
                share * s_y_tmp_151 = ycirc->PutMUXGate( s_y_tmp1 , s_y_tmp0 , s_y_tmp_152 );
                share * s_y_tmp_148 = ycirc->PutMUXGate( s_y_tmp1 , s_y_tmp_151 , s_y_tmp_149 );
                s_y_hp1[i][j][k][l] = ycirc->PutMUXGate( s_y_tmp_143 , s_y_tmp_148 , s_y_tmp_141 );
            }
        }
    }
}
auto hp1Buf = make_vector<uint32_t>(1, 18, 18, 32);
auto s_y_hp1Buf = make_vector<share*>(1, 18, 18, 32);
auto hc21Buf = make_vector<uint32_t>(1, 14, 14, 64, 800);
auto s_y_hc21Buf = make_vector<share*>(1, 14, 14, 64, 800);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 14; j++)
    {
        for (uint32_t k = 0; k < 14; k++)
        {
            for (uint32_t l = 0; l < 32; l++)
            {
                uint32_t _tmp_154 = 2147483648 ;
                share * s_y__tmp_154 = ycirc->PutCONSGate( _tmp_154 ,bitlen);
                share * s_y_tmp_153 = ycirc->PutGTGate( s_y__tmp_154 , s_y_hp1[i][j][k][l] );
                vector<uint32_t> _vec156 = s_y_hp1[i][j][k][l]->get_wires();
                _vec156.erase( _vec156.begin(), _vec156.begin() + 15 );
                share *s_y_tmp_155 = create_new_share( _vec156 , ycirc );
                uint32_t _tmp_160 = 4294967295 ;
                share * s_y__tmp_160 = ycirc->PutCONSGate( _tmp_160 ,bitlen);
                share * s_y_tmp_159 = ycirc->PutXORGate( s_y_hp1[i][j][k][l] , s_y__tmp_160 );
                vector<uint32_t> _vec161 = s_y_tmp_159->get_wires();
                _vec161.erase( _vec161.begin(), _vec161.begin() + 15 );
                share *s_y_tmp_158 = create_new_share( _vec161 , ycirc );
                uint32_t _tmp_162 = 4294967295 ;
                share * s_y__tmp_162 = ycirc->PutCONSGate( _tmp_162 ,bitlen);
                share * s_y_tmp_157 = ycirc->PutXORGate( s_y_tmp_158 , s_y__tmp_162 );
                s_y_hp1[i][j][k][l] = ycirc->PutMUXGate( s_y_tmp_155 , s_y_tmp_157 , s_y_tmp_153 );
            }
        }
    }
}
auto s_y_Wc2 = make_vector<share*>(5, 5, 32, 64);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 32 ; _i7++) {
for (int _i10 = 0; _i10 < 64 ; _i10++) {
s_y_Wc2[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_Wc2[_i1][_i4][_i7][_i10] );
}
}
}
}
for (uint32_t i = 0; i < 5; i++)
{
    for (uint32_t j = 0; j < 5; j++)
    {
        for (uint32_t k = 0; k < 32; k++)
        {
            for (uint32_t l = 0; l < 64; l++)
            {
                uint32_t _tmp_164 = 2147483648 ;
                share * s_y__tmp_164 = ycirc->PutCONSGate( _tmp_164 ,bitlen);
                share * s_y_tmp_163 = ycirc->PutGTGate( s_y__tmp_164 , s_y_Wc2[i][j][k][l] );
                vector<uint32_t> _vec166 = s_y_Wc2[i][j][k][l]->get_wires();
                _vec166.erase( _vec166.begin(), _vec166.begin() + 15 );
                share *s_y_tmp_165 = create_new_share( _vec166 , ycirc );
                uint32_t _tmp_170 = 4294967295 ;
                share * s_y__tmp_170 = ycirc->PutCONSGate( _tmp_170 ,bitlen);
                share * s_y_tmp_169 = ycirc->PutXORGate( s_y_Wc2[i][j][k][l] , s_y__tmp_170 );
                vector<uint32_t> _vec171 = s_y_tmp_169->get_wires();
                _vec171.erase( _vec171.begin(), _vec171.begin() + 15 );
                share *s_y_tmp_168 = create_new_share( _vec171 , ycirc );
                uint32_t _tmp_172 = 4294967295 ;
                share * s_y__tmp_172 = ycirc->PutCONSGate( _tmp_172 ,bitlen);
                share * s_y_tmp_167 = ycirc->PutXORGate( s_y_tmp_168 , s_y__tmp_172 );
                s_y_Wc2[i][j][k][l] = ycirc->PutMUXGate( s_y_tmp_165 , s_y_tmp_167 , s_y_tmp_163 );
            }
        }
    }
}
for (uint32_t n = 0; n < 1; n++)
{
    htmp = 0 ;
    s_y_htmp = ycirc->PutCONSGate( htmp ,bitlen);
    for (uint32_t h = 0; h < 18; h++)
    {
        wtmp = 0 ;
        s_y_wtmp = ycirc->PutCONSGate( wtmp ,bitlen);
        for (uint32_t w = 0; w < 18; w++)
        {
            for (uint32_t ci = 0; ci < 32; ci++)
            {
                uint32_t _tmp_176 = 2 ;
                share * s_y__tmp_176 = ycirc->PutCONSGate( _tmp_176 ,bitlen);
                share * s_y_tmp_175 = ycirc->PutSUBGate( s_y_htmp , s_y__tmp_176 );
                uint32_t _tmp_177 = 14 ;
                share * s_y__tmp_177 = ycirc->PutCONSGate( _tmp_177 ,bitlen);
                share * s_y_tmp_174 = ycirc->PutGTGate( s_y__tmp_177 , s_y_tmp_175 );
                uint32_t _tmp_180 = 2 ;
                share * s_y__tmp_180 = ycirc->PutCONSGate( _tmp_180 ,bitlen);
                share * s_y_tmp_179 = ycirc->PutSUBGate( s_y_wtmp , s_y__tmp_180 );
                uint32_t _tmp_181 = 14 ;
                share * s_y__tmp_181 = ycirc->PutCONSGate( _tmp_181 ,bitlen);
                share * s_y_tmp_178 = ycirc->PutGTGate( s_y__tmp_181 , s_y_tmp_179 );
                share * s_y_tmp_173 = ycirc->PutANDGate( s_y_tmp_174 , s_y_tmp_178 );
                uint32_t _tmp_182 = 0 ;
                share * s_y__tmp_182 = ycirc->PutCONSGate( _tmp_182 ,bitlen);
                s_y_hp1Buf[n][h][w][ci] = ycirc->PutMUXGate( s_y_hp1[n][h-2][w-2][ci] , s_y__tmp_182 , s_y_tmp_173 );
            }
            uint32_t _tmp_183 = 1 ;
            share * s_y__tmp_183 = ycirc->PutCONSGate( _tmp_183 ,bitlen);
            s_y_wtmp = ycirc->PutADDGate( s_y_wtmp , s_y__tmp_183 );
        }
        uint32_t _tmp_184 = 1 ;
        share * s_y__tmp_184 = ycirc->PutCONSGate( _tmp_184 ,bitlen);
        s_y_htmp = ycirc->PutADDGate( s_y_htmp , s_y__tmp_184 );
    }
}
auto s_a_hp1Buf = make_vector<share*>(1, 18, 18, 32);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 18 ; _i4++) {
for (int _i7 = 0; _i7 < 18 ; _i7++) {
for (int _i10 = 0; _i10 < 32 ; _i10++) {
s_a_hp1Buf[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_hp1Buf[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 5 ; _i4++) {
for (int _i7 = 0; _i7 < 32 ; _i7++) {
for (int _i10 = 0; _i10 < 64 ; _i10++) {
s_a_Wc2[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_Wc2[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
auto s_a_hc21Buf = make_vector<share*>(1, 14, 14, 64, 800);
for (uint32_t n = 0; n < 1; n++)
{
    for (uint32_t h = 0; h < 14; h++)
    {
        for (uint32_t w = 0; w < 14; w++)
        {
            for (uint32_t co = 0; co < 64; co++)
            {
                cnt = 0 ;
                s_a_cnt = acirc->PutCONSGate( cnt ,bitlen);
                for (uint32_t hf = 0; hf < 5; hf++)
                {
                    for (uint32_t wf = 0; wf < 5; wf++)
                    {
                        for (uint32_t ci = 0; ci < 32; ci++)
                        {
                            s_a_hc21Buf[n][h][w][co][cnt] = acirc->PutMULGate( s_a_hp1Buf[n][h+hf][w+wf][ci] , s_a_Wc2[hf][wf][ci][co] );
                            uint32_t _tmp_185 = 1 ;
                            share * s_a__tmp_185 = acirc->PutCONSGate( _tmp_185 ,bitlen);
                            s_a_cnt = acirc->PutADDGate( s_a_cnt , s_a__tmp_185 );
                        }
                    }
                }
            }
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 14 ; _i4++) {
for (int _i7 = 0; _i7 < 14 ; _i7++) {
for (int _i10 = 0; _i10 < 64 ; _i10++) {
for (int _i13 = 0; _i13 < 800 ; _i13++) {
s_y_hc21Buf[_i1][_i4][_i7][_i10][_i13] = ycirc->PutA2YGate( s_a_hc21Buf[_i1][_i4][_i7][_i10][_i13] );
}
}
}
}
}
auto s_y_hc21 = make_vector<share*>(1, 14, 14, 64);
for (uint32_t n = 0; n < 1; n++)
{
    for (uint32_t h = 0; h < 14; h++)
    {
        for (uint32_t w = 0; w < 14; w++)
        {
            for (uint32_t co = 0; co < 64; co++)
            {
                N = 800 ;
                s_y_N = ycirc->PutCONSGate( N ,bitlen);
                for (uint32_t a = 0; a < 2; a++)
                {
                    mtmp = 0 ;
                    s_y_mtmp = ycirc->PutCONSGate( mtmp ,bitlen);
                    for (uint32_t m = 0; m < 800; m++)
                    {
                        vector<uint32_t> _vec188 = s_y_N->get_wires();
                        _vec188.erase( _vec188.begin(), _vec188.begin() + 1 );
                        share *s_y_tmp_187 = create_new_share( _vec188 , ycirc );
                        share * s_y_tmp_186 = ycirc->PutGTGate( s_y_tmp_187 , s_y_mtmp );
                        share * s_y_tmp_191 = ycirc->PutADDGate( s_y_hc21Buf[n][h][w][co][2*mtmp] , s_y_hc21Buf[n][h][w][co][2*mtmp+1] );
                        uint32_t _tmp_192 = 2147483648 ;
                        share * s_y__tmp_192 = ycirc->PutCONSGate( _tmp_192 ,bitlen);
                        share * s_y_tmp_190 = ycirc->PutGTGate( s_y__tmp_192 , s_y_tmp_191 );
                        share * s_y_tmp_194 = ycirc->PutADDGate( s_y_hc21Buf[n][h][w][co][2*mtmp] , s_y_hc21Buf[n][h][w][co][2*mtmp+1] );
                        vector<uint32_t> _vec195 = s_y_tmp_194->get_wires();
                        _vec195.erase( _vec195.begin(), _vec195.begin() + 1 );
                        share *s_y_tmp_193 = create_new_share( _vec195 , ycirc );
                        share * s_y_tmp_199 = ycirc->PutADDGate( s_y_hc21Buf[n][h][w][co][2*mtmp] , s_y_hc21Buf[n][h][w][co][2*mtmp+1] );
                        uint32_t _tmp_200 = 4294967295 ;
                        share * s_y__tmp_200 = ycirc->PutCONSGate( _tmp_200 ,bitlen);
                        share * s_y_tmp_198 = ycirc->PutXORGate( s_y_tmp_199 , s_y__tmp_200 );
                        vector<uint32_t> _vec201 = s_y_tmp_198->get_wires();
                        _vec201.erase( _vec201.begin(), _vec201.begin() + 1 );
                        share *s_y_tmp_197 = create_new_share( _vec201 , ycirc );
                        uint32_t _tmp_202 = 4294967295 ;
                        share * s_y__tmp_202 = ycirc->PutCONSGate( _tmp_202 ,bitlen);
                        share * s_y_tmp_196 = ycirc->PutXORGate( s_y_tmp_197 , s_y__tmp_202 );
                        share * s_y_tmp_189 = ycirc->PutMUXGate( s_y_tmp_193 , s_y_tmp_196 , s_y_tmp_190 );
                        s_y_hc21Buf[n][h][w][co][mtmp] = ycirc->PutMUXGate( s_y_tmp_189 , s_y_hc21Buf[n][h][w][co][mtmp] , s_y_tmp_186 );
                        uint32_t _tmp_203 = 1 ;
                        share * s_y__tmp_203 = ycirc->PutCONSGate( _tmp_203 ,bitlen);
                        s_y_mtmp = ycirc->PutADDGate( s_y_mtmp , s_y__tmp_203 );
                    }
                    uint32_t _tmp_206 = 1 ;
                    share * s_y__tmp_206 = ycirc->PutCONSGate( _tmp_206 ,bitlen);
                    share * s_y_tmp_205 = ycirc->PutANDGate( s_y_N , s_y__tmp_206 );
                    uint32_t _tmp_207 = 1 ;
                    share * s_y__tmp_207 = ycirc->PutCONSGate( _tmp_207 ,bitlen);
                    share * s_y_tmp_204 = ycirc->PutEQGate( s_y_tmp_205 , s_y__tmp_207 );
                    uint32_t _tmp_210 = 2147483648 ;
                    share * s_y__tmp_210 = ycirc->PutCONSGate( _tmp_210 ,bitlen);
                    share * s_y_tmp_209 = ycirc->PutGTGate( s_y__tmp_210 , s_y_hc21Buf[n][h][w][co][N-1] );
                    vector<uint32_t> _vec212 = s_y_hc21Buf[n][h][w][co][N-1]->get_wires();
                    _vec212.erase( _vec212.begin(), _vec212.begin() + 1 );
                    share *s_y_tmp_211 = create_new_share( _vec212 , ycirc );
                    uint32_t _tmp_216 = 4294967295 ;
                    share * s_y__tmp_216 = ycirc->PutCONSGate( _tmp_216 ,bitlen);
                    share * s_y_tmp_215 = ycirc->PutXORGate( s_y_hc21Buf[n][h][w][co][N-1] , s_y__tmp_216 );
                    vector<uint32_t> _vec217 = s_y_tmp_215->get_wires();
                    _vec217.erase( _vec217.begin(), _vec217.begin() + 1 );
                    share *s_y_tmp_214 = create_new_share( _vec217 , ycirc );
                    uint32_t _tmp_218 = 4294967295 ;
                    share * s_y__tmp_218 = ycirc->PutCONSGate( _tmp_218 ,bitlen);
                    share * s_y_tmp_213 = ycirc->PutXORGate( s_y_tmp_214 , s_y__tmp_218 );
                    share * s_y_tmp_208 = ycirc->PutMUXGate( s_y_tmp_211 , s_y_tmp_213 , s_y_tmp_209 );
                    uint32_t _tmp_219 = 0 ;
                    share * s_y__tmp_219 = ycirc->PutCONSGate( _tmp_219 ,bitlen);
                    s_y_hc21Buf[n][h][w][co][N>>1] = ycirc->PutMUXGate( s_y_tmp_208 , s_y__tmp_219 , s_y_tmp_204 );
                    uint32_t _tmp_221 = 1 ;
                    share * s_y__tmp_221 = ycirc->PutCONSGate( _tmp_221 ,bitlen);
                    share * s_y_tmp_220 = ycirc->PutADDGate( s_y_N , s_y__tmp_221 );
                    vector<uint32_t> _vec222 = s_y_tmp_220->get_wires();
                    _vec222.erase( _vec222.begin(), _vec222.begin() + 1 );
                    s_y_N = create_new_share( _vec222 , ycirc );
                }
                for (uint32_t a = 0; a < 8; a++)
                {
                    mtmp = 0 ;
                    s_y_mtmp = ycirc->PutCONSGate( mtmp ,bitlen);
                    for (uint32_t m = 0; m < 800; m++)
                    {
                        vector<uint32_t> _vec225 = s_y_N->get_wires();
                        _vec225.erase( _vec225.begin(), _vec225.begin() + 1 );
                        share *s_y_tmp_224 = create_new_share( _vec225 , ycirc );
                        share * s_y_tmp_223 = ycirc->PutGTGate( s_y_tmp_224 , s_y_mtmp );
                        share * s_y_tmp_226 = ycirc->PutADDGate( s_y_hc21Buf[n][h][w][co][2*mtmp] , s_y_hc21Buf[n][h][w][co][2*mtmp+1] );
                        s_y_hc21Buf[n][h][w][co][mtmp] = ycirc->PutMUXGate( s_y_tmp_226 , s_y_hc21Buf[n][h][w][co][mtmp] , s_y_tmp_223 );
                        uint32_t _tmp_227 = 1 ;
                        share * s_y__tmp_227 = ycirc->PutCONSGate( _tmp_227 ,bitlen);
                        s_y_mtmp = ycirc->PutADDGate( s_y_mtmp , s_y__tmp_227 );
                    }
                    uint32_t _tmp_230 = 1 ;
                    share * s_y__tmp_230 = ycirc->PutCONSGate( _tmp_230 ,bitlen);
                    share * s_y_tmp_229 = ycirc->PutANDGate( s_y_N , s_y__tmp_230 );
                    uint32_t _tmp_231 = 1 ;
                    share * s_y__tmp_231 = ycirc->PutCONSGate( _tmp_231 ,bitlen);
                    share * s_y_tmp_228 = ycirc->PutEQGate( s_y_tmp_229 , s_y__tmp_231 );
                    uint32_t _tmp_232 = 0 ;
                    share * s_y__tmp_232 = ycirc->PutCONSGate( _tmp_232 ,bitlen);
                    s_y_hc21Buf[n][h][w][co][N>>1] = ycirc->PutMUXGate( s_y_hc21Buf[n][h][w][co][N-1] , s_y__tmp_232 , s_y_tmp_228 );
                    uint32_t _tmp_234 = 1 ;
                    share * s_y__tmp_234 = ycirc->PutCONSGate( _tmp_234 ,bitlen);
                    share * s_y_tmp_233 = ycirc->PutADDGate( s_y_N , s_y__tmp_234 );
                    vector<uint32_t> _vec235 = s_y_tmp_233->get_wires();
                    _vec235.erase( _vec235.begin(), _vec235.begin() + 1 );
                    s_y_N = create_new_share( _vec235 , ycirc );
                }
                s_y_hc21[n][h][w][co] = create_new_share(s_y_hc21Buf[n][h][w][co][0]->get_wires(), ycirc );
            }
        }
    }
}
auto s_y_bc2 = make_vector<share*>(1, 1, 1, 64);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 64 ; _i10++) {
s_y_bc2[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_bc2[_i1][_i4][_i7][_i10] );
}
}
}
}
auto s_y_hc22 = make_vector<share*>(1, 14, 14, 64);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 14; j++)
    {
        for (uint32_t k = 0; k < 14; k++)
        {
            for (uint32_t l = 0; l < 64; l++)
            {
                s_y_tmp0 = create_new_share(s_y_hc21[i][j][k][l]->get_wires(), ycirc );
                uint32_t _tmp_237 = 2147483648 ;
                share * s_y__tmp_237 = ycirc->PutCONSGate( _tmp_237 ,bitlen);
                share * s_y_tmp_236 = ycirc->PutGTGate( s_y__tmp_237 , s_y_bc2[0][0][0][l] );
                vector<uint32_t> _vec239 = s_y_bc2[0][0][0][l]->get_wires();
                _vec239.erase( _vec239.begin(), _vec239.begin() + 8 );
                share *s_y_tmp_238 = create_new_share( _vec239 , ycirc );
                uint32_t _tmp_243 = 4294967295 ;
                share * s_y__tmp_243 = ycirc->PutCONSGate( _tmp_243 ,bitlen);
                share * s_y_tmp_242 = ycirc->PutXORGate( s_y_bc2[0][0][0][l] , s_y__tmp_243 );
                vector<uint32_t> _vec244 = s_y_tmp_242->get_wires();
                _vec244.erase( _vec244.begin(), _vec244.begin() + 8 );
                share *s_y_tmp_241 = create_new_share( _vec244 , ycirc );
                uint32_t _tmp_245 = 4294967295 ;
                share * s_y__tmp_245 = ycirc->PutCONSGate( _tmp_245 ,bitlen);
                share * s_y_tmp_240 = ycirc->PutXORGate( s_y_tmp_241 , s_y__tmp_245 );
                s_y_tmp1 = ycirc->PutMUXGate( s_y_tmp_238 , s_y_tmp_240 , s_y_tmp_236 );
                s_y_hc22[i][j][k][l] = ycirc->PutADDGate( s_y_tmp0 , s_y_tmp1 );
                s_y_hc22[i][j][k][l] = create_new_share(s_y_hc22[i][j][k][l]->get_wires(), ycirc );
            }
        }
    }
}
auto s_y_hc23 = make_vector<share*>(1, 14, 14, 64);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 14; j++)
    {
        for (uint32_t k = 0; k < 14; k++)
        {
            for (uint32_t l = 0; l < 64; l++)
            {
                uint32_t _tmp_247 = 2147483648 ;
                share * s_y__tmp_247 = ycirc->PutCONSGate( _tmp_247 ,bitlen);
                share * s_y_tmp_246 = ycirc->PutGTGate( s_y__tmp_247 , s_y_hc22[i][j][k][l] );
                uint32_t _tmp_248 = 0 ;
                share * s_y__tmp_248 = ycirc->PutCONSGate( _tmp_248 ,bitlen);
                s_y_hc23[i][j][k][l] = ycirc->PutMUXGate( s_y_hc22[i][j][k][l] , s_y__tmp_248 , s_y_tmp_246 );
            }
        }
    }
}
auto s_y_hp2 = make_vector<share*>(1, 7, 7, 64);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 7; j++)
    {
        for (uint32_t k = 0; k < 7; k++)
        {
            for (uint32_t l = 0; l < 64; l++)
            {
                uint32_t _tmp_250 = 2147483648 ;
                share * s_y__tmp_250 = ycirc->PutCONSGate( _tmp_250 ,bitlen);
                share * s_y_tmp_249 = ycirc->PutGTGate( s_y__tmp_250 , s_y_hc23[i][2*j][2*k][l] );
                uint32_t _tmp_253 = 2147483648 ;
                share * s_y__tmp_253 = ycirc->PutCONSGate( _tmp_253 ,bitlen);
                share * s_y_tmp_252 = ycirc->PutGTGate( s_y__tmp_253 , s_y_hc23[i][2*j][2*k+1][l] );
                share * s_y_tmp_255 = ycirc->PutGTGate( s_y_hc23[i][2*j][2*k][l] , s_y_hc23[i][2*j][2*k+1][l] );
                share * s_y_tmp_254 = ycirc->PutMUXGate( s_y_hc23[i][2*j][2*k][l] , s_y_hc23[i][2*j][2*k+1][l] , s_y_tmp_255 );
                share * s_y_tmp_251 = ycirc->PutMUXGate( s_y_tmp_254 , s_y_hc23[i][2*j][2*k][l] , s_y_tmp_252 );
                uint32_t _tmp_258 = 2147483648 ;
                share * s_y__tmp_258 = ycirc->PutCONSGate( _tmp_258 ,bitlen);
                share * s_y_tmp_257 = ycirc->PutGTGate( s_y__tmp_258 , s_y_hc23[i][2*j][2*k+1][l] );
                share * s_y_tmp_260 = ycirc->PutGTGate( s_y_hc23[i][2*j][2*k][l] , s_y_hc23[i][2*j][2*k+1][l] );
                share * s_y_tmp_259 = ycirc->PutMUXGate( s_y_hc23[i][2*j][2*k+1][l] , s_y_hc23[i][2*j][2*k][l] , s_y_tmp_260 );
                share * s_y_tmp_256 = ycirc->PutMUXGate( s_y_hc23[i][2*j][2*k+1][l] , s_y_tmp_259 , s_y_tmp_257 );
                s_y_tmp0 = ycirc->PutMUXGate( s_y_tmp_251 , s_y_tmp_256 , s_y_tmp_249 );
                uint32_t _tmp_262 = 2147483648 ;
                share * s_y__tmp_262 = ycirc->PutCONSGate( _tmp_262 ,bitlen);
                share * s_y_tmp_261 = ycirc->PutGTGate( s_y__tmp_262 , s_y_hc23[i][2*j+1][2*k][l] );
                uint32_t _tmp_265 = 2147483648 ;
                share * s_y__tmp_265 = ycirc->PutCONSGate( _tmp_265 ,bitlen);
                share * s_y_tmp_264 = ycirc->PutGTGate( s_y__tmp_265 , s_y_hc23[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_267 = ycirc->PutGTGate( s_y_hc23[i][2*j+1][2*k][l] , s_y_hc23[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_266 = ycirc->PutMUXGate( s_y_hc23[i][2*j+1][2*k][l] , s_y_hc23[i][2*j+1][2*k+1][l] , s_y_tmp_267 );
                share * s_y_tmp_263 = ycirc->PutMUXGate( s_y_tmp_266 , s_y_hc23[i][2*j+1][2*k][l] , s_y_tmp_264 );
                uint32_t _tmp_270 = 2147483648 ;
                share * s_y__tmp_270 = ycirc->PutCONSGate( _tmp_270 ,bitlen);
                share * s_y_tmp_269 = ycirc->PutGTGate( s_y__tmp_270 , s_y_hc23[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_272 = ycirc->PutGTGate( s_y_hc23[i][2*j+1][2*k][l] , s_y_hc23[i][2*j+1][2*k+1][l] );
                share * s_y_tmp_271 = ycirc->PutMUXGate( s_y_hc23[i][2*j+1][2*k+1][l] , s_y_hc23[i][2*j+1][2*k][l] , s_y_tmp_272 );
                share * s_y_tmp_268 = ycirc->PutMUXGate( s_y_hc23[i][2*j+1][2*k+1][l] , s_y_tmp_271 , s_y_tmp_269 );
                s_y_tmp1 = ycirc->PutMUXGate( s_y_tmp_263 , s_y_tmp_268 , s_y_tmp_261 );
                uint32_t _tmp_274 = 2147483648 ;
                share * s_y__tmp_274 = ycirc->PutCONSGate( _tmp_274 ,bitlen);
                share * s_y_tmp_273 = ycirc->PutGTGate( s_y__tmp_274 , s_y_tmp0 );
                uint32_t _tmp_277 = 2147483648 ;
                share * s_y__tmp_277 = ycirc->PutCONSGate( _tmp_277 ,bitlen);
                share * s_y_tmp_276 = ycirc->PutGTGate( s_y__tmp_277 , s_y_tmp1 );
                share * s_y_tmp_279 = ycirc->PutGTGate( s_y_tmp0 , s_y_tmp1 );
                share * s_y_tmp_278 = ycirc->PutMUXGate( s_y_tmp0 , s_y_tmp1 , s_y_tmp_279 );
                share * s_y_tmp_275 = ycirc->PutMUXGate( s_y_tmp_278 , s_y_tmp0 , s_y_tmp_276 );
                uint32_t _tmp_282 = 2147483648 ;
                share * s_y__tmp_282 = ycirc->PutCONSGate( _tmp_282 ,bitlen);
                share * s_y_tmp_281 = ycirc->PutGTGate( s_y__tmp_282 , s_y_tmp1 );
                share * s_y_tmp_284 = ycirc->PutGTGate( s_y_tmp0 , s_y_tmp1 );
                share * s_y_tmp_283 = ycirc->PutMUXGate( s_y_tmp1 , s_y_tmp0 , s_y_tmp_284 );
                share * s_y_tmp_280 = ycirc->PutMUXGate( s_y_tmp1 , s_y_tmp_283 , s_y_tmp_281 );
                s_y_hp2[i][j][k][l] = ycirc->PutMUXGate( s_y_tmp_275 , s_y_tmp_280 , s_y_tmp_273 );
            }
        }
    }
}
ii = 0 ;
s_y_ii = ycirc->PutCONSGate( ii ,bitlen);
jj = 0 ;
s_y_jj = ycirc->PutCONSGate( jj ,bitlen);
kk = 0 ;
s_y_kk = ycirc->PutCONSGate( kk ,bitlen);
ll = 0 ;
s_y_ll = ycirc->PutCONSGate( ll ,bitlen);
auto s_y_ht2 = make_vector<share*>(1, 1, 1, 3136);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 3136; l++)
            {
                s_y_ht2[i][j][k][l] = create_new_share(s_y_hp2[ii][jj][kk][ll]->get_wires(), ycirc );
                uint32_t _tmp_285 = 1 ;
                share * s_y__tmp_285 = ycirc->PutCONSGate( _tmp_285 ,bitlen);
                s_y_ll = ycirc->PutADDGate( s_y_ll , s_y__tmp_285 );
                uint32_t _tmp_287 = 64 ;
                share * s_y__tmp_287 = ycirc->PutCONSGate( _tmp_287 ,bitlen);
                share * s_y_tmp_286 = ycirc->PutEQGate( s_y_ll , s_y__tmp_287 );
                uint32_t _tmp_288 = 1 ;
                share * s_y__tmp_288 = ycirc->PutCONSGate( _tmp_288 ,bitlen);
                uint32_t _tmp_289 = 0 ;
                share * s_y__tmp_289 = ycirc->PutCONSGate( _tmp_289 ,bitlen);
                s_y_llover = ycirc->PutMUXGate( s_y__tmp_288 , s_y__tmp_289 , s_y_tmp_286 );
                uint32_t _tmp_291 = 1 ;
                share * s_y__tmp_291 = ycirc->PutCONSGate( _tmp_291 ,bitlen);
                share * s_y_tmp_290 = ycirc->PutEQGate( s_y_llover , s_y__tmp_291 );
                uint32_t _tmp_292 = 0 ;
                share * s_y__tmp_292 = ycirc->PutCONSGate( _tmp_292 ,bitlen);
                s_y_ll = ycirc->PutMUXGate( s_y__tmp_292 , s_y_ll , s_y_tmp_290 );
                uint32_t _tmp_294 = 1 ;
                share * s_y__tmp_294 = ycirc->PutCONSGate( _tmp_294 ,bitlen);
                share * s_y_tmp_293 = ycirc->PutEQGate( s_y_llover , s_y__tmp_294 );
                uint32_t _tmp_296 = 1 ;
                share * s_y__tmp_296 = ycirc->PutCONSGate( _tmp_296 ,bitlen);
                share * s_y_tmp_295 = ycirc->PutADDGate( s_y_kk , s_y__tmp_296 );
                s_y_kk = ycirc->PutMUXGate( s_y_tmp_295 , s_y_kk , s_y_tmp_293 );
                uint32_t _tmp_298 = 7 ;
                share * s_y__tmp_298 = ycirc->PutCONSGate( _tmp_298 ,bitlen);
                share * s_y_tmp_297 = ycirc->PutEQGate( s_y_kk , s_y__tmp_298 );
                uint32_t _tmp_299 = 1 ;
                share * s_y__tmp_299 = ycirc->PutCONSGate( _tmp_299 ,bitlen);
                uint32_t _tmp_300 = 0 ;
                share * s_y__tmp_300 = ycirc->PutCONSGate( _tmp_300 ,bitlen);
                s_y_kkover = ycirc->PutMUXGate( s_y__tmp_299 , s_y__tmp_300 , s_y_tmp_297 );
                uint32_t _tmp_302 = 1 ;
                share * s_y__tmp_302 = ycirc->PutCONSGate( _tmp_302 ,bitlen);
                share * s_y_tmp_301 = ycirc->PutEQGate( s_y_kkover , s_y__tmp_302 );
                uint32_t _tmp_303 = 0 ;
                share * s_y__tmp_303 = ycirc->PutCONSGate( _tmp_303 ,bitlen);
                s_y_kk = ycirc->PutMUXGate( s_y__tmp_303 , s_y_kk , s_y_tmp_301 );
                uint32_t _tmp_305 = 1 ;
                share * s_y__tmp_305 = ycirc->PutCONSGate( _tmp_305 ,bitlen);
                share * s_y_tmp_304 = ycirc->PutEQGate( s_y_kkover , s_y__tmp_305 );
                uint32_t _tmp_307 = 1 ;
                share * s_y__tmp_307 = ycirc->PutCONSGate( _tmp_307 ,bitlen);
                share * s_y_tmp_306 = ycirc->PutADDGate( s_y_jj , s_y__tmp_307 );
                s_y_jj = ycirc->PutMUXGate( s_y_tmp_306 , s_y_jj , s_y_tmp_304 );
                uint32_t _tmp_309 = 7 ;
                share * s_y__tmp_309 = ycirc->PutCONSGate( _tmp_309 ,bitlen);
                share * s_y_tmp_308 = ycirc->PutEQGate( s_y_jj , s_y__tmp_309 );
                uint32_t _tmp_310 = 1 ;
                share * s_y__tmp_310 = ycirc->PutCONSGate( _tmp_310 ,bitlen);
                uint32_t _tmp_311 = 0 ;
                share * s_y__tmp_311 = ycirc->PutCONSGate( _tmp_311 ,bitlen);
                s_y_jjover = ycirc->PutMUXGate( s_y__tmp_310 , s_y__tmp_311 , s_y_tmp_308 );
                uint32_t _tmp_313 = 1 ;
                share * s_y__tmp_313 = ycirc->PutCONSGate( _tmp_313 ,bitlen);
                share * s_y_tmp_312 = ycirc->PutEQGate( s_y_jjover , s_y__tmp_313 );
                uint32_t _tmp_314 = 0 ;
                share * s_y__tmp_314 = ycirc->PutCONSGate( _tmp_314 ,bitlen);
                s_y_jj = ycirc->PutMUXGate( s_y__tmp_314 , s_y_jj , s_y_tmp_312 );
                uint32_t _tmp_316 = 1 ;
                share * s_y__tmp_316 = ycirc->PutCONSGate( _tmp_316 ,bitlen);
                share * s_y_tmp_315 = ycirc->PutEQGate( s_y_jjover , s_y__tmp_316 );
                uint32_t _tmp_318 = 1 ;
                share * s_y__tmp_318 = ycirc->PutCONSGate( _tmp_318 ,bitlen);
                share * s_y_tmp_317 = ycirc->PutADDGate( s_y_ii , s_y__tmp_318 );
                s_y_ii = ycirc->PutMUXGate( s_y_tmp_317 , s_y_ii , s_y_tmp_315 );
            }
        }
    }
}
auto hf11Buf = make_vector<uint32_t>(1, 1, 1, 1024, 3136);
auto s_y_hf11Buf = make_vector<share*>(1, 1, 1, 1024, 3136);
for (uint32_t k = 0; k < 1; k++)
{
    for (uint32_t l = 0; l < 3136; l++)
    {
        uint32_t _tmp_320 = 2147483648 ;
        share * s_y__tmp_320 = ycirc->PutCONSGate( _tmp_320 ,bitlen);
        share * s_y_tmp_319 = ycirc->PutGTGate( s_y__tmp_320 , s_y_ht2[0][0][k][l] );
        vector<uint32_t> _vec322 = s_y_ht2[0][0][k][l]->get_wires();
        _vec322.erase( _vec322.begin(), _vec322.begin() + 15 );
        share *s_y_tmp_321 = create_new_share( _vec322 , ycirc );
        uint32_t _tmp_326 = 4294967295 ;
        share * s_y__tmp_326 = ycirc->PutCONSGate( _tmp_326 ,bitlen);
        share * s_y_tmp_325 = ycirc->PutXORGate( s_y_ht2[0][0][k][l] , s_y__tmp_326 );
        vector<uint32_t> _vec327 = s_y_tmp_325->get_wires();
        _vec327.erase( _vec327.begin(), _vec327.begin() + 15 );
        share *s_y_tmp_324 = create_new_share( _vec327 , ycirc );
        uint32_t _tmp_328 = 4294967295 ;
        share * s_y__tmp_328 = ycirc->PutCONSGate( _tmp_328 ,bitlen);
        share * s_y_tmp_323 = ycirc->PutXORGate( s_y_tmp_324 , s_y__tmp_328 );
        s_y_ht2[0][0][k][l] = ycirc->PutMUXGate( s_y_tmp_321 , s_y_tmp_323 , s_y_tmp_319 );
    }
}
auto s_y_Wf1 = make_vector<share*>(1, 1, 3136, 1024);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 3136 ; _i7++) {
for (int _i10 = 0; _i10 < 1024 ; _i10++) {
s_y_Wf1[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_Wf1[_i1][_i4][_i7][_i10] );
}
}
}
}
for (uint32_t k = 0; k < 3136; k++)
{
    for (uint32_t l = 0; l < 1024; l++)
    {
        uint32_t _tmp_330 = 2147483648 ;
        share * s_y__tmp_330 = ycirc->PutCONSGate( _tmp_330 ,bitlen);
        share * s_y_tmp_329 = ycirc->PutGTGate( s_y__tmp_330 , s_y_Wf1[0][0][k][l] );
        vector<uint32_t> _vec332 = s_y_Wf1[0][0][k][l]->get_wires();
        _vec332.erase( _vec332.begin(), _vec332.begin() + 15 );
        share *s_y_tmp_331 = create_new_share( _vec332 , ycirc );
        uint32_t _tmp_336 = 4294967295 ;
        share * s_y__tmp_336 = ycirc->PutCONSGate( _tmp_336 ,bitlen);
        share * s_y_tmp_335 = ycirc->PutXORGate( s_y_Wf1[0][0][k][l] , s_y__tmp_336 );
        vector<uint32_t> _vec337 = s_y_tmp_335->get_wires();
        _vec337.erase( _vec337.begin(), _vec337.begin() + 15 );
        share *s_y_tmp_334 = create_new_share( _vec337 , ycirc );
        uint32_t _tmp_338 = 4294967295 ;
        share * s_y__tmp_338 = ycirc->PutCONSGate( _tmp_338 ,bitlen);
        share * s_y_tmp_333 = ycirc->PutXORGate( s_y_tmp_334 , s_y__tmp_338 );
        s_y_Wf1[0][0][k][l] = ycirc->PutMUXGate( s_y_tmp_331 , s_y_tmp_333 , s_y_tmp_329 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 3136 ; _i10++) {
s_a_ht2[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_ht2[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 3136 ; _i7++) {
for (int _i10 = 0; _i10 < 1024 ; _i10++) {
s_a_Wf1[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_Wf1[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
auto s_a_hf11Buf = make_vector<share*>(1, 1, 1, 1024, 3136);
for (uint32_t k = 0; k < 1; k++)
{
    for (uint32_t l = 0; l < 1024; l++)
    {
        for (uint32_t m = 0; m < 3136; m++)
        {
            s_a_hf11Buf[0][0][k][l][m] = acirc->PutMULGate( s_a_ht2[0][0][k][m] , s_a_Wf1[0][0][m][l] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 1024 ; _i10++) {
for (int _i13 = 0; _i13 < 3136 ; _i13++) {
s_y_hf11Buf[_i1][_i4][_i7][_i10][_i13] = ycirc->PutA2YGate( s_a_hf11Buf[_i1][_i4][_i7][_i10][_i13] );
}
}
}
}
}
auto s_y_hf11 = make_vector<share*>(1, 1, 1, 1024);
for (uint32_t k = 0; k < 1; k++)
{
    for (uint32_t l = 0; l < 1024; l++)
    {
        N = 3136 ;
        s_y_N = ycirc->PutCONSGate( N ,bitlen);
        for (uint32_t a = 0; a < 1; a++)
        {
            mtmp = 0 ;
            s_y_mtmp = ycirc->PutCONSGate( mtmp ,bitlen);
            for (uint32_t m = 0; m < 3136; m++)
            {
                vector<uint32_t> _vec341 = s_y_N->get_wires();
                _vec341.erase( _vec341.begin(), _vec341.begin() + 1 );
                share *s_y_tmp_340 = create_new_share( _vec341 , ycirc );
                share * s_y_tmp_339 = ycirc->PutGTGate( s_y_tmp_340 , s_y_mtmp );
                share * s_y_tmp_344 = ycirc->PutADDGate( s_y_hf11Buf[0][0][k][l][2*mtmp] , s_y_hf11Buf[0][0][k][l][2*mtmp+1] );
                uint32_t _tmp_345 = 2147483648 ;
                share * s_y__tmp_345 = ycirc->PutCONSGate( _tmp_345 ,bitlen);
                share * s_y_tmp_343 = ycirc->PutGTGate( s_y__tmp_345 , s_y_tmp_344 );
                share * s_y_tmp_347 = ycirc->PutADDGate( s_y_hf11Buf[0][0][k][l][2*mtmp] , s_y_hf11Buf[0][0][k][l][2*mtmp+1] );
                vector<uint32_t> _vec348 = s_y_tmp_347->get_wires();
                _vec348.erase( _vec348.begin(), _vec348.begin() + 1 );
                share *s_y_tmp_346 = create_new_share( _vec348 , ycirc );
                share * s_y_tmp_352 = ycirc->PutADDGate( s_y_hf11Buf[0][0][k][l][2*mtmp] , s_y_hf11Buf[0][0][k][l][2*mtmp+1] );
                uint32_t _tmp_353 = 4294967295 ;
                share * s_y__tmp_353 = ycirc->PutCONSGate( _tmp_353 ,bitlen);
                share * s_y_tmp_351 = ycirc->PutXORGate( s_y_tmp_352 , s_y__tmp_353 );
                vector<uint32_t> _vec354 = s_y_tmp_351->get_wires();
                _vec354.erase( _vec354.begin(), _vec354.begin() + 1 );
                share *s_y_tmp_350 = create_new_share( _vec354 , ycirc );
                uint32_t _tmp_355 = 4294967295 ;
                share * s_y__tmp_355 = ycirc->PutCONSGate( _tmp_355 ,bitlen);
                share * s_y_tmp_349 = ycirc->PutXORGate( s_y_tmp_350 , s_y__tmp_355 );
                share * s_y_tmp_342 = ycirc->PutMUXGate( s_y_tmp_346 , s_y_tmp_349 , s_y_tmp_343 );
                s_y_hf11Buf[0][0][k][l][mtmp] = ycirc->PutMUXGate( s_y_tmp_342 , s_y_hf11Buf[0][0][k][l][mtmp] , s_y_tmp_339 );
                uint32_t _tmp_356 = 1 ;
                share * s_y__tmp_356 = ycirc->PutCONSGate( _tmp_356 ,bitlen);
                s_y_mtmp = ycirc->PutADDGate( s_y_mtmp , s_y__tmp_356 );
            }
            uint32_t _tmp_359 = 1 ;
            share * s_y__tmp_359 = ycirc->PutCONSGate( _tmp_359 ,bitlen);
            share * s_y_tmp_358 = ycirc->PutANDGate( s_y_N , s_y__tmp_359 );
            uint32_t _tmp_360 = 1 ;
            share * s_y__tmp_360 = ycirc->PutCONSGate( _tmp_360 ,bitlen);
            share * s_y_tmp_357 = ycirc->PutEQGate( s_y_tmp_358 , s_y__tmp_360 );
            uint32_t _tmp_363 = 2147483648 ;
            share * s_y__tmp_363 = ycirc->PutCONSGate( _tmp_363 ,bitlen);
            share * s_y_tmp_362 = ycirc->PutGTGate( s_y__tmp_363 , s_y_hf11Buf[0][0][k][l][N-1] );
            vector<uint32_t> _vec365 = s_y_hf11Buf[0][0][k][l][N-1]->get_wires();
            _vec365.erase( _vec365.begin(), _vec365.begin() + 1 );
            share *s_y_tmp_364 = create_new_share( _vec365 , ycirc );
            uint32_t _tmp_369 = 4294967295 ;
            share * s_y__tmp_369 = ycirc->PutCONSGate( _tmp_369 ,bitlen);
            share * s_y_tmp_368 = ycirc->PutXORGate( s_y_hf11Buf[0][0][k][l][N-1] , s_y__tmp_369 );
            vector<uint32_t> _vec370 = s_y_tmp_368->get_wires();
            _vec370.erase( _vec370.begin(), _vec370.begin() + 1 );
            share *s_y_tmp_367 = create_new_share( _vec370 , ycirc );
            uint32_t _tmp_371 = 4294967295 ;
            share * s_y__tmp_371 = ycirc->PutCONSGate( _tmp_371 ,bitlen);
            share * s_y_tmp_366 = ycirc->PutXORGate( s_y_tmp_367 , s_y__tmp_371 );
            share * s_y_tmp_361 = ycirc->PutMUXGate( s_y_tmp_364 , s_y_tmp_366 , s_y_tmp_362 );
            uint32_t _tmp_372 = 0 ;
            share * s_y__tmp_372 = ycirc->PutCONSGate( _tmp_372 ,bitlen);
            s_y_hf11Buf[0][0][k][l][N>>1] = ycirc->PutMUXGate( s_y_tmp_361 , s_y__tmp_372 , s_y_tmp_357 );
            uint32_t _tmp_374 = 1 ;
            share * s_y__tmp_374 = ycirc->PutCONSGate( _tmp_374 ,bitlen);
            share * s_y_tmp_373 = ycirc->PutADDGate( s_y_N , s_y__tmp_374 );
            vector<uint32_t> _vec375 = s_y_tmp_373->get_wires();
            _vec375.erase( _vec375.begin(), _vec375.begin() + 1 );
            s_y_N = create_new_share( _vec375 , ycirc );
        }
        for (uint32_t a = 0; a < 11; a++)
        {
            mtmp = 0 ;
            s_y_mtmp = ycirc->PutCONSGate( mtmp ,bitlen);
            for (uint32_t m = 0; m < 3136; m++)
            {
                vector<uint32_t> _vec378 = s_y_N->get_wires();
                _vec378.erase( _vec378.begin(), _vec378.begin() + 1 );
                share *s_y_tmp_377 = create_new_share( _vec378 , ycirc );
                share * s_y_tmp_376 = ycirc->PutGTGate( s_y_tmp_377 , s_y_mtmp );
                share * s_y_tmp_379 = ycirc->PutADDGate( s_y_hf11Buf[0][0][k][l][2*mtmp] , s_y_hf11Buf[0][0][k][l][2*mtmp+1] );
                s_y_hf11Buf[0][0][k][l][mtmp] = ycirc->PutMUXGate( s_y_tmp_379 , s_y_hf11Buf[0][0][k][l][mtmp] , s_y_tmp_376 );
                uint32_t _tmp_380 = 1 ;
                share * s_y__tmp_380 = ycirc->PutCONSGate( _tmp_380 ,bitlen);
                s_y_mtmp = ycirc->PutADDGate( s_y_mtmp , s_y__tmp_380 );
            }
            uint32_t _tmp_383 = 1 ;
            share * s_y__tmp_383 = ycirc->PutCONSGate( _tmp_383 ,bitlen);
            share * s_y_tmp_382 = ycirc->PutANDGate( s_y_N , s_y__tmp_383 );
            uint32_t _tmp_384 = 1 ;
            share * s_y__tmp_384 = ycirc->PutCONSGate( _tmp_384 ,bitlen);
            share * s_y_tmp_381 = ycirc->PutEQGate( s_y_tmp_382 , s_y__tmp_384 );
            uint32_t _tmp_385 = 0 ;
            share * s_y__tmp_385 = ycirc->PutCONSGate( _tmp_385 ,bitlen);
            s_y_hf11Buf[0][0][k][l][N>>1] = ycirc->PutMUXGate( s_y_hf11Buf[0][0][k][l][N-1] , s_y__tmp_385 , s_y_tmp_381 );
            uint32_t _tmp_387 = 1 ;
            share * s_y__tmp_387 = ycirc->PutCONSGate( _tmp_387 ,bitlen);
            share * s_y_tmp_386 = ycirc->PutADDGate( s_y_N , s_y__tmp_387 );
            vector<uint32_t> _vec388 = s_y_tmp_386->get_wires();
            _vec388.erase( _vec388.begin(), _vec388.begin() + 1 );
            s_y_N = create_new_share( _vec388 , ycirc );
        }
        s_y_hf11[0][0][k][l] = create_new_share(s_y_hf11Buf[0][0][k][l][0]->get_wires(), ycirc );
    }
}
auto s_y_bf1 = make_vector<share*>(1, 1, 1, 1024);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 1024 ; _i10++) {
s_y_bf1[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_bf1[_i1][_i4][_i7][_i10] );
}
}
}
}
auto s_y_hf12 = make_vector<share*>(1, 1, 1, 1024);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 1024; l++)
            {
                s_y_tmp0 = create_new_share(s_y_hf11[i][j][k][l]->get_wires(), ycirc );
                uint32_t _tmp_390 = 2147483648 ;
                share * s_y__tmp_390 = ycirc->PutCONSGate( _tmp_390 ,bitlen);
                share * s_y_tmp_389 = ycirc->PutGTGate( s_y__tmp_390 , s_y_bf1[0][0][0][l] );
                vector<uint32_t> _vec392 = s_y_bf1[0][0][0][l]->get_wires();
                _vec392.erase( _vec392.begin(), _vec392.begin() + 8 );
                share *s_y_tmp_391 = create_new_share( _vec392 , ycirc );
                uint32_t _tmp_396 = 4294967295 ;
                share * s_y__tmp_396 = ycirc->PutCONSGate( _tmp_396 ,bitlen);
                share * s_y_tmp_395 = ycirc->PutXORGate( s_y_bf1[0][0][0][l] , s_y__tmp_396 );
                vector<uint32_t> _vec397 = s_y_tmp_395->get_wires();
                _vec397.erase( _vec397.begin(), _vec397.begin() + 8 );
                share *s_y_tmp_394 = create_new_share( _vec397 , ycirc );
                uint32_t _tmp_398 = 4294967295 ;
                share * s_y__tmp_398 = ycirc->PutCONSGate( _tmp_398 ,bitlen);
                share * s_y_tmp_393 = ycirc->PutXORGate( s_y_tmp_394 , s_y__tmp_398 );
                s_y_tmp1 = ycirc->PutMUXGate( s_y_tmp_391 , s_y_tmp_393 , s_y_tmp_389 );
                s_y_hf12[i][j][k][l] = ycirc->PutADDGate( s_y_tmp0 , s_y_tmp1 );
                s_y_hf12[i][j][k][l] = create_new_share(s_y_hf12[i][j][k][l]->get_wires(), ycirc );
            }
        }
    }
}
auto s_y_hf13 = make_vector<share*>(1, 1, 1, 1024);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 1024; l++)
            {
                uint32_t _tmp_400 = 2147483648 ;
                share * s_y__tmp_400 = ycirc->PutCONSGate( _tmp_400 ,bitlen);
                share * s_y_tmp_399 = ycirc->PutGTGate( s_y__tmp_400 , s_y_hf12[i][j][k][l] );
                uint32_t _tmp_401 = 0 ;
                share * s_y__tmp_401 = ycirc->PutCONSGate( _tmp_401 ,bitlen);
                s_y_hf13[i][j][k][l] = ycirc->PutMUXGate( s_y_hf12[i][j][k][l] , s_y__tmp_401 , s_y_tmp_399 );
            }
        }
    }
}
auto hf21Buf = make_vector<uint32_t>(1, 1, 1, 10, 1024);
auto s_y_hf21Buf = make_vector<share*>(1, 1, 1, 10, 1024);
for (uint32_t k = 0; k < 1; k++)
{
    for (uint32_t l = 0; l < 1024; l++)
    {
        uint32_t _tmp_403 = 2147483648 ;
        share * s_y__tmp_403 = ycirc->PutCONSGate( _tmp_403 ,bitlen);
        share * s_y_tmp_402 = ycirc->PutGTGate( s_y__tmp_403 , s_y_hf13[0][0][k][l] );
        vector<uint32_t> _vec405 = s_y_hf13[0][0][k][l]->get_wires();
        _vec405.erase( _vec405.begin(), _vec405.begin() + 15 );
        share *s_y_tmp_404 = create_new_share( _vec405 , ycirc );
        uint32_t _tmp_409 = 4294967295 ;
        share * s_y__tmp_409 = ycirc->PutCONSGate( _tmp_409 ,bitlen);
        share * s_y_tmp_408 = ycirc->PutXORGate( s_y_hf13[0][0][k][l] , s_y__tmp_409 );
        vector<uint32_t> _vec410 = s_y_tmp_408->get_wires();
        _vec410.erase( _vec410.begin(), _vec410.begin() + 15 );
        share *s_y_tmp_407 = create_new_share( _vec410 , ycirc );
        uint32_t _tmp_411 = 4294967295 ;
        share * s_y__tmp_411 = ycirc->PutCONSGate( _tmp_411 ,bitlen);
        share * s_y_tmp_406 = ycirc->PutXORGate( s_y_tmp_407 , s_y__tmp_411 );
        s_y_hf13[0][0][k][l] = ycirc->PutMUXGate( s_y_tmp_404 , s_y_tmp_406 , s_y_tmp_402 );
    }
}
auto s_y_Wf2 = make_vector<share*>(1, 1, 1024, 10);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1024 ; _i7++) {
for (int _i10 = 0; _i10 < 10 ; _i10++) {
s_y_Wf2[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_Wf2[_i1][_i4][_i7][_i10] );
}
}
}
}
for (uint32_t k = 0; k < 1024; k++)
{
    for (uint32_t l = 0; l < 10; l++)
    {
        uint32_t _tmp_413 = 2147483648 ;
        share * s_y__tmp_413 = ycirc->PutCONSGate( _tmp_413 ,bitlen);
        share * s_y_tmp_412 = ycirc->PutGTGate( s_y__tmp_413 , s_y_Wf2[0][0][k][l] );
        vector<uint32_t> _vec415 = s_y_Wf2[0][0][k][l]->get_wires();
        _vec415.erase( _vec415.begin(), _vec415.begin() + 15 );
        share *s_y_tmp_414 = create_new_share( _vec415 , ycirc );
        uint32_t _tmp_419 = 4294967295 ;
        share * s_y__tmp_419 = ycirc->PutCONSGate( _tmp_419 ,bitlen);
        share * s_y_tmp_418 = ycirc->PutXORGate( s_y_Wf2[0][0][k][l] , s_y__tmp_419 );
        vector<uint32_t> _vec420 = s_y_tmp_418->get_wires();
        _vec420.erase( _vec420.begin(), _vec420.begin() + 15 );
        share *s_y_tmp_417 = create_new_share( _vec420 , ycirc );
        uint32_t _tmp_421 = 4294967295 ;
        share * s_y__tmp_421 = ycirc->PutCONSGate( _tmp_421 ,bitlen);
        share * s_y_tmp_416 = ycirc->PutXORGate( s_y_tmp_417 , s_y__tmp_421 );
        s_y_Wf2[0][0][k][l] = ycirc->PutMUXGate( s_y_tmp_414 , s_y_tmp_416 , s_y_tmp_412 );
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 1024 ; _i10++) {
s_a_hf13[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_hf13[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1024 ; _i7++) {
for (int _i10 = 0; _i10 < 10 ; _i10++) {
s_a_Wf2[_i1][_i4][_i7][_i10] = acirc->PutY2AGate( s_y_Wf2[_i1][_i4][_i7][_i10] ,bcirc);
}
}
}
}
auto s_a_hf21Buf = make_vector<share*>(1, 1, 1, 10, 1024);
for (uint32_t k = 0; k < 1; k++)
{
    for (uint32_t l = 0; l < 10; l++)
    {
        for (uint32_t m = 0; m < 1024; m++)
        {
            s_a_hf21Buf[0][0][k][l][m] = acirc->PutMULGate( s_a_hf13[0][0][k][m] , s_a_Wf2[0][0][m][l] );
        }
    }
}
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 10 ; _i10++) {
for (int _i13 = 0; _i13 < 1024 ; _i13++) {
s_y_hf21Buf[_i1][_i4][_i7][_i10][_i13] = ycirc->PutA2YGate( s_a_hf21Buf[_i1][_i4][_i7][_i10][_i13] );
}
}
}
}
}
auto s_y_hf21 = make_vector<share*>(1, 1, 1, 10);
for (uint32_t k = 0; k < 1; k++)
{
    for (uint32_t l = 0; l < 10; l++)
    {
        N = 1024 ;
        s_y_N = ycirc->PutCONSGate( N ,bitlen);
        for (uint32_t a = 0; a < 1; a++)
        {
            mtmp = 0 ;
            s_y_mtmp = ycirc->PutCONSGate( mtmp ,bitlen);
            for (uint32_t m = 0; m < 1024; m++)
            {
                vector<uint32_t> _vec424 = s_y_N->get_wires();
                _vec424.erase( _vec424.begin(), _vec424.begin() + 1 );
                share *s_y_tmp_423 = create_new_share( _vec424 , ycirc );
                share * s_y_tmp_422 = ycirc->PutGTGate( s_y_tmp_423 , s_y_mtmp );
                share * s_y_tmp_427 = ycirc->PutADDGate( s_y_hf21Buf[0][0][k][l][2*mtmp] , s_y_hf21Buf[0][0][k][l][2*mtmp+1] );
                uint32_t _tmp_428 = 2147483648 ;
                share * s_y__tmp_428 = ycirc->PutCONSGate( _tmp_428 ,bitlen);
                share * s_y_tmp_426 = ycirc->PutGTGate( s_y__tmp_428 , s_y_tmp_427 );
                share * s_y_tmp_430 = ycirc->PutADDGate( s_y_hf21Buf[0][0][k][l][2*mtmp] , s_y_hf21Buf[0][0][k][l][2*mtmp+1] );
                vector<uint32_t> _vec431 = s_y_tmp_430->get_wires();
                _vec431.erase( _vec431.begin(), _vec431.begin() + 1 );
                share *s_y_tmp_429 = create_new_share( _vec431 , ycirc );
                share * s_y_tmp_435 = ycirc->PutADDGate( s_y_hf21Buf[0][0][k][l][2*mtmp] , s_y_hf21Buf[0][0][k][l][2*mtmp+1] );
                uint32_t _tmp_436 = 4294967295 ;
                share * s_y__tmp_436 = ycirc->PutCONSGate( _tmp_436 ,bitlen);
                share * s_y_tmp_434 = ycirc->PutXORGate( s_y_tmp_435 , s_y__tmp_436 );
                vector<uint32_t> _vec437 = s_y_tmp_434->get_wires();
                _vec437.erase( _vec437.begin(), _vec437.begin() + 1 );
                share *s_y_tmp_433 = create_new_share( _vec437 , ycirc );
                uint32_t _tmp_438 = 4294967295 ;
                share * s_y__tmp_438 = ycirc->PutCONSGate( _tmp_438 ,bitlen);
                share * s_y_tmp_432 = ycirc->PutXORGate( s_y_tmp_433 , s_y__tmp_438 );
                share * s_y_tmp_425 = ycirc->PutMUXGate( s_y_tmp_429 , s_y_tmp_432 , s_y_tmp_426 );
                s_y_hf21Buf[0][0][k][l][mtmp] = ycirc->PutMUXGate( s_y_tmp_425 , s_y_hf21Buf[0][0][k][l][mtmp] , s_y_tmp_422 );
                uint32_t _tmp_439 = 1 ;
                share * s_y__tmp_439 = ycirc->PutCONSGate( _tmp_439 ,bitlen);
                s_y_mtmp = ycirc->PutADDGate( s_y_mtmp , s_y__tmp_439 );
            }
            uint32_t _tmp_442 = 1 ;
            share * s_y__tmp_442 = ycirc->PutCONSGate( _tmp_442 ,bitlen);
            share * s_y_tmp_441 = ycirc->PutANDGate( s_y_N , s_y__tmp_442 );
            uint32_t _tmp_443 = 1 ;
            share * s_y__tmp_443 = ycirc->PutCONSGate( _tmp_443 ,bitlen);
            share * s_y_tmp_440 = ycirc->PutEQGate( s_y_tmp_441 , s_y__tmp_443 );
            uint32_t _tmp_446 = 2147483648 ;
            share * s_y__tmp_446 = ycirc->PutCONSGate( _tmp_446 ,bitlen);
            share * s_y_tmp_445 = ycirc->PutGTGate( s_y__tmp_446 , s_y_hf21Buf[0][0][k][l][N-1] );
            vector<uint32_t> _vec448 = s_y_hf21Buf[0][0][k][l][N-1]->get_wires();
            _vec448.erase( _vec448.begin(), _vec448.begin() + 1 );
            share *s_y_tmp_447 = create_new_share( _vec448 , ycirc );
            uint32_t _tmp_452 = 4294967295 ;
            share * s_y__tmp_452 = ycirc->PutCONSGate( _tmp_452 ,bitlen);
            share * s_y_tmp_451 = ycirc->PutXORGate( s_y_hf21Buf[0][0][k][l][N-1] , s_y__tmp_452 );
            vector<uint32_t> _vec453 = s_y_tmp_451->get_wires();
            _vec453.erase( _vec453.begin(), _vec453.begin() + 1 );
            share *s_y_tmp_450 = create_new_share( _vec453 , ycirc );
            uint32_t _tmp_454 = 4294967295 ;
            share * s_y__tmp_454 = ycirc->PutCONSGate( _tmp_454 ,bitlen);
            share * s_y_tmp_449 = ycirc->PutXORGate( s_y_tmp_450 , s_y__tmp_454 );
            share * s_y_tmp_444 = ycirc->PutMUXGate( s_y_tmp_447 , s_y_tmp_449 , s_y_tmp_445 );
            uint32_t _tmp_455 = 0 ;
            share * s_y__tmp_455 = ycirc->PutCONSGate( _tmp_455 ,bitlen);
            s_y_hf21Buf[0][0][k][l][N>>1] = ycirc->PutMUXGate( s_y_tmp_444 , s_y__tmp_455 , s_y_tmp_440 );
            uint32_t _tmp_457 = 1 ;
            share * s_y__tmp_457 = ycirc->PutCONSGate( _tmp_457 ,bitlen);
            share * s_y_tmp_456 = ycirc->PutADDGate( s_y_N , s_y__tmp_457 );
            vector<uint32_t> _vec458 = s_y_tmp_456->get_wires();
            _vec458.erase( _vec458.begin(), _vec458.begin() + 1 );
            s_y_N = create_new_share( _vec458 , ycirc );
        }
        for (uint32_t a = 0; a < 9; a++)
        {
            mtmp = 0 ;
            s_y_mtmp = ycirc->PutCONSGate( mtmp ,bitlen);
            for (uint32_t m = 0; m < 1024; m++)
            {
                vector<uint32_t> _vec461 = s_y_N->get_wires();
                _vec461.erase( _vec461.begin(), _vec461.begin() + 1 );
                share *s_y_tmp_460 = create_new_share( _vec461 , ycirc );
                share * s_y_tmp_459 = ycirc->PutGTGate( s_y_tmp_460 , s_y_mtmp );
                share * s_y_tmp_462 = ycirc->PutADDGate( s_y_hf21Buf[0][0][k][l][2*mtmp] , s_y_hf21Buf[0][0][k][l][2*mtmp+1] );
                s_y_hf21Buf[0][0][k][l][mtmp] = ycirc->PutMUXGate( s_y_tmp_462 , s_y_hf21Buf[0][0][k][l][mtmp] , s_y_tmp_459 );
                uint32_t _tmp_463 = 1 ;
                share * s_y__tmp_463 = ycirc->PutCONSGate( _tmp_463 ,bitlen);
                s_y_mtmp = ycirc->PutADDGate( s_y_mtmp , s_y__tmp_463 );
            }
            uint32_t _tmp_466 = 1 ;
            share * s_y__tmp_466 = ycirc->PutCONSGate( _tmp_466 ,bitlen);
            share * s_y_tmp_465 = ycirc->PutANDGate( s_y_N , s_y__tmp_466 );
            uint32_t _tmp_467 = 1 ;
            share * s_y__tmp_467 = ycirc->PutCONSGate( _tmp_467 ,bitlen);
            share * s_y_tmp_464 = ycirc->PutEQGate( s_y_tmp_465 , s_y__tmp_467 );
            uint32_t _tmp_468 = 0 ;
            share * s_y__tmp_468 = ycirc->PutCONSGate( _tmp_468 ,bitlen);
            s_y_hf21Buf[0][0][k][l][N>>1] = ycirc->PutMUXGate( s_y_hf21Buf[0][0][k][l][N-1] , s_y__tmp_468 , s_y_tmp_464 );
            uint32_t _tmp_470 = 1 ;
            share * s_y__tmp_470 = ycirc->PutCONSGate( _tmp_470 ,bitlen);
            share * s_y_tmp_469 = ycirc->PutADDGate( s_y_N , s_y__tmp_470 );
            vector<uint32_t> _vec471 = s_y_tmp_469->get_wires();
            _vec471.erase( _vec471.begin(), _vec471.begin() + 1 );
            s_y_N = create_new_share( _vec471 , ycirc );
        }
        s_y_hf21[0][0][k][l] = create_new_share(s_y_hf21Buf[0][0][k][l][0]->get_wires(), ycirc );
    }
}
auto s_y_bf2 = make_vector<share*>(1, 1, 1, 10);
for (int _i1 = 0; _i1 < 1 ; _i1++) {
for (int _i4 = 0; _i4 < 1 ; _i4++) {
for (int _i7 = 0; _i7 < 1 ; _i7++) {
for (int _i10 = 0; _i10 < 10 ; _i10++) {
s_y_bf2[_i1][_i4][_i7][_i10] = ycirc->PutA2YGate( s_a_bf2[_i1][_i4][_i7][_i10] );
}
}
}
}
auto s_y_hf22 = make_vector<share*>(1, 1, 1, 10);
for (uint32_t i = 0; i < 1; i++)
{
    for (uint32_t j = 0; j < 1; j++)
    {
        for (uint32_t k = 0; k < 1; k++)
        {
            for (uint32_t l = 0; l < 10; l++)
            {
                s_y_tmp0 = create_new_share(s_y_hf21[i][j][k][l]->get_wires(), ycirc );
                uint32_t _tmp_473 = 2147483648 ;
                share * s_y__tmp_473 = ycirc->PutCONSGate( _tmp_473 ,bitlen);
                share * s_y_tmp_472 = ycirc->PutGTGate( s_y__tmp_473 , s_y_bf2[0][0][0][l] );
                vector<uint32_t> _vec475 = s_y_bf2[0][0][0][l]->get_wires();
                _vec475.erase( _vec475.begin(), _vec475.begin() + 7 );
                share *s_y_tmp_474 = create_new_share( _vec475 , ycirc );
                uint32_t _tmp_479 = 4294967295 ;
                share * s_y__tmp_479 = ycirc->PutCONSGate( _tmp_479 ,bitlen);
                share * s_y_tmp_478 = ycirc->PutXORGate( s_y_bf2[0][0][0][l] , s_y__tmp_479 );
                vector<uint32_t> _vec480 = s_y_tmp_478->get_wires();
                _vec480.erase( _vec480.begin(), _vec480.begin() + 7 );
                share *s_y_tmp_477 = create_new_share( _vec480 , ycirc );
                uint32_t _tmp_481 = 4294967295 ;
                share * s_y__tmp_481 = ycirc->PutCONSGate( _tmp_481 ,bitlen);
                share * s_y_tmp_476 = ycirc->PutXORGate( s_y_tmp_477 , s_y__tmp_481 );
                s_y_tmp1 = ycirc->PutMUXGate( s_y_tmp_474 , s_y_tmp_476 , s_y_tmp_472 );
                s_y_hf22[i][j][k][l] = ycirc->PutADDGate( s_y_tmp0 , s_y_tmp1 );
                s_y_hf22[i][j][k][l] = create_new_share(s_y_hf22[i][j][k][l]->get_wires(), ycirc );
            }
        }
    }
}
maxind = 0 ;
share *s_y_maxind = ycirc->PutCONSGate( maxind ,bitlen);
share *s_y_maxval = create_new_share(s_y_hf22[0][0][0][0]->get_wires(), ycirc );
cnt = 0 ;
share *s_y_cnt = ycirc->PutCONSGate( cnt ,bitlen);
share * s_y_tmp ;
for (uint32_t l = 0; l < 10; l++)
{
    uint32_t _tmp_483 = 2147483648 ;
    share * s_y__tmp_483 = ycirc->PutCONSGate( _tmp_483 ,bitlen);
    share * s_y_tmp_482 = ycirc->PutGTGate( s_y__tmp_483 , s_y_maxval );
    uint32_t _tmp_486 = 2147483648 ;
    share * s_y__tmp_486 = ycirc->PutCONSGate( _tmp_486 ,bitlen);
    share * s_y_tmp_485 = ycirc->PutGTGate( s_y__tmp_486 , s_y_hf22[0][0][0][l] );
    share * s_y_tmp_488 = ycirc->PutGTGate( s_y_maxval , s_y_hf22[0][0][0][l] );
    share * s_y_tmp_487 = ycirc->PutMUXGate( s_y_maxval , s_y_hf22[0][0][0][l] , s_y_tmp_488 );
    share * s_y_tmp_484 = ycirc->PutMUXGate( s_y_tmp_487 , s_y_maxval , s_y_tmp_485 );
    uint32_t _tmp_491 = 2147483648 ;
    share * s_y__tmp_491 = ycirc->PutCONSGate( _tmp_491 ,bitlen);
    share * s_y_tmp_490 = ycirc->PutGTGate( s_y__tmp_491 , s_y_hf22[0][0][0][l] );
    share * s_y_tmp_493 = ycirc->PutGTGate( s_y_maxval , s_y_hf22[0][0][0][l] );
    share * s_y_tmp_492 = ycirc->PutMUXGate( s_y_hf22[0][0][0][l] , s_y_maxval , s_y_tmp_493 );
    share * s_y_tmp_489 = ycirc->PutMUXGate( s_y_hf22[0][0][0][l] , s_y_tmp_492 , s_y_tmp_490 );
    s_y_tmp = ycirc->PutMUXGate( s_y_tmp_484 , s_y_tmp_489 , s_y_tmp_482 );
    share * s_y_tmp_494 = ycirc->PutEQGate( s_y_tmp , s_y_maxval );
    s_y_maxind = ycirc->PutMUXGate( s_y_maxind , s_y_cnt , s_y_tmp_494 );
    s_y_maxval = create_new_share(s_y_tmp->get_wires(), ycirc );
    uint32_t _tmp_495 = 1 ;
    share * s_y__tmp_495 = ycirc->PutCONSGate( _tmp_495 ,bitlen);
    s_y_cnt = ycirc->PutADDGate( s_y_cnt , s_y__tmp_495 );
}
share * s_y_tmp_496 = ycirc->PutOUTGate( s_y_maxind , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_496->get_clear_value<uint32_t>();
