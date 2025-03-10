#ifndef CONTROL_SYSTEM_PID_GS
#define CONTROL_SYSTEM_PID_GS

#include "../../Math_lite/Math_general/Math_general.h"
#include "../../Filters/Filters.h"

template <typename T>
class PID_GS_controller{
	public:
		PID_GS_controller();

		void init(T dt_, T Kp_, T Ki_, T Kd_, T I_max_, T u_max_, bool d_filter_=false, T fc_=10.0);
		void set_param(T dt_, T Kp_, T Ki_, T Kd_, T I_max_, T u_max_, bool d_filter_=false, T fc_=10.0);
		T update(T x_0, T x, T u_ff_=0.0, T op_cond_);
		void reset();
		void merge(T u_k_1_);
		void set_gain_lookup_table(T* op_cond_arr_, T* Kp_arr_, T* Ki_arr_, T* Kd_arr_, uint16_t len_arr_);
 
		void set_dt(T dt_);
		void set_Kp(T Kp_);
		void set_Ki(T Ki_);
		void set_Kd(T Kd_);
		void set_I_max(T I_max_);
		void set_u_max(T u_max_);
		void set_d_filter(bool d_filter_);
        void set_fc(T fc_);
		void set_ff(T u_ff_);

        T get_dt();
        T get_Kp();
        T get_Ki();
        T get_Kd();
        T get_I_max();
        T get_u_max();
        bool get_d_filter();
        T get_fc();
        T get_ff();

		T get_P();
		T get_I();
		T get_D();
		T get_u();
		T get_e_k_1();

	private:
		LPF_filter lpf;
		Math_functions math_fun;

		void update_gain(T Kp_, T Ki_, T Kd_);
		T interpolate(T x, T x1, T y1, T x2, T y2);
		
		T dt = 0.0;
		T Kp = 0.0;
		T Ki = 0.0;
		T Kd = 0.0;
		T I_max = 0.0;
		T u_max = 0.0;
		bool d_filter = false;
        T fc = 0.0;

		T e_k_1 = 0.0;
		T P = 0.0;
		T I = 0.0;
		T D = 0.0;
		T u = 0.0;
		T u_ff = 0.0;

		T* op_cond_arr;
		T* Kp_arr;
		T* Ki_arr;
		T* Kd_arr;
		uint16_t len_arr;

		bool start = true;
};

#include "PID_GS.tpp"

#endif