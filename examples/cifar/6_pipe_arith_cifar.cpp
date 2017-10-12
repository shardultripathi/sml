ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 120000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto c2out = make_vector<uint32_t>(64, 1024);
auto s_a_c2out = make_vector<share*>(64, 1024);
auto r2out = make_vector<uint32_t>(64, 1024);
auto s_a_r2out = make_vector<share*>(64, 1024);
auto p1out = make_vector<uint32_t>(64, 256);
auto s_a_p1out = make_vector<share*>(64, 256);
auto c3in = make_vector<uint32_t>(576, 256);
auto s_a_c3in = make_vector<share*>(576, 256);
auto t2 = make_vector<uint32_t>(66, 258);
auto s_a_t2 = make_vector<share*>(66, 258);
auto w3 = make_vector<uint32_t>(64, 576);
auto s_a_w3 = make_vector<share*>(64, 576);
auto c3out = make_vector<uint32_t>(64, 256);
auto s_a_c3out = make_vector<share*>(64, 256);
auto r3out = make_vector<uint32_t>(64, 256);
auto s_a_r3out = make_vector<share*>(64, 256);
auto c4in = make_vector<uint32_t>(576, 256);
auto s_a_c4in = make_vector<share*>(576, 256);
auto t3 = make_vector<uint32_t>(66, 258);
auto s_a_t3 = make_vector<share*>(66, 258);
auto Rc2out = make_vector<uint32_t>(64, 1024);
auto s_a_Rc2out = make_vector<share*>(64, 1024);
auto IRc2out = make_vector<uint32_t>(64, 1024);
auto s_a_IRc2out = make_vector<share*>(64, 1024);
auto Rc4in = make_vector<uint32_t>(576, 256);
auto s_a_Rc4in = make_vector<share*>(576, 256);
auto IRc4in = make_vector<uint32_t>(576, 256);
auto s_a_IRc4in = make_vector<share*>(576, 256);
if(role == SERVER){
ifstream fin("IRc2out");
while(!fin.eof()){
	uint32_t i, j, val;
	fin >> i >> j >> val;
	IRc2out[i][j] = val;
}
fin.close();
}
if(role == CLIENT){
ifstream fin("c2out");
while(!fin.eof()){
	uint32_t i, j, val;
	fin >> i >> j >> val;
	c2out[i][j] = val;
	s_a_c2out[i][j]= acirc->PutINGate(c2out[i][j] ,bitlen,CLIENT);
	
}
fin.close();
}
else {
 for(int i = 0; i <64;i++) {
	for (int j = 0; j <1024; j++) {
		s_a_c2out[i][j] = acirc->PutDummyINGate(bitlen);
	}
}
}
if(role == SERVER){
ofstream fout("IRc4in", std::ofstream::out | std::ofstream::app);
for(int i = 0; i < 576; i++) {
	for(int j = 0; j < 256; j++) {
		fout << i << " " << j << " " <<(IRc4in[i][j] = rand()) << endl;
	}
}
fout.close();
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        if (role == SERVER) {
            Rc2out[i][j] = IRc2out[i][j] ;
            s_a_Rc2out[i][j] = acirc->PutINGate( Rc2out[i][j] ,bitlen,SERVER);
        } else {
            s_a_Rc2out[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 576; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        if (role == SERVER) {
            Rc4in[i][j] = IRc4in[i][j] ;
            s_a_Rc4in[i][j] = acirc->PutINGate( Rc4in[i][j] ,bitlen,SERVER);
        } else {
            s_a_Rc4in[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == CLIENT) {
            w3[i][j] = 500 ;
            s_a_w3[i][j] = acirc->PutINGate( w3[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w3[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
uint32_t tmp;
share *s_a_tmp;
auto s_y_c2out = make_vector<share*>(64, 1024);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_y_c2out[_i1][_i4] = ycirc->PutA2YGate( s_a_c2out[_i1][_i4] );
}
}
auto s_y_Rc2out = make_vector<share*>(64, 1024);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_y_Rc2out[_i1][_i4] = ycirc->PutA2YGate( s_a_Rc2out[_i1][_i4] );
}
}
share * s_y_tmp ;
auto s_y_r2out = make_vector<share*>(64, 1024);
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        s_y_tmp = ycirc->PutSUBGate( s_y_c2out[i][j] , s_y_Rc2out[i][j] );
        uint32_t _tmp_1 = 1 ;
        share * s_y__tmp_1 = ycirc->PutCONSGate( _tmp_1 ,bitlen);
        share * s_y_tmp_0 = ycirc->PutGTGate( s_y_tmp , s_y__tmp_1 );
        uint32_t _tmp_2 = 0 ;
        share * s_y__tmp_2 = ycirc->PutCONSGate( _tmp_2 ,bitlen);
        s_y_r2out[i][j] = ycirc->PutMUXGate( s_y_tmp , s_y__tmp_2 , s_y_tmp_0 );
    }
}
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 1024 ; _i4++) {
s_a_r2out[_i1][_i4] = acirc->PutY2AGate( s_y_r2out[_i1][_i4] ,bcirc);
}
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        p1out[i][j] = 0 ;
        s_a_p1out[i][j] = acirc->PutCONSGate( p1out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 2; k++)
        {
            for (uint32_t l = 0; l < 2; l++)
            {
                s_a_p1out[i][j] = acirc->PutADDGate( s_a_r2out[i][4*j+2*k+l] , s_a_p1out[i][j] );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        s_a_t2[i+1][j+1] = create_new_share(s_a_p1out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t2[i][0] = 0 ;
    s_a_t2[i][0] = acirc->PutCONSGate( t2[i][0] ,bitlen);
    t2[i][257] = 0 ;
    s_a_t2[i][257] = acirc->PutCONSGate( t2[i][257] ,bitlen);
}
for (uint32_t i = 1; i < 257; i++)
{
    t2[0][i] = 0 ;
    s_a_t2[0][i] = acirc->PutCONSGate( t2[0][i] ,bitlen);
    t2[65][i] = 0 ;
    s_a_t2[65][i] = acirc->PutCONSGate( t2[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c3in[i*9+3*l+m][j] = create_new_share(s_a_t2[i+l][j+m]->get_wires(), acirc );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        c3out[i][j] = 0 ;
        s_a_c3out[i][j] = acirc->PutCONSGate( c3out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_3 = acirc->PutMULGate( s_a_w3[i][k] , s_a_c3in[k][j] );
            s_a_c3out[i][j] = acirc->PutADDGate( s_a_c3out[i][j] , s_a_tmp_3 );
        }
    }
}
auto s_y_c3out = make_vector<share*>(64, 256);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 256 ; _i4++) {
s_y_c3out[_i1][_i4] = ycirc->PutA2YGate( s_a_c3out[_i1][_i4] );
}
}
auto s_y_r3out = make_vector<share*>(64, 256);
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        uint32_t _tmp_5 = 1 ;
        share * s_y__tmp_5 = ycirc->PutCONSGate( _tmp_5 ,bitlen);
        share * s_y_tmp_4 = ycirc->PutGTGate( s_y_c3out[i][j] , s_y__tmp_5 );
        uint32_t _tmp_6 = 0 ;
        share * s_y__tmp_6 = ycirc->PutCONSGate( _tmp_6 ,bitlen);
        s_y_r3out[i][j] = ycirc->PutMUXGate( s_y_c3out[i][j] , s_y__tmp_6 , s_y_tmp_4 );
    }
}
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 256 ; _i4++) {
s_a_r3out[_i1][_i4] = acirc->PutY2AGate( s_y_r3out[_i1][_i4] ,bcirc);
}
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        s_a_t3[i+1][j+1] = create_new_share(s_a_r3out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t3[i][0] = 0 ;
    s_a_t3[i][0] = acirc->PutCONSGate( t3[i][0] ,bitlen);
    t3[i][257] = 0 ;
    s_a_t3[i][257] = acirc->PutCONSGate( t3[i][257] ,bitlen);
}
for (uint32_t i = 1; i < 257; i++)
{
    t3[0][i] = 0 ;
    s_a_t3[0][i] = acirc->PutCONSGate( t3[0][i] ,bitlen);
    t3[65][i] = 0 ;
    s_a_t3[65][i] = acirc->PutCONSGate( t3[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c4in[i*9+3*l+m][j] = acirc->PutADDGate( s_a_t3[i+l][j+m] , s_a_Rc4in[i*9+3*l+m][j] );
            }
        }
    }
}
uint32_t _tmp_8 = 1 ;
share * s_a__tmp_8 = acirc->PutCONSGate( _tmp_8 ,bitlen);
share * s_a_tmp_7 = acirc->PutOUTGate( s_a__tmp_8 , ALL);
auto s_a_c4in_o = make_vector<share*>(576, 256);
for(int i = 0; i < 576; i++) {
	for(int j = 0; j < 256; j++) {
		s_a_c4in_o[i][j] = acirc->PutOUTGate(s_a_c4in[i][j], CLIENT);
	}
}
party->ExecCircuit();
if(role == CLIENT) {
	ofstream fout("c4in", std::ofstream::out | std::ofstream::app);
	for(int i = 0; i < 576; i++) {
		for(int j = 0; j < 256; j++) {
			fout << i << " " << j << " " << (s_a_c4in_o[i][j]->get_clear_value<uint32_t>()) << endl;
		}
	}
	fout.close();
}
uint32_t _output9 = s_a_tmp_7->get_clear_value<uint32_t>();
