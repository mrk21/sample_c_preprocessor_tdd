#define BOOST_PP_VARIADICS
#include <boost/preprocessor.hpp>

#define STRINGIFIABLE_ENUM(type, ...) \
    enum class type { \
        __VA_ARGS__ \
    }; \
    std::ostream & operator <<(std::ostream & out, type value) { \
        static std::map<type, std::string> const data{ \
            STRINGIFIABLE_ENUM_NAME_LIST(type, __VA_ARGS__) \
        }; \
        return out << data.at(value); \
    }

#define STRINGIFIABLE_ENUM_NAME_LIST(type, ...) \
    BOOST_PP_REPEAT( \
        BOOST_PP_VARIADIC_SIZE(__VA_ARGS__), \
        STRINGIFIABLE_ENUM_NAME_LIST_ELEM, \
        (type, (__VA_ARGS__)) \
    ) \

#define STRINGIFIABLE_ENUM_NAME_LIST_ELEM(unused, i, tuple) \
    STRINGIFIABLE_ENUM_NAME_LIST_ELEM_IMPL( \
        BOOST_PP_TUPLE_ELEM(0, tuple), \
        BOOST_PP_TUPLE_ELEM(i, BOOST_PP_TUPLE_ELEM(1, tuple)) \
    )

#define STRINGIFIABLE_ENUM_NAME_LIST_ELEM_IMPL(type, value) \
    {type::value, BOOST_PP_STRINGIZE(value)},
