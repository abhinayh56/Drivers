#ifndef CONSTANTS_DATA_TYPE_H
#define CONSTANTS_DATA_TYPE_H

// data type constants
#define INT_64_MIN      (-9223372036854775807i64 - 1)
#define INT_64_MAX      9223372036854775807i64
#define UINT_64_MIN     0x0ui64
#define UINT_64_MAX     0xffffffffffffffffui64
#define INT_32_MIN      (-2147483647i32 - 1)               // the biggest 32-bit signed integer
#define INT_32_MAX      2147483647i32
#define UINT_32_MIN     0x0ui32
#define UINT_32_MAX     0xffffffffui32
#define INT_16_MIN      (-32767i16 - 1)
#define INT_16_MAX      32767i16
#define UINT_16_MIN     0x0ui16
#define UINT_16_MAX     0xffffui16
#define INT_8_MIN       (-127i8 - 1)
#define INT_8_MAX       127i8
#define UINT_8_MIN      0x0ui8
#define UINT_8_MAX      0xffui8
#define LONG_MIN        (-2147483647L - 1)
#define LONG_MAX        2147483647L
#define ULONG_MIN       0x0UL
#define ULONG_MAX       0xffffffffUL
#define LONG_LONG_MIN   (-9223372036854775807i64 - 1)
#define LONG_LONG_MAX   9223372036854775807i64
#define ULONG_LONG_MIN  0x0ui64
#define ULONG_LONG_MAX  0xffffffffffffffffui64
#define SCHAR_MIN       -128
#define SCHAR_MAX       127
#define UCHAR_MIN       0x00
#define UCHAR_MAX       0xff
#define SHORT_MIN       (-32768)
#define SHORT_MAX       32767
#define USHORT_MIN      0x00
#define USHORT_MAX      0xffff
#define INT_MIN         (-2147483647i - 1)
#define INT_MAX         2147483647i
#define UINT_MIN        0x00u
#define UINT_MAX        0xffffffffu
#define FLOAT_MIN       -3.402823466e+38f
#define FLOAT_MAX       3.402823466e+38f
#define FLOAT_MIN_POS   1.175494351e-38f
#define DOUBLE_MIN      -1.7976931348623158e+308
#define DOUBLE_MAX      1.7976931348623158e+308
#define DOUBLE_MIN_POS  2.2250738585072014e-308
#define FLOAT_SMALL     1e-30f  // a small 32-bit floating-point number
#define FLOAT_BIG       1e+30f  // a large 32-bit floating-point number
#define DOUBLE_SMALL    1e-300  // a small 64-bit floating-point number
#define DOUBLE_BIG      1e+300  // a large 64-bit floating-point number

#endif