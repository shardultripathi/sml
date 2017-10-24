#include <iostream>
#include <vector>
using namespace std;
namespace details {
template<class T>struct tag{using type=T;};
template<class Tag>using type=typename Tag::type;
template<class T, size_t n>
struct n_dim_vec:tag< std::vector< type< n_dim_vec<T, n-1> > > > {};
template<class T>
struct n_dim_vec<T, 0>:tag<T>{};
template<class T, size_t n>
using n_dim_vec_t = type<n_dim_vec<T,n>>;
template <class T, class R=std::vector<T>>
R make_vector(size_t size) {
return R(size);
}
template<class T, class...Args, class R=n_dim_vec_t<T, sizeof...(Args)+1>>
R make_vector(size_t top, Args...args){
return R(top, make_vector<T>(std::forward<Args>(args)...));
}
}
template <class T, class... Args, class R=details::n_dim_vec_t<T, sizeof...(Args)>>
R make_vector(Args... args)
{ return details::make_vector<T>(std::forward<Args>(args)...); }
int main() {
auto outmp = make_vector<uint32_t>(16384, 24);
auto boolarr = make_vector<uint32_t>(1000000);
auto temp = make_vector<uint32_t>(10);
auto dots = make_vector<uint32_t>(15444);
public uint32_t ;
auto Routmp = make_vector<uint32_t>(16384, 24);
auto IRoutmp = make_vector<uint32_t>(16384, 24);
uint32_t b ;
uint32_t b1 ;
boolidx = 0;
public uint32_t ;
for (uint32_t i = 0; i < 1000000; i++)
{
boolarr[i] = 1;
}
for (uint32_t i = 0; i < 16384; i++)
{
for (uint32_t j = 0; j < 24; j++)
{
Routmp[i][j] = IRoutmp[i][j];
}
}
for (uint32_t i = 0; i < 16384; i++)
{
for (uint32_t j = 0; j < 24; j++)
{
sassert(i<16384);
sassert(j<24);
sassert(i<16384);
sassert(j<24);
sassert(i<16384);
sassert(j<24);
outmp[i][j] = outmp[i][j]-Routmp[i][j];
}
}
for (uint32_t i = 0; i < 8192; i++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(2*i<16384);
sassert(j<24);
sassert(2*i<16384);
sassert(j<24);
sassert(2*i+1<16384);
sassert(j<24);
outmp[2*i][j] = (b*outmp[2*i][j])+(b1*outmp[2*i+1][j]);
sassert(2*i+1<16384);
sassert(j<24);
sassert(2*i<16384);
sassert(j<24);
sassert(2*i+1<16384);
sassert(j<24);
outmp[2*i+1][j] = (b1*outmp[2*i][j])+(b*outmp[2*i+1][j]);
}
}
for (uint32_t i = 0; i < 4096; i++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(4*i<16384);
sassert(j<24);
sassert(4*i<16384);
sassert(j<24);
sassert(4*i+2<16384);
sassert(j<24);
outmp[4*i][j] = (b*outmp[4*i][j])+(b1*outmp[4*i+2][j]);
sassert(4*i+2<16384);
sassert(j<24);
sassert(4*i<16384);
sassert(j<24);
sassert(4*i+2<16384);
sassert(j<24);
outmp[4*i+2][j] = (b1*outmp[4*i][j])+(b*outmp[4*i+2][j]);
}
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(4*i+1<16384);
sassert(j<24);
sassert(4*i+1<16384);
sassert(j<24);
sassert(4*i+3<16384);
sassert(j<24);
outmp[4*i+1][j] = (b*outmp[4*i+1][j])+(b1*outmp[4*i+3][j]);
sassert(4*i+3<16384);
sassert(j<24);
sassert(4*i+1<16384);
sassert(j<24);
sassert(4*i+3<16384);
sassert(j<24);
outmp[4*i+3][j] = (b1*outmp[4*i+1][j])+(b*outmp[4*i+3][j]);
}
}
for (uint32_t i = 0; i < 4096; i++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(4*i+2<16384);
sassert(j<24);
sassert(4*i+1<16384);
sassert(j<24);
sassert(4*i+2<16384);
sassert(j<24);
outmp[4*i+2][j] = (b1*outmp[4*i+1][j])+(b*outmp[4*i+2][j]);
sassert(4*i+1<16384);
sassert(j<24);
sassert(4*i+1<16384);
sassert(j<24);
sassert(4*i+2<16384);
sassert(j<24);
outmp[4*i+1][j] = (b*outmp[4*i+1][j])+(b1*outmp[4*i+2][j]);
}
}
for (uint32_t i = 0; i < 2048; i++)
{
for (uint32_t k = 0; k < 2; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(8*i+2*k<16384);
sassert(j<24);
sassert(8*i+2*k<16384);
sassert(j<24);
sassert(8*i+4+2*k<16384);
sassert(j<24);
outmp[8*i+2*k][j] = (b1*outmp[8*i+2*k][j])+(b*outmp[8*i+4+2*k][j]);
sassert(8*i+4+2*k<16384);
sassert(j<24);
sassert(8*i+2*k<16384);
sassert(j<24);
sassert(8*i+4+2*k<16384);
sassert(j<24);
outmp[8*i+4+2*k][j] = (b*outmp[8*i+2*k][j])+(b1*outmp[8*i+4+2*k][j]);
}
}
for (uint32_t k = 0; k < 2; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(8*i+2*k+1<16384);
sassert(j<24);
sassert(8*i+2*k+1<16384);
sassert(j<24);
sassert(8*i+4+2*k+1<16384);
sassert(j<24);
outmp[8*i+2*k+1][j] = (b1*outmp[8*i+2*k+1][j])+(b*outmp[8*i+4+2*k+1][j]);
sassert(8*i+4+2*k+1<16384);
sassert(j<24);
sassert(8*i+2*k+1<16384);
sassert(j<24);
sassert(8*i+4+2*k+1<16384);
sassert(j<24);
outmp[8*i+4+2*k+1][j] = (b*outmp[8*i+2*k+1][j])+(b1*outmp[8*i+4+2*k+1][j]);
}
}
}
for (uint32_t i = 0; i < 2048; i++)
{
for (uint32_t k = 0; k < 3; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(8*i+2+2*k<16384);
sassert(j<24);
sassert(8*i+1+2*k<16384);
sassert(j<24);
sassert(8*i+2+2*k<16384);
sassert(j<24);
outmp[8*i+2+2*k][j] = (b1*outmp[8*i+1+2*k][j])+(b*outmp[8*i+2+2*k][j]);
sassert(8*i+1+2*k<16384);
sassert(j<24);
sassert(8*i+1+2*k<16384);
sassert(j<24);
sassert(8*i+2+2*k<16384);
sassert(j<24);
outmp[8*i+1+2*k][j] = (b*outmp[8*i+1+2*k][j])+(b1*outmp[8*i+2+2*k][j]);
}
}
}
for (uint32_t i = 0; i < 1024; i++)
{
for (uint32_t k = 0; k < 4; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(16*i+2*k<16384);
sassert(j<24);
sassert(16*i+2*k<16384);
sassert(j<24);
sassert(16*i+2*k+8<16384);
sassert(j<24);
outmp[16*i+2*k][j] = (b1*outmp[16*i+2*k][j])+(b*outmp[16*i+2*k+8][j]);
sassert(16*i+2*k+8<16384);
sassert(j<24);
sassert(16*i+2*k<16384);
sassert(j<24);
sassert(16*i+2*k+8<16384);
sassert(j<24);
outmp[16*i+2*k+8][j] = (b*outmp[16*i+2*k][j])+(b1*outmp[16*i+2*k+8][j]);
}
}
for (uint32_t k = 0; k < 4; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(16*i+2*k+1<16384);
sassert(j<24);
sassert(16*i+2*k+1<16384);
sassert(j<24);
sassert(16*i+2*k+8+1<16384);
sassert(j<24);
outmp[16*i+2*k+1][j] = (b1*outmp[16*i+2*k+1][j])+(b*outmp[16*i+2*k+8+1][j]);
sassert(16*i+2*k+8+1<16384);
sassert(j<24);
sassert(16*i+2*k+1<16384);
sassert(j<24);
sassert(16*i+2*k+8+1<16384);
sassert(j<24);
outmp[16*i+2*k+8+1][j] = (b*outmp[16*i+2*k+1][j])+(b1*outmp[16*i+2*k+8+1][j]);
}
}
}
for (uint32_t i = 0; i < 1024; i++)
{
for (uint32_t k = 0; k < 7; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(16*i+2*k+1<16384);
sassert(j<24);
sassert(16*i+2*k+1<16384);
sassert(j<24);
sassert(16*i+2*k+2<16384);
sassert(j<24);
outmp[16*i+2*k+1][j] = (b*outmp[16*i+2*k+1][j])+(b1*outmp[16*i+2*k+2][j]);
sassert(16*i+2*k+2<16384);
sassert(j<24);
sassert(16*i+2*k+1<16384);
sassert(j<24);
sassert(16*i+2*k+2<16384);
sassert(j<24);
outmp[16*i+2*k+2][j] = (b1*outmp[16*i+2*k+1][j])+(b*outmp[16*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 512; i++)
{
for (uint32_t k = 0; k < 8; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(32*i+2*k<16384);
sassert(j<24);
sassert(32*i+2*k<16384);
sassert(j<24);
sassert(32*i+2*k+16<16384);
sassert(j<24);
outmp[32*i+2*k][j] = (b1*outmp[32*i+2*k][j])+(b*outmp[32*i+2*k+16][j]);
sassert(32*i+2*k+16<16384);
sassert(j<24);
sassert(32*i+2*k<16384);
sassert(j<24);
sassert(32*i+2*k+16<16384);
sassert(j<24);
outmp[32*i+2*k+16][j] = (b*outmp[32*i+2*k][j])+(b1*outmp[32*i+2*k+16][j]);
}
}
for (uint32_t k = 0; k < 8; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(32*i+2*k+1<16384);
sassert(j<24);
sassert(32*i+2*k+1<16384);
sassert(j<24);
sassert(32*i+2*k+16+1<16384);
sassert(j<24);
outmp[32*i+2*k+1][j] = (b1*outmp[32*i+2*k+1][j])+(b*outmp[32*i+2*k+16+1][j]);
sassert(32*i+2*k+16+1<16384);
sassert(j<24);
sassert(32*i+2*k+1<16384);
sassert(j<24);
sassert(32*i+2*k+16+1<16384);
sassert(j<24);
outmp[32*i+2*k+16+1][j] = (b*outmp[32*i+2*k+1][j])+(b1*outmp[32*i+2*k+16+1][j]);
}
}
}
for (uint32_t i = 0; i < 512; i++)
{
for (uint32_t k = 0; k < 15; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(32*i+2*k+1<16384);
sassert(j<24);
sassert(32*i+2*k+1<16384);
sassert(j<24);
sassert(32*i+2*k+2<16384);
sassert(j<24);
outmp[32*i+2*k+1][j] = (b*outmp[32*i+2*k+1][j])+(b1*outmp[32*i+2*k+2][j]);
sassert(32*i+2*k+2<16384);
sassert(j<24);
sassert(32*i+2*k+1<16384);
sassert(j<24);
sassert(32*i+2*k+2<16384);
sassert(j<24);
outmp[32*i+2*k+2][j] = (b1*outmp[32*i+2*k+1][j])+(b*outmp[32*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 256; i++)
{
for (uint32_t k = 0; k < 16; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(64*i+2*k<16384);
sassert(j<24);
sassert(64*i+2*k<16384);
sassert(j<24);
sassert(64*i+2*k+32<16384);
sassert(j<24);
outmp[64*i+2*k][j] = (b1*outmp[64*i+2*k][j])+(b*outmp[64*i+2*k+32][j]);
sassert(64*i+2*k+32<16384);
sassert(j<24);
sassert(64*i+2*k<16384);
sassert(j<24);
sassert(64*i+2*k+32<16384);
sassert(j<24);
outmp[64*i+2*k+32][j] = (b*outmp[64*i+2*k][j])+(b1*outmp[64*i+2*k+32][j]);
}
}
for (uint32_t k = 0; k < 16; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(64*i+2*k+1<16384);
sassert(j<24);
sassert(64*i+2*k+1<16384);
sassert(j<24);
sassert(64*i+2*k+32+1<16384);
sassert(j<24);
outmp[64*i+2*k+1][j] = (b1*outmp[64*i+2*k+1][j])+(b*outmp[64*i+2*k+32+1][j]);
sassert(64*i+2*k+32+1<16384);
sassert(j<24);
sassert(64*i+2*k+1<16384);
sassert(j<24);
sassert(64*i+2*k+32+1<16384);
sassert(j<24);
outmp[64*i+2*k+32+1][j] = (b*outmp[64*i+2*k+1][j])+(b1*outmp[64*i+2*k+32+1][j]);
}
}
}
for (uint32_t i = 0; i < 256; i++)
{
for (uint32_t k = 0; k < 31; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(64*i+2*k+1<16384);
sassert(j<24);
sassert(64*i+2*k+1<16384);
sassert(j<24);
sassert(64*i+2*k+2<16384);
sassert(j<24);
outmp[64*i+2*k+1][j] = (b*outmp[64*i+2*k+1][j])+(b1*outmp[64*i+2*k+2][j]);
sassert(64*i+2*k+2<16384);
sassert(j<24);
sassert(64*i+2*k+1<16384);
sassert(j<24);
sassert(64*i+2*k+2<16384);
sassert(j<24);
outmp[64*i+2*k+2][j] = (b1*outmp[64*i+2*k+1][j])+(b*outmp[64*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 128; i++)
{
for (uint32_t k = 0; k < 32; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(128*i+2*k<16384);
sassert(j<24);
sassert(128*i+2*k<16384);
sassert(j<24);
sassert(128*i+2*k+64<16384);
sassert(j<24);
outmp[128*i+2*k][j] = (b1*outmp[128*i+2*k][j])+(b*outmp[128*i+2*k+64][j]);
sassert(128*i+2*k+64<16384);
sassert(j<24);
sassert(128*i+2*k<16384);
sassert(j<24);
sassert(128*i+2*k+64<16384);
sassert(j<24);
outmp[128*i+2*k+64][j] = (b*outmp[128*i+2*k][j])+(b1*outmp[128*i+2*k+64][j]);
}
}
for (uint32_t k = 0; k < 32; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(128*i+2*k+1<16384);
sassert(j<24);
sassert(128*i+2*k+1<16384);
sassert(j<24);
sassert(128*i+2*k+64+1<16384);
sassert(j<24);
outmp[128*i+2*k+1][j] = (b1*outmp[128*i+2*k+1][j])+(b*outmp[128*i+2*k+64+1][j]);
sassert(128*i+2*k+64+1<16384);
sassert(j<24);
sassert(128*i+2*k+1<16384);
sassert(j<24);
sassert(128*i+2*k+64+1<16384);
sassert(j<24);
outmp[128*i+2*k+64+1][j] = (b*outmp[128*i+2*k+1][j])+(b1*outmp[128*i+2*k+64+1][j]);
}
}
}
for (uint32_t i = 0; i < 128; i++)
{
for (uint32_t k = 0; k < 63; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(128*i+2*k+1<16384);
sassert(j<24);
sassert(128*i+2*k+1<16384);
sassert(j<24);
sassert(128*i+2*k+2<16384);
sassert(j<24);
outmp[128*i+2*k+1][j] = (b*outmp[128*i+2*k+1][j])+(b1*outmp[128*i+2*k+2][j]);
sassert(128*i+2*k+2<16384);
sassert(j<24);
sassert(128*i+2*k+1<16384);
sassert(j<24);
sassert(128*i+2*k+2<16384);
sassert(j<24);
outmp[128*i+2*k+2][j] = (b1*outmp[128*i+2*k+1][j])+(b*outmp[128*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t k = 0; k < 64; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(256*i+2*k<16384);
sassert(j<24);
sassert(256*i+2*k<16384);
sassert(j<24);
sassert(256*i+2*k+128<16384);
sassert(j<24);
outmp[256*i+2*k][j] = (b1*outmp[256*i+2*k][j])+(b*outmp[256*i+2*k+128][j]);
sassert(256*i+2*k+128<16384);
sassert(j<24);
sassert(256*i+2*k<16384);
sassert(j<24);
sassert(256*i+2*k+128<16384);
sassert(j<24);
outmp[256*i+2*k+128][j] = (b*outmp[256*i+2*k][j])+(b1*outmp[256*i+2*k+128][j]);
}
}
for (uint32_t k = 0; k < 64; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(256*i+2*k+1<16384);
sassert(j<24);
sassert(256*i+2*k+1<16384);
sassert(j<24);
sassert(256*i+2*k+128+1<16384);
sassert(j<24);
outmp[256*i+2*k+1][j] = (b1*outmp[256*i+2*k+1][j])+(b*outmp[256*i+2*k+128+1][j]);
sassert(256*i+2*k+128+1<16384);
sassert(j<24);
sassert(256*i+2*k+1<16384);
sassert(j<24);
sassert(256*i+2*k+128+1<16384);
sassert(j<24);
outmp[256*i+2*k+128+1][j] = (b*outmp[256*i+2*k+1][j])+(b1*outmp[256*i+2*k+128+1][j]);
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t k = 0; k < 127; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(256*i+2*k+1<16384);
sassert(j<24);
sassert(256*i+2*k+1<16384);
sassert(j<24);
sassert(256*i+2*k+2<16384);
sassert(j<24);
outmp[256*i+2*k+1][j] = (b*outmp[256*i+2*k+1][j])+(b1*outmp[256*i+2*k+2][j]);
sassert(256*i+2*k+2<16384);
sassert(j<24);
sassert(256*i+2*k+1<16384);
sassert(j<24);
sassert(256*i+2*k+2<16384);
sassert(j<24);
outmp[256*i+2*k+2][j] = (b1*outmp[256*i+2*k+1][j])+(b*outmp[256*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 32; i++)
{
for (uint32_t k = 0; k < 128; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(512*i+2*k<16384);
sassert(j<24);
sassert(512*i+2*k<16384);
sassert(j<24);
sassert(512*i+2*k+256<16384);
sassert(j<24);
outmp[512*i+2*k][j] = (b1*outmp[512*i+2*k][j])+(b*outmp[512*i+2*k+256][j]);
sassert(512*i+2*k+256<16384);
sassert(j<24);
sassert(512*i+2*k<16384);
sassert(j<24);
sassert(512*i+2*k+256<16384);
sassert(j<24);
outmp[512*i+2*k+256][j] = (b*outmp[512*i+2*k][j])+(b1*outmp[512*i+2*k+256][j]);
}
}
for (uint32_t k = 0; k < 128; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(512*i+2*k+1<16384);
sassert(j<24);
sassert(512*i+2*k+1<16384);
sassert(j<24);
sassert(512*i+2*k+256+1<16384);
sassert(j<24);
outmp[512*i+2*k+1][j] = (b1*outmp[512*i+2*k+1][j])+(b*outmp[512*i+2*k+256+1][j]);
sassert(512*i+2*k+256+1<16384);
sassert(j<24);
sassert(512*i+2*k+1<16384);
sassert(j<24);
sassert(512*i+2*k+256+1<16384);
sassert(j<24);
outmp[512*i+2*k+256+1][j] = (b*outmp[512*i+2*k+1][j])+(b1*outmp[512*i+2*k+256+1][j]);
}
}
}
for (uint32_t i = 0; i < 32; i++)
{
for (uint32_t k = 0; k < 255; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(512*i+2*k+1<16384);
sassert(j<24);
sassert(512*i+2*k+1<16384);
sassert(j<24);
sassert(512*i+2*k+2<16384);
sassert(j<24);
outmp[512*i+2*k+1][j] = (b*outmp[512*i+2*k+1][j])+(b1*outmp[512*i+2*k+2][j]);
sassert(512*i+2*k+2<16384);
sassert(j<24);
sassert(512*i+2*k+1<16384);
sassert(j<24);
sassert(512*i+2*k+2<16384);
sassert(j<24);
outmp[512*i+2*k+2][j] = (b1*outmp[512*i+2*k+1][j])+(b*outmp[512*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t k = 0; k < 256; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(1024*i+2*k<16384);
sassert(j<24);
sassert(1024*i+2*k<16384);
sassert(j<24);
sassert(1024*i+2*k+512<16384);
sassert(j<24);
outmp[1024*i+2*k][j] = (b1*outmp[1024*i+2*k][j])+(b*outmp[1024*i+2*k+512][j]);
sassert(1024*i+2*k+512<16384);
sassert(j<24);
sassert(1024*i+2*k<16384);
sassert(j<24);
sassert(1024*i+2*k+512<16384);
sassert(j<24);
outmp[1024*i+2*k+512][j] = (b*outmp[1024*i+2*k][j])+(b1*outmp[1024*i+2*k+512][j]);
}
}
for (uint32_t k = 0; k < 256; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(1024*i+2*k+1<16384);
sassert(j<24);
sassert(1024*i+2*k+1<16384);
sassert(j<24);
sassert(1024*i+2*k+512+1<16384);
sassert(j<24);
outmp[1024*i+2*k+1][j] = (b1*outmp[1024*i+2*k+1][j])+(b*outmp[1024*i+2*k+512+1][j]);
sassert(1024*i+2*k+512+1<16384);
sassert(j<24);
sassert(1024*i+2*k+1<16384);
sassert(j<24);
sassert(1024*i+2*k+512+1<16384);
sassert(j<24);
outmp[1024*i+2*k+512+1][j] = (b*outmp[1024*i+2*k+1][j])+(b1*outmp[1024*i+2*k+512+1][j]);
}
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t k = 0; k < 511; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(1024*i+2*k+1<16384);
sassert(j<24);
sassert(1024*i+2*k+1<16384);
sassert(j<24);
sassert(1024*i+2*k+2<16384);
sassert(j<24);
outmp[1024*i+2*k+1][j] = (b*outmp[1024*i+2*k+1][j])+(b1*outmp[1024*i+2*k+2][j]);
sassert(1024*i+2*k+2<16384);
sassert(j<24);
sassert(1024*i+2*k+1<16384);
sassert(j<24);
sassert(1024*i+2*k+2<16384);
sassert(j<24);
outmp[1024*i+2*k+2][j] = (b1*outmp[1024*i+2*k+1][j])+(b*outmp[1024*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 8; i++)
{
for (uint32_t k = 0; k < 512; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(2048*i+2*k<16384);
sassert(j<24);
sassert(2048*i+2*k<16384);
sassert(j<24);
sassert(2048*i+2*k+1024<16384);
sassert(j<24);
outmp[2048*i+2*k][j] = (b1*outmp[2048*i+2*k][j])+(b*outmp[2048*i+2*k+1024][j]);
sassert(2048*i+2*k+1024<16384);
sassert(j<24);
sassert(2048*i+2*k<16384);
sassert(j<24);
sassert(2048*i+2*k+1024<16384);
sassert(j<24);
outmp[2048*i+2*k+1024][j] = (b*outmp[2048*i+2*k][j])+(b1*outmp[2048*i+2*k+1024][j]);
}
}
for (uint32_t k = 0; k < 512; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(2048*i+2*k+1<16384);
sassert(j<24);
sassert(2048*i+2*k+1<16384);
sassert(j<24);
sassert(2048*i+2*k+1024+1<16384);
sassert(j<24);
outmp[2048*i+2*k+1][j] = (b1*outmp[2048*i+2*k+1][j])+(b*outmp[2048*i+2*k+1024+1][j]);
sassert(2048*i+2*k+1024+1<16384);
sassert(j<24);
sassert(2048*i+2*k+1<16384);
sassert(j<24);
sassert(2048*i+2*k+1024+1<16384);
sassert(j<24);
outmp[2048*i+2*k+1024+1][j] = (b*outmp[2048*i+2*k+1][j])+(b1*outmp[2048*i+2*k+1024+1][j]);
}
}
}
for (uint32_t i = 0; i < 8; i++)
{
for (uint32_t k = 0; k < 1023; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(2048*i+2*k+1<16384);
sassert(j<24);
sassert(2048*i+2*k+1<16384);
sassert(j<24);
sassert(2048*i+2*k+2<16384);
sassert(j<24);
outmp[2048*i+2*k+1][j] = (b*outmp[2048*i+2*k+1][j])+(b1*outmp[2048*i+2*k+2][j]);
sassert(2048*i+2*k+2<16384);
sassert(j<24);
sassert(2048*i+2*k+1<16384);
sassert(j<24);
sassert(2048*i+2*k+2<16384);
sassert(j<24);
outmp[2048*i+2*k+2][j] = (b1*outmp[2048*i+2*k+1][j])+(b*outmp[2048*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 4; i++)
{
for (uint32_t k = 0; k < 1024; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(4096*i+2*k<16384);
sassert(j<24);
sassert(4096*i+2*k<16384);
sassert(j<24);
sassert(4096*i+2*k+2048<16384);
sassert(j<24);
outmp[4096*i+2*k][j] = (b1*outmp[4096*i+2*k][j])+(b*outmp[4096*i+2*k+2048][j]);
sassert(4096*i+2*k+2048<16384);
sassert(j<24);
sassert(4096*i+2*k<16384);
sassert(j<24);
sassert(4096*i+2*k+2048<16384);
sassert(j<24);
outmp[4096*i+2*k+2048][j] = (b*outmp[4096*i+2*k][j])+(b1*outmp[4096*i+2*k+2048][j]);
}
}
for (uint32_t k = 0; k < 1024; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(4096*i+2*k+1<16384);
sassert(j<24);
sassert(4096*i+2*k+1<16384);
sassert(j<24);
sassert(4096*i+2*k+2048+1<16384);
sassert(j<24);
outmp[4096*i+2*k+1][j] = (b1*outmp[4096*i+2*k+1][j])+(b*outmp[4096*i+2*k+2048+1][j]);
sassert(4096*i+2*k+2048+1<16384);
sassert(j<24);
sassert(4096*i+2*k+1<16384);
sassert(j<24);
sassert(4096*i+2*k+2048+1<16384);
sassert(j<24);
outmp[4096*i+2*k+2048+1][j] = (b*outmp[4096*i+2*k+1][j])+(b1*outmp[4096*i+2*k+2048+1][j]);
}
}
}
for (uint32_t i = 0; i < 4; i++)
{
for (uint32_t k = 0; k < 2047; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(4096*i+2*k+1<16384);
sassert(j<24);
sassert(4096*i+2*k+1<16384);
sassert(j<24);
sassert(4096*i+2*k+2<16384);
sassert(j<24);
outmp[4096*i+2*k+1][j] = (b*outmp[4096*i+2*k+1][j])+(b1*outmp[4096*i+2*k+2][j]);
sassert(4096*i+2*k+2<16384);
sassert(j<24);
sassert(4096*i+2*k+1<16384);
sassert(j<24);
sassert(4096*i+2*k+2<16384);
sassert(j<24);
outmp[4096*i+2*k+2][j] = (b1*outmp[4096*i+2*k+1][j])+(b*outmp[4096*i+2*k+2][j]);
}
}
}
for (uint32_t i = 0; i < 2; i++)
{
for (uint32_t k = 0; k < 2048; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(8192*i+2*k<16384);
sassert(j<24);
sassert(8192*i+2*k<16384);
sassert(j<24);
sassert(8192*i+2*k+4096<16384);
sassert(j<24);
outmp[8192*i+2*k][j] = (b1*outmp[8192*i+2*k][j])+(b*outmp[8192*i+2*k+4096][j]);
sassert(8192*i+2*k+4096<16384);
sassert(j<24);
sassert(8192*i+2*k<16384);
sassert(j<24);
sassert(8192*i+2*k+4096<16384);
sassert(j<24);
outmp[8192*i+2*k+4096][j] = (b*outmp[8192*i+2*k][j])+(b1*outmp[8192*i+2*k+4096][j]);
}
}
for (uint32_t k = 0; k < 2048; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(8192*i+2*k+1<16384);
sassert(j<24);
sassert(8192*i+2*k+1<16384);
sassert(j<24);
sassert(8192*i+2*k+4096+1<16384);
sassert(j<24);
outmp[8192*i+2*k+1][j] = (b1*outmp[8192*i+2*k+1][j])+(b*outmp[8192*i+2*k+4096+1][j]);
sassert(8192*i+2*k+4096+1<16384);
sassert(j<24);
sassert(8192*i+2*k+1<16384);
sassert(j<24);
sassert(8192*i+2*k+4096+1<16384);
sassert(j<24);
outmp[8192*i+2*k+4096+1][j] = (b*outmp[8192*i+2*k+1][j])+(b1*outmp[8192*i+2*k+4096+1][j]);
}
}
}
for (uint32_t i = 0; i < 2; i++)
{
for (uint32_t k = 0; k < 4095; k++)
{
sassert(boolidx<1000000);
b = boolarr[boolidx];
b1 = 1-b;
boolidx = boolidx+1;
for (uint32_t j = 0; j < 24; j++)
{
sassert(8192*i+2*k+1<16384);
sassert(j<24);
sassert(8192*i+2*k+1<16384);
sassert(j<24);
sassert(8192*i+2*k+2<16384);
sassert(j<24);
outmp[8192*i+2*k+1][j] = (b*outmp[8192*i+2*k+1][j])+(b1*outmp[8192*i+2*k+2][j]);
sassert(8192*i+2*k+2<16384);
sassert(j<24);
sassert(8192*i+2*k+1<16384);
sassert(j<24);
sassert(8192*i+2*k+2<16384);
sassert(j<24);
outmp[8192*i+2*k+2][j] = (b1*outmp[8192*i+2*k+1][j])+(b*outmp[8192*i+2*k+2][j]);
}
}
}
for (uint32_t i = 41; i < 16384; i++)
{
t = 16384-i;
for (uint32_t j = 4; j < 14; j++)
{
sassert(t<16384);
sassert(j<24);
sassert(t<16384);
sassert(j<24);
sassert(t+1<16384);
sassert(2<24);
sassert(t+1<16384);
sassert(j<24);
sassert(t+1<16384);
sassert(2<24);
sassert(t<16384);
sassert(j<24);
outmp[t][j] = outmp[t][j]+(outmp[t+1][2]*outmp[t+1][j])+((1-outmp[t+1][2])*outmp[t][j]);
}
}
cout << 1 << endl;
}
