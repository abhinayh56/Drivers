#ifndef CONTROL_SYSTEM_D
#define CONTROL_SYSTEM_D

#include "../../Math_lite/Math_general/Math_general.h"

template <typename T>
class D_controller
{
public:
	D_controller();
	void init(T dt_, T Kd_, T u_max_);
	void set_param(T dt_, T Kd_, T u_max_);
	T update(T x_0, T x);
	void reset();
	void merge(T u_k_1_);
	void set_dt(T dt_);
	void set_Kd(T Kd_);
	void set_u_max(T u_max_);
	T get_dt();
	T get_Kd();
	T get_e_k_1();
	T get_u_max();

private:
	Math_functions math_fun;
	T dt = 0.0;
	T e_k_1 = 0.0;
	T Kd = 0.0;
	bool start = true;
	T u_max = 9999999999;
};

#include "D.tpp"

#endif