#ifdef TSTD
# include <map>
namespace ft = std;
#else
# include "map.hpp"
#endif

#include <limits.h>
#include <climits>
#include <cfloat>
#include <iostream>

const char data_char[] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    CHAR_MIN, CHAR_MAX, 0
};

const unsigned char data_uchar[] =
{
    1, 2, 5, 50, 120, 126, 127, 0
};

const short data_short[17] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    CHAR_MIN, CHAR_MAX, SHRT_MIN, SHRT_MAX, 0
};

const unsigned short data_ushort[] =
{
    1, 2, 5, 50, 120, 126, 127,
    USHRT_MAX, 0
};

const int data_int[] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, -89756454, 564891235, 0
};

const unsigned int data_uint[] =
{
    1, 2, 5, 50, 120, 126, 127,
    USHRT_MAX, UINT_MAX, 564891235, 0
};

const long data_long[] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, -89756454, 564891235,
    LONG_MIN, LONG_MAX, 0
};

const unsigned long data_ulong[] =
{
    1, 2, 5, 50, 120, 126, 127,
    USHRT_MAX, UINT_MAX, 564891235,
    ULONG_MAX, 0
};

const long long data_long_long[] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, -89756454, 564891235,
    LONG_MIN, LONG_MAX, LONG_LONG_MIN, LONG_LONG_MAX, 0
};

const unsigned long long data_ulong_long[] =
{
    1, 2, 5, 50, 120, 126, 127,
    USHRT_MAX, UINT_MAX, 564891235,
    ULONG_MAX, ULONG_LONG_MAX, 0
};

const float data_float[] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, -89756454, 564891235,
    LONG_MIN, LONG_MAX, LONG_LONG_MIN, LONG_LONG_MAX, FLT_MIN, FLT_MAX, 0
};

const double data_double[] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, -89756454, 564891235,
    LONG_MIN, LONG_MAX, LONG_LONG_MIN, LONG_LONG_MAX, FLT_MIN,
    FLT_MAX, DBL_MIN, DBL_MAX, 0
};

const long double data_ldouble[] =
{
    -128, -127, -50, -2, -1, 1, 2, 5, 50, 120, 126, 127,
    SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, -89756454, 564891235,
    LONG_MIN, LONG_MAX, LONG_LONG_MIN, LONG_LONG_MAX, FLT_MIN,
    FLT_MAX, DBL_MIN, DBL_MAX, LDBL_MIN, LDBL_MAX, 0
};

# define sizeof_data_char sizeof(data_char) / sizeof(data_char[0])
# define sizeof_data_uchar sizeof(data_uchar) / sizeof(data_uchar[0])
# define sizeof_data_short sizeof(data_short) / sizeof(data_short[0])
# define sizeof_data_ushort sizeof(data_ushort) / sizeof(data_ushort[0])
# define sizeof_data_int sizeof(data_int) / sizeof(data_int[0])
# define sizeof_data_uint sizeof(data_uint) / sizeof(data_uint[0])
# define sizeof_data_long sizeof(data_long) / sizeof(data_long[0])
# define sizeof_data_ulong sizeof(data_ulong) / sizeof(data_ulong[0])
# define sizeof_data_long_long sizeof(data_long_long) / sizeof(data_long_long[0])
# define sizeof_data_ulong_long sizeof(data_ulong_long) / sizeof(data_ulong_long[0])
# define sizeof_data_float sizeof(data_float) / sizeof(data_float[0])
# define sizeof_data_double sizeof(data_double) / sizeof(data_double[0])
# define sizeof_data_ldouble sizeof(data_ldouble) / sizeof(data_ldouble[0])

