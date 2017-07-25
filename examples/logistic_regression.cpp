ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
uint32_t w[10][785];
share *s_a_w[10][785];
uint32_t x[785];
share *s_a_x[785];
uint32_t ans[10];
share *s_a_ans[10];
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 785; j++)
    {
        w[i][j] = 50 ;
        if (role == SERVER) {
            s_a_w[i][j] = acirc->PutINGate( w[i][j] ,bitlen,SERVER);
        } else {
            s_a_w[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 785; i++)
{
    x[i] = 100 ;
    if (role == CLIENT) {
        s_a_x[i] = acirc->PutINGate( x[i] ,bitlen,CLIENT);
    } else {
        s_a_x[i] = acirc->PutDummyINGate(bitlen);
    }
}
uint32_t tmp;
share *s_a_tmp;
for (uint32_t i = 0; i < 10; i++)
{
    tmp = 0 ;
    s_a_tmp = acirc->PutCONSGate( tmp ,bitlen);
    for (uint32_t j = 0; j < 785; j++)
    {
        share * s_a_tmp_0 = acirc->PutMULGate( s_a_w[i][j] , s_a_x[j] );
        s_a_tmp = acirc->PutADDGate( s_a_tmp , s_a_tmp_0 );
    }
    s_a_ans[i] = create_new_share(s_a_tmp->get_wire_ids(), acirc );
}
uint32_t max;
share *s_a_max;
max = 0 ;
s_a_max = acirc->PutCONSGate( max ,bitlen);
share *s_b_ans[10] ;
for (int _i1 = 0; _i1 < 10 ; _i1++) {
s_b_ans[_i1] = bcirc->PutA2BGate( s_a_ans[_i1] ,ycirc);
}
share *s_b_max = bcirc->PutA2BGate( s_a_max ,ycirc);
for (uint32_t i = 0; i < 10; i++)
{
    share * s_b_tmp_1 = bcirc->PutGTGate( s_b_ans[i] , s_b_max );
    s_b_max = bcirc->PutMUXGate( s_b_ans[i] , s_b_max , s_b_tmp_1 );
}
share * s_b_tmp_2 = bcirc->PutOUTGate( s_b_max , ALL);
party->ExecCircuit();
uint32_t _output = s_b_tmp_2->get_clear_value<uint32_t>();
