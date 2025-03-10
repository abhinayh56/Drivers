#include "Math_general.h"

template <typename T>
inline constexpr T Math_general<T>::saturate(T x, T x_min, T x_max)
{
	if (x < x_min)
	{
		return x_min;
	}
	else if (x > x_max)
	{
		return x_max;
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::mod(T x)
{
	if (x < T(0))
	{
		return -x;
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::sign(T x)
{
	if (x < T(0))
	{
		return T(-1.0);
	}
	else if (x == T(0))
	{
		return T(0.0);
	}
	else
	{
		return T(1.0);
	}
}

template <typename T>
inline constexpr int Math_general<T>::great_int(T x)
{
	if (x >= T(0))
	{
		return (int)x;
	}
	else
	{
		return (int)x - 1;
	}
}

template <typename T>
inline constexpr T Math_general<T>::ceil(T x)
{
	if (x >= T(0))
	{
		return T((int)x + 1);
	}
	else
	{
		return T((int)x);
	}
}

template <typename T>
inline constexpr T Math_general<T>::floor(T x)
{
	if (x >= T(0))
	{
		return T((int)x);
	}
	else
	{
		return T((int)x - 1);
	}
}

template <typename T>
inline constexpr T Math_general<T>::wrap(T x, T a, T b)
{
	if (x < a)
	{
		return x - a + b;
	}
	else if (x >= b)
	{
		return x + a - b;
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::wrap_pi(T x)
{
	if (x <= T(-MATH_PI))
	{
		return x + T(MATH_2_PI);
	}
	else if (x > T(MATH_PI))
	{
		return x - T(MATH_2_PI);
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::wrap_2pi(T x)
{
	if (x < T(0))
	{
		return x + T(MATH_2_PI);
	}
	else if (x >= T(MATH_2_PI))
	{
		return x - T(MATH_2_PI);
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::wrap_180(T x)
{
	if (x <= T(-180))
	{
		return x + T(360);
	}
	else if (x > T(180))
	{
		return x - T(360);
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::wrap_360(T x)
{
	if (x < T(0))
	{
		return x + T(360);
	}
	else if (x >= T(360))
	{
		return x - T(360);
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::apply_deadband(T x, T deadband)
{
	if (mod(x) < deadband * T(0.5))
	{
		return T(0);
	}
	else
	{
		return x;
	}
}

template <typename T>
inline constexpr T Math_general<T>::apply_deadband2(T x, T deadband)
{
	if (mod(x) <= deadband * T(0.5))
	{
		return 0;
	}
	else
	{
		if (x > deadband * T(0.5))
		{
			return x - deadband * T(0.5);
		}
		else
		{
			return x + deadband * T(0.5);
		}
	}
}

template <typename T>
inline constexpr T Math_general<T>::rad_2_deg(T x)
{
	return x * T(RAD_2_DEG);
}

template <typename T>
inline constexpr T Math_general<T>::deg_2_rad(T x)
{
	return x * T(DEG_2_RAD);
}

template <typename T>
inline constexpr T Math_general<T>::rpm_2_radps(T x)
{
	return x * T(RPM_2_RADPS);
}

template <typename T>
inline constexpr T Math_general<T>::rpm_2_degps(T x)
{
	return x * T(RPM_2_DEGPS);
}

template <typename T>
inline constexpr T Math_general<T>::radps_2_rpm(T x)
{
	return x * T(RADPS_2_RPM);
}

template <typename T>
inline constexpr T Math_general<T>::degps_2_rpm(T x)
{
	return x * T(DEGPS_2_RPM);
}

template <typename T>
inline constexpr T Math_general<T>::hz_to_s(T freq)
{
	return T(1) / freq;
}

template <typename T>
inline constexpr T Math_general<T>::hz_to_ms(T freq)
{
	return T(1000) / freq;
}

template <typename T>
inline constexpr T Math_general<T>::hz_to_us(T freq)
{
	return T(1000000) / freq;
}

template <typename T>
inline constexpr T Math_general<T>::hz_to_ns(T freq)
{
	return T(1000000000) / freq;
}

template <typename T>
inline constexpr T Math_general<T>::s_to_hz(T dt)
{
	return T(1) / dt;
}

template <typename T>
inline constexpr T Math_general<T>::ms_to_hz(T dt)
{
	return T(1000) / dt;
}

template <typename T>
inline constexpr T Math_general<T>::us_to_hz(T dt)
{
	return T(1000000) / dt;
}

template <typename T>
inline constexpr T Math_general<T>::ns_to_hz(T dt)
{
	return T(1000000000) / dt;
}

template <typename T>
inline constexpr T Math_general<T>::linear_map(T x, T x1, T x2, T y1, T y2)
{
	return y1 + ((y2 - y1) / (x2 - x1)) * (x - x1);
}

template <typename T>
inline constexpr T Math_general<T>::poly_map_deg1(T x, T a0, T a1)
{
	return a0 + a1 * x;
}

template <typename T>
inline constexpr T Math_general<T>::poly_map_deg2(T x, T a0, T a1, T a2)
{
	return a0 + a1 * x + a2 * x * x;
}

template <typename T>
inline constexpr T Math_general<T>::poly_map_deg3(T x, T a0, T a1, T a2, T a3)
{
	return a0 + a1 * x + a2 * x * x + a3 * x * x * x;
}

template <typename T>
inline constexpr T Math_general<T>::poly_map_deg4(T x, T a0, T a1, T a2, T a3, T a4)
{
	return a0 + a1 * x + a2 * x * x + a3 * x * x * x + a4 * x * x * x * x;
}

template <typename T>
inline constexpr T Math_general<T>::poly_map_deg5(T x, T a0, T a1, T a2, T a3, T a4, T a5)
{
	return a0 + a1 * x + a2 * x * x + a3 * x * x * x + a4 * x * x * x * x + a4 * x * x * x * x * x;
}

template <typename T>
inline constexpr T Math_general<T>::poly_map_deg6(T x, T a0, T a1, T a2, T a3, T a4, T a5, T a6)
{
	return a0 + a1 * x + a2 * x * x + a3 * x * x * x + a4 * x * x * x * x + a4 * x * x * x * x * x + a4 * x * x * x * x * x * x;
}

template <typename T>
inline constexpr T Math_general<T>::poly_map_degn(T x, T a[], int n)
{
	if (n >= 1)
	{
		return 0; // poly_map_degn(T x, T a[], int n-1);
	}
	else
	{
		return a[0];
	}
}

// https://en.wikipedia.org/wiki/Fast_inverse_square_root
template <typename T>
inline constexpr T Math_general<T>::fast_inv_sqrt(T number)
{
	long i;
	T x2, y;
	const T threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(T *)&i;
	y = y * (threehalfs - (x2 * y * y));
	// y  = y*(threehalfs - (x2*y*y));   // 2nd iteration, this can be removed
	return y;
}
