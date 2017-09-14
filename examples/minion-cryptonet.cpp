ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto x = make_vector<uint32_t>(25, 169);
auto s_a_x = make_vector<share*>(25, 169);
auto w1 = make_vector<uint32_t>(5, 25);
auto s_a_w1 = make_vector<share*>(5, 25);
auto t1 = make_vector<uint32_t>(5, 169);
auto s_a_t1 = make_vector<share*>(5, 169);
auto t2 = make_vector<uint32_t>(845);
auto s_a_t2 = make_vector<share*>(845);
auto t3 = make_vector<uint32_t>(845);
auto s_a_t3 = make_vector<share*>(845);
auto w2 = make_vector<uint32_t>(100, 845);
auto s_a_w2 = make_vector<share*>(100, 845);
auto t4 = make_vector<uint32_t>(100);
auto s_a_t4 = make_vector<share*>(100);
auto t5 = make_vector<uint32_t>(100);
auto s_a_t5 = make_vector<share*>(100);
auto w3 = make_vector<uint32_t>(10, 100);
auto s_a_w3 = make_vector<share*>(10, 100);
auto t6 = make_vector<uint32_t>(10);
auto s_a_t6 = make_vector<share*>(10);
for (uint32_t i = 0; i < 25; i++)
{
    for (uint32_t j = 0; j < 169; j++)
    {
        if (role == SERVER) {
            x[i][j] = 450 ;
            s_a_x[i][j] = acirc->PutINGate( x[i][j] ,bitlen,SERVER);
        } else {
            s_a_x[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 5; i++)
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
for (uint32_t i = 0; i < 100; i++)
{
    for (uint32_t j = 0; j < 845; j++)
    {
        if (role == CLIENT) {
            w2[i][j] = 500 ;
            s_a_w2[i][j] = acirc->PutINGate( w2[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w2[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        if (role == CLIENT) {
            w3[i][j] = 500 ;
            s_a_w3[i][j] = acirc->PutINGate( w3[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w3[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 5; i++)
{
    for (uint32_t j = 0; j < 169; j++)
    {
        t1[i][j] = 0 ;
        s_a_t1[i][j] = acirc->PutCONSGate( t1[i][j] ,bitlen);
        for (uint32_t k = 0; k < 25; k++)
        {
            share * s_a_tmp_0 = acirc->PutMULGate( s_a_w1[i][k] , s_a_x[k][j] );
            s_a_t1[i][j] = acirc->PutADDGate( s_a_t1[i][j] , s_a_tmp_0 );
        }
    }
}
for (uint32_t i = 0; i < 5; i++)
{
    for (uint32_t j = 0; j < 169; j++)
    {
        s_a_t2[169*i+j] = create_new_share(s_a_t1[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 845; i++)
{
    s_a_t3[i] = acirc->PutMULGate( s_a_t2[i] , s_a_t2[i] );
}
for (uint32_t i = 0; i < 100; i++)
{
    t4[i] = 0 ;
    s_a_t4[i] = acirc->PutCONSGate( t4[i] ,bitlen);
    for (uint32_t j = 0; j < 845; j++)
    {
        share * s_a_tmp_1 = acirc->PutMULGate( s_a_w2[i][j] , s_a_t3[j] );
        s_a_t4[i] = acirc->PutADDGate( s_a_t4[i] , s_a_tmp_1 );
    }
}
for (uint32_t i = 0; i < 100; i++)
{
    s_a_t5[i] = acirc->PutMULGate( s_a_t4[i] , s_a_t4[i] );
}
for (uint32_t i = 0; i < 10; i++)
{
    t6[i] = 0 ;
    s_a_t6[i] = acirc->PutCONSGate( t6[i] ,bitlen);
    for (uint32_t j = 0; j < 100; j++)
    {
        share * s_a_tmp_2 = acirc->PutMULGate( s_a_w3[i][j] , s_a_t5[j] );
        s_a_t6[i] = acirc->PutADDGate( s_a_t6[i] , s_a_tmp_2 );
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
auto s_y_t6 = make_vector<share*>(10);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
s_y_t6[_i1] = ycirc->PutA2YGate( s_a_t6[_i1] );
}
share *s_y_max = ycirc->PutA2YGate( s_a_max );
share *s_y_myj = ycirc->PutA2YGate( s_a_myj );
share *s_y_maxidx = ycirc->PutA2YGate( s_a_maxidx );
for (uint32_t i = 0; i < 10; i++)
{
    share * s_y_tmp_3 = ycirc->PutGTGate( s_y_t6[i] , s_y_max );
    s_y_max = ycirc->PutMUXGate( s_y_t6[i] , s_y_max , s_y_tmp_3 );
    share * s_y_tmp_4 = ycirc->PutGTGate( s_y_t6[i] , s_y_max );
    s_y_maxidx = ycirc->PutMUXGate( s_y_myj , s_y_maxidx , s_y_tmp_4 );
    uint32_t _tmp_5 = 1 ;
    share * s_y__tmp_5 = ycirc->PutCONSGate( _tmp_5 ,bitlen);
    s_y_myj = ycirc->PutADDGate( s_y_myj , s_y__tmp_5 );
}
share *s_y_out = create_new_share(s_y_maxidx->get_wires(), ycirc );
share * s_y_tmp_6 = ycirc->PutOUTGate( s_y_out , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_6->get_clear_value<uint32_t>();
