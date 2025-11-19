/*
 * CFI10_sf.c
 *
 * Code generation for model "CFI10_sf".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Apr 08 09:38:52 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "CFI10_sf.h"
#include "CFI10_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *CFI10_malloc(SimStruct *S);

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

  CFI10_malloc(S);
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
  real_T u;
  B_CFI10_T *_rtB;
  _rtB = ((B_CFI10_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S2>/FaultCont1' */
    _rtB->FaultCont1 = (*(real_T *)(mxGetData(FaultType(S))));

    /* Constant: '<S2>/FaultCont' */
    _rtB->FaultCont = (*(real_T *)(mxGetData(ContantofPassiveDevice(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S6>/Step' */
    currentTime = ssGetTaskTime(S,0);
    if (currentTime < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->Step = 0.0;
    } else {
      _rtB->Step = (*(real_T *)(mxGetData(PerformanceDegradationValue(S))));
    }

    /* End of Step: '<S6>/Step' */

    /* Clock: '<S6>/Clock' */
    ((B_CFI10_T *) ssGetLocalBlockIO(S))->Clock = ssGetT(S);
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S6>/Constant' */
    _rtB->Constant = (*(real_T *)(mxGetData(FaultInjectionTime(S))));
  }

  if (ssIsContinuousTask(S, tid)) {
    /* MultiPortSwitch: '<S2>/Multiport Switch' incorporates:
     *  Inport: '<Root>/Inport1'
     *  Inport: '<Root>/Outside Signal1'
     */
    switch ((int32_T)_rtB->FaultCont1) {
     case 2:
      _rtB->MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 2))
        [0];
      break;

     case 3:
      _rtB->MultiportSwitch = _rtB->FaultCont;
      break;

     case 4:
      /* Sum: '<S6>/Sum' */
      _rtB->Sum = _rtB->Clock - _rtB->Constant;

      /* Product: '<S6>/Product' */
      _rtB->Product = _rtB->Step * _rtB->Sum;

      /* Sum: '<S6>/Output' incorporates:
       *  Constant: '<S6>/Constant1'
       */
      _rtB->Output = _rtB->Product + 1.0;
      _rtB->MultiportSwitch = _rtB->Output;
      break;

     default:
      _rtB->MultiportSwitch = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))
        [0];
      break;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport Switch' */

    /* Sum: '<S1>/Add' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    _rtB->Add = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] +
      _rtB->MultiportSwitch;
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S3>/ContantofPassiveDevice' */
    _rtB->ContantofPassiveDevice = (*(real_T *)(mxGetData(ContantofPassiveDevice
                                      (S))));
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
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Logic: '<S2>/Logical' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    currentTime = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
    _rtB->Logical = !(currentTime != 0.0);
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Step: '<S2>/FaultSelec1' */
    currentTime = ssGetTaskTime(S,0);
    if (currentTime < (*(real_T *)(mxGetData(FaultInjectionTime(S))))) {
      _rtB->FaultSelec1_n = 1.0;
    } else {
      _rtB->FaultSelec1_n = (*(real_T *)(mxGetData(FaultType(S))));
    }

    /* End of Step: '<S2>/FaultSelec1' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* RelationalOperator: '<S5>/Compare' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Constant: '<S5>/Constant'
     */
    currentTime = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
    _rtB->Compare = (currentTime == 2.0);

    /* MultiPortSwitch: '<S2>/Multiport1' incorporates:
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant4'
     */
    if (_rtB->Compare == 0) {
      _rtB->Multiport1 = 5.0;
    } else {
      _rtB->Multiport1 = 6.0;
    }

    /* End of MultiPortSwitch: '<S2>/Multiport1' */
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Sum: '<S1>/Add1' incorporates:
     *  Inport: '<Root>/Nomal'
     */
    _rtB->Add1 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] +
      _rtB->MultiportSwitch;

    /* MultiPortSwitch: '<S3>/Multiport Switch1' */
    switch ((int32_T)_rtB->FaultSelec1) {
     case 1:
     case 2:
     case 4:
     case 5:
      /* RelationalOperator: '<S4>/Compare' incorporates:
       *  Constant: '<S4>/Constant'
       */
      _rtB->Compare_o = (_rtB->FaultSelec1_n == 5.0);

      /* Logic: '<S2>/Logical ' */
      _rtB->Logical_p = (_rtB->Logical && _rtB->Compare_o);

      /* MultiPortSwitch: '<S2>/Multiport Switch2' incorporates:
       *  Constant: '<S2>/Constant3'
       */
      if (_rtB->Logical_p == 0) {
        /* Logic: '<S2>/Logical Operator' incorporates:
         *  Constant: '<S2>/Constant2'
         */
        currentTime = (*(real_T *)(mxGetData(AddMux(S)))) - 1.0;
        _rtB->LogicalOperator = ((currentTime != 0.0) && _rtB->Compare_o);

        /* MultiPortSwitch: '<S2>/Multiport' */
        if (_rtB->LogicalOperator == 0) {
          _rtB->Multiport = _rtB->FaultSelec1_n;
        } else {
          _rtB->Multiport = _rtB->Multiport1;
        }

        /* End of MultiPortSwitch: '<S2>/Multiport' */
        _rtB->MultiportSwitch2 = _rtB->Multiport;
      } else {
        _rtB->MultiportSwitch2 = 2.0;
      }

      /* End of MultiPortSwitch: '<S2>/Multiport Switch2' */

      /* MultiPortSwitch: '<S2>/Multiport Switch3' incorporates:
       *  Constant: '<S2>/1'
       *  Constant: '<S2>/2'
       *  Constant: '<S2>/3'
       *  Constant: '<S2>/5'
       */
      switch ((int32_T)_rtB->MultiportSwitch2) {
       case 2:
       case 4:
        _rtB->MultiportSwitch3 = 1.0;
        break;

       case 1:
        _rtB->MultiportSwitch3 = 5.0;
        break;

       case 5:
        _rtB->MultiportSwitch3 = 3.0;
        break;

       default:
        _rtB->MultiportSwitch3 = 6.0;
        break;
      }

      /* End of MultiPortSwitch: '<S2>/Multiport Switch3' */

      /* MultiPortSwitch: '<S3>/Multiport Switch2' incorporates:
       *  Inport: '<Root>/Nomal'
       */
      switch ((int32_T)_rtB->MultiportSwitch3) {
       case 1:
        _rtB->MultiportSwitch2_d = _rtB->Add;
        break;

       case 2:
        /* Saturate: '<S7>/Saturation' */
        currentTime = _rtB->Add;
        u = 0.0;
        if ((currentTime >= u) || rtIsNaN(u)) {
          _rtB->Saturation = currentTime;
        } else {
          _rtB->Saturation = u;
        }

        /* End of Saturate: '<S7>/Saturation' */
        _rtB->MultiportSwitch2_d = _rtB->Saturation;
        break;

       case 3:
        _rtB->MultiportSwitch2_d = _rtB->Add1;
        break;

       case 4:
        _rtB->MultiportSwitch2_d = _rtB->Add1;
        break;

       case 5:
        _rtB->MultiportSwitch2_d = *((const real_T **)ssGetInputPortSignalPtrs(S,
          0))[0];
        break;

       default:
        _rtB->MultiportSwitch2_d = _rtB->MultiportSwitch;
        break;
      }

      /* End of MultiPortSwitch: '<S3>/Multiport Switch2' */
      _rtB->MultiportSwitch1 = _rtB->MultiportSwitch2_d;
      break;

     default:
      _rtB->MultiportSwitch1 = _rtB->ContantofPassiveDevice;
      break;
    }

    /* End of MultiPortSwitch: '<S3>/Multiport Switch1' */
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/Noise0'
     *  Constant: '<S1>/NoiseSelec'
     *  Inport: '<Root>/Inport2'
     */
    if ((*(real_T *)(mxGetData(NoiseSelec(S)))) != 0.0) {
      _rtB->Switch = *((const real_T **)ssGetInputPortSignalPtrs(S, 3))[0];
    } else {
      _rtB->Switch = 0.0;
    }

    /* End of Switch: '<S1>/Switch' */
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Sum: '<S1>/NoiseAdd' */
    _rtB->NoiseAdd = _rtB->Switch + _rtB->MultiportSwitch1;

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

  /* Parameter check for 'ContantofPassiveDevice' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'ContantofPassiveDevice' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,
                     "Parameter 'ContantofPassiveDevice' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'ContantofPassiveDevice' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'FaultInjectionTime' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,
                     "Parameter 'FaultInjectionTime' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultInjectionTime' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'FaultType' */
  if (mxIsComplex(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 3))) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 3)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 3))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'FaultType' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'NoiseSelec' */
  if (mxIsComplex(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 4))) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 4)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 4))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'NoiseSelec' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'PerformanceDegradationValue' */
  if (mxIsComplex(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'PerformanceDegradationValue' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 5))) {
    ssSetErrorStatus(S,
                     "Parameter 'PerformanceDegradationValue' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 5)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 5))[1] != 1) ) {
    ssSetErrorStatus(S,
                     "Parameter 'PerformanceDegradationValue' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "CFI10_mid.h"
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
    ssSetInputPortSampleTime(S, 2, 0.0);
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

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 6);

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
# define S_FUNCTION_NAME               CFI10_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
