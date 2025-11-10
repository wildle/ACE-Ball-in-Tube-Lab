/*
 * Ctrl_only_data.cpp
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

/* Block parameters (default storage) */
P_Ctrl_only_T Ctrl_only_P{
  /* Mask Parameter: PIDController_D
   * Referenced by: '<S33>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S37>/Integral Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S35>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_a
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S43>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S4>/Constant'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S4>/Constant2'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S5>/h0'
   */
  0.1,

  /* Expression: 0.35
   * Referenced by: '<S5>/hE'
   */
  0.35,

  /* Expression: 5
   * Referenced by: '<S5>/T'
   */
  5.0,

  /* Expression: 10
   * Referenced by: '<S5>/T_rep'
   */
  10.0,

  /* Expression: 0.0
   * Referenced by: '<S5>/Delay'
   */
  0.0,

  /* Expression: 1/1000
   * Referenced by: '<S3>/mm2m'
   */
  0.001,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S40>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S35>/Filter'
   */
  0.005,

  /* Expression: 100
   * Referenced by: '<S4>/Saturation'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S4>/Saturation'
   */
  0.0,

  /* Expression: 65535/100
   * Referenced by: '<S4>/procent2ticks'
   */
  655.35,

  /* Expression: 60
   * Referenced by: '<S5>/rps2rpm'
   */
  60.0,

  /* Computed Parameter: PIDvsFF_CurrentSetting
   * Referenced by: '<S4>/PID vs. FF'
   */
  1U,

  /* Computed Parameter: disableu_ref_CurrentSetting
   * Referenced by: '<S4>/disable u_ref'
   */
  1U,

  /* Computed Parameter: ControlvsConstant_CurrentSettin
   * Referenced by: '<S4>/Control vs. Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<Root>/Constant'
   */
  3U
};
