ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 120000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto S1S5 = make_vector<uint32_t>(10, 100);
auto s_a_S1S5 = make_vector<share*>(10, 100);
auto S1S6 = make_vector<uint32_t>(10, 100);
auto s_a_S1S6 = make_vector<share*>(10, 100);
auto S2S5 = make_vector<uint32_t>(10, 100);
auto s_a_S2S5 = make_vector<share*>(10, 100);
auto S2S6 = make_vector<uint32_t>(10, 100);
auto s_a_S2S6 = make_vector<share*>(10, 100);
auto S5 = make_vector<uint32_t>(10, 100);
auto s_a_S5 = make_vector<share*>(10, 100);
auto S5P = make_vector<uint32_t>(10, 100);
auto s_a_S5P = make_vector<share*>(10, 100);
auto S6 = make_vector<uint32_t>(10, 100);
auto s_a_S6 = make_vector<share*>(10, 100);
auto S6P = make_vector<uint32_t>(10, 100);
auto s_a_S6P = make_vector<share*>(10, 100);
auto S1R = make_vector<uint32_t>(100);
auto s_a_S1R = make_vector<share*>(100);
auto S2R = make_vector<uint32_t>(100);
auto s_a_S2R = make_vector<share*>(100);
auto R = make_vector<uint32_t>(100);
auto s_a_R = make_vector<share*>(100);
auto IP = make_vector<uint32_t>(100);
auto s_a_IP = make_vector<share*>(100);
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        if (role == SERVER) {
            S1S5[i][j] = 50 ;
            s_a_S1S5[i][j] = acirc->PutINGate( S1S5[i][j] ,bitlen,SERVER);
        } else {
            s_a_S1S5[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        if (role == SERVER) {
            S1S6[i][j] = 55 ;
            s_a_S1S6[i][j] = acirc->PutINGate( S1S6[i][j] ,bitlen,SERVER);
        } else {
            s_a_S1S6[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        if (role == CLIENT) {
            S2S5[i][j] = 60 ;
            s_a_S2S5[i][j] = acirc->PutINGate( S2S5[i][j] ,bitlen,CLIENT);
        } else {
            s_a_S2S5[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        if (role == CLIENT) {
            S2S6[i][j] = 65 ;
            s_a_S2S6[i][j] = acirc->PutINGate( S2S6[i][j] ,bitlen,CLIENT);
        } else {
            s_a_S2S6[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t j = 0; j < 100; j++)
{
    if (role == SERVER) {
        S1R[j] = 70 ;
        s_a_S1R[j] = acirc->PutINGate( S1R[j] ,bitlen,SERVER);
    } else {
        s_a_S1R[j] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t j = 0; j < 100; j++)
{
    if (role == CLIENT) {
        S2R[j] = 70 ;
        s_a_S2R[j] = acirc->PutINGate( S2R[j] ,bitlen,CLIENT);
    } else {
        s_a_S2R[j] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t j = 0; j < 100; j++)
{
    s_a_R[j] = acirc->PutADDGate( s_a_S1R[j] , s_a_S2R[j] );
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        s_a_S5[i][j] = acirc->PutADDGate( s_a_S1S5[i][j] , s_a_S2S5[i][j] );
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 100; j++)
    {
        s_a_S6[i][j] = acirc->PutADDGate( s_a_S1S6[i][j] , s_a_S2S6[i][j] );
    }
}
for (uint32_t i = 0; i < 100; i++)
{
    IP[i] = 0 ;
    s_a_IP[i] = acirc->PutCONSGate( IP[i] ,bitlen);
    for (uint32_t j = 0; j < 10; j++)
    {
        share * s_a_tmp_0 = acirc->PutMULGate( s_a_S5[j][i] , s_a_S6[j][i] );
        s_a_IP[i] = acirc->PutADDGate( s_a_IP[i] , s_a_tmp_0 );
    }
    s_a_IP[i] = acirc->PutSUBGate( s_a_R[i] , s_a_IP[i] );
}
for (uint32_t i = 0; i < 100; i++)
{
    for (uint32_t j = 0; j < 10; j++)
    {
        s_a_S5P[j][i] = acirc->PutMULGate( s_a_S6[j][i] , s_a_IP[i] );
    }
}
for (uint32_t i = 0; i < 100; i++)
{
    for (uint32_t j = 0; j < 10; j++)
    {
        s_a_S6P[j][i] = acirc->PutMULGate( s_a_S5[j][i] , s_a_IP[i] );
    }
}
uint32_t _tmp_2 = 1 ;
share * s_a__tmp_2 = acirc->PutCONSGate( _tmp_2 ,bitlen);
share * s_a_tmp_1 = acirc->PutOUTGate( s_a__tmp_2 , ALL);
party->ExecCircuit();
uint32_t _output3 = s_a_tmp_1->get_clear_value<uint32_t>();
