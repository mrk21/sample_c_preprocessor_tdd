#define BOOST_PP_VARIADICS
#include <boost/preprocessor.hpp>

#define HOGE hoge

#define VARIABLE_LIST(...) \
    BOOST_PP_REPEAT( \
        BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
        VARIABLE, \
        (__VA_ARGS__) \
    )

#define VARIABLE(unused, i, tuple) \
    int BOOST_PP_TUPLE_ELEM(i, tuple) = i;