template< class K, class V, class DK, class DV >
int map_tester(DK data_key, DV data_value, int sk, int sv)
{
    ft::map<K, V> m;

    int ik;
    int iv;


    ik = 0;
    iv = 0;
    while (ik < sk)
    {
        iv = 0;
        while (iv < sv)
        {
            m.erase(data_key[ik]);
            iv++;
        }
        ik++;
    }

    ik = 0;
    iv = 0;
    while (ik < sk)
    {
        iv = 0;
        while (iv < sv)
        {
            m.insert(ft::make_pair<K, V>(data_key[ik], data_value[iv]));
            iv++;
        }
        ik++;
    }

    ik = 0;
    iv = 0;
    while (ik < sk)
    {
        iv = 0;
        while (iv < sv)
        {
            m.erase(data_key[ik]);
            iv++;
        }
        ik++;
    }

    ik = 0;
    iv = 0;
    while (ik < sk)
    {
        iv = 0;
        while (iv < sv)
        {
            m.insert(ft::make_pair<K, V>(data_key[ik], data_value[iv]));
            iv++;
        }
        ik++;
    }

    ik = 0;
    iv = 0;
    while (ik < sk)
    {
        iv = 0;
        while (iv < sv)
        {
            m.erase(data_key[ik]);
            iv++;
        }
        ik++;
    }

    return (0);
}

int large_map_test(int size)
{
    // positive
    {
        std::cout << "positive test forward" << std::endl;
        ft::map<int, int> m;

        for (int i = 0; i < size; i++)
            m.insert(ft::make_pair<int, int>(i, i));
        for (int i = 0; i < size; i++)
            m.erase(i);
    }
    {
        std::cout << "positive test backward" << std::endl;
        ft::map<int, int> m;

        for (int i = size; i >= 0; i--)
            m.insert(ft::make_pair<int, int>(i, i));
        for (int i = size; i >= 0; i--)
            m.erase(i);
    }

    // negative
    {
        std::cout << "negative test forward" << std::endl;
        ft::map<int, int> m;

        for (int i = 0; i < size; i++)
            m.insert(ft::make_pair<int, int>(-i, -i));
        for (int i = 0; i < size; i++)
            m.erase(-i);
    }
    {
        std::cout << "negative test backward" << std::endl;
        ft::map<int, int> m;

        for (int i = size; i >= 0; i--)
            m.insert(ft::make_pair<int, int>(-i, -i));
        for (int i = size; i >= 0; i--)
            m.erase(-i);
    }
    return (0);
}

int main(void)
{
    std::cout << "basic test with all integral types" << std::endl;
    map_tester<char, char>                             (data_char       , data_char       , sizeof_data_char       , sizeof_data_char       );
    map_tester<short, short>                           (data_short      , data_short      , sizeof_data_short      , sizeof_data_short      );
    map_tester<int, int>                               (data_int        , data_int        , sizeof_data_int        , sizeof_data_int        );
    map_tester<long, long>                             (data_long       , data_long       , sizeof_data_long       , sizeof_data_long       );
    map_tester<long long, long long>                   (data_long_long  , data_long_long  , sizeof_data_long_long  , sizeof_data_long_long  );
    map_tester<unsigned char, unsigned char>           (data_uchar      , data_uchar      , sizeof_data_uchar      , sizeof_data_uchar      );
    map_tester<unsigned short, unsigned short>         (data_ushort     , data_ushort     , sizeof_data_ushort     , sizeof_data_ushort     );
    map_tester<unsigned int, unsigned int>             (data_uint       , data_uint       , sizeof_data_uint       , sizeof_data_uint       );
    map_tester<unsigned long, unsigned long>           (data_ulong      , data_ulong      , sizeof_data_ulong      , sizeof_data_ulong      );
    map_tester<unsigned long long, unsigned long long> (data_ulong_long , data_ulong_long , sizeof_data_ulong_long , sizeof_data_ulong_long );
    map_tester<float, float>                           (data_float      , data_float      , sizeof_data_float      , sizeof_data_float      );
    map_tester<double, double>                         (data_double     , data_double     , sizeof_data_double     , sizeof_data_double     );
    map_tester<long double, long double>               (data_ldouble    , data_ldouble    , sizeof_data_ldouble    , sizeof_data_ldouble    );

    std::cout << "large_map_test - 1" << std::endl;
    large_map_test(1);
    std::cout << "large_map_test - 10" << std::endl;
    large_map_test(10);
    std::cout << "large_map_test - 100" << std::endl;
    large_map_test(100);
    std::cout << "large_map_test - 1000" << std::endl;
    large_map_test(1000);
    std::cout << "large_map_test - 10000" << std::endl;
    large_map_test(10000);
    std::cout << "large_map_test - 30000" << std::endl;
    large_map_test(30000);
    return 0;
}
