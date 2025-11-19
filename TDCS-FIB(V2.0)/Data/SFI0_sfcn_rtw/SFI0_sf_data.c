/*
 * SFI0_sf_data.c
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
#include "SFI0_sf.h"
#include "SFI0_sf_private.h"

/* Block parameters (auto storage) */
P_SFI0_T SFI0_DefaultP = {
  1.0,                                 /* Variable: AddMux
                                        * Referenced by: '<S3>/Constant2'
                                        */
  10.0,                                /* Variable: Comp_ConV
                                        * Referenced by: '<S5>/Constant'
                                        */

  /*  Variable: DriftFault
   * Referenced by:
   *   '<S9>/Constant1'
   *   '<S9>/Step'
   */
  { 120.0, 20.0 },
  5.0,                                 /* Variable: FaultCont
                                        * Referenced by:
                                        *   '<S2>/FaultCont'
                                        *   '<S3>/ST_OF_GA_Cont'
                                        */
  0.1,                                 /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S3>/Shock_Fault'
                                        *   '<S9>/Constant'
                                        *   '<S9>/Step'
                                        */
  1.0,                                 /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S8>/FaultType'
                                        */
  0.0,                                 /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  100.0,                               /* Variable: ShockGain
                                        * Referenced by: '<S3>/Shock_Fault'
                                        */
  0.1                                  /* Variable: Variance
                                        * Referenced by: '<S3>/Random Number'
                                        */
};
