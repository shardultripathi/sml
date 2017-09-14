ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto x = make_vector<uint32_t>(784);
auto s_a_x = make_vector<share*>(784);
auto w1 = make_vector<uint32_t>(128, 784);
auto s_a_w1 = make_vector<share*>(128, 784);
auto f1out = make_vector<uint32_t>(128);
auto s_a_f1out = make_vector<share*>(128);
auto r1out = make_vector<uint32_t>(128);
auto s_a_r1out = make_vector<share*>(128);
auto f2out = make_vector<uint32_t>(128);
auto s_a_f2out = make_vector<share*>(128);
auto w2 = make_vector<uint32_t>(128, 128);
auto s_a_w2 = make_vector<share*>(128, 128);
auto r2out = make_vector<uint32_t>(128);
auto s_a_r2out = make_vector<share*>(128);
auto w3 = make_vector<uint32_t>(10, 128);
auto s_a_w3 = make_vector<share*>(10, 128);
auto f3out = make_vector<uint32_t>(10);
auto s_a_f3out = make_vector<share*>(10);
for (uint32_t i = 0; i < 784; i++)
{
    if (role == SERVER) {
        x[i] = 450 ;
        s_a_x[i] = acirc->PutINGate( x[i] ,bitlen,SERVER);
    } else {
        s_a_x[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i = 0; i < 128; i++)
{
    for (uint32_t j = 0; j < 784; j++)
    {
        if (role == CLIENT) {
            w1[i][j] = 500 ;
            s_a_w1[i][j] = acirc->PutINGate( w1[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w1[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 128; i++)
{
    for (uint32_t j = 0; j < 128; j++)
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
    for (uint32_t j = 0; j < 128; j++)
    {
        if (role == CLIENT) {
            w3[i][j] = 500 ;
            s_a_w3[i][j] = acirc->PutINGate( w3[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w3[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 128; i++)
{
    f1out[i] = 0 ;
    s_a_f1out[i] = acirc->PutCONSGate( f1out[i] ,bitlen);
    for (uint32_t j = 0; j < 784; j++)
    {
        share * s_a_tmp_0 = acirc->PutMULGate( s_a_w1[i][j] , s_a_x[j] );
        s_a_f1out[i] = acirc->PutADDGate( s_a_f1out[i] , s_a_tmp_0 );
    }
}
for (uint32_t i = 0; i < 128; i++)
{
    s_a_r1out[i] = acirc->PutMULGate( s_a_f1out[i] , s_a_f1out[i] );
}
for (uint32_t i = 0; i < 128; i++)
{
    f2out[i] = 0 ;
    s_a_f2out[i] = acirc->PutCONSGate( f2out[i] ,bitlen);
    for (uint32_t j = 0; j < 128; j++)
    {
        share * s_a_tmp_1 = acirc->PutMULGate( s_a_w2[i][j] , s_a_r1out[j] );
        s_a_f2out[i] = acirc->PutADDGate( s_a_f2out[i] , s_a_tmp_1 );
    }
}
for (uint32_t i = 0; i < 128; i++)
{
    s_a_r2out[i] = acirc->PutMULGate( s_a_f2out[i] , s_a_f2out[i] );
}
for (uint32_t i = 0; i < 10; i++)
{
    f3out[i] = 0 ;
    s_a_f3out[i] = acirc->PutCONSGate( f3out[i] ,bitlen);
    for (uint32_t j = 0; j < 128; j++)
    {
        share * s_a_tmp_2 = acirc->PutMULGate( s_a_w3[i][j] , s_a_r2out[j] );
        s_a_f3out[i] = acirc->PutADDGate( s_a_f3out[i] , s_a_tmp_2 );
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
auto s_y_f3out = make_vector<share*>(10);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
s_y_f3out[_i1] = ycirc->PutA2YGate( s_a_f3out[_i1] );
}
share *s_y_max = ycirc->PutA2YGate( s_a_max );
share *s_y_myj = ycirc->PutA2YGate( s_a_myj );
share *s_y_maxidx = ycirc->PutA2YGate( s_a_maxidx );
for (uint32_t i = 0; i < 10; i++)
{
    share * s_y_tmp_3 = ycirc->PutGTGate( s_y_f3out[i] , s_y_max );
    s_y_max = ycirc->PutMUXGate( s_y_f3out[i] , s_y_max , s_y_tmp_3 );
    share * s_y_tmp_4 = ycirc->PutGTGate( s_y_f3out[i] , s_y_max );
    s_y_maxidx = ycirc->PutMUXGate( s_y_myj , s_y_maxidx , s_y_tmp_4 );
    uint32_t _tmp_5 = 1 ;
    share * s_y__tmp_5 = ycirc->PutCONSGate( _tmp_5 ,bitlen);
    s_y_myj = ycirc->PutADDGate( s_y_myj , s_y__tmp_5 );
}
share *s_y_out = create_new_share(s_y_maxidx->get_wires(), ycirc );
share * s_y_tmp_6 = ycirc->PutOUTGate( s_y_out , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_6->get_clear_value<uint32_t>();
