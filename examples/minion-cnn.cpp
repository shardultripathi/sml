ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto x = make_vector<uint32_t>(25, 576);
auto s_a_x = make_vector<share*>(25, 576);
auto w1 = make_vector<uint32_t>(16, 25);
auto s_a_w1 = make_vector<share*>(16, 25);
auto c1out = make_vector<uint32_t>(16, 576);
auto s_a_c1out = make_vector<share*>(16, 576);
auto r1out = make_vector<uint32_t>(16, 576);
auto s_a_r1out = make_vector<share*>(16, 576);
auto pool1out = make_vector<uint32_t>(16, 12, 12);
auto s_a_pool1out = make_vector<share*>(16, 12, 12);
auto c2in = make_vector<uint32_t>(400, 64);
auto s_a_c2in = make_vector<share*>(400, 64);
auto w2 = make_vector<uint32_t>(16, 400);
auto s_a_w2 = make_vector<share*>(16, 400);
auto c2out = make_vector<uint32_t>(16, 64);
auto s_a_c2out = make_vector<share*>(16, 64);
auto r2out = make_vector<uint32_t>(16, 64);
auto s_a_r2out = make_vector<share*>(16, 64);
auto pool2out = make_vector<uint32_t>(16, 4, 4);
auto s_a_pool2out = make_vector<share*>(16, 4, 4);
auto reshape = make_vector<uint32_t>(256);
auto s_a_reshape = make_vector<share*>(256);
auto w3 = make_vector<uint32_t>(100, 256);
auto s_a_w3 = make_vector<share*>(100, 256);
auto f1out = make_vector<uint32_t>(100);
auto s_a_f1out = make_vector<share*>(100);
auto r3out = make_vector<uint32_t>(100);
auto s_a_r3out = make_vector<share*>(100);
auto w4 = make_vector<uint32_t>(10, 100);
auto s_a_w4 = make_vector<share*>(10, 100);
auto f2out = make_vector<uint32_t>(10);
auto s_a_f2out = make_vector<share*>(10);
for (uint32_t i = 0; i < 25; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == SERVER) {
            x[i][j] = 450 ;
            s_a_x[i][j] = acirc->PutINGate( x[i][j] ,bitlen,SERVER);
        } else {
            s_a_x[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 25; j++)
    {
        if (role == CLIENT) {
            w1[i][j] = 500 ;
            s_a_w1[i][j] = acirc->PutINGate( w1[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w1[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 400; j++)
    {
        if (role == CLIENT) {
            w2[i][j] = 500 ;
            s_a_w2[i][j] = acirc->PutINGate( w2[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w2[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 100; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        if (role == CLIENT) {
            w3[i][j] = 500 ;
            s_a_w3[i][j] = acirc->PutINGate( w3[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w3[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        if (role == CLIENT) {
            w4[i][j] = 500 ;
            s_a_w4[i][j] = acirc->PutINGate( w4[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w4[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        c1out[i][j] = 0 ;
        s_a_c1out[i][j] = acirc->PutCONSGate( c1out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 25; k++)
        {
            share * s_a_tmp_0 = acirc->PutMULGate( s_a_w1[i][k] , s_a_x[k][j] );
            s_a_c1out[i][j] = acirc->PutADDGate( s_a_c1out[i][j] , s_a_tmp_0 );
        }
    }
}
auto s_y_c1out = make_vector<share*>(16, 576);
for (int _i1 = 0; _i1 < 16 ; _i1++) {
for (int _i4 = 0; _i4 < 576 ; _i4++) {
s_y_c1out[_i1][_i4] = ycirc->PutA2YGate( s_a_c1out[_i1][_i4] );
}
}
auto s_y_r1out = make_vector<share*>(16, 576);
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        uint32_t _tmp_2 = 100 ;
        share * s_y__tmp_2 = ycirc->PutCONSGate( _tmp_2 ,bitlen);
        share * s_y_tmp_1 = ycirc->PutGTGate( s_y_c1out[i][j] , s_y__tmp_2 );
        uint32_t _tmp_3 = 0 ;
        share * s_y__tmp_3 = ycirc->PutCONSGate( _tmp_3 ,bitlen);
        s_y_r1out[i][j] = ycirc->PutMUXGate( s_y_c1out[i][j] , s_y__tmp_3 , s_y_tmp_1 );
    }
}
auto s_y_pool1out = make_vector<share*>(16, 12, 12);
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 12; j++)
    {
        for (uint32_t k = 0; k < 12; k++)
        {
            pool1out[i][j][k] = 0 ;
            s_y_pool1out[i][j][k] = ycirc->PutCONSGate( pool1out[i][j][k] ,bitlen);
            for (uint32_t l = 0; l < 4; l++)
            {
                share * s_y_tmp_4 = ycirc->PutGTGate( s_y_r1out[i][48*j+4*k+l] , s_y_pool1out[i][j][k] );
                s_y_pool1out[i][j][k] = ycirc->PutMUXGate( s_y_r1out[i][48*j+4*k+l] , s_y_pool1out[i][j][k] , s_y_tmp_4 );
            }
        }
    }
}
for (int _i1 = 0; _i1 < 16 ; _i1++) {
for (int _i4 = 0; _i4 < 12 ; _i4++) {
for (int _i7 = 0; _i7 < 12 ; _i7++) {
s_a_pool1out[_i1][_i4][_i7] = acirc->PutY2AGate( s_y_pool1out[_i1][_i4][_i7] ,bcirc);
}
}
}
for (uint32_t i = 0; i < 8; i++)
{
    for (uint32_t j = 0; j < 8; j++)
    {
        for (uint32_t k = 0; k < 16; k++)
        {
            for (uint32_t l = 0; l < 5; l++)
            {
                for (uint32_t m = 0; m < 5; m++)
                {
                    s_a_c2in[25*k+5*l+m][8*i+j] = create_new_share(s_a_pool1out[k][i+l][j+m]->get_wires(), acirc );
                }
            }
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        c2out[i][j] = 0 ;
        s_a_c2out[i][j] = acirc->PutCONSGate( c2out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 400; k++)
        {
            share * s_a_tmp_5 = acirc->PutMULGate( s_a_w2[i][k] , s_a_c2in[k][j] );
            s_a_c2out[i][j] = acirc->PutADDGate( s_a_c2out[i][j] , s_a_tmp_5 );
        }
    }
}
auto s_y_c2out = make_vector<share*>(16, 64);
for (int _i1 = 0; _i1 < 16 ; _i1++) {
for (int _i4 = 0; _i4 < 64 ; _i4++) {
s_y_c2out[_i1][_i4] = ycirc->PutA2YGate( s_a_c2out[_i1][_i4] );
}
}
auto s_y_r2out = make_vector<share*>(16, 64);
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        uint32_t _tmp_7 = 100 ;
        share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
        share * s_y_tmp_6 = ycirc->PutGTGate( s_y_c2out[i][j] , s_y__tmp_7 );
        uint32_t _tmp_8 = 0 ;
        share * s_y__tmp_8 = ycirc->PutCONSGate( _tmp_8 ,bitlen);
        s_y_r2out[i][j] = ycirc->PutMUXGate( s_y_c2out[i][j] , s_y__tmp_8 , s_y_tmp_6 );
    }
}
auto s_y_pool2out = make_vector<share*>(16, 4, 4);
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 4; j++)
    {
        for (uint32_t k = 0; k < 4; k++)
        {
            pool2out[i][j][k] = 0 ;
            s_y_pool2out[i][j][k] = ycirc->PutCONSGate( pool2out[i][j][k] ,bitlen);
            for (uint32_t l = 0; l < 4; l++)
            {
                share * s_y_tmp_9 = ycirc->PutGTGate( s_y_r2out[i][16*j+4*k+l] , s_y_pool2out[i][j][k] );
                s_y_pool2out[i][j][k] = ycirc->PutMUXGate( s_y_r2out[i][16*j+4*k+l] , s_y_pool2out[i][j][k] , s_y_tmp_9 );
            }
        }
    }
}
for (int _i1 = 0; _i1 < 16 ; _i1++) {
for (int _i4 = 0; _i4 < 4 ; _i4++) {
for (int _i7 = 0; _i7 < 4 ; _i7++) {
s_a_pool2out[_i1][_i4][_i7] = acirc->PutY2AGate( s_y_pool2out[_i1][_i4][_i7] ,bcirc);
}
}
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 4; j++)
    {
        for (uint32_t k = 0; k < 4; k++)
        {
            s_a_reshape[16*i+4*j+k] = create_new_share(s_a_pool2out[i][j][k]->get_wires(), acirc );
        }
    }
}
for (uint32_t i = 0; i < 100; i++)
{
    f1out[i] = 0 ;
    s_a_f1out[i] = acirc->PutCONSGate( f1out[i] ,bitlen);
    for (uint32_t j = 0; j < 256; j++)
    {
        share * s_a_tmp_10 = acirc->PutMULGate( s_a_w3[i][j] , s_a_reshape[j] );
        s_a_f1out[i] = acirc->PutADDGate( s_a_f1out[i] , s_a_tmp_10 );
    }
}
auto s_y_f1out = make_vector<share*>(100);
for (int _i1 = 0; _i1 < 100 ; _i1++) {
s_y_f1out[_i1] = ycirc->PutA2YGate( s_a_f1out[_i1] );
}
auto s_y_r3out = make_vector<share*>(100);
for (uint32_t i = 0; i < 100; i++)
{
    uint32_t _tmp_12 = 100 ;
    share * s_y__tmp_12 = ycirc->PutCONSGate( _tmp_12 ,bitlen);
    share * s_y_tmp_11 = ycirc->PutGTGate( s_y_f1out[i] , s_y__tmp_12 );
    uint32_t _tmp_13 = 0 ;
    share * s_y__tmp_13 = ycirc->PutCONSGate( _tmp_13 ,bitlen);
    s_y_r3out[i] = ycirc->PutMUXGate( s_y_f1out[i] , s_y__tmp_13 , s_y_tmp_11 );
}
for (int _i1 = 0; _i1 < 100 ; _i1++) {
s_a_r3out[_i1] = acirc->PutY2AGate( s_y_r3out[_i1] ,bcirc);
}
for (uint32_t i = 0; i < 10; i++)
{
    f2out[i] = 0 ;
    s_a_f2out[i] = acirc->PutCONSGate( f2out[i] ,bitlen);
    for (uint32_t j = 0; j < 100; j++)
    {
        share * s_a_tmp_14 = acirc->PutMULGate( s_a_w4[i][j] , s_a_r3out[j] );
        s_a_f2out[i] = acirc->PutADDGate( s_a_f2out[i] , s_a_tmp_14 );
    }
}
uint32_t max;
share *s_a_max;
uint32_t out;
share *s_a_out;
uint32_t maxidx;
share *s_a_maxidx;
uint32_t myj;
share *s_a_myj;
max = 0 ;
s_a_max = acirc->PutCONSGate( max ,bitlen);
maxidx = 0 ;
s_a_maxidx = acirc->PutCONSGate( maxidx ,bitlen);
myj = 0 ;
s_a_myj = acirc->PutCONSGate( myj ,bitlen);
auto s_y_f2out = make_vector<share*>(10);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
s_y_f2out[_i1] = ycirc->PutA2YGate( s_a_f2out[_i1] );
}
share *s_y_max = ycirc->PutA2YGate( s_a_max );
share *s_y_myj = ycirc->PutA2YGate( s_a_myj );
share *s_y_maxidx = ycirc->PutA2YGate( s_a_maxidx );
for (uint32_t i = 0; i < 10; i++)
{
    share * s_y_tmp_15 = ycirc->PutGTGate( s_y_f2out[i] , s_y_max );
    s_y_max = ycirc->PutMUXGate( s_y_f2out[i] , s_y_max , s_y_tmp_15 );
    share * s_y_tmp_16 = ycirc->PutGTGate( s_y_f2out[i] , s_y_max );
    s_y_maxidx = ycirc->PutMUXGate( s_y_myj , s_y_maxidx , s_y_tmp_16 );
    uint32_t _tmp_17 = 1 ;
    share * s_y__tmp_17 = ycirc->PutCONSGate( _tmp_17 ,bitlen);
    s_y_myj = ycirc->PutADDGate( s_y_myj , s_y__tmp_17 );
}
share *s_y_out = create_new_share(s_y_maxidx->get_wires(), ycirc );
share * s_y_tmp_18 = ycirc->PutOUTGate( s_y_out , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_18->get_clear_value<uint32_t>();
