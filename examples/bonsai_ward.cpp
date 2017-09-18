ABYParty *party = new ABYParty(role, address, port, seclvl, bitlen, nthreads, mt_alg, 100000000);
vector<Sharing*>& sharings = party->GetSharings();
Circuit* ycirc = sharings[S_YAO]->GetCircuitBuildRoutine();
Circuit* acirc = sharings[S_ARITH]->GetCircuitBuildRoutine();
Circuit* bcirc = sharings[S_BOOL]->GetCircuitBuildRoutine();
auto testX = make_vector<uint32_t>(1000);
auto s_a_testX = make_vector<share*>(1000);
for (uint32_t i = 0; i < 1000; i++)
{
    if (role == SERVER) {
        testX[i] = 50 ;
        s_a_testX[i] = acirc->PutINGate( testX[i] ,bitlen,SERVER);
    } else {
        s_a_testX[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto Z = make_vector<uint32_t>(7, 1000);
auto s_a_Z = make_vector<share*>(7, 1000);
for (uint32_t i = 0; i < 7; i++)
{
    for (uint32_t j = 0; j < 1000; j++)
    {
        if (role == CLIENT) {
            Z[i][j] = 1000 ;
            s_a_Z[i][j] = acirc->PutINGate( Z[i][j] ,bitlen,CLIENT);
        } else {
            s_a_Z[i][j] = acirc->PutDummyINGate(bitlen);
        }
    }
}
auto ZX = make_vector<uint32_t>(7);
auto s_a_ZX = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    ZX[i] = 0 ;
    s_a_ZX[i] = acirc->PutCONSGate( ZX[i] ,bitlen);
    for (uint32_t j = 0; j < 1000; j++)
    {
        share * s_a_tmp_0 = acirc->PutMULGate( s_a_testX[i] , s_a_Z[i][j] );
        s_a_ZX[i] = acirc->PutADDGate( s_a_ZX[i] , s_a_tmp_0 );
    }
}
uint32_t Score;
share *s_a_Score;
Score = 0 ;
s_a_Score = acirc->PutCONSGate( Score ,bitlen);
uint32_t curr;
share *s_a_curr;
curr = 0 ;
s_a_curr = acirc->PutCONSGate( curr ,bitlen);
uint32_t VZX;
share *s_a_VZX;
VZX = 0 ;
s_a_VZX = acirc->PutCONSGate( VZX ,bitlen);
auto V = make_vector<uint32_t>(7);
auto s_a_V = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V[i] = 150 ;
        s_a_V[i] = acirc->PutINGate( V[i] ,bitlen,CLIENT);
    } else {
        s_a_V[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i = 0; i < 7; i++)
{
    share * s_a_tmp_1 = acirc->PutMULGate( s_a_V[i] , s_a_ZX[i] );
    s_a_VZX = acirc->PutADDGate( s_a_VZX , s_a_tmp_1 );
}
share *s_y_VZX = ycirc->PutA2YGate( s_a_VZX );
uint32_t _tmp_3 = 100 ;
share * s_y__tmp_3 = ycirc->PutCONSGate( _tmp_3 ,bitlen);
share * s_y_tmp_2 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_3 );
uint32_t _tmp_4 = 100 ;
share * s_y__tmp_4 = ycirc->PutCONSGate( _tmp_4 ,bitlen);
uint32_t _tmp_7 = 10 ;
share * s_y__tmp_7 = ycirc->PutCONSGate( _tmp_7 ,bitlen);
share * s_y_tmp_6 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_7 );
uint32_t _tmp_8 = 10 ;
share * s_y__tmp_8 = ycirc->PutCONSGate( _tmp_8 ,bitlen);
share * s_y_tmp_5 = ycirc->PutMUXGate( s_y_VZX , s_y__tmp_8 , s_y_tmp_6 );
s_y_VZX = ycirc->PutMUXGate( s_y__tmp_4 , s_y_tmp_5 , s_y_tmp_2 );
uint32_t WZX;
share *s_y_WZX;
WZX = 0 ;
s_y_WZX = ycirc->PutCONSGate( WZX ,bitlen);
auto W = make_vector<uint32_t>(7);
auto s_y_W = make_vector<share*>(7);
auto s_a_W = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W[i] = 150 ;
        s_a_W[i] = acirc->PutINGate( W[i] ,bitlen,CLIENT);
    } else {
        s_a_W[i] = acirc->PutDummyINGate(bitlen);
    }
}
share *s_a_WZX = acirc->PutY2AGate( s_y_WZX ,bcirc);
for (uint32_t i = 0; i < 7; i++)
{
    share * s_a_tmp_9 = acirc->PutMULGate( s_a_W[i] , s_a_ZX[i] );
    s_a_WZX = acirc->PutADDGate( s_a_WZX , s_a_tmp_9 );
}
s_a_VZX = acirc->PutY2AGate( s_y_VZX ,bcirc);
share * s_a_tmp_10 = acirc->PutMULGate( s_a_VZX , s_a_WZX );
s_a_Score = acirc->PutADDGate( s_a_Score , s_a_tmp_10 );
uint32_t TZX;
share *s_a_TZX;
TZX = 0 ;
s_a_TZX = acirc->PutCONSGate( TZX ,bitlen);
auto T = make_vector<uint32_t>(7);
auto s_a_T = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        T[i] = 150 ;
        s_a_T[i] = acirc->PutINGate( T[i] ,bitlen,CLIENT);
    } else {
        s_a_T[i] = acirc->PutDummyINGate(bitlen);
    }
}
for (uint32_t i = 0; i < 7; i++)
{
    share * s_a_tmp_11 = acirc->PutMULGate( s_a_T[i] , s_a_ZX[i] );
    s_a_TZX = acirc->PutADDGate( s_a_TZX , s_a_tmp_11 );
}
share *s_y_TZX = ycirc->PutA2YGate( s_a_TZX );
uint32_t _tmp_13 = 100 ;
share * s_y__tmp_13 = ycirc->PutCONSGate( _tmp_13 ,bitlen);
share * s_y_tmp_12 = ycirc->PutGTGate( s_y_TZX , s_y__tmp_13 );
uint32_t _tmp_16 = 2 ;
share * s_a__tmp_16 = acirc->PutCONSGate( _tmp_16 ,bitlen);
share * s_a_tmp_15 = acirc->PutMULGate( s_a__tmp_16 , s_a_curr );
uint32_t _tmp_17 = 1 ;
share * s_a__tmp_17 = acirc->PutCONSGate( _tmp_17 ,bitlen);
share * s_a_tmp_14 = acirc->PutADDGate( s_a_tmp_15 , s_a__tmp_17 );
uint32_t _tmp_20 = 2 ;
share * s_a__tmp_20 = acirc->PutCONSGate( _tmp_20 ,bitlen);
share * s_a_tmp_19 = acirc->PutMULGate( s_a__tmp_20 , s_a_curr );
uint32_t _tmp_21 = 2 ;
share * s_a__tmp_21 = acirc->PutCONSGate( _tmp_21 ,bitlen);
share * s_a_tmp_18 = acirc->PutADDGate( s_a_tmp_19 , s_a__tmp_21 );
share *s_y_tmp_14 = ycirc->PutA2YGate( s_a_tmp_14 );
share *s_y_tmp_18 = ycirc->PutA2YGate( s_a_tmp_18 );
share * s_y_curr = ycirc->PutMUXGate( s_y_tmp_14 , s_y_tmp_18 , s_y_tmp_12 );
auto V1 = make_vector<uint32_t>(7);
auto s_y_V1 = make_vector<share*>(7);
auto s_a_V1 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V1[i] = 150 ;
        s_a_V1[i] = acirc->PutINGate( V1[i] ,bitlen,CLIENT);
    } else {
        s_a_V1[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V2 = make_vector<uint32_t>(7);
auto s_a_V2 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V2[i] = 150 ;
        s_a_V2[i] = acirc->PutINGate( V2[i] ,bitlen,CLIENT);
    } else {
        s_a_V2[i] = acirc->PutDummyINGate(bitlen);
    }
}
VZX = 0 ;
s_a_VZX = acirc->PutCONSGate( VZX ,bitlen);
uint32_t tmp;
share *s_a_tmp;
auto s_y_V2 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V2[_i1] = ycirc->PutA2YGate( s_a_V2[_i1] );
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V1[_i1] = ycirc->PutA2YGate( s_a_V1[_i1] );
}
share * s_y_tmp ;
s_y_VZX = ycirc->PutA2YGate( s_a_VZX );
auto s_y_ZX = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_ZX[_i1] = ycirc->PutA2YGate( s_a_ZX[_i1] );
}
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_23 = 1 ;
    share * s_y__tmp_23 = ycirc->PutCONSGate( _tmp_23 ,bitlen);
    share * s_y_tmp_22 = ycirc->PutGTGate( s_y_curr , s_y__tmp_23 );
    s_y_tmp = ycirc->PutMUXGate( s_y_V2[i] , s_y_V1[i] , s_y_tmp_22 );
    share * s_y_tmp_24 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_VZX = ycirc->PutADDGate( s_y_VZX , s_y_tmp_24 );
}
uint32_t _tmp_26 = 100 ;
share * s_y__tmp_26 = ycirc->PutCONSGate( _tmp_26 ,bitlen);
share * s_y_tmp_25 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_26 );
uint32_t _tmp_27 = 100 ;
share * s_y__tmp_27 = ycirc->PutCONSGate( _tmp_27 ,bitlen);
uint32_t _tmp_30 = 10 ;
share * s_y__tmp_30 = ycirc->PutCONSGate( _tmp_30 ,bitlen);
share * s_y_tmp_29 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_30 );
uint32_t _tmp_31 = 10 ;
share * s_y__tmp_31 = ycirc->PutCONSGate( _tmp_31 ,bitlen);
share * s_y_tmp_28 = ycirc->PutMUXGate( s_y_VZX , s_y__tmp_31 , s_y_tmp_29 );
s_y_VZX = ycirc->PutMUXGate( s_y__tmp_27 , s_y_tmp_28 , s_y_tmp_25 );
WZX = 0 ;
s_y_WZX = ycirc->PutCONSGate( WZX ,bitlen);
auto W1 = make_vector<uint32_t>(7);
auto s_y_W1 = make_vector<share*>(7);
auto s_a_W1 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W1[i] = 150 ;
        s_a_W1[i] = acirc->PutINGate( W1[i] ,bitlen,CLIENT);
    } else {
        s_a_W1[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W2 = make_vector<uint32_t>(7);
auto s_a_W2 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W2[i] = 150 ;
        s_a_W2[i] = acirc->PutINGate( W2[i] ,bitlen,CLIENT);
    } else {
        s_a_W2[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto s_y_W2 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W2[_i1] = ycirc->PutA2YGate( s_a_W2[_i1] );
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W1[_i1] = ycirc->PutA2YGate( s_a_W1[_i1] );
}
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_33 = 1 ;
    share * s_y__tmp_33 = ycirc->PutCONSGate( _tmp_33 ,bitlen);
    share * s_y_tmp_32 = ycirc->PutGTGate( s_y_curr , s_y__tmp_33 );
    s_y_tmp = ycirc->PutMUXGate( s_y_W2[i] , s_y_W1[i] , s_y_tmp_32 );
    share * s_y_tmp_34 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_WZX = ycirc->PutADDGate( s_y_WZX , s_y_tmp_34 );
}
s_a_VZX = acirc->PutY2AGate( s_y_VZX ,bcirc);
s_a_WZX = acirc->PutY2AGate( s_y_WZX ,bcirc);
share * s_a_tmp_35 = acirc->PutMULGate( s_a_VZX , s_a_WZX );
s_a_Score = acirc->PutADDGate( s_a_Score , s_a_tmp_35 );
TZX = 0 ;
s_a_TZX = acirc->PutCONSGate( TZX ,bitlen);
auto T1 = make_vector<uint32_t>(7);
auto s_a_T1 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        T1[i] = 150 ;
        s_a_T1[i] = acirc->PutINGate( T1[i] ,bitlen,CLIENT);
    } else {
        s_a_T1[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto T2 = make_vector<uint32_t>(7);
auto s_a_T2 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        T2[i] = 150 ;
        s_a_T2[i] = acirc->PutINGate( T2[i] ,bitlen,CLIENT);
    } else {
        s_a_T2[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto s_y_T2 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_T2[_i1] = ycirc->PutA2YGate( s_a_T2[_i1] );
}
auto s_y_T1 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_T1[_i1] = ycirc->PutA2YGate( s_a_T1[_i1] );
}
s_y_TZX = ycirc->PutA2YGate( s_a_TZX );
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_37 = 1 ;
    share * s_y__tmp_37 = ycirc->PutCONSGate( _tmp_37 ,bitlen);
    share * s_y_tmp_36 = ycirc->PutGTGate( s_y_curr , s_y__tmp_37 );
    s_y_tmp = ycirc->PutMUXGate( s_y_T2[i] , s_y_T1[i] , s_y_tmp_36 );
    share * s_y_tmp_38 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_TZX = ycirc->PutADDGate( s_y_TZX , s_y_tmp_38 );
}
uint32_t _tmp_40 = 100 ;
share * s_y__tmp_40 = ycirc->PutCONSGate( _tmp_40 ,bitlen);
share * s_y_tmp_39 = ycirc->PutGTGate( s_y_TZX , s_y__tmp_40 );
uint32_t _tmp_43 = 2 ;
share * s_a__tmp_43 = acirc->PutCONSGate( _tmp_43 ,bitlen);
s_a_curr = acirc->PutY2AGate( s_y_curr ,bcirc);
share * s_a_tmp_42 = acirc->PutMULGate( s_a__tmp_43 , s_a_curr );
uint32_t _tmp_44 = 1 ;
share * s_a__tmp_44 = acirc->PutCONSGate( _tmp_44 ,bitlen);
share * s_a_tmp_41 = acirc->PutADDGate( s_a_tmp_42 , s_a__tmp_44 );
uint32_t _tmp_47 = 2 ;
share * s_a__tmp_47 = acirc->PutCONSGate( _tmp_47 ,bitlen);
share * s_a_tmp_46 = acirc->PutMULGate( s_a__tmp_47 , s_a_curr );
uint32_t _tmp_48 = 2 ;
share * s_a__tmp_48 = acirc->PutCONSGate( _tmp_48 ,bitlen);
share * s_a_tmp_45 = acirc->PutADDGate( s_a_tmp_46 , s_a__tmp_48 );
share *s_y_tmp_41 = ycirc->PutA2YGate( s_a_tmp_41 );
share *s_y_tmp_45 = ycirc->PutA2YGate( s_a_tmp_45 );
s_y_curr = ycirc->PutMUXGate( s_y_tmp_41 , s_y_tmp_45 , s_y_tmp_39 );
auto V3 = make_vector<uint32_t>(7);
auto s_y_V3 = make_vector<share*>(7);
auto s_a_V3 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V3[i] = 150 ;
        s_a_V3[i] = acirc->PutINGate( V3[i] ,bitlen,CLIENT);
    } else {
        s_a_V3[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V4 = make_vector<uint32_t>(7);
auto s_a_V4 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V4[i] = 150 ;
        s_a_V4[i] = acirc->PutINGate( V4[i] ,bitlen,CLIENT);
    } else {
        s_a_V4[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V5 = make_vector<uint32_t>(7);
auto s_a_V5 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V5[i] = 150 ;
        s_a_V5[i] = acirc->PutINGate( V5[i] ,bitlen,CLIENT);
    } else {
        s_a_V5[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V6 = make_vector<uint32_t>(7);
auto s_a_V6 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V6[i] = 150 ;
        s_a_V6[i] = acirc->PutINGate( V6[i] ,bitlen,CLIENT);
    } else {
        s_a_V6[i] = acirc->PutDummyINGate(bitlen);
    }
}
VZX = 0 ;
s_a_VZX = acirc->PutCONSGate( VZX ,bitlen);
auto s_y_V6 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V6[_i1] = ycirc->PutA2YGate( s_a_V6[_i1] );
}
auto s_y_V5 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V5[_i1] = ycirc->PutA2YGate( s_a_V5[_i1] );
}
auto s_y_V4 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V4[_i1] = ycirc->PutA2YGate( s_a_V4[_i1] );
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V3[_i1] = ycirc->PutA2YGate( s_a_V3[_i1] );
}
s_y_VZX = ycirc->PutA2YGate( s_a_VZX );
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_50 = 4 ;
    share * s_y__tmp_50 = ycirc->PutCONSGate( _tmp_50 ,bitlen);
    share * s_y_tmp_49 = ycirc->PutGTGate( s_y_curr , s_y__tmp_50 );
    uint32_t _tmp_53 = 5 ;
    share * s_y__tmp_53 = ycirc->PutCONSGate( _tmp_53 ,bitlen);
    share * s_y_tmp_52 = ycirc->PutGTGate( s_y_curr , s_y__tmp_53 );
    share * s_y_tmp_51 = ycirc->PutMUXGate( s_y_V6[i] , s_y_V5[i] , s_y_tmp_52 );
    uint32_t _tmp_56 = 3 ;
    share * s_y__tmp_56 = ycirc->PutCONSGate( _tmp_56 ,bitlen);
    share * s_y_tmp_55 = ycirc->PutGTGate( s_y_curr , s_y__tmp_56 );
    share * s_y_tmp_54 = ycirc->PutMUXGate( s_y_V4[i] , s_y_V3[i] , s_y_tmp_55 );
    s_y_tmp = ycirc->PutMUXGate( s_y_tmp_51 , s_y_tmp_54 , s_y_tmp_49 );
    share * s_y_tmp_57 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_VZX = ycirc->PutADDGate( s_y_VZX , s_y_tmp_57 );
}
uint32_t _tmp_59 = 100 ;
share * s_y__tmp_59 = ycirc->PutCONSGate( _tmp_59 ,bitlen);
share * s_y_tmp_58 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_59 );
uint32_t _tmp_60 = 100 ;
share * s_y__tmp_60 = ycirc->PutCONSGate( _tmp_60 ,bitlen);
uint32_t _tmp_63 = 10 ;
share * s_y__tmp_63 = ycirc->PutCONSGate( _tmp_63 ,bitlen);
share * s_y_tmp_62 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_63 );
uint32_t _tmp_64 = 10 ;
share * s_y__tmp_64 = ycirc->PutCONSGate( _tmp_64 ,bitlen);
share * s_y_tmp_61 = ycirc->PutMUXGate( s_y_VZX , s_y__tmp_64 , s_y_tmp_62 );
s_y_VZX = ycirc->PutMUXGate( s_y__tmp_60 , s_y_tmp_61 , s_y_tmp_58 );
WZX = 0 ;
s_y_WZX = ycirc->PutCONSGate( WZX ,bitlen);
auto W3 = make_vector<uint32_t>(7);
auto s_y_W3 = make_vector<share*>(7);
auto s_a_W3 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W3[i] = 150 ;
        s_a_W3[i] = acirc->PutINGate( W3[i] ,bitlen,CLIENT);
    } else {
        s_a_W3[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W4 = make_vector<uint32_t>(7);
auto s_a_W4 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W4[i] = 150 ;
        s_a_W4[i] = acirc->PutINGate( W4[i] ,bitlen,CLIENT);
    } else {
        s_a_W4[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W5 = make_vector<uint32_t>(7);
auto s_a_W5 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W5[i] = 150 ;
        s_a_W5[i] = acirc->PutINGate( W5[i] ,bitlen,CLIENT);
    } else {
        s_a_W5[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W6 = make_vector<uint32_t>(7);
auto s_a_W6 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W6[i] = 150 ;
        s_a_W6[i] = acirc->PutINGate( W6[i] ,bitlen,CLIENT);
    } else {
        s_a_W6[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto s_y_W6 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W6[_i1] = ycirc->PutA2YGate( s_a_W6[_i1] );
}
auto s_y_W5 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W5[_i1] = ycirc->PutA2YGate( s_a_W5[_i1] );
}
auto s_y_W4 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W4[_i1] = ycirc->PutA2YGate( s_a_W4[_i1] );
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W3[_i1] = ycirc->PutA2YGate( s_a_W3[_i1] );
}
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_66 = 4 ;
    share * s_y__tmp_66 = ycirc->PutCONSGate( _tmp_66 ,bitlen);
    share * s_y_tmp_65 = ycirc->PutGTGate( s_y_curr , s_y__tmp_66 );
    uint32_t _tmp_69 = 5 ;
    share * s_y__tmp_69 = ycirc->PutCONSGate( _tmp_69 ,bitlen);
    share * s_y_tmp_68 = ycirc->PutGTGate( s_y_curr , s_y__tmp_69 );
    share * s_y_tmp_67 = ycirc->PutMUXGate( s_y_W6[i] , s_y_W5[i] , s_y_tmp_68 );
    uint32_t _tmp_72 = 3 ;
    share * s_y__tmp_72 = ycirc->PutCONSGate( _tmp_72 ,bitlen);
    share * s_y_tmp_71 = ycirc->PutGTGate( s_y_curr , s_y__tmp_72 );
    share * s_y_tmp_70 = ycirc->PutMUXGate( s_y_W4[i] , s_y_W3[i] , s_y_tmp_71 );
    s_y_tmp = ycirc->PutMUXGate( s_y_tmp_67 , s_y_tmp_70 , s_y_tmp_65 );
    share * s_y_tmp_73 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_WZX = ycirc->PutADDGate( s_y_WZX , s_y_tmp_73 );
}
s_a_VZX = acirc->PutY2AGate( s_y_VZX ,bcirc);
s_a_WZX = acirc->PutY2AGate( s_y_WZX ,bcirc);
share * s_a_tmp_74 = acirc->PutMULGate( s_a_VZX , s_a_WZX );
s_a_Score = acirc->PutADDGate( s_a_Score , s_a_tmp_74 );
TZX = 0 ;
s_a_TZX = acirc->PutCONSGate( TZX ,bitlen);
auto T3 = make_vector<uint32_t>(7);
auto s_a_T3 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        T3[i] = 150 ;
        s_a_T3[i] = acirc->PutINGate( T3[i] ,bitlen,CLIENT);
    } else {
        s_a_T3[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto T4 = make_vector<uint32_t>(7);
auto s_a_T4 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        T4[i] = 150 ;
        s_a_T4[i] = acirc->PutINGate( T4[i] ,bitlen,CLIENT);
    } else {
        s_a_T4[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto T5 = make_vector<uint32_t>(7);
auto s_a_T5 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        T5[i] = 150 ;
        s_a_T5[i] = acirc->PutINGate( T5[i] ,bitlen,CLIENT);
    } else {
        s_a_T5[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto T6 = make_vector<uint32_t>(7);
auto s_a_T6 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        T6[i] = 150 ;
        s_a_T6[i] = acirc->PutINGate( T6[i] ,bitlen,CLIENT);
    } else {
        s_a_T6[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto s_y_T6 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_T6[_i1] = ycirc->PutA2YGate( s_a_T6[_i1] );
}
auto s_y_T5 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_T5[_i1] = ycirc->PutA2YGate( s_a_T5[_i1] );
}
auto s_y_T4 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_T4[_i1] = ycirc->PutA2YGate( s_a_T4[_i1] );
}
auto s_y_T3 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_T3[_i1] = ycirc->PutA2YGate( s_a_T3[_i1] );
}
s_y_TZX = ycirc->PutA2YGate( s_a_TZX );
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_76 = 4 ;
    share * s_y__tmp_76 = ycirc->PutCONSGate( _tmp_76 ,bitlen);
    share * s_y_tmp_75 = ycirc->PutGTGate( s_y_curr , s_y__tmp_76 );
    uint32_t _tmp_79 = 5 ;
    share * s_y__tmp_79 = ycirc->PutCONSGate( _tmp_79 ,bitlen);
    share * s_y_tmp_78 = ycirc->PutGTGate( s_y_curr , s_y__tmp_79 );
    share * s_y_tmp_77 = ycirc->PutMUXGate( s_y_T6[i] , s_y_T5[i] , s_y_tmp_78 );
    uint32_t _tmp_82 = 3 ;
    share * s_y__tmp_82 = ycirc->PutCONSGate( _tmp_82 ,bitlen);
    share * s_y_tmp_81 = ycirc->PutGTGate( s_y_curr , s_y__tmp_82 );
    share * s_y_tmp_80 = ycirc->PutMUXGate( s_y_T4[i] , s_y_T3[i] , s_y_tmp_81 );
    s_y_tmp = ycirc->PutMUXGate( s_y_tmp_77 , s_y_tmp_80 , s_y_tmp_75 );
    share * s_y_tmp_83 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_TZX = ycirc->PutADDGate( s_y_TZX , s_y_tmp_83 );
}
uint32_t _tmp_85 = 100 ;
share * s_y__tmp_85 = ycirc->PutCONSGate( _tmp_85 ,bitlen);
share * s_y_tmp_84 = ycirc->PutGTGate( s_y_TZX , s_y__tmp_85 );
uint32_t _tmp_88 = 2 ;
share * s_a__tmp_88 = acirc->PutCONSGate( _tmp_88 ,bitlen);
s_a_curr = acirc->PutY2AGate( s_y_curr ,bcirc);
share * s_a_tmp_87 = acirc->PutMULGate( s_a__tmp_88 , s_a_curr );
uint32_t _tmp_89 = 1 ;
share * s_a__tmp_89 = acirc->PutCONSGate( _tmp_89 ,bitlen);
share * s_a_tmp_86 = acirc->PutADDGate( s_a_tmp_87 , s_a__tmp_89 );
uint32_t _tmp_92 = 2 ;
share * s_a__tmp_92 = acirc->PutCONSGate( _tmp_92 ,bitlen);
share * s_a_tmp_91 = acirc->PutMULGate( s_a__tmp_92 , s_a_curr );
uint32_t _tmp_93 = 2 ;
share * s_a__tmp_93 = acirc->PutCONSGate( _tmp_93 ,bitlen);
share * s_a_tmp_90 = acirc->PutADDGate( s_a_tmp_91 , s_a__tmp_93 );
share *s_y_tmp_86 = ycirc->PutA2YGate( s_a_tmp_86 );
share *s_y_tmp_90 = ycirc->PutA2YGate( s_a_tmp_90 );
s_y_curr = ycirc->PutMUXGate( s_y_tmp_86 , s_y_tmp_90 , s_y_tmp_84 );
auto V7 = make_vector<uint32_t>(7);
auto s_y_V7 = make_vector<share*>(7);
auto s_a_V7 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V7[i] = 150 ;
        s_a_V7[i] = acirc->PutINGate( V7[i] ,bitlen,CLIENT);
    } else {
        s_a_V7[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V8 = make_vector<uint32_t>(7);
auto s_a_V8 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V8[i] = 150 ;
        s_a_V8[i] = acirc->PutINGate( V8[i] ,bitlen,CLIENT);
    } else {
        s_a_V8[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V9 = make_vector<uint32_t>(7);
auto s_a_V9 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V9[i] = 150 ;
        s_a_V9[i] = acirc->PutINGate( V9[i] ,bitlen,CLIENT);
    } else {
        s_a_V9[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V10 = make_vector<uint32_t>(7);
auto s_a_V10 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V10[i] = 150 ;
        s_a_V10[i] = acirc->PutINGate( V10[i] ,bitlen,CLIENT);
    } else {
        s_a_V10[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V11 = make_vector<uint32_t>(7);
auto s_a_V11 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V11[i] = 150 ;
        s_a_V11[i] = acirc->PutINGate( V11[i] ,bitlen,CLIENT);
    } else {
        s_a_V11[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V12 = make_vector<uint32_t>(7);
auto s_a_V12 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V12[i] = 150 ;
        s_a_V12[i] = acirc->PutINGate( V12[i] ,bitlen,CLIENT);
    } else {
        s_a_V12[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V13 = make_vector<uint32_t>(7);
auto s_a_V13 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V13[i] = 150 ;
        s_a_V13[i] = acirc->PutINGate( V13[i] ,bitlen,CLIENT);
    } else {
        s_a_V13[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto V14 = make_vector<uint32_t>(7);
auto s_a_V14 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        V14[i] = 150 ;
        s_a_V14[i] = acirc->PutINGate( V14[i] ,bitlen,CLIENT);
    } else {
        s_a_V14[i] = acirc->PutDummyINGate(bitlen);
    }
}
VZX = 0 ;
s_a_VZX = acirc->PutCONSGate( VZX ,bitlen);
auto s_y_V14 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V14[_i1] = ycirc->PutA2YGate( s_a_V14[_i1] );
}
auto s_y_V13 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V13[_i1] = ycirc->PutA2YGate( s_a_V13[_i1] );
}
auto s_y_V12 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V12[_i1] = ycirc->PutA2YGate( s_a_V12[_i1] );
}
auto s_y_V11 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V11[_i1] = ycirc->PutA2YGate( s_a_V11[_i1] );
}
auto s_y_V10 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V10[_i1] = ycirc->PutA2YGate( s_a_V10[_i1] );
}
auto s_y_V9 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V9[_i1] = ycirc->PutA2YGate( s_a_V9[_i1] );
}
auto s_y_V8 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V8[_i1] = ycirc->PutA2YGate( s_a_V8[_i1] );
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_V7[_i1] = ycirc->PutA2YGate( s_a_V7[_i1] );
}
s_y_VZX = ycirc->PutA2YGate( s_a_VZX );
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_95 = 10 ;
    share * s_y__tmp_95 = ycirc->PutCONSGate( _tmp_95 ,bitlen);
    share * s_y_tmp_94 = ycirc->PutGTGate( s_y_curr , s_y__tmp_95 );
    uint32_t _tmp_98 = 12 ;
    share * s_y__tmp_98 = ycirc->PutCONSGate( _tmp_98 ,bitlen);
    share * s_y_tmp_97 = ycirc->PutGTGate( s_y_curr , s_y__tmp_98 );
    uint32_t _tmp_101 = 13 ;
    share * s_y__tmp_101 = ycirc->PutCONSGate( _tmp_101 ,bitlen);
    share * s_y_tmp_100 = ycirc->PutGTGate( s_y_curr , s_y__tmp_101 );
    share * s_y_tmp_99 = ycirc->PutMUXGate( s_y_V14[i] , s_y_V13[i] , s_y_tmp_100 );
    uint32_t _tmp_104 = 11 ;
    share * s_y__tmp_104 = ycirc->PutCONSGate( _tmp_104 ,bitlen);
    share * s_y_tmp_103 = ycirc->PutGTGate( s_y_curr , s_y__tmp_104 );
    share * s_y_tmp_102 = ycirc->PutMUXGate( s_y_V12[i] , s_y_V11[i] , s_y_tmp_103 );
    share * s_y_tmp_96 = ycirc->PutMUXGate( s_y_tmp_99 , s_y_tmp_102 , s_y_tmp_97 );
    uint32_t _tmp_107 = 8 ;
    share * s_y__tmp_107 = ycirc->PutCONSGate( _tmp_107 ,bitlen);
    share * s_y_tmp_106 = ycirc->PutGTGate( s_y_curr , s_y__tmp_107 );
    uint32_t _tmp_110 = 9 ;
    share * s_y__tmp_110 = ycirc->PutCONSGate( _tmp_110 ,bitlen);
    share * s_y_tmp_109 = ycirc->PutGTGate( s_y_curr , s_y__tmp_110 );
    share * s_y_tmp_108 = ycirc->PutMUXGate( s_y_V10[i] , s_y_V9[i] , s_y_tmp_109 );
    uint32_t _tmp_113 = 7 ;
    share * s_y__tmp_113 = ycirc->PutCONSGate( _tmp_113 ,bitlen);
    share * s_y_tmp_112 = ycirc->PutGTGate( s_y_curr , s_y__tmp_113 );
    share * s_y_tmp_111 = ycirc->PutMUXGate( s_y_V8[i] , s_y_V7[i] , s_y_tmp_112 );
    share * s_y_tmp_105 = ycirc->PutMUXGate( s_y_tmp_108 , s_y_tmp_111 , s_y_tmp_106 );
    s_y_tmp = ycirc->PutMUXGate( s_y_tmp_96 , s_y_tmp_105 , s_y_tmp_94 );
    share * s_y_tmp_114 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_VZX = ycirc->PutADDGate( s_y_VZX , s_y_tmp_114 );
}
uint32_t _tmp_116 = 100 ;
share * s_y__tmp_116 = ycirc->PutCONSGate( _tmp_116 ,bitlen);
share * s_y_tmp_115 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_116 );
uint32_t _tmp_117 = 100 ;
share * s_y__tmp_117 = ycirc->PutCONSGate( _tmp_117 ,bitlen);
uint32_t _tmp_120 = 10 ;
share * s_y__tmp_120 = ycirc->PutCONSGate( _tmp_120 ,bitlen);
share * s_y_tmp_119 = ycirc->PutGTGate( s_y_VZX , s_y__tmp_120 );
uint32_t _tmp_121 = 10 ;
share * s_y__tmp_121 = ycirc->PutCONSGate( _tmp_121 ,bitlen);
share * s_y_tmp_118 = ycirc->PutMUXGate( s_y_VZX , s_y__tmp_121 , s_y_tmp_119 );
s_y_VZX = ycirc->PutMUXGate( s_y__tmp_117 , s_y_tmp_118 , s_y_tmp_115 );
auto W7 = make_vector<uint32_t>(7);
auto s_y_W7 = make_vector<share*>(7);
auto s_a_W7 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W7[i] = 150 ;
        s_a_W7[i] = acirc->PutINGate( W7[i] ,bitlen,CLIENT);
    } else {
        s_a_W7[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W8 = make_vector<uint32_t>(7);
auto s_a_W8 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W8[i] = 150 ;
        s_a_W8[i] = acirc->PutINGate( W8[i] ,bitlen,CLIENT);
    } else {
        s_a_W8[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W9 = make_vector<uint32_t>(7);
auto s_a_W9 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W9[i] = 150 ;
        s_a_W9[i] = acirc->PutINGate( W9[i] ,bitlen,CLIENT);
    } else {
        s_a_W9[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W10 = make_vector<uint32_t>(7);
auto s_a_W10 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W10[i] = 150 ;
        s_a_W10[i] = acirc->PutINGate( W10[i] ,bitlen,CLIENT);
    } else {
        s_a_W10[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W11 = make_vector<uint32_t>(7);
auto s_a_W11 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W11[i] = 150 ;
        s_a_W11[i] = acirc->PutINGate( W11[i] ,bitlen,CLIENT);
    } else {
        s_a_W11[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W12 = make_vector<uint32_t>(7);
auto s_a_W12 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W12[i] = 150 ;
        s_a_W12[i] = acirc->PutINGate( W12[i] ,bitlen,CLIENT);
    } else {
        s_a_W12[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W13 = make_vector<uint32_t>(7);
auto s_a_W13 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W13[i] = 150 ;
        s_a_W13[i] = acirc->PutINGate( W13[i] ,bitlen,CLIENT);
    } else {
        s_a_W13[i] = acirc->PutDummyINGate(bitlen);
    }
}
auto W14 = make_vector<uint32_t>(7);
auto s_a_W14 = make_vector<share*>(7);
for (uint32_t i = 0; i < 7; i++)
{
    if (role == CLIENT) {
        W14[i] = 150 ;
        s_a_W14[i] = acirc->PutINGate( W14[i] ,bitlen,CLIENT);
    } else {
        s_a_W14[i] = acirc->PutDummyINGate(bitlen);
    }
}
WZX = 0 ;
s_a_WZX = acirc->PutCONSGate( WZX ,bitlen);
auto s_y_W14 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W14[_i1] = ycirc->PutA2YGate( s_a_W14[_i1] );
}
auto s_y_W13 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W13[_i1] = ycirc->PutA2YGate( s_a_W13[_i1] );
}
auto s_y_W12 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W12[_i1] = ycirc->PutA2YGate( s_a_W12[_i1] );
}
auto s_y_W10 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W10[_i1] = ycirc->PutA2YGate( s_a_W10[_i1] );
}
auto s_y_W9 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W9[_i1] = ycirc->PutA2YGate( s_a_W9[_i1] );
}
auto s_y_W8 = make_vector<share*>(7);
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W8[_i1] = ycirc->PutA2YGate( s_a_W8[_i1] );
}
for (int _i1 = 0; _i1 < 7 ; _i1++) {
s_y_W7[_i1] = ycirc->PutA2YGate( s_a_W7[_i1] );
}
s_y_WZX = ycirc->PutA2YGate( s_a_WZX );
for (uint32_t i = 0; i < 7; i++)
{
    uint32_t _tmp_123 = 10 ;
    share * s_y__tmp_123 = ycirc->PutCONSGate( _tmp_123 ,bitlen);
    share * s_y_tmp_122 = ycirc->PutGTGate( s_y_curr , s_y__tmp_123 );
    uint32_t _tmp_126 = 12 ;
    share * s_y__tmp_126 = ycirc->PutCONSGate( _tmp_126 ,bitlen);
    share * s_y_tmp_125 = ycirc->PutGTGate( s_y_curr , s_y__tmp_126 );
    uint32_t _tmp_129 = 13 ;
    share * s_y__tmp_129 = ycirc->PutCONSGate( _tmp_129 ,bitlen);
    share * s_y_tmp_128 = ycirc->PutGTGate( s_y_curr , s_y__tmp_129 );
    share * s_y_tmp_127 = ycirc->PutMUXGate( s_y_W14[i] , s_y_W13[i] , s_y_tmp_128 );
    uint32_t _tmp_132 = 11 ;
    share * s_y__tmp_132 = ycirc->PutCONSGate( _tmp_132 ,bitlen);
    share * s_y_tmp_131 = ycirc->PutGTGate( s_y_curr , s_y__tmp_132 );
    share * s_y_tmp_130 = ycirc->PutMUXGate( s_y_W12[i] , s_y_V11[i] , s_y_tmp_131 );
    share * s_y_tmp_124 = ycirc->PutMUXGate( s_y_tmp_127 , s_y_tmp_130 , s_y_tmp_125 );
    uint32_t _tmp_135 = 8 ;
    share * s_y__tmp_135 = ycirc->PutCONSGate( _tmp_135 ,bitlen);
    share * s_y_tmp_134 = ycirc->PutGTGate( s_y_curr , s_y__tmp_135 );
    uint32_t _tmp_138 = 9 ;
    share * s_y__tmp_138 = ycirc->PutCONSGate( _tmp_138 ,bitlen);
    share * s_y_tmp_137 = ycirc->PutGTGate( s_y_curr , s_y__tmp_138 );
    share * s_y_tmp_136 = ycirc->PutMUXGate( s_y_W10[i] , s_y_W9[i] , s_y_tmp_137 );
    uint32_t _tmp_141 = 7 ;
    share * s_y__tmp_141 = ycirc->PutCONSGate( _tmp_141 ,bitlen);
    share * s_y_tmp_140 = ycirc->PutGTGate( s_y_curr , s_y__tmp_141 );
    share * s_y_tmp_139 = ycirc->PutMUXGate( s_y_W8[i] , s_y_W7[i] , s_y_tmp_140 );
    share * s_y_tmp_133 = ycirc->PutMUXGate( s_y_tmp_136 , s_y_tmp_139 , s_y_tmp_134 );
    s_y_tmp = ycirc->PutMUXGate( s_y_tmp_124 , s_y_tmp_133 , s_y_tmp_122 );
    share * s_y_tmp_142 = ycirc->PutMULGate( s_y_tmp , s_y_ZX[i] );
    s_y_WZX = ycirc->PutADDGate( s_y_WZX , s_y_tmp_142 );
}
s_a_VZX = acirc->PutY2AGate( s_y_VZX ,bcirc);
s_a_WZX = acirc->PutY2AGate( s_y_WZX ,bcirc);
share * s_a_tmp_143 = acirc->PutMULGate( s_a_VZX , s_a_WZX );
s_a_Score = acirc->PutADDGate( s_a_Score , s_a_tmp_143 );
uint32_t out;
share *s_a_out;
share *s_y_Score = ycirc->PutA2YGate( s_a_Score );
uint32_t _tmp_145 = 100 ;
share * s_y__tmp_145 = ycirc->PutCONSGate( _tmp_145 ,bitlen);
share * s_y_tmp_144 = ycirc->PutGTGate( s_y_Score , s_y__tmp_145 );
uint32_t _tmp_146 = 1 ;
share * s_y__tmp_146 = ycirc->PutCONSGate( _tmp_146 ,bitlen);
uint32_t _tmp_147 = 0 ;
share * s_y__tmp_147 = ycirc->PutCONSGate( _tmp_147 ,bitlen);
share * s_y_out = ycirc->PutMUXGate( s_y__tmp_146 , s_y__tmp_147 , s_y_tmp_144 );
share * s_y_tmp_148 = ycirc->PutOUTGate( s_y_out , ALL);
party->ExecCircuit();
uint32_t _output = s_y_tmp_148->get_clear_value<uint32_t>();
