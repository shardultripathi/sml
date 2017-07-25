ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
uint32_t a[100];
share *s_a_a[100];
uint32_t b[100];
share *s_a_b[100];
uint32_t c[100];
share *s_a_c[100];
uint32_t d[100];
share *s_a_d[100];
for (uint32_t i = 0; i < 100; i++)
{
    a[i] = 50 ;
    if (role == SERVER) {
        s_a_a[i] = acirc->PutINGate( a[i] ,bitlen,SERVER);
    } else {
        s_a_a[i] = acirc->PutDummyINGate(bitlen);
    }
    b[i] = 60 ;
    if (role == CLIENT) {
        s_a_b[i] = acirc->PutINGate( b[i] ,bitlen,CLIENT);
    } else {
        s_a_b[i] = acirc->PutDummyINGate(bitlen);
    }
}
share *s_b_a[100] ;
for (int _i1 = 0; _i1 < 100 ; _i1++) {
s_b_a[_i1] = bcirc->PutA2BGate( s_a_a[_i1] ,ycirc);
}
share *s_b_b[100] ;
for (int _i1 = 0; _i1 < 100 ; _i1++) {
s_b_b[_i1] = bcirc->PutA2BGate( s_a_b[_i1] ,ycirc);
}
for (uint32_t i = 0; i < 100; i++)
{
    share * s_b_c[i] = bcirc->PutANDGate( s_b_a[i] , s_b_b[i] );
}
for (uint32_t i = 0; i < 100; i++)
{
    s_b_a[i] = bcirc->PutANDGate( s_b_a[i] , s_b_b[i] );
}
for (int _i1 = 0; _i1 < 100 ; _i1++) {
s_a_a[_i1] = acirc->PutB2AGate( s_b_a[_i1] );
}
for (uint32_t i = 0; i < 100; i++)
{
    s_a_d[i] = acirc->PutADDGate( s_a_a[i] , s_a_b[i] );
}
uint32_t _tmp_1 = 1 ;
share * s_a__tmp_1 = acirc->PutCONSGate( _tmp_1 ,bitlen);
share * s_a_tmp_0 = acirc->PutOUTGate( s_a__tmp_1 , ALL);
party->ExecCircuit();
uint32_t _output = s_a_tmp_0->get_clear_value<uint32_t>();
