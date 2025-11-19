/*
 * TFI1_sf_data.c
 *
 * Code generation for model "TFI1_sf".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Wed Apr 06 20:55:06 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "TFI1_sf.h"
#include "TFI1_sf_private.h"

/* Block parameters (auto storage) */
P_TFI1_T TFI1_DefaultP = {
  1.0,                                 /* Variable: AddMux
                                        * Referenced by: '<S3>/Constant2'
                                        */
  23341.0,                             /* Variable: Comp_ConV
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S4>/Constant1'
                                        *   '<S8>/Constant2'
                                        *   '<S8>/Constant3'
                                        *   '<S10>/Constant'
                                        *   '<S11>/Constant'
                                        *   '<S12>/Constant'
                                        *   '<S13>/Constant'
                                        */
  0.1,                                 /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S9>/Constant'
                                        *   '<S9>/Step'
                                        *   '<S16>/Constant'
                                        *   '<S16>/Step'
                                        */
  1.0,                                 /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        */
  1.0,                                 /* Variable: InvertBit
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.0,                                 /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  3.5                                  /* Variable: TH
                                        * Referenced by: '<S5>/Constant'
                                        */
};
