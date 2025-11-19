/*
 * MFI_sf_data.c
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
#include "MFI_sf.h"
#include "MFI_sf_private.h"

/* Block parameters (auto storage) */
P_MFI_T MFI_DefaultP = {
  1.0,                                 /* Variable: AddMux
                                        * Referenced by:
                                        *   '<S1>/Constant2'
                                        *   '<S3>/Constant2'
                                        */

  /*  Variable: BearingFP
   * Referenced by:
   *   '<S10>/Constant'
   *   '<S16>/D'
   *   '<S16>/Z'
   *   '<S16>/a'
   *   '<S16>/d'
   *   '<S16>/fr'
   *   '<S17>/D'
   *   '<S17>/Z'
   *   '<S17>/a'
   *   '<S17>/d'
   *   '<S17>/fr'
   *   '<S18>/D'
   *   '<S18>/Z'
   *   '<S18>/a'
   *   '<S18>/d'
   *   '<S18>/fr'
   *   '<S19>/D'
   *   '<S19>/Z'
   *   '<S19>/a'
   *   '<S19>/d'
   *   '<S19>/fr'
   *   '<S20>/D'
   *   '<S20>/Z'
   *   '<S20>/a'
   *   '<S20>/d'
   *   '<S20>/fr'
   *   '<S21>/D'
   *   '<S21>/Z'
   *   '<S21>/a'
   *   '<S21>/d'
   *   '<S21>/fr'
   *   '<S22>/D'
   *   '<S22>/a'
   *   '<S22>/d'
   *   '<S22>/fcage'
   *   '<S22>/fr'
   *   '<S23>/D'
   *   '<S23>/a'
   *   '<S23>/d'
   *   '<S23>/fcage'
   *   '<S23>/fr'
   *   '<S24>/D'
   *   '<S24>/a'
   *   '<S24>/d'
   *   '<S24>/fcage'
   *   '<S24>/fr'
   *   '<S25>/D'
   *   '<S25>/a'
   *   '<S25>/d'
   *   '<S25>/fcage'
   *   '<S25>/fr'
   */
  { 1.0, 8.0, 25.0, 25.0, 65.0, 0.0, 20.0 },

  /*  Variable: FS
   * Referenced by:
   *   '<S8>/2'
   *   '<S8>/4'
   *   '<S8>/5'
   *   '<S8>/6'
   *   '<S9>/2'
   *   '<S9>/4'
   *   '<S9>/5'
   *   '<S9>/6'
   *   '<S11>/2'
   *   '<S11>/4'
   *   '<S11>/5'
   *   '<S11>/6'
   *   '<S12>/2'
   *   '<S12>/4'
   *   '<S12>/5'
   *   '<S12>/6'
   *   '<S16>/7'
   *   '<S17>/7'
   *   '<S18>/7'
   *   '<S19>/7'
   *   '<S20>/7'
   *   '<S21>/7'
   *   '<S22>/7'
   *   '<S23>/7'
   *   '<S24>/7'
   *   '<S25>/7'
   */
  { 128.7, 0.038 },
  0.1,                                 /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S3>/FaultSelec1'
                                        *   '<S3>/Step'
                                        *   '<S5>/Step'
                                        */
  1.0,                                 /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S3>/FaultSelec1'
                                        *   '<S3>/Step'
                                        *   '<S5>/Step'
                                        */
  0.0,                                 /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  0.5,                                 /* Variable: Severity1
                                        * Referenced by: '<S3>/FaultCont1'
                                        */
  0.2,                                 /* Variable: Severity2
                                        * Referenced by: '<S3>/FaultCont2'
                                        */
  0.2                                  /* Variable: Severity3
                                        * Referenced by: '<S3>/FaultCont4'
                                        */
};
