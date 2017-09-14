ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto a = make_vector<uint32_t>(30);
auto s_a_a = make_vector<share*>(30);
auto b = make_vector<uint32_t>(30);
auto s_a_b = make_vector<share*>(30);
uint32_t j;
share *s_a_j;
uint32_t k;
share *s_a_k;
j = 0 ;
s_a_j = acirc->PutCONSGate( j ,bitlen);
for (uint32_t i = 0; i < 30; i++)
{
    if (role == SERVER) {
        a[i] = 50 ;
        s_a_a[i] = acirc->PutINGate( a[i] ,bitlen,SERVER);
    } else {
        s_a_a[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i = 0; i < 30; i++)
{
    if (role == CLIENT) {
        b[i] = 100 ;
        s_a_b[i] = acirc->PutINGate( b[i] ,bitlen,CLIENT);
    } else {
        s_a_b[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i = 0; i < 30; i++)
{
    share * s_a_tmp_0 = acirc->PutMULGate( s_a_a[i] , s_a_b[i] );
    s_a_j = acirc->PutADDGate( s_a_j , s_a_tmp_0 );
}
share *s_y_j = ycirc->PutA2YGate( s_a_j );
uint32_t _tmp_2 = 100 ;
share * s_y__tmp_2 = ycirc->PutCONSGate( _tmp_2 ,bitlen);
share * s_y_tmp_1 = ycirc->PutGTGate( s_y_j , s_y__tmp_2 );
uint32_t _tmp_3 = 1 ;
share * s_y__tmp_3 = ycirc->PutCONSGate( _tmp_3 ,bitlen);
uint32_t _tmp_4 = 0 ;
share * s_y__tmp_4 = ycirc->PutCONSGate( _tmp_4 ,bitlen);
share * s_y_k = ycirc->PutMUXGate( s_y__tmp_3 , s_y__tmp_4 , s_y_tmp_1 );
share * s_y_tmp_5 = ycirc->PutOUTGate( s_y_k , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_5->get_clear_value<uint32_t>();
