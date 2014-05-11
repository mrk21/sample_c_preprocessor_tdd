#define BOOST_PP_VARIADICS
#include <boost/preprocessor.hpp>

#define HOGE hoge

#define INITIALIZER_LIST(...) \
    { \
        BOOST_PP_SEQ_ENUM( \
            BOOST_PP_REPEAT( \
                BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
                INITIALIZER_LIST_ELEM, \
                (__VA_ARGS__) \
            ) \
        ) \
    }

#define INITIALIZER_LIST_ELEM(unused, i, tuple) \
    INITIALIZER_LIST_ELEM_IMPL(BOOST_PP_TUPLE_ELEM(i, tuple))

#define INITIALIZER_LIST_ELEM_IMPL(value) \
    ({type::value) (BOOST_PP_STRINGIZE(value)})
