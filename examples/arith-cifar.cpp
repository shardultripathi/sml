ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 130000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto x = make_vector<uint32_t>(27, 1024);
auto s_a_x = make_vector<share*>(27, 1024);
auto w1 = make_vector<uint32_t>(64, 27);
auto s_a_w1 = make_vector<share*>(64, 27);
auto c1out = make_vector<uint32_t>(64, 1024);
auto s_a_c1out = make_vector<share*>(64, 1024);
auto r1out = make_vector<uint32_t>(64, 1024);
auto s_a_r1out = make_vector<share*>(64, 1024);
auto t1 = make_vector<uint32_t>(66, 1026);
auto s_a_t1 = make_vector<share*>(66, 1026);
auto c2in = make_vector<uint32_t>(576, 1024);
auto s_a_c2in = make_vector<share*>(576, 1024);
auto w2 = make_vector<uint32_t>(64, 576);
auto s_a_w2 = make_vector<share*>(64, 576);
auto c2out = make_vector<uint32_t>(64, 1024);
auto s_a_c2out = make_vector<share*>(64, 1024);
auto r2out = make_vector<uint32_t>(64, 1024);
auto s_a_r2out = make_vector<share*>(64, 1024);
auto p1out = make_vector<uint32_t>(64, 256);
auto s_a_p1out = make_vector<share*>(64, 256);
auto c3in = make_vector<uint32_t>(576, 256);
auto s_a_c3in = make_vector<share*>(576, 256);
auto t2 = make_vector<uint32_t>(66, 258);
auto s_a_t2 = make_vector<share*>(66, 258);
auto w3 = make_vector<uint32_t>(64, 576);
auto s_a_w3 = make_vector<share*>(64, 576);
auto c3out = make_vector<uint32_t>(64, 256);
auto s_a_c3out = make_vector<share*>(64, 256);
auto r3out = make_vector<uint32_t>(64, 256);
auto s_a_r3out = make_vector<share*>(64, 256);
auto c4in = make_vector<uint32_t>(576, 256);
auto s_a_c4in = make_vector<share*>(576, 256);
auto t3 = make_vector<uint32_t>(66, 258);
auto s_a_t3 = make_vector<share*>(66, 258);
auto w4 = make_vector<uint32_t>(64, 576);
auto s_a_w4 = make_vector<share*>(64, 576);
auto c4out = make_vector<uint32_t>(64, 256);
auto s_a_c4out = make_vector<share*>(64, 256);
auto r4out = make_vector<uint32_t>(64, 256);
auto s_a_r4out = make_vector<share*>(64, 256);
auto p2out = make_vector<uint32_t>(64, 64);
auto s_a_p2out = make_vector<share*>(64, 64);
auto c5in = make_vector<uint32_t>(576, 64);
auto s_a_c5in = make_vector<share*>(576, 64);
auto t4 = make_vector<uint32_t>(66, 66);
auto s_a_t4 = make_vector<share*>(66, 66);
auto w5 = make_vector<uint32_t>(64, 576);
auto s_a_w5 = make_vector<share*>(64, 576);
auto c5out = make_vector<uint32_t>(64, 64);
auto s_a_c5out = make_vector<share*>(64, 64);
auto r5out = make_vector<uint32_t>(64, 64);
auto s_a_r5out = make_vector<share*>(64, 64);
auto w6 = make_vector<uint32_t>(64, 64);
auto s_a_w6 = make_vector<share*>(64, 64);
auto c6out = make_vector<uint32_t>(64, 64);
auto s_a_c6out = make_vector<share*>(64, 64);
auto r6out = make_vector<uint32_t>(64, 64);
auto s_a_r6out = make_vector<share*>(64, 64);
auto w7 = make_vector<uint32_t>(16, 64);
auto s_a_w7 = make_vector<share*>(16, 64);
auto c7out = make_vector<uint32_t>(16, 64);
auto s_a_c7out = make_vector<share*>(16, 64);
auto r7out = make_vector<uint32_t>(16, 64);
auto s_a_r7out = make_vector<share*>(16, 64);
auto reshape = make_vector<uint32_t>(1024);
auto s_a_reshape = make_vector<share*>(1024);
auto w8 = make_vector<uint32_t>(10, 1024);
auto s_a_w8 = make_vector<share*>(10, 1024);
auto f1out = make_vector<uint32_t>(10);
auto s_a_f1out = make_vector<share*>(10);
for (uint32_t i = 0; i < 27; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        if (role == SERVER) {
            x[i][j] = 450 ;
            s_a_x[i][j] = acirc->PutINGate( x[i][j] ,bitlen,SERVER);
        } else {
            s_a_x[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 27; j++)
    {
        if (role == CLIENT) {
            w1[i][j] = 500 ;
            s_a_w1[i][j] = acirc->PutINGate( w1[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w1[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == CLIENT) {
            w2[i][j] = 500 ;
            s_a_w2[i][j] = acirc->PutINGate( w2[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w2[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == CLIENT) {
            w3[i][j] = 500 ;
            s_a_w3[i][j] = acirc->PutINGate( w3[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w3[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == CLIENT) {
            w4[i][j] = 500 ;
            s_a_w4[i][j] = acirc->PutINGate( w4[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w4[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == CLIENT) {
            w5[i][j] = 500 ;
            s_a_w5[i][j] = acirc->PutINGate( w5[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w5[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        if (role == CLIENT) {
            w6[i][j] = 500 ;
            s_a_w6[i][j] = acirc->PutINGate( w6[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w6[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        if (role == CLIENT) {
            w7[i][j] = 500 ;
            s_a_w7[i][j] = acirc->PutINGate( w7[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w7[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        if (role == CLIENT) {
            w8[i][j] = 500 ;
            s_a_w8[i][j] = acirc->PutINGate( w8[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w8[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        c1out[i][j] = 0 ;
        s_a_c1out[i][j] = acirc->PutCONSGate( c1out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 27; k++)
        {
            share * s_a_tmp_0 = acirc->PutMULGate( s_a_w1[i][k] , s_a_x[k][j] );
            s_a_c1out[i][j] = acirc->PutADDGate( s_a_c1out[i][j] , s_a_tmp_0 );
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        s_a_r1out[i][j] = acirc->PutMULGate( s_a_c1out[i][j] , s_a_c1out[i][j] );
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        s_a_t1[i+1][j+1] = create_new_share(s_a_r1out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t1[i][0] = 0 ;
    s_a_t1[i][0] = acirc->PutCONSGate( t1[i][0] ,bitlen);
    t1[i][1025] = 0 ;
    s_a_t1[i][1025] = acirc->PutCONSGate( t1[i][1025] ,bitlen);
}
for (uint32_t i = 1; i < 1025; i++)
{
    t1[0][i] = 0 ;
    s_a_t1[0][i] = acirc->PutCONSGate( t1[0][i] ,bitlen);
    t1[65][i] = 0 ;
    s_a_t1[65][i] = acirc->PutCONSGate( t1[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c2in[i*9+3*l+m][j] = create_new_share(s_a_t1[i+l][j+m]->get_wires(), acirc );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        c2out[i][j] = 0 ;
        s_a_c2out[i][j] = acirc->PutCONSGate( c2out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_1 = acirc->PutMULGate( s_a_w2[i][k] , s_a_c2in[k][j] );
            s_a_c2out[i][j] = acirc->PutADDGate( s_a_c2out[i][j] , s_a_tmp_1 );
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        s_a_r2out[i][j] = acirc->PutMULGate( s_a_c2out[i][j] , s_a_c2out[i][j] );
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        p1out[i][j] = 0 ;
        s_a_p1out[i][j] = acirc->PutCONSGate( p1out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 2; k++)
        {
            for (uint32_t l = 0; l < 2; l++)
            {
                s_a_p1out[i][j] = acirc->PutADDGate( s_a_r2out[i][4*j+2*k+l] , s_a_p1out[i][j] );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        s_a_t2[i+1][j+1] = create_new_share(s_a_p1out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t2[i][0] = 0 ;
    s_a_t2[i][0] = acirc->PutCONSGate( t2[i][0] ,bitlen);
    t2[i][257] = 0 ;
    s_a_t2[i][257] = acirc->PutCONSGate( t2[i][257] ,bitlen);
}
for (uint32_t i = 1; i < 257; i++)
{
    t2[0][i] = 0 ;
    s_a_t2[0][i] = acirc->PutCONSGate( t2[0][i] ,bitlen);
    t2[65][i] = 0 ;
    s_a_t2[65][i] = acirc->PutCONSGate( t2[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c3in[i*9+3*l+m][j] = create_new_share(s_a_t2[i+l][j+m]->get_wires(), acirc );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        c3out[i][j] = 0 ;
        s_a_c3out[i][j] = acirc->PutCONSGate( c3out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_2 = acirc->PutMULGate( s_a_w3[i][k] , s_a_c3in[k][j] );
            s_a_c3out[i][j] = acirc->PutADDGate( s_a_c3out[i][j] , s_a_tmp_2 );
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        s_a_r3out[i][j] = acirc->PutMULGate( s_a_c3out[i][j] , s_a_c3out[i][j] );
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        s_a_t3[i+1][j+1] = create_new_share(s_a_r3out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t3[i][0] = 0 ;
    s_a_t3[i][0] = acirc->PutCONSGate( t3[i][0] ,bitlen);
    t3[i][257] = 0 ;
    s_a_t3[i][257] = acirc->PutCONSGate( t3[i][257] ,bitlen);
}
for (uint32_t i = 1; i < 257; i++)
{
    t3[0][i] = 0 ;
    s_a_t3[0][i] = acirc->PutCONSGate( t3[0][i] ,bitlen);
    t3[65][i] = 0 ;
    s_a_t3[65][i] = acirc->PutCONSGate( t3[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c4in[i*9+3*l+m][j] = create_new_share(s_a_t3[i+l][j+m]->get_wires(), acirc );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        c4out[i][j] = 0 ;
        s_a_c4out[i][j] = acirc->PutCONSGate( c4out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_3 = acirc->PutMULGate( s_a_w4[i][k] , s_a_c4in[k][j] );
            s_a_c4out[i][j] = acirc->PutADDGate( s_a_c4out[i][j] , s_a_tmp_3 );
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        s_a_r4out[i][j] = acirc->PutMULGate( s_a_c4out[i][j] , s_a_c4out[i][j] );
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        p2out[i][j] = 0 ;
        s_a_p2out[i][j] = acirc->PutCONSGate( p2out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 2; k++)
        {
            for (uint32_t l = 0; l < 2; l++)
            {
                s_a_p2out[i][j] = acirc->PutADDGate( s_a_r4out[i][4*j+2*k+l] , s_a_p2out[i][j] );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        s_a_t4[i+1][j+1] = create_new_share(s_a_p2out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t4[i][0] = 0 ;
    s_a_t4[i][0] = acirc->PutCONSGate( t4[i][0] ,bitlen);
    t4[i][65] = 0 ;
    s_a_t4[i][65] = acirc->PutCONSGate( t4[i][65] ,bitlen);
}
for (uint32_t i = 1; i < 65; i++)
{
    t4[0][i] = 0 ;
    s_a_t4[0][i] = acirc->PutCONSGate( t4[0][i] ,bitlen);
    t4[65][i] = 0 ;
    s_a_t4[65][i] = acirc->PutCONSGate( t4[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c5in[i*9+3*l+m][j] = create_new_share(s_a_t4[i+l][j+m]->get_wires(), acirc );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        c5out[i][j] = 0 ;
        s_a_c5out[i][j] = acirc->PutCONSGate( c5out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_4 = acirc->PutMULGate( s_a_w5[i][k] , s_a_c5in[k][j] );
            s_a_c5out[i][j] = acirc->PutADDGate( s_a_c5out[i][j] , s_a_tmp_4 );
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        s_a_r5out[i][j] = acirc->PutMULGate( s_a_c5out[i][j] , s_a_c5out[i][j] );
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        c6out[i][j] = 0 ;
        s_a_c6out[i][j] = acirc->PutCONSGate( c6out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 64; k++)
        {
            share * s_a_tmp_5 = acirc->PutMULGate( s_a_w6[i][k] , s_a_r5out[k][j] );
            s_a_c6out[i][j] = acirc->PutADDGate( s_a_c6out[i][j] , s_a_tmp_5 );
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        s_a_r6out[i][j] = acirc->PutMULGate( s_a_c6out[i][j] , s_a_c6out[i][j] );
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        c7out[i][j] = 0 ;
        s_a_c7out[i][j] = acirc->PutCONSGate( c7out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 64; k++)
        {
            share * s_a_tmp_6 = acirc->PutMULGate( s_a_w7[i][k] , s_a_r6out[k][j] );
            s_a_c7out[i][j] = acirc->PutADDGate( s_a_c7out[i][j] , s_a_tmp_6 );
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        s_a_r7out[i][j] = acirc->PutMULGate( s_a_c7out[i][j] , s_a_c7out[i][j] );
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        s_a_reshape[64*i+j] = create_new_share(s_a_r7out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    f1out[i] = 0 ;
    s_a_f1out[i] = acirc->PutCONSGate( f1out[i] ,bitlen);
    for (uint32_t j = 0; j < 1024; j++)
    {
        share * s_a_tmp_7 = acirc->PutMULGate( s_a_w8[i][j] , s_a_reshape[j] );
        s_a_f1out[i] = acirc->PutADDGate( s_a_f1out[i] , s_a_tmp_7 );
    }
}
uint32_t _tmp_9 = 1 ;
share * s_a__tmp_9 = acirc->PutCONSGate( _tmp_9 ,bitlen);
share * s_a_tmp_8 = acirc->PutOUTGate( s_a__tmp_9 , ALL);
party->ExecCircuit();
uint32_t _output = s_a_tmp_8->get_clear_value<uint32_t>();
