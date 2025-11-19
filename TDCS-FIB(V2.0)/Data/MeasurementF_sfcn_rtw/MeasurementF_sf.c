/*
 * MeasurementF_sf.c
 *
 * Code generation for model "MeasurementF_sf".
 *
 * Model version              : 1.160
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Fri Jul 21 16:18:47 2017
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
#include "MeasurementF_sf.h"
#include "MeasurementF_sf_private.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)

extern void *MeasurementF_malloc(SimStruct *S);

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

/* Initial conditions for root system: '<Root>' */
#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  X_MeasurementF_T *_rtX;
  _rtX = ((X_MeasurementF_T *) ssGetContStates(S));

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  _rtX->Integrator_CSTATE = 0.0;
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

  MeasurementF_malloc(S);
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
  real_T A;
  real_T B;
  B_MeasurementF_T *_rtB;
  X_MeasurementF_T *_rtX;
  _rtX = ((X_MeasurementF_T *) ssGetContStates(S));
  _rtB = ((B_MeasurementF_T *) ssGetLocalBlockIO(S));
  if (ssIsContinuousTask(S, tid)) {
    /* Integrator: '<S1>/Integrator' */
    _rtB->Integrator = _rtX->Integrator_CSTATE;

    /* Product: '<S1>/Product1' incorporates:
     *  Inport: '<Root>/ir¦Â'
     *  Inport: '<Root>/is¦Á'
     */
    _rtB->Product1 = *((const real_T **)ssGetInputPortSignalPtrs(S, 0))[0] * *((
      const real_T **)ssGetInputPortSignalPtrs(S, 3))[0];

    /* Product: '<S1>/Product2' incorporates:
     *  Inport: '<Root>/ir¦Á'
     *  Inport: '<Root>/is¦Â'
     */
    _rtB->Product2 = *((const real_T **)ssGetInputPortSignalPtrs(S, 1))[0] * *((
      const real_T **)ssGetInputPortSignalPtrs(S, 2))[0];

    /* Sum: '<S1>/Sum1' */
    _rtB->Sum1 = _rtB->Product2 - _rtB->Product1;

    /* Gain: '<S1>/Np.Lm' */
    A = (*(real_T *)(mxGetData(np(S)))) * (*(real_T *)(mxGetData(Lm(S))));
    _rtB->NpLm = A * _rtB->Sum1;

    /* Fcn: '<S2>/Fcn' incorporates:
     *  Inport: '<Root>/is¦Á'
     */
    _rtB->Fcn = 0.816496580927726 * *((const real_T **)ssGetInputPortSignalPtrs
      (S, 0))[0];

    /* Fcn: '<S2>/Fcn1' incorporates:
     *  Inport: '<Root>/is¦Á'
     *  Inport: '<Root>/is¦Â'
     */
    _rtB->Fcn1 = -0.408248290463863 * *((const real_T **)
      ssGetInputPortSignalPtrs(S, 0))[0] + 0.70710678118654757 * *((const real_T
      **)ssGetInputPortSignalPtrs(S, 1))[0];

    /* Fcn: '<S2>/Fcn2' incorporates:
     *  Inport: '<Root>/is¦Á'
     *  Inport: '<Root>/is¦Â'
     */
    _rtB->Fcn2 = -0.408248290463863 * *((const real_T **)
      ssGetInputPortSignalPtrs(S, 0))[0] - 0.70710678118654757 * *((const real_T
      **)ssGetInputPortSignalPtrs(S, 1))[0];

    /* Sum: '<S1>/Add1' incorporates:
     *  Inport: '<Root>/TL'
     */
    _rtB->Add1 = _rtB->NpLm - *((const real_T **)ssGetInputPortSignalPtrs(S, 4))
      [0];
  }

  if (ssIsSampleHit(S, 1, tid)) {
    /* Constant: '<S1>/machine' */
    A = (*(real_T *)(mxGetData(np(S))));
    B = (*(real_T *)(mxGetData(J(S))));
    _rtB->machine = A / B;
  }

  if (ssIsContinuousTask(S, tid)) {
    /* Product: '<S1>/Product' */
    _rtB->Product = _rtB->machine * _rtB->Add1;

    /* Outport: '<Root>/Te' */
    ((real_T *)ssGetOutputPortSignal(S, 0))[0] = _rtB->NpLm;

    /* Outport: '<Root>/¦Ø' */
    ((real_T *)ssGetOutputPortSignal(S, 1))[0] = _rtB->Integrator;

    /* Outport: '<Root>/Isabc' */
    ((real_T *)ssGetOutputPortSignal(S, 2))[0] = _rtB->Fcn;
    ((real_T *)ssGetOutputPortSignal(S, 2))[1] = _rtB->Fcn1;
    ((real_T *)ssGetOutputPortSignal(S, 2))[2] = _rtB->Fcn2;
  }

  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
