/*
 * CFI10_sf_data.c
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
#include "CFI10_sf.h"
#include "CFI10_sf_private.h"

/* Block parameters (auto storage) */
P_CFI10_T CFI10_DefaultP = {
  1.0,                                 /* Variable: AddMux
                                        * Referenced by: '<S2>/Constant2'
                                        */
  0.0001,                              /* Variable: ContantofPassiveDevice
                                        * Referenced by:
                                        *   '<S2>/FaultCont'
                                        *   '<S3>/ContantofPassiveDevice'
                                        */
  0.1,                                 /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S2>/FaultSelec1'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S6>/Constant'
                                        *   '<S6>/Step'
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
  600.0                                /* Variable: PerformanceDegradationValue
                                        * Referenced by: '<S6>/Step'
                                        */
};
