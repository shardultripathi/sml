ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 120000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto c2in = make_vector<uint32_t>(576, 1024);
auto s_a_c2in = make_vector<share*>(576, 1024);
auto w2 = make_vector<uint32_t>(64, 576);
auto s_a_w2 = make_vector<share*>(64, 576);
auto c2out = make_vector<uint32_t>(64, 1024);
auto s_a_c2out = make_vector<share*>(64, 1024);
auto Rc2in = make_vector<uint32_t>(576, 1024);
auto s_a_Rc2in = make_vector<share*>(576, 1024);
auto IRc2in = make_vector<uint32_t>(576, 1024);
auto s_a_IRc2in = make_vector<share*>(576, 1024);
auto Rc2outIS0IE16 = make_vector<uint32_t>(64, 1024);
auto s_a_Rc2outIS0IE16 = make_vector<share*>(64, 1024);
auto IRc2outIS0IE16 = make_vector<uint32_t>(64, 1024);
auto s_a_IRc2outIS0IE16 = make_vector<share*>(64, 1024);
if(role == SERVER){
ifstream fin("IRc2in");
while(!fin.eof()){
	uint32_t i, j, val;
	fin >> i >> j >> val;
	IRc2in[i][j] = val;
}
fin.close();
}
if(role == CLIENT){
ifstream fin("c2in");
while(!fin.eof()){
	uint32_t i, j, val;
	fin >> i >> j >> val;
	c2in[i][j] = val;
	s_a_c2in[i][j]= acirc->PutINGate(c2in[i][j] ,bitlen,CLIENT);
	
}
fin.close();
}
else {
 for(int i = 0; i <576;i++) {
	for (int j = 0; j <1024; j++) {
		s_a_c2in[i][j] = acirc->PutDummyINGate(bitlen);
	}
}
}
if(role == SERVER){
ofstream fout("IRc2out", std::ofstream::out | std::ofstream::app);
for(int i = 0; i < 16; i++) {
	for(int j = 0; j < 1024; j++) {
		fout << i << " " << j << " " <<(IRc2outIS0IE16[i][j] = rand()) << endl;
	}
}
fout.close();
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
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        if (role == SERVER) {
            Rc2outIS0IE16[i][j] = IRc2outIS0IE16[i][j] ;
            s_a_Rc2outIS0IE16[i][j] = acirc->PutINGate( Rc2outIS0IE16[i][j] ,bitlen,SERVER);
        } else {
            s_a_Rc2outIS0IE16[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == CLIENT) {
            w2[i][j] = 500 ;
            s_a_w2[i][j] = acirc->PutINGate( w2[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w2[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        c2out[i][j] = 0 ;
        s_a_c2out[i][j] = acirc->PutCONSGate( c2out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_1 = acirc->PutSUBGate( s_a_c2in[k][j] , s_a_Rc2in[k][j] );
            share * s_a_tmp_0 = acirc->PutMULGate( s_a_w2[i][k] , s_a_tmp_1 );
            s_a_c2out[i][j] = acirc->PutADDGate( s_a_c2out[i][j] , s_a_tmp_0 );
        }
        s_a_c2out[i][j] = acirc->PutADDGate( s_a_c2out[i][j] , s_a_Rc2outIS0IE16[i][j] );
    }
}
uint32_t _tmp_3 = 1 ;
share * s_a__tmp_3 = acirc->PutCONSGate( _tmp_3 ,bitlen);
share * s_a_tmp_2 = acirc->PutOUTGate( s_a__tmp_3 , ALL);
auto s_a_c2out_o = make_vector<share*>(64, 1024);
for(int i = 0; i < 16; i++) {
	for(int j = 0; j < 1024; j++) {
		s_a_c2out_o[i][j] = acirc->PutOUTGate(s_a_c2out[i][j], CLIENT);
	}
}
party->ExecCircuit();
if(role == CLIENT) {
	ofstream fout("c2out", std::ofstream::out | std::ofstream::app);
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 1024; j++) {
			fout << i << " " << j << " " << (s_a_c2out_o[i][j]->get_clear_value<uint32_t>()) << endl;
		}
	}
	fout.close();
}
uint32_t _output4 = s_a_tmp_2->get_clear_value<uint32_t>();
