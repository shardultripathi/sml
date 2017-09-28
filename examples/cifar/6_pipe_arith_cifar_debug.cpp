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
auto c2out = make_vector<uint32_t>(64, 1024);
auto r2out = make_vector<uint32_t>(64, 1024);
auto p1out = make_vector<uint32_t>(64, 256);
auto c3in = make_vector<uint32_t>(576, 256);
auto t2 = make_vector<uint32_t>(66, 258);
auto w3 = make_vector<uint32_t>(64, 576);
auto c3out = make_vector<uint32_t>(64, 256);
auto r3out = make_vector<uint32_t>(64, 256);
auto c4in = make_vector<uint32_t>(576, 256);
auto t3 = make_vector<uint32_t>(66, 258);
auto Rc2out = make_vector<uint32_t>(64, 1024);
auto IRc2out = make_vector<uint32_t>(64, 1024);
auto Rc4in = make_vector<uint32_t>(576, 256);
auto IRc4in = make_vector<uint32_t>(576, 256);
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
Rc2out[i][j] = IRc2out[i][j];
}
}
for (uint32_t i = 0; i < 576; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
Rc4in[i][j] = IRc4in[i][j];
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 576; j++)
{
w3[i][j] = 500;
}
}
uint32_t tmp ;
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
tmp = c2out[i][j]-Rc2out[i][j];
r2out[i][j] = (tmp>1)?tmp:0;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
p1out[i][j] = 0;
for (uint32_t k = 0; k < 2; k++)
{
for (uint32_t l = 0; l < 2; l++)
{
p1out[i][j] = r2out[i][4*j+2*k+l]+p1out[i][j];
}
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
t2[i+1][j+1] = p1out[i][j];
}
}
for (uint32_t i = 0; i < 66; i++)
{
t2[i][0] = 0;
t2[i][257] = 0;
}
for (uint32_t i = 1; i < 257; i++)
{
t2[0][i] = 0;
t2[65][i] = 0;
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
for (uint32_t l = 0; l < 3; l++)
{
for (uint32_t m = 0; m < 3; m++)
{
c3in[i*9+3*l+m][j] = t2[i+l][j+m];
}
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
c3out[i][j] = 0;
for (uint32_t k = 0; k < 576; k++)
{
c3out[i][j] = c3out[i][j]+w3[i][k]*c3in[k][j];
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
r3out[i][j] = (c3out[i][j]>1)?c3out[i][j]:0;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
t3[i+1][j+1] = r3out[i][j];
}
}
for (uint32_t i = 0; i < 66; i++)
{
t3[i][0] = 0;
t3[i][257] = 0;
}
for (uint32_t i = 1; i < 257; i++)
{
t3[0][i] = 0;
t3[65][i] = 0;
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
for (uint32_t l = 0; l < 3; l++)
{
for (uint32_t m = 0; m < 3; m++)
{
c4in[i*9+3*l+m][j] = t3[i+l][j+m]+Rc4in[i*9+3*l+m][j];
}
}
}
}
cout << 1 << endl;
}
