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
auto c4in = make_vector<uint32_t>(576, 256);
auto w4 = make_vector<uint32_t>(64, 576);
auto c4out = make_vector<uint32_t>(64, 256);
auto r4out = make_vector<uint32_t>(64, 256);
auto p2out = make_vector<uint32_t>(64, 64);
auto c5in = make_vector<uint32_t>(576, 64);
auto t4 = make_vector<uint32_t>(66, 66);
auto w5 = make_vector<uint32_t>(64, 576);
auto c5out = make_vector<uint32_t>(64, 64);
auto r5out = make_vector<uint32_t>(64, 64);
auto w6 = make_vector<uint32_t>(64, 64);
auto c6out = make_vector<uint32_t>(64, 64);
auto r6out = make_vector<uint32_t>(64, 64);
auto w7 = make_vector<uint32_t>(16, 64);
auto c7out = make_vector<uint32_t>(16, 64);
auto r7out = make_vector<uint32_t>(16, 64);
auto reshape = make_vector<uint32_t>(1024);
auto w8 = make_vector<uint32_t>(10, 1024);
auto f1out = make_vector<uint32_t>(10);
auto Rc4in = make_vector<uint32_t>(576, 256);
auto IRc4in = make_vector<uint32_t>(576, 256);
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
w4[i][j] = 500;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 576; j++)
{
w5[i][j] = 500;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
w6[i][j] = 500;
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
w7[i][j] = 500;
}
}
for (uint32_t i = 0; i < 10; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
w8[i][j] = 500;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
c4out[i][j] = 0;
for (uint32_t k = 0; k < 576; k++)
{
c4out[i][j] = c4out[i][j]+w4[i][k]*(c4in[k][j]-Rc4in[k][j]);
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 256; j++)
{
r4out[i][j] = (c4out[i][j]>1)?c4out[i][j]:0;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
p2out[i][j] = 0;
for (uint32_t k = 0; k < 2; k++)
{
for (uint32_t l = 0; l < 2; l++)
{
p2out[i][j] = r4out[i][4*j+2*k+l]+p2out[i][j];
}
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
t4[i+1][j+1] = p2out[i][j];
}
}
for (uint32_t i = 0; i < 66; i++)
{
t4[i][0] = 0;
t4[i][65] = 0;
}
for (uint32_t i = 1; i < 65; i++)
{
t4[0][i] = 0;
t4[65][i] = 0;
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
for (uint32_t l = 0; l < 3; l++)
{
for (uint32_t m = 0; m < 3; m++)
{
c5in[i*9+3*l+m][j] = t4[i+l][j+m];
}
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
c5out[i][j] = 0;
for (uint32_t k = 0; k < 576; k++)
{
c5out[i][j] = c5out[i][j]+w5[i][k]*c5in[k][j];
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
r5out[i][j] = (c5out[i][j]>1)?c5out[i][j]:0;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
c6out[i][j] = 0;
for (uint32_t k = 0; k < 64; k++)
{
c6out[i][j] = c6out[i][j]+w6[i][k]*r5out[k][j];
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
r6out[i][j] = (c6out[i][j]>1)?c6out[i][j]:0;
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
c7out[i][j] = 0;
for (uint32_t k = 0; k < 64; k++)
{
c7out[i][j] = c7out[i][j]+w7[i][k]*r6out[k][j];
}
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
r7out[i][j] = (c7out[i][j]>1)?c7out[i][j]:0;
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t j = 0; j < 64; j++)
{
reshape[64*i+j] = r7out[i][j];
}
}
for (uint32_t i = 0; i < 10; i++)
{
f1out[i] = 0;
for (uint32_t j = 0; j < 1024; j++)
{
f1out[i] = f1out[i]+w8[i][j]*reshape[j];
}
}
cout << 1 << endl;
}
