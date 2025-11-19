/*
 * IntermediateDClinkN_sf.c
 *
 * Code generation for model "IntermediateDClinkN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:25:25 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "IntermediateDClinkN_sf.h"
#include "IntermediateDClinkN_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *IntermediateDClinkN_malloc(SimStruct *S);

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

#  endif

  IntermediateDClinkN_malloc(S);
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
  B_IntermediateDClinkN_T *_rtB;
  _rtB = ((B_IntermediateDClinkN_T *) ssGetLocalBlockIO(S));

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/In1'
   */
  _rtB->Compare = (*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] == 1.0);

  /* Gain: '<S1>/Gain' */
  _rtB->Gain = (uint8_T)(_rtB->Compare ? ((uint8_T)128U) : 0);

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  Inport: '<Root>/In1'
   */
  _rtB->Compare_n = (*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] ==
                     0.0);

  /* Gain: '<S1>/Gain1' */
  _rtB->Gain1 = (uint8_T)(_rtB->Compare_n ? ((uint8_T)128U) : 0);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/In1'
   */
  _rtB->Compare_g = (*((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] ==
                     (-1.0));

  /* Gain: '<S1>/Gain2' */
  _rtB->Gain2 = (uint8_T)(_rtB->Compare_g ? ((uint8_T)192U) : 0);

  /* Sum: '<S1>/Add1' */
  _rtB->Add1 = (uint8_T)(((((uint32_T)_rtB->Gain1 << 1) + _rtB->Gain) +
    ((uint32_T)_rtB->Gain2 << 1)) >> 1);

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  switch (_rtB->Add1 >> 6) {
   case 1:
    _rtB->MultiportSwitch[0] = 1.0;
    _rtB->MultiportSwitch[1] = 0.0;
    _rtB->MultiportSwitch[2] = 0.0;
    break;

   case 2:
    _rtB->MultiportSwitch[0] = 0.0;
    _rtB->MultiportSwitch[1] = 1.0;
    _rtB->MultiportSwitch[2] = 0.0;
    break;

   default:
    _rtB->MultiportSwitch[0] = 0.0;
    _rtB->MultiportSwitch[1] = 0.0;
    _rtB->MultiportSwitch[2] = 1.0;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* Product: '<S1>/Product3' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product3 = *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0] *
    _rtB->MultiportSwitch[0];

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/In2'
   */
  _rtB->Compare_h = (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] ==
                     1.0);

  /* Gain: '<S1>/Gain3' */
  _rtB->Gain3 = (uint8_T)(_rtB->Compare_h ? ((uint8_T)128U) : 0);

  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  Inport: '<Root>/In2'
   */
  _rtB->Compare_ns = (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] ==
                      0.0);

  /* Gain: '<S1>/Gain4' */
  _rtB->Gain4 = (uint8_T)(_rtB->Compare_ns ? ((uint8_T)128U) : 0);

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   *  Inport: '<Root>/In2'
   */
  _rtB->Compare_k = (*((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] ==
                     (-1.0));

  /* Gain: '<S1>/Gain5' */
  _rtB->Gain5 = (uint8_T)(_rtB->Compare_k ? ((uint8_T)192U) : 0);

  /* Sum: '<S1>/Add2' */
  _rtB->Add2 = (uint8_T)(((((uint32_T)_rtB->Gain4 << 1) + _rtB->Gain3) +
    ((uint32_T)_rtB->Gain5 << 1)) >> 1);

  /* MultiPortSwitch: '<S1>/Multiport Switch1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  switch (_rtB->Add2 >> 6) {
   case 1:
    _rtB->MultiportSwitch1[0] = 1.0;
    _rtB->MultiportSwitch1[1] = 0.0;
    _rtB->MultiportSwitch1[2] = 0.0;
    break;

   case 2:
    _rtB->MultiportSwitch1[0] = 0.0;
    _rtB->MultiportSwitch1[1] = 1.0;
    _rtB->MultiportSwitch1[2] = 0.0;
    break;

   default:
    _rtB->MultiportSwitch1[0] = 0.0;
    _rtB->MultiportSwitch1[1] = 0.0;
    _rtB->MultiportSwitch1[2] = 1.0;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch1' */

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product1 = _rtB->MultiportSwitch1[0] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[1];

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  Inport: '<Root>/In3'
   */
  _rtB->Compare_p = (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] ==
                     1.0);

  /* Gain: '<S1>/Gain6' */
  _rtB->Gain6 = (uint8_T)(_rtB->Compare_p ? ((uint8_T)128U) : 0);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/In3'
   */
  _rtB->Compare_i = (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] ==
                     0.0);

  /* Gain: '<S1>/Gain7' */
  _rtB->Gain7 = (uint8_T)(_rtB->Compare_i ? ((uint8_T)128U) : 0);

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/In3'
   */
  _rtB->Compare_b = (*((const real_T **)ssGetInputPortSignalPtrs(S, 2))[0] ==
                     (-1.0));

  /* Gain: '<S1>/Gain8' */
  _rtB->Gain8 = (uint8_T)(_rtB->Compare_b ? ((uint8_T)192U) : 0);

  /* Sum: '<S1>/Add3' */
  _rtB->Add3 = (uint8_T)(((((uint32_T)_rtB->Gain7 << 1) + _rtB->Gain6) +
    ((uint32_T)_rtB->Gain8 << 1)) >> 1);

  /* MultiPortSwitch: '<S1>/Multiport Switch2' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  switch (_rtB->Add3 >> 6) {
   case 1:
    _rtB->MultiportSwitch2[0] = 1.0;
    _rtB->MultiportSwitch2[1] = 0.0;
    _rtB->MultiportSwitch2[2] = 0.0;
    break;

   case 2:
    _rtB->MultiportSwitch2[0] = 0.0;
    _rtB->MultiportSwitch2[1] = 1.0;
    _rtB->MultiportSwitch2[2] = 0.0;
    break;

   default:
    _rtB->MultiportSwitch2[0] = 0.0;
    _rtB->MultiportSwitch2[1] = 0.0;
    _rtB->MultiportSwitch2[2] = 1.0;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch2' */

  /* Product: '<S1>/Product2' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product2 = _rtB->MultiportSwitch2[0] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[2];

  /* Sum: '<S1>/Add4' */
  _rtB->Add4 = (_rtB->Product3 + _rtB->Product1) + _rtB->Product2;

  /* Outport: '<Root>/Out1' */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->Add4;

  /* Product: '<S1>/Product4' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product4 = *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0] *
    _rtB->MultiportSwitch[1];

  /* Product: '<S1>/Product6' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product6 = _rtB->MultiportSwitch1[1] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[1];

  /* Product: '<S1>/Product7' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product7 = _rtB->MultiportSwitch2[1] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[2];

  /* Sum: '<S1>/Add5' */
  _rtB->Add5 = (_rtB->Product4 + _rtB->Product6) + _rtB->Product7;

  /* Outport: '<Root>/Out4' */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->Add5;

  /* Product: '<S1>/Product5' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product5 = *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0] *
    _rtB->MultiportSwitch[2];

  /* Product: '<S1>/Product8' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product8 = _rtB->MultiportSwitch1[2] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[1];

  /* Product: '<S1>/Product9' incorporates:
   *  Inport: '<Root>/In4'
   */
  _rtB->Product9 = _rtB->MultiportSwitch2[2] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[2];

  /* Sum: '<S1>/Add6' */
  _rtB->Add6 = (_rtB->Product5 + _rtB->Product8) + _rtB->Product9;

  /* Outport: '<Root>/Out7' */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = _rtB->Add6;
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
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

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "IntermediateDClinkN_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 3))
    return;

  /* outport number: 0 */
  if (!ssSetOutputPortVectorDimension(S, 0, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 0, 1.0E-5);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 1.0E-5);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 2, 1.0E-5);
  ssSetOutputPortOffsetTime(S, 2, 0.0);
  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

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
    ssSetInputPortSampleTime(S, 0, 1.0E-5);
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
    ssSetInputPortSampleTime(S, 1, 1.0E-5);
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
    if (!ssSetInputPortVectorDimension(S, 3, 3))
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
  if (!ssSetNumDWork(S, 1)) {
    return;
  }

  /* '<S1>/Add1': DWORK1 */
  ssSetDWorkName(S, 0, "DWORK0");
  ssSetDWorkWidth(S, 0, 1);
  ssSetDWorkDataType(S, 0, SS_UINT32);

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 0);

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
  ssSetSampleTime(S, 0, 1.0E-5);

  /* task offsets */
  ssSetOffsetTime(S, 0, 0.0);
}

#if defined(MATLAB_MEX_FILE)
# include "fixedpoint.c"
# include "simulink.c"
#else
# undef S_FUNCTION_NAME
# define S_FUNCTION_NAME               IntermediateDClinkN_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
