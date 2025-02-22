#ifndef CONTROL_SYSTEM_D_LPF_1
#define CONTROL_SYSTEM_D_LPF_1

#include "../../Constants/Constants.h"
#include "../../Math_lite/Utility/Math_functions.h"

template <typename T>
class D_LPF_1_controller {
public:
	D_LPF_1_controller();
	void init(T dt_, T Kd_, T fc_, T u_max_);
	void set_param(T dt_, T Kd_, T fc_, T u_max_);
	T update(T x_0, T x);
	void reset();
	void merge(T u_k_1_);
	void set_dt(T dt_);
	void set_Kd(T Kd_);
	void set_fc(T fc_);
	void set_u_max(T u_max_);
	T get_dt();
	T get_Kd();
	T get_fc();
	T get_e_k_1();
	T get_u_k_1();
	T get_u_max();

private:
	Math_functions math_fun;
	T dt = 0.0;
	T e_k_1 = 0.0;
	T Kd = 0.0;
	bool start = true;

	T u_k_1 = 0.0;
	T tau = 0.0;
	T u_max = 9999999999;
};

#include "D_LPF_1.tpp"

#endif