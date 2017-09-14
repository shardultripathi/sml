ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto T = make_vector<uint32_t>(5, 9, 3);
auto s_a_T = make_vector<share*>(5, 9, 3);
auto P = make_vector<uint32_t>(5);
auto s_a_P = make_vector<share*>(5);
auto x = make_vector<uint32_t>(9);
auto s_a_x = make_vector<share*>(9);
uint32_t s;
share *s_a_s;
uint32_t t;
share *s_a_t;
uint32_t k;
share *s_a_k;
auto A = make_vector<uint32_t>(5);
auto s_a_A = make_vector<share*>(5);
for (uint32_t i = 0; i < 5; i++)
{
    if (role == SERVER) {
        P[i] = 25 ;
        s_a_P[i] = acirc->PutINGate( P[i] ,bitlen,SERVER);
    } else {
        s_a_P[i] = acirc->PutDummyINGate(bitlen);
    }
    for (uint32_t j = 0; j < 9; j++)
    {
        if (role == SERVER) {
            T[i][j][0] = 30 ;
            s_a_T[i][j][0] = acirc->PutINGate( T[i][j][0] ,bitlen,SERVER);
        } else {
            s_a_T[i][j][0] = acirc->PutDummyINGate(bitlen);
        }
        if (role == SERVER) {
            T[i][j][1] = 31 ;
            s_a_T[i][j][1] = acirc->PutINGate( T[i][j][1] ,bitlen,SERVER);
        } else {
            s_a_T[i][j][1] = acirc->PutDummyINGate(bitlen);
        }
        if (role == SERVER) {
            T[i][j][2] = 32 ;
            s_a_T[i][j][2] = acirc->PutINGate( T[i][j][2] ,bitlen,SERVER);
        } else {
            s_a_T[i][j][2] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 9; i++)
{
    if (role == CLIENT) {
        x[i] = 40 ;
        s_a_x[i] = acirc->PutINGate( x[i] ,bitlen,CLIENT);
    } else {
        s_a_x[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto s_y_P = make_vector<share*>(5);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
s_y_P[_i1] = ycirc->PutA2YGate( s_a_P[_i1] );
}
share * s_y_s ;
auto s_y_x = make_vector<share*>(9);
for (int _i1 = 0; _i1 < 9 ; _i1++) {
s_y_x[_i1] = ycirc->PutA2YGate( s_a_x[_i1] );
}
auto s_y_T = make_vector<share*>(5, 9, 3);
for (int _i1 = 0; _i1 < 5 ; _i1++) {
for (int _i4 = 0; _i4 < 9 ; _i4++) {
for (int _i7 = 0; _i7 < 3 ; _i7++) {
s_y_T[_i1][_i4][_i7] = ycirc->PutA2YGate( s_a_T[_i1][_i4][_i7] );
}
}
}
share * s_y_t ;
auto s_y_A = make_vector<share*>(5);
for (uint32_t i = 0; i < 5; i++)
{
    s_y_s = create_new_share(s_y_P[i]->get_wires(), ycirc );
    for (uint32_t j = 0; j < 9; j++)
    {
        uint32_t _tmp_1 = 1 ;
        share * s_y__tmp_1 = ycirc->PutCONSGate( _tmp_1 ,bitlen);
        share * s_y_tmp_0 = ycirc->PutGTGate( s_y__tmp_1 , s_y_x[j] );
        uint32_t _tmp_4 = 2 ;
        share * s_y__tmp_4 = ycirc->PutCONSGate( _tmp_4 ,bitlen);
        share * s_y_tmp_3 = ycirc->PutGTGate( s_y__tmp_4 , s_y_x[j] );
        share * s_y_tmp_2 = ycirc->PutMUXGate( s_y_T[i][j][1] , s_y_T[i][j][2] , s_y_tmp_3 );
        s_y_t = ycirc->PutMUXGate( s_y_T[i][j][0] , s_y_tmp_2 , s_y_tmp_0 );
        s_y_s = ycirc->PutADDGate( s_y_s , s_y_t );
    }
    s_y_A[i] = create_new_share(s_y_s->get_wires(), ycirc );
}
uint32_t max;
share *s_y_max;
uint32_t out;
share *s_y_out;
uint32_t maxidx;
share *s_y_maxidx;
uint32_t myj;
share *s_y_myj;
max = 0 ;
s_y_max = ycirc->PutCONSGate( max ,bitlen);
maxidx = 0 ;
s_y_maxidx = ycirc->PutCONSGate( maxidx ,bitlen);
myj = 0 ;
s_y_myj = ycirc->PutCONSGate( myj ,bitlen);
for (uint32_t i = 0; i < 10; i++)
{
    share * s_y_tmp_5 = ycirc->PutGTGate( s_y_A[i] , s_y_max );
    s_y_max = ycirc->PutMUXGate( s_y_A[i] , s_y_max , s_y_tmp_5 );
    share * s_y_tmp_6 = ycirc->PutGTGate( s_y_A[i] , s_y_max );
    s_y_maxidx = ycirc->PutMUXGate( s_y_myj , s_y_maxidx , s_y_tmp_6 );
    uint32_t _tmp_7 = 1 ;
    share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
    s_y_myj = ycirc->PutADDGate( s_y_myj , s_y__tmp_7 );
}
s_y_out = create_new_share(s_y_maxidx->get_wires(), ycirc );
share * s_y_tmp_8 = ycirc->PutOUTGate( s_y_out , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_8->get_clear_value<uint32_t>();
