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
auto c2in = make_vector<uint32_t>(576, 1024);
auto w2 = make_vector<uint32_t>(64, 576);
auto c2out = make_vector<uint32_t>(64, 1024);
auto Rc2in = make_vector<uint32_t>(576, 1024);
auto IRc2in = make_vector<uint32_t>(576, 1024);
auto Rc2outIS0IE16 = make_vector<uint32_t>(64, 1024);
auto IRc2outIS0IE16 = make_vector<uint32_t>(64, 1024);
for (uint32_t i = 0; i < 576; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
Rc2in[i][j] = IRc2in[i][j];
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
Rc2outIS0IE16[i][j] = IRc2outIS0IE16[i][j];
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t j = 0; j < 576; j++)
{
w2[i][j] = 500;
}
}
for (uint32_t i = 0; i < 16; i++)
{
for (uint32_t j = 0; j < 1024; j++)
{
c2out[i][j] = 0;
for (uint32_t k = 0; k < 576; k++)
{
c2out[i][j] = c2out[i][j]+w2[i][k]*(c2in[k][j]-Rc2in[k][j]);
}
c2out[i][j] = c2out[i][j]+Rc2outIS0IE16[i][j];
}
}
cout << 1 << endl;
}
