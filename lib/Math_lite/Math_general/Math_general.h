#ifndef MATH_GENERAL_H
#define MATH_GENERAL_H

#include "cmath"
#include "../Constants/Constants.h"

template <typename T>
class Math_general
{
public:
	static inline constexpr T saturate(T x, T x_min, T x_max);
	static inline constexpr T mod(T x);
	static inline constexpr T sign(T x);
	static inline constexpr int great_int(T x);
	static inline constexpr T ceil(T x);
	static inline constexpr T floor(T x);
	static inline constexpr T wrap(T x, T a, T b);
	static inline constexpr T wrap_pi(T x);
	static inline constexpr T wrap_2pi(T x);
	static inline constexpr T wrap_180(T x);
	static inline constexpr T wrap_360(T x);
	static inline constexpr T apply_deadband(T x, T deadband);
	static inline constexpr T apply_deadband2(T x, T deadband);

	static inline constexpr T rad_2_deg(T x);
	static inline constexpr T deg_2_rad(T x);
	static inline constexpr T rpm_2_radps(T x);
	static inline constexpr T rpm_2_degps(T x);
	static inline constexpr T radps_2_rpm(T x);
	static inline constexpr T degps_2_rpm(T x);

	static inline constexpr T hz_to_s(T freq);
	static inline constexpr T hz_to_ms(T freq);
	static inline constexpr T hz_to_us(T freq);
	static inline constexpr T hz_to_ns(T freq);
	static inline constexpr T s_to_hz(T dt);
	static inline constexpr T ms_to_hz(T dt);
	static inline constexpr T us_to_hz(T dt);
	static inline constexpr T ns_to_hz(T dt);

	static inline constexpr T linear_map(T x, T x1, T x2, T y1, T y2);
	static inline constexpr T poly_map_deg1(T x, T a0, T a1);
	static inline constexpr T poly_map_deg2(T x, T a0, T a1, T a2);
	static inline constexpr T poly_map_deg3(T x, T a0, T a1, T a2, T a3);
	static inline constexpr T poly_map_deg4(T x, T a0, T a1, T a2, T a3, T a4);
	static inline constexpr T poly_map_deg5(T x, T a0, T a1, T a2, T a3, T a4, T a5);
	static inline constexpr T poly_map_deg6(T x, T a0, T a1, T a2, T a3, T a4, T a5, T a6);
	static inline constexpr T poly_map_degn(T x, T a[], int n);
	static inline constexpr T fast_inv_sqrt(T number);

	#include "Math_general.tpp"
};

#endif