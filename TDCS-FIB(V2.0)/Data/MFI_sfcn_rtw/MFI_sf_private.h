/*
 * MFI_sf_private.h
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
#ifndef RTW_HEADER_MFI_sf_private_h_
#define RTW_HEADER_MFI_sf_private_h_
#include "rtwtypes.h"
#ifndef RTW_COMMON_DEFINES_
# define RTW_COMMON_DEFINES_
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 }
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers delcare free without const! */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif                                 /* RTW_COMMON_DEFINES_ */

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

/*
 * Tunable Parameters
 *
 * Note: Tunable parameters with Auto storage class are treated as S-Function
 * parameters in the generated S-Function Target.  The generated
 * s-function will declare them as parameters and verify correct data
 * types/sizes are maintained.  The parameters are propagated to nested
 * non-inlined S-Functions
 *
 */
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_MFI_sf)
#define AddMux(S)                      _ssGetSFcnParam(S,0)
#define BearingFP(S)                   _ssGetSFcnParam(S,1)
#define FS(S)                          _ssGetSFcnParam(S,2)
#define FaultInjectionTime(S)          _ssGetSFcnParam(S,3)
#define FaultType(S)                   _ssGetSFcnParam(S,4)
#define NoiseSelec(S)                  _ssGetSFcnParam(S,5)
#define Severity1(S)                   _ssGetSFcnParam(S,6)
#define Severity2(S)                   _ssGetSFcnParam(S,7)
#define Severity3(S)                   _ssGetSFcnParam(S,8)
#endif                                 /* RTW_GENERATED_SFCN_TUNABLE_PRMS_MFI_sf */
#endif                                 /* RTW_HEADER_MFI_sf_private_h_ */
