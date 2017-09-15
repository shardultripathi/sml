ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
uint32_t a1;
share *s_a_a1;
uint32_t a2;
share *s_a_a2;
a1 = 92 ;
s_a_a1 = acirc->PutCONSGate( a1 ,bitlen);
share *s_y_a1 = ycirc->PutA2YGate( s_a_a1 );
vector<uint32_t> _vec0 = s_y_a1->get_wires();
_vec0.erase( _vec0.begin(), _vec0.begin() + 3 );
uint32_t _msb1 = _vec0[_vec0.size()-1];
for (int _i2 = 0; _i2 < 3 ; _i2++) {
    _vec0.push_back(_msb1);
}
s_y_a1 = create_new_share( _vec0 , ycirc );
s_a_a1 = acirc->PutY2AGate( s_y_a1 ,bcirc);
for (uint32_t i = 0; i < 100; i++)
{
    for (uint32_t j = 0; j < 10; j++)
    {
        if ( i>j )
            {
                uint32_t _tmp_3 = 1 ;
                share * s_a__tmp_3 = acirc->PutCONSGate( _tmp_3 ,bitlen);
                s_a_a1 = acirc->PutADDGate( s_a_a1 , s_a__tmp_3 );
            }
    }
}
share * s_a_tmp_4 = acirc->PutOUTGate( s_a_a1 , ALL);
party->ExecCircuit();
uint32_t _output = s_a_tmp_4->get_clear_value<uint32_t>();
