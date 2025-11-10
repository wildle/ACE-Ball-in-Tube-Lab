/*
 * Ctrl_only.cpp
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

#include "Ctrl_only.h"
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "Ctrl_only_private.h"

/* Named constants for MATLAB Function: '<S5>/MATLAB Function' */
const int32_T Ctrl_only_CALL_EVENT{ -1 };

/* Model step function */
void Ctrl_only_step(RT_MODEL_Ctrl_only_T *const Ctrl_only_M)
{
  B_Ctrl_only_T *Ctrl_only_B{ Ctrl_only_M->blockIO };

  DW_Ctrl_only_T *Ctrl_only_DW{ Ctrl_only_M->dwork };

  ExtU_Ctrl_only_T *Ctrl_only_U{ static_cast<ExtU_Ctrl_only_T *>
    (Ctrl_only_M->inputs) };

  ExtY_Ctrl_only_T *Ctrl_only_Y{ static_cast<ExtY_Ctrl_only_T *>
    (Ctrl_only_M->outputs) };

  real_T tmp;
  int32_T i;

  /* Delay: '<S5>/Delay' */
  Ctrl_only_B->Delay = Ctrl_only_B->count_new;

  /* MATLAB Function: '<S5>/MATLAB Function' */
  Ctrl_only_DW->sfEvent = Ctrl_only_CALL_EVENT;
  Ctrl_only_B->t = (Ctrl_only_B->Delay + 1.0) * 0.005;
  Ctrl_only_B->h_ref = 0.0;
  Ctrl_only_B->u_ref = 0.0;
  for (i = 0; i < 5; i++) {
    Ctrl_only_B->x_out[i] = 0.0;
  }

  Ctrl_only_B->count_new = Ctrl_only_B->Delay + 1.0;

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* ManualSwitch: '<S4>/disable u_ref' */
  if (Ctrl_only_P.disableu_ref_CurrentSetting == 1) {
    /* ManualSwitch: '<S4>/disable u_ref' */
    Ctrl_only_B->disableu_ref = 0.0;
  } else {
    /* ManualSwitch: '<S4>/disable u_ref' incorporates:
     *  Constant: '<S4>/Constant2'
     */
    Ctrl_only_B->disableu_ref = Ctrl_only_P.Constant2_Value;
  }

  /* End of ManualSwitch: '<S4>/disable u_ref' */

  /* Sum: '<S1>/Sum4' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  Ctrl_only_B->Sum4 = Ctrl_only_U->actpos;

  /* Gain: '<S3>/mm2m' */
  Ctrl_only_B->mm2m = Ctrl_only_P.mm2m_Gain * Ctrl_only_B->Sum4;

  /* Sum: '<S1>/Sum4' */
  Ctrl_only_B->Sum4 = Ctrl_only_B->h_ref - Ctrl_only_B->mm2m;

  /* Gain: '<S45>/Proportional Gain' */
  Ctrl_only_B->ProportionalGain = Ctrl_only_P.PIDController_P *
    Ctrl_only_B->Sum4;

  /* DiscreteIntegrator: '<S40>/Integrator' */
  Ctrl_only_B->Integrator = Ctrl_only_DW->Integrator_DSTATE;

  /* Gain: '<S4>/procent2ticks' incorporates:
   *  Gain: '<S33>/Derivative Gain'
   */
  Ctrl_only_B->procent2ticks = Ctrl_only_P.PIDController_D * Ctrl_only_B->Sum4;

  /* DiscreteIntegrator: '<S35>/Filter' */
  Ctrl_only_B->Filter = Ctrl_only_DW->Filter_DSTATE;

  /* Gain: '<S4>/procent2ticks' incorporates:
   *  Sum: '<S35>/SumD'
   */
  Ctrl_only_B->procent2ticks -= Ctrl_only_B->Filter;

  /* Gain: '<S43>/Filter Coefficient' */
  Ctrl_only_B->FilterCoefficient = Ctrl_only_P.PIDController_N *
    Ctrl_only_B->procent2ticks;

  /* ManualSwitch: '<S4>/Control vs. Constant' */
  if (Ctrl_only_P.ControlvsConstant_CurrentSettin == 1) {
    /* ManualSwitch: '<S4>/PID vs. FF' */
    if (Ctrl_only_P.PIDvsFF_CurrentSetting == 1) {
      /* Sum: '<S49>/Sum' */
      Ctrl_only_B->Sum_a = (Ctrl_only_B->ProportionalGain +
                            Ctrl_only_B->Integrator) +
        Ctrl_only_B->FilterCoefficient;

      /* ManualSwitch: '<S4>/PID vs. FF' */
      Ctrl_only_B->PIDvsFF = Ctrl_only_B->Sum_a;
    } else {
      /* ManualSwitch: '<S4>/PID vs. FF' incorporates:
       *  Constant: '<S4>/Constant1'
       */
      Ctrl_only_B->PIDvsFF = Ctrl_only_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<S4>/PID vs. FF' */

    /* Sum: '<S4>/Sum' */
    Ctrl_only_B->Sum = Ctrl_only_B->disableu_ref + Ctrl_only_B->PIDvsFF;

    /* Gain: '<S4>/procent2ticks' */
    Ctrl_only_B->procent2ticks = Ctrl_only_B->Sum;
  } else {
    /* Gain: '<S4>/procent2ticks' incorporates:
     *  Constant: '<S4>/Constant'
     */
    Ctrl_only_B->procent2ticks = Ctrl_only_P.Constant_Value;
  }

  /* End of ManualSwitch: '<S4>/Control vs. Constant' */

  /* Saturate: '<S4>/Saturation' */
  if (Ctrl_only_B->procent2ticks > Ctrl_only_P.Saturation_UpperSat) {
    /* Saturate: '<S4>/Saturation' */
    Ctrl_only_B->Saturation = Ctrl_only_P.Saturation_UpperSat;
  } else if (Ctrl_only_B->procent2ticks < Ctrl_only_P.Saturation_LowerSat) {
    /* Saturate: '<S4>/Saturation' */
    Ctrl_only_B->Saturation = Ctrl_only_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Saturation' */
    Ctrl_only_B->Saturation = Ctrl_only_B->procent2ticks;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Gain: '<S4>/procent2ticks' */
  Ctrl_only_B->procent2ticks = Ctrl_only_P.procent2ticks_Gain *
    Ctrl_only_B->Saturation;

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  tmp = std::floor(Ctrl_only_B->procent2ticks);
  if (std::isnan(tmp) || std::isinf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = std::fmod(tmp, 65536.0);
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  Ctrl_only_B->DataTypeConversion2 = static_cast<uint16_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
    (tmp)));

  /* Outport: '<Root>/dutyCyc' */
  Ctrl_only_Y->dutyCyc = Ctrl_only_B->DataTypeConversion2;

  /* DataTypeConversion: '<S3>/Data Type Conversion1' */
  Ctrl_only_B->DataTypeConversion1 = Ctrl_only_U->rpm;

  /* Gain: '<S5>/rps2rpm' */
  Ctrl_only_B->rps2rpm = Ctrl_only_P.rps2rpm_Gain * Ctrl_only_B->x_out[3];

  /* Gain: '<S37>/Integral Gain' */
  Ctrl_only_B->IntegralGain = Ctrl_only_P.PIDController_I * Ctrl_only_B->Sum4;

  /* Outport: '<Root>/ctrl' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Ctrl_only_Y->ctrl = Ctrl_only_P.Constant_Value_i;

  /* Update for DiscreteIntegrator: '<S40>/Integrator' */
  Ctrl_only_DW->Integrator_DSTATE += Ctrl_only_P.Integrator_gainval *
    Ctrl_only_B->IntegralGain;

  /* Update for DiscreteIntegrator: '<S35>/Filter' */
  Ctrl_only_DW->Filter_DSTATE += Ctrl_only_P.Filter_gainval *
    Ctrl_only_B->FilterCoefficient;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.005s, 0.0s] */
    rtExtModeUpload(0, (real_T)Ctrl_only_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(Ctrl_only_M)!=-1) &&
        !((rtmGetTFinal(Ctrl_only_M)-Ctrl_only_M->Timing.taskTime0) >
          Ctrl_only_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Ctrl_only_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Ctrl_only_M)) {
      rtmSetErrorStatus(Ctrl_only_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Ctrl_only_M->Timing.clockTick0)) {
    ++Ctrl_only_M->Timing.clockTickH0;
  }

  Ctrl_only_M->Timing.taskTime0 = Ctrl_only_M->Timing.clockTick0 *
    Ctrl_only_M->Timing.stepSize0 + Ctrl_only_M->Timing.clockTickH0 *
    Ctrl_only_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Ctrl_only_initialize(RT_MODEL_Ctrl_only_T *const Ctrl_only_M)
{
  B_Ctrl_only_T *Ctrl_only_B{ Ctrl_only_M->blockIO };

  DW_Ctrl_only_T *Ctrl_only_DW{ Ctrl_only_M->dwork };

  /* InitializeConditions for Delay: '<S5>/Delay' */
  Ctrl_only_B->count_new = Ctrl_only_P.Delay_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Integrator' */
  Ctrl_only_DW->Integrator_DSTATE = Ctrl_only_P.PIDController_InitialConditio_a;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Filter' */
  Ctrl_only_DW->Filter_DSTATE = Ctrl_only_P.PIDController_InitialConditionF;

  /* SystemInitialize for MATLAB Function: '<S5>/MATLAB Function' */
  Ctrl_only_DW->doneDoubleBufferReInit = false;
  Ctrl_only_DW->sfEvent = Ctrl_only_CALL_EVENT;
}

