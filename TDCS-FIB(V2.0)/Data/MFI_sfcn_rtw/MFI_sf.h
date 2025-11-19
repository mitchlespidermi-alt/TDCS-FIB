/*
 * MFI_sf.h
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
#ifndef RTW_HEADER_MFI_sf_h_
#define RTW_HEADER_MFI_sf_h_
#ifndef MFI_sf_COMMON_INCLUDES_
# define MFI_sf_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#define S_FUNCTION_NAME                MFI_sf
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
#endif                                 /* MFI_sf_COMMON_INCLUDES_ */

#include "MFI_sf_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Switch;                       /* '<S1>/Switch' */
  real_T FaultSelec1;                  /* '<S3>/FaultSelec1' */
  real_T Multiport1;                   /* '<S3>/Multiport1' */
  real_T MultiportSwitch2;             /* '<S3>/Multiport Switch2' */
  real_T MultiportSwitch3;             /* '<S3>/Multiport Switch3' */
  real_T Step;                         /* '<S5>/Step' */
  real_T Clock;                        /* '<S9>/Clock' */
  real_T u;                            /* '<S9>/2' */
  real_T u_p;                          /* '<S9>/5' */
  real_T Step_j;                       /* '<S4>/Step' */
  real_T MultiportSwitch;              /* '<S4>/Multiport Switch' */
  real_T MinMax;                       /* '<S4>/MinMax' */
  real_T Step_h;                       /* '<S3>/Step' */
  real_T FaultCont1;                   /* '<S3>/FaultCont1' */
  real_T FaultCont2;                   /* '<S3>/FaultCont2' */
  real_T FaultCont4;                   /* '<S3>/FaultCont4' */
  real_T MultiportSwitch_g;            /* '<S3>/Multiport Switch' */
  real_T Product;                      /* '<S1>/Product' */
  real_T Clock1;                       /* '<S9>/Clock1' */
  real_T u_a;                          /* '<S9>/4' */
  real_T u_f;                          /* '<S9>/6' */
  real_T Clock_b;                      /* '<S12>/Clock' */
  real_T u_l;                          /* '<S12>/2' */
  real_T u_f2;                         /* '<S12>/5' */
  real_T Clock1_o;                     /* '<S12>/Clock1' */
  real_T u_c;                          /* '<S12>/4' */
  real_T u_pb;                         /* '<S12>/6' */
  real_T Clock_i;                      /* '<S8>/Clock' */
  real_T u_k;                          /* '<S8>/2' */
  real_T u_j;                          /* '<S8>/5' */
  real_T Clock1_p;                     /* '<S8>/Clock1' */
  real_T u_o;                          /* '<S8>/4' */
  real_T u_fd;                         /* '<S8>/6' */
  real_T Clock_g;                      /* '<S11>/Clock' */
  real_T u_h;                          /* '<S11>/2' */
  real_T u_ka;                         /* '<S11>/5' */
  real_T Clock1_l;                     /* '<S11>/Clock1' */
  real_T u_of;                         /* '<S11>/4' */
  real_T u_ax;                         /* '<S11>/6' */
  real_T Constant;                     /* '<S10>/Constant' */
  real_T Clock_h;                      /* '<S16>/Clock' */
  real_T Gain;                         /* '<S16>/Gain' */
  real_T Product1;                     /* '<S16>/Product1' */
  real_T Divide;                       /* '<S16>/Divide' */
  real_T TrigonometricFunction1;       /* '<S16>/Trigonometric Function1' */
  real_T Product2;                     /* '<S16>/Product2' */
  real_T Subtract;                     /* '<S16>/Subtract' */
  real_T Product3;                     /* '<S16>/Product3' */
  real_T Add;                          /* '<S16>/Add' */
  real_T Clock_d;                      /* '<S17>/Clock' */
  real_T Gain_e;                       /* '<S17>/Gain' */
  real_T Product1_k;                   /* '<S17>/Product1' */
  real_T Divide_j;                     /* '<S17>/Divide' */
  real_T TrigonometricFunction1_g;     /* '<S17>/Trigonometric Function1' */
  real_T Product2_a;                   /* '<S17>/Product2' */
  real_T Subtract_b;                   /* '<S17>/Subtract' */
  real_T Product3_n;                   /* '<S17>/Product3' */
  real_T Subtract1;                    /* '<S17>/Subtract1' */
  real_T Clock_p;                      /* '<S18>/Clock' */
  real_T Gain_k;                       /* '<S18>/Gain' */
  real_T Product1_e;                   /* '<S18>/Product1' */
  real_T Divide_b;                     /* '<S18>/Divide' */
  real_T TrigonometricFunction1_a;     /* '<S18>/Trigonometric Function1' */
  real_T Product2_h;                   /* '<S18>/Product2' */
  real_T Add2;                         /* '<S18>/Add2' */
  real_T Product3_c;                   /* '<S18>/Product3' */
  real_T Add_a;                        /* '<S18>/Add' */
  real_T Clock_k;                      /* '<S19>/Clock' */
  real_T Gain_o;                       /* '<S19>/Gain' */
  real_T Product1_a;                   /* '<S19>/Product1' */
  real_T Divide_a;                     /* '<S19>/Divide' */
  real_T TrigonometricFunction1_c;     /* '<S19>/Trigonometric Function1' */
  real_T Product2_h2;                  /* '<S19>/Product2' */
  real_T Add2_p;                       /* '<S19>/Add2' */
  real_T Product3_p;                   /* '<S19>/Product3' */
  real_T Add_a1;                       /* '<S19>/Add' */
  real_T Clock_f;                      /* '<S20>/Clock' */
  real_T Gain_i;                       /* '<S20>/Gain' */
  real_T Product1_ez;                  /* '<S20>/Product1' */
  real_T Divide_g;                     /* '<S20>/Divide' */
  real_T TrigonometricFunction1_h;     /* '<S20>/Trigonometric Function1' */
  real_T Product2_n;                   /* '<S20>/Product2' */
  real_T Add2_m;                       /* '<S20>/Add2' */
  real_T Product3_l;                   /* '<S20>/Product3' */
  real_T Add_o;                        /* '<S20>/Add' */
  real_T Clock_bw;                     /* '<S21>/Clock' */
  real_T Gain_f;                       /* '<S21>/Gain' */
  real_T Product1_p;                   /* '<S21>/Product1' */
  real_T Divide_gp;                    /* '<S21>/Divide' */
  real_T TrigonometricFunction1_hw;    /* '<S21>/Trigonometric Function1' */
  real_T Product2_ad;                  /* '<S21>/Product2' */
  real_T Add2_i;                       /* '<S21>/Add2' */
  real_T Product3_o;                   /* '<S21>/Product3' */
  real_T Add_ot;                       /* '<S21>/Add' */
  real_T Clock_o;                      /* '<S22>/Clock' */
  real_T Divide1;                      /* '<S22>/Divide1' */
  real_T Product1_a3;                  /* '<S22>/Product1' */
  real_T Product5;                     /* '<S22>/Product5' */
  real_T Product6;                     /* '<S22>/Product6' */
  real_T Divide_k;                     /* '<S22>/Divide' */
  real_T TrigonometricFunction1_j;     /* '<S22>/Trigonometric Function1' */
  real_T TrigonometricFunction3;       /* '<S22>/Trigonometric Function3' */
  real_T Product7;                     /* '<S22>/Product7' */
  real_T Product2_b;                   /* '<S22>/Product2' */
  real_T Add2_d;                       /* '<S22>/Add2' */
  real_T Product3_g;                   /* '<S22>/Product3' */
  real_T Add_j;                        /* '<S22>/Add' */
  real_T Clock_ka;                     /* '<S23>/Clock' */
  real_T Divide1_i;                    /* '<S23>/Divide1' */
  real_T Product1_b;                   /* '<S23>/Product1' */
  real_T Product5_f;                   /* '<S23>/Product5' */
  real_T Product6_k;                   /* '<S23>/Product6' */
  real_T Divide_ju;                    /* '<S23>/Divide' */
  real_T TrigonometricFunction1_b;     /* '<S23>/Trigonometric Function1' */
  real_T TrigonometricFunction3_d;     /* '<S23>/Trigonometric Function3' */
  real_T Product7_k;                   /* '<S23>/Product7' */
  real_T Product2_j;                   /* '<S23>/Product2' */
  real_T Add2_c;                       /* '<S23>/Add2' */
  real_T Product3_n5;                  /* '<S23>/Product3' */
  real_T Add_l;                        /* '<S23>/Add' */
  real_T Clock_e;                      /* '<S24>/Clock' */
  real_T Divide1_b;                    /* '<S24>/Divide1' */
  real_T Product1_i;                   /* '<S24>/Product1' */
  real_T Product5_fk;                  /* '<S24>/Product5' */
  real_T Product6_j;                   /* '<S24>/Product6' */
  real_T Divide_i;                     /* '<S24>/Divide' */
  real_T TrigonometricFunction1_j5;    /* '<S24>/Trigonometric Function1' */
  real_T TrigonometricFunction3_l;     /* '<S24>/Trigonometric Function3' */
  real_T Product7_l;                   /* '<S24>/Product7' */
  real_T Product2_bv;                  /* '<S24>/Product2' */
  real_T Add2_o;                       /* '<S24>/Add2' */
  real_T Product3_k;                   /* '<S24>/Product3' */
  real_T Add_e;                        /* '<S24>/Add' */
  real_T Clock_k2;                     /* '<S25>/Clock' */
  real_T Divide1_f;                    /* '<S25>/Divide1' */
  real_T Product1_o;                   /* '<S25>/Product1' */
  real_T Product5_k;                   /* '<S25>/Product5' */
  real_T Product6_ki;                  /* '<S25>/Product6' */
  real_T Divide_m;                     /* '<S25>/Divide' */
  real_T TrigonometricFunction1_n;     /* '<S25>/Trigonometric Function1' */
  real_T TrigonometricFunction3_g;     /* '<S25>/Trigonometric Function3' */
  real_T Product7_m;                   /* '<S25>/Product7' */
  real_T Product2_ji;                  /* '<S25>/Product2' */
  real_T Add2_b;                       /* '<S25>/Add2' */
  real_T Product3_m;                   /* '<S25>/Product3' */
  real_T Add_f;                        /* '<S25>/Add' */
  real_T Constant2;                    /* '<S1>/Constant2' */
  real_T MultiportSwitch2_i;           /* '<S2>/Multiport Switch2' */
  real_T NoiseAdd;                     /* '<S1>/NoiseAdd' */
  real_T Multiport;                    /* '<S3>/Multiport' */
  real_T MultiportSwitch_f;            /* '<S5>/Multiport Switch' */
  real_T Add1;                         /* '<S1>/Add1' */
  real_T Product2_g;                   /* '<S9>/Product2' */
  real_T Add1_k;                       /* '<S9>/Add1' */
  real_T TrigonometricFunction1_be;    /* '<S9>/Trigonometric Function1' */
  real_T Product3_oy;                  /* '<S9>/Product3' */
  real_T Product_k;                    /* '<S9>/Product' */
  real_T Add_oe;                       /* '<S9>/Add' */
  real_T TrigonometricFunction;        /* '<S9>/Trigonometric Function' */
  real_T Product1_d;                   /* '<S9>/Product1' */
  real_T Add2_dz;                      /* '<S9>/Add2' */
  real_T Product2_af;                  /* '<S12>/Product2' */
  real_T Add1_n;                       /* '<S12>/Add1' */
  real_T TrigonometricFunction1_d;     /* '<S12>/Trigonometric Function1' */
  real_T Product3_np;                  /* '<S12>/Product3' */
  real_T Product_h;                    /* '<S12>/Product' */
  real_T Add_i;                        /* '<S12>/Add' */
  real_T TrigonometricFunction_h;      /* '<S12>/Trigonometric Function' */
  real_T Product1_h;                   /* '<S12>/Product1' */
  real_T Add2_b3;                      /* '<S12>/Add2' */
  real_T Product2_gv;                  /* '<S8>/Product2' */
  real_T Add1_n0;                      /* '<S8>/Add1' */
  real_T TrigonometricFunction1_m;     /* '<S8>/Trigonometric Function1' */
  real_T Product3_h;                   /* '<S8>/Product3' */
  real_T Product_j;                    /* '<S8>/Product' */
  real_T Add_h;                        /* '<S8>/Add' */
  real_T TrigonometricFunction_k;      /* '<S8>/Trigonometric Function' */
  real_T Product1_aq;                  /* '<S8>/Product1' */
  real_T Add2_mo;                      /* '<S8>/Add2' */
  real_T Product2_k;                   /* '<S11>/Product2' */
  real_T Add1_h;                       /* '<S11>/Add1' */
  real_T TrigonometricFunction1_az;    /* '<S11>/Trigonometric Function1' */
  real_T Product3_f;                   /* '<S11>/Product3' */
  real_T Product_m;                    /* '<S11>/Product' */
  real_T Add_c;                        /* '<S11>/Add' */
  real_T TrigonometricFunction_c;      /* '<S11>/Trigonometric Function' */
  real_T Product1_l;                   /* '<S11>/Product1' */
  real_T Add2_k;                       /* '<S11>/Add2' */
  real_T MultiportSwitch_fe;           /* '<S10>/Multiport Switch' */
  real_T Product4;                     /* '<S17>/Product4' */
  real_T Add1_nm;                      /* '<S17>/Add1' */
  real_T TrigonometricFunction2;       /* '<S17>/Trigonometric Function2' */
  real_T Product4_a;                   /* '<S16>/Product4' */
  real_T Add1_kz;                      /* '<S16>/Add1' */
  real_T TrigonometricFunction2_a;     /* '<S16>/Trigonometric Function2' */
  real_T Product5_c;                   /* '<S13>/Product5' */
  real_T Add_oj;                       /* '<S13>/Add' */
  real_T Product4_am;                  /* '<S21>/Product4' */
  real_T Add1_j;                       /* '<S21>/Add1' */
  real_T TrigonometricFunction2_j;     /* '<S21>/Trigonometric Function2' */
  real_T Product4_p;                   /* '<S20>/Product4' */
  real_T Add1_b;                       /* '<S20>/Add1' */
  real_T TrigonometricFunction2_e;     /* '<S20>/Trigonometric Function2' */
  real_T Product4_d;                   /* '<S19>/Product4' */
  real_T Add1_o;                       /* '<S19>/Add1' */
  real_T TrigonometricFunction2_l;     /* '<S19>/Trigonometric Function2' */
  real_T Product4_i;                   /* '<S18>/Product4' */
  real_T Add1_g;                       /* '<S18>/Add1' */
  real_T TrigonometricFunction2_n;     /* '<S18>/Trigonometric Function2' */
  real_T Product5_h;                   /* '<S14>/Product5' */
  real_T Add_e0;                       /* '<S14>/Add' */
  real_T Product4_j;                   /* '<S25>/Product4' */
  real_T Add1_b4;                      /* '<S25>/Add1' */
  real_T TrigonometricFunction2_g;     /* '<S25>/Trigonometric Function2' */
  real_T Product4_at;                  /* '<S24>/Product4' */
  real_T Add1_jd;                      /* '<S24>/Add1' */
  real_T TrigonometricFunction2_i;     /* '<S24>/Trigonometric Function2' */
  real_T Product4_m;                   /* '<S23>/Product4' */
  real_T Add1_i;                       /* '<S23>/Add1' */
  real_T TrigonometricFunction2_b;     /* '<S23>/Trigonometric Function2' */
  real_T Product4_b;                   /* '<S22>/Product4' */
  real_T Add1_jr;                      /* '<S22>/Add1' */
  real_T TrigonometricFunction2_bw;    /* '<S22>/Trigonometric Function2' */
  real_T Product5_fa;                  /* '<S15>/Product5' */
  real_T Add_k;                        /* '<S15>/Add' */
  real_T Multiport_d;                  /* '<S1>/Multiport' */
  real_T Add2_h;                       /* '<S1>/Add2' */
  real_T Product1_oo;                  /* '<S1>/Product1' */
  boolean_T Logical;                   /* '<S3>/Logical' */
  boolean_T Compare;                   /* '<S6>/Compare' */
  boolean_T Logical_i;                 /* '<S3>/Logical ' */
  boolean_T Compare_h;                 /* '<S7>/Compare' */
  boolean_T LogicalOperator;           /* '<S3>/Logical Operator' */
} B_MFI_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Nomal;                       /* '<Root>/Nomal' */
  real_T *OutsideSignal1;              /* '<Root>/Outside Signal1' */
  real_T *Inport1;                     /* '<Root>/Inport1' */
} ExternalUPtrs_MFI_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *Out;                         /* '<Root>/Out' */
} ExtY_MFI_T;

