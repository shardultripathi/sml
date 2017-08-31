ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 650000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
MultiDimArray< uint32_t, 10, 785>::type w ;
MultiDimArray<share*, 10, 785>::type s_a_w ;
MultiDimArray< uint32_t, 785>::type x ;
MultiDimArray<share*, 785>::type s_a_x ;
MultiDimArray< uint32_t, 10>::type ans ;
MultiDimArray<share*, 10>::type s_a_ans ;
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
MultiDimArray<share*, 10>::type s_y_ans ;
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
