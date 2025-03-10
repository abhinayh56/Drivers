#include "D_LPF_1.h"

template <typename T>
D_LPF_1_controller<T>::D_LPF_1_controller() {
	dt = 0.0;
	e_k_1 = 0.0;
	Kd = 0.0;
	start = true;

	u_k_1 = 0.0;
	tau = 0.0;
}

template <typename T>
void D_LPF_1_controller<T>::init(T dt_, T Kd_, T fc_, T u_max_) {
	set_param(dt_, Kd_, fc_, u_max_);
	start = true;
}

template <typename T>
void D_LPF_1_controller<T>::set_param(T dt_, T Kd_, T fc_, T u_max_) {
	dt = dt_;
	Kd = Kd_;
	tau = 1.0/(math_2pi*fc_);
	u_max = u_max_;
}

template <typename T>
T D_LPF_1_controller<T>::update(T x_0, T x) {
	T e_k = x_0 - x;
	T u_k = 0.0;
	if (start == true) {
		start = false;
		u_k = 0.0;
	}
	else {
		u_k = (tau * u_k_1 + Kd * (e_k - e_k_1)) / (tau + dt);
	}
	u_k = Math_general<T>::saturate(u_k, -u_max, u_max);
	e_k_1 = e_k;
	u_k_1 = u_k;
	return u_k;
}

template <typename T>
void D_LPF_1_controller<T>::reset() {
	e_k_1 = 0.0;
	start = true;
	u_k_1 = 0.0;
}

template <typename T>
void D_LPF_1_controller<T>::merge(T u_k_1_) {
	u_k_1 = u_k_1_;
}

template <typename T>
void D_LPF_1_controller<T>::set_dt(T dt_) {
	dt = dt_;
}

template <typename T>
void D_LPF_1_controller<T>::set_Kd(T Kd_) {
	Kd = Kd_;
}

template <typename T>
void D_LPF_1_controller<T>::set_fc(T fc_) {
	tau = 1.0/(math_2pi*fc_);
}

template <typename T>
void D_LPF_1_controller<T>::set_u_max(T u_max_){
    u_max = u_max_;
}

template <typename T>
T D_LPF_1_controller<T>::get_dt() {
	return dt;
}

template <typename T>
T D_LPF_1_controller<T>::get_Kd() {
	return Kd;
}

template <typename T>
T D_LPF_1_controller<T>::get_fc() {
	return 1.0/(math_2pi*tau);
}

template <typename T>
T D_LPF_1_controller<T>::get_e_k_1() {
	return e_k_1;
}

template <typename T>
T D_LPF_1_controller<T>::get_u_k_1() {
	return u_k_1;
}

template <typename T>
T D_LPF_1_controller<T>::get_u_max(){
    return u_max;
}
