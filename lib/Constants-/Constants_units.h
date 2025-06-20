#ifndef CONSTANTS_UNITS_H
#define CONSTANTS_UNITS_H

// multiplicative conversion constants
#define RAD_2_DEG   57.295779513082322864647721871733665   // from radians to degrees
#define DEG_2_RAD   0.017453292519943295769236907684886127 // from degrees to radians
#define RPM_2_RADPS 0.10471975511965977461542144610932     // from rpm to radian per second
#define RPM_2_DEGPS 6                                      // from rpm to degree per second
#define RADPS_2_RPM 9.5492965855137201461330258023509      // from radian per second to rpm
#define DEGPS_2_RPM 0.16666666666666666666666666666667     // from degree per second to rpm
#define IN_2_M      0.0254                                 // from inches to meters
#define M_2_IN      39.370078740157480314960629921259843   // from meters to inches
#define M_2_FT      3.2808398950131233595800524934383202   // from meters to feet
#define FT_2_M      0.3048                                 // from feet to meters

#define SEC_2_NS   1000000000
#define SEC_2_US   1000000
#define SEC_2_MS   1000
#define MS_2_SEC   0.001
#define US_2_SEC   0.000001
#define NS_2_SEC   0.000000001
#define MIN_2_SEC  60
#define HR_2_SEC   3600
#define HR_2_MIN   60
#define DAYS_2_HR  24
#define DAYS_2_MIN 1440
#define DAYS_2_SEC 86400

// Decimal prefix Specific units of IEC 60027-2 A.2 and ISO/IEC 80000:13-2008
#define QUETTA  1e30
#define RONNA   1e27
#define YOTTA   1e24
#define ZETTA   1e21
#define EXA     1e18
#define PETA    1e15
#define TERA    1e12
#define GIGA    1e9
#define MEGA    1e6
#define KILO    1e3
#define HECTO   1e2
#define DEKA    1e1
#define DECI    1e-1
#define CENTI   1e-2
#define MILLI   1e-3
#define MICRO   1e-6
#define NANO    1e-9
#define PICO    1e-12
#define FEMTO   1e-15
#define ATTO    1e-18
#define ZEPTO   1e-21
#define YOCTO   1e-24
#define RONTO   1e-27
#define QUECTO  1e-30

// Binary prefix Specific units of IEC 60027-2 A.2 and ISO/IEC 80000:13-2008
#define KIBI  (1 << 10)
#define MEBI  (1 << 20)
#define GIBI  (1 << 30)
#define TEBI  (1 << 40)
#define PEBI  (1 << 50)
#define EXBI  (1 << 60)
#define ZEBI  (1 << 70)
#define YOBI  (1 << 80)

#endif