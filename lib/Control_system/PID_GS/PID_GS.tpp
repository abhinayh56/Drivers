#include "PID_GS.h"

template <typename T>
PID_GS_controller::PID_GS_controller(){
    dt = 0.0;
    Kp = 0.0;
    Ki = 0.0;
    Kd = 0.0;
    fc = 0.0;
    I_max = 0.0;
    u_max = 0.0;
    d_filter = false;
    e_k_1 = 0.0;
    P = 0.0;
    I = 0.0;
    D = 0.0;
    u = 0.0;
    u_ff = 0.0;
    start = true;
}

template <typename T>
void PID_GS_controller::init(T dt_, T Kp_, T Ki_, T Kd_, T I_max_, T u_max_, bool d_filter_, T fc_){
    set_param(dt_, Kp_, Ki_, Kd_, I_max_, u_max_, d_filter_, fc_);
    start = true;
}

template <typename T>
void PID_GS_controller::set_param(T dt_, T Kp_, T Ki_, T Kd_, T I_max_, T u_max_, bool d_filter_, T fc_){
    dt = dt_;
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    I_max = I_max_;
    u_max = u_max_;
    d_filter = d_filter_;
    fc = fc_;
    lpf.set_param(fc,dt);
}

template <typename T>
T PID_GS_controller::update(T x_0, T x, T u_ff_, T op_cond_){
    update_gain(op_cond_);

    T e_k = x_0 - x;
    u_ff = u_ff_;
	
    P = Kp*e_k;
	
    I = I + Ki*e_k*dt;
	I = math_fun.saturate(I,-I_max,I_max);
	
    if(start == true){
		D = 0.0;
		start = false;
	}
	else{
		D = Kd*(e - e_pre)/dt;
	}

	if(d_filter_==true){
		lpf.cal_y(D);
		D = lpf.get_y();
	}
	e_k_1 = e_k;
	u = u_ff + P + I + D;
	u = math_fun.saturate(u,-u_max,u_max);
	return u;
}

template <typename T>
void PID_GS_controller::reset(){
    e_k_1 = 0.0;
    P = 0.0;
    I = 0.0;
    D = 0.0;
    u = 0.0;
    u_ff = 0.0;
    start = true;
    lpf.reset();
}

template <typename T>
void PID_GS_controller::merge(T u_k_1_){
}

template <typename T>
void PID_GS_controller::set_gain_lookup_table(T* op_cond_arr_, T* Kp_arr_, T* Ki_arr_, T* Kd_arr_, uint16_t len_arr_){
    op_cond_arr = op_cond_arr_;
    Kp_arr = Kp_arr_;
    Ki_arr = Ki_arr_;
    Kd_arr = Kd_arr_;
    len_arr = len_arr_;
}

template <typename T>
void PID_GS_controller::update_gain(T op_cond_){
    if(op_cond_<=op_cond_arr[0]){
        Kp = Kp_arr[0];
        Ki = Ki_arr[0];
        Kd = Kd_arr[0];
    }
    else if(op_cond_>=op_cond_arr[len_arr-1]){
        Kp = Kp_arr[len_arr-1];
        Ki = Ki_arr[len_arr-1];
        Kd = Kd_arr[len_arr-1];
    }
    else{
        uint16_t index_i = 0;

        for(uint16_t i=0;i<len_arr;i++){
            if (op_cond_>op_cond_arr[i]){
                index_i++;
            }
            else{
                break;
            }
        }

        Kp = interpolate(op_cond_, op_cond_arr[index_i], Kp_arr[index_i], op_cond_arr[index_i + 1], Kp_arr[index_i + 1]);
        Ki = interpolate(op_cond_, op_cond_arr[index_i], Ki_arr[index_i], op_cond_arr[index_i + 1], Ki_arr[index_i + 1]);
        Kd = interpolate(op_cond_, op_cond_arr[index_i], Kd_arr[index_i], op_cond_arr[index_i + 1], Kd_arr[index_i + 1]);
    }
}

template <typename T>
void PID_GS_controller::set_dt(T dt_){
    dt = dt_;
    lpf.set_param(fc,dt);
}

template <typename T>
void PID_GS_controller::set_Kp(T Kp_){
    Kp = Kp_;
}

template <typename T>
void PID_GS_controller::set_Ki(T Ki_){
    Ki = Ki_;
}

template <typename T>
void PID_GS_controller::set_Kd(T Kd_){
    Kd = Kd_;
}

template <typename T>
void PID_GS_controller::set_I_max(T I_max_){
    I_max = I_max_;
}

template <typename T>
void PID_GS_controller::set_u_max(T u_max_){
    u_max = u_max_;
}

template <typename T>
void PID_GS_controller::set_d_filter(bool d_filter_){
    d_filter = d_filter_;
}

template <typename T>
void PID_GS_controller::set_fc(T fc_){
    fc = fc_;
    lpf.set_param(fc,dt);
}

template <typename T>
void PID_GS_controller::set_ff(T u_ff_){
    u_ff = u_ff_;
}

template <typename T>
T PID_GS_controller::get_dt(){
    return dt;
}

template <typename T>
T PID_GS_controller::get_Kp(){
    return Kp;
}

template <typename T>
T PID_GS_controller::get_Ki(){
    return Ki;
}

template <typename T>
T PID_GS_controller::get_Kd(){
    return Kd;
}

template <typename T>
T PID_GS_controller::get_I_max(){
    return I_max;
}

template <typename T>
T PID_GS_controller::get_u_max(){
    return u_max;
}

template <typename T>
bool PID_GS_controller::get_d_filter(){
    return d_filter;
}

template <typename T>
T PID_GS_controller::get_fc(){
    return fc;
}

template <typename T>
T PID_GS_controller::get_ff(){
    return u_ff;
}

template <typename T>
T PID_GS_controller::get_P(){
    return P;
}

template <typename T>
T PID_GS_controller::get_I(){
    return I;
}

template <typename T>
T PID_GS_controller::get_D(){
    return D;
}

template <typename T>
T PID_GS_controller::get_u(){
    return u;
}

template <typename T>
T PID_GS_controller::get_e_k_1(){
    return e_k_1;
}

template <typename T>
T PID_GS_controller::interpolate(T x, T x1, T y1, T x2, T y2){
    return y1 + (x-x1)*(y2-y1)/(x2-x1);
}