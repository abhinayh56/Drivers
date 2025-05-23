#include "PD.h"

template <typename T>
PD_controller<T>::PD_controller()
{
	dt = 0.0;
	e_k_1 = 0.0;
	Kp = 0.0;
	Kd = 0.0;
	start = true;
}

template <typename T>
void PD_controller<T>::init(T dt_, T Kp_, T Kd_, T u_max_)
{
	set_param(dt_, Kp_, Kd_, u_max_);
	start = true;
}

template <typename T>
void PD_controller<T>::set_param(T dt_, T Kp_, T Kd_, T u_max_)
{
	dt = dt_;
	Kp = Kp_;
	Kd = Kd_;
	u_max = u_max_;
}

template <typename T>
T PD_controller<T>::update(T x_0, T x)
{
	T e_k = x_0 - x;
	T u_k = 0.0;
	if (start == true)
	{
		start = false;
		u_k = Kp * e_k;
	}
	else
	{
		u_k = (Kp + Kd / dt) * e_k - (Kd / dt) * e_k_1;
	}
	u_k = Math_general<T>::saturate(u_k, -u_max, u_max);
	e_k_1 = e_k;
	return u_k;
}

template <typename T>
void PD_controller<T>::reset()
{
	e_k_1 = 0.0;
	start = true;
}

template <typename T>
void PD_controller<T>::merge(T u_k_1_)
{
}

template <typename T>
void PD_controller<T>::set_dt(T dt_)
{
	dt = dt_;
}

template <typename T>
void PD_controller<T>::set_Kp(T Kp_)
{
	Kp = Kp_;
}

template <typename T>
void PD_controller<T>::set_Kd(T Kd_)
{
	Kd = Kd_;
}

template <typename T>
void PD_controller<T>::set_u_max(T u_max_)
{
	u_max = u_max_;
}

template <typename T>
T PD_controller<T>::get_dt()
{
	return dt;
}

template <typename T>
T PD_controller<T>::get_Kp()
{
	return Kp;
}

template <typename T>
T PD_controller<T>::get_Kd()
{
	return Kd;
}

template <typename T>
T PD_controller<T>::get_e_k_1()
{
	return e_k_1;
}

template <typename T>
T PD_controller<T>::get_u_max()
{
	return u_max;
}