/* Parameters (auto storage) */
struct P_MFI_T_ {
  real_T AddMux;                       /* Variable: AddMux
                                        * Referenced by:
                                        *   '<S1>/Constant2'
                                        *   '<S3>/Constant2'
                                        */
  real_T BearingFP[7];                 /* Variable: BearingFP
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
  real_T FS[2];                        /* Variable: FS
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
  real_T FaultInjectionTime;           /* Variable: FaultInjectionTime
                                        * Referenced by:
                                        *   '<S3>/FaultSelec1'
                                        *   '<S3>/Step'
                                        *   '<S5>/Step'
                                        */
  real_T FaultType;                    /* Variable: FaultType
                                        * Referenced by:
                                        *   '<S3>/FaultSelec1'
                                        *   '<S3>/Step'
                                        *   '<S5>/Step'
                                        */
  real_T NoiseSelec;                   /* Variable: NoiseSelec
                                        * Referenced by: '<S1>/NoiseSelec'
                                        */
  real_T Severity1;                    /* Variable: Severity1
                                        * Referenced by: '<S3>/FaultCont1'
                                        */
  real_T Severity2;                    /* Variable: Severity2
                                        * Referenced by: '<S3>/FaultCont2'
                                        */
  real_T Severity3;                    /* Variable: Severity3
                                        * Referenced by: '<S3>/FaultCont4'
                                        */
};

