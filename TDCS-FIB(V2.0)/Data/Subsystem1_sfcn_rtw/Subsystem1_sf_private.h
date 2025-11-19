/*
 * Subsystem1_sf_private.h
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
#ifndef RTW_HEADER_Subsystem1_sf_private_h_
#define RTW_HEADER_Subsystem1_sf_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
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
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_Subsystem1_sf)
#define AddMux(S)                      _ssGetSFcnParam(S,0)
#define ContantofPassiveDevice(S)      _ssGetSFcnParam(S,1)
#define FaultInjectionTime(S)          _ssGetSFcnParam(S,2)
#define FaultType(S)                   _ssGetSFcnParam(S,3)
#define NoiseSelec(S)                  _ssGetSFcnParam(S,4)
#define PerformanceDegradationValue(S) _ssGetSFcnParam(S,5)
#endif                                 /* RTW_GENERATED_SFCN_TUNABLE_PRMS_Subsystem1_sf */
#endif                                 /* RTW_HEADER_Subsystem1_sf_private_h_ */
