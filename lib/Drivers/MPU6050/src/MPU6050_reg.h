#ifndef MPU6050_REG
#define MPU6050_REG

#include <stdint.h>

namespace MPU6050_INFO
{
    enum class ADDR : uint8_t
    {
        I2C_1 = 0x68,
        I2C_2 = 0x69,
        I2C_DEFAULT = I2C_1
    };
    
    enum class REGISTER : uint8_t
    {
        SELF_TEST_X        = 0x0D,
        SELF_TEST_Y        = 0x0E,
        SELF_TEST_Z        = 0x0F,
        SELF_TEST_A        = 0x10,
        SMPLRT_DIV         = 0x19,
        CONFIG             = 0x1A,
        GYRO_CONFIG        = 0x1B,
        ACCEL_CONFIG       = 0x1C,
        FIFO_EN            = 0x23,
        I2C_MST_CTRL       = 0x24,
        I2C_SLV0_ADDR      = 0x25,
        I2C_SLV0_REG       = 0x26,
        I2C_SLV0_CTRL      = 0x27,
        I2C_SLV1_ADDR      = 0x28,
        I2C_SLV1_REG       = 0x29,
        I2C_SLV1_CTRL      = 0x2A,
        I2C_SLV2_ADD       = 0x2B,
        I2C_SLV2_RE        = 0x2C,
        I2C_SLV2_CTR       = 0x2D,
        I2C_SLV3_ADDR      = 0x2E,
        I2C_SLV3_REG       = 0x2F,
        I2C_SLV3_CTRL      = 0x30,
        I2C_SLV4_ADDR      = 0x31,
        I2C_SLV4_REG       = 0x32,
        I2C_SLV4_DO        = 0x33,
        I2C_SLV4_CTRL      = 0x34,
        I2C_SLV4_DI        = 0x35,
        I2C_MST_STATUS     = 0x36,
        INT_PIN_CFG        = 0x37,
        INT_ENABLE         = 0x38,
        INT_STATUS         = 0x3A,
        ACCEL_XOUT_H       = 0x3B,
        ACCEL_XOUT_L       = 0x3C,
        ACCEL_YOUT_H       = 0x3D,
        ACCEL_YOUT_L       = 0x3E,
        ACCEL_ZOUT_H       = 0x3F,
        ACCEL_ZOUT_L       = 0x40,
        TEMP_OUT_H         = 0x41,
        TEMP_OUT_L         = 0x42,
        GYRO_XOUT_H        = 0x43,
        GYRO_XOUT_L        = 0x44,
        GYRO_YOUT_H        = 0x45,
        GYRO_YOUT_L        = 0x46,
        GYRO_ZOUT_H        = 0x47,
        GYRO_ZOUT_L        = 0x48,
        EXT_SENS_DATA_00   = 0x49,
        EXT_SENS_DATA_01   = 0x4A,
        EXT_SENS_DATA_02   = 0x4B,
        EXT_SENS_DATA_03   = 0x4C,
        EXT_SENS_DATA_04   = 0x4D,
        EXT_SENS_DATA_05   = 0x4E,
        EXT_SENS_DATA_06   = 0x4F,
        EXT_SENS_DATA_07   = 0x50,
        EXT_SENS_DATA_08   = 0x51,
        EXT_SENS_DATA_09   = 0x52,
        EXT_SENS_DATA_10   = 0x53,
        EXT_SENS_DATA_11   = 0x54,
        EXT_SENS_DATA_12   = 0x55,
        EXT_SENS_DATA_13   = 0x56,
        EXT_SENS_DATA_14   = 0x57,
        EXT_SENS_DATA_15   = 0x58,
        EXT_SENS_DATA_16   = 0x59,
        EXT_SENS_DATA_17   = 0x5A,
        EXT_SENS_DATA_18   = 0x5B,
        EXT_SENS_DATA_19   = 0x5C,
        EXT_SENS_DATA_20   = 0x5D,
        EXT_SENS_DATA_21   = 0x5E,
        EXT_SENS_DATA_22   = 0x5F,
        EXT_SENS_DATA_23   = 0x60,
        I2C_SLV0_DO        = 0x63,
        I2C_SLV1_DO        = 0x64,
        I2C_SLV2_DO        = 0x65,
        I2C_SLV3_DO        = 0x66,
        I2C_MST_DELAY_CTRL = 0x67,
        SIGNAL_PATH_RESET  = 0x68,
        USER_CTRL          = 0x6A,
        PWR_MGMT_1         = 0x6B,
        PWR_MGMT_2         = 0x6C,
        FIFO_COUNTH        = 0x72,
        FIFO_COUNTL        = 0x73,
        FIFO_R_W           = 0x74,
        WHO_AM_I           = 0x75
    };

    namespace BIT_FLAGS
    {
        // enum class SELF_TEST_X : uint8_t
        // {
        // };
        