extern P_MFI_T MFI_DefaultP;

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
 * hilite_system('untitled/MFI')    - opens subsystem untitled/MFI
 * hilite_system('untitled/MFI/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/MFI'
 * '<S2>'   : 'untitled/MFI/Logic Operation'
 * '<S3>'   : 'untitled/MFI/SFI'
 * '<S4>'   : 'untitled/MFI/Subsystem'
 * '<S5>'   : 'untitled/MFI/Subsystem1'
 * '<S6>'   : 'untitled/MFI/SFI/Compare To Constant'
 * '<S7>'   : 'untitled/MFI/SFI/Compare To Constant1'
 * '<S8>'   : 'untitled/MFI/Subsystem1/Air Gap Eccentricity Fault'
 * '<S9>'   : 'untitled/MFI/Subsystem1/Bar Broken Fault'
 * '<S10>'  : 'untitled/MFI/Subsystem1/Bearing Fault'
 * '<S11>'  : 'untitled/MFI/Subsystem1/End Link Fault'
 * '<S12>'  : 'untitled/MFI/Subsystem1/Inter-turn Short Circuit Fault'
 * '<S13>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault1'
 * '<S14>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault2'
 * '<S15>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault3'
 * '<S16>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault1/Subsystem'
 * '<S17>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault1/Subsystem1'
 * '<S18>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault2/Subsystem'
 * '<S19>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault2/Subsystem1'
 * '<S20>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault2/Subsystem2'
 * '<S21>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault2/Subsystem3'
 * '<S22>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault3/Subsystem'
 * '<S23>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault3/Subsystem1'
 * '<S24>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault3/Subsystem2'
 * '<S25>'  : 'untitled/MFI/Subsystem1/Bearing Fault/bearing fault3/Subsystem3'
 */
#endif                                 /* RTW_HEADER_MFI_sf_h_ */
