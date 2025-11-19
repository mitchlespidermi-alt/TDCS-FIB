/*
 * SFI0_sf.c
 *
 * Code generation for model "SFI0_sf".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Apr 06 14:43:03 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "SFI0_sf.h"
#include "SFI0_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *SFI0_malloc(SimStruct *S);

#endif

#ifndef __RTW_UTFREE__
#if defined (MATLAB_MEX_FILE)

extern void * utMalloc(size_t);
extern void utFree(void *);

#endif
#endif                                 /* #ifndef __RTW_UTFREE__ */

/* Forward declaration for local functions */
static real_T SFI0_rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
static real_T SFI0_rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);

#if defined(MATLAB_MEX_FILE)
#include "rt_nonfinite.c"
#endif

static const char_T *RT_MEMORY_ALLOCATION_ERROR =
  "memory allocation error in generated S-Function";
static real_T SFI0_rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

static real_T SFI0_rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * SFI0_rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * SFI0_rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

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

  SFI0_malloc(S);
  if (ssGetErrorStatus(S) != (NULL) ) {
    return;
  }

#endif

  {
    /* Start for RandomNumber: '<S3>/Random Number' */
    ((uint32_T *)ssGetDWork(S, 1))[0] = 1144108930U;
    ((real_T *)ssGetDWork(S, 0))[0] = SFI0_rt_nrand_Upu32_Yd_f_pw_snf
      (&((uint32_T *)ssGetDWork(S, 1))[0]) * sqrt((*(real_T *)(mxGetData
      (Variance(S)))));
  }
}

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Clock;
  real_T rtb_MultiportSwitch;
  real_T rtb_MultiportSwitch1;
  real_T rtb_FaultSelec_j;
  real_T rtb_FaultSelec;
  real_T rtb_Step;
  real_T rtb_Add;
  real_T rtb_FaultSelec1;
  boolean_T rtb_Compare_o;
  B_SFI0_T *_rtB;
  _rtB = ((B_SFI0_T *) ssGetLocalBlockIO(S));
  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S3>/FaultSelec' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      rtb_FaultSelec_j = 1.0;
    } else {
      rtb_FaultSelec_j = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S3>/FaultSelec' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Logic: '<S8>/Logical Operator' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S11>/Constant'
     *  Constant: '<S8>/FaultType'
     *  RelationalOperator: '<S10>/Compare'
     *  RelationalOperator: '<S11>/Compare'
     */
    _rtB->LogicalOperator = (((*(real_T *)(mxGetData(FaultType(S)))) == 7.0) ||
                             ((*(real_T *)(mxGetData(FaultType(S)))) == 8.0));

    /* Constant: '<S3>/ST_OF_GA_Cont' */
    _rtB->ST_OF_GA_Cont = (*(real_T *)(mxGetData(FaultCont(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S3>/Shock_Fault' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S)))) +
        0.02) {
      rtb_MultiportSwitch1 = (*(real_T *)(mxGetData(ShockGain(S))));
    } else {
      rtb_MultiportSwitch1 = 1.0;
    }

    /* End of Step: '<S3>/Shock_Fault' */

    /* Step: '<S9>/Step' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      rtb_Step = 0.0;
    } else {
      rtb_Step = (((real_T *)mxGetData(DriftFault(S)))[0]);
    }

    /* End of Step: '<S9>/Step' */

    /* Clock: '<S9>/Clock' */
    rtb_Clock = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S9>/Constant' */
    _rtB->Constant = (*(real_T *)(mxGetData(FaultInjectionTime(S))));

    /* Constant: '<S9>/Constant1' */
    _rtB->Constant1 = (((real_T *)mxGetData(DriftFault(S)))[1]);

    /* Gain: '<S3>/Gain' incorporates:
     *  RandomNumber: '<S3>/Random Number'
     */
    _rtB->Gain = 5.0 * ((real_T *)ssGetDWork(S, 0))[0];
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
     *  Inport: '<Root>/Inport1'
     *  Inport: '<Root>/Inport2'
     *  Inport: '<Root>/Outside Signal'
     *  Product: '<S9>/Product'
     *  Sum: '<S9>/Output'
     *  Sum: '<S9>/Sum'
     */
    switch ((int32_T)rtb_FaultSelec_j) {
     case 1:
     case 2:
     case 3:
     case 11:
      rtb_MultiportSwitch = _rtB->LogicalOperator;
      break;

     case 4:
      rtb_MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];
      break;

     case 5:
     case 6:
     case 7:
      rtb_MultiportSwitch = _rtB->ST_OF_GA_Cont;
      break;

     case 8:
      rtb_MultiportSwitch = rtb_MultiportSwitch1;
      break;

     case 9:
      rtb_MultiportSwitch = (rtb_Clock - _rtB->Constant) * rtb_Step +
        _rtB->Constant1;
      break;

     case 10:
      rtb_MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0];
      break;

     case 12:
      rtb_MultiportSwitch = _rtB->Gain;
      break;

     default:
      rtb_MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0];
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

    /* Sum: '<S1>/Add' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    rtb_Add = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] +
      rtb_MultiportSwitch;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S5>/Constant' */
    _rtB->Constant_f = (*(real_T *)(mxGetData(Comp_ConV(S))));

    /* Constant: '<S2>/FaultCont' */
    _rtB->FaultCont = (*(real_T *)(mxGetData(FaultCont(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S2>/FaultSelec' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      rtb_FaultSelec = 1.0;
    } else {
      rtb_FaultSelec = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S2>/FaultSelec' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Logic: '<S3>/Logical' incorporates:
     *  Constant: '<S3>/Constant2'
     */
    _rtB->Logical = !((*(real_T *)(mxGetData(AddMux(S)))) - 1.0 != 0.0);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S3>/FaultSelec1' */
    if (ssGetTaskTime(S,0) < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      rtb_FaultSelec1 = 1.0;
    } else {
      rtb_FaultSelec1 = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S3>/FaultSelec1' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* MultiPortSwitch: '<S3>/Multiport1' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S3>/Constant4'
     *  Constant: '<S7>/Constant'
     *  RelationalOperator: '<S7>/Compare'
     */
    if (((*(real_T *)(mxGetData(AddMux(S)))) - 1.0 == 2.0) == 0) {
      _rtB->Multiport1 = 7.0;
    } else {
      _rtB->Multiport1 = 13.0;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport1' */
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S2>/Multiport Switch1' incorporates:
     *  Constant: '<S2>/23'
     */
    switch ((int32_T)rtb_FaultSelec) {
     case 1:
     case 4:
     case 6:
     case 7:
     case 8:
     case 9:
     case 10:
     case 11:
     case 12:
     case 13:
      /* RelationalOperator: '<S6>/Compare' incorporates:
       *  Constant: '<S6>/Constant'
       */
      rtb_Compare_o = (rtb_FaultSelec1 == 13.0);

      /* MultiPortSwitch: '<S3>/Multiport Switch2' incorporates:
       *  Constant: '<S3>/Constant3'
       *  Logic: '<S3>/Logical '
       */
      if ((_rtB->Logical && rtb_Compare_o) == 0) {
        /* MultiPortSwitch: '<S3>/Multiport' incorporates:
         *  Constant: '<S3>/Constant2'
         *  Logic: '<S3>/Logical Operator'
         */
        switch (((*(real_T *)(mxGetData(AddMux(S)))) - 1.0 != 0.0) &&
                rtb_Compare_o) {
         case 0:
          break;

         default:
          rtb_FaultSelec1 = _rtB->Multiport1;
          break;
        }

        /* End of MultiPortSwitch: '<S3>/Multiport' */
      } else {
        rtb_FaultSelec1 = 4.0;
      }

      /* End of MultiPortSwitch: '<S3>/Multiport Switch2' */

      /* MultiPortSwitch: '<S3>/Multiport Switch3' incorporates:
       *  Constant: '<S3>/1'
       *  Constant: '<S3>/2'
       *  Constant: '<S3>/3'
       *  Constant: '<S3>/4'
       *  Constant: '<S3>/7'
       */
      switch ((int32_T)rtb_FaultSelec1) {
       case 1:
       case 2:
       case 3:
       case 5:
        rtb_FaultSelec_j = 4.0;
        break;

       case 4:
       case 6:
       case 9:
       case 10:
       case 12:
        rtb_FaultSelec_j = 1.0;
        break;

       case 7:
       case 8:
        rtb_FaultSelec_j = 3.0;
        break;

       case 11:
        rtb_FaultSelec_j = 2.0;
        break;

       default:
        rtb_FaultSelec_j = 5.0;
        break;
      }

      /* End of MultiPortSwitch: '<S3>/Multiport Switch3' */

      /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
       *  Inport: '<Root>/Nomal'
       *  Product: '<S1>/Product'
       */
      switch ((int32_T)rtb_FaultSelec_j) {
       case 1:
        rtb_MultiportSwitch = rtb_Add;
        break;

       case 2:
        /* MultiPortSwitch: '<S4>/Switch' incorporates:
         *  Abs: '<S4>/Abs'
         *  Constant: '<S4>/Constant'
         *  RelationalOperator: '<S5>/Compare'
         */
        switch (fabs(rtb_Add) <= _rtB->Constant_f) {
         case 0:
          break;

         default:
          rtb_Add = 0.0;
          break;
        }

        /* End of MultiPortSwitch: '<S4>/Switch' */
        rtb_MultiportSwitch = rtb_Add;
        break;

       case 3:
        rtb_MultiportSwitch *= *((const real_T **)ssGetInputPortSignalPtrs(S, 0))
          [0];
        break;

       case 4:
        rtb_MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))
          [0];
        break;
      }

      /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */
      rtb_MultiportSwitch1 = rtb_MultiportSwitch;
      break;

     case 2:
     case 3:
      rtb_MultiportSwitch1 = 0.0;
      break;

     default:
      rtb_MultiportSwitch1 = _rtB->FaultCont;
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch1' */
  }

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
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Outport: '<Root>/Out' incorporates:
     *  Sum: '<S1>/NoiseAdd'
     */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->Switch +
      rtb_MultiportSwitch1;
  }
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  if (ssIsSampleHit(S, 1, tid)) {
    /* Update for RandomNumber: '<S3>/Random Number' */
    ((real_T *)ssGetDWork(S, 0))[0] = SFI0_rt_nrand_Upu32_Yd_f_pw_snf
      (&((uint32_T *)ssGetDWork(S, 1))[0]) * sqrt((*(real_T *)(mxGetData
      (Variance(S)))));
  }
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

  /* Parameter check for 'Comp_ConV' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'Comp_ConV' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'Comp_ConV' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Comp_ConV' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'DriftFault' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'DriftFault' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'DriftFault' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 2) ) {
    ssSetErrorStatus(S,"Parameter 'DriftFault' has to be a [1x2] array.");
    return;
  }

  /* Parameter check for 'FaultCont' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'FaultCont' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'FaultCont' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultCont' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'FaultInjectionTime' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultInjectionTime' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'FaultType' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'NoiseSelec' */
  if (mxIsComplex(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 6))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 6)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 6))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'ShockGain' */
  if (mxIsComplex(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,"Parameter 'ShockGain' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 7))) {
    ssSetErrorStatus(S,"Parameter 'ShockGain' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 7)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 7))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'ShockGain' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'Variance' */
  if (mxIsComplex(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,"Parameter 'Variance' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 8))) {
    ssSetErrorStatus(S,"Parameter 'Variance' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 8)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 8))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Variance' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "SFI0_mid.h"
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
  if (!ssSetNumInputPorts(S, 4))
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

  /* inport number: 3 */
  {
    if (!ssSetInputPortVectorDimension(S, 3, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 3, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 3, 1);
    ssSetInputPortSampleTime(S, 3, 1.0E-5);
    ssSetInputPortOffsetTime(S, 3, 0.0);
    ssSetInputPortOverWritable(S, 3, 0);
    ssSetInputPortOptimOpts(S, 3, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* DWork */
  if (!ssSetNumDWork(S, 2)) {
    return;
  }

  /* '<S3>/Random Number': NextOutput */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);

  /* '<S3>/Random Number': RandSeed */
  ssSetDWorkName(S, 1, "DWORK1");
  ssSetDWorkWidth(S, 1, 1);
  ssSetDWorkDataType(S, 1, SS_UINT32);

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
# define S_FUNCTION_NAME               SFI0_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