        // enum class SELF_TEST_Y : uint8_t
        // {
        // };
        
        // enum class SELF_TEST_Z : uint8_t
        // {
        // };
        
        // enum class SELF_TEST_A : uint8_t
        // {
        // };

        enum class CONFIG : uint8_t
        {
            EXT_SYNC_SET_0 = 0,
            EXT_SYNC_SET_1 = 1,
            EXT_SYNC_SET_2 = 2,
            EXT_SYNC_SET_3 = 3,
            EXT_SYNC_SET_4 = 4,
            EXT_SYNC_SET_5 = 5,
            EXT_SYNC_SET_6 = 6,
            EXT_SYNC_SET_7 = 7,
            DLPF_CFG_0 = 0,
            DLPF_CFG_1 = 1,
            DLPF_CFG_2 = 2,
            DLPF_CFG_3 = 3,
            DLPF_CFG_4 = 4,
            DLPF_CFG_5 = 5,
            DLPF_CFG_6 = 6,
            DLPF_CFG_7 = 7
        };

        enum class GYRO_CONFIG : uint8_t
        {
            XG_ST_0 = 0,
            XG_ST_1 = 1,
            YG_ST_0 = 0,
            YG_ST_1 = 1,
            ZG_ST_0 = 0,
            ZG_ST_1 = 1,
            FS_SEL_0 = 0,
            FS_SEL_1 = 1,
            FS_SEL_2 = 2,
            FS_SEL_3 = 3
        };
        
        enum class ACCEL_CONFIG : uint8_t
        {
            XA_ST_0 = 0,
            XA_ST_1 = 1,
            YA_ST_0 = 0,
            YA_ST_1 = 1,
            ZA_ST_0 = 0,
            ZA_ST_1 = 1,
            AFS_SEL_0 = 0,
            AFS_SEL_1 = 1,
            AFS_SEL_2 = 2,
            AFS_SEL_3 = 3
        };
        
        enum class FIFO_EN : uint8_t
        {
            TEMP_FIFO_EN_0 = 0,
            TEMP_FIFO_EN_1 = 1,
            XG_FIFO_EN_0 = 0,
            XG_FIFO_EN_1 = 1,
            YG_FIFO_EN_0 = 0,
            YG_FIFO_EN_1 = 1,
            ZG_FIFO_EN_0 = 0,
            ZG_FIFO_EN_1 = 1,
            ACCEL_FIFO_EN_0 = 0,
            ACCEL_FIFO_EN_1 = 1,
            SLV2_FIFO_EN_0 = 0,
            SLV2_FIFO_EN_1 = 1,
            SLV1_FIFO_EN_0 = 0,
            SLV1_FIFO_EN_1 = 1,
            SLV0_FIFO_EN_0 = 0,
            SLV0_FIFO_EN_1 = 1
        };
        
        enum class I2C_MST_CTRL : uint8_t
        {
            MUL_MST_EN_0 = 0,
            MUL_MST_EN_1 = 1,
            WAIT_FOR_ES_0 = 0,
            WAIT_FOR_ES_1 = 1,
            SLV3_FIFO_EN_0 = 0,
            SLV3_FIFO_EN_1 = 1,
            I2C_MST_P_NSR_0 = 0,
            I2C_MST_P_NSR_1 = 1,
            I2C_MST_CLK_0 = 0,
            I2C_MST_CLK_1 = 1,
            I2C_MST_CLK_2 = 2,
            I2C_MST_CLK_3 = 3,
            I2C_MST_CLK_4 = 4,
            I2C_MST_CLK_5 = 5,
            I2C_MST_CLK_6 = 6,
            I2C_MST_CLK_7 = 7,
            I2C_MST_CLK_8 = 8,
            I2C_MST_CLK_9 = 9,
            I2C_MST_CLK_10 = 10,
            I2C_MST_CLK_11 = 11,
            I2C_MST_CLK_12 = 12,
            I2C_MST_CLK_13 = 13,
            I2C_MST_CLK_14 = 14,
            I2C_MST_CLK_15 = 15
        };
        
        enum class I2C_MST_STATUS : uint8_t
        {
            PASS_THROUGH_0 = 0,
            PASS_THROUGH_1 = 1,
            I2C_SLV4_DONE_0 = 0,
            I2C_SLV4_DONE_1 = 1,
            I2C_LOST_ARB_0 = 0,
            I2C_LOST_ARB_1 = 1,
            I2C_SLV4_NACK_0 = 0,
            I2C_SLV4_NACK_1 = 1,
            I2C_SLV3_NACK_0 = 0,
            I2C_SLV3_NACK_1 = 1,
            I2C_SLV2_NACK_0 = 0,
            I2C_SLV2_NACK_1 = 1,
            I2C_SLV1_NACK_0 = 0,
            I2C_SLV1_NACK_1 = 1,
            I2C_SLV0_NACK_0 = 0,
            I2C_SLV0_NACK_1 = 1

        };
        
