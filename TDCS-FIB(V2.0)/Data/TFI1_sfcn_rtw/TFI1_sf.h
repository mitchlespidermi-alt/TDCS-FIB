/*
 * TFI1_sf.h
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
#ifndef RTW_HEADER_TFI1_sf_h_
#define RTW_HEADER_TFI1_sf_h_
#ifndef TFI1_sf_COMMON_INCLUDES_
# define TFI1_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#define S_FUNCTION_NAME                TFI1_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* TFI1_sf_COMMON_INCLUDES_ */

#include "TFI1_sf_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Constant;                     /* '<S11>/Constant' */
  real_T FaultSelec;                   /* '<S3>/FaultSelec' */
  real_T Step;                         /* '<S16>/Step' */
  real_T Clock;                        /* '<S16>/Clock' */
  real_T Constant_h;                   /* '<S16>/Constant' */
  real_T MultiportSwitch;              /* '<S3>/Multiport Switch' */
  real_T Add;                          /* '<S1>/Add' */
  real_T Constant_hf;                  /* '<S4>/Constant' */
  real_T Constant_g;                   /* '<S10>/Constant' */
  real_T Constant1;                    /* '<S4>/Constant1' */
  real_T Constant_n;                   /* '<S13>/Constant' */
  real_T Product;                      /* '<S1>/Product' */
  real_T Constant2;                    /* '<S8>/Constant2' */
  real_T Constant_b;                   /* '<S12>/Constant' */
  real_T Constant3;                    /* '<S8>/Constant3' */
  real_T FaultSelec1;                  /* '<S3>/FaultSelec1' */
  real_T Multiport1;                   /* '<S3>/Multiport1' */
  real_T Multiport;                    /* '<S3>/Multiport  ' */
  real_T MultiportSwitch1;             /* '<S3>/Multiport Switch1' */
  real_T MultiportSwitch2;             /* '<S2>/Multiport Switch2' */
  real_T Step_f;                       /* '<S9>/Step' */
  real_T Clock_l;                      /* '<S9>/Clock' */
  real_T Constant_p;                   /* '<S9>/Constant' */
  real_T Constant_ha;                  /* '<S5>/Constant' */
  real_T Add1;                         /* '<S2>/Add1' */
  real_T FaultSelec_a;                 /* '<S2>/FaultSelec' */
  real_T MultiportSwitch3;             /* '<S2>/Multiport Switch3' */
  real_T MultiportSwitch1_i;           /* '<S2>/Multiport Switch1' */
  real_T Switch;                       /* '<S1>/Switch' */
  real_T NoiseAdd;                     /* '<S1>/NoiseAdd' */
  real_T Sum;                          /* '<S16>/Sum' */
  real_T Product_c;                    /* '<S16>/Product' */
  real_T Output;                       /* '<S16>/Output' */
  real_T Fcn;                          /* '<S3>/Fcn' */
  real_T Multiport_g;                  /* '<S3>/Multiport' */
  real_T y;                            /* '<S2>/MATLAB Function1' */
  real_T y_b;                          /* '<S2>/MATLAB Function' */
  real_T Sum_n;                        /* '<S9>/Sum' */
  real_T Product_k;                    /* '<S9>/Product' */
  real_T Output_j;                     /* '<S9>/Output' */
  real_T Fcn_b;                        /* '<S2>/Fcn' */
  real_T MultiportSwitch_d;            /* '<S2>/Multiport Switch' */
  real_T Switch_k;                     /* '<S4>/Switch' */
  real_T Switch2;                      /* '<S4>/Switch2' */
  real_T Switch3;                      /* '<S8>/Switch3' */
  real_T Switch4;                      /* '<S8>/Switch4' */
  boolean_T Logical;                   /* '<S3>/Logical' */
  boolean_T Compare;                   /* '<S14>/Compare' */
  boolean_T Logical_b;                 /* '<S3>/Logical ' */
  boolean_T Compare_n;                 /* '<S15>/Compare' */
  boolean_T LogicalOperator;           /* '<S3>/Logical Operator' */
  boolean_T Compare_o;                 /* '<S5>/Compare' */
  boolean_T Compare_k;                 /* '<S11>/Compare' */
  boolean_T Compare_a;                 /* '<S10>/Compare' */
  boolean_T Compare_b;                 /* '<S13>/Compare' */
  boolean_T Compare_j;                 /* '<S12>/Compare' */
} B_TFI1_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Nomal;                       /* '<Root>/Nomal' */
  real_T *OutsideSignal;               /* '<Root>/Outside Signal' */
  real_T *Inport1;                     /* '<Root>/Inport1' */
  real_T *Inport2;                     /* '<Root>/Inport2' */
} ExternalUPtrs_TFI1_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out;                         /* '<Root>/Out' */
  real_T *Outport3;                    /* '<Root>/Outport3' */
} ExtY_TFI1_T;

/* Parameters (auto storage) */
struct P_TFI1_T_ {
  real_T AddMux;                       /* Variable: AddMux
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Comp_ConV;                    /* Variable: Comp_ConV
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
  real_T FaultInjectionTime;           /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        *   '<S9>/Constant'
                                        *   '<S9>/Step'
                                        *   '<S16>/Constant'
                                        *   '<S16>/Step'
                                        */
  real_T FaultType;                    /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S2>/FaultSelec'
                                        *   '<S3>/FaultSelec'
                                        *   '<S3>/FaultSelec1'
                                        */
  real_T InvertBit;                    /* Variable: InvertBit
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T NoiseSelec;                   /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  real_T TH;                           /* Variable: TH
                                        * Referenced by: '<S5>/Constant'
                                        */
};

extern P_TFI1_T TFI1_DefaultP;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('TFI/TFI1')    - opens subsystem TFI/TFI1
 * hilite_system('TFI/TFI1/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TFI'
 * '<S1>'   : 'TFI/TFI1'
 * '<S2>'   : 'TFI/TFI1/Logic Operation'
 * '<S3>'   : 'TFI/TFI1/TFI'
 * '<S4>'   : 'TFI/TFI1/Logic Operation/AddComp'
 * '<S5>'   : 'TFI/TFI1/Logic Operation/Compare To Constant'
 * '<S6>'   : 'TFI/TFI1/Logic Operation/MATLAB Function'
 * '<S7>'   : 'TFI/TFI1/Logic Operation/MATLAB Function1'
 * '<S8>'   : 'TFI/TFI1/Logic Operation/MuxComp'
 * '<S9>'   : 'TFI/TFI1/Logic Operation/Ramp'
 * '<S10>'  : 'TFI/TFI1/Logic Operation/AddComp/Max'
 * '<S11>'  : 'TFI/TFI1/Logic Operation/AddComp/Min'
 * '<S12>'  : 'TFI/TFI1/Logic Operation/MuxComp/Max1'
 * '<S13>'  : 'TFI/TFI1/Logic Operation/MuxComp/Min1'
 * '<S14>'  : 'TFI/TFI1/TFI/Compare To Constant'
 * '<S15>'  : 'TFI/TFI1/TFI/Compare To Constant1'
 * '<S16>'  : 'TFI/TFI1/TFI/Ramp'
 */
#endif                                 /* RTW_HEADER_TFI1_sf_h_ */
