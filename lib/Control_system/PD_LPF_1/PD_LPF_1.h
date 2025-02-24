#ifndef CONTROL_SYSTEM_PD_LPF_1
#define CONTROL_SYSTEM_PD_LPF_1

#include "../../Constants/Constants.h"
#include "../../Math_lite/Math_lite.h"

template <typename T>
class PD_LPF_1_controller {
public:
	PD_LPF_1_controller();
	void init(T dt_, T Kp_, T Kd_, T fc_, T u_max_);
	void set_param(T dt_, T Kp_, T Kd_, T fc_, T u_max_);
	T update(T x_0, T x);
	void reset();
	void merge(T u_k_1_);
	void set_dt(T dt_);
	void set_Kp(T Kp_);
	void set_Kd(T Kd_);
	void set_fc(T fc_);
	void set_u_max(T u_max_);
	T get_dt();
	T get_Kp();
	T get_Kd();
	T get_fc();
	T get_e_k_1();
	T get_u_k_1();
	T get_u_max();

private:
	Math_functions math_fun;
	T dt = 0.0;
	T e_k_1 = 0.0;
	T Kp = 0.0;
	T Kd = 0.0;
	bool start = true;
	T u_k_1 = 0.0;
	T tau = 0.0;
	T u_max = 9999999999;
};

#include "PD_LPF_1.tpp"

#endif