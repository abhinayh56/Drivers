#include "PD_LPF_1.h"

template <typename T>
PD_LPF_1_controller<T>::PD_LPF_1_controller()
{
	dt = 0.0;
	e_k_1 = 0.0;
	Kd = 0.0;
	start = true;

	u_k_1 = 0.0;
	tau = 0.0;
}

template <typename T>
void PD_LPF_1_controller<T>::init(T dt_, T Kp_, T Kd_, T fc_, T u_max_)
{
	set_param(dt_, Kp_, Kd_, fc_, u_max_);
	start = true;
}

template <typename T>
void PD_LPF_1_controller<T>::set_param(T dt_, T Kp_, T Kd_, T fc_, T u_max_)
{
	dt = dt_;
	Kp = Kp_;
	Kd = Kd_;
	tau = 1.0 / (MATH_2_PI * fc_);
	u_max = u_max_;
}

template <typename T>
T PD_LPF_1_controller<T>::update(T x_0, T x)
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
		u_k = (tau * u_k_1 + (Kp * (dt + tau) + Kd) * e_k - (Kp * tau + Kd) * e_k_1) / (tau + dt);
	}
	u_k = Math_general<T>::saturate(u_k, -u_max, u_max);
	e_k_1 = e_k;
	u_k_1 = u_k;
	return u_k;
}

template <typename T>
void PD_LPF_1_controller<T>::reset()
{
	e_k_1 = 0.0;
	start = true;
	u_k_1 = 0.0;
}

template <typename T>
void PD_LPF_1_controller<T>::merge(T u_k_1_)
{
}

template <typename T>
void PD_LPF_1_controller<T>::set_dt(T dt_)
{
	dt = dt_;
}

template <typename T>
void PD_LPF_1_controller<T>::set_Kp(T Kp_)
{
	Kp = Kp_;
}

template <typename T>
void PD_LPF_1_controller<T>::set_Kd(T Kd_)
{
	Kd = Kd_;
}

template <typename T>
void PD_LPF_1_controller<T>::set_fc(T fc_)
{
	tau = 1.0 / (MATH_2_PI * fc_);
}

template <typename T>
void PD_LPF_1_controller<T>::set_u_max(T u_max_)
{
	u_max = u_max_;
}

template <typename T>
T PD_LPF_1_controller<T>::get_dt()
{
	return dt;
}

template <typename T>
T PD_LPF_1_controller<T>::get_Kp()
{
	return Kp;
}

template <typename T>
T PD_LPF_1_controller<T>::get_Kd()
{
	return Kd;
}

template <typename T>
T PD_LPF_1_controller<T>::get_fc()
{
	return 1.0 / (MATH_2_PI * tau);
}

template <typename T>
T PD_LPF_1_controller<T>::get_e_k_1()
{
	return e_k_1;
}

template <typename T>
T PD_LPF_1_controller<T>::get_u_k_1()
{
	return u_k_1;
}

template <typename T>
T PD_LPF_1_controller<T>::get_u_max()
{
	return u_max;
}
