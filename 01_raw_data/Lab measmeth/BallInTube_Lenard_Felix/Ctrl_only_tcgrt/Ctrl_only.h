/*
 * Ctrl_only.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ctrl_only".
 *
 * Model version              : 1.0
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov 10 13:08:37 2025
 *
 * Target selection: TwinCatGrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Ctrl_only_h_
#define Ctrl_only_h_
#include <cmath>
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "Ctrl_only_types.h"
#include <cfloat>
#include <cstring>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define Ctrl_only_M_TYPE               RT_MODEL_Ctrl_only_T

/* Block signals (default storage) */
struct B_Ctrl_only_T {
  real_T Delay;                        /* '<S5>/Delay' */
  real_T disableu_ref;                 /* '<S4>/disable u_ref' */
  real_T mm2m;                         /* '<S3>/mm2m' */
  real_T ProportionalGain;             /* '<S45>/Proportional Gain' */
  real_T Integrator;                   /* '<S40>/Integrator' */
  real_T FilterCoefficient;            /* '<S43>/Filter Coefficient' */
  real_T Saturation;                   /* '<S4>/Saturation' */
  real_T DataTypeConversion1;          /* '<S3>/Data Type Conversion1' */
  real_T rps2rpm;                      /* '<S5>/rps2rpm' */
  real_T IntegralGain;                 /* '<S37>/Integral Gain' */
  real_T x_out[5];                     /* '<S5>/MATLAB Function' */
  real_T u_ref;                        /* '<S5>/MATLAB Function' */
  real_T h_ref;                        /* '<S5>/MATLAB Function' */
  real_T t;                            /* '<S5>/MATLAB Function' */
  real_T count_new;                    /* '<S5>/MATLAB Function' */
  real_T Sum;                          /* '<S4>/Sum' */
  real_T Sum_a;                        /* '<S49>/Sum' */
  real_T Filter;                       /* '<S35>/Filter' */
  real_T PIDvsFF;                      /* '<S4>/PID vs. FF' */
  real_T Sum4;                         /* '<S1>/Sum4' */
  real_T procent2ticks;                /* '<S4>/procent2ticks' */
  uint16_T DataTypeConversion2;        /* '<S2>/Data Type Conversion2' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_Ctrl_only_T {
  real_T Integrator_DSTATE;            /* '<S40>/Integrator' */
  real_T Filter_DSTATE;                /* '<S35>/Filter' */
  struct {
    void *LoggedData[2];
  } height_PWORK;                      /* '<S1>/height' */

  struct {
    void *LoggedData[2];
  } rpm_PWORK;                         /* '<S1>/rpm' */

  struct {
    void *LoggedData[2];
  } u_PWORK;                           /* '<S4>/u [%]' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S5>/Scope2' */

  struct {
    void *LoggedData;
  } Statexxpxppomegaomegap_PWORK;     /* '<S5>/State [x,xp,xpp,omega,omegap]' */

  int32_T sfEvent;                     /* '<S5>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/MATLAB Function' */
};

/* External inputs (root inport signals with default storage) */
struct ExtU_Ctrl_only_T {
  uint16_T actpos;                     /* '<Root>/actpos' */
  uint16_T rpm;                        /* '<Root>/rpm' */
};

/* External outputs (root outports fed by signals with default storage) */
struct ExtY_Ctrl_only_T {
  uint16_T dutyCyc;                    /* '<Root>/dutyCyc' */
  uint8_T ctrl;                        /* '<Root>/ctrl' */
};

/* Parameters (default storage) */
struct P_Ctrl_only_T_ {
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S33>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S35>/Filter'
                               */
  real_T PIDController_InitialConditio_a;
                              /* Mask Parameter: PIDController_InitialConditio_a
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S43>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T h0_Value;                     /* Expression: 0.1
                                        * Referenced by: '<S5>/h0'
                                        */
  real_T hE_Value;                     /* Expression: 0.35
                                        * Referenced by: '<S5>/hE'
                                        */
  real_T T_Value;                      /* Expression: 5
                                        * Referenced by: '<S5>/T'
                                        */
  real_T T_rep_Value;                  /* Expression: 10
                                        * Referenced by: '<S5>/T_rep'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S5>/Delay'
                                        */
  real_T mm2m_Gain;                    /* Expression: 1/1000
                                        * Referenced by: '<S3>/mm2m'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S40>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S35>/Filter'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S4>/Saturation'
                                        */
  real_T procent2ticks_Gain;           /* Expression: 65535/100
                                        * Referenced by: '<S4>/procent2ticks'
                                        */
  real_T rps2rpm_Gain;                 /* Expression: 60
                                        * Referenced by: '<S5>/rps2rpm'
                                        */
  uint8_T PIDvsFF_CurrentSetting;  /* Computed Parameter: PIDvsFF_CurrentSetting
                                    * Referenced by: '<S4>/PID vs. FF'
                                    */
  uint8_T disableu_ref_CurrentSetting;
                              /* Computed Parameter: disableu_ref_CurrentSetting
                               * Referenced by: '<S4>/disable u_ref'
                               */
  uint8_T ControlvsConstant_CurrentSettin;
                          /* Computed Parameter: ControlvsConstant_CurrentSettin
                           * Referenced by: '<S4>/Control vs. Constant'
                           */
  uint8_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Ctrl_only_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  B_Ctrl_only_T *blockIO;
  ExtU_Ctrl_only_T *inputs;
  ExtY_Ctrl_only_T *outputs;
  DW_Ctrl_only_T *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_Ctrl_only_T Ctrl_only_P;

#ifdef __cplusplus

}

