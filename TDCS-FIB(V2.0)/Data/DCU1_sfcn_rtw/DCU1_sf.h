/*
 * DCU1_sf.h
 *
 * Code generation for model "DCU1_sf".
 *
 * Model version              : 1.77
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Oct 31 17:21:50 2016
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_DCU1_sf_h_
#define RTW_HEADER_DCU1_sf_h_
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef DCU1_sf_COMMON_INCLUDES_
# define DCU1_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME                DCU1_sf
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
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
#endif                                 /* DCU1_sf_COMMON_INCLUDES_ */

#include "DCU1_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

/* Block signals (auto storage) */
typedef struct {
  creal_T RealImagtoComplex;           /* '<S20>/Real-Imag to Complex' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Constant1;                    /* '<S65>/Constant1' */
  real_T Sum;                          /* '<S65>/Sum' */
  real_T Switch;                       /* '<S11>/Switch' */
  real_T MultiportSwitch1;             /* '<S11>/Multiport Switch 1' */
  real_T Gain_c;                       /* '<S70>/Gain' */
  real_T Gain1;                        /* '<S70>/Gain1' */
  real_T Gain3;                        /* '<S70>/Gain3' */
  real_T Gain2;                        /* '<S70>/Gain2' */
  real_T Add;                          /* '<S70>/Add' */
  real_T Add1;                         /* '<S70>/Add1' */
  real_T Add1_m;                       /* '<S84>/Add 1' */
  real_T Divide1;                      /* '<S84>/Divide 1' */
  real_T Product2;                     /* '<S84>/Product2' */
  real_T Add_m;                        /* '<S84>/Add' */
  real_T Switch_g;                     /* '<S84>/Switch' */
  real_T Product1;                     /* '<S84>/Product 1' */
  real_T Divide;                       /* '<S84>/Divide' */
  real_T Add2;                         /* '<S75>/Add2' */
  real_T Switch_o;                     /* '<S75>/Switch' */
  real_T Product1_b;                   /* '<S75>/Product1' */
  real_T Divide_c;                     /* '<S75>/Divide' */
  real_T Product2_h;                   /* '<S75>/Product2' */
  real_T Switch_j;                     /* '<S65>/Switch' */
  real_T Saturation;                   /* '<S67>/Saturation' */
  real_T Switch_n;                     /* '<S67>/Switch' */
  real_T Product1_h;                   /* '<S67>/Product1' */
  real_T Divide_k;                     /* '<S67>/Divide ' */
  real_T MultiportSwitch;              /* '<S11>/Multiport Switch' */
  real_T Saturation_h;                 /* '<S9>/Saturation' */
  real_T perpetual;                    /* '<S9>/perpetual' */
  real_T Switch1;                      /* '<S9>/Switch1' */
  real_T Fcn;                          /* '<S12>/Fcn' */
  real_T Fcn1;                         /* '<S12>/Fcn1' */
  real_T Fcn2;                         /* '<S12>/Fcn2' */
  real_T Gain_h;                       /* '<S7>/Gain' */
  real_T Sum1;                         /* '<S7>/Sum1' */
  real_T Fcn1_c;                       /* '<S13>/Fcn1' */
  real_T C1;                           /* '<S15>/C1' */
  real_T DiscreteTimeIntegrator;       /* '<S7>/Discrete-Time Integrator' */
  real_T TrigonometricFunction;        /* '<S14>/Trigonometric Function' */
  real_T Product;                      /* '<S14>/Product' */
  real_T TrigonometricFunction1;       /* '<S14>/Trigonometric Function1' */
  real_T C2;                           /* '<S15>/C2' */
  real_T Product3;                     /* '<S14>/Product3' */
  real_T Add_o;                        /* '<S14>/Add' */
  real_T Sum_g;                        /* '<S16>/Sum' */
  real_T ProportionalGain;             /* '<S18>/Proportional Gain' */
  real_T IntegralGain;                 /* '<S18>/Integral Gain' */
  real_T Integrator;                   /* '<S18>/Integrator' */
  real_T Sum_m;                        /* '<S18>/Sum' */
  real_T Sum1_l;                       /* '<S2>/Sum1' */
  real_T TrigonometricFunction_i;      /* '<S4>/Trigonometric Function' */
  real_T Product_o;                    /* '<S4>/Product' */
  real_T Fcn_o;                        /* '<S13>/Fcn' */
  real_T Product2_e;                   /* '<S14>/Product2' */
  real_T Product1_k;                   /* '<S14>/Product1' */
  real_T Add1_p;                       /* '<S14>/Add1' */
  real_T Sum_g4;                       /* '<S17>/Sum' */
  real_T ProportionalGain_g;           /* '<S19>/Proportional Gain' */
  real_T IntegralGain_o;               /* '<S19>/Integral Gain' */
  real_T Integrator_b;                 /* '<S19>/Integrator' */
  real_T Sum_b;                        /* '<S19>/Sum' */
  real_T Sum_i;                        /* '<S2>/Sum' */
  real_T TrigonometricFunction1_m;     /* '<S4>/Trigonometric Function1' */
  real_T Product3_k;                   /* '<S4>/Product3' */
  real_T Add_h;                        /* '<S4>/Add' */
  real_T Product1_m;                   /* '<S4>/Product1' */
  real_T Product2_d;                   /* '<S4>/Product2' */
  real_T Add1_pf;                      /* '<S4>/Add1' */
  real_T ComplextoMagnitudeAngle_o1;   /* '<S20>/Complex to Magnitude-Angle' */
  real_T ComplextoMagnitudeAngle_o2;   /* '<S20>/Complex to Magnitude-Angle' */
  real_T Saturation_g;                 /* '<S20>/Saturation' */
  real_T DataTypeConversion;           /* '<S22>/Data Type Conversion' */
  real_T Gain_d;                       /* '<S22>/Gain' */
  real_T DataTypeConversion1;          /* '<S22>/Data Type Conversion1' */
  real_T Gain1_b;                      /* '<S22>/Gain1' */
  real_T DataTypeConversion2;          /* '<S22>/Data Type Conversion2' */
  real_T Gain2_e;                      /* '<S22>/Gain2' */
  real_T DataTypeConversion3;          /* '<S22>/Data Type Conversion3' */
  real_T Gain3_o;                      /* '<S22>/Gain3' */
  real_T DataTypeConversion4;          /* '<S22>/Data Type Conversion4' */
  real_T Gain4;                        /* '<S22>/Gain4' */
  real_T DataTypeConversion5;          /* '<S22>/Data Type Conversion5' */
  real_T Gain5;                        /* '<S22>/Gain5' */
  real_T Add_b;                        /* '<S22>/Add' */
  real_T Switch_nm;                    /* '<S23>/Switch' */
  real_T Gain_n;                       /* '<S23>/Gain' */
  real_T Add_i;                        /* '<S23>/Add' */
  real_T Add_f;                        /* '<S3>/Add' */
  real_T Fcn_g;                        /* '<S20>/Fcn' */
  real_T Saturation1;                  /* '<S20>/Saturation1' */
  real_T Clock;                        /* '<S30>/Clock' */
  real_T Sum_m1;                       /* '<S30>/Sum' */
  real_T MathFunction;                 /* '<S30>/Math Function' */
  real_T LookUpTable1;                 /* '<S30>/Look-Up Table1' */
  real_T Output;                       /* '<S30>/Output' */
  real_T Ts;                           /* '<S10>/Ts' */
  real_T MultiportSwitch_h[3];         /* '<S27>/Multiport Switch' */
  real_T Gain1_d;                      /* '<S31>/Gain1' */
  real_T Gain2_et;                     /* '<S31>/Gain2' */
  real_T Add1_f;                       /* '<S31>/Add1' */
  real_T Gain3_f;                      /* '<S31>/Gain3' */
  real_T Add2_a;                       /* '<S31>/Add2' */
  real_T Gain4_n;                      /* '<S31>/Gain4' */
  real_T Add3;                         /* '<S31>/Add3' */
  real_T Add4;                         /* '<S31>/Add4' */
  real_T Add5;                         /* '<S31>/Add5' */
  real_T DataTypeConversion_i[6];      /* '<S31>/Data Type Conversion' */
  real_T Gain5_l[6];                   /* '<S31>/Gain5' */
  real_T Add6;                         /* '<S31>/Add6' */
  real_T Add7;                         /* '<S31>/Add7' */
  real_T MultiportSwitch_b[3];         /* '<S29>/Multiport Switch' */
  real_T Clock_n;                      /* '<S91>/Clock' */
  real_T Sum_c;                        /* '<S91>/Sum' */
  real_T MathFunction_a;               /* '<S91>/Math Function' */
  real_T LookUpTable1_l;               /* '<S91>/Look-Up Table1' */
  real_T Output_g;                     /* '<S91>/Output' */
  real_T Sum_cb;                       /* '<S87>/Sum' */
  real_T Integrator_m;                 /* '<S92>/Integrator' */
  real_T Sum_mi;                       /* '<S92>/Sum' */
  real_T ProportionalGain_l;           /* '<S92>/Proportional Gain' */
  real_T Divide_i;                     /* '<S87>/Divide' */
  real_T Sum1_d;                       /* '<S87>/Sum1' */
  real_T Clock_c;                      /* '<S87>/Clock' */
  real_T Product2_do;                  /* '<S87>/Product2' */
  real_T Sinwt;                        /* '<S87>/Sin(wt)' */
  real_T Product1_g;                   /* '<S87>/Product1' */
  real_T Sum2;                         /* '<S87>/Sum2' */
  real_T G;                            /* '<S87>/G' */
  real_T Product5;                     /* '<S87>/Product5' */
  real_T Coswt;                        /* '<S87>/Cos(wt)' */
  real_T Product4;                     /* '<S87>/Product4' */
  real_T Add_hq;                       /* '<S87>/Add' */
  real_T Sum3;                         /* '<S87>/Sum3' */
  real_T G1;                           /* '<S87>/G1' */
  real_T Uza7;                         /* '<S86>/Uza7' */
  real_T Uza;                          /* '<S86>/Uza' */
  real_T Clock_k;                      /* '<S90>/Clock' */
  real_T Sum_f;                        /* '<S90>/Sum' */
  real_T MathFunction_l;               /* '<S90>/Math Function' */
  real_T LookUpTable1_ll;              /* '<S90>/Look-Up Table1' */
  real_T Output_c;                     /* '<S90>/Output' */
  real_T Uza3;                         /* '<S86>/Uza3' */
  real_T Uza4;                         /* '<S86>/Uza4' */
  real_T Add_l;                        /* '<S85>/Add' */
  real_T Relay;                        /* '<S85>/Relay' */
  real_T Product_b;                    /* '<S85>/Product' */
  real_T MultiportSwitch_o[2];         /* '<S85>/Multiport Switch' */
  real_T Add_n[2];                     /* '<S89>/Add' */
  real_T MultiportSwitch_l[4];         /* '<S89>/Multiport Switch' */
  real_T MultiportSwitch1_g[4];        /* '<S89>/Multiport Switch1' */
  real_T SineWave;                     /* '<S86>/Sine Wave' */
  real_T IntegralGain_h;               /* '<S92>/Integral Gain' */
  real_T FLAG;                         /* '<S85>/NPC-Function' */
  real_T Divide1_h;                    /* '<S67>/Divide1' */
  real_T Product2_m;                   /* '<S67>/Product2' */
  real_T Add_of;                       /* '<S67>/Add' */
  real_T Add_op;                       /* '<S75>/Add' */
  real_T Divide1_c;                    /* '<S75>/Divide1' */
  real_T Add1_o;                       /* '<S75>/Add1' */
  real_T Divide2;                      /* '<S75>/Divide2' */
  real_T MultiportSwitch_i;            /* '<S68>/Multiport Switch' */
  real_T Add2_d;                       /* '<S74>/Add 2' */
  real_T Add1_fc;                      /* '<S74>/Add 1' */
  real_T Divide1_j;                    /* '<S74>/Divide1' */
  real_T Add3_e;                       /* '<S74>/Add3' */
  real_T Product_k;                    /* '<S68>/Product' */
  real_T Add1_i;                       /* '<S69>/Add1' */
  real_T Divide2_c;                    /* '<S69>/Divide2' */
  real_T Switch_jh;                    /* '<S62>/Switch' */
  real_T Product1_c;                   /* '<S62>/Product1' */
  real_T Divide_l;                     /* '<S62>/Divide' */
  real_T Divide3;                      /* '<S62>/Divide3' */
  real_T Add_j;                        /* '<S62>/Add' */
  real_T Divide1_g;                    /* '<S62>/Divide1' */
  real_T Add1_g;                       /* '<S62>/Add1' */
  real_T Divide2_f;                    /* '<S62>/Divide2' */
  real_T Gain1_n;                      /* '<S68>/Gain1' */
  real_T Gain_dk;                      /* '<S68>/Gain' */
  real_T Add_oh;                       /* '<S68>/Add' */
  real_T Add1_n;                       /* '<S68>/Add1' */
  real_T MultiportSwitch_bm[3];        /* '<S32>/Multiport Switch' */
  real_T MultiportSwitch_d[3];         /* '<S38>/Multiport Switch' */
  real_T MultiportSwitch_m[3];         /* '<S39>/Multiport Switch' */
  real_T MultiportSwitch_f[3];         /* '<S40>/Multiport Switch' */
  real_T MultiportSwitch_e[3];         /* '<S41>/Multiport Switch' */
  real_T MultiportSwitch_k[3];         /* '<S33>/Multiport Switch' */
  real_T MultiportSwitch_c[3];         /* '<S42>/Multiport Switch' */
  real_T MultiportSwitch_bmk[3];       /* '<S43>/Multiport Switch' */
  real_T MultiportSwitch_mm[3];        /* '<S44>/Multiport Switch' */
  real_T MultiportSwitch_n[3];         /* '<S45>/Multiport Switch' */
  real_T MultiportSwitch_lq[3];        /* '<S34>/Multiport Switch' */
  real_T MultiportSwitch_br[3];        /* '<S46>/Multiport Switch' */
  real_T MultiportSwitch_p[3];         /* '<S47>/Multiport Switch' */
  real_T MultiportSwitch_bk[3];        /* '<S48>/Multiport Switch' */
  real_T MultiportSwitch_bd[3];        /* '<S49>/Multiport Switch' */
  real_T MultiportSwitch_fx[3];        /* '<S35>/Multiport Switch' */
  real_T MultiportSwitch_hc[3];        /* '<S50>/Multiport Switch' */
  real_T MultiportSwitch_dg[3];        /* '<S51>/Multiport Switch' */
  real_T MultiportSwitch_c2[3];        /* '<S52>/Multiport Switch' */
  real_T MultiportSwitch_h3[3];        /* '<S53>/Multiport Switch' */
  real_T MultiportSwitch_kn[3];        /* '<S36>/Multiport Switch' */
  real_T MultiportSwitch_g[3];         /* '<S54>/Multiport Switch' */
  real_T MultiportSwitch_mh[3];        /* '<S55>/Multiport Switch' */
  real_T MultiportSwitch_k2[3];        /* '<S56>/Multiport Switch' */
  real_T MultiportSwitch_b0[3];        /* '<S57>/Multiport Switch' */
  real_T MultiportSwitch_gd[3];        /* '<S37>/Multiport Switch' */
  real_T MultiportSwitch_h1[3];        /* '<S58>/Multiport Switch' */
  real_T MultiportSwitch_a[3];         /* '<S59>/Multiport Switch' */
  real_T MultiportSwitch_hr[3];        /* '<S60>/Multiport Switch' */
  real_T MultiportSwitch_cm[3];        /* '<S61>/Multiport Switch' */
  real_T Ta;                           /* '<S25>/Section-n' */
  real_T Tb;                           /* '<S25>/Section-n' */
  real_T Tc;                           /* '<S25>/Section-n' */
  real_T n;                            /* '<S20>/Section-n1' */
  real_T Fcn_a;                        /* '<S23>/Fcn' */
  real_T Switch_jhq;                   /* '<S9>/Switch' */
  real_T Fcn_i;                        /* '<S9>/Fcn' */
  real_T Switch2;                      /* '<S9>/Switch2' */
  real_T Fcn1_i;                       /* '<S9>/Fcn1' */
  boolean_T Compare;                   /* '<S64>/Compare' */
  boolean_T Compare_n;                 /* '<S76>/Compare' */
  boolean_T Compare_n5;                /* '<S77>/Compare' */
  boolean_T LogicalOperator2;          /* '<S70>/Logical Operator2' */
  boolean_T Compare_f;                 /* '<S78>/Compare' */
  boolean_T Compare_e;                 /* '<S79>/Compare' */
  boolean_T LogicalOperator3;          /* '<S70>/Logical Operator3' */
  boolean_T Compare_ew;                /* '<S82>/Compare' */
  boolean_T Compare_k;                 /* '<S83>/Compare' */
  boolean_T LogicalOperator1;          /* '<S70>/Logical Operator1' */
  boolean_T Compare_p;                 /* '<S80>/Compare' */
  boolean_T Compare_b;                 /* '<S81>/Compare' */
  boolean_T LogicalOperator;           /* '<S70>/Logical Operator' */
  boolean_T Compare_h;                 /* '<S73>/Compare' */
  boolean_T Compare_bb;                /* '<S63>/Compare' */
  boolean_T RelationalOperator;        /* '<S22>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S22>/Relational Operator1' */
  boolean_T LogicalOperator_a;         /* '<S22>/Logical Operator' */
  boolean_T RelationalOperator2;       /* '<S22>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S22>/Relational Operator3' */
  boolean_T LogicalOperator1_n;        /* '<S22>/Logical Operator1' */
  boolean_T RelationalOperator4;       /* '<S22>/Relational Operator4' */
  boolean_T RelationalOperator5;       /* '<S22>/Relational Operator5' */
  boolean_T LogicalOperator2_o;        /* '<S22>/Logical Operator2' */
  boolean_T RelationalOperator6;       /* '<S22>/Relational Operator6' */
  boolean_T RelationalOperator7;       /* '<S22>/Relational Operator7' */
  boolean_T LogicalOperator3_m;        /* '<S22>/Logical Operator3' */
  boolean_T RelationalOperator8;       /* '<S22>/Relational Operator8' */
  boolean_T RelationalOperator9;       /* '<S22>/Relational Operator9' */
  boolean_T LogicalOperator4;          /* '<S22>/Logical Operator4' */
  boolean_T RelationalOperator10;      /* '<S22>/Relational Operator10' */
  boolean_T RelationalOperator11;      /* '<S22>/Relational Operator11' */
  boolean_T LogicalOperator5;          /* '<S22>/Logical Operator5' */
  boolean_T RelationalOperator_p;      /* '<S23>/Relational Operator' */
  boolean_T RelationalOperator_h;      /* '<S31>/Relational Operator' */
  boolean_T RelationalOperator1_l;     /* '<S31>/Relational Operator1' */
  boolean_T RelationalOperator2_o;     /* '<S31>/Relational Operator2' */
  boolean_T RelationalOperator3_p;     /* '<S31>/Relational Operator3' */
  boolean_T RelationalOperator4_j;     /* '<S31>/Relational Operator4' */
  boolean_T RelationalOperator5_l;     /* '<S31>/Relational Operator5' */
  boolean_T RelationalOperator_g;      /* '<S86>/Relational Operator' */
  boolean_T RelationalOperator1_e;     /* '<S86>/Relational Operator1' */
  boolean_T RelationalOperator2_i;     /* '<S86>/Relational Operator2' */
  boolean_T RelationalOperator3_l;     /* '<S86>/Relational Operator3' */
  boolean_T Compare_c;                 /* '<S72>/Compare' */
  boolean_T Compare_o;                 /* '<S71>/Compare' */
  uint8_T Uza1;                        /* '<S86>/Uza1' */
  uint8_T Uza5;                        /* '<S86>/Uza5' */
  int8_T Uza2;                         /* '<S86>/Uza2' */
  int8_T Uza6;                         /* '<S86>/Uza6' */
  int8_T Add_c;                        /* '<S86>/Add' */
  int8_T Add1_b;                       /* '<S86>/Add1' */
} B_DCU1_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Product;                /* '<S84>/Product' */
  const real_T Product_k;              /* '<S75>/Product' */
  const real_T Product_d;              /* '<S67>/Product' */
  const real_T Product_dd;             /* '<S62>/Product' */
  const real_T Product3;               /* '<S87>/Product3' */
} ConstB_DCU1_T;

