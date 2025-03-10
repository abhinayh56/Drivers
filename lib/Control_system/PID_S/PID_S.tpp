#include "PID_S.h"

template <typename T>
PID_S_controller<T>::PID_S_controller()
{
    dt = 0.0;
    Kp = 0.0;
    T_i = 0.0;
    T_d = 0.0;
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
void PID_S_controller<T>::init(T dt_, T Kp_, T T_i_, T T_d_, T I_max_, T u_max_, bool d_filter_, T fc_)
{
    set_param(dt_, Kp_, T_i_, T_d_, I_max_, u_max_, d_filter_, fc_);
    start = true;
}

template <typename T>
void PID_S_controller<T>::set_param(T dt_, T Kp_, T T_i_, T T_d_, T I_max_, T u_max_, bool d_filter_, T fc_)
{
    dt = dt_;
    Kp = Kp_;
    T_i = T_i_;
    T_d = T_d_;
    I_max = I_max_;
    u_max = u_max_;
    d_filter = d_filter_;
    fc = fc_;
    lpf.set_param(fc, dt);
}

template <typename T>
T PID_S_controller<T>::update(T x_0, T x, T u_ff_)
{
    T e_k = x_0 - x;
    u_ff = u_ff_;

    P = Kp * e_k;

    I = I + (Kp / T_i) * e_k * dt;
    I = Math_general<T>::saturate(I, -I_max, I_max);

    if (start == true)
    {
        D = 0.0;
        start = false;
    }
    else
    {
        D = Kp * T_d * (e - e_pre) / dt;
    }

    if (d_filter_ == true)
    {
        lpf.cal_y(D);
        D = lpf.get_y();
    }
    e_k_1 = e_k;
    u = u_ff + P + I + D;
    u = Math_general<T>::saturate(u, -u_max, u_max);
    return u;
}

template <typename T>
void PID_S_controller<T>::reset()
{
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
void PID_S_controller<T>::merge(T u_k_1_)
{
}

template <typename T>
void PID_S_controller<T>::set_dt(T dt_)
{
    dt = dt_;
    lpf.set_param(fc, dt);
}

template <typename T>
void PID_S_controller<T>::set_Kp(T Kp_)
{
    Kp = Kp_;
}

template <typename T>
void PID_S_controller<T>::set_Ti(T T_i_)
{
    T_i = T_i_;
}

template <typename T>
void PID_S_controller<T>::set_Td(T T_d_)
{
    T_d = T_d_;
}

template <typename T>
void PID_S_controller<T>::set_I_max(T I_max_)
{
    I_max = I_max_;
}

template <typename T>
void PID_S_controller<T>::set_u_max(T u_max_)
{
    u_max = u_max_;
}

template <typename T>
void PID_S_controller<T>::set_d_filter(bool d_filter_)
{
    d_filter = d_filter_;
}

template <typename T>
void PID_S_controller<T>::set_fc(T fc_)
{
    fc = fc_;
    lpf.set_param(fc, dt);
}

template <typename T>
void PID_S_controller<T>::set_ff(T u_ff_)
{
    u_ff = u_ff_;
}

template <typename T>
T PID_S_controller<T>::get_dt()
{
    return dt;
}

template <typename T>
T PID_S_controller<T>::get_Kp()
{
    return Kp;
}

template <typename T>
T PID_S_controller<T>::get_T_i()
{
    return T_i;
}

template <typename T>
T PID_S_controller<T>::get_T_d()
{
    return T_d;
}

template <typename T>
T PID_S_controller<T>::get_I_max()
{
    return I_max;
}

template <typename T>
T PID_S_controller<T>::get_u_max()
{
    return u_max;
}

template <typename T>
bool PID_S_controller<T>::get_d_filter()
{
    return d_filter;
}

template <typename T>
T PID_S_controller<T>::get_fc()
{
    return fc;
}

template <typename T>
T PID_S_controller<T>::get_ff()
{
    return u_ff;
}

template <typename T>
T PID_S_controller<T>::get_P()
{
    return P;
}

template <typename T>
T PID_S_controller<T>::get_I()
{
    return I;
}

template <typename T>
T PID_S_controller<T>::get_D()
{
    return D;
}

template <typename T>
T PID_S_controller<T>::get_u()
{
    return u;
}

template <typename T>
T PID_S_controller<T>::get_e_k_1()
{
    return e_k_1;
}