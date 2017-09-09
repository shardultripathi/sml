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
auto w = make_vector<uint32_t>(10, 785);
auto x = make_vector<uint32_t>(785);
auto ans = make_vector<uint32_t>(10);
for (uint32_t i = 0; i < 10; i++)
{
for (uint32_t j = 0; j < 785; j++)
{
w[i][j] = 50;
}
}
for (uint32_t i = 0; i < 785; i++)
{
x[i] = 100;
}
for (uint32_t i = 0; i < 10; i++)
{
ans[i] = 0;
for (uint32_t j = 0; j < 785; j++)
{
ans[i] = ans[i]+w[i][j]*x[j];
}
}
uint32_t max ;
max = 0;
for (uint32_t i = 0; i < 10; i++)
{
max = (ans[i]>max)?ans[i]:max;
}
cout << max << endl;
}
