/*
 * CFI10_sid.h
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
 *
 * SOURCES: CFI10_sf.c
 */

/* statically allocated instance data for model: CFI10 */
{
  extern P_CFI10_T CFI10_DefaultP;

  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static B_CFI10_T sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(B_CFI10_T));
    }

    /* model parameters */
    ssSetLocalDefaultParam(rts, (real_T *) &CFI10_DefaultP);

    /* model checksums */
    ssSetChecksumVal(rts, 0, 2197808711U);
    ssSetChecksumVal(rts, 1, 1800539230U);
    ssSetChecksumVal(rts, 2, 4052282217U);
    ssSetChecksumVal(rts, 3, 1308409369U);
  }
}