/* Model terminate function */
void Ctrl_only_terminate(RT_MODEL_Ctrl_only_T * Ctrl_only_M)
{
  /* model code */
  rt_FREE(Ctrl_only_M->blockIO);
  rt_FREE(Ctrl_only_M->inputs);
  rt_FREE(Ctrl_only_M->outputs);
  rt_FREE(Ctrl_only_M->dwork);

  {
    DataTypeTransInfo *dtInfo{ (DataTypeTransInfo *)
      Ctrl_only_M->SpecialInfo.mappingInfo };

    DataTypeTransitionTable *BTransTable{ dtGetBIODataTypeTrans(dtInfo) };

    rt_FREE(dtGetTransitions(BTransTable));
    rt_FREE(BTransTable);
    rt_FREE(dtGetDataTypeSizes(dtInfo));

    {
      void *ptr{ (void *) dtGetDataTypeNames(dtInfo) };

      rt_FREE(ptr);
    }

    rt_FREE(dtInfo);
  }

  delete Ctrl_only_M;
}

/* Model data allocation function */
RT_MODEL_Ctrl_only_T *Ctrl_only(void)
{
  RT_MODEL_Ctrl_only_T *Ctrl_only_M;
  Ctrl_only_M = new RT_MODEL_Ctrl_only_T();
  if (Ctrl_only_M == (nullptr)) {
    return (nullptr);
  }

  {
    RTWExtModeInfo *rt_ExtModeInfo{ (RTWExtModeInfo *) malloc(sizeof
      (RTWExtModeInfo)) };

    const sysRanDType **systemRan{ (const sysRanDType **)malloc( 7 * sizeof
      (sysRanDType *) ) };

    rt_VALIDATE_MEMORY(Ctrl_only_M,rt_ExtModeInfo);
    rt_VALIDATE_MEMORY(Ctrl_only_M,systemRan);
    Ctrl_only_M->extModeInfo = (rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(rt_ExtModeInfo, systemRan);
  }

  /* block I/O */
  {
    B_Ctrl_only_T *b{ (B_Ctrl_only_T *) malloc(sizeof(B_Ctrl_only_T)) };

    rt_VALIDATE_MEMORY(Ctrl_only_M,b);
    Ctrl_only_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_Ctrl_only_T *dwork{ static_cast<DW_Ctrl_only_T *>(malloc(sizeof
      (DW_Ctrl_only_T))) };

    rt_VALIDATE_MEMORY(Ctrl_only_M,dwork);
    Ctrl_only_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_Ctrl_only_T *Ctrl_only_U{ static_cast<ExtU_Ctrl_only_T *>(malloc(sizeof
      (ExtU_Ctrl_only_T))) };

    rt_VALIDATE_MEMORY(Ctrl_only_M,Ctrl_only_U);
    Ctrl_only_M->inputs = ((static_cast<ExtU_Ctrl_only_T *>(Ctrl_only_U)));
  }

  /* external outputs */
  {
    ExtY_Ctrl_only_T *Ctrl_only_Y{ static_cast<ExtY_Ctrl_only_T *>(malloc(sizeof
      (ExtY_Ctrl_only_T))) };

    rt_VALIDATE_MEMORY(Ctrl_only_M,Ctrl_only_Y);
    Ctrl_only_M->outputs = (Ctrl_only_Y);
  }

  /* data type transition information */
  {

#include "Ctrl_only_reg_dt.h"

  }

  {
    B_Ctrl_only_T *Ctrl_only_B{ Ctrl_only_M->blockIO };

    DW_Ctrl_only_T *Ctrl_only_DW{ Ctrl_only_M->dwork };

    ExtU_Ctrl_only_T *Ctrl_only_U{ static_cast<ExtU_Ctrl_only_T *>
      (Ctrl_only_M->inputs) };

    ExtY_Ctrl_only_T *Ctrl_only_Y{ static_cast<ExtY_Ctrl_only_T *>
      (Ctrl_only_M->outputs) };

    rtmSetTFinal(Ctrl_only_M, -1);
    Ctrl_only_M->Timing.stepSize0 = 0.005;

    /* External mode info */
    Ctrl_only_M->Sizes.checksums[0] = (1412284351U);
    Ctrl_only_M->Sizes.checksums[1] = (1880243088U);
    Ctrl_only_M->Sizes.checksums[2] = (4205576579U);
    Ctrl_only_M->Sizes.checksums[3] = (410856134U);

    {
      static const sysRanDType rtAlwaysEnabled{ SUBSYS_RAN_BC_ENABLE };

      ((const sysRanDType**)rteiGetSubSystemActiveVectorAddresses
        (Ctrl_only_M->extModeInfo))[0] = &rtAlwaysEnabled;
      ((const sysRanDType**)rteiGetSubSystemActiveVectorAddresses
        (Ctrl_only_M->extModeInfo))[1] = &rtAlwaysEnabled;
      ((const sysRanDType**)rteiGetSubSystemActiveVectorAddresses
        (Ctrl_only_M->extModeInfo))[2] = &rtAlwaysEnabled;
      ((const sysRanDType**)rteiGetSubSystemActiveVectorAddresses
        (Ctrl_only_M->extModeInfo))[3] = &rtAlwaysEnabled;
      ((const sysRanDType**)rteiGetSubSystemActiveVectorAddresses
        (Ctrl_only_M->extModeInfo))[4] = &rtAlwaysEnabled;
      ((const sysRanDType**)rteiGetSubSystemActiveVectorAddresses
        (Ctrl_only_M->extModeInfo))[5] = &rtAlwaysEnabled;
      ((const sysRanDType**)rteiGetSubSystemActiveVectorAddresses
        (Ctrl_only_M->extModeInfo))[6] = &rtAlwaysEnabled;
      rteiSetModelMappingInfoPtr(Ctrl_only_M->extModeInfo,
        &Ctrl_only_M->SpecialInfo.mappingInfo);
      rteiSetChecksumsPtr(Ctrl_only_M->extModeInfo, Ctrl_only_M->Sizes.checksums);
      rteiSetTPtr(Ctrl_only_M->extModeInfo, rtmGetTPtr(Ctrl_only_M));
    }

    /* block I/O */
    (void) std::memset((static_cast<void *>(Ctrl_only_B)), 0,
                       sizeof(B_Ctrl_only_T));

    /* states (dwork) */
    (void) std::memset(static_cast<void *>(Ctrl_only_DW), 0,
                       sizeof(DW_Ctrl_only_T));

    /* external inputs */
    (void)std::memset(Ctrl_only_U, 0, sizeof(ExtU_Ctrl_only_T));

    /* external outputs */
    (void)std::memset(Ctrl_only_Y, 0, sizeof(ExtY_Ctrl_only_T));
  }

  return Ctrl_only_M;
}
