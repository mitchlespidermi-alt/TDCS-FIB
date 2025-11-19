/*
 * InverterTwN_sf.c
 *
 * Code generation for model "InverterTwN_sf".
 *
 * Model version              : 1.162
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:24:58 2017
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
#include "InverterTwN_sf.h"
#include "InverterTwN_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *InverterTwN_malloc(SimStruct *S);

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

  InverterTwN_malloc(S);
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
  int32_T bitIdx;
  int32_T i;
  uint32_T intVal;
  uint32_T u;
  B_InverterTwN_T *_rtB;
  _rtB = ((B_InverterTwN_T *) ssGetLocalBlockIO(S));

  /* RelationalOperator: '<S2>/Relational Operator7' incorporates:
   *  Constant: '<S2>/Constant13'
   *  Inport: '<Root>/Ic'
   */
  _rtB->RelationalOperator7 = (*((const real_T **)ssGetInputPortSignalPtrs(S, 4))
    [0] >= 0.0);

  /* SignalConversion: '<S2>/TmpSignal ConversionAtBit to Integer ConverterInport1' incorporates:
   *  Inport: '<Root>/Tw1'
   *  Inport: '<Root>/Tw2'
   *  Inport: '<Root>/Tw3'
   *  Inport: '<Root>/Tw4'
   */
  _rtB->TmpSignalConversionAtBittoInteg[0] = *((const real_T **)
    ssGetInputPortSignalPtrs(S, 0))[0];
  _rtB->TmpSignalConversionAtBittoInteg[1] = *((const real_T **)
    ssGetInputPortSignalPtrs(S, 1))[0];
  _rtB->TmpSignalConversionAtBittoInteg[2] = *((const real_T **)
    ssGetInputPortSignalPtrs(S, 2))[0];
  _rtB->TmpSignalConversionAtBittoInteg[3] = *((const real_T **)
    ssGetInputPortSignalPtrs(S, 3))[0];

  /* S-Function (scominttobit): '<S2>/Bit to Integer Converter' */
  /* Bit to Integer Conversion */
  bitIdx = 0;
  i = 0;
  while (i < 1) {
    u = (uint32_T)_rtB->TmpSignalConversionAtBittoInteg[bitIdx];

    /* Input bit order is MSB first */
    intVal = u;
    bitIdx++;
    u = (uint32_T)_rtB->TmpSignalConversionAtBittoInteg[bitIdx];

    /* Input bit order is MSB first */
    intVal <<= 1U;
    intVal |= u;
    bitIdx++;
    u = (uint32_T)_rtB->TmpSignalConversionAtBittoInteg[bitIdx];

    /* Input bit order is MSB first */
    intVal <<= 1U;
    intVal |= u;
    bitIdx++;
    u = (uint32_T)_rtB->TmpSignalConversionAtBittoInteg[bitIdx];

    /* Input bit order is MSB first */
    intVal <<= 1U;
    intVal |= u;
    bitIdx++;
    _rtB->BittoIntegerConverter = intVal;
    i = 1;
  }

  /* End of S-Function (scominttobit): '<S2>/Bit to Integer Converter' */

  /* RelationalOperator: '<S2>/Relational Operator4' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  _rtB->RelationalOperator4 = (_rtB->BittoIntegerConverter == 6.0);

  /* RelationalOperator: '<S2>/Relational Operator5' incorporates:
   *  Constant: '<S2>/Constant5'
   */
  _rtB->RelationalOperator5 = (_rtB->BittoIntegerConverter == 2.0);

  /* Logic: '<S2>/Logical Operator1' */
  _rtB->LogicalOperator1 = (_rtB->RelationalOperator4 ||
    _rtB->RelationalOperator5);

  /* MultiPortSwitch: '<S2>/Multiport Switch1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  if (_rtB->LogicalOperator1 == 0) {
    /* RelationalOperator: '<S2>/Relational Operator6' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    _rtB->RelationalOperator6 = (_rtB->BittoIntegerConverter == 3.0);

    /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S2>/Constant3'
     */
    if (_rtB->RelationalOperator6 == 0) {
      _rtB->MultiportSwitch2 = 1.0;
    } else {
      _rtB->MultiportSwitch2 = (-1.0);
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */
    _rtB->MultiportSwitch1 = _rtB->MultiportSwitch2;
  } else {
    _rtB->MultiportSwitch1 = 0.0;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch1' */

  /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
   *  Constant: '<S2>/Constant10'
   */
  _rtB->RelationalOperator1 = (_rtB->BittoIntegerConverter == 6.0);

  /* RelationalOperator: '<S2>/Relational Operator2' incorporates:
   *  Constant: '<S2>/Constant11'
   */
  _rtB->RelationalOperator2 = (_rtB->BittoIntegerConverter == 4.0);

  /* Logic: '<S2>/Logical Operator2' */
  _rtB->LogicalOperator2 = (_rtB->RelationalOperator1 ||
    _rtB->RelationalOperator2);

  /* MultiPortSwitch: '<S2>/Multiport Switch3' incorporates:
   *  Constant: '<S2>/Constant7'
   */
  if (_rtB->LogicalOperator2 == 0) {
    /* RelationalOperator: '<S2>/Relational Operator3' incorporates:
     *  Constant: '<S2>/Constant12'
     */
    _rtB->RelationalOperator3 = (_rtB->BittoIntegerConverter == 12.0);

    /* MultiPortSwitch: '<S2>/Multiport Switch4' incorporates:
     *  Constant: '<S2>/Constant8'
     *  Constant: '<S2>/Constant9'
     */
    if (_rtB->RelationalOperator3 == 0) {
      _rtB->MultiportSwitch4 = (-1.0);
    } else {
      _rtB->MultiportSwitch4 = 1.0;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch4' */
    _rtB->MultiportSwitch3 = _rtB->MultiportSwitch4;
  } else {
    _rtB->MultiportSwitch3 = 0.0;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch3' */

  /* MultiPortSwitch: '<S2>/Multiport Switch5' */
  if (_rtB->RelationalOperator7 == 0) {
    _rtB->MultiportSwitch5 = _rtB->MultiportSwitch1;
  } else {
    _rtB->MultiportSwitch5 = _rtB->MultiportSwitch3;
  }

  /* End of MultiPortSwitch: '<S2>/Multiport Switch5' */

  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant'
   */
  _rtB->Add = _rtB->MultiportSwitch5 + 1.0;

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  switch ((int32_T)_rtB->Add) {
   case 0:
    _rtB->MultiportSwitch[0] = 0.0;
    _rtB->MultiportSwitch[1] = 0.0;
    _rtB->MultiportSwitch[2] = 1.0;
    break;

   case 1:
    _rtB->MultiportSwitch[0] = 0.0;
    _rtB->MultiportSwitch[1] = 1.0;
    _rtB->MultiportSwitch[2] = 0.0;
    break;

   default:
    _rtB->MultiportSwitch[0] = 1.0;
    _rtB->MultiportSwitch[1] = 0.0;
    _rtB->MultiportSwitch[2] = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* Product: '<S1>/Product' incorporates:
   *  Inport: '<Root>/Ic'
   */
  _rtB->Product = _rtB->MultiportSwitch[0] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 4))[0];

  /* Product: '<S1>/Product2' incorporates:
   *  Inport: '<Root>/Ic'
   */
  _rtB->Product2 = _rtB->MultiportSwitch[2] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 4))[0];

  /* Product: '<S1>/Product1' incorporates:
   *  Inport: '<Root>/Ic'
   */
  _rtB->Product1 = _rtB->MultiportSwitch[1] * *((const real_T **)
    ssGetInputPortSignalPtrs(S, 4))[0];

  /* Sum: '<S1>/Add1' incorporates:
   *  Inport: '<Root>/U1'
   *  Inport: '<Root>/U2'
   */
  _rtB->Add1 = *((const real_T **)ssGetInputPortSignalPtrs(S, 5))[0] + *((const
    real_T **)ssGetInputPortSignalPtrs(S, 6))[0];

  /* Product: '<S1>/Product3' */
  _rtB->Product3 = _rtB->Add1 * _rtB->MultiportSwitch5;

  /* Gain: '<S1>/Gain' */
  _rtB->Gain = 0.5 * _rtB->Product3;

  /* Outport: '<Root>/Iu' */
  ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->Product;

  /* Outport: '<Root>/Iz' */
  ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->Product1;

  /* Outport: '<Root>/Id' */
  ((real_T *)ssGetOutputPortSignal(S, 2))[0] = _rtB->Product2;

  /* Outport: '<Root>/Vw' */
  ((real_T *)ssGetOutputPortSignal(S, 3))[0] = _rtB->Gain;
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
#  include "InverterTwN_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 1);           /* Number of sample times */
  ssSetNumContStates(S, 0);            /* Number of continuous states */
  ssSetNumNonsampledZCs(S, 0);         /* Number of nonsampled ZCs */

  /* Number of output ports */
  if (!ssSetNumOutputPorts(S, 4))
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

  /* outport number: 3 */
  if (!ssSetOutputPortVectorDimension(S, 3, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 3, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 3, 1.0E-5);
  ssSetOutputPortOffsetTime(S, 3, 0.0);
  ssSetOutputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 7))
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

  /* inport number: 4 */
  {
    if (!ssSetInputPortVectorDimension(S, 4, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 4, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 4, 1);
    ssSetInputPortSampleTime(S, 4, 1.0E-5);
    ssSetInputPortOffsetTime(S, 4, 0.0);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 5 */
  {
    if (!ssSetInputPortVectorDimension(S, 5, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 5, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 5, 1);
    ssSetInputPortSampleTime(S, 5, 1.0E-5);
    ssSetInputPortOffsetTime(S, 5, 0.0);
    ssSetInputPortOverWritable(S, 5, 0);
    ssSetInputPortOptimOpts(S, 5, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  /* inport number: 6 */
  {
    if (!ssSetInputPortVectorDimension(S, 6, 1))
      return;
    if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
      ssSetInputPortDataType(S, 6, SS_DOUBLE);
    }

    ssSetInputPortDirectFeedThrough(S, 6, 1);
    ssSetInputPortSampleTime(S, 6, 1.0E-5);
    ssSetInputPortOffsetTime(S, 6, 0.0);
    ssSetInputPortOverWritable(S, 6, 0);
    ssSetInputPortOptimOpts(S, 6, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

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
# define S_FUNCTION_NAME               InverterTwN_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
