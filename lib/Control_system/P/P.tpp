#include "P.h"

template <typename T>
P_controller<T>::P_controller() {
	Kp = 0.0;
}

template <typename T>
void P_controller<T>::init(T Kp_, T u_max_) {
	set_param(Kp_, u_max_);
}

template <typename T>
void P_controller<T>::set_param(T Kp_, T u_max_) {
	Kp = Kp_;
	u_max = u_max_;
}

template <typename T>
T P_controller<T>::update(T x_0, T x) {
	return Math_general<T>::saturate(Kp * (x_0 - x), -u_max, u_max);
}

template <typename T>
void P_controller<T>::reset() {
}

template <typename T>
void P_controller<T>::set_Kp(T Kp_) {
	Kp = Kp_;
}

template <typename T>
void P_controller<T>::set_u_max(T u_max_){
    u_max = u_max_;
}

template <typename T>
T P_controller<T>::get_Kp() {
	return Kp;
}

template <typename T>
T P_controller<T>::get_u_max(){
    return u_max;
}