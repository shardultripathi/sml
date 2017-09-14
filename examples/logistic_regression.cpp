ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto w = make_vector<uint32_t>(10, 785);
auto s_a_w = make_vector<share*>(10, 785);
auto x = make_vector<uint32_t>(785);
auto s_a_x = make_vector<share*>(785);
auto ans = make_vector<uint32_t>(10);
auto s_a_ans = make_vector<share*>(10);
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 785; j++)
    {
        if (role == SERVER) {
            w[i][j] = 50 ;
            s_a_w[i][j] = acirc->PutINGate( w[i][j] ,bitlen,SERVER);
        } else {
            s_a_w[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 785; i++)
{
    if (role == CLIENT) {
        x[i] = 100 ;
        s_a_x[i] = acirc->PutINGate( x[i] ,bitlen,CLIENT);
    } else {
        s_a_x[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    ans[i] = 0 ;
    s_a_ans[i] = acirc->PutCONSGate( ans[i] ,bitlen);
    for (uint32_t j = 0; j < 785; j++)
    {
        share * s_a_tmp_0 = acirc->PutMULGate( s_a_w[i][j] , s_a_x[j] );
        s_a_ans[i] = acirc->PutADDGate( s_a_ans[i] , s_a_tmp_0 );
    }
}
uint32_t max;
share *s_a_max;
max = 0 ;
s_a_max = acirc->PutCONSGate( max ,bitlen);
auto s_y_ans = make_vector<share*>(10);
for (int _i1 = 0; _i1 < 10 ; _i1++) {
s_y_ans[_i1] = ycirc->PutA2YGate( s_a_ans[_i1] );
}
share *s_y_max = ycirc->PutA2YGate( s_a_max );
for (uint32_t i = 0; i < 10; i++)
{
    share * s_y_tmp_1 = ycirc->PutGTGate( s_y_ans[i] , s_y_max );
    s_y_max = ycirc->PutMUXGate( s_y_ans[i] , s_y_max , s_y_tmp_1 );
}
share * s_y_tmp_2 = ycirc->PutOUTGate( s_y_max , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_2->get_clear_value<uint32_t>();
