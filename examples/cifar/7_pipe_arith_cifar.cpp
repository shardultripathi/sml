ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 120000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto c4in = make_vector<uint32_t>(576, 256);
auto s_a_c4in = make_vector<share*>(576, 256);
auto w4 = make_vector<uint32_t>(64, 576);
auto s_a_w4 = make_vector<share*>(64, 576);
auto c4out = make_vector<uint32_t>(64, 256);
auto s_a_c4out = make_vector<share*>(64, 256);
auto r4out = make_vector<uint32_t>(64, 256);
auto s_a_r4out = make_vector<share*>(64, 256);
auto p2out = make_vector<uint32_t>(64, 64);
auto s_a_p2out = make_vector<share*>(64, 64);
auto c5in = make_vector<uint32_t>(576, 64);
auto s_a_c5in = make_vector<share*>(576, 64);
auto t4 = make_vector<uint32_t>(66, 66);
auto s_a_t4 = make_vector<share*>(66, 66);
auto w5 = make_vector<uint32_t>(64, 576);
auto s_a_w5 = make_vector<share*>(64, 576);
auto c5out = make_vector<uint32_t>(64, 64);
auto s_a_c5out = make_vector<share*>(64, 64);
auto r5out = make_vector<uint32_t>(64, 64);
auto s_a_r5out = make_vector<share*>(64, 64);
auto w6 = make_vector<uint32_t>(64, 64);
auto s_a_w6 = make_vector<share*>(64, 64);
auto c6out = make_vector<uint32_t>(64, 64);
auto s_a_c6out = make_vector<share*>(64, 64);
auto r6out = make_vector<uint32_t>(64, 64);
auto s_a_r6out = make_vector<share*>(64, 64);
auto w7 = make_vector<uint32_t>(16, 64);
auto s_a_w7 = make_vector<share*>(16, 64);
auto c7out = make_vector<uint32_t>(16, 64);
auto s_a_c7out = make_vector<share*>(16, 64);
auto r7out = make_vector<uint32_t>(16, 64);
auto s_a_r7out = make_vector<share*>(16, 64);
auto reshape = make_vector<uint32_t>(1024);
auto s_a_reshape = make_vector<share*>(1024);
auto w8 = make_vector<uint32_t>(10, 1024);
auto s_a_w8 = make_vector<share*>(10, 1024);
auto f1out = make_vector<uint32_t>(10);
auto s_a_f1out = make_vector<share*>(10);
auto Rc4in = make_vector<uint32_t>(576, 256);
auto s_a_Rc4in = make_vector<share*>(576, 256);
auto IRc4in = make_vector<uint32_t>(576, 256);
auto s_a_IRc4in = make_vector<share*>(576, 256);
if(role == SERVER){
ifstream fin("IRc4in");
while(!fin.eof()){
	uint32_t i, j, val;
	fin >> i >> j >> val;
	IRc4in[i][j] = val;
}
fin.close();
}
if(role == CLIENT){
ifstream fin("c4in");
while(!fin.eof()){
	uint32_t i, j, val;
	fin >> i >> j >> val;
	c4in[i][j] = val;
	s_a_c4in[i][j]= acirc->PutINGate(c4in[i][j] ,bitlen,CLIENT);
	
}
fin.close();
}
else {
 for(int i = 0; i <576;i++) {
	for (int j = 0; j <256; j++) {
		s_a_c4in[i][j] = acirc->PutDummyINGate(bitlen);
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
            w4[i][j] = 500 ;
            s_a_w4[i][j] = acirc->PutINGate( w4[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w4[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 576; j++)
    {
        if (role == CLIENT) {
            w5[i][j] = 500 ;
            s_a_w5[i][j] = acirc->PutINGate( w5[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w5[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        if (role == CLIENT) {
            w6[i][j] = 500 ;
            s_a_w6[i][j] = acirc->PutINGate( w6[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w6[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        if (role == CLIENT) {
            w7[i][j] = 500 ;
            s_a_w7[i][j] = acirc->PutINGate( w7[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w7[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    for (uint32_t j = 0; j < 1024; j++)
    {
        if (role == CLIENT) {
            w8[i][j] = 500 ;
            s_a_w8[i][j] = acirc->PutINGate( w8[i][j] ,bitlen,CLIENT);
        } else {
            s_a_w8[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        c4out[i][j] = 0 ;
        s_a_c4out[i][j] = acirc->PutCONSGate( c4out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_1 = acirc->PutSUBGate( s_a_c4in[k][j] , s_a_Rc4in[k][j] );
            share * s_a_tmp_0 = acirc->PutMULGate( s_a_w4[i][k] , s_a_tmp_1 );
            s_a_c4out[i][j] = acirc->PutADDGate( s_a_c4out[i][j] , s_a_tmp_0 );
        }
    }
}
auto s_y_c4out = make_vector<share*>(64, 256);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 256 ; _i4++) {
s_y_c4out[_i1][_i4] = ycirc->PutA2YGate( s_a_c4out[_i1][_i4] );
}
}
auto s_y_r4out = make_vector<share*>(64, 256);
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 256; j++)
    {
        uint32_t _tmp_3 = 1 ;
        share * s_y__tmp_3 = ycirc->PutCONSGate( _tmp_3 ,bitlen);
        share * s_y_tmp_2 = ycirc->PutGTGate( s_y_c4out[i][j] , s_y__tmp_3 );
        uint32_t _tmp_4 = 0 ;
        share * s_y__tmp_4 = ycirc->PutCONSGate( _tmp_4 ,bitlen);
        s_y_r4out[i][j] = ycirc->PutMUXGate( s_y_c4out[i][j] , s_y__tmp_4 , s_y_tmp_2 );
    }
}
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 256 ; _i4++) {
s_a_r4out[_i1][_i4] = acirc->PutY2AGate( s_y_r4out[_i1][_i4] ,bcirc);
}
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        p2out[i][j] = 0 ;
        s_a_p2out[i][j] = acirc->PutCONSGate( p2out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 2; k++)
        {
            for (uint32_t l = 0; l < 2; l++)
            {
                s_a_p2out[i][j] = acirc->PutADDGate( s_a_r4out[i][4*j+2*k+l] , s_a_p2out[i][j] );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        s_a_t4[i+1][j+1] = create_new_share(s_a_p2out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 66; i++)
{
    t4[i][0] = 0 ;
    s_a_t4[i][0] = acirc->PutCONSGate( t4[i][0] ,bitlen);
    t4[i][65] = 0 ;
    s_a_t4[i][65] = acirc->PutCONSGate( t4[i][65] ,bitlen);
}
for (uint32_t i = 1; i < 65; i++)
{
    t4[0][i] = 0 ;
    s_a_t4[0][i] = acirc->PutCONSGate( t4[0][i] ,bitlen);
    t4[65][i] = 0 ;
    s_a_t4[65][i] = acirc->PutCONSGate( t4[65][i] ,bitlen);
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        for (uint32_t l = 0; l < 3; l++)
        {
            for (uint32_t m = 0; m < 3; m++)
            {
                s_a_c5in[i*9+3*l+m][j] = create_new_share(s_a_t4[i+l][j+m]->get_wires(), acirc );
            }
        }
    }
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        c5out[i][j] = 0 ;
        s_a_c5out[i][j] = acirc->PutCONSGate( c5out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 576; k++)
        {
            share * s_a_tmp_5 = acirc->PutMULGate( s_a_w5[i][k] , s_a_c5in[k][j] );
            s_a_c5out[i][j] = acirc->PutADDGate( s_a_c5out[i][j] , s_a_tmp_5 );
        }
    }
}
auto s_y_c5out = make_vector<share*>(64, 64);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 64 ; _i4++) {
s_y_c5out[_i1][_i4] = ycirc->PutA2YGate( s_a_c5out[_i1][_i4] );
}
}
auto s_y_r5out = make_vector<share*>(64, 64);
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        uint32_t _tmp_7 = 1 ;
        share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
        share * s_y_tmp_6 = ycirc->PutGTGate( s_y_c5out[i][j] , s_y__tmp_7 );
        uint32_t _tmp_8 = 0 ;
        share * s_y__tmp_8 = ycirc->PutCONSGate( _tmp_8 ,bitlen);
        s_y_r5out[i][j] = ycirc->PutMUXGate( s_y_c5out[i][j] , s_y__tmp_8 , s_y_tmp_6 );
    }
}
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 64 ; _i4++) {
s_a_r5out[_i1][_i4] = acirc->PutY2AGate( s_y_r5out[_i1][_i4] ,bcirc);
}
}
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        c6out[i][j] = 0 ;
        s_a_c6out[i][j] = acirc->PutCONSGate( c6out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 64; k++)
        {
            share * s_a_tmp_9 = acirc->PutMULGate( s_a_w6[i][k] , s_a_r5out[k][j] );
            s_a_c6out[i][j] = acirc->PutADDGate( s_a_c6out[i][j] , s_a_tmp_9 );
        }
    }
}
auto s_y_c6out = make_vector<share*>(64, 64);
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 64 ; _i4++) {
s_y_c6out[_i1][_i4] = ycirc->PutA2YGate( s_a_c6out[_i1][_i4] );
}
}
auto s_y_r6out = make_vector<share*>(64, 64);
for (uint32_t i = 0; i < 64; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        uint32_t _tmp_11 = 1 ;
        share * s_y__tmp_11 = ycirc->PutCONSGate( _tmp_11 ,bitlen);
        share * s_y_tmp_10 = ycirc->PutGTGate( s_y_c6out[i][j] , s_y__tmp_11 );
        uint32_t _tmp_12 = 0 ;
        share * s_y__tmp_12 = ycirc->PutCONSGate( _tmp_12 ,bitlen);
        s_y_r6out[i][j] = ycirc->PutMUXGate( s_y_c6out[i][j] , s_y__tmp_12 , s_y_tmp_10 );
    }
}
for (int _i1 = 0; _i1 < 64 ; _i1++) {
for (int _i4 = 0; _i4 < 64 ; _i4++) {
s_a_r6out[_i1][_i4] = acirc->PutY2AGate( s_y_r6out[_i1][_i4] ,bcirc);
}
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        c7out[i][j] = 0 ;
        s_a_c7out[i][j] = acirc->PutCONSGate( c7out[i][j] ,bitlen);
        for (uint32_t k = 0; k < 64; k++)
        {
            share * s_a_tmp_13 = acirc->PutMULGate( s_a_w7[i][k] , s_a_r6out[k][j] );
            s_a_c7out[i][j] = acirc->PutADDGate( s_a_c7out[i][j] , s_a_tmp_13 );
        }
    }
}
auto s_y_c7out = make_vector<share*>(16, 64);
for (int _i1 = 0; _i1 < 16 ; _i1++) {
for (int _i4 = 0; _i4 < 64 ; _i4++) {
s_y_c7out[_i1][_i4] = ycirc->PutA2YGate( s_a_c7out[_i1][_i4] );
}
}
auto s_y_r7out = make_vector<share*>(16, 64);
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        uint32_t _tmp_15 = 1 ;
        share * s_y__tmp_15 = ycirc->PutCONSGate( _tmp_15 ,bitlen);
        share * s_y_tmp_14 = ycirc->PutGTGate( s_y_c7out[i][j] , s_y__tmp_15 );
        uint32_t _tmp_16 = 0 ;
        share * s_y__tmp_16 = ycirc->PutCONSGate( _tmp_16 ,bitlen);
        s_y_r7out[i][j] = ycirc->PutMUXGate( s_y_c7out[i][j] , s_y__tmp_16 , s_y_tmp_14 );
    }
}
for (int _i1 = 0; _i1 < 16 ; _i1++) {
for (int _i4 = 0; _i4 < 64 ; _i4++) {
s_a_r7out[_i1][_i4] = acirc->PutY2AGate( s_y_r7out[_i1][_i4] ,bcirc);
}
}
for (uint32_t i = 0; i < 16; i++)
{
    for (uint32_t j = 0; j < 64; j++)
    {
        s_a_reshape[64*i+j] = create_new_share(s_a_r7out[i][j]->get_wires(), acirc );
    }
}
for (uint32_t i = 0; i < 10; i++)
{
    f1out[i] = 0 ;
    s_a_f1out[i] = acirc->PutCONSGate( f1out[i] ,bitlen);
    for (uint32_t j = 0; j < 1024; j++)
    {
        share * s_a_tmp_17 = acirc->PutMULGate( s_a_w8[i][j] , s_a_reshape[j] );
        s_a_f1out[i] = acirc->PutADDGate( s_a_f1out[i] , s_a_tmp_17 );
    }
}
uint32_t _tmp_19 = 1 ;
share * s_a__tmp_19 = acirc->PutCONSGate( _tmp_19 ,bitlen);
share * s_a_tmp_18 = acirc->PutOUTGate( s_a__tmp_19 , ALL);
party->ExecCircuit();
uint32_t _output20 = s_a_tmp_18->get_clear_value<uint32_t>();
