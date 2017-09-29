ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 120000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto x = make_vector<uint32_t>(27, 1024);
auto s_a_x = make_vector<share*>(27, 1024);
auto w1 = make_vector<uint32_t>(64, 27);
auto s_a_w1 = make_vector<share*>(64, 27);
auto c1out = make_vector<uint32_t>(64, 1024);
auto s_a_c1out = make_vector<share*>(64, 1024);
auto r1out = make_vector<uint32_t>(64, 1024);
auto s_a_r1out = make_vector<share*>(64, 1024);
auto t1 = make_vector<uint32_t>(66, 1026);
auto s_a_t1 = make_vector<share*>(66, 1026);
auto c2in = make_vector<uint32_t>(576, 1024);
auto s_a_c2in = make_vector<share*>(576, 1024);
auto Rc2in = make_vector<uint32_t>(576, 1024);
auto s_a_Rc2in = make_vector<share*>(576, 1024);
auto IRc2in = make_vector<uint32_t>(576, 1024);
auto s_a_IRc2in = make_vector<share*>(576, 1024);
if(role == SERVER){
ofstream fout("IRc2in", std::ofstream::out | std::ofstream::app);
for(int i = 0; i < 576; i++) {
	for(int j = 0; j < 1024; j++) {
		fout << i << " " << j << " " <<(IRc2in[i][j] = rand()) << endl;
	}
}
fout.close();
}
for (uint32_t i = 0; i < 27; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        if (role == SERVER) {
            x[i][j] = 450 ;
            s_a_x[i][j] = acirc->PutINGate( x[i][j] ,bitlen,SERVER);
        } else {
            s_a_x[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 576; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        if (role == SERVER) {
            Rc2in[i][j] = IRc2in[i][j] ;
            s_a_Rc2in[i][j] = acirc->PutINGate( Rc2in[i][j] ,bitlen,SERVER);
        } else {
            s_a_Rc2in[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 27; j++)
    {
        if (role == CLIENT) {
            w1[i][j] = 500 ;
            s_a_w1[i][j] = acirc->PutINGate( w1[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w1[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        c1out[i][j] = 0 ;
        s_a_c1out[i][j] = acirc->PutCONSGate( c1out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 27; k++)
        {
            share * s_a_tmp_0 = acirc->PutMULGate( s_a_w1[i][k] , s_a_x[k][j] );
            s_a_c1out[i][j] = acirc->PutADDGate( s_a_c1out[i][j] , s_a_tmp_0 );
        }
    }
}
auto s_y_c1out = make_vector<share*>(64, 1024);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_y_c1out[_i1][_i4] = ycirc->PutA2YGate( s_a_c1out[_i1][_i4] );
}
}
auto s_y_r1out = make_vector<share*>(64, 1024);
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        uint32_t _tmp_2 = 1 ;
        share * s_y__tmp_2 = ycirc->PutCONSGate( _tmp_2 ,bitlen);
        share * s_y_tmp_1 = ycirc->PutGTGate( s_y_c1out[i][j] , s_y__tmp_2 );
        uint32_t _tmp_3 = 0 ;
        share * s_y__tmp_3 = ycirc->PutCONSGate( _tmp_3 ,bitlen);
        s_y_r1out[i][j] = ycirc->PutMUXGate( s_y_c1out[i][j] , s_y__tmp_3 , s_y_tmp_1 );
    }
}
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_a_r1out[_i1][_i4] = acirc->PutY2AGate( s_y_r1out[_i1][_i4] ,bcirc);
}
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        s_a_t1[i+1][j+1] = create_new_share(s_a_r1out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t1[i][0] = 0 ;
    s_a_t1[i][0] = acirc->PutCONSGate( t1[i][0] ,bitlen);
    t1[i][1025] = 0 ;
    s_a_t1[i][1025] = acirc->PutCONSGate( t1[i][1025] ,bitlen);
}
for (uint32_t i = 1; i < 1025; i++)
{
    t1[0][i] = 0 ;
    s_a_t1[0][i] = acirc->PutCONSGate( t1[0][i] ,bitlen);
    t1[65][i] = 0 ;
    s_a_t1[65][i] = acirc->PutCONSGate( t1[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c2in[i*9+3*l+m][j] = acirc->PutADDGate( s_a_t1[i+l][j+m] , s_a_Rc2in[i*9+3*l+m][j] );
            }
        }
    }
}
uint32_t _tmp_5 = 1 ;
share * s_a__tmp_5 = acirc->PutCONSGate( _tmp_5 ,bitlen);
share * s_a_tmp_4 = acirc->PutOUTGate( s_a__tmp_5 , ALL);
auto s_a_c2in_o = make_vector<share*>(576, 1024);
for(int i = 0; i < 576; i++) {
	for(int j = 0; j < 1024; j++) {
		s_a_c2in_o[i][j] = acirc->PutOUTGate(s_a_c2in[i][j], CLIENT);
	}
}
party->ExecCircuit();
if(role == CLIENT) {
	ofstream fout("c2in", std::ofstream::out | std::ofstream::app);
	for(int i = 0; i < 576; i++) {
		for(int j = 0; j < 1024; j++) {
			fout << i << " " << j << " " << (s_a_c2in_o[i][j]->get_clear_value<uint32_t>()) << endl;
		}
	}
	fout.close();
}
uint32_t _output6 = s_a_tmp_4->get_clear_value<uint32_t>();
