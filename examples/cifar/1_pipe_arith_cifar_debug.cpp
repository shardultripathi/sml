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
auto x = make_vector<uint32_t>(27, 1024);
auto w1 = make_vector<uint32_t>(64, 27);
auto c1out = make_vector<uint32_t>(64, 1024);
auto r1out = make_vector<uint32_t>(64, 1024);
auto t1 = make_vector<uint32_t>(66, 1026);
auto c2in = make_vector<uint32_t>(576, 1024);
auto Rc2in = make_vector<uint32_t>(576, 1024);
auto IRc2in = make_vector<uint32_t>(576, 1024);
for (uint32_t i = 0; i < 27; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
x[i][j] = 450;
}
}
for (uint32_t i = 0; i < 576; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
Rc2in[i][j] = IRc2in[i][j];
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 27; j++)
{
w1[i][j] = 500;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
c1out[i][j] = 0;
for (uint32_t k = 0; k < 27; k++)
{
c1out[i][j] = c1out[i][j]+w1[i][k]*x[k][j];
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
r1out[i][j] = (c1out[i][j]>1)?c1out[i][j]:0;
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
t1[i+1][j+1] = r1out[i][j];
}
}
for (uint32_t i = 0; i < 66; i++)
{
t1[i][0] = 0;
t1[i][1025] = 0;
}
for (uint32_t i = 1; i < 1025; i++)
{
t1[0][i] = 0;
t1[65][i] = 0;
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
for (uint32_t l = 0; l < 3; l++)
{
for (uint32_t m = 0; m < 3; m++)
{
c2in[i*9+3*l+m][j] = t1[i+l][j+m]+Rc2in[i*9+3*l+m][j];
}
}
}
}
cout << 1 << endl;
}