/* For easy access from the SimStruct */
#define DCU1_rtC(rts)                  ((ConstB_DCU1_T *) _ssGetConstBlockIO(rts))

/* Constant parameters (auto storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<S30>/Look-Up Table1'
   */
  real_T pooled31[2];

  /* Expression: rep_seq_y
   * Referenced by: '<S91>/Look-Up Table1'
   */
  real_T LookUpTable1_tableDat[3];

  /* Pooled Parameter (Expression: rep_seq_t - min(rep_seq_t))
   * Referenced by:
   *   '<S90>/Look-Up Table1'
   *   '<S91>/Look-Up Table1'
   */
  real_T pooled59[3];

  /* Expression: rep_seq_y
   * Referenced by: '<S90>/Look-Up Table1'
   */
  real_T LookUpTable1_tableD_l[3];
} ConstP_DCU1_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T *Commander;                   /* '<Root>/Commander' */
  real_T *Inport1;                     /* '<Root>/Inport1' */
  real_T *Inport2;                     /* '<Root>/Inport2' */
  real_T *Inport3;                     /* '<Root>/Inport3' */
  real_T *Inport4;                     /* '<Root>/Inport4' */
  real_T *Inport5;                     /* '<Root>/Inport5' */
  real_T *Inport6;                     /* '<Root>/Inport6' */
  real_T *Inport7[3];                  /* '<Root>/Inport7' */
  real_T *Inport8;                     /* '<Root>/Inport8' */
} ExternalUPtrs_DCU1_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T *SPWM1[3];                    /* '<Root>/SPWM1' */
  real_T *SPWM[8];                     /* '<Root>/SPWM' */
} ExtY_DCU1_T;