        enum class INT_PIN_CFG : uint8_t
        {
            INT_LEVEL_0 = 0,
            INT_LEVEL_1 = 1,
            INT_OPEN_0 = 0,
            INT_OPEN_1 = 1,
            LATCH_INT_EN_0 = 0,
            LATCH_INT_EN_1 = 1,
            INT_RD_CLEAR_0 = 0,
            INT_RD_CLEAR_1 = 1,
            FSYNC_INT_LEVEL_0 = 0,
            FSYNC_INT_LEVEL_1 = 1,
            FSYNC_INT_EN_0 = 0,
            FSYNC_INT_EN_1 = 1,
            I2C_BYPASS_EN_0 = 0,
            I2C_BYPASS_EN_1 = 1
        };
        
        enum class INT_ENABLE : uint8_t
        {
            FIFO_OFLOW_EN_0 = 0,
            FIFO_OFLOW_EN_1 = 1,
            I2C_MST_INT_EN_0 = 0,
            I2C_MST_INT_EN_1 = 1,
            DATA_RDY_EN_0 = 0,
            DATA_RDY_EN_1 = 1
        };
        
        enum class INT_STATUS : uint8_t
        {
            FIFO_OFLOW_INT_0 = 0,
            FIFO_OFLOW_INT_1 = 1,
            I2C_MST_INT_0 = 0,
            I2C_MST_INT_1 = 1,
            DATA_RDY_INT_0 = 0,
            DATA_RDY_INT_1 = 1
        };
        
        enum class I2C_MST_DELAY_CTRL : uint8_t
        {
            DELAY_ES_SHADOW_0 = 0,
            DELAY_ES_SHADOW_1 = 1,
            I2C_SLV4_DLY_EN_0 = 0,
            I2C_SLV4_DLY_EN_1 = 1,
            I2C_SLV3_DLY_EN_0 = 0,
            I2C_SLV3_DLY_EN_1 = 1,
            I2C_SLV2_DLY_EN_0 = 0,
            I2C_SLV2_DLY_EN_1 = 1,
            I2C_SLV1_DLY_EN_0 = 0,
            I2C_SLV1_DLY_EN_1 = 1,
            I2C_SLV0_DLY_EN_0 = 0,
            I2C_SLV0_DLY_EN_1 = 1
        };
        
        enum class SIGNAL_PATH_RESET : uint8_t
        {
            GYRO_RESET_0 = 0,
            GYRO_RESET_1 = 1,
            ACCEL_RESET_0 = 0,
            ACCEL_RESET_1 = 1,
            TEMP_RESET_0 = 0,
            TEMP_RESET_1 = 1
        };
        
        enum class USER_CTRL : uint8_t
        {
            FIFO_EN_0 = 0,
            FIFO_EN_1 = 1,
            I2C_MST_EN_0 = 0,
            I2C_MST_EN_1 = 1,
            I2C_IF_DIS_0 = 0,
            I2C_IF_DIS_1 = 1,
            FIFO_RESET_0 = 0,
            FIFO_RESET_1 = 1,
            I2C_MST_RESET_0 = 0,
            I2C_MST_RESET_1 = 1,
            SIG_COND_RESET_0 = 0,
            SIG_COND_RESET_1 = 1
        };
        
        enum class PWR_MGMT_1 : uint8_t
        {
            DEVICE_RESET_0 = 0,
            DEVICE_RESET_1 = 1,
            SLEEP_0 = 0,
            SLEEP_1 = 1,
            CYCLE_0 = 0,
            CYCLE_1 = 1,
            TEMP_DIS_0 = 0,
            TEMP_DIS_1 = 1,
            CLKSEL_0 = 0,
            CLKSEL_1 = 1,
            CLKSEL_2 = 2,
            CLKSEL_3 = 3,
            CLKSEL_4 = 4,
            CLKSEL_5 = 5,
            CLKSEL_6 = 6,
            CLKSEL_7 = 7
        };
        
        enum class PWR_MGMT_2 : uint8_t
        {
            LP_WAKE_CTRL_0 = 0,
            LP_WAKE_CTRL_1 = 1,
            LP_WAKE_CTRL_2 = 2,
            LP_WAKE_CTRL_3 = 3,
            STBY_XA_0 = 0,
            STBY_XA_1 = 1,
            STBY_YA_0 = 0,
            STBY_YA_1 = 1,
            STBY_ZA_0 = 0,
            STBY_ZA_1 = 1,
            STBY_XG_0 = 0,
            STBY_XG_1 = 1,
            STBY_YG_0 = 0,
            STBY_YG_1 = 1,
            STBY_ZG_0 = 0,
            STBY_ZG_1 = 1
        };
        
        enum class WHO_AM_I : uint8_t
        {
            WHO_AM_I = 0x34
        };
    }
}

#endif
