// copy this file to /ABY/src/examples/millionaire_prob/common/millionaire_prob.cpp

#include "millionaire_prob.h"
#include <vector>

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
{
    return details::make_vector<T>(std::forward<Args>(args)...);
}

int32_t test_millionaire_prob_circuit(e_role role, char* address, uint16_t port, seclvl seclvl,
        uint32_t nvals, uint32_t bitlen, uint32_t nthreads, e_mt_gen_alg mt_alg,
        e_sharing sharing) {

// my generated code -- use your file here
#include "/media/psf/Home/Documents/sml/examples/logistic_regression.cpp"
// my generated code

    cout << "Testing Millionaire's Problem in " << get_sharing_name(sharing)
                << " sharing: " << endl;

    delete party;
    return 0;
}