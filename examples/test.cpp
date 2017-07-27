ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 65000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
uint32_t a[100];
share *s_a_a[100];
uint32_t b[100];
share *s_a_b[100];
uint32_t d[100];
share *s_a_d[100];
for (uint32_t i = 0; i < 100; i++)
{
    a[i] = 2 ;
    if (role == SERVER) {
        s_a_a[i] = acirc->PutINGate( a[i] ,bitlen,SERVER);
    } else {
        s_a_a[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i = 0; i < 100; i++)
{
    b[i] = 2 ;
    if (role == CLIENT) {
        s_a_b[i] = acirc->PutINGate( b[i] ,bitlen,CLIENT);
    } else {
        s_a_b[i] = acirc->PutDummyINGate(bitlen);
    }
}
share *s_y_b[100] ;
for (int _i1 = 0; _i1 < 100 ; _i1++) {
s_y_b[_i1] = ycirc->PutA2YGate( s_a_b[_i1] );
}
share *s_y_a[100] ;
for (int _i1 = 0; _i1 < 100 ; _i1++) {
s_y_a[_i1] = ycirc->PutA2YGate( s_a_a[_i1] );
}
for (uint32_t i = 0; i < 100; i++)
{
    s_y_a[i] = ycirc->PutANDGate( s_y_b[i] , s_y_a[i] );
}
uint32_t c[100];
share *s_y_c[100];
share * s_a_c[100] ;
for (uint32_t i = 0; i < 100; i++)
{
    c[i] = 2 ;
    s_a_c[i] = acirc->PutCONSGate( c[i] ,bitlen);
}
for (uint32_t i = 0; i < 100; i++)
{
    s_a_a[i] = acirc->PutADDGate( s_a_b[i] , s_a_c[i] );
}
uint32_t _tmp_2 = 24 ;
share * s_y__tmp_2 = ycirc->PutCONSGate( _tmp_2 ,bitlen);
vector<uint32_t> _vec3 = s_y__tmp_2->get_wires();
_vec3.erase( _vec3.begin(), _vec3.begin() + 1 );
share *s_y_tmp_1 = create_new_share( _vec3 , ycirc );
share * s_y_tmp_0 = ycirc->PutOUTGate( s_y_tmp_1 , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_0->get_clear_value<uint32_t>();