#define MDL_DERIVATIVES

static void mdlDerivatives(SimStruct *S)
{
  B_MeasurementF_T *_rtB;
  XDot_MeasurementF_T *_rtXdot;
  _rtXdot = ((XDot_MeasurementF_T *) ssGetdX(S));
  _rtB = ((B_MeasurementF_T *) ssGetLocalBlockIO(S));

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = _rtB->Product;
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
  /* Parameter check for 'J' */
  if (mxIsComplex(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'J' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 0))) {
    ssSetErrorStatus(S,"Parameter 'J' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 0)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 0))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'J' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'Lm' */
  if (mxIsComplex(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'Lm' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 1))) {
    ssSetErrorStatus(S,"Parameter 'Lm' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 1)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 1))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'Lm' has to be a [1x1] array.");
    return;
  }

  /* Parameter check for 'np' */
  if (mxIsComplex(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'np' has to be a non complex array.");
    return;
  }

  if (!mxIsDouble(ssGetSFcnParam(S, 2))) {
    ssSetErrorStatus(S,"Parameter 'np' has to be a double array.");
    return;
  }

  if ((mxGetNumberOfDimensions(ssGetSFcnParam(S, 2)) != 2) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[0] != 1) ||
      (mxGetDimensions(ssGetSFcnParam(S, 2))[1] != 1) ) {
    ssSetErrorStatus(S,"Parameter 'np' has to be a [1x1] array.");
    return;
  }
}

#endif                                 /* MDL_CHECK_PARAMETERS */

#if defined(RT_MALLOC) || defined(MATLAB_MEX_FILE)
#  include "MeasurementF_mid.h"
#endif

/* Function to initialize sizes. */
static void mdlInitializeSizes(SimStruct *S)
{
  ssSetNumSampleTimes(S, 2);           /* Number of sample times */
  ssSetNumContStates(S, 1);            /* Number of continuous states */
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

  ssSetOutputPortSampleTime(S, 0, 0.0);
  ssSetOutputPortOffsetTime(S, 0, 0.0);
  ssSetOutputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);

  /* outport number: 1 */
  if (!ssSetOutputPortVectorDimension(S, 1, 1))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 1, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 1, 0.0);
  ssSetOutputPortOffsetTime(S, 1, 0.0);
  ssSetOutputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);

  /* outport number: 2 */
  if (!ssSetOutputPortVectorDimension(S, 2, 3))
    return;
  if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY) {
    ssSetOutputPortDataType(S, 2, SS_DOUBLE);
  }

  ssSetOutputPortSampleTime(S, 2, 0.0);
  ssSetOutputPortOffsetTime(S, 2, 0.0);
  ssSetOutputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

  /* Number of input ports */
  if (!ssSetNumInputPorts(S, 5))
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
    ssSetInputPortSampleTime(S, 3, 0.0);
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
    ssSetInputPortSampleTime(S, 4, 0.0);
    ssSetInputPortOffsetTime(S, 4, 0.0);
    ssSetInputPortOverWritable(S, 4, 0);
    ssSetInputPortOptimOpts(S, 4, SS_NOT_REUSABLE_AND_GLOBAL);
  }

  ssSetRTWGeneratedSFcn(S, 1);         /* Generated S-function */

  /* Tunable Parameters */
  ssSetNumSFcnParams(S, 3);

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
# define S_FUNCTION_NAME               MeasurementF_sf
# include "cg_sfun.h"
#endif                                 /* defined(MATLAB_MEX_FILE) */
