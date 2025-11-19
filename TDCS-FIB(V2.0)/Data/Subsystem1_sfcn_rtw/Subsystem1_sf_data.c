/*
 * Subsystem1_sf_data.c
 *
 * Code generation for model "Subsystem1_sf".
 *
 * Model version              : 1.11
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Tue Jul 04 15:10:17 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Subsystem1_sf.h"
#include "Subsystem1_sf_private.h"

/* Block parameters (auto storage) */
P_Subsystem1_T Subsystem1_DefaultP = {
  1.0,                                 /* Variable: AddMux
                                        * Referenced by: '<S2>/Constant2'
                                        */
  0.0001,                              /* Variable: ContantofPassiveDevice
                                        * Referenced by:
                                        *   '<S2>/FaultCont'
                                        *   '<S3>/ContantofPassiveDevice'
                                        */
  1.0,                                 /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S2>/FaultSelec1'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S4>/Step'
                                        */
  1.0,                                 /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S2>/FaultCont1'
                                        *   '<S2>/FaultSelec1'
                                        *   '<S3>/FaultSelec1'
                                        */
  0.0,                                 /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  0.1                                  /* Variable: PerformanceDegradationValue
                                        * Referenced by: '<S4>/Constant'
                                        */
};
