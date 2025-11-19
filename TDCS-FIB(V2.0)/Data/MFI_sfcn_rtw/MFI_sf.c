/*
 * MFI_sf.c
 *
 * Code generation for model "MFI_sf".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Apr 06 14:57:21 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "MFI_sf.h"
#include "MFI_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *MFI_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";

/* Start for root system: '<Root>' */
#define MDL_START

static void mdlStart(SimStruct *S)
{
  /* instance underlying S-Function data */
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  if defined(MATLAB_MEX_FILE)

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Check for invalid switching between solver types */
  if (ssIsVariableStepSolver(S)) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "a solver type of variable-step "
                     "because this S-Function was created from a model with "
                     "solver type of fixed-step and it has continuous time blocks. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

  if (fabs(ssGetFixedStepSize(S) - 1.0E-5) > mxGetEps()*100*1.0E-5) {
    ssSetErrorStatus(S, "This Simulink Coder generated "
                     "S-Function cannot be used in a simulation with "
                     "the current fixed step size "
                     "because this S-Function was created from a model with "
                     "a fixed step size of 1.0E-5 and had both "
                     "continuous blocks and discrete blocks running at this rate. "
                     "See the Solver page of the simulation parameters dialog.");
    return;
  }

#  endif

  MFI_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  real_T currentTime;
  real_T y;
  B_MFI_T *_rtB;
  _rtB = ((B_MFI_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, tid)) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Noise0'
     *  Constant: '<S1>/NoiseSelec'
     *  Inport: '<Root>/Inport1'
     */
    if ((*(real_T *)(mxGetData(NoiseSelec(S)))) != 0.0) {
      _rtB->Switch = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
    } else {
      _rtB->Switch = 0.0;
    }

    /* End of Switch: '<S1>/Switch' */

    /* Logic: '<S3>/Logical' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    y = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
    _rtB->Logical = !(y != 0.0);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S3>/FaultSelec1' */
    currentTime = ssGetTaskTime(S,0);
    if (currentTime < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->FaultSelec1 = 1.0;
    } else {
      _rtB->FaultSelec1 = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S3>/FaultSelec1' */

    /* RelationalOperator: '<S6>/Compare' incorporates:
     *  Constant: '<S6>/Constant'
     */
    _rtB->Compare = (_rtB->FaultSelec1 == 7.0);

    /* Logic: '<S3>/Logical ' */
    _rtB->Logical_i = (_rtB->Logical && _rtB->Compare);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* RelationalOperator: '<S7>/Compare' incorporates:
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S7>/Constant'
     */
    y = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
    _rtB->Compare_h = (y == 2.0);

    /* MultiPortSwitch: '<S3>/Multiport1' incorporates:
     *  Constant: '<S3>/Constant1'
     */
    _rtB->Multiport1 = 7.0;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S3>/Multiport Switch2' incorporates:
     *  Constant: '<S3>/Constant3'
     */
    if (_rtB->Logical_i == 0) {
      /* Logic: '<S3>/Logical Operator' incorporates:
       *  Constant: '<S3>/Constant2'
       */
      y = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
      _rtB->LogicalOperator = ((y != 0.0) && _rtB->Compare);

      /* MultiPortSwitch: '<S3>/Multiport' */
      if (_rtB->LogicalOperator == 0) {
        _rtB->Multiport = _rtB->FaultSelec1;
      } else {
        _rtB->Multiport = _rtB->Multiport1;
      }

      /* End of MultiPortSwitch: '<S3>/Multiport' */
      _rtB->MultiportSwitch2 = _rtB->Multiport;
    } else {
      _rtB->MultiportSwitch2 = 7.0;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch2' */

    /* MultiPortSwitch: '<S3>/Multiport Switch3' incorporates:
     *  Constant: '<S3>/1'
     *  Constant: '<S3>/2'
     *  Constant: '<S3>/3'
     */
    switch ((int32_T)_rtB->MultiportSwitch2) {
     case 2:
     case 3:
     case 4:
     case 5:
     case 6:
      _rtB->MultiportSwitch3 = 1.0;
      break;

     case 1:
      _rtB->MultiportSwitch3 = 2.0;
      break;

     default:
      _rtB->MultiportSwitch3 = 3.0;
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch3' */

    /* Step: '<S5>/Step' */
    currentTime = ssGetTaskTime(S,0);
    if (currentTime < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->Step = 1.0;
    } else {
      _rtB->Step = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S5>/Step' */

    /* Clock: '<S9>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S9>/2' */
    currentTime = (((real_T *)mxGetData(FS(S)))[1]);
    y = 2.0 * currentTime;
    currentTime = 1.0 - y;
    _rtB->u = 6.2831853071795862 * currentTime;

    /* Constant: '<S9>/5' */
    _rtB->u_p = (((real_T *)mxGetData(FS(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S4>/Step' */
    currentTime = ssGetTaskTime(S,0);
    if (currentTime < 0.6) {
      _rtB->Step_j = 0.0;
    } else {
      _rtB->Step_j = 1.0;
    }

    /* End of Step: '<S4>/Step' */

    /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
     *  Constant: '<S4>/constant'
     *  Inport: '<Root>/Nomal'
     */
    if ((int32_T)_rtB->Step_j == 0) {
      _rtB->MultiportSwitch = 0.0;
    } else {
      _rtB->MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))
        [0];
    }

    /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

    /* MinMax: '<S4>/MinMax' */
    _rtB->MinMax = _rtB->MultiportSwitch;

    /* Step: '<S3>/Step' */
    currentTime = ssGetTaskTime(S,0);
    if (currentTime < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->Step_h = 1.0;
    } else {
      _rtB->Step_h = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S3>/Step' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S3>/FaultCont1' */
    _rtB->FaultCont1 = (*(real_T *)(mxGetData(Severity1(S))));

    /* Constant: '<S3>/FaultCont2' */
    _rtB->FaultCont2 = (*(real_T *)(mxGetData(Severity2(S))));

    /* Constant: '<S3>/FaultCont4' */
    _rtB->FaultCont4 = (*(real_T *)(mxGetData(Severity3(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
     *  Constant: '<S3>/FaultCont3'
     *  Inport: '<Root>/Outside Signal1'
     */
    switch ((int32_T)_rtB->Step_h) {
     case 1:
      _rtB->MultiportSwitch_g = 0.0;
      break;

     case 2:
     case 5:
     case 6:
      _rtB->MultiportSwitch_g = _rtB->FaultCont1;
      break;

     case 3:
      _rtB->MultiportSwitch_g = _rtB->FaultCont2;
      break;

     case 4:
      _rtB->MultiportSwitch_g = _rtB->FaultCont4;
      break;

     default:
      _rtB->MultiportSwitch_g = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
        [0];
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

    /* Product: '<S1>/Product' */
    _rtB->Product = _rtB->MinMax * _rtB->MultiportSwitch_g;

    /* Clock: '<S9>/Clock1' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock1 = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S9>/4' */
    currentTime = (((real_T *)mxGetData(FS(S)))[1]);
    y = 2.0 * currentTime;
    currentTime = 1.0 + y;
    _rtB->u_a = 6.2831853071795862 * currentTime;

    /* Constant: '<S9>/6' */
    _rtB->u_f = (((real_T *)mxGetData(FS(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S12>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_b = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S12>/2' */
    currentTime = (((real_T *)mxGetData(FS(S)))[1]);
    y = 2.0 * currentTime;
    currentTime = 1.0 + y;
    _rtB->u_l = 12.566370614359172 * currentTime;

    /* Constant: '<S12>/5' */
    _rtB->u_f2 = (((real_T *)mxGetData(FS(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S12>/Clock1' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock1_o = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S12>/4' */
    currentTime = (((real_T *)mxGetData(FS(S)))[1]);
    y = 2.0 * currentTime;
    currentTime = 1.0 - y;
    _rtB->u_c = 12.566370614359172 * currentTime;

    /* Constant: '<S12>/6' */
    _rtB->u_pb = (((real_T *)mxGetData(FS(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S8>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_i = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S8>/2' */
    currentTime = 1.0 + (((real_T *)mxGetData(FS(S)))[1]);
    _rtB->u_k = 3.1415926535897931 * currentTime;

    /* Constant: '<S8>/5' */
    _rtB->u_j = (((real_T *)mxGetData(FS(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S8>/Clock1' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock1_p = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S8>/4' */
    currentTime = 1.0 - (((real_T *)mxGetData(FS(S)))[1]);
    _rtB->u_o = 3.1415926535897931 * currentTime;

    /* Constant: '<S8>/6' */
    _rtB->u_fd = (((real_T *)mxGetData(FS(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S11>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_g = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S11>/2' */
    currentTime = (((real_T *)mxGetData(FS(S)))[1]);
    y = 2.0 * currentTime;
    currentTime = 1.0 - y;
    _rtB->u_h = 6.2831853071795862 * currentTime;

    /* Constant: '<S11>/5' */
    _rtB->u_ka = (((real_T *)mxGetData(FS(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S11>/Clock1' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock1_l = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S11>/4' */
    currentTime = (((real_T *)mxGetData(FS(S)))[1]);
    y = 2.0 * currentTime;
    currentTime = 1.0 + y;
    _rtB->u_of = 6.2831853071795862 * currentTime;

    /* Constant: '<S11>/6' */
    _rtB->u_ax = (((real_T *)mxGetData(FS(S)))[0]);

    /* Constant: '<S10>/Constant' */
    _rtB->Constant = (((real_T *)mxGetData(BearingFP(S)))[0]);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S16>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_h = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S16>/Gain' incorporates:
     *  Constant: '<S16>/Z'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[1]);
    _rtB->Gain = 0.5 * y;

    /* Product: '<S16>/Product1' incorporates:
     *  Constant: '<S16>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1 = _rtB->Gain * y;

    /* Product: '<S16>/Divide' incorporates:
     *  Constant: '<S16>/D'
     *  Constant: '<S16>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Divide = y / currentTime;

    /* Trigonometry: '<S16>/Trigonometric Function1' incorporates:
     *  Constant: '<S16>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1 = cos(y);

    /* Product: '<S16>/Product2' */
    _rtB->Product2 = _rtB->Divide * _rtB->TrigonometricFunction1;

    /* Sum: '<S16>/Subtract' incorporates:
     *  Constant: '<S16>/Constant'
     */
    _rtB->Subtract = 1.0 - _rtB->Product2;

    /* Product: '<S16>/Product3' */
    _rtB->Product3 = _rtB->Product1 * _rtB->Subtract;

    /* Sum: '<S16>/Add' incorporates:
     *  Constant: '<S16>/7'
     */
    y = (((real_T *)mxGetData(FS(S)))[0]);
    _rtB->Add = y + _rtB->Product3;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S17>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_d = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S17>/Gain' incorporates:
     *  Constant: '<S17>/Z'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[1]);
    _rtB->Gain_e = 0.5 * y;

    /* Product: '<S17>/Product1' incorporates:
     *  Constant: '<S17>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_k = _rtB->Gain_e * y;

    /* Product: '<S17>/Divide' incorporates:
     *  Constant: '<S17>/D'
     *  Constant: '<S17>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Divide_j = y / currentTime;

    /* Trigonometry: '<S17>/Trigonometric Function1' incorporates:
     *  Constant: '<S17>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->TrigonometricFunction1_g = cos(y);

    /* Product: '<S17>/Product2' */
    _rtB->Product2_a = _rtB->Divide_j * _rtB->TrigonometricFunction1_g;

    /* Sum: '<S17>/Subtract' incorporates:
     *  Constant: '<S17>/Constant'
     */
    _rtB->Subtract_b = 1.0 - _rtB->Product2_a;

    /* Product: '<S17>/Product3' */
    _rtB->Product3_n = _rtB->Product1_k * _rtB->Subtract_b;

    /* Sum: '<S17>/Subtract1' incorporates:
     *  Constant: '<S17>/7'
     */
    y = (((real_T *)mxGetData(FS(S)))[0]);
    _rtB->Subtract1 = y - _rtB->Product3_n;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S18>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_p = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S18>/Gain' incorporates:
     *  Constant: '<S18>/Z'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[1]);
    _rtB->Gain_k = 0.5 * y;

    /* Product: '<S18>/Product1' incorporates:
     *  Constant: '<S18>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_e = _rtB->Gain_k * y;

    /* Product: '<S18>/Divide' incorporates:
     *  Constant: '<S18>/D'
     *  Constant: '<S18>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Divide_b = y / currentTime;

    /* Trigonometry: '<S18>/Trigonometric Function1' incorporates:
     *  Constant: '<S18>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_a = cos(y);

    /* Product: '<S18>/Product2' */
    _rtB->Product2_h = _rtB->Divide_b * _rtB->TrigonometricFunction1_a;

    /* Sum: '<S18>/Add2' incorporates:
     *  Constant: '<S18>/Constant'
     */
    _rtB->Add2 = 1.0 + _rtB->Product2_h;

    /* Product: '<S18>/Product3' */
    _rtB->Product3_c = _rtB->Product1_e * _rtB->Add2;

    /* Sum: '<S18>/Add' incorporates:
     *  Constant: '<S18>/7'
     *  Constant: '<S18>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    currentTime = (((real_T *)mxGetData(FS(S)))[0]);
    _rtB->Add_a = (y + currentTime) + _rtB->Product3_c;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S19>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_k = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S19>/Gain' incorporates:
     *  Constant: '<S19>/Z'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[1]);
    _rtB->Gain_o = 0.5 * y;

    /* Product: '<S19>/Product1' incorporates:
     *  Constant: '<S19>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_a = _rtB->Gain_o * y;

    /* Product: '<S19>/Divide' incorporates:
     *  Constant: '<S19>/D'
     *  Constant: '<S19>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Divide_a = y / currentTime;

    /* Trigonometry: '<S19>/Trigonometric Function1' incorporates:
     *  Constant: '<S19>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_c = cos(y);

    /* Product: '<S19>/Product2' */
    _rtB->Product2_h2 = _rtB->Divide_a * _rtB->TrigonometricFunction1_c;

    /* Sum: '<S19>/Add2' incorporates:
     *  Constant: '<S19>/Constant'
     */
    _rtB->Add2_p = 1.0 + _rtB->Product2_h2;

    /* Product: '<S19>/Product3' */
    _rtB->Product3_p = _rtB->Product1_a * _rtB->Add2_p;

    /* Sum: '<S19>/Add' incorporates:
     *  Constant: '<S19>/7'
     *  Constant: '<S19>/fr'
     */
    y = (((real_T *)mxGetData(FS(S)))[0]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Add_a1 = (y - currentTime) + _rtB->Product3_p;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S20>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_f = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S20>/Gain' incorporates:
     *  Constant: '<S20>/Z'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[1]);
    _rtB->Gain_i = 0.5 * y;

    /* Product: '<S20>/Product1' incorporates:
     *  Constant: '<S20>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_ez = _rtB->Gain_i * y;

    /* Product: '<S20>/Divide' incorporates:
     *  Constant: '<S20>/D'
     *  Constant: '<S20>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Divide_g = y / currentTime;

    /* Trigonometry: '<S20>/Trigonometric Function1' incorporates:
     *  Constant: '<S20>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_h = cos(y);

    /* Product: '<S20>/Product2' */
    _rtB->Product2_n = _rtB->Divide_g * _rtB->TrigonometricFunction1_h;

    /* Sum: '<S20>/Add2' incorporates:
     *  Constant: '<S20>/Constant'
     */
    _rtB->Add2_m = 1.0 + _rtB->Product2_n;

    /* Product: '<S20>/Product3' */
    _rtB->Product3_l = _rtB->Product1_ez * _rtB->Add2_m;

    /* Sum: '<S20>/Add' incorporates:
     *  Constant: '<S20>/7'
     *  Constant: '<S20>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    currentTime = (((real_T *)mxGetData(FS(S)))[0]);
    _rtB->Add_o = (y + currentTime) - _rtB->Product3_l;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S21>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_bw = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Gain: '<S21>/Gain' incorporates:
     *  Constant: '<S21>/Z'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[1]);
    _rtB->Gain_f = 0.5 * y;

    /* Product: '<S21>/Product1' incorporates:
     *  Constant: '<S21>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_p = _rtB->Gain_f * y;

    /* Product: '<S21>/Divide' incorporates:
     *  Constant: '<S21>/D'
     *  Constant: '<S21>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Divide_gp = y / currentTime;

    /* Trigonometry: '<S21>/Trigonometric Function1' incorporates:
     *  Constant: '<S21>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_hw = cos(y);

    /* Product: '<S21>/Product2' */
    _rtB->Product2_ad = _rtB->Divide_gp * _rtB->TrigonometricFunction1_hw;

    /* Sum: '<S21>/Add2' incorporates:
     *  Constant: '<S21>/Constant'
     */
    _rtB->Add2_i = 1.0 + _rtB->Product2_ad;

    /* Product: '<S21>/Product3' */
    _rtB->Product3_o = _rtB->Product1_p * _rtB->Add2_i;

    /* Sum: '<S21>/Add' incorporates:
     *  Constant: '<S21>/7'
     *  Constant: '<S21>/fr'
     */
    y = (((real_T *)mxGetData(FS(S)))[0]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Add_ot = (y - currentTime) - _rtB->Product3_o;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S22>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_o = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Product: '<S22>/Divide1' incorporates:
     *  Constant: '<S22>/D'
     *  Constant: '<S22>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Divide1 = y / currentTime;

    /* Product: '<S22>/Product1' incorporates:
     *  Constant: '<S22>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_a3 = _rtB->Divide1 * y;

    /* Product: '<S22>/Product5' incorporates:
     *  Constant: '<S22>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Product5 = y * currentTime;

    /* Product: '<S22>/Product6' incorporates:
     *  Constant: '<S22>/D'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Product6 = y * currentTime;

    /* Product: '<S22>/Divide' */
    _rtB->Divide_k = _rtB->Product5 / _rtB->Product6;

    /* Trigonometry: '<S22>/Trigonometric Function1' incorporates:
     *  Constant: '<S22>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_j = cos(y);

    /* Trigonometry: '<S22>/Trigonometric Function3' incorporates:
     *  Constant: '<S22>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction3 = cos(y);

    /* Product: '<S22>/Product7' */
    _rtB->Product7 = _rtB->TrigonometricFunction1_j *
      _rtB->TrigonometricFunction3;

    /* Product: '<S22>/Product2' */
    _rtB->Product2_b = _rtB->Divide_k * _rtB->Product7;

    /* Sum: '<S22>/Add2' incorporates:
     *  Constant: '<S22>/Constant'
     */
    _rtB->Add2_d = 1.0 - _rtB->Product2_b;

    /* Product: '<S22>/Product3' */
    _rtB->Product3_g = _rtB->Product1_a3 * _rtB->Add2_d;

    /* Sum: '<S22>/Add' incorporates:
     *  Constant: '<S22>/7'
     *  Constant: '<S22>/fcage'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[6]);
    currentTime = (((real_T *)mxGetData(FS(S)))[0]);
    _rtB->Add_j = (y + currentTime) + _rtB->Product3_g;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S23>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_ka = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Product: '<S23>/Divide1' incorporates:
     *  Constant: '<S23>/D'
     *  Constant: '<S23>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Divide1_i = y / currentTime;

    /* Product: '<S23>/Product1' incorporates:
     *  Constant: '<S23>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_b = _rtB->Divide1_i * y;

    /* Product: '<S23>/Product5' incorporates:
     *  Constant: '<S23>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Product5_f = y * currentTime;

    /* Product: '<S23>/Product6' incorporates:
     *  Constant: '<S23>/D'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Product6_k = y * currentTime;

    /* Product: '<S23>/Divide' */
    _rtB->Divide_ju = _rtB->Product5_f / _rtB->Product6_k;

    /* Trigonometry: '<S23>/Trigonometric Function1' incorporates:
     *  Constant: '<S23>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_b = cos(y);

    /* Trigonometry: '<S23>/Trigonometric Function3' incorporates:
     *  Constant: '<S23>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction3_d = cos(y);

    /* Product: '<S23>/Product7' */
    _rtB->Product7_k = _rtB->TrigonometricFunction1_b *
      _rtB->TrigonometricFunction3_d;

    /* Product: '<S23>/Product2' */
    _rtB->Product2_j = _rtB->Divide_ju * _rtB->Product7_k;

    /* Sum: '<S23>/Add2' incorporates:
     *  Constant: '<S23>/Constant'
     */
    _rtB->Add2_c = 1.0 - _rtB->Product2_j;

    /* Product: '<S23>/Product3' */
    _rtB->Product3_n5 = _rtB->Product1_b * _rtB->Add2_c;

    /* Sum: '<S23>/Add' incorporates:
     *  Constant: '<S23>/7'
     *  Constant: '<S23>/fcage'
     */
    y = (((real_T *)mxGetData(FS(S)))[0]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[6]);
    _rtB->Add_l = (y - currentTime) + _rtB->Product3_n5;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S24>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_e = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Product: '<S24>/Divide1' incorporates:
     *  Constant: '<S24>/D'
     *  Constant: '<S24>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Divide1_b = y / currentTime;

    /* Product: '<S24>/Product1' incorporates:
     *  Constant: '<S24>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_i = _rtB->Divide1_b * y;

    /* Product: '<S24>/Product5' incorporates:
     *  Constant: '<S24>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Product5_fk = y * currentTime;

    /* Product: '<S24>/Product6' incorporates:
     *  Constant: '<S24>/D'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Product6_j = y * currentTime;

    /* Product: '<S24>/Divide' */
    _rtB->Divide_i = _rtB->Product5_fk / _rtB->Product6_j;

    /* Trigonometry: '<S24>/Trigonometric Function1' incorporates:
     *  Constant: '<S24>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_j5 = cos(y);

    /* Trigonometry: '<S24>/Trigonometric Function3' incorporates:
     *  Constant: '<S24>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction3_l = cos(y);

    /* Product: '<S24>/Product7' */
    _rtB->Product7_l = _rtB->TrigonometricFunction1_j5 *
      _rtB->TrigonometricFunction3_l;

    /* Product: '<S24>/Product2' */
    _rtB->Product2_bv = _rtB->Divide_i * _rtB->Product7_l;

    /* Sum: '<S24>/Add2' incorporates:
     *  Constant: '<S24>/Constant'
     */
    _rtB->Add2_o = 1.0 - _rtB->Product2_bv;

    /* Product: '<S24>/Product3' */
    _rtB->Product3_k = _rtB->Product1_i * _rtB->Add2_o;

    /* Sum: '<S24>/Add' incorporates:
     *  Constant: '<S24>/7'
     *  Constant: '<S24>/fcage'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[6]);
    currentTime = (((real_T *)mxGetData(FS(S)))[0]);
    _rtB->Add_e = (y + currentTime) - _rtB->Product3_k;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Clock: '<S25>/Clock' */
    ((B_MFI_T *) ssGetLocalBlockIO(S))->Clock_k2 = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Product: '<S25>/Divide1' incorporates:
     *  Constant: '<S25>/D'
     *  Constant: '<S25>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Divide1_f = y / currentTime;

    /* Product: '<S25>/Product1' incorporates:
     *  Constant: '<S25>/fr'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[2]);
    _rtB->Product1_o = _rtB->Divide1_f * y;

    /* Product: '<S25>/Product5' incorporates:
     *  Constant: '<S25>/d'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[3]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[3]);
    _rtB->Product5_k = y * currentTime;

    /* Product: '<S25>/Product6' incorporates:
     *  Constant: '<S25>/D'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[4]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[4]);
    _rtB->Product6_ki = y * currentTime;

    /* Product: '<S25>/Divide' */
    _rtB->Divide_m = _rtB->Product5_k / _rtB->Product6_ki;

    /* Trigonometry: '<S25>/Trigonometric Function1' incorporates:
     *  Constant: '<S25>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction1_n = cos(y);

    /* Trigonometry: '<S25>/Trigonometric Function3' incorporates:
     *  Constant: '<S25>/a'
     */
    y = (((real_T *)mxGetData(BearingFP(S)))[5]);
    _rtB->TrigonometricFunction3_g = cos(y);

    /* Product: '<S25>/Product7' */
    _rtB->Product7_m = _rtB->TrigonometricFunction1_n *
      _rtB->TrigonometricFunction3_g;

    /* Product: '<S25>/Product2' */
    _rtB->Product2_ji = _rtB->Divide_m * _rtB->Product7_m;

    /* Sum: '<S25>/Add2' incorporates:
     *  Constant: '<S25>/Constant'
     */
    _rtB->Add2_b = 1.0 - _rtB->Product2_ji;

    /* Product: '<S25>/Product3' */
    _rtB->Product3_m = _rtB->Product1_o * _rtB->Add2_b;

    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S25>/7'
     *  Constant: '<S25>/fcage'
     */
    y = (((real_T *)mxGetData(FS(S)))[0]);
    currentTime = (((real_T *)mxGetData(BearingFP(S)))[6]);
    _rtB->Add_f = (y - currentTime) - _rtB->Product3_m;

    /* Constant: '<S1>/Constant2' */
    _rtB->Constant2 = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    switch ((int32_T)_rtB->MultiportSwitch3) {
     case 1:
      /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
       *  Constant: '<S5>/FaultCont3'
       */
      switch ((int32_T)_rtB->Step) {
       case 1:
       case 7:
        _rtB->MultiportSwitch_f = 0.0;
        break;

       case 2:
        /* Product: '<S9>/Product2' */
        _rtB->Product2_g = _rtB->Clock1 * _rtB->u_a * _rtB->u_f;

        /* Sum: '<S9>/Add1' incorporates:
         *  Constant: '<S9>/3'
         */
        _rtB->Add1_k = 1.0471975511965976 + _rtB->Product2_g;

        /* Trigonometry: '<S9>/Trigonometric Function1' */
        _rtB->TrigonometricFunction1_be = cos(_rtB->Add1_k);

        /* Product: '<S9>/Product3' */
        _rtB->Product3_oy = _rtB->TrigonometricFunction1_be * _rtB->Product;

        /* Product: '<S9>/Product' */
        _rtB->Product_k = _rtB->Clock * _rtB->u * _rtB->u_p;

        /* Sum: '<S9>/Add' incorporates:
         *  Constant: '<S9>/1'
         */
        _rtB->Add_oe = 0.31415926535897931 + _rtB->Product_k;

        /* Trigonometry: '<S9>/Trigonometric Function' */
        _rtB->TrigonometricFunction = cos(_rtB->Add_oe);

        /* Product: '<S9>/Product1' */
        _rtB->Product1_d = _rtB->TrigonometricFunction * _rtB->Product;

        /* Sum: '<S9>/Add2' */
        _rtB->Add2_dz = _rtB->Product1_d + _rtB->Product3_oy;
        _rtB->MultiportSwitch_f = _rtB->Add2_dz;
        break;

       case 3:
        /* Product: '<S12>/Product2' */
        _rtB->Product2_af = _rtB->Clock1_o * _rtB->u_c * _rtB->u_pb;

        /* Sum: '<S12>/Add1' incorporates:
         *  Constant: '<S12>/3'
         */
        _rtB->Add1_n = 2.0943951023931953 + _rtB->Product2_af;

        /* Trigonometry: '<S12>/Trigonometric Function1' */
        _rtB->TrigonometricFunction1_d = cos(_rtB->Add1_n);

        /* Product: '<S12>/Product3' */
        _rtB->Product3_np = _rtB->TrigonometricFunction1_d * _rtB->Product;

        /* Product: '<S12>/Product' */
        _rtB->Product_h = _rtB->Clock_b * _rtB->u_l * _rtB->u_f2;

        /* Sum: '<S12>/Add' incorporates:
         *  Constant: '<S12>/1'
         */
        _rtB->Add_i = 1.0471975511965976 + _rtB->Product_h;

        /* Trigonometry: '<S12>/Trigonometric Function' */
        _rtB->TrigonometricFunction_h = cos(_rtB->Add_i);

        /* Product: '<S12>/Product1' */
        _rtB->Product1_h = _rtB->TrigonometricFunction_h * _rtB->Product;

        /* Sum: '<S12>/Add2' */
        _rtB->Add2_b3 = _rtB->Product1_h + _rtB->Product3_np;
        _rtB->MultiportSwitch_f = _rtB->Add2_b3;
        break;

       case 4:
        /* Product: '<S8>/Product2' */
        _rtB->Product2_gv = _rtB->Clock1_p * _rtB->u_o * _rtB->u_fd;

        /* Sum: '<S8>/Add1' incorporates:
         *  Constant: '<S8>/3'
         */
        _rtB->Add1_n0 = 2.0943951023931953 + _rtB->Product2_gv;

        /* Trigonometry: '<S8>/Trigonometric Function1' */
        _rtB->TrigonometricFunction1_m = cos(_rtB->Add1_n0);

        /* Product: '<S8>/Product3' */
        _rtB->Product3_h = _rtB->TrigonometricFunction1_m * _rtB->Product;

        /* Product: '<S8>/Product' */
        _rtB->Product_j = _rtB->Clock_i * _rtB->u_k * _rtB->u_j;

        /* Sum: '<S8>/Add' incorporates:
         *  Constant: '<S8>/1'
         */
        _rtB->Add_h = 1.0471975511965976 + _rtB->Product_j;

        /* Trigonometry: '<S8>/Trigonometric Function' */
        _rtB->TrigonometricFunction_k = cos(_rtB->Add_h);

        /* Product: '<S8>/Product1' */
        _rtB->Product1_aq = _rtB->TrigonometricFunction_k * _rtB->Product;

        /* Sum: '<S8>/Add2' */
        _rtB->Add2_mo = _rtB->Product1_aq + _rtB->Product3_h;
        _rtB->MultiportSwitch_f = _rtB->Add2_mo;
        break;

       case 5:
        /* Product: '<S11>/Product2' */
        _rtB->Product2_k = _rtB->Clock1_l * _rtB->u_of * _rtB->u_ax;

        /* Sum: '<S11>/Add1' incorporates:
         *  Constant: '<S11>/3'
         */
        _rtB->Add1_h = 1.0471975511965976 + _rtB->Product2_k;

        /* Trigonometry: '<S11>/Trigonometric Function1' */
        _rtB->TrigonometricFunction1_az = cos(_rtB->Add1_h);

        /* Product: '<S11>/Product3' */
        _rtB->Product3_f = _rtB->TrigonometricFunction1_az * _rtB->Product;

        /* Product: '<S11>/Product' */
        _rtB->Product_m = _rtB->Clock_g * _rtB->u_h * _rtB->u_ka;

        /* Sum: '<S11>/Add' incorporates:
         *  Constant: '<S11>/1'
         */
        _rtB->Add_c = 0.31415926535897931 + _rtB->Product_m;

        /* Trigonometry: '<S11>/Trigonometric Function' */
        _rtB->TrigonometricFunction_c = cos(_rtB->Add_c);

        /* Product: '<S11>/Product1' */
        _rtB->Product1_l = _rtB->TrigonometricFunction_c * _rtB->Product;

        /* Sum: '<S11>/Add2' */
        _rtB->Add2_k = _rtB->Product1_l + _rtB->Product3_f;
        _rtB->MultiportSwitch_f = _rtB->Add2_k;
        break;

       default:
        /* MultiPortSwitch: '<S10>/Multiport Switch' */
        switch ((int32_T)_rtB->Constant) {
         case 1:
          /* Product: '<S17>/Product4' incorporates:
           *  Constant: '<S17>/Constant1'
           */
          _rtB->Product4 = 6.2831853071795862 * _rtB->Clock_d * _rtB->Subtract1;

          /* Sum: '<S17>/Add1' incorporates:
           *  Constant: '<S17>/1'
           */
          _rtB->Add1_nm = 0.62831853071795862 + _rtB->Product4;

          /* Trigonometry: '<S17>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2 = cos(_rtB->Add1_nm);

          /* Product: '<S16>/Product4' incorporates:
           *  Constant: '<S16>/Constant1'
           */
          _rtB->Product4_a = 6.2831853071795862 * _rtB->Clock_h * _rtB->Add;

          /* Sum: '<S16>/Add1' incorporates:
           *  Constant: '<S16>/1'
           */
          _rtB->Add1_kz = 0.31415926535897931 + _rtB->Product4_a;

          /* Trigonometry: '<S16>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_a = cos(_rtB->Add1_kz);

          /* Product: '<S13>/Product5' */
          _rtB->Product5_c = _rtB->TrigonometricFunction2_a * _rtB->Product;

          /* Sum: '<S13>/Add' */
          _rtB->Add_oj = _rtB->Product5_c + _rtB->TrigonometricFunction2;
          _rtB->MultiportSwitch_fe = _rtB->Add_oj;
          break;

         case 2:
          /* Product: '<S21>/Product4' incorporates:
           *  Constant: '<S21>/Constant1'
           */
          _rtB->Product4_am = 6.2831853071795862 * _rtB->Clock_bw * _rtB->Add_ot;

          /* Sum: '<S21>/Add1' incorporates:
           *  Constant: '<S21>/1'
           */
          _rtB->Add1_j = 1.2566370614359172 + _rtB->Product4_am;

          /* Trigonometry: '<S21>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_j = cos(_rtB->Add1_j);

          /* Product: '<S20>/Product4' incorporates:
           *  Constant: '<S20>/Constant1'
           */
          _rtB->Product4_p = 6.2831853071795862 * _rtB->Clock_f * _rtB->Add_o;

          /* Sum: '<S20>/Add1' incorporates:
           *  Constant: '<S20>/1'
           */
          _rtB->Add1_b = 0.94247779607693793 + _rtB->Product4_p;

          /* Trigonometry: '<S20>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_e = cos(_rtB->Add1_b);

          /* Product: '<S19>/Product4' incorporates:
           *  Constant: '<S19>/Constant1'
           */
          _rtB->Product4_d = 6.2831853071795862 * _rtB->Clock_k * _rtB->Add_a1;

          /* Sum: '<S19>/Add1' incorporates:
           *  Constant: '<S19>/1'
           */
          _rtB->Add1_o = 0.62831853071795862 + _rtB->Product4_d;

          /* Trigonometry: '<S19>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_l = cos(_rtB->Add1_o);

          /* Product: '<S18>/Product4' incorporates:
           *  Constant: '<S18>/Constant1'
           */
          _rtB->Product4_i = 6.2831853071795862 * _rtB->Clock_p * _rtB->Add_a;

          /* Sum: '<S18>/Add1' incorporates:
           *  Constant: '<S18>/1'
           */
          _rtB->Add1_g = 0.31415926535897931 + _rtB->Product4_i;

          /* Trigonometry: '<S18>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_n = cos(_rtB->Add1_g);

          /* Product: '<S14>/Product5' */
          _rtB->Product5_h = _rtB->TrigonometricFunction2_n * _rtB->Product;

          /* Sum: '<S14>/Add' */
          _rtB->Add_e0 = ((_rtB->Product5_h + _rtB->TrigonometricFunction2_l) +
                          _rtB->TrigonometricFunction2_e) +
            _rtB->TrigonometricFunction2_j;
          _rtB->MultiportSwitch_fe = _rtB->Add_e0;
          break;

         default:
          /* Product: '<S25>/Product4' incorporates:
           *  Constant: '<S25>/Constant1'
           */
          _rtB->Product4_j = 6.2831853071795862 * _rtB->Clock_k2 * _rtB->Add_f;

          /* Sum: '<S25>/Add1' incorporates:
           *  Constant: '<S25>/1'
           */
          _rtB->Add1_b4 = 1.2566370614359172 + _rtB->Product4_j;

          /* Trigonometry: '<S25>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_g = cos(_rtB->Add1_b4);

          /* Product: '<S24>/Product4' incorporates:
           *  Constant: '<S24>/Constant1'
           */
          _rtB->Product4_at = 6.2831853071795862 * _rtB->Clock_e * _rtB->Add_e;

          /* Sum: '<S24>/Add1' incorporates:
           *  Constant: '<S24>/1'
           */
          _rtB->Add1_jd = 0.94247779607693793 + _rtB->Product4_at;

          /* Trigonometry: '<S24>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_i = cos(_rtB->Add1_jd);

          /* Product: '<S23>/Product4' incorporates:
           *  Constant: '<S23>/Constant1'
           */
          _rtB->Product4_m = 6.2831853071795862 * _rtB->Clock_ka * _rtB->Add_l;

          /* Sum: '<S23>/Add1' incorporates:
           *  Constant: '<S23>/1'
           */
          _rtB->Add1_i = 0.62831853071795862 + _rtB->Product4_m;

          /* Trigonometry: '<S23>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_b = cos(_rtB->Add1_i);

          /* Product: '<S22>/Product4' incorporates:
           *  Constant: '<S22>/Constant1'
           */
          _rtB->Product4_b = 6.2831853071795862 * _rtB->Clock_o * _rtB->Add_j;

          /* Sum: '<S22>/Add1' incorporates:
           *  Constant: '<S22>/1'
           */
          _rtB->Add1_jr = 0.31415926535897931 + _rtB->Product4_b;

          /* Trigonometry: '<S22>/Trigonometric Function2' */
          _rtB->TrigonometricFunction2_bw = cos(_rtB->Add1_jr);

          /* Product: '<S15>/Product5' */
          _rtB->Product5_fa = _rtB->TrigonometricFunction2_bw * _rtB->Product;

          /* Sum: '<S15>/Add' */
          _rtB->Add_k = ((_rtB->Product5_fa + _rtB->TrigonometricFunction2_b) +
                         _rtB->TrigonometricFunction2_i) +
            _rtB->TrigonometricFunction2_g;
          _rtB->MultiportSwitch_fe = _rtB->Add_k;
          break;
        }

        /* End of MultiPortSwitch: '<S10>/Multiport Switch' */
        _rtB->MultiportSwitch_f = _rtB->MultiportSwitch_fe;
        break;
      }

      /* End of MultiPortSwitch: '<S5>/Multiport Switch' */

      /* Sum: '<S1>/Add1' incorporates:
       *  Inport: '<Root>/Nomal'
       */
      _rtB->Add1 = _rtB->MultiportSwitch_f + *((const real_T **)
        ssGetInputPortSignalPtrs(S, 0))[0];
      _rtB->MultiportSwitch2_i = _rtB->Add1;
      break;

     case 2:
      _rtB->MultiportSwitch2_i = *((const real_T **)ssGetInputPortSignalPtrs(S,
        0))[0];
      break;

     default:
      /* MultiPortSwitch: '<S1>/Multiport' */
      switch ((int32_T)_rtB->Constant2) {
       case 0:
        /* Sum: '<S1>/Add2' incorporates:
         *  Inport: '<Root>/Nomal'
         */
        _rtB->Add2_h = _rtB->MultiportSwitch_g + *((const real_T **)
          ssGetInputPortSignalPtrs(S, 0))[0];
        _rtB->Multiport_d = _rtB->Add2_h;
        break;

       case 1:
        /* Product: '<S1>/Product1' incorporates:
         *  Inport: '<Root>/Nomal'
         */
        _rtB->Product1_oo = _rtB->MultiportSwitch_g * *((const real_T **)
          ssGetInputPortSignalPtrs(S, 0))[0];
        _rtB->Multiport_d = _rtB->Product1_oo;
        break;

       default:
        _rtB->Multiport_d = _rtB->MultiportSwitch_g;
        break;
      }

      /* End of MultiPortSwitch: '<S1>/Multiport' */
      _rtB->MultiportSwitch2_i = _rtB->Multiport_d;
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */

    /* Sum: '<S1>/NoiseAdd' */
    _rtB->NoiseAdd = _rtB->Switch + _rtB->MultiportSwitch2_i;

    /* Outport: '<Root>/Out' */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->NoiseAdd;
  }
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Termination for root system: '<Root>' */
static void mdlTerminate(SimStruct *S)
{

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

  if (ssGetUserData(S) != (NULL) ) {
    rt_FREE(ssGetLocalBlockIO(S));
  }

  rt_FREE(ssGetUserData(S));

#endif

}

/* This function checks the attributes of tunable parameters. */
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{
  /* Parameter check for 'AddMux' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'AddMux' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'AddMux' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'AddMux' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'BearingFP' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'BearingFP' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'BearingFP' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 7) ) {
    ssSetErrorStatus(S,"Parameter 'BearingFP' has to be a [1x7] array.");
    return;
  }

  /* Parameter check for 'FS' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'FS' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'FS' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 2) ) {
    ssSetErrorStatus(S,"Parameter 'FS' has to be a [1x2] array.");
    return;
  }

  /* Parameter check for 'FaultInjectionTime' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultInjectionTime' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'FaultType' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'NoiseSelec' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'Severity1' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'Severity1' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'Severity1' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Severity1' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'Severity2' */
  if (mxIsComplex(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,"Parameter 'Severity2' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,"Parameter 'Severity2' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 7)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Severity2' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'Severity3' */
  if (mxIsComplex(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,"Parameter 'Severity3' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,"Parameter 'Severity3' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 8)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Severity3' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "MFI_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 1))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 3))
    return;

  /* inport number: 0 */
  {
    if (!ssSetInputPortVectorDimension(S, 0, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 0, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortSampleTime(S, 0, 0.0);
    ssSetInputPortOffsetTime(S, 0, 0.0);
    ssSetInputPortOverWritable(S, 0, 0);
    ssSetInputPortOptimOpts(S, 0, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 1 */
  {
    if (!ssSetInputPortVectorDimension(S, 1, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 1, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 1, 1);
    ssSetInputPortSampleTime(S, 1, 0.0);
    ssSetInputPortOffsetTime(S, 1, 0.0);
    ssSetInputPortOverWritable(S, 1, 0);
    ssSetInputPortOptimOpts(S, 1, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 2 */
  {
    if (!ssSetInputPortVectorDimension(S, 2, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 2, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 2, 1);
    ssSetInputPortSampleTime(S, 2, 1.0E-5);
    ssSetInputPortOffsetTime(S, 2, 0.0);
    ssSetInputPortOverWritable(S, 2, 0);
    ssSetInputPortOptimOpts(S, 2, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 9);

  /* Number of expected parameters */
#if defined(MATLAB_MEX_FILE)

  if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {

#if defined(MDL_CHECK_PARAMETERS)

    mdlCheckParameters(S);

#endif                                 /* MDL_CHECK_PARAMETERS */

    if (ssGetErrorStatus(S) != (NULL) ) {
      return;
    }
  } else {
    return;                            /* Parameter mismatch will be reported by Simulink */
  }

#endif                                 /* MATLAB_MEX_FILE */

  /* Options */
  ssSetOptions(S, (SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE |
                   SS_OPTION_PORT_SAMPLE_TIMES_ASSIGNED ));

#if SS_SFCN_FOR_SIM

  {
    ssSupportsMultipleExecInstances(S, true);
    ssHasStateInsideForEachSS(S, false);
  }

#endif

}

/* Function to initialize sample times. */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* task periods */
  ssSetSampleTime(S, 0, 0.0);
  ssSetSampleTime(S, 1, 1.0E-5);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
  ssSetOffsetTime(S, 1, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               MFI_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
