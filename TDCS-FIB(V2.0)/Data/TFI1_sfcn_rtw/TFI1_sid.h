/*
 * TFI1_sid.h
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
 *
 * SOURCES: TFI1_sf.c
 */

/* statically allocated instance data for model: TFI1 */
{
  extern P_TFI1_T TFI1_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_TFI1_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_TFI1_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &TFI1_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 3182343336U);
    ssSetChecksumVal(rts, 1, 237055141U);
    ssSetChecksumVal(rts, 2, 1011831040U);
    ssSetChecksumVal(rts, 3, 4158899751U);
  }
}
