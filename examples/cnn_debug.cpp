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
auto x = make_vector<uint32_t>(33, 33);
auto wconv1 = make_vector<uint32_t>(32, 5, 5);
auto bconv1 = make_vector<uint32_t>(32);
auto hconv1 = make_vector<uint32_t>(32, 28, 28);
for (uint32_t i = 0; i < 33; i++)
{
for (uint32_t j = 0; j < 33; j++)
{
x[i][j] = 450;
}
}
for (uint32_t i = 0; i < 32; i++)
{
for (uint32_t j = 0; j < 5; j++)
{
for (uint32_t k = 0; k < 5; k++)
{
wconv1[i][j][k] = 500;
}
}
}
for (uint32_t i = 0; i < 32; i++)
{
bconv1[i] = 66882;
}
for (uint32_t i = 0; i < 32; i++)
{
for (uint32_t j = 0; j < 28; j++)
{
for (uint32_t k = 0; k < 28; k++)
{
hconv1[i][j][k] = 0;
for (uint32_t l = 0; l < 5; l++)
{
for (uint32_t m = 0; m < 5; m++)
{
hconv1[i][j][k] = hconv1[i][j][k]+wconv1[i][l][m]*x[j+l][k+m];
}
}
hconv1[i][j][k] = hconv1[i][j][k]+bconv1[i];
}
}
}
for (uint32_t i = 0; i < 32; i++)
{
for (uint32_t j = 0; j < 28; j++)
{
for (uint32_t k = 0; k < 28; k++)
{
hconv1[i][j][k] = (hconv1[i][j][k]>2147483648)?0:(hconv1[i][j][k]>>8);
}
}
}
auto hpool1 = make_vector<uint32_t>(32, 19, 19);
for (uint32_t i = 0; i < 32; i++)
{
for (uint32_t j = 0; j < 28; j += 2)
{
for (uint32_t k = 0; k < 28; k += 2)
{
hpool1[i][j/2][k/2] = 0;
hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2]>hconv1[i][j][k])?hpool1[i][j/2][k/2]:hconv1[i][j][k];
hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2]>hconv1[i][j+1][k])?hpool1[i][j/2][k/2]:hconv1[i][j+1][k];
hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2]>hconv1[i][j][k+1])?hpool1[i][j/2][k/2]:hconv1[i][j][k+1];
hpool1[i][j/2][k/2] = (hpool1[i][j/2][k/2]>hconv1[i][j+1][k+1])?hpool1[i][j/2][k/2]:hconv1[i][j+1][k+1];
}
}
for (uint32_t j = 14; j < 19; j++)
{
for (uint32_t k = 0; k < 19; k++)
{
hpool1[i][j][k] = 0;
}
}
for (uint32_t j = 0; j < 19; j++)
{
for (uint32_t k = 14; k < 19; k++)
{
hpool1[i][j][k] = 0;
}
}
}
auto wconv2 = make_vector<uint32_t>(64, 5, 5);
auto bconv2 = make_vector<uint32_t>(64);
auto hconv2 = make_vector<uint32_t>(64, 14, 14);
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 5; j++)
{
for (uint32_t k = 0; k < 5; k++)
{
wconv2[i][j][k] = 500;
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
bconv2[i] = 66882;
}
for (uint32_t i = 0; i < 32; i++)
{
for (uint32_t j = 0; j < 14; j++)
{
for (uint32_t k = 0; k < 14; k++)
{
hconv2[2*i][j][k] = 0;
hconv2[2*i+1][j][k] = 0;
for (uint32_t l = 0; l < 5; l++)
{
for (uint32_t m = 0; m < 5; m++)
{
hconv2[2*i][j][k] = hconv2[2*i][j][k]+wconv2[2*i][l][m]*hpool1[i][j+l][k+m];
hconv2[2*i+1][j][k] = hconv2[2*i+1][j][k]+wconv2[2*i+1][l][m]*hpool1[i][j+l][k+m];
}
}
hconv2[2*i][j][k] = hconv2[2*i][j][k]+bconv2[2*i];
hconv2[2*i+1][j][k] = hconv2[2*i+1][j][k]+bconv2[2*i+1];
}
}
}
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 14; j++)
{
for (uint32_t k = 0; k < 14; k++)
{
hconv2[i][j][k] = (hconv2[i][j][k]>2147483648)?0:(hconv2[i][j][k]>>8);
}
}
}
auto hpool2 = make_vector<uint32_t>(64, 7, 7);
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 14; j += 2)
{
for (uint32_t k = 0; k < 14; k += 2)
{
hpool2[i][j/2][k/2] = 0;
hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2]>hconv2[i][j][k])?hpool2[i][j/2][k/2]:hconv2[i][j][k];
hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2]>hconv2[i][j+1][k])?hpool2[i][j/2][k/2]:hconv2[i][j+1][k];
hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2]>hconv2[i][j][k+1])?hpool2[i][j/2][k/2]:hconv2[i][j][k+1];
hpool2[i][j/2][k/2] = (hpool2[i][j/2][k/2]>hconv2[i][j+1][k+1])?hpool2[i][j/2][k/2]:hconv2[i][j+1][k+1];
}
}
}
auto hpool2flat = make_vector<uint32_t>(3136);
for (uint32_t i = 0; i < 64; i++)
{
for (uint32_t j = 0; j < 7; j++)
{
for (uint32_t k = 0; k < 7; k++)
{
hpool2flat[49*i+7*j+k] = hpool2[i][j][k];
}
}
}
auto wfc1 = make_vector<uint32_t>(1024, 3136);
auto bfc1 = make_vector<uint32_t>(1024);
for (uint32_t i = 0; i < 1024; i++)
{
for (uint32_t j = 0; j < 3136; j++)
{
wfc1[i][j] = 460;
}
}
for (uint32_t i = 0; i < 1024; i++)
{
bfc1[i] = 66892;
}
auto hfc1 = make_vector<uint32_t>(1024);
for (uint32_t i = 0; i < 1024; i++)
{
hfc1[i] = 0;
for (uint32_t j = 0; j < 3136; j++)
{
hfc1[i] = hfc1[i]+wfc1[i][j]*hpool2flat[j];
}
hfc1[i] = hfc1[i]+bfc1[i];
}
for (uint32_t i = 0; i < 1024; i++)
{
hfc1[i] = (hfc1[i]>2147483648)?0:(hfc1[i]);
}
auto wfc2 = make_vector<uint32_t>(10, 1024);
auto bfc2 = make_vector<uint32_t>(10);
for (uint32_t i = 0; i < 10; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
wfc2[i][j] = 460;
}
}
for (uint32_t i = 0; i < 10; i++)
{
bfc2[i] = 66892;
}
auto yconv = make_vector<uint32_t>(10);
for (uint32_t i = 0; i < 10; i++)
{
yconv[i] = 0;
for (uint32_t j = 0; j < 1024; j++)
{
yconv[i] = yconv[i]+wfc2[i][j]*hfc1[j];
}
yconv[i] = yconv[i]+bfc2[i];
}
uint32_t max ;
max = 0;
for (uint32_t i = 0; i < 10; i++)
{
max = (yconv[i]>max)?yconv[i]:max;
}
cout << 47>>2 << endl;
}
