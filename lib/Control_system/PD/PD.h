#ifndef CONTROL_SYSTEM_PD
#define CONTROL_SYSTEM_PD

#include "../../Math_lite/Math_general/Math_general.h"

template <typename T>
class PD_controller
{
public:
	PD_controller();
	void init(T dt_, T Kp_, T Kd_, T u_max_);
	void set_param(T dt_, T Kp_, T Kd_, T u_max_);
	T update(T x_0, T x);
	void reset();
	void merge(T u_k_1_);
	void set_dt(T dt_);
	void set_Kp(T Kp_);
	void set_Kd(T Kd_);
	void set_u_max(T u_max_);
	T get_dt();
	T get_Kp();
	T get_Kd();
	T get_e_k_1();
	T get_u_max();

private:
	Math_functions math_fun;
	T dt = 0.0;
	T e_k_1 = 0.0;
	T Kp = 0.0;
	T Kd = 0.0;
	bool start = true;
	T u_max = 9999999999;
};

#include "PD.tpp"

#endif