/* Parameters (auto storage) */
struct P_DCU1_T_ {
  real_T KIM;                          /* Variable: KIM
                                        * Referenced by: '<S18>/Integral Gain'
                                        */
  real_T KIT;                          /* Variable: KIT
                                        * Referenced by: '<S19>/Integral Gain'
                                        */
  real_T KPM;                          /* Variable: KPM
                                        * Referenced by: '<S18>/Proportional Gain'
                                        */
  real_T KPT;                          /* Variable: KPT
                                        * Referenced by: '<S19>/Proportional Gain'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by: '<S10>/Ts'
                                        */
  real_T Vge;                          /* Variable: Vge
                                        * Referenced by:
                                        *   '<S65>/Constant1'
                                        *   '<S75>/Constant8'
                                        *   '<S84>/Constant5'
                                        */
  real_T np;                           /* Variable: np
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T phir;                         /* Variable: phir
                                        * Referenced by: '<S9>/perpetual'
                                        */
};

extern P_DCU1_T DCU1_DefaultP;
extern const ConstB_DCU1_T DCU1_Invariant;

/* Constant parameters (auto storage) */
extern const ConstP_DCU1_T DCU1_ConstP;

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
 * hilite_system('CRH2forBenchmark/DCU1')    - opens subsystem CRH2forBenchmark/DCU1
 * hilite_system('CRH2forBenchmark/DCU1/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CRH2forBenchmark'
 * '<S1>'   : 'CRH2forBenchmark/DCU1'
 * '<S2>'   : 'CRH2forBenchmark/DCU1/DCU-Inverter'
 * '<S3>'   : 'CRH2forBenchmark/DCU1/DCU-Rectifier'
 * '<S4>'   : 'CRH2forBenchmark/DCU1/DCU-Inverter/2r//2s'
 * '<S5>'   : 'CRH2forBenchmark/DCU1/DCU-Inverter/3S//2R'
 * '<S6>'   : 'CRH2forBenchmark/DCU1/DCU-Inverter/Calculator Model'
 * '<S7>'   : 'CRH2forBenchmark/DCU1/DCU-Inverter/Calculator Model (CM)'
 * '<S8>'   : 'CRH2forBenchmark/DCU1/DCU-Inverter/Constant Current Control'
 * '<S9>'   : 'CRH2forBenchmark/DCU1/DCU-Inverter/Phir Control£¨PC£©'
 * '<S10>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy'
 * '<S11>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© '
 * '<S12>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Vector Calculator Function Form£¨VCFF£©'
 * '<S13>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Voltage Feed-forward Compensation'
 * '<S14>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/3S//2R/2s//2r'
 * '<S15>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/3S//2R/3r//2s'
 * '<S16>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Constant Current Control/ACPR'
 * '<S17>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Constant Current Control/ACTR'
 * '<S18>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Constant Current Control/ACPR/Discrete PID Controller1'
 * '<S19>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Constant Current Control/ACTR/Discrete PID Controller2'
 * '<S20>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Reference voltage orientation '
 * '<S21>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting'
 * '<S22>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Reference voltage orientation /Reference voltage orientation 1 '
 * '<S23>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Reference voltage orientation /Reference voltage orientation 2'
 * '<S24>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Reference voltage orientation /Section-n1'
 * '<S25>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggered'
 * '<S26>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator'
 * '<S27>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggered/Reference voltage orientation '
 * '<S28>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggered/Section-n'
 * '<S29>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check'
 * '<S30>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/Repeating Sequence'
 * '<S31>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/Seven Part'
 * '<S32>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/1'
 * '<S33>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/2'
 * '<S34>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/3'
 * '<S35>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/4'
 * '<S36>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/5'
 * '<S37>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/6'
 * '<S38>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/1/1'
 * '<S39>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/1/2'
 * '<S40>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/1/3'
 * '<S41>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/1/4'
 * '<S42>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/2/1'
 * '<S43>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/2/2'
 * '<S44>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/2/3'
 * '<S45>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/2/4'
 * '<S46>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/3/1'
 * '<S47>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/3/2'
 * '<S48>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/3/3'
 * '<S49>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/3/4'
 * '<S50>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/4/1'
 * '<S51>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/4/2'
 * '<S52>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/4/3'
 * '<S53>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/4/4'
 * '<S54>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/5/1'
 * '<S55>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/5/2'
 * '<S56>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/5/3'
 * '<S57>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/5/4'
 * '<S58>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/6/1'
 * '<S59>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/6/2'
 * '<S60>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/6/3'
 * '<S61>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/SVPWM Genratorfxy/Time Setting/Triggle Generator/PON-XNJD-LGJ-check/6/4'
 * '<S62>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Brake Control'
 * '<S63>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Compare '
 * '<S64>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Compare 1'
 * '<S65>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control'
 * '<S66>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Ramp Control'
 * '<S67>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Traction Control'
 * '<S68>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  '
 * '<S69>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Brake calculator'
 * '<S70>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice'
 * '<S71>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Compare '
 * '<S72>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Compare1'
 * '<S73>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Compare2'
 * '<S74>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Tractin Calculator'
 * '<S75>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Brake calculator/Brake Control'
 * '<S76>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 1'
 * '<S77>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 2'
 * '<S78>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 3'
 * '<S79>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 4'
 * '<S80>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 5'
 * '<S81>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 6'
 * '<S82>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 7'
 * '<S83>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Choice/Compare 8'
 * '<S84>'  : 'CRH2forBenchmark/DCU1/DCU-Inverter/Torque Control Unit£¨TCU£© /Holding Control/Enabled  /Tractin Calculator/Calculator'
 * '<S85>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/NPC-fengxiaoyun'
 * '<S86>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/SPWM-State-Generator'
 * '<S87>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/Transient Current Control System'
 * '<S88>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/NPC-fengxiaoyun/NPC-Function'
 * '<S89>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/NPC-fengxiaoyun/State to SPWM'
 * '<S90>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/SPWM-State-Generator/Triangle-Carrier -Wave-2'
 * '<S91>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/SPWM-State-Generator/Triangle-Carrier-Wave-1'
 * '<S92>'  : 'CRH2forBenchmark/DCU1/DCU-Rectifier/Transient Current Control System/Continue PI Controller1'
 */
#endif                                 /* RTW_HEADER_DCU1_sf_h_ */