#endif

/* External data declarations for dependent source files */
#ifdef __cplusplus

extern "C"
{

#endif

  extern const char_T *RT_MEMORY_ALLOCATION_ERROR;

#ifdef __cplusplus

}

#endif

extern P_Ctrl_only_T Ctrl_only_P;      /* parameters */

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern RT_MODEL_Ctrl_only_T *Ctrl_only(void);
  extern void Ctrl_only_initialize(RT_MODEL_Ctrl_only_T *const Ctrl_only_M);
  extern void Ctrl_only_step(RT_MODEL_Ctrl_only_T *const Ctrl_only_M);
  extern void Ctrl_only_terminate(RT_MODEL_Ctrl_only_T * Ctrl_only_M);

#ifdef __cplusplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Ctrl_only'
 * '<S1>'   : 'Ctrl_only/Lab Setup'
 * '<S2>'   : 'Ctrl_only/LabDown (send data)'
 * '<S3>'   : 'Ctrl_only/LabUp (read data)'
 * '<S4>'   : 'Ctrl_only/Lab Setup/Regler'
 * '<S5>'   : 'Ctrl_only/Lab Setup/Vorsteuerung'
 * '<S6>'   : 'Ctrl_only/Lab Setup/Regler/PID Controller'
 * '<S7>'   : 'Ctrl_only/Lab Setup/Regler/PID Controller/Anti-windup'
 * '<S8>'   : 'Ctrl_only/Lab Setup/Regler/PID Controller/D Gain'
 * '<S9>'   : 'Ctrl_only/Lab Setup/Regler/PID Controller/External Derivative'
 * '<S10>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Filter'
 * '<S11>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Filter ICs'
 * '<S12>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/I Gain'
 * '<S13>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Ideal P Gain'
 * '<S14>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Integrator'
 * '<S16>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Integrator ICs'
 * '<S17>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/N Copy'
 * '<S18>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/N Gain'
 * '<S19>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/P Copy'
 * '<S20>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Parallel P Gain'
 * '<S21>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Reset Signal'
 * '<S22>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Saturation'
 * '<S23>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Saturation Fdbk'
 * '<S24>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Sum'
 * '<S25>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Sum Fdbk'
 * '<S26>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tracking Mode'
 * '<S27>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tsamp - Integral'
 * '<S29>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tsamp - Ngain'
 * '<S30>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/postSat Signal'
 * '<S31>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/preSat Signal'
 * '<S32>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Anti-windup/Passthrough'
 * '<S33>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/D Gain/Internal Parameters'
 * '<S34>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/External Derivative/Error'
 * '<S35>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S36>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S37>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/I Gain/Internal Parameters'
 * '<S38>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Ideal P Gain/Passthrough'
 * '<S39>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Integrator/Discrete'
 * '<S41>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Integrator ICs/Internal IC'
 * '<S42>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/N Copy/Disabled'
 * '<S43>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/N Gain/Internal Parameters'
 * '<S44>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/P Copy/Disabled'
 * '<S45>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Reset Signal/Disabled'
 * '<S47>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Saturation/Passthrough'
 * '<S48>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Saturation Fdbk/Disabled'
 * '<S49>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Sum/Sum_PID'
 * '<S50>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Sum Fdbk/Disabled'
 * '<S51>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tracking Mode/Disabled'
 * '<S52>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S54>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/postSat Signal/Forward_Path'
 * '<S56>'  : 'Ctrl_only/Lab Setup/Regler/PID Controller/preSat Signal/Forward_Path'
 * '<S57>'  : 'Ctrl_only/Lab Setup/Vorsteuerung/MATLAB Function'
 */
#endif                                 /* Ctrl_only_h_ */